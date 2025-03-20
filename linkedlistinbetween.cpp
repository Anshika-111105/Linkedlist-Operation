// C++ program for insertion in a single linked
// list at a specified position
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to insert a Node at required position
void insertPos(Node **head, int pos, int data, int size) {

    // This condition to check whether the
    // position given is valid or not.
    if (pos < 1 || pos > size + 1)
        return;

    Node *newNode = new Node(data);

    // head will change if pos=1
    if (pos == 1) {
        newNode->next = *head;
        *head=newNode;
    }

    Node *curr = *head;

    // Traverse to the node that will be
    // present just before the new node
    for (int i = 1; i < pos - 1; i++){
        curr = curr->next;
    }
    // update the next pointers
    newNode->next = curr->next;
    curr->next = newNode;

    //size++;
}

void printList(struct Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    // Creating the list 3->5->8->10
    Node *head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(10);
    printList(head);
    int size = 4;
    int data = 12, pos = 3;
    cout<<"Position :"<< pos<<endl;
    insertPos(&head, pos, data, size);    //3->5->12->8->10
    printList(head);                  

    return 0;
}

