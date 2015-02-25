/* Write a program to delete the element at index i in a heap and restore
the heap property among the remaining n − 1 elements. */

#include<iostream>
#include<cstdlib>
using namespace std;
 
 
void display(int*, int);
 
 
class Heap{
			int *heap;
			int heapSize;
			int leftChild(int);
			int rightChild(int);
			int parent(int);
			void siftDown(int, int);
			void heapify();
		public:
			Heap(int[], int);
			void deleteEle(int);
};
 
 
int main()
{
	int A[100], size, x;
	cout<<"Enter the number of elements : ";
	cin>>size;
	for(int i=0;i<size;i++)
		A[i] = rand()%100;
	cout<<"The array is -->"<<endl;
	display(A, size);
	Heap H(A, size);
	cout<<endl<<"The heapified array -->"<<endl;
	display(A, size);
	cout<<endl<<"Enter the index you want to delete : ";
	cin>>x;
	H.deleteEle(x);
	cout<<endl<<"The array after deletion is --> "<<endl;
	display(A, --size);
	return 0;
}
 
 
Heap::Heap(int A[], int size)
{
	heap = A;
	heapSize = size;
	heapify();
}

int Heap::leftChild(int index)
{
	int ans = 2*index + 1;
	if(ans<heapSize)
		return ans;
	else
		return heapSize;
}

int Heap::rightChild(int index)
{
	int ans = 2*index + 2;
	if(ans<heapSize)
		return ans;
	else
		return heapSize;
}

int Heap::parent(int index)
{
	int ans = (index - 1)/2;
	if(ans<0)
		return -1;
	else
		return ans;
}

void Heap::heapify()
{
	int start = parent(heapSize-1);
	while(start>=0)
	{
		siftDown(start, heapSize-1);
		start--;
	}	
}

void Heap::siftDown(int start, int end)
{
	int parent = start;
	while(leftChild(parent)<=end)
	{
		int swapWith = parent;
		if(heap[swapWith]<heap[leftChild(parent)])
			swapWith = leftChild(parent);
		if(rightChild(parent)<heapSize && heap[swapWith]<heap[rightChild(parent)])
			swapWith = rightChild(parent);
		if(swapWith!=parent)
		{
			int temp = heap[parent];
			heap[parent] = heap[swapWith];
			heap[swapWith] = temp;
			parent = swapWith;
		}
		else
			return;
	}
}

void Heap::deleteEle(int index)
{
	if(index<heapSize)
	{
		heap[index] = heap[heapSize-1];
		heapSize--;
		siftDown(index, heapSize-1);
	}
	else
		return;
}
 
 
void display(int *A, int size)
{
	for(int i=0;i<size;i++)
		cout<<A[i]<<" ";
	cout<<"\n";
}
 
