// INSERTION SORT

#include <iostream>
using namespace std;

void insertionSort(int a[],int n)
{
	int p,ptr,temp;	

	for(p=2;p<=n;p++)
	{
		temp=a[p];
		ptr=p-1;

		while(temp<a[ptr])
		{
			a[ptr+1]=a[ptr];                // Move Element Forward
			ptr--;
		}

		a[ptr+1]=temp;                 // Insert Element in Proper Place
	}
}

int main()
{
		int a[100],i,n;

		cout<<"\n------------ INSERTION SORT ------------ \n\n";

		cout<<"Enter No. of Elements : ";
		cin>>n;

		cout<<"\nEnter Elements : \n";
		for(i=1;i<=n;i++)
		{
		cin>>a[i];
		}

		a[0]=0;

		insertionSort(a,n);

		cout<<"\nAfter Sorting : \n";
		
		for(i=1;i<=n;i++)
		{
			cout<<a[i]<<" ";
		}

		cout<<endl;

		return 0;
}