//recursion
#include<iostream>
using namespace std;
typedef struct ListNode{
    int data;
    struct ListNode *next;
}node;
node* createNode(int value){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
node* insertNode(node *head,int value){
    node* newNode=createNode(value);
    if((head)==nullptr){
        head=newNode;
    }
    newNode=(head);
    (head)=newNode;
    cout<<value<<" entered succcessfully!"<<endl;
    return newNode;
}
void display(node *head) 
{ 
    while(head!=NULL) 
    { 
        cout<<head->data<<" -> "; 
        head=head->next; 
    } 
    cout<<"NULL"<<endl; 
} 
node* reverselist(node *head){
    if(!head || !head->next){
        return head;
    }
    node *temp=reverselist(head->next);
    head->next->next=head;
    head->next=nullptr;

    return temp;
}
int main(){
    node* head=NULL;
    head=insertNode(head,10);
    head=insertNode(head,15);
    head=insertNode(head,20);
    head=insertNode(head,70);
    cout<<"before reverse:";
    display(head);
    cout<<"After reverse:";
    //head=reverselist(head);
    //printList(head);
    return 0;
}
