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

    
    void insertEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

  
    void deleteValue(int value)
    {
        if (head == NULL)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

       
        if (head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << value << " deleted." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL &&
               temp->next->data != value)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << value << " not found." << endl;
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;

        delete deleteNode;

        cout << value << " deleted." << endl;
    }

    
    void display()
    {
        Node* temp = head;

        cout << "Queue (Front to Back): ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    
    void reversePrint(Node* temp)
    {
        if (temp == NULL)
            return;

        reversePrint(temp->next);

        cout << temp->data << " ";
    }

    void displayReverse()
    {
        cout << "Queue (Back to Front): ";
        reversePrint(head);
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.insertEnd(10);
    q.insertEnd(20);
    q.insertEnd(30);
    q.insertEnd(40);
    q.insertEnd(50);

    cout << "Original Queue:" << endl;
    q.display();

    cout << endl;

    q.deleteValue(30);

    cout << endl;

    q.display();

    q.displayReverse();

    return 0;
}