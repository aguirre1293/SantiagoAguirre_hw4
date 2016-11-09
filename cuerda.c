#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define T 40
#define rho 10
#define L 100
#define t_max 200
#define nx 10.
#define nt 20.
#define delta_x 10
#define delta_t 2

void print_table();
float f(int i);


int main(){
	print_table();
	return 0;
}


void print_table(){
	int i;
	int j;
	int index;
	int preindex;
	float *u;
	float c;
	float alpha;

	u = malloc(nx*nt*sizeof(float));
	c = pow(T/rho,0.5);	
	alpha = c*delta_t/delta_x;

	for(i=0;i<=nx;i++){
		u[i] = f(i);
		printf("%f ", u[i]);
	}
		printf("\n");
	
	for(j=1;j<=nt;j++){
		u[(int)nx*j]= 0.;
		for(i=1;i<nx;i++){
			index = nx*j+i;
			preindex = nx*(j-1)+i;

			u[index] = u[preindex] + (pow(alpha,2)/2.)*(u[preindex+1]+u[preindex-1]-2.0*u[preindex]);
			printf("%f ", u[index]);
		}
		printf("\n");
	}

}

float f(int i){
	float x = delta_x*i;
	float result;
	if (x<= 80){
		result = 1.25*x/L;
	}
	else {
		result = 5-5.*x/L;
	}
	return result;
}









