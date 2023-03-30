#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int partition(int arr[], int l, int h)
{
	int x = arr[h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++) {
		if (arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[h]);
	return (i + 1);
}

void quickSortIterative(int arr[], int l, int h)
{
	int stack[h - l + 1];

	int top = -1;

	stack[++top] = l;
	stack[++top] = h;

	while (top >= 0) {
	
		h = stack[top--];
		l = stack[top--];

		int p = partition(arr, l, h);

		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		if (p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}

void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout << arr[i] << " ";
}

int main()
{
	for(int j=1;j<7;j++){
		int sz = 10000*j;
		int arr[sz];

		for(int i=0;i<sz;i++){
        	arr[i] = rand()%100;
    }
		auto arr_size = sizeof(arr) / sizeof(arr[0]);

		auto start = high_resolution_clock::now();
		quickSortIterative(arr, 0, arr_size - 1);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop-start);
		cout<<"Time : "<<duration.count()<<endl;
	}
	
	return 0;
}
	

