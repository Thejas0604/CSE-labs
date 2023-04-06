#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

struct Node {
   int data;
   struct Node *next;
};

struct Node* top = NULL;

bool isEmpty(){
    if(top==NULL){
        return true;
    }else{
        return false;
    }
}

void push(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = val;
   newnode->next = top;
   top = newnode;
}
int pop() {
   if(isEmpty())
    throw invalid_argument("Stack Underflow");
   else {
      top = top->next;
   }
}


void display() {
   struct Node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}

int main(){
    auto start = high_resolution_clock::now();
    for(int i=0;i<10;i++){
        	int j = rand()%100;
            push(j);
    }
    display();
    for(int i=0;i<5;i++){
            pop();
    }
    display();
    for(int i=0;i<4;i++){
        	int j = rand()%100;
            push(j);
    }
    display();
    auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop-start);
	cout<<"Time : "<<duration.count()<<endl;
}
