#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable {
private:
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int accountNumber) {
        int index = hashFunction(accountNumber);
        int start = index;

        while (table[index] != -1) {
            index = (index + 1) % SIZE;

            if (index == start) {
                cout << "Hash table is full!\n";
                return;
            }
        }

        table[index] = accountNumber;
        cout << "Account inserted successfully!\n";
    }

    void search(int accountNumber) {
        int index = hashFunction(accountNumber);
        int start = index;

        while (table[index] != -1) {
            if (table[index] == accountNumber) {
                cout << "Account found at index "
                     << index << '\n';
                return;
            }

            index = (index + 1) % SIZE;

            if (index == start)
                break;
        }

        cout << "Account not found!\n";
    }

    void display() {
        cout << "\nHash Table:\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << " : ";

            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];

            cout << '\n';
        }
    }
};

int main() {
    HashTable ht;
    int choice, accountNumber;

    do {
        cout << "\n--- Bank Account Hash Table ---\n";
        cout << "1. Insert account number\n";
        cout << "2. Search account number\n";
        cout << "3. Display hash table\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> accountNumber;

                if (accountNumber < 0)
                    cout << "Invalid account number!\n";
                else
                    ht.insert(accountNumber);
                break;

            case 2:
                cout << "Enter account number to search: ";
                cin >> accountNumber;

                if (accountNumber < 0)
                    cout << "Invalid account number!\n";
                else
                    ht.search(accountNumber);
                break;

            case 3:
                ht.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
