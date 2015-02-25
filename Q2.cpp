#include<iostream>
#include<cstdlib>
using namespace std;
//============================================================================
//============================================================================
void insertionSort(int[], int);
void selectionSort(int[], int);
void bubbleSort(int[], int);
void iterMergeSort(int[], int);
void recuMergeSort(int[], int, int);
void merge(int[], int, int, int, int);
void display(int[], int);
//============================================================================
//============================================================================
int main()
{
	int A[100], x;
	cout<<"Enter the size of the array : ";
	cin>>x;
	for(int i=0;i<x;i++)
		A[i] = rand()%x;
	cout<<"Original Array : ";
	display(A, x);
	cout<<"Insertion Sort : ";
	insertionSort(A,x);
	display(A, x);
	cout<<"Selection Sort : ";
	selectionSort(A,x);
	display(A, x);
	cout<<"Bubble Sort : ";
	bubbleSort(A,x);
	display(A, x);
	cout<<"Iterative Merge Sort : ";
	iterMergeSort(A,x);
	display(A, x);
	cout<<"Recursive Merge Sort : ";
	recuMergeSort(A,0, x-1);
	display(A, x);
	return 0;
}

void insertionSort(int A[], int size)
{
	int i, j, temp;
	for(i=1;i<size;i++)
	{
		bool foundPos = false;
		j = i-1;
		temp = A[i];
		while(!foundPos && j>=0)
		{
			if(temp<A[j])
			{
				A[j+1] = A[j];
				j--;
			}
			else
				foundPos = true;
		}
		A[j+1] = temp;
	}
}
//============================================================================
//============================================================================
void selectionSort(int A[], int size)
{
	int min, i, j, swap, temp;
	for(i=0;i<size;i++)
	{
		min = A[i]; swap = i;
		for(j=i+1;j<size;j++)
		{
			if(min>A[j])
			{
				min = A[j];
				swap  = j;
			}
		}
		temp = A[swap];
		A[swap] = A[i];
		A[i] = temp;
	}
}
//============================================================================
//============================================================================
void bubbleSort(int A[], int size)
{
	int i, j, temp;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}
//============================================================================
//============================================================================
void iterMergeSort(int A[], int size)
{
    int start = 0, end = size - 1, incr = 1;
	while(2*incr<=size)
	{
        start = 0;
        while(start+2*incr<=size)
		{
            merge(A, start, start+incr-1, start+incr, start+2*incr-1);
            start += 2*incr;
		}
        merge(A, start, start+incr-1, start+incr, end);
		incr *= 2;
	}
	merge(A, 0, incr-1, incr, end);
}
//============================================================================
//============================================================================
void recuMergeSort(int A[], int start, int end)
{
	if(start!=end)
	{
		int mid = (start+end)/2;
		recuMergeSort(A, start, mid);
		recuMergeSort(A, mid+1, end);
		merge(A, start, mid, mid+1, end);
	}
}
//============================================================================
//============================================================================
void merge(int A[], int start1, int end1, int start2, int end2)
{
	int i, j, k;
	i = start1; j = start2; k = start1>=start2?start2:start1;
	int B[100];
	while( i<=end1 || j<=end2 )
	{
		if(i<=end1 && j<=end2)
		{
			if(A[i]>=A[j])
				B[k++] = A[j++];
			else
				B[k++] = A[i++];
		}
		else if(i<=end1)
		{
			while(i<=end1)
				B[k++] = A[i++];
		}
		else
		{
			while(j<=end2)
				B[k++] = A[j++];
		}
	}
	for(i=start1; i<=end2; i++)
		A[i] = B[i];
}
//============================================================================
//============================================================================
void display(int A[], int size)
{
	for(int i=0;i<size;i++)
		cout<<A[i]<<" ";
	cout<<"\n";
}

