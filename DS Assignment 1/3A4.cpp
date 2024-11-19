#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int &comparisons, int &swaps) {
    comparisons = 0;
     swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
           comparisons++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
     }
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
            swaps++;
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
    selectionSort(arr, n, comparisons, swaps);
    cout << "Sorted array \n";
    printArray(arr, n);
    cout << "Comparisons" << comparisons << "\nSwaps" << swaps << endl;
    return 0;
}
