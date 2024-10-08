#include <stdio.h>
#include <stdint.h>

unsigned long long int fibonacciIterative(unsigned long long int iterativeValue) {
   unsigned long long int sumOfFibonacci = 0;
   unsigned long long int previousNum = 0;
   unsigned long long int currentNum = 1;
   for (size_t indexOfLoop = 0; indexOfLoop < iterativeValue; ++indexOfLoop) {
      if (indexOfLoop == 0) { continue; } // 0 does nothing
      sumOfFibonacci = previousNum + currentNum;
      previousNum = currentNum;
      currentNum = sumOfFibonacci;
   }
   return sumOfFibonacci;
}

unsigned long long int fibonacciRecursive(unsigned long long int recursionValue) {
   if (recursionValue == 0 || recursionValue == 1) {
      return recursionValue;
   }
   return (fibonacciRecursive(recursionValue - 2)
    + fibonacciRecursive(recursionValue - 1));
}

int main(int argc, char *argv[]) {
   unsigned long long int fibN = 0;
   sscanf(argv[1], "%llu", &fibN);
   --fibN;
   char methodOfAddition = *argv[2];

   if (methodOfAddition == 'i') { // iterative
      unsigned long long int sumOfFibonacci = fibonacciIterative(fibN);
      printf("%llu", sumOfFibonacci);
   } else { // recursive
      unsigned long long int sumOfFibonacci = fibonacciRecursive(fibN);
      printf("%llu", sumOfFibonacci);
   }
   return 0;
}
