#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define T 40.
#define rho 10.
#define L 100
#define t_max 200
#define nx 100.
#define nt 1000.
#define delta_x 1
#define delta_t 0.2

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
	float *u_future;
	float *u_past;
	float c;
	float r;

	u = malloc(nx*sizeof(float));
	u_future = malloc(nx*sizeof(float));
	u_past = malloc(nx*sizeof(float));
	c = pow(T/rho,0.5);	
	r = c*delta_t/delta_x;

	for(i=0;i<=nx;i++){
		u_past[i] = f(i);
		printf("%f ", u_past[i]);
	}
		printf("\n");
	
	u[0]= 0.0;
	u[(int)nx] = 0.0;
	printf("%f ", u[0]);
	for(i=1;i<nx;i++){
		u[i] = u_past[i] + pow(r,2.)*(u_past[i-1]+u_past[i+1]-2*u_past[i]);
		printf("%f ", u[i]);
	}
		printf("%f ", u[(int)nx]);
		printf("\n");

	for(j=0;j<nt;j++){
		for(i=0;i<=nx;i++){
			u_future[i] = -u_past[i] + 2*(1-pow(r,2.))*u[i] + pow(r,2.)*(u[i-1]+u[i+1]);
			u_future[0] = 0;
			u_future[(int)nx] = 0;
			printf("%f ", u_future[i]);
		}
		for(i=1;i<nx;i++){
			u_past[i] = u[i];
			u[i] = u_future[i];
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









