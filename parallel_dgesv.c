#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void main(int argc, char *argv[])
    {

	
	double c,sum=0.0;
	int size = atoi(argv[1]);
	int i,j,k,col;

	double *a = (double *)malloc(sizeof(double) * size * size);
	double *b = (double *)malloc(sizeof(double) * size * size);
	double **matriz_aumentada = malloc(sizeof(double *)*(size));	
	double **x =  malloc(sizeof(double *) * size);
	clock_t tStart = clock();      

	srand(1);
	for (i = 0; i < size * size; i++)
    	{
        	a[i] = rand() % 100;
    	}
	srand(1);
    	for (i = 0; i < size * size; i++)
    	{
		b[i] = rand() % 100;
	}
// Inicializar matriz_aumentada y
	for(int i = 0; i < size; ++i) {
        	matriz_aumentada[i] = malloc((size+1) * sizeof(double));
    	}
//Inicializar matriz x
	for(int i = 0; i < size; ++i) {
                x[i] = malloc((size) * sizeof(double));
        }
        // Usar eliminacion Gaussiana
/* 	
for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                printf("%lf ", a[i*size+j]);
            }
            printf("\n");
        }

for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                printf("%lf ", b[i*size+j]);
            }
            printf("\n");
        }
*/
	// Para cada columna de b
	for (col = 0; col < size; col++)
	{
		//Copiar el contenido de a en la matriz aumentada	
		for (i = 0; i < size; i++)
   			for (j = 0; j < size; j++)
        			matriz_aumentada[i][j]=a[i*size+j];
            	//Para cada fila i añadir el valor de la columna B a la matriz aumentada
		for (i = 0; i < size; i++)
			matriz_aumentada[i][size]=b[i*size +col];

		for(j=0; j<size; j++) // loop for the generation of upper triangular matrix
    		{
#pragma omp parallel shared(size,j,matriz_aumentada)
{
#pragma omp for private(i,k,c) 
        		for(i=j+1; i<size ; i++)
        		{
                			c=matriz_aumentada[i][j]/matriz_aumentada[j][j];
		                	for(k=0; k<=size; k++)
                			{
                				matriz_aumentada[i][k]=matriz_aumentada[i][k]-c*matriz_aumentada[j][k];
                			}
        		}
}
    		}

    		x[size-1][col]=matriz_aumentada[size-1][size]/matriz_aumentada[size-1][size-1];
    	
	// this loop is for backward substitution
    		for(i=size-2; i>=0; i--)
		{
        		sum=0;
        		for(j=i; j<size; j++)
        		{
        		    	sum=sum+matriz_aumentada[i][j]*x[j][col];
        		}
			x[i][col]=(matriz_aumentada[i][size]-sum)/matriz_aumentada[i][i];
   	 	}
	}

        printf("Time taken by my implementation: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);


	for (i = 0; i < 4; i++)
    	{
            for (j = 0; j < 4; j++)
            {
                printf("%lf ", x[i][j]);
            }
            printf("\n");
    	}
   
	free(a);
	free(b);
	for(int i = 0; i < size; ++i)
	{
		free(matriz_aumentada[i]);
		free(x[i]);
    	}	
	free(matriz_aumentada);
	free(x);
    }
