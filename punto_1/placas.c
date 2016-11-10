#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define L 5
#define l 2
#define d 1
#define h 0.02
#define V0 100
#define N 100


int main(){
	float *V;
	int i;
	int j;
	int dim;
	int index;
	int n;
	dim = (int)L/h;

	V = malloc((dim+1)*(dim+1)*sizeof(float));

	for(j=0;j<=dim;j++){
		for(i=0;i<=dim;i++){
			index = j*dim + i;
			V[index] = 0.0;
			
			if(j==(int)(0.4*L/h)){
				if(i>=(int)(1.5/5.*L/h) && i<=(int)(3.5/5.*L/h)){
					V[index] = V0/2;
				}
			}
			if(j==(int)(0.6*L/h)){
				if(i>=(int)(1.5/5.*L/h) && i<=(int)(3.5/5.*L/h)){
					V[index] = -V0/2;
				}
			}

			printf("%f ",V[index]);
		}
	}

	for(n=0;n<N;n++){
		for(j=1;j<dim;j++){
			for(i=1;i<dim;i++){
				index = j*dim+i;
				V[index] = 1./4.*(V[index+1]+V[index-1]+V[(j-1)*dim+i]+V[(j+1)*dim+i]);
	
				if(j==(int)(0.4*L/h)){
					if(i>=(int)(1.5/5.*L/h) && i<=(int)(3.5/5.*L/h)){
						V[index] = V0/2;
					}
				}
				if(j==(int)(0.6*L/h)){
					if(i>=(int)(1.5/5.*L/h) && i<=(int)(3.5/5.*L/h)){
						V[index] = -V0/2;
					}
				}
			}
		}	
	}
	printf("\n");
	for(j=0;j<=dim;j++){
		for(i=0;i<=dim;i++){
			index = j*dim+i;
			printf("%f ", V[index]);
		}
	}

	return 0;
}
