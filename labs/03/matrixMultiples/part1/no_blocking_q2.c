#include <stdio.h>
#include <math.h>

#define XSIZE 10
#define YSIZE 10

int main(void) {

  int x[XSIZE][YSIZE];
  int y[XSIZE][YSIZE];
  int z[XSIZE][YSIZE];
  int addrsArr[3*XSIZE*YSIZE]; // array to store addresses of array elements
  int i, j, k;

  int r;
	int mask = 0x0000FFF;	// used for bit masking
	int maskedAddr;			// stores masked address
	int addr;				// stores original address

	printf("\nx matrix:\n");
//  /* Initialize x matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
      x[i][j] = 0;
      addr = &x[i][j];				// set addr to the address of current array element
	  maskedAddr = addr & mask;	// use bit masking operations to isolate index and offset
	//printf("%08X\t", &x[i][j]);
	//addrsArr[i] = &x[i][j]);
    	printf("%08X\t", maskedAddr); // for testing purposes
    	addrsArr[i] = maskedAddr;		// add masked address to address array
    }
	printf("\n");
  }


	printf("\ny matrix:\n");
  /* Initialize y matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
	    y[i][j] = i + j;
		addr = &y[i][j];				// set addr to address of current array element
		maskedAddr = addr & mask;		// bit masking to isolate index and offset
		printf("%08X\t", maskedAddr);	// for testing purposes
		addrsArr[XSIZE+i] = maskedAddr;	// add masked address to address array
    }
    printf("\n");
  }

	printf("\nz matrix:\n");
  /* Initialize z matrix */
  for(i=0; i<XSIZE; i++) {
    for(j=0; j<YSIZE; j++) {
		z[i][j] = i + j;
		addr = &z[i][j];
		maskedAddr = addr & mask;
		printf("%08X\t", maskedAddr);
		addrsArr[XSIZE*2+i] = maskedAddr;;
    }
    printf("\n");
  }

  /* Do matrix multiply */
  for(i=0; i<XSIZE; i=i+1) {
    for(j=0; j<YSIZE; j=j+1) {
      r = 0;
      for(k=0; k<XSIZE; k=k+1) {
        r = r + y[i][k] * z[k][j];
      	// use index of address to see what element cache would map to
      	// store tag
      	// check matching tags in subsequent cmoparisons for cache miss/hit
      }
      x[i][j] = r;

    }
  }

}

/* Added Calculations
	Given:
		(a) 64 bytes/1 block --> 2^6 bytes/1 block
		(b) 32 bits/1 word --> 32 bits/1 word * 1 bytes/8 bits = 4 bytes/1 word --> 2^2 bytes/1 word
		(c) 16 Kbytes/$ --> 2^14 bytes/$
		(d) Blocks addresed to word
	Thus...
		Using (a) and (b), 2^6 bytes/1 block * 1 word/2^2 bytes = 2^4 words/1 block
			--> 4 bits of offset
		Using (c) and (a), 2^14 bytes/$ * 1 block/2^6 bytes = 2^8 blocks/$
			--> 8 bits of index
		Using above, 32 - 4 - 8 = 20 bits of tag
		*/
