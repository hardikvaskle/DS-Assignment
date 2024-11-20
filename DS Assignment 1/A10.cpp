#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string mobileNumber;
    Contact* next;
};

class ContactList {
private:
    Contact* head;
public:
    ContactList() {
        head = nullptr;
    }

void addContact(string name, string mobileNumber) {
    Contact* newContact = new Contact();
      newContact->name = name;
      newContact->mobileNumber = mobileNumber;
      newContact->next = head;
        head = newContact;
    }

 void displayContacts() {
        Contact* current = head;
        while (current != nullptr) {
            cout << "Name" << current->name << " Mobile Number" << current->mobileNumber << endl;
            current = current->next;
        }
    }

    void deleteContact(string name) {
        Contact* current = head;
        Contact* previous = nullptr;
        while (current != nullptr && current->name != name) {
            previous = current;
            current = current->next;
        }
        if (current == nullptr) {
            cout << "Contact not found" << endl;
            return;
        }
        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        delete current;
        cout << "Contact deleted" << endl;
    }

    void searchContact(string name) {
        Contact* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                cout << "Found Contact - Name" << current->name << "Mobile Number" << current->mobileNumber << endl;
                return;
            }
            current = current->next;
        }
        cout << "Contact not found" << endl;
    }
};

int main() {
 ContactList contacts;
    contacts.addContact("ram", "1234567890");
    contacts.addContact("sham", "9876543210");
    contacts.addContact("sama", "5555555555");

    cout << "Contact List:" << endl;
    contacts.displayContacts();

    cout << "\nSearch for sham" << endl;
    contacts.searchContact("sham");

    cout << "\nDelete ram" << endl;
    contacts.deleteContact("ram");

    cout << "\nContact List after deletion:" << endl;
    contacts.displayContacts();

    return 0;
}
