//Write a program to build an alternating heap of n elements

#include<iostream>
#include<cstdlib>
using namespace std;
 
 
void display(int*, int);
 
 
class Heap{
		int *heap;
		int heapSize;
		int parent(int);
		int leftChild(int);
		int rightChild(int);
		int level(int);
		void heapify();
		void insert(int);
		void verify(int, int, int);
	public:
		Heap(int*, int);
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
	cout<<endl<<"The alternating heap is -->"<<endl;
	display(A, size);
	return 0;
}
 
 
Heap::Heap(int *A, int size)
{
	heap = A;
	heapSize = size;
	heapify();
}

int Heap::parent(int i)
{
	if(i==0)
		return -1;
	else
		return (i-1)/2;
}

int Heap::leftChild(int i)
{
	int ans = 2*i+1;
	if(ans>=heapSize)
		return heapSize;
	else
		return ans;
}

int Heap::rightChild(int i)
{
	int ans = 2*i+2;
	if(ans>=heapSize)
		return heapSize;
	else
		return ans;
}

int Heap::level(int i)
{
	int x = 1, k=0;
	while(true)
	{
		if(i>=x-1&&i<=2*x-2)
			return k;
		else
		{	
			x*=2;
			k++;
		}
	}
	return 0;
}

void Heap::heapify()
{
	int heapPtr = 1, tempHeapSize = heapSize;
	heapSize = 1;
	while(heapPtr<tempHeapSize)
	{
		insert(heap[heapPtr]);
		heapPtr++;
		heapSize++;
	}
	
}

void Heap::insert(int x)
{
	int elementAt = heapSize;
	switch(level(elementAt)%2)
	{
		case 0: if(x>heap[parent(elementAt)])
				{
					heap[elementAt] = heap[parent(elementAt)];
					elementAt = parent(elementAt);
				}
				verify(x, elementAt, level(elementAt)%2);
				break;
		case 1:	if(x<heap[parent(elementAt)])
				{
					heap[elementAt] = heap[parent(elementAt)];
					elementAt = parent(elementAt);
				}
				verify(x, elementAt, level(elementAt)%2);
				break;
	}
}

void Heap::verify(int x, int elementAt, int choice)
{
	if(choice==0)
	{
			int grandparent = parent(parent(elementAt));
			while(grandparent>=0)
			{
				if(x<heap[grandparent])
				{
					heap[elementAt] = heap[grandparent];
					elementAt = grandparent;
					grandparent = parent(parent(grandparent));
				}
				else
					break;
			}
			heap[elementAt] = x;//verify min
	}
	else
	{
		int grandparent = parent(parent(elementAt));
		while(grandparent>=0)
		{
			if(x>heap[grandparent])
			{
				heap[elementAt] = heap[grandparent];
				elementAt = grandparent;
				grandparent = parent(parent(grandparent));
			}
			else
				break;
		}
		heap[elementAt] = x;	//verify max
	}
}
 
 
void display(int *A, int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<"\n";
}
 
