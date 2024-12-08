#include <iostream> 

struct Node { 
char data; 
Node* next; 
}; 

class LinkedList { 
private: 
Node* head; 
public: 
LinkedList() : head(nullptr) {} 

// Get the length of the linked list 
int getLength() { 
int length = 0; 
Node* current = head; 
while (current != nullptr) { 
length++; 
current = current->next; 
} 
return length; 
} 

// Add a node at the beginning 
void addAtBeg(char x) { 
Node* newNode = new Node(); 
newNode->data = x; 
newNode->next = head; 
head = newNode; 
} 

// Append a node at the end 
void append(char x) { 
Node* newNode = new Node(); 
newNode->data = x; 
newNode->next = nullptr; 
if (head == nullptr) { 
head = newNode; 
} else { 
Node* current = head; 
while (current->next != nullptr) { 
current = current->next; 
} 
current->next = newNode; 
} 
} 

// Add a node at a specific position 
void addAtPOS(char x, int pos) { 
if (pos < 0 || pos > getLength()) { 
std::cout << "Invalid position\n"; 
return; 
} 
Node* newNode = new Node(); 
newNode->data = x; 
if (pos == 0) { 
newNode->next = head; 
head = newNode; 
} else { 
Node* current = head; 
for (int i = 1; i < pos; i++) { 
current = current->next; 
} 
newNode->next = current->next; 
current->next = newNode; 
} 
} 

// Display the linked list 
void display() { 
Node* current = head; 
while (current != nullptr) { 
std::cout << current->data << " "; 
current = current->next; 
} 
std::cout << "\n"; 
} 

// Display more details about the linked list 
void displayMORE() { 
Node* current = head; 
while (current != nullptr) { 
std::cout << "Address: " << current << ", Value: " << current->data << ", Next: " << current->next << 
"\n"; 
} 
current = current->next; 
} 
// Remove the first node 
void removeFirst() { 
if (head != nullptr) { 
Node* temp = head; 
head = head->next; 
delete temp; 
} 
} 
// Remove the last node 
void removeLast() { 
if (head != nullptr) { 
if (head->next == nullptr) { 
delete head; 
head = nullptr; 
} else { 
Node* current = head; 
while (current->next->next != nullptr) { 
current = current->next; 
} 
delete current->next; 
current->next = nullptr; 
} 
} 
} 

// Remove a node at a specific position 
void removePOS(int pos) { 
if (pos < 0 || pos >= getLength()) { 
std::cout << "Invalid position\n"; 
return; 
} 
if (pos == 0) { 
removeFirst(); 
} else { 
Node* current = head; 
for (int i = 1; i < pos; i++) { 
current = current->next; 
} 
Node* temp = current->next; 
current->next = current->next->next; 
delete temp; 
} 
} 
}; 
int main() { 
LinkedList list; 
list.addAtBeg('a'); 
list.append('b'); 
list.addAtBeg('c'); 
list.addAtPOS('d', 1); 
list.display(); 
list.displayMORE(); 
std::cout << "Length: " << list.getLength() << "\n"; 
list.removeFirst(); 
list.removeLast(); 
list.removePOS(1); 
list.display(); 
list.displayMORE(); 
return 0; 
} 