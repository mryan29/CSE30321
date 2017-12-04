/* Version 4 of Problem A corresponding to Step 6:
	Modify your code from Step 5 such that 16 matrix elements (a 4x4 grid) are calculated during each
	iteration of the loop.
*/

#include <stdio.h>
#include <math.h>

#define XSIZE 200
#define YSIZE 200
#define MATRIX_SIZE 200
int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];

  int i, j, k;

  int r0, r1, r2, r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15;
	printf("Initializing y matrix...\n");
  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      y[i][j] = i + j;
    //  printf("%d ", y[i][j]);

    }
    //printf("\n");
  }

	printf("Initializing z matrix...\n");
  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	z[i][j] = i + j;
	//printf("%d ", z[i][j]);
    }
    //printf("\n");
  }

	/* unrolled loop body such that 4 matrix elements calculated each iteration:
		x[i][j], x[i+1][j], x[i][j+1], and x[i+1][j+1].
		x[i][j] replaced with variable m
	*/
	printf("Building x matrix...\n");
	for (i=0; i < MATRIX_SIZE-5; i++) {
		for (j=0; j < MATRIX_SIZE-5; j++) {
			// unrolled 4 times
			r0 = 0;
			r1 = 0;
			r2 = 0;
			r3 = 0;
			// unrolled 7 times
			r4=0;
			r5=0;
			r6=0;
			//unrolled 10 times
			r7=0;
			r8=0;
			r9=0;
			// unrolled 13 times
			r10=0;
			r11=0;
			r12=0;
			// unrolled 16 times
			r13=0;
			r14=0;
			r15=0;

			for(k=0; k < MATRIX_SIZE; k++) {
				r0	= r0 + y[i][k] * z[k][j];
				r1	= r1 + y[i+1][k] * z[k][j];
				r2	= r2 + y[i][k] * z[k][j+1];
				r3	= r3 + y[i+1][k] * z[k][j+1];
			/*	// unrolled 4 times
				m = m + y[i][k] * z[k][j];
				x[i+1][j] 	= x[i+1][j] + y[i+1][k] * z[k][j];
				x[i][j+1]	= x[i][j+1] + y[i][k] * z[k][j+1];
				x[i+1][j+1]	= x[i+1][j+1] + y[i+1][k] * z[k][j+1];
				// unrolled 7 times
			*/	r4 	= r4 + y[i+2][k] * z[k][j];
				r5	= r5 + y[i][k] * z[k][j+2];
				r6	= r6 + y[i+2][k] * z[k][j+2];
				// unrolled 10 times
				r7	= r7 + y[i+3][k] * z[k][j];
				r8	= r8 + y[i][k] * z[k][j+3];
				r9	= r9 + y[i+3][k] * z[k][j+3];
				// unrolled 13 times
				r10 = r10 + y[i+4][k] * z[k][j];
				r11	= r11 + y[i][k] * z[k][j+4];
				r12	= r12 + y[i+4][k] * z[k][j+4];
				// unrolled 16 times
				r13 = r13 + y[i+5][k] * z[k][j];
				r14	= r14 + y[i][k] * z[k][j+5];
				r15	= r15 + y[i+5][k] * z[k][j+5];
			}
			x[i][j] 	= r0;
			x[i+1][j]	= r1;
			x[i][j+1]	= r2;
			x[i+1][j+1]	= r3;
			x[i+2][j]	= r4;
			x[i][j+2]	= r5;
			x[i+2][j+2]	= r6;
			x[i+3][j]	= r7;
			x[i][j+3]	= r8;
			x[i+3][j+3]	= r9;
			x[i+4][j]	= r10;
			x[i][j+4]	= r11;
			x[i+4][j+4]	= r12;
			x[i+5][j]	= r13;
			x[i][j+5]	= r14;
			x[i+5][j+5]	= r15;

			j = j + 5;
		}
		i = i + 5;
	}
/*
	// for testing purposes
	for (i = 0; i < MATRIX_SIZE; i++) {
		for (j = 0; j < MATRIX_SIZE; j++) {
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}
*/
}
