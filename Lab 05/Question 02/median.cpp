#include <iostream>
#include <vector>
#include<cmath>
#include <iomanip>
using namespace std;

void printVector(vector <int> const &input){
    for(int i = 0;i<input.size();i++){
        cout<<input.at(i)<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int a;
    vector<int> arr1;
    for(int k = 0;k<n;k++){
        cin>>a;
        arr1.push_back(a);
    }

    vector<int> list1;

    for (int i = 0;i<arr1.size();i++){
        if(i == 0){
            list1.insert(list1.end(),arr1[i]);
            cout<<"[ ";
            printVector(list1);
            cout<<" ]  ";
            float x = arr1[i];
            printf("%.1f",x);
            cout<<endl;
        }else{
            list1.insert(list1.end(),arr1[i]);
            for(int j=list1.size()-1;j>0;j--){
                if(list1[j]<list1[j-1]){
                    swap(list1[j],list1[j-1]);
                }else{
                    break;
                }
            }
            if(list1.size()%2==0){
                cout<<"[ ";
                printVector(list1);
                cout<<" ]  ";
                float num = (list1[list1.size()/2]+list1[(list1.size()/2)-1])/2.0;
                printf("%.1f",num);
                cout<<endl;
            }else{
                cout<<"[ ";
                printVector(list1);
                cout<<" ]  ";
                float num = list1[round(list1.size()/2)];
                printf("%.1f",num);
                cout<<endl;
            }
        }
    }
}