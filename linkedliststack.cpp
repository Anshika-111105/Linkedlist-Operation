#include<iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
};
typedef struct node node;
void *push(node **head,int value){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->info=value;
    newnode->next=*head;
}
//when returning head
/*node *pop(node *head){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    if(head==NULL){
        cout<<"Stack is empty!"<<endl;
        return 0;
    }
    else{
        temp=head;
        head=temp->next;
        temp->next=NULL;
        cout<<"\nDeleted value:"<<temp->info<<endl;
        return head;
    }
}*/
//when no return of head
void pop(node **head){
    while(*head==nullptr){
        cout<<"Stack is empty!"<<endl;
    }
    node *temp=*head;
    *head=(temp)->next;
    cout<<"\nDelete element: "<<temp->info<<endl;
    temp->next=nullptr;

}
void display(node *head){
    while(head!=NULL){
        cout<<head->info<<"\t";
        head=head->next;
    }
}
int main()
{
    node *head=NULL;
    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);
    //display(head);
    pop(&head);
    display(head);
    pop(&head);
    display(head);
    return 0;
}

