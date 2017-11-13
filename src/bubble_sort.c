#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int unsortedArray[100];
  int arraySize = sizeof(unsortedArray) / sizeof(unsortedArray[0]);

  printf("Size: %d", arraySize);
  
  for(int i = 0; i < arraySize; i++) {
    unsortedArray[i] = rand();
    printf("Element #%d: %d\n", i, unsortedArray[i]);
  }

  int sortedArray[arraySize];

  for(int i = 0; i < arraySize; i++) {
    for(int j = 0; j < arraySize - 1; j++) {
      if(unsortedArray[j] > unsortedArray[j+1]) {
        int temp = unsortedArray[j];
        unsortedArray[j] = unsortedArray[j+1];
        unsortedArray[j+1] = temp;
      }
    }
  }

  for(int i = 0; i < arraySize; i++) {
    printf("Element #%d: %d\n", i, unsortedArray[i]);
  }

  getchar();
  return 0;
}
