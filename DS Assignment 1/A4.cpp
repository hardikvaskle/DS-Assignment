#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons, int &swaps) {
comparisons = 0;
    swaps = 0;
 for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
           if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                  swaps++;
          }
     }
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
    bubbleSort(arr, n, comparisons, swaps);
    cout << "Sorted array \n";
    printArray(arr, n);
    cout << "Comparisons " << comparisons << "\nSwaps" << swaps << endl;
    return 0;
}

