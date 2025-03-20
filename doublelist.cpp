#include<iostream>
using namespace std;
typedef struct node
{
    int info;
    struct node *prev,*next;
}node;
void insertatstart(node **head,int value){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->info=value;
    newnode->prev=nullptr;
    if(*head==nullptr){
        *head=newnode;
        newnode->next=nullptr;
    }else{
        newnode->next=*head;
        *head=newnode;
    }
}
void insertatend(node **front,int value){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->info=value;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    if(*front==nullptr){
        *front=newnode;
    }else{
        node *rear=*front;
        while(rear->next!=nullptr){
            rear=rear->next;
        }
        rear->next=newnode;
        newnode->prev=rear;
    }
}
node *insertbetween(node *head,int value,int position) 
{ 
    node *temp=new node; 
    temp->info=value; 
    if(head==NULL) 
    { 
        cout<<"position dont exist"<<endl; 
    } 
    else{ 
        node *news=head; 
        int x=1; 
        while(x<position-1) 
        { 
            ++x; 
            news=news->next; 
        } 
        temp->next=news->next; 
        news->next->prev=temp; 
        news->next=temp; 
        temp->prev=news; 
    } 
    return head; 
} 
void display(node *head) 
{ 
    while(head!=NULL) 
    { 
        cout<<head->info<<" "; 
        head=head->next; 
    } 
    cout<<endl;
}
int main(){
    node *head=nullptr,*last=nullptr;
    cout<<"Insert at beginning:"<<endl;
    insertatstart(&head,96);
    insertatstart(&head,100);
    insertatstart(&head,105);
    insertatstart(&head,17);
    insertatstart(&head,55);
    insertatstart(&head,70);
    display(head);
    cout<<"\nInsert at end:"<<endl;
    insertatend(&head,10);
    insertatend(&head,20);
    insertatend(&head,30);
    display(head);
    cout<<"\nInsert after a given node:"<<endl;
    insertbetween(head,15,4);
    display(head);

    return 0;
}


