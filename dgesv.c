#include <time.h>
#include <stdio.h>
#include <stdlib.h>


double *generate_matrix(int size)
{
    int i;
    double *matrix = (double *)malloc(sizeof(double) * size * size);
    srand(1);

    for (i = 0; i < size * size; i++)
    {
        matrix[i] = rand() % 100;
    }

    return matrix;
}

void print_matrix(const char *name, double *matrix, int size)
{
    int i, j;
    printf("matrix: %s \n", name);

    for (i = 0; i < size; i++)
    {
            for (j = 0; j < size; j++)
            {
                printf("%f ", matrix[i * size + j]);
            }
            printf("\n");
    }
}


int my_dgesv(int n, double *a, double *b) {
    //Replace with your implementation
	int i,j,k,col;
	double c,sum=0.0;
	double matriz_aumentada[n][n+1];	
	double x[n][n];

// Para cada columna de b
	for (col = 0; col < n; col++)
	{
	//Copiar el contenido de a en la matriz aumentada	
		for (i = 0; i < n; i++)
   		{
        		for (j = 0; j < n; j++)
        		{
				matriz_aumentada[i][j]=a[i*n+j];
            		}
			// Para cada fila i añadir el valor de la columna B a la matriz aumentada
			matriz_aumentada[i][j]=b[i*n +col];
   		}
		for(j=0; j<n; j++) // loop for the generation of upper triangular matrix
    		{
        		for(i=0; i<n; i++)
        		{
            			if(i>j)
				{
                			c=matriz_aumentada[i][j]/matriz_aumentada[j][j];
		                	for(k=0; k<=n; k++)
                			{
                				matriz_aumentada[i][k]=matriz_aumentada[i][k]-c*matriz_aumentada[j][k];
                			}
            			}
        		}
    		}
    		x[n-1][col]=matriz_aumentada[n-1][n]/matriz_aumentada[n-1][n-1];
    	
	// this loop is for backward substitution
    		for(i=n-2; i>=0; i--)
		{
        		sum=0;
        		for(j=i; j<n; j++)
        		{
        		    	sum=sum+matriz_aumentada[i][j]*x[j][col];
        		}
			x[i][col]=(matriz_aumentada[i][n]-sum)/matriz_aumentada[i][i];
   	 	}
	}
// Poner la solución en B
	for (i = 0; i < n; i++)
	{
        	for (j = 0; j < n; j++)
        	{
                b[i*n+j]=x[i][j];
                }
        }
}




 void main(int argc, char *argv[])
    {

        int size = atoi(argv[1]);

        double *a; 
        double *b;

        a = generate_matrix(size);
        b = generate_matrix(size);



        //print_matrix("A", a, size);
        //print_matrix("B", b, size);



        // Usar eliminacion Gaussiana
	clock_t tStart = clock();      
        my_dgesv(size, a, b);
        printf("Time taken by my implementation: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);


//        print_matrix("X", b, size);
//        print_matrix("Xref", bref, size);
    }
