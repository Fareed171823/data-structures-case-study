#include <iostream>
using namespace std;

struct Coach {
    int coachNo;
    Coach* next;
};

Coach* head = nullptr;

void addBeginning(int n) {
    Coach* newCoach = new Coach{n, head};
    head = newCoach;
}

void addEnd(int n) {
    Coach* newCoach = new Coach{n, nullptr};

    if (head == nullptr) {
        head = newCoach;
        return;
    }

    Coach* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newCoach;
}

void removeCoach(int n) {
    Coach* temp = head;
    Coach* prev = nullptr;

    while (temp != nullptr && temp->coachNo != n) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Coach not found!\n";
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Coach removed!\n";
}

void display() {
    Coach* temp = head;

    if (temp == nullptr) {
        cout << "No coaches available.\n";
        return;
    }

    while (temp != nullptr) {
        cout << "Coach" << temp->coachNo << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    addEnd(1);
    addEnd(2);
    addEnd(3);
    addEnd(4);

    int choice, n;

    do {
        cout << "\n1. Add coach at beginning\n";
        cout << "2. Add coach at end\n";
        cout << "3. Remove coach\n";
        cout << "4. Display coaches\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter coach number: ";
                cin >> n;
                addBeginning(n);
                break;

            case 2:
                cout << "Enter coach number: ";
                cin >> n;
                addEnd(n);
                break;

            case 3:
                cout << "Enter coach number to remove: ";
                cin >> n;
                removeCoach(n);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    while (head != nullptr) {
        Coach* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
