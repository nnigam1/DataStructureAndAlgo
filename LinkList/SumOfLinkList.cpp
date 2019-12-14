#include<iostream>
using namespace std;

//A linked list node
struct Node
{
    int data; //data belong to that node
    Node *next; //next pointer
};

// Push the data to the head of the linked list
void push(Node **head, int data)
{
    //Allocation memory to the new node
    Node *newnode = new Node;

    //Assigning data to the new node
    newnode->data = data;

    //Adjusting next pointer of the new node
    newnode->next = *head;

    //New node becomes the head of the list
    *head = newnode;
}

void finalMaxSumList(Node* a , Node* b)
{
    Node* result = NULL;
    Node* pre1 = a;
    Node* pre2 = b;

    Node* curr1 = a;
    Node* curr2 = b;

    while(curr1 != NULL || curr2 != NULL)
    {
        int sum1 = 0 , sum2 = 0;
        while(curr1 != NULL && curr2 != NULL && curr1->data != curr2->data)
        {
            if( curr1->data < curr2->data)
            {
                sum1+=curr1->data;
                curr1 = curr1->next;
            }
            if( curr2->data < curr1->data)
            {
                sum2+=curr2->data;
                curr2 = curr2->next;
            }
        }

        if( curr1 == NULL)
        {
            while( curr2 != NULL)
            {
                sum2 += curr2->data;
                curr2 = curr2->next;
            }
        }

        if( curr2 == NULL)
        {
            while( curr1 != NULL)
            {
                sum1 += curr1->data;
                curr1 = curr1->next;
            }
        }

        if( pre1 == a && pre2 == b)
        {
            result = ( sum1 > sum2 ) ? pre1 : pre2;
        } else{
            if( sum1 > sum2)
            {
                pre2->next = pre1->next;
            } else {
                pre1->next = pre2->next;
            }
        }

        pre1 = curr1 , pre2 = curr2;

        if( curr1)
            curr1 = curr1->next;
        if( curr2)
            curr2 = curr2->next;

    }

    if( result != NULL)
    {
        while( result != NULL) {
            cout << result->data<<" ";
            result = result->next;
        }
    }
    cout<<endl;
}

//Main driver program
int main()
{
    //Linked List 1 : 1->3->30->90->110->120->NULL
    //Linked List 2 : 0->3->12->32->90->100->120->130->NULL
    Node *head1 = NULL, *head2 = NULL;
    push(&head1, 120);
    push(&head1, 110);
    push(&head1, 90);
    push(&head1, 30);
    push(&head1, 3);
    push(&head1, 1);

    push(&head2, 130);
    push(&head2, 120);
    push(&head2, 100);
    push(&head2, 90);
    push(&head2, 32);
    push(&head2, 12);
    push(&head2, 3);
    push(&head2, 0);

    finalMaxSumList(head1, head2);
    return 0;
}

