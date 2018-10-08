#include <time.h>
#include <stdio.h>
#include <stdlib.h>

 void main(int argc, char *argv[])
    {

	
	double c,sum=0.0;
	int size = atoi(argv[1]);
	int i,j,k,col;

	double *a = (double *)malloc(sizeof(double) * size * size);
	double *b = (double *)malloc(sizeof(double) * size * size);
	double matriz_aumentada[size][size+1];	
	double x[size][size];
	srand(1);
	
    	for (i = 0; i < size * size; i++)
    	{
        	a[i] = rand() % 100;
		b[i] = rand() % 100;

    	}

 


        //print_matrix("A", a, size);
        //print_matrix("B", b, size);



        // Usar eliminacion Gaussiana
	clock_t tStart = clock();      
 	
	// Para cada columna de b
	for (col = 0; col < size; col++)
	{
	//Copiar el contenido de a en la matriz aumentada	
		for (i = 0; i < size; i++)
   		{
        		for (j = 0; j < size; j++)
        		{
				matriz_aumentada[i][j]=a[i*size+j];
            		}
			// Para cada fila i añadir el valor de la columna B a la matriz aumentada
			matriz_aumentada[i][j]=b[i*size +col];
   		}
		for(j=0; j<size; j++) // loop for the generation of upper triangular matrix
    		{
        		for(i=0; i<size; i++)
        		{
            			if(i>j)
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


//        print_matrix("X", b, size);
//        print_matrix("Xref", bref, size);
    }
