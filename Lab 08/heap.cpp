#include <iostream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(vector<int>&arr, int n, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
 
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
 
    // If right child is larger than largest
    if (right < n && arr[right] > arr[largest])
        largest = right;
 
    // If largest is not root
    if (largest != root) {
        swap(arr[root], arr[largest]);
 
    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
    }
  
   
}
  
// implementing heap sort
void heapSort(vector<int>&arr, int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
   // extracting elements from heap one by one
   for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // heapify the reduced heap
        heapify(arr, i, 0);
    }
}
  
/* print contents of array */
void displayArray(vector<int>&arr, int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    vector<int> heap_arr;
    int x;
    while (cin >> x && x != -1) {
        heap_arr.push_back(x);
    }
   int n = heap_arr.size();
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}