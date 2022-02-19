#include <bits/stdc++.h>
using namespace std;

//Min Heap
class MinHeap{
  int* min_heap;
  int heap_size;
  int heap_capacity;

  public:
  // constructor
  MinHeap(int n){
    min_heap = new int[n];
    heap_size = 0;
    heap_capacity = n;
  }
	
  // function to insert a value into the heap
  void insertVal(int val){
    // insert the value at the end of the heap
    min_heap[heap_size] = val;
    // heapify from bottom to root
    int cur = heap_size;
    while(cur>0){
      int parent = getParent(cur);
      if(min_heap[cur] < min_heap[parent]){
        swap(&min_heap[cur],&min_heap[parent]);
      } else break;
      cur = parent;
    }
    heap_size++;
    printMinHeap();
  }
	
  // function to delete the minimum value in the heap
  void deleteMin(){
    // swap root (min element) and last element in the heap
    swap(&min_heap[0], &min_heap[heap_size-1]);
    // delete the last element.
    min_heap[heap_size-1] = INT_MAX;
    // heapify from root to bottom
    int cur = 0;
    while(cur<heap_size){
      int min = cur;
      int left = getLeftChild(cur);
      int right = getRightChild(cur);
      if(left<heap_size && min_heap[cur]>min_heap[left]){
        min = left;
      }
      if(right<heap_size && min_heap[min]>min_heap[right]){
          min = right;
      }
      if(min!=cur){
        swap(&min_heap[min], &min_heap[cur]);
        cur = min;
      } else break;
    } 
    heap_size--;
    printMinHeap();
  }
	
  // function to return the minimum value in the heap (array)
  int getMin(){
    return heap_size>0 ? min_heap[0] : -1;
  }
	
  // function to return index of the parent node
  int getParent(int index){
    return (index-1)/2;
  }
	
  // function to return index of left child
  int getLeftChild(int index){
    return 2*index + 1;
  }
	
  // function to return index of right child
  int getRightChild(int index){
    return 2*index + 2;
  }
	
  // utility function to swap values of two memory locations
  void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
  }
	
  // function to print the heap elements
  void printMinHeap(){
    cout<<"Heap Elements : ";
    for(int i=0;i<heap_size;i++){
      cout<<min_heap[i]<<" ";
    }
    cout<<endl;
  }
};

int main() {
  int n;
  cout<<"Enter array size : ";
  cin>>n;
  int ar[n];
  MinHeap* heap = new MinHeap(n);
  cout<<"Enter array elements : "<<endl;
  // insert array elements into the min heap
  for(int i=0;i<n;i++){
    cout<<"Enter data : ";
    cin>>ar[i];
    heap->insertVal(ar[i]);
  }
  // Deleting minimum elements until all the elements are deleted
  for(int i=0;i<n;i++){
    cout<<"Min element : "<<heap->getMin()<<endl;
    heap->deleteMin();
  }
  return 0;
}
