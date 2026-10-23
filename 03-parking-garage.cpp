#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> parking;
    int choice, car;

    do {
        cout << "\n--- Parking Garage ---\n";
        cout << "1. Park a car\n";
        cout << "2. Remove a car\n";
        cout << "3. Display parked cars\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter car number: ";
                cin >> car;
                parking.push(car);
                cout << "Car parked successfully!\n";
                break;

            case 2:
                if (parking.empty()) {
                    cout << "Parking garage is empty!\n";
                } else {
                    cout << "Car removed: "
                         << parking.top() << '\n';
                    parking.pop();
                }
                break;

            case 3: {
                if (parking.empty()) {
                    cout << "Parking garage is empty!\n";
                } else {
                    stack<int> temp = parking;

                    cout << "Cars (last parked first):\n";

                    while (!temp.empty()) {
                        cout << temp.top() << '\n';
                        temp.pop();
                    }
                }
                break;
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
