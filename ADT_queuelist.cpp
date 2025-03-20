#include <iostream>
using namespace std;
typedef struct Node{
    int data;
    Node* next;
}Node;
struct Queue {
    Node* front;  // Front of the queue
    Node* rear;   // Rear of the queue
};
Node* createNode(int value) {
    Node* newnode=(Node *)malloc(sizeof(Node));
    if(!newnode){
        cout<<"No sufficient space!"<<endl;
        exit(1);
    }
    newnode->data=value;
    newnode->next=nullptr;
    return newnode;
}
Queue* createQueue() {
    Queue* q=new Queue(); //DMA using new keyword
    q->front=q->rear = nullptr;
    return q;
}
bool isEmpty(Queue* q) {
    if(q->front==nullptr){
        return true;
    }else{
        return false;
    }
}
void enqueue(Queue* q,int value) {
    Node* newnode=createNode(value);
    if(q->rear==nullptr){
        q->front=q->rear=newnode;
        return;
    }
    q->rear->next=newnode;
    q->rear=newnode;
}
int dequeue(Queue* q) {
    if (isEmpty(q)){
        cout<<"Queue is empty!"<<endl;
        return -1;
    }
    Node* temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;
    if (q->front == nullptr) {
        q->rear = nullptr;
    }
    delete temp;
    return dequeuedValue;
}
void display(Queue* q) {
    if (isEmpty(q)) {
        cout<<"Queue is empty!"<<endl;
        return;
    }
    Node* temp=q->front;
    while (temp!=nullptr) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}
int main() {
    Queue* q=createQueue();
    enqueue(q,-8);
    enqueue(q,20);
    enqueue(q,64);
    enqueue(q,56);
    enqueue(q,76);
    enqueue(q,-83);
    enqueue(q,100);
    cout<<"****************************"<<endl;
    cout<<"ELEMENTS PRESENT IN A QUEUE:"<<endl;
    cout<<"****************************"<<endl;
    //cout<<endl;
    display(q);
    //cout<<endl;
    cout << "Dequeued element: "<<dequeue(q)<<endl;
    display(q);
    cout << "Dequeued element: "<<dequeue(q)<<endl;
    display(q);
    return 0;
}