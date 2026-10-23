#include <iostream>
using namespace std;

struct Node {
    int employeeID;
    Node* left;
    Node* right;

    Node(int id) {
        employeeID = id;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int id) {
    if (root == nullptr)
        return new Node(id);

    if (id < root->employeeID)
        root->left = insert(root->left, id);
    else if (id > root->employeeID)
        root->right = insert(root->right, id);
    else
        cout << "Employee ID already exists!\n";

    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->employeeID << " ";
        inorder(root->right);
    }
}

bool search(Node* root, int id) {
    if (root == nullptr)
        return false;

    if (root->employeeID == id)
        return true;

    if (id < root->employeeID)
        return search(root->left, id);

    return search(root->right, id);
}

int main() {
    Node* root = nullptr;
    int choice, id;

    do {
        cout << "\n--- Employee ID Management ---\n";
        cout << "1. Insert Employee ID\n";
        cout << "2. Display Employee IDs\n";
        cout << "3. Search Employee ID\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;

                if (id > 0)
                    root = insert(root, id);
                else
                    cout << "Enter a valid positive ID!\n";
                break;

            case 2:
                cout << "Employee IDs in sorted order: ";
                inorder(root);
                cout << '\n';
                break;

            case 3:
                cout << "Enter Employee ID to search: ";
                cin >> id;

                if (search(root, id))
                    cout << "Employee ID found!\n";
                else
                    cout << "Employee ID not found!\n";
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
