#include <gb/gb.h>
#include <stdio.h>
#include <rand.h>
#include <gb/drawing.h>

void swapValues(int *randomArray, int index1, int index2) {
  int intermediateValue = 0;
  intermediateValue = (randomArray)[index1];
  (randomArray)[index1] = (randomArray)[index2];
  (randomArray)[index2] = intermediateValue; 
  // printf("Swapped: %d with %d, idx:%d,%d\n", (randomArray)[index2], (randomArray)[index1], index2, index1);
}

void bubbleSort(int *randomArray, int arrayLength) {
  int i = 0;
  int j = 0;
  int intermediateValue = 0;

  for(i = 0; i < arrayLength - 1; i++) {
    for(j = 0; j < arrayLength - i - 1; j++) {
      if((randomArray)[j] > (randomArray)[j + 1]) {
        swapValues(randomArray, j, j + 1);
      }
    }
  }
}

void selectionSort(int *randomArray, int arrayLength) {
  int i = 0;
  int j = 0;
  int intermediateValue = 0;
  int minIndex = 0;

  for(i = 0; i < arrayLength - 1; i++) {
    minIndex = i;
    for(j = i + 1; j < arrayLength; j++) {
      if((randomArray)[j] < (randomArray)[minIndex]) {
        minIndex = j;
      }
      swapValues(randomArray, minIndex, i);
    }
  }
}

void generateRandomArray(int *randomArray, int arrayLength) {
  int i = 0;

  for(i = 0; i < arrayLength; i++) {
    (randomArray)[i] = arrayLength - i; // Rand starts at -127.
  }
}

void printArray(int array[], int arrayLength) {
  int i = 0;
  
  printf("[");
  for(i = 0; i < arrayLength; i++) {
    printf("%d,", array[i]);
  }
  printf("]");
}

void main(void)
{

  unsigned int i = 0;

  int randomArray[300];
  int arrayLength = 300;

  /* We use the DIV register to get a random initial seed */

  generateRandomArray(&randomArray, arrayLength);

  //printArray(randomArray, arrayLength);
  printf("Generated reverse array.\n");

  selectionSort(&randomArray, arrayLength);
  printf("Selection Sort Completed.\n");
  generateRandomArray(&randomArray, arrayLength);
  printf("Generated reverse array.\n");
  bubbleSort(&randomArray, arrayLength);
  printf("Bubble Sort Completed.\n");

  printArray(randomArray, arrayLength);

}
