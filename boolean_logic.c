/************************************************************************/
/* */
/* This C program demonstrates how to write a generic logic function */
/* that can compute any logic function of four variables. Given C’s */
/* bit manipulation operators, along with hexadecimal I/O, this is an */
/* easy task to accomplish in the C programming language. */
/* */
/************************************************************************/
#include <stdlib.h>
#include <stdio.h>
/* Generic logic function. The “Func” parameter contains the 16-bit */
/* logical function number. This is actually an encoded truth table */
/* for the function. The a, b, c, and d parameters are the inputs to */
/* the logic function. If we treat “func” as a 2x2x2x2 array of bits, */
/* this particular function selects bit “func[d,c,b,a]” from func. */
int generic(int func, int a, int b, int c, int d)
{
 /* Return the bit specified by a, b, c, and d */
 
 return (func >> (a + b*2 + c*4 + d*8)) & 1;
}
/* Main program to drive the generic logic function written in C. */
main()
{
 int func, a, b, c, d;
 /* Repeat the following until the user enters zero. */
 
 do
 {
 /* Get the function’s number (truth table) */
 
 printf(“Enter function value (hex): “);
 scanf(“%x”, &func);
 
 /* If the user specified zero as the function #, stop */
 /* the program. */
 
 if (func != 0)
 {
 printf(“Enter values for d, c, b, & a: “);
 scanf(“%d%d%d%d”,
 &d, &c, &b, &a);
 printf(“The result is %d\n”, generic(func,a,b,c,d));
 printf(“Func = %x, A=%d, B=%d, C=%d, D=%d\n”,
 func, a, b, c, d);
 }
 
 } while (func !=0);
}
