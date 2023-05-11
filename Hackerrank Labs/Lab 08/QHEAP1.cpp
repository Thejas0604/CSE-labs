#include <cmath>
#include <cstdio>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int queries;
    cin>>queries;
    set<int>minHeap; 
    for(int i=0;i<queries;i++){
        int task,value;
        cin>>task;
        switch(task){
            case 1:
            cin>>value;
            minHeap.insert(value);
            break;
            case 2:
            cin>>value;
            minHeap.erase(minHeap.find(value));
            break;
            case 3:
            cout<<*minHeap.begin();
        }
    }
    return 0;
}
