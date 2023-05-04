#include <iostream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int i=root;
   int l = 2*i+1;      //left child of i
   int r = 2*i+2;      //right child of i
   int largest;        //a variable to store largest number of i, left or right
   if (l < n && arr[l] > arr[i]) // l<n is for not to exceed the length of the array
      largest = l;               // the below r<n is for the same purpose 
   else
      largest = i;
      
   if (r < n && arr[r] > arr[largest]){ 
      largest = r;
      }
   int extemp;  //temporary variable for the exchange
   if (largest != i)
   {
      //exchanging arr[i] and arr[largest]
      extemp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = extemp;
      heapify(arr, n ,largest);  
   }
}

// implementing heap sort
void heapSort(int arr[], int n) //n is the size of array
{
   // build heap
   int heap_size = n;
   for (int i=(n-1)/2 ;i >=0 ;i--){   
      heapify(arr,n,i);
   }
   
   int temp;
   // to get elements from array from last to first 
   for (int j =n-1 ; j>=1 ;j--){
      //exchanging A[0] and A[j] as highest value is at A[0]
      temp = arr[j];
      arr[j]= arr[0];
      arr[0] = temp;
      heap_size = heap_size - 1; //new array is the unsorted part of the array
      heapify(arr,heap_size, 0); //heapifying to do the same thing for other elements as well in the iteration
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   vector<int> vec; // using a vector to add unknown number of elements
   cout << "Enter the elements: ";
   int x;
   while (cin >> x && x != -1) {
      vec.push_back(x);  // add element to the vector
   }
   int n =vec.size();  // n is length of array
   int* heap_arr = vec.data();

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
