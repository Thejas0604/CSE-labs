#include <iostream>
#include <vector>
using namespace std;
#include <unordered_map>

int partition(vector<int>arr, int start, int end)
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

void quickSort(vector<int>arr, int start, int end)
{

	if (start >= end)
		return;

	int p = partition(arr, start, end);

	quickSort(arr, start, p - 1);

	quickSort(arr, p + 1, end);
}

vector<int> closestNumbers(vector<int>arr){
	
	int min_diff = NULL;
	quickSort(arr,arr[0],arr[arr.size()-1]);
	unordered_map<int,vector<int>> result;
	for (int i =0;i<arr.size();i++){
		int diff = abs(arr[i+1] - arr[i]);
		result[diff].push_back(arr[i]);
		result[diff].push_back(arr[i+1]);
		min_diff = min(min_diff,diff);
	}
	return result[min_diff];
}