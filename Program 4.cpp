// Code for finding the rank of an element.

#include <iostream>
#include <cstdlib>
using namespace std;
//============================================================================
//============================================================================
int find_rank(int[], int, int);
void display(int[], int);
//============================================================================
//============================================================================
int main()
{
	int x, i, A[100], key;
	cout<<"\nEnter the number of elements : ";
	cin>>x;
	for(i=0;i<x;i++)
		A[i] = rand()%x;
	cout<<"\nA : ";
	display(A, x);
	cout<<"Enter the key you want to search : " ;
	cin>>key;
	cout<<"\nRank of "<<key<<" in A = "<<find_rank(A, x, key)<<"\n";
	return 0;
}
//============================================================================
//============================================================================
void display(int A[], int size)
{
	for(int i=0;i<size;i++)
		cout<<A[i]<<" ";
	cout<<"\n";
}
//============================================================================
//============================================================================
int find_rank(int A[], int size, int key)
{
	int rank = 1;
	bool found = false;
	for(int i=0;i<size;i++)
	{
		if(A[i]==key)
			found = true;
		if(A[i]<key)
			rank++;
	}
	if(found)
		return rank;
	else
		return 0;
}
