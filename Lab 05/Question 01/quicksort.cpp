#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	if (start >= end)
		return;

	int p = partition(arr, start, end);

	quickSort(arr, start, p - 1);

	quickSort(arr, p + 1, end);
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
		quickSort(arr, 0, arr_size - 1);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop-start);
		cout<<"Time : "<<duration.count()<<endl;
	}
	
	return 0;
}
