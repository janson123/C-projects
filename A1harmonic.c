/* Filename: A1harmonic.c
   Part of: Homework Assignment one
   Created by: Jared
   Created on: 9/10/14
   Last Modified by: Jared
   Last Modified on: 10/12/14 */




// This function prints a sentence asking for a postive input value and 
// finds the harmonic series for that given input value.
// If a user accidentally inputs a negative number or a zero, then it prints a
// statement telling them to enter a positive value.

// inputs are positive integer or floating point number
// (since floats can handle both).
// output is a print statement saying the 
//  harmonic series for the given input value.

#include <stdio.h>

int main() {

  // a float is used to maintain decimal precision

  float number, sum;

  printf("Enter a value to calculate the value of this harmonic series: ");
  scanf("%f", &number);

  if(number <= 0){
    printf("Please enter a POSITIVE Number: ");
    scanf("%f", &number);
  }

  // a float variable is needed for i, otherwise the sum wouldn't have
  // correct decimal values.
  // if the number entered is zero or a negative, it prompts the user with a
  // print sentence asking for a positive number.
  //

  float i;

  for(i = 1; i <= number; i++){
    sum = sum + (1/i);
  }

  // a basic for loop is used; i is less than or equal to number so it includes
  // number in the sum; sum starts at one and is changed with each pass of the loop
  // as fractional values are added to the sum.
  // the function ends with the print statement saying what the sum is.

  printf("The value for the series is: %f\n", sum);

  return (0);


}
