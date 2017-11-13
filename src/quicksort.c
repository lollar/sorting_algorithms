#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int randomSize = rand() % 100 + 10;

  int testArray[randomSize];
  int arraySize = sizeof(testArray) / sizeof(testArray[0]);

  // fill array with random numbers
  for(int i = 0; i < arraySize; i++) {
    testArray[i] = rand();
  }

  int partition = 1;
  if(arraySize % 3 == 0) {
    partition = arraySize / 3;
  } else if (arraySize % 4 == 0) {
    partition = arraySize / 4;
  } else {
    partion = arraySize / 2;
  }

  for(int i = 0; i < arraySize; i++) {
    printf("Element #%d: %d\n", i, testArray[i]);
  }

  getchar();
  return 0;
}
