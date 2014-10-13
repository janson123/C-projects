/* Filename: A1prime.c
   Part of: Homework Assignment 1
   Created by: Jared
   Created on: 9/10/14
   Last Modified by: Jared
   Last Modified on: 10/12/14 */




// This function tests, and then prints whether the input value is a prime number.
// The Output is either a print statement saying the input number is a prime number
// or it is a print statement saying the input number is NOT a prime number.

// input accepts integer values


#include <stdio.h>

int main() {

  int number, i;

  // i had to create a boolean variable to handle the print statements
  // my for loop changes the variable based on whether something is prime
  // then my if statement at the end checks if that variable has been changed
  // and responds accordingly.

  int isPrime = 0;

  printf("Enter a number to check if it is a prime number: ");
  scanf("%d", &number);

  for(i = 2; i < number; i++){
    if((number % i) == 0) {
      isPrime = 0;
      break;
    }
    else {
      isPrime = 1;
    }
  }
  if(isPrime == 1){
    printf("The number %d is a prime number.\n", number);
  }
  else {
    printf("The number %d is NOT a prime number. \n", number);
  }

      // the code is a basic for loop, you need to start at 2 because starting at
      // 0 give a float error and 1 gives incorrect prime responses.


  return (0);


}
