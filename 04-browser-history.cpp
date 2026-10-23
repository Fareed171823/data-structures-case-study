#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> history;
    int choice;
    string website;

    do {
        cout << "\n--- Browser History ---\n";
        cout << "1. Visit website\n";
        cout << "2. Go back\n";
        cout << "3. Show current website\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter website name: ";
                cin >> ws;
                getline(cin, website);
                history.push(website);
                cout << "Website visited!\n";
                break;

            case 2:
                if (history.size() > 1) {
                    history.pop();
                    cout << "Moved back successfully!\n";
                } else {
                    cout << "No previous website available!\n";
                }
                break;

            case 3:
                if (!history.empty()) {
                    cout << "Current website: "
                         << history.top() << '\n';
                } else {
                    cout << "No website visited yet!\n";
                }
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
