#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int &comparisons, int &swaps) {
    comparisons = 0;
    swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
   while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
          }
        arr[j + 1] = key;
        if (j >= 0) comparisons++;
 }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons, swaps;
    insertionSort(arr, n, comparisons, swaps);
    cout << "Sorted array \n";
    printArray(arr, n);
    cout << "Comparisons" << comparisons << "\nSwaps " << swaps << endl;
    
    return 0;
}
