// Bubble Sort
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class ArraySort {
public:
  ArraySort();
  ~ArraySort();
  void randomize();
  void display();
  virtual void sort() = 0;

protected:
  int * arr;
  static const int ARR_SIZE = 100;
};

ArraySort::ArraySort(){
  arr = new int[ARR_SIZE];
}
ArraySort::~ArraySort() {
  delete[] arr;
}
void ArraySort::randomize(){
  srand(time(NULL));

  for (int i = 0; i < ARR_SIZE; i++){
    arr[i] = rand() % 1000;
  }

}

void ArraySort::display() {
  for (int i = 0; i < ARR_SIZE; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}
// END ARRAY SORT CLASS

class BubbleSort : public ArraySort {
public:
  void sort();
};

void BubbleSort::sort(){
  for (int i = 0; i < ARR_SIZE - 1; i++){
    for(int j = 0; j < ARR_SIZE - i - 1; j++) {
      if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
      }
    }
  }
}

class MergeSort : public ArraySort {
public:
  void sort();
private:
  void sort(int low, int high);
}

void MergeSort::sort() {
  if (high - low <= 1){
    return;
  }

  int mid = (low+high)/2;

  sort(0, mid);
  sort(mid, high);

  int i = low;
  int j = mid;
  int index = 0;
  int * temp = new int[high - low];

  while (i < mid && j < high){
    if (arr[i] < arr[j]) {
      temp[index] = arr[i];
      i++;
    }
    else {
      temp[index] = arr[j];
      j++;
    }
    index++;
  }

  while(i < mid){
    temp[index] = arr[i];
    i++;
    index++;
  }
  while(j < high){
    temp[index] = arr[j];
    j++;
    index++;
  }

  int oIndex = low;
  int tIndex = 0;

  for(; oIndex < high; oIndex++, tIndex++){
    arr[oIndex] = temp[tempIndex];
  }

  delete[] temp;
}

int main(){
  MergeSort bubblePower;
  bubblePower.randomize();
  bubblePower.display();
  bubblePower.sort();
  bubblePower.display();

  getchar();
  return 0;
}
