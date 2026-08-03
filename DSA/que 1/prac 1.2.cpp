#include <iostream>
using namespace std;

void Display(int no, int id)
{
    cout << "Book ID: " << id << endl;
    cout << "Number of times borrowed: " << no << endl;
}

int main()
{
    int a, id, no;

    cout << "Enter number of books: ";
    cin >> a;

    for (int i = 0; i < a; i++)
    {
        cout << "\nEnter Book ID: ";
        cin >> id;

        cout << "Enter number of times borrowed: ";
        cin >> no;

        if (no > 1)
        {
            Display(no, id);
        }
    }

    return 0;
}
