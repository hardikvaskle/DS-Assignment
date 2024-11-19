#include <iostream>
using namespace std;

int main() {
    char type;
    int depth, rows, cols;
    char memoryArrangement;
    int baseAddress;
    int depthIndex, rowIndex, colIndex;

    cout << "Enter type of array (i for int, c for char, f for float)";
    cin >> type;

    cout << "Enter the number of depth, rows, and columns";
    cin >> depth >> rows >> cols;

    cout << "Enter memory arrangement (R for ROW major, C for COLUMN major) ";
    cin >> memoryArrangement;

    cout << "Enter base address of the array ";
    cin >> baseAddress;

    cout << "Enter the depth, row and column index of the element";
    cin >> depthIndex >> rowIndex >> colIndex;

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
            cout << "Invalid type" << endl;
            return 1;
    }
    
    int address;
    if (memoryArrangement == 'R') { 
        address = baseAddress + ((depthIndex * rows * cols) + (rowIndex * cols) + colIndex) * elementSize;
    }
    else if (memoryArrangement == 'C') { 
        address = baseAddress + ((colIndex * rows * depth) + (rowIndex * depth) + depthIndex) * elementSize;
    } 
    else {
     cout << "Invalid memory arrangement" << endl;
        return 1;
    }

    cout << "Address of the element" << address << endl;
    return 0;
}
