//Write a procedure for Heap-Sort


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
			void heapsortAsc();
};
 
 
int main()
{
	int A[100], size;
	cout<<"Enter the number of elements : ";
	cin>>size;
	for(int i=0;i<size;i++)
		A[i] = rand()%100;
	cout<<"The array is -->"<<endl;
	display(A, size);
	Heap H(A, size);
	cout<<endl<<"The heapified array -->"<<endl;
	display(A, size);
	H.heapsortAsc();
	cout<<endl<<"The sorted array (ascending order) --> "<<endl;
	display(A, size);
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

void Heap::heapsortAsc()
{
	int tempSize = heapSize;
	while(heapSize>1)
	{
		int temp = heap[0];
		heap[0] = heap[heapSize-1];
		heap[heapSize-1] = temp;
		heapSize--;
		siftDown(0, heapSize-1);
	}
	heapSize = tempSize;
}
 
 
void display(int *A, int size)
{
	for(int i=0;i<size;i++)
		cout<<A[i]<<" ";
	cout<<"\n";
}
 
