#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "mkl_lapacke.h"

#define ERR 0.00000001

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

int check_result(double *bref, double *b, int size) {
    int i;
    for(i=0;i<size*size;i++) {
        if ((bref[i]-b[i])>ERR)
		 return 0;
    }
    return 1;
}

/*
n 	The number of linear equations, i.e., the order of the matrix A.  N >= 0
nrhs 	The number of right hand sides, i.e., the number of columns of the matrix B. NRHS >= 0.
A 	is DOUBLE PRECISION array, dimension (LDA,N)
          On entry, the N-by-N coefficient matrix A.
          On exit, the factors L and U from the factorization
          A = P*L*U; the unit diagonal elements of L are not stored.
LDA 	The leading dimension of the array A.  LDA >= max(1,N).
ipiv	IPIV is INTEGER array, dimension (N) The pivot indices that define the 		permutation matrix P;row i of the matrix was interchanged with row IPIV(i).
b 	is DOUBLE PRECISION array, dimension (LDB,NRHS)
          On entry, the N-by-NRHS matrix of right hand side matrix B.
          On exit, if INFO = 0, the N-by-NRHS solution matrix X.
ldb	LDB is INTEGER The leading dimension of the array B.  LDB >= max(1,N).
*/
int my_dgesv(int n, int nrhs, double *a, int lda, int *ipiv, double *b, int ldb) {
    //Replace with your implementation
	int i,j,k,col;
	double c,sum=0.0;
	double matriz_aumentada[n][n+1];	
	double x[n][n];

// Para cada columna de b
	for (col = 0; col < ldb; col++)
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

        double *a, *aref;
        double *b, *bref;

        a = generate_matrix(size);
        aref = generate_matrix(size);
        b = generate_matrix(size);
        bref = generate_matrix(size);



        //print_matrix("A", a, size);
        //print_matrix("B", b, size);

        // Using MKL to solve the system
        MKL_INT n = size, nrhs = size, lda = size, ldb = size, info;
        MKL_INT *ipiv = (MKL_INT *)malloc(sizeof(MKL_INT)*size);

        clock_t tStart = clock();
        info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs, aref, lda, ipiv, bref, ldb);
        printf("Time taken by MKL: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

        // Usar eliminacion Gaussiana
	tStart = clock();      
        my_dgesv(n, nrhs, a, lda, ipiv, b, ldb);
        printf("Time taken by my implementation: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

        if (check_result(bref,b,size)==1)
            printf("Result is ok!\n");
        else
            printf("Result is wrong!\n");

        print_matrix("X", b, size);
        print_matrix("Xref", bref, size);
    }
