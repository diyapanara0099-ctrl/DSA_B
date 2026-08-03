#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of items: ";
    cin >> n;

    int arr[n];

    cout << "Enter the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter number of hours: ";
    cin >> h;

    // Effective rotations
    h = h % n;

    cout << "Final display order: ";

    // Print from h to end
    for (int i = h; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Print remaining elements
    for (int i = 0; i < h; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
