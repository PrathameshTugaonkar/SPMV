#include <stdio.h>
#include <stdlib.h>
#include<omp.h>

int main(int argc, char *argv[])
{							//Data structure for Compressed Sparse Row format 	
    int    *i_ptr, *j_ptr;
    double *a, *x, *y;
    int    row, i, j, idx, n, nnzMax, nnz, nrows;	// nnz=not non zero number
    double ts, t, rate;

    n = 10;
    if (argc > 1) n = atoi(argv[1]);


    nrows  = n * n;					//creating sizes for the matrix and rows
    nnzMax = nrows * 5;
    i_ptr = (int*)malloc(nrows*sizeof(int));
    j_ptr = (int*)malloc(nnzMax*sizeof(int));
    a  = (double*)malloc(nnzMax*sizeof(double));
    /* Allocate the source and result vectors */
    x = (double*)malloc(nrows*sizeof(double));
    y = (double*)malloc(nrows*sizeof(double));
	row = 0;
    nnz = 0;
#pragma omp parallel num_threads(8)
#pragma omp for private(i,j) schedule(dynamic)	 		//parallelizing for loop
    for (i=0; i<n; i++) {
		
{

for(j=0; j<n; j++) {
	    i_ptr[row] = nnz;
	    if (i>0) { j_ptr[nnz] = row - n; a[nnz] = -1.0; nnz++; }
	    if (j>0) { j_ptr[nnz] = row - 1; a[nnz] = -1.0; nnz++; }
	    j_ptr[nnz] = row; a[nnz] = 4.0; nnz++;
	    if (j<n-1) { j_ptr[nnz] = row + 1; a[nnz] = -1.0; nnz++; }
	    if (i<n-1) { j_ptr[nnz] = row + n; a[nnz] = -1.0; nnz++; }
	    row++;
	}
    }
   i_ptr[row] = nnz;
}

#pragma omp parallel for private(row,nrows)
    for (i=0; i<nrows; i++) x[i] = 1.0;
    ts = omp_get_wtime();			//start time

    for (row=0; row<nrows; row++) {
	double sum = 0.0;
	for (idx=i_ptr[row]; idx<i_ptr[row+1]; idx++) {
	#pragma omp parallel reduction(+:sum)
	    sum += a[idx] * x[j_ptr[idx]];
	}
	y[row] = sum;
    }
    t = omp_get_wtime();
	t=t-ts;		      //end time, difference calculates the time required for parallel execution 												
    for (row=0; row<nrows; row++) {
	if (y[row] < 0) {
	    fprintf(stderr,"y[%d]=%f, fails consistency test\n", row, y[row]);
	}
    }
    printf("Time for Sparse Ax, nrows=%d, nnz=%d, T = %f\n", nrows, nnz, t);

    free(i_ptr); free(j_ptr); free(a); free(x); free(y);
    return 0;
}
