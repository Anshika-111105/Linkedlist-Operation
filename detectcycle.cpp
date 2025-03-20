#include<iostream>
using namespace std; 
 
struct node { 
    int data; 
    struct node *next,*prev; 
}; 
 
typedef struct node node; 
void insert_start(node **head,int value){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    if(*head==nullptr){
        *head=newnode;
        newnode->next=newnode;
        newnode->prev=newnode;
    }else{
        node* temp1=*head;
        node *temp2=(node *)malloc(sizeof(node));
        temp2=temp1->prev;
        *head=newnode;
        newnode->next=temp1;
        newnode->prev=temp2;
        temp2->next=newnode;
    }
}
void insert_end(node **head,int value){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    if(*head==nullptr){
        *head=newnode;
        newnode->next=newnode;
        newnode->prev=newnode;
    }else{
        node* temp1=*head;
        node *temp2=(node *)malloc(sizeof(node));
        temp2=temp1->prev;
        newnode->prev=temp2;
        newnode->next=temp1;
        temp1->prev=newnode;
        temp2->next=newnode;
    }
}
void insertbetween(node **head,int value,int pos) 
{ 
    node *temp=new node; 
    temp->data=value; 
    if(head==NULL) 
    { 
        cout<<"position don't exist in the list!"<<endl; 
    } 
    else{ 
        int x=1; 
        node *point=*head; 
        while(x<pos-1) 
        { 
            ++x; 
            point=point->next; 
        } 
        temp->next=point->next; 
        point->next=temp; 
    }  
} 
void display(node *head){ 
    if(head==nullptr){ 
        cout<<"List is empty!" << endl; 
        return; 
    }  
    node *temp=head; 
    do{ 
        cout<<temp->data<<" -> "; 
        temp=temp->next; 
    } while(temp!=head); 
    cout<<endl;
} 
bool detectcycle(node *head) 
{ 
    node *r=head; 
    node *t=head; 
    int flag=0; 
    while(flag==0 ||r==NULL||t==NULL) 
    { 
        r=r->next->next; 
        t=t->next; 
        if(r==t) 
        { 
            flag=1; 
        } 
    } 
    if (flag==1) 
    { 
        return true; 
    } 
    else{ 
        return false; 
    } 
 
}  
int main() { 
    node *head = NULL; 
     
    insert_end(&head, 20); 
    insert_end(&head, 30); 
    insert_end(&head, 40); 
    insert_start(&head, 10); 
    insert_start(&head, 5); 
    insertbetween(&head,80,5); 
    if(detectcycle(head)) 
    { 
        cout<<"list is cycle"<<endl; 
    } 
    else 
    { 
        cout<<"not cycled"<<endl; 
    } 
    return 0; 
} 