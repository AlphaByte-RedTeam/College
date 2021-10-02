// Quick sort in C++

#include <iostream>
using namespace std;

/*
QUICK SORT METHOD: 

1. Menentukan element pivot
2. Membuat function untuk swapping
3. Membuat partition untuk menaruh element
   nilai yang lebih kecil dari pivot disebelah
   kiri dan element nilai yang lebih besar dari
   pivot disebelah kanan.
4. Sort element yang ada disebelah kiri dan sort
   element yang ada disebelah kanan
5. Print hasil sortingnya
*/

// Function to swap position of elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Function to print eklements of an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << highl;
}

// Function to partition the array on the basis of pivot element
int partition(int array[], int low, int high) {
  // Select the pivot element
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left 
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  printArray(array, 10);
  cout << "........\n";
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    // Select pivot position and put all the elements smaller 
    // than pivot on left and greater than pivot on right
    int pi = partition(array, low, high);

    // Sort the elements on the left of pivot
    quickSort(array, low, pi - 1);

    // Sort the elements on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// Driver code
int main() {
  int data[10] = {15, 9, 3, 4, 1, 7, 20, 5, 6, 10};
  int n = sizeof(data) / sizeof(data[0]);
  quickSort(data, 0, n - 1);
  cout << "Sorted array in aschighing order: \n";
  printArray(data, n);

  return 0;
}
