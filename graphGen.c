#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void generateCSVGraph(int dim);
void generateCSVGraphSpec(int dim);
void generateCSVGraph3D(int dim);
void generateCSVGraph3DRand(int dim);


int main(){

srand ( time(NULL) );

generateCSVGraph3DRand(16);

return 0;
}


void generateCSVGraph(int dim){
	FILE *fp=fopen("graphRand1000x1000.txt","a");	
	if(fp==NULL){
		printf("File failed to open\n");
	   exit(EXIT_FAILURE);
	}
	fprintf(fp,"%d\n",dim*dim);
	int i;
	for(i=0;i<dim*dim;i++){

			if(rand()%4 && (i<dim*(dim-1))){
				fprintf(fp,"%d,",i+dim);
			}
			if( !(rand()%10) && (i>dim)){
				fprintf(fp,"%d,",i-dim);
			}
			if(rand()%10 && i<dim*dim-1  && (i%dim)){
				fprintf(fp,"%d,",i+1);
			}
			if(!(rand()%10) && i>0 &&(i%dim-1)){
				fprintf(fp,"%d,",i-1);
			}
		
		fprintf(fp,";\n");
	}
}

void generateCSVGraphSpec(int dim){
	FILE *fp=fopen("graphSpec512x512.txt","a");	
	if(fp==NULL){
		printf("File failed to open\n");
	   exit(EXIT_FAILURE);
	}
	fprintf(fp,"%d\n",dim*dim);
	int i;
	for(i=0;i<dim*dim;i++){

			if( (i<dim*(dim-1))){
				fprintf(fp,"%d,",i+dim);
			}
			if(i<dim*dim-1  && ((i+1)%dim)){
				fprintf(fp,"%d,",i+1);
			}
		
		fprintf(fp,";\n");
	}
}

void generateCSVGraph3D(int dim){
	FILE *fp=fopen("test100x100x100.txt","a");	
	if(fp==NULL){
		printf("File failed to open\n");
	   exit(EXIT_FAILURE);
	}
	fprintf(fp,"%d\n",dim*dim*dim);
	int i,j;
	j=1;
	for(i=0;i<dim*dim*dim;i++){

			if((i<dim*dim*(dim-1))){
				fprintf(fp,"%d,",i+dim*dim);
			}
			if( j<dim ){
				fprintf(fp,"%d,",i+dim);
			}
			if(i<dim*dim*dim-1  && ((i+1)%dim)){
				fprintf(fp,"%d,",i+1);
				
			}else{
				if(j==dim){
					j=0;
				}
				j++;
			}
		
		fprintf(fp,";\n");
	}
}

void generateCSVGraph3DRand(int dim){
	FILE *fp=fopen("test16x16x16Rand.txt","a");	
	if(fp==NULL){
		printf("File failed to open\n");
	   exit(EXIT_FAILURE);
	}
	fprintf(fp,"%d\n",dim*dim*dim);
	int i,j;
	j=1;
	for(i=0;i<dim*dim*dim;i++){

			if((i<dim*dim*(dim-1)) && rand()%10 ){
				fprintf(fp,"%d,",i+dim*dim);
			}
			if((i>dim*dim) && !rand()%10 ){
				fprintf(fp,"%d,",i-dim*dim);
			}
			if(i<dim*dim*(dim-1) && rand()%20 ){
				fprintf(fp,"%d,",i+dim);
			}
			if(i>dim && !rand()%20 ){
				fprintf(fp,"%d,",i-dim);
			}
			if((i%dim) && !rand()%8 ){
				fprintf(fp,"%d,",i-1);
			}			
			
			if(i<dim*dim*dim-1  && ((i+1)%dim)){
				fprintf(fp,"%d,",i+1);
				
			}
		
	}
}
