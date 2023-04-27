#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node*next;
};

void insertAtBeginning(Node**head,int n){
    Node* newHead = new Node();
    newHead->value = n;
    newHead->next = *head;
    *head = newHead;

}
void insertAtEnd(Node**head,int n){
    Node* newNode = new Node();
    newNode->value = n;
    newNode->next = NULL;
    if(*head==NULL){
        *head = newNode;
        return;
    }else
    {Node*last = *head;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next = newNode;}

} 

void printlist(Node*n){
    while (n!=NULL)
    {
     cout<<n->value << endl;
     n = n->next;  
    }
    
}

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;

    insertAtBeginning(&head,5);
    insertAtEnd(&head,10);  

    printlist(head);
    return 0;
}