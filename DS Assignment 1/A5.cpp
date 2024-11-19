#include <iostream>
using namespace std;

int main() {
    
    char type;
    int rows, cols;
    char memoryArrangement;
    int baseAddress;
    int rowIndex, colIndex;

    cout << " type of array (i for int, c for char, f for float): ";
    cin >> type;

    cout << " number of rows and columns: ";
    cin >> rows >> cols;

    cout << " memory arrangement (R for ROW major, C for COLUMN major): ";
    cin >> memoryArrangement;

    cout << "base address of the array: ";
    cin >> baseAddress;
    cout << "the row and column index of the element: ";
    cin >> rowIndex >> colIndex;

    int elementSize;
    switch (type) {
     case 'i':
            elementSize = sizeof(int);
            break;
    case 'c':
            elementSize = sizeof(char);
            break;
     case 'f':
            elementSize = sizeof(float);
            break;
      default:
            cout << "Invalid type!" << endl;
            return 1;
     }

    int address;
    if (memoryArrangement == 'R') { 
        address = baseAddress + ((rowIndex * cols + colIndex) * elementSize);
    }
     else if (memoryArrangement == 'C') { 
        address = baseAddress + ((colIndex * rows + rowIndex) * elementSize);
    }
     else {
        cout << "Invalid memory arrangement" << endl;
        return 1;
    }

    cout << "Address of element: " << address << endl;
    return 0;
}
