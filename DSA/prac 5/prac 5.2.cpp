#include <iostream>
using namespace std;



struct SNode {
    int data;
    SNode* next;
};

class SinglyCircular {
    SNode* head;

public:
    SinglyCircular() {
        head = NULL;
    }


    void insert(int value, int position) {
        SNode* newNode = new SNode();
        newNode->data = value;


        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }


        if (position <= 1) {
            SNode* temp = head;

            while (temp->next != head)
                temp = temp->next;

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
            return;
        }


        SNode* temp = head;

        for (int i = 1; i < position - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }


    void remove(int value) {
        if (head == NULL)
            return;

        SNode* current = head;
        SNode* previous = NULL;


        if (head->next == head) {
            if (head->data == value) {
                delete head;
                head = NULL;
            }
            return;
        }


        if (head->data == value) {
            SNode* last = head;

            while (last->next != head)
                last = last->next;

            last->next = head->next;
            current = head;
            head = head->next;
            delete current;
            return;
        }


        previous = head;
        current = head->next;

        while (current != head) {
            if (current->data == value) {
                previous->next = current->next;
                delete current;
                return;
            }

            previous = current;
            current = current->next;
        }
    }


    void display() {
        if (head == NULL) {
            cout << "Empty Circle\n";
            return;
        }

        SNode* temp = head;

        cout << "Singly Circular: ";

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};


struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

class DoublyCircular {
    DNode* head;

public:
    DoublyCircular() {
        head = NULL;
    }


    void insert(int value, int position) {
        DNode* newNode = new DNode();
        newNode->data = value;


        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }


        if (position <= 1) {
            DNode* last = head->prev;

            newNode->next = head;
            newNode->prev = last;

            last->next = newNode;
            head->prev = newNode;

            head = newNode;
            return;
        }


        DNode* temp = head;

        for (int i = 1; i < position - 1 && temp->next != head; i++)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }


    void remove(int value) {
        if (head == NULL)
            return;

        DNode* current = head;


        do {
            if (current->data == value)
                break;

            current = current->next;
        } while (current != head);


        if (current->data != value)
            return;


        if (current->next == current) {
            delete current;
            head = NULL;
            return;
        }


        current->prev->next = current->next;
        current->next->prev = current->prev;


        if (current == head)
            head = current->next;

        delete current;
    }


    void display() {
        if (head == NULL) {
            cout << "Empty Circle\n";
            return;
        }

        DNode* temp = head;

        cout << "Doubly Circular: ";

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};



int main() {

    SinglyCircular single;
    DoublyCircular doubly;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int choice, value, position;

        cout << "\n1. Join Student";
        cout << "\n2. Leave Student";
        cout << "\n3. Display";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter student number: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            single.insert(value, position);
            doubly.insert(value, position);

            cout << "\nAfter Join:\n";
            single.display();
            doubly.display();
        }

        else if (choice == 2) {
            cout << "Enter student number to leave: ";
            cin >> value;

            single.remove(value);
            doubly.remove(value);

            cout << "\nAfter Leave:\n";
            single.display();
            doubly.display();
        }

        else if (choice == 3) {
            cout << "\nCurrent Circle:\n";
            single.display();
            doubly.display();
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
