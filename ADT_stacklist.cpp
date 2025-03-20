#include <iostream>
using namespace std;
struct Node {
    int data;      
    Node* next;    
};
typedef struct Node node;
struct Stack {
    node* top;     
};
Node* create_node(int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->next = nullptr;
    return newnode;
}
Stack* create_stack() {
    Stack* stack = new Stack();
    stack->top = nullptr;
    return stack;
}
bool isEmpty(Stack* stack) {
    return stack->top == nullptr;
}
void push(Stack* stack, int value) {
    Node* newNode = create_node(value);
    if (isEmpty(stack)){
        stack->top = newNode;
    } else {
        newNode->next=stack->top;
        stack->top=newNode;
    }
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty!"<<endl;
        return -1;
    } else {
        Node* temp = stack->top;
        int poppedValue = temp->data;
        stack->top = stack->top->next;
        delete temp;  
        return poppedValue;
    }
}
void display(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Stack is empty!\n";
        return;
    }
    Node* temp = stack->top;
    cout << "Stack elements: ";
    while (temp != nullptr) {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Stack* stack = create_stack();
    push(stack,55);
    push(stack,75);
    push(stack,43);
    push(stack,95);
    push(stack,-88);
    display(stack);
    cout<<"Popped element:"<< pop(stack)<<endl;
    display(stack);
    return 0;
}
