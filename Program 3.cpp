// Code for finding maximum, minimum, and an element of arbitrary rank. 

#include <iostream>
#include <cstdlib>
using namespace std;
//============================================================================
//============================================================================
int max(int[], int);
int min(int[], int);
int elementOf(int[], int, int);
void display(int[], int);
//============================================================================
//============================================================================
int main()
{
	int x, i, A[100], rank;
	cout<<"\nEnter the number of elements : ";
	cin>>x;
	for(i=0;i<x;i++)
		A[i] = rand()%x;
	cout<<"A : ";
	display(A, x);
	cout<<"Max of A = "<<max(A, x)<<"\n";
	cout<<"Min of A = "<<min(A, x)<<"\n";
	cout<<"Enter the rank : ";
	cin>>rank;
	cout<<"Element of rank "<<rank<<" is = "<<elementOf(A, x, rank)<<"\n";
	return 0;
}
//============================================================================
//============================================================================
int max(int A[], int size)
{
	int max = A[0];
	for(int i=1;i<size;i++)
		if(A[i]>max)
			max = A[i];
	return max;
}

int min(int A[], int size)
{
	int min = A[0];
	for(int i=1;i<size;i++)
		if(A[i]<min)
			min = A[i];
	return min;
}
//============================================================================
//============================================================================
int elementOf(int A[], int size, int rank)
{
	int min, i, j, swap, temp;
	for(i=0;i<=rank;i++)
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
	return A[i-1];
}
//============================================================================
//============================================================================
void display(int A[], int size)
{
	for(int i=0;i<size;i++)
		cout<<A[i]<<" ";
	cout<<"\n";
}

