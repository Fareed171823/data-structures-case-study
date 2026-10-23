#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;

    cout << "Enter number of package weights: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of packages!\n";
        return 0;
    }

    int* weights = new int[n];

    cout << "Enter package weights:\n";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    mergeSort(weights, 0, n - 1);

    cout << "Sorted package weights:\n";
    for (int i = 0; i < n; i++)
        cout << weights[i] << " ";

    cout << endl;

    delete[] weights;
    return 0;
}
