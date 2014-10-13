/*

Filename: calculator.c
partof: assignment 2
createdby: Jared
LastModifiedon: 10/12/14


*/


#include <stdio.h>
#include <string.h>


// below is a simple calculator function


void Calculator()
  
{
  
  
  char operator;
  double acc,number;
  
  int b;
  b = 0;
  
  // creating my own boolean

  printf("Begin Calculations \n");
  
  printf("Initialize your Accumulator with data of the form \"number\" \"S\" which sets the Accumulator to the value of your number. \n");

  // if b is 0 then it will run through the calculator in a loop
  // when the operator E is entered after a number b becomes 1 and the loop ends.
  // there are cases for +,/,*,-, and S for saving a value to the accumulator
  // if something besides these are entered then it says unknown operator.

  while(b == 0){
    scanf("%lf %s", &number, &operator);
    switch(operator){
    case 'S':
      acc = number;
      printf("Value in the Accumulator = %lf\n", acc);
      break;
    case '+':
      acc = acc + number;
      printf("Value in the Accumulator = %lf\n", acc);
      break;
    case '*':
      acc = acc * number;
      printf("Value in the Accumulator = %lf\n", acc);
      break;
    case '-':
      acc = acc - number;
      printf("Value in the Accumulator = %lf\n", acc);
      break;
    case '/':
      if(number == 0){
	printf("Can not divide by 0.\n");
	printf("Value in the Accumulator = %lf\n", acc);
	break;
      }
      else {
	acc = acc / number;
	printf("Value in the Accumulator = %lf\n", acc);
	break;
      }
    case 'E':
      printf("Value in the Accumulator = %lf\n", acc);
      printf("End of Calculations. \n");     
      b = 1;
      break;
    default:
      printf("Unknown operator. \n");
      break;
    }
  }
  
}

int main(void)
{

  printf(" \n");
  printf("Below is a calculator function. \n");
  printf(" \n");
  printf(" \n");

  Calculator();




return(0);

}
