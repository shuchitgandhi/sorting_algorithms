/* Write a routine to add an extra element into an existing heap. This should
increase the heapsize by 1 and then incorporate the new element. */

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
		public:
			Heap(int[], int);
			void insert(int);
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
	cout<<endl<<"Enter the new element : ";
	cin>>x;
	H.insert(x);
	cout<<endl<<"The array after insertion is --> "<<endl;
	display(A, ++size);
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

void Heap::insert(int x)
{
	heap[heapSize] = x;
	heapSize++;
	siftUp(0, heapSize-1);
}
 
 
void display(int *A, int size)
{
	for(int i=0;i<size;i++)
		cout<<A[i]<<" ";
	cout<<"\n";
}
 
