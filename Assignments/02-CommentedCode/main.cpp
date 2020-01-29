/////////////////////////////////////////////////////
//
// Author: Terry Griffin (commented by Austin Morris)
// Email (for commenter): ausmor23@gmail.com
// Label: A02
// Title: Code Commenting
// Course: CMPS 3013
// Semester: Spring 2020
//
// Description:
//      This program is Dr. Griffin's uncommented
//      implementation of a linked list. The program
//      has been documented as part of a graded
//      exercise in uploading files to github.
//
// Usage: Ask Terry Griffin first, it's not my IP
//
// Files: main.cpp

#include <iostream>

using namespace std;

int A[100];


// Node struct to make the linked list class more understandable
// (without this an actual linked list would be difficult to make)
struct Node {
    int x;
    Node *next;
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};

// List class
//
// Description:
//      Uses the previously defined Node struct
//      as a building block to drive the logic 
//      behind a linked list.
//
// Public Methods: 
//  - List() (Constructor)
//  - Push(int) (No return type)
//  - Insert(int) (No return type)
//  - PrintTail() (No return type)
//  - Print() (Returns string)
//  - Pop() (Returns int)
//  - + operator (Returns list)
//  - [] operator (Returns int)
//  - << operator (Returns ostream object)
//
// Private Methods:
//  - No
//
// Usage:
//  - Linked list things
//  - ???
//  - Not reinventing the wheel

class List {
private:
    Node *Head;
    Node *Tail;
    int Size;

public:
    // Easy constructor (both node pointers null)
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    void PrintTail() {
        cout << Tail->x << endl;
    }

    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    List L1;
    List L2;

    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}
