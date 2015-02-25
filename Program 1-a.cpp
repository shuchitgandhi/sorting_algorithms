//Recursive version of Binary Search.

#include <iostream>
using namespace std;
int binarysearch(int a[],int n,int start,int end)
	{ int mid;
	  
	  if (start > end)
	  { 
	  	cout<<endl<<"Element not found"<<endl;
	  	return -1;
	  }

	  mid = (start + end)/2;
	  
	  if(n == a[mid])
	  { 	cout<<endl<<"The element is at position "<<mid+1<<endl;
	    	return 0;
	  }
	  if(n < a[mid])
	  {   end = mid - 1;
	      binarysearch(a,n,start,end);
	  }
	  if(n > a[mid])
	  {   start = mid + 1;
	      binarysearch(a,n,start,end);
	  }

	  return 0;
	}

int main()
{		int a[50];
		int n,no,x,result;
		
		cout<<"\n------------ BINARY SEARCH (Recursive) ------------ \n\n";

		cout<<endl<<"Enter the number of terms : "<<endl;
		cin>>no;
		
		cout<<endl<<"Enter the elements : "<<endl;
		
		for(x=0;x<no;x++)
			cin>>a[x];
		
		cout<<endl<<"Enter the number to be searched : ";
		cin>>n;
		
		result = binarysearch(a,n,0,no-1);
		
		return 0;
}