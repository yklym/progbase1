
#include <stdio.h>
#include <stdlib.h>
#include <progbase.h>
#include <progbase/console.h>

int main(void) {
    int arr[11][11];
    int size = 11;
    int i, j;
    int x, y;
    int count = 0;
    int idir = 0;
    int jdir = 0;
    int lim;

    for (i = 0; i < size; i++) {
   	 for (j = 0; j < size; j++) {
   		 arr[i][j] = size * i + j + 1;
   	 }
    }
    Console_clear();

    /* initial values */
    i = 0;
    j = 0;
    idir = 0;
    jdir = 1;
    lim = 0;
    for (count = 0; count < size * size; count++) {
   	 /* output */
   	 x = 1 + (j * 5);
   	 y = 1 + i;
   	 Console_setCursorPosition(y, x);
   	 printf("%3i", arr[i][j]);
   	 fflush(stdout);  /* force console output */
   	 sleepMillis(40);
   	 /* end output */

   	 /* move next */
   	 i += idir;
   	 j += jdir;

   	 /* limits */
   	 if (j == size - lim) {
   		 j--;
   		 i++;
   		 jdir = 0;
   		 idir = 1;
   	 }
   	 if (i == size - lim) {
   		 i--;
   		 j--;
   		 idir = 0;
   		 jdir = -1;
   	 }
   	 if (j == -1 + lim) {
   		 j++;
   		 i--;
   		 idir = -1;
   		 jdir = 0;
   	 }
   	 if (i == lim && j == lim) {
   		 lim++;
   		 i = j = lim;
   		 idir = 0;
   		 jdir = 1;
   	 }
    }

    Console_setCursorPosition( 1 + (size + 1), 1);
    return 0;
}
