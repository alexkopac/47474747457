#include <iostream>
#include <cstring>

using namespace std;

struct Contact {
    char name[30];
    char homePhone[13];
    char workPhone[13];
    char mobilePhone[13];
    char info[150];
};

class Phonebook {
private:
    Contact* contacts;
    int size;

public:
    Phonebook() : contacts(nullptr), size(0) {}

    ~Phonebook() {
        delete[] contacts;
        contacts = nullptr;
    }

    void add() {
        Contact* newContacts = new Contact[size + 1];

        for (int i = 0; i < size; ++i) {
            newContacts[i] = contacts[i];
        }

        cin.ignore();

        cout << "Name: ";
        cin.getline(newContacts[size].name, 100);

        cout << "Home phone: ";
        cin.getline(newContacts[size].homePhone, 20);

        cout << "Work phone: ";
        cin.getline(newContacts[size].workPhone, 20);

        cout << "Mobile phone: ";
        cin.getline(newContacts[size].mobilePhone, 20);

        cout << "Additional info: ";
        cin.getline(newContacts[size].info, 200);

        delete[] contacts;
        contacts = newContacts;
        size++;
        cout << "Contact added" << endl;
    }

    void remove() {
        if (size == 0) {
            cout << "Phonebook is empty" << endl;
            return;
        }

        char name[100];
        cout << "Enter the name of the contact: ";
        cin.ignore();
        cin.getline(name, 100);

        for (int i = 0; i < size; ++i) {
            if (strcmp(contacts[i].name, name) == 0) {
                Contact* newContacts = new Contact[size - 1];

                for (int j = 0, k = 0; j < size; ++j) {
                    if (j != i) {
                        newContacts[k++] = contacts[j];
                    }
                }

                delete[] contacts;
                contacts = newContacts;
                size--;

                cout << "Contact deleted" << endl;
                return;
            }
        }
        cout << "Contact not found" << endl;
    }

    void search() const {
        if (size == 0) {
            cout << "Phonebook is empty" << endl;
            return;
        }

        char name[100];
        cout << "Enter the name of the contact to search: ";
        cin.ignore();
        cin.getline(name, 100);

        for (int i = 0; i < size; ++i) {
            if (strcmp(contacts[i].name, name) == 0) {
                displayOne(contacts[i]);
                return;
            }
        }
        cout << "Contact not found" << endl;
    }

    void displayAll() const {
        if (size == 0) {
            cout << "Phonebook is empty" << endl;
            return;
        }

        for (int i = 0; i < size; ++i) {
            cout << "Contact " << i + 1 << ":" << endl;
            displayOne(contacts[i]);
            cout << endl;
        }
    }

private:
    void displayOne(const Contact& contact) const {
        cout << "Name: " << contact.name << endl;
        cout << "Home Phone: " << contact.homePhone << endl;
        cout << "Work Phone: " << contact.workPhone << endl;
        cout << "Mobile Phone: " << contact.mobilePhone << endl;
        cout << "Additional Info: " << contact.info << endl;
    }
};

int main() {
    Phonebook phoneBook;

    while (true) {

        cout << endl << "Menu: " << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Delete contact" << endl;
        cout << "3. Search contact" << endl;
        cout << "4. Display all contacts" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();  

        if (choice == 1) {
            phoneBook.add();
        }
        else if (choice == 2) {
            phoneBook.remove();
        }
        else if (choice == 3) {
            phoneBook.search();
        }
        else if (choice == 4) {
            phoneBook.displayAll();
        }
        else if (choice == 5) {
            cout << "Exiting program..." << endl;
            break;
        }
        else {
            cout << "Invalid choice, try again" << endl;
        }
    }

    return 0;
}
