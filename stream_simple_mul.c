/*


    gcc -O1 stream_simple.c -lm -o stream_simple

*/

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <sys/time.h>

#define OUTER_LOOP_ITERS 1000 /* outer loop iterations */
#define MAXSIZE 1000000       /* inner loop iterations, and row length of arrays */
// /* 1/8 */
// #define FLOPs_per_Loop 2.0         /* MODIFY this and ALL other lines marked "MODIFY" */
// #define Unique_Reads_per_Loop 16.0 /* MODIFY this and ALL other lines marked "MODIFY" */

// /* 1/4 */
// #define FLOPs_per_Loop 4.0         /* MODIFY this and ALL other lines marked "MODIFY" */
// #define Unique_Reads_per_Loop 16.0 /* MODIFY this and ALL other lines marked "MODIFY" */

// /* 1/2 */
// #define FLOPs_per_Loop 2.0        /* MODIFY this and ALL other lines marked "MODIFY" */
// #define Unique_Reads_per_Loop 4.0 /* MODIFY this and ALL other lines marked "MODIFY" */

// /* 1 */
// #define FLOPs_per_Loop 2.0        /* MODIFY this and ALL other lines marked "MODIFY" */
// #define Unique_Reads_per_Loop 2.0 /* MODIFY this and ALL other lines marked "MODIFY" */

// /* 2 */
// #define FLOPs_per_Loop 4.0        /* MODIFY this and ALL other lines marked "MODIFY" */
// #define Unique_Reads_per_Loop 2.0 /* MODIFY this and ALL other lines marked "MODIFY" */

/* 4*/
// #define FLOPs_per_Loop 4.0        /* MODIFY this and ALL other lines marked "MODIFY" */
// #define Unique_Reads_per_Loop 1.0 /* MODIFY this and ALL other lines marked "MODIFY" */

/* 8 */
#define FLOPs_per_Loop 8.0        /* MODIFY this and ALL other lines marked "MODIFY" */
#define Unique_Reads_per_Loop 1.0 /* MODIFY this and ALL other lines marked "MODIFY" */

#define Arithmetic_Intensity (FLOPs_per_Loop / Unique_Reads_per_Loop) /* recommended range =  [1/8 , 2] */

/* gtod_seconds() gets the current time in seconds using gettimeofday */
double gtod_seconds(void)
{
  struct timeval tp;
  struct timezone tzp;
  int i;

  i = gettimeofday(&tp, &tzp);
  return ((double)tp.tv_sec + (double)tp.tv_usec * 1.e-6);
}

static float in[MAXSIZE], out[MAXSIZE]; // input and output arrays

/* A two-dimensional array of integer values, useful for varying the number
   of memory accesses without affecting FLOPs. The code as given below (before
   you modify it) has 8 reads/flop. The 8 reads come from 7 rows of this 2D
   integer array, plus one item of the float array "a". */
int integer[7][MAXSIZE];

int main()
{
  double start_time;
  long int i, j, k;
  double total_time = 0;
  double time2;
  double total_flops, flops_per_second, gflops_per_second;
  float quasi_random = 0;
  float final_answer = 0;

  /* All arrays should be initialized */
  for (i = 0; i < MAXSIZE; i++)
  {
    /* Chaotic dynamics iteration, related to the Julia and Mandelbrot sets. */
    quasi_random = quasi_random * quasi_random - 1.923432;
    in[i] = quasi_random;
    for (j = 0; j < 7; j++)
    {
      integer[j][i] = j * 1234 + i;
    }
  }

  start_time = gtod_seconds();
  for (i = 0; i < OUTER_LOOP_ITERS; i++)
  {
    quasi_random = quasi_random * quasi_random - 1.923432;
    final_answer += quasi_random + 1.0e-6 * out[i];
    for (j = 0; j < MAXSIZE; j++)
    {
      // out[j] = quasi_random * in[j] + (float)(integer[0][j] + integer[1][j] + integer[2][j] + integer[3][j] + integer[4][j] + integer[5][j] + integer[6][j]); /* MODIFY this and ALL other lines marked "MODIFY" */
      // 2/16 or 1/8
      // out[j] = quasi_random * in[j] + (float)(integer[0][j] + integer[1][j] + integer[2][j] + integer[3][j] + integer[4][j] + integer[5][j] + integer[6][j] + integer[0][j + 1] + integer[1][j + 1] + integer[2][j + 1] + integer[3][j + 1] + integer[4][j + 1] + integer[5][j + 1] + integer[6][j + 1] + integer[0][j + 2]);
      // // 4/16 or 1/4
      // out[j] = quasi_random * in[j] + in[j] * in[j] + (float)(integer[0][j] + integer[1][j] + integer[2][j] + integer[3][j] + integer[4][j] + integer[5][j] + integer[6][j] + integer[0][j + 1] + integer[1][j + 1] + integer[2][j + 1] + integer[3][j + 1] + integer[4][j + 1] + integer[5][j + 1] + integer[6][j + 1] + integer[0][j + 2]);
      // // 2/4 or 1/2
      // out[j] = quasi_random * in[j] + (float)(integer[0][j] + integer[1][j] + integer[2][j]);
      // // 1 or 1/1
      // out[j] = quasi_random * in[j];

      // 4 or 4/1
      // out[j] = quasi_random * in[j] + in[j] * in[j] + in[j];
      // 8 or 8/1
      // out[j] = quasi_random * in[j] + in[j] * in[j] + in[j] * in[j] + in[j] * in[j] + in[j];
      out[j] = in[j] * in[j] * in[j] * in[j] * in[j] * in[j] * in[j] * in[j] * in[j];
    }
  }
  total_time = gtod_seconds() - start_time;

  total_flops = ((double)FLOPs_per_Loop) * ((double)OUTER_LOOP_ITERS) * ((double)MAXSIZE);

  flops_per_second = total_flops / total_time;

  gflops_per_second = flops_per_second / 1.0e9;

  printf("AI = %f    GFLOPs/s = %f    time = %f\n",
         Arithmetic_Intensity, gflops_per_second, total_time);

  // In previous semesters this program had the following (incomprehensible)
  // calculation and printout
  // time2 = total_time / (double)OUTER_LOOP_ITERS;
  // printf ("AI*GFLOPS/sec = %f \n", (double)(Arithmetic_Intensity)/(time2*1000.0) );

  /* To prevent over-optimization on some machines and compilers, we
     randomly select an element of the output array out[] and print it. */
  final_answer += total_time;
  j = (*((int *)(&final_answer))) & 0xFFFFFFF;
  final_answer = out[j % MAXSIZE];
  printf("We spent all this time calculating %g\n", final_answer);

  return 0;
}