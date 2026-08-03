#include <iostream>
using namespace std;


int iterativeSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}


int recursiveSearch(int arr[], int n, int target, int i) {
    if (i == n)
        return -1;

    if (arr[i] == target)
        return i;

    return recursiveSearch(arr, n, target, i + 1);
}

int main() {
    int n, target;

    cout << "Enter number of license plates: ";
    cin >> n;

    int arr[100];

    cout << "Enter license plate numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target plate: ";
    cin >> target;

    int a = iterativeSearch(arr, n, target);
    int b = recursiveSearch(arr, n, target, 0);

    if (a != -1)
        cout << "Iterative Search: Found at position " << a + 1 << endl;
    else
        cout << "Iterative Search: Not Found" << endl;

    if (b != -1)
        cout << "Recursive Search: Found at position " << b + 1 << endl;
    else
        cout << "Recursive Search: Not Found" << endl;

    return 0;
}
