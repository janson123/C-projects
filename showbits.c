/* 
   Filename: showbits.c
   Part of: Assignment three
   Created by: Jared
   Created on: 10/8/14
   Last Modified by: Jared
   Last Modified on: 10/12/14

*/


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// function prototype
void showbits(unsigned int n);

int main(void)

{
  
  // calling both of the functions in the main

  void showbits(unsigned int n);
  bitcalculator();


  return(0);
}


// this function doesn't return anything, but takes an unsigned integer.
// showbits is a function that takes an unsigned integer in base 10, and prints out the binary form of the number.
// since I used an unsigned integer, it can handle negative integer inputs correctly.
// it prints out all 32 bits of the binary number, even if the number doesn't use all of them.
// the extras are just zeros out front.
void showbits(unsigned int n)
{

  // increment int variable

  int i;

  // starts at 31 and goes down and includes 0, totalling 32.
  // this function prints out the binary up to and including 32 bits.
  // each loop left shifts i amount and then ANDS to the number passed into the function.
  // it then right shifts i amount and prints. i is then decreased by 1, and the loop starts over again
for (i = 31; i >= 0; i--){
  printf("%u", (n & (1 << i)) >> i);
 
 }
}

