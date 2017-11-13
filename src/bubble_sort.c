#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int testArray[100];
  int arraySize = sizeof(testArray) / sizeof(testArray[0]);
  
  // fill array with random numbers
  for(int i = 0; i < arraySize; i++) {
    testArray[i] = rand();
  }

  // sort the array
  for(int i = 0; i < arraySize; i++) {
    for(int j = 0; j < arraySize - 1; j++) {
      if(testArray[j] > testArray[j+1]) {
        int temp = testArray[j];
        testArray[j] = testArray[j+1];
        testArray[j+1] = temp;
      }
    }
  }

  for(int i = 0; i < arraySize; i++) {
    printf("Element #%d: %d\n", i, testArray[i]);
  }

  getchar();
  return 0;
}
