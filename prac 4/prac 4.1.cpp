#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
    Node* head;

public:
    Queue()
    {
        head = NULL;
    }


    void insertFront(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        display();
    }
    void insertEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        display();
    }

    
    void insertAtPosition(int value, int position)
    {
        if (position <= 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1)
        {
            insertFront(value);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Position is greater than queue length!" << endl;
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;

        display();
    }

    
    void display()
    {
        Node* temp = head;

        cout << "Queue: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    cout << "Critical patient 10:" << endl;
    q.insertFront(10);

    cout << "Routine patient 20:" << endl;
    q.insertEnd(20);

    cout << "Routine patient 30:" << endl;
    q.insertEnd(30);

    cout << "Critical patient 5:" << endl;
    q.insertFront(5);

    cout << "Insert patient 15 at position 3:" << endl;
    q.insertAtPosition(15, 3);

    return 0;
}