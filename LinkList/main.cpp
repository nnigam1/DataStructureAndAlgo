// Recursive C++ program to reverse
// a linked list
#include <iostream>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList()
    {
        head = NULL;
    }

    Node* recursiveReverse(Node* head)
    {
        if( head == NULL || head->next == NULL)
        {
            return head;
        }

        Node* rest = recursiveReverse(head->next);

        cout<<rest->data<<endl;

        head->next->next = head;
        head->next = NULL;
        return rest;
    }

    Node* iterativeReverse(Node* head)
    {
        Node* prev = head;
        Node* curr = head;
        curr = curr->next;
        prev->next = NULL;

        while( curr != NULL)
        {
            Node* succ = curr->next;
            curr->next = prev;
            prev = curr;
            curr = succ;
        }
        head = prev;
        return head;
    }



    /* Function to print linked list */
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print();
     cout<<endl;
    ll.head = ll.recursiveReverse(ll.head);

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}
