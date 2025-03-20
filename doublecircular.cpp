#include <iostream> 
using namespace std; 
struct node { 
    int data; 
    struct node *prev,*next; 
}; 
typedef struct node node;  
node *insertbegin(node *head,int v) 
{ 
    node *temp=new node; 
    temp->data=v; 
    if(head==NULL) 
    { 
        temp->next=temp; 
        temp->prev=temp; 
        head=temp; 
    } 
    else 
    { 
        node *c=head; 
        while(c->next!=head) 
        { 
            c=c->next; 
        } 
        temp->prev=c; 
        c->next=temp; 
        temp->next=head; 
        head=temp; 
    } 
return head; 
} 
node *insertend(node *head, int value) 
{ 
    node *temp=new node; 
    temp->data=value; 
    if (head == NULL) 
    { 
        temp->next=temp; 
        temp->prev=temp; 
        head =temp; 
    } 
    else 
    { 
        node *point=head; 
        while (point->next!=head) 
        { 
            point=point->next; 
        } 
        point->next=temp; 
        temp->prev=point;
        temp->next=head; 
        head->prev=temp; 
    } 
    return head; 
} 
node *insertbetween(node* head,int value,int pos) 
{ 
    node *temp=new node; 
    temp->data=value; 
    if(head==NULL) 
    { 
        cout<<"position don't exist"<<endl; 
    } 
    else{ 
        node *point=head; 
        int x=1; 
        while(x<pos-1) 
        { 
            ++x; 
            point=point->next; 
        } 
        temp->next=point->next; 
        point->next->prev=temp; 
        point->next=temp; 
        temp->prev=point; 
    } 
    return head; 
} 
void display(node *head) 
{ 
node *temp=head; 
     
    do{ 
        cout<<temp->data<<" "; 
        temp=temp->next; 
    } 
    while(temp!=head); 
    cout<<endl; 
} 
int main(){ 
    node *head=nullptr;
    head=insertbegin(head,10);     
    head=insertbegin(head,-20);     
    head=insertbegin(head,79);     
    head=insertbegin(head,40); 
    display(head);     
    head=insertend(head,50);             
    display(head);     
    head=insertbetween(head,80,2); 
    display(head);     
    return 0; 
} 