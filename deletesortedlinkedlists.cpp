#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void deleteNode(Node*& head, int key){
    if(head==nullptr){
        cout<<"empty."<<endl;
        return;
    }
    if (head->data == key) { //If the head node is to be deleted
        Node* temp = head;
        head = head->next;  
        delete temp;        
        return;
    }
    Node* current=head;
    while (current->next != nullptr && current->next->data != key) {
        current=current->next;
    }
    if (current->next == nullptr) {  //If the key is not present in the list
        cout<< "Key not found in the list."<<endl;
        return;
    }
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}
void insertSorted(Node*& head, int data) {
    Node* newNode =(Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr || head->data >= data) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current=head;
    while (current->next != nullptr && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}
void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertSorted(head, -10);
    insertSorted(head, 22);
    insertSorted(head, 59);
    insertSorted(head, 37);
    insertSorted(head, 500);

    cout << "Original list: ";
    display(head);
    int key =59;
    cout << "Deleting node with key " << key << endl;
    deleteNode(head, key);
    cout << "Updated list: ";
    display(head);

    return 0;
}