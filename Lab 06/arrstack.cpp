#include <iostream>
#include <chrono>
using namespace std::chrono;
#define MAX 14

using namespace std ;

int arr[MAX];
int top = -1;

bool isEmpty(){
    if(top==-1){
        return true;
    }else{
        return false;
    }
}
int push(int x){
    top = top +1;
    if(top>=MAX){
        throw invalid_argument("Stack Overflow");
    }else{
        arr[top] = x;
    }
    
} 

int pop(){
    if (isEmpty()){
        throw invalid_argument("Stack Underflow");
    }else{
        top = top - 1 ;
        return arr[top+1];
    }
}

int display(){
    if(top>=0){
        for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
    }else{
        cout<<"Stack is empty";
    }
    
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