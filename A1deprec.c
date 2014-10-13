/* Filename: A1deprec.c
   Part of: Homework Assignment 1
   Created by: Jared
   Created on: 9/10/14
   Last Modified by: Jared
   Last Modified on: 10/12/14 */


// Annual Depreciation = (Purchase Price - Salvage Value)/ Years of Service

//   Salvage Value = Purchase Price - (Annual Depreciation * Years of Service)



// This function calculates the Salvage value when the Purchase Price, 
// Years of Service, and Annual Depreciation are entered. 
// Each value is a value used in the Annual Depreciation formula that has just been
// rewritten so that it calculates Salvage Value.
// The output of the function is a print statement with the Salvage Value.


#include <stdio.h>

int main() {

  float purchasePrice, yearsofService, salvageValue, annualDepreciation;

  // the float type was used to handle decimals
  // print statement prompts you for three input values

  printf("Enter the Purchase Price, Years of Service, Annual Depreciation: ");
  scanf("%f %f %f", &purchasePrice, &yearsofService, &annualDepreciation);

  // formula used to calculate the output value
  salvageValue = purchasePrice - (annualDepreciation * yearsofService);

  printf("The Salvage Value of the item is: %f\n", salvageValue);
  
  // print statement which returns a statement and the salvage value

  return(0);


}
