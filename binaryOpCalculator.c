/* 
   Filename: binaryOpCalculator.c
   Part of: Assignment three
   Created by: Jared
   Created on: 10/8/14
   Last Modified by: Jared
   Last Modified on: 10/9/14

*/


#include <stdio.h>
#include <math.h>
#include <string.h>


// this is a binary operations calculator



// function prototypes.

void showbits(unsigned int n);
void bitcalculator();



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


// this function takes no arguments, and doesn't return anything.

void bitcalculator()

{

  // variables used for my switch case.
  // i used a boolean for my while loop, so the loop continues until 7 is entered.
  // then boolean is changed to 1 and the loop breaks.


  int choice, boolean;
  int number, shift, changednum;

  int value1, value2, changedval;

  int step;

  boolean = 0;
  // the while loop
  while(boolean == 0){
    // the prints below are used to create the text based main menu

    printf("\n\t\t Main Menu\n");
    printf("\t\t ---------\n");

    printf("1. Perform Left Bit Shift Operation (one value) \n");
    printf("2. Perform Right Bit Shift Operation (one value) \n");
    printf("3. Perform Binary AND Operation (two values) \n");
    printf("4. Perform Binary OR Operation (two values) \n");
    printf("5. Perform Binary One's Complement (~) Operation (one value) \n");
    printf("6. Perform Binary XOR Operation (two values) \n");
    printf("7. Quit \n");
    
    // this scan lets the user enter their choice of function
    scanf("%d", &choice);
    
    // the switch case
    // you choice is fed into the switch case, 1-6 result in different functions, 7 quits the loop, and the default catches invalid inputs.

    switch(choice){
    case 1: printf("\nEnter a base 10 Integer: ");
      
      scanf("%d", &number);
      
      printf("\nEnter number of places to shift bit: ");
      
      scanf("%d", &shift);

      printf("\n\n\t Entered Integer: ");
      showbits(number);
      printf(" (base 10 %d) \n", number);
      
      printf("\t Left Shifted \t: ");
      
      changednum = (number << shift);
      // i store the shifted binary number in variable for ease of printing.
      showbits(changednum);
      printf(" (base 10 %d) \n", changednum);
      
      // this first case takes an integer in base 10, and a number that represents how much the integer in binary will be shifted to the left.
      // the showbits function is called twice to print out the original integer in binary, and the left shifted binary value.

      break;
      
    case 2: printf("\nEnter a base 10 Integer: ");
      scanf("%d", &number);
      // the entered number is printed along with text so you can see it is base 10
      printf("\nEnter number of places to shift bit: ");
      
      scanf("%d", &shift);
      // this scan lets them decide how much the integer is shifted
      printf("\n\n\t Entered Integer: ");
      showbits(number);
      printf(" (base 10 %d) \n", number);
      
      printf("\t Right Shifted \t: ");
      // below is how to shift a value in binary.
      changednum = (number >> shift);
      // the right shifted value is stored for ease of printing.
      showbits(changednum);
      printf(" (base 10 %d) \n", changednum);
      
      // this second case takes an integer in base 10, and a number that represents how much the integer in binary will be shifted to the right.
      // showbits function is called twice to print out the original integer in binary, and the right shifted binary value.

      break;
    
    case 3: printf("\nEnter two base 10 Integers, separated by a space: ");
      scanf("%d %d", &value1, &value2);
      
      printf("\n\n\t Entered Integer 1: ");
      showbits(value1);
      printf(" (base 10 %d) \n", value1);
      
      printf("\t Entered Integer 2: ");
      showbits(value2);
      printf(" (base 10 %d) \n", value2);
      // this print below looks really stupid, but it was the only way i could make the colons even with each other.
      // AND, OR, and XOR all have this format. 
      printf("\t AND'ed  \t"  "  : ");
      // below is how to and two values in binary.
      changedval = value1 & value2;
      // the and'ed value is stored for ease of printing
      showbits(changedval);
      printf(" (base 10 %d) \n", changedval);
      // this third case takes two integers in base 10, and AND's the two numbers together in binary.
      // the showbits function is called three times, to show the two integers in binary and to see the binary representation after they are AND'ed together.
      
      break;

    case 4: printf("\nEnter two base 10 Integers, separated by a space: ");
      scanf("%d %d", &value1, &value2);
      
      printf("\n\n\t Entered Integer 1: ");
      showbits(value1);
      printf(" (base 10 %d) \n", value1);
      
      printf("\t Entered Integer 2: ");
      showbits(value2);
      printf(" (base 10 %d) \n", value2);
      
      printf("\t OR'ed  \t"  "  : ");
      // below is how to OR two values in binary.
      changedval = value1 | value2;
      // the or'ed value is stored for ease of printing
      showbits(changedval);
      printf(" (base 10 %d) \n", changedval);
      // this forth case takes two integers in base 10, and OR's the two numbers together in binary.
      // the showbits function is called three times, to show the two integers in binary and to see the binary representation after they are OR'ed together.
      
      
      break;

    case 5: printf("\nEnter a base 10 Integer: ");
      
      scanf("%d", &number);
      
      printf("\n\n\t Entered Integer: ");
      showbits(number);
      printf(" (base 10 %d) \n", number);
      
      printf("\t ~'ed \t\t: ");
      // below is how to do a binary one's complement operation
      changednum = ~ number;
      // it is stored in a variable for ease of printing
      showbits(changednum);
      printf(" (base 10 %d) \n", changednum);
      // this fifth case takes one integer in base 10, and performs the one's complement operation on the entered number in binary
      // the showbits function is called twice, the first time to show the original entered base 10 integer in binary and the second time to show the binary representation of the one's complement operation being performed on the entered number.      

      break;

    case 6: printf("\nEnter two base 10 Integers, separated by a space: ");

      scanf("%d %d", &value1, &value2);
      
      printf("\n\n\t Entered Integer 1: ");
      showbits(value1);
      printf(" (base 10 %d) \n", value1);

      printf("\t Entered Integer 2: ");
      showbits(value2);
      printf(" (base 10 %d) \n", value2);

      printf("\t XOR'ed  \t"  "  : ");
      // below is how to do an exclusive or operation in binary.
      step = value1 ^ value2;
      // stored in a variable for ease of printing
      showbits(step);
      printf(" (base 10 %d) \n", step);
      // the sixth case takes two integers in base 10, and performs the exclusive or operation on the entered integers in binary.
      // the showbits function is called three times, two times to show the entered base 10 integers in binary and the third time to show the binary representation of the exclusive or operation that was performed on the two values.
      break;

    case 7:
      boolean = 1;
      break;
      // seventh case ends the loop and the exits the program

    default: printf("Invalid choice, try again. \n");
      break;
      // this default case catches invalid choices.
    }
  }
  
}
