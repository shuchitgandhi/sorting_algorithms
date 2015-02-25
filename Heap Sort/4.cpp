/* Write a routine for restoring the heap property when the key value at a
node is altered. */

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
			void siftUp(int, int);
			void heapify();
			void siftDown(int, int);
		public:
			Heap(int[], int);
			void alter(int, int);
};
 
 
int main()
{
	int A[100], size, x, y;
	cout<<"Enter the number of elements : ";
	cin>>size;
	for(int i=0;i<size;i++)
		A[i] = rand()%100;
	cout<<"The array is -->"<<endl;
	display(A, size);
	Heap H(A, size);
	cout<<endl<<"The heapified array -->"<<endl;
	display(A, size);
	cout<<endl<<"Enter the index you want to alter : ";
	cin>>x;
	cout<<"Enter the number : ";
	cin>>y;
	H.alter(x,y);
	cout<<endl<<"The array after alteration is --> "<<endl;
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
	int end = 1;
	while(end<heapSize)
	{
		siftUp(0, end);
		end++;
	}
}

void Heap::siftUp(int start, int end)
{
	int child = end;
	while(parent(child)>=start)
	{
		if(heap[parent(child)]<heap[child])
		{
			int temp = heap[parent(child)];
			heap[parent(child)] = heap[child];
			heap[child] = temp;
			child = parent(child);
		}
		else
			return;
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

void Heap::alter(int index, int x)
{
	
	if(index<heapSize)
	{
		heap[index] = x;
		if(heap[parent(index)]<heap[index])
			siftUp(0, index);
		else if(heap[leftChild(index)]>heap[index] || heap[rightChild(index)]>heap[index])
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
 
