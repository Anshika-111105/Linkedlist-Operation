#include <iostream>
using namespace std;
struct Node {
    int info;
    Node* next;
};
void enqueue(int value,Node **front,Node **rear) {
        Node* newNode =(Node *)malloc(sizeof(Node)); 
        newNode->info = value;
        newNode->next = nullptr;
        if (*front== nullptr)
        {
            *front=*rear=newNode;
            return;
        }
        (*rear)->next = newNode;
        *rear = newNode;
    }
int dequeue(Node **front,Node **rear) {
    if (*front == nullptr) {
        cout<<"Queue is empty!"<< endl;
        return -1;
    }
    int deleted_value=(*front)->info;
    Node* temp=*front;
    *front=(*front)->next;
    if (*front==nullptr){
        *rear=nullptr;
    }
    delete temp;
    return deleted_value;
    }
void display(Node *front) {
    if (front==nullptr) {
        cout<<"Queue is empty."<<endl;
            return;
        }
    Node* temp = front;
    while (temp != nullptr) {
        cout << temp->info<<"\t";
        temp=temp->next;
    }
        cout << endl;
}
int main() {
    Node* front=nullptr;  
    Node* rear=nullptr;
    enqueue(10,&front,&rear);
    enqueue(20,&front,&rear);
    enqueue(30,&front,&rear);
    enqueue(40,&front,&rear);
    cout << "Queue after enqueuing:"<<endl;
    display(front);
    cout << "Deleted value:"<<dequeue(&front,&rear)<<endl;
    cout << "Queue after dequeue:" << endl;
    display(front);
    cout<<"Dequeued: "<<dequeue(&front,&rear)<<endl;
    cout <<"Queue after dequeue:"<<endl;
    display(front);

    return 0;
}

/*
1.create a linkedlist for insert and delete in sorted order
2.Addition of 2 polynomial using linkedlist

1.insertion
2.bubble
3.selection
4.merge
5.quick

test within 7days
*/
