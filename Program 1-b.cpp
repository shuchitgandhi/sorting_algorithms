//Iterative version of Binary Search.


#include <iostream>

using namespace std;
const int SIZE = 10;

int binary_search_iterative( int array[], int start, int end, int value  )
{
    int mid = ( (start + end ) / 2 );
    
    while( start < end && array[ mid ] != value  )
    {
        if ( array[ mid ] < value )
        {
            start = mid+1; 
            mid = ( (start + end ) / 2 );
        }
        else
        {
            end = mid-1;
            mid = ( ( start + end ) / 2 );
        } 
    }

    if(array[mid] != value )
        return -1;
    else
        return mid;
}

int main()
{       int a[50];
        int n,no,x,result;

        cout<<"\n------------ BINARY SEARCH (Iterative) ------------ \n\n";
        
        cout<<endl<<"Enter the number of terms : "<<endl;
        cin>>no;
        
        cout<<endl<<"Enter the elements : "<<endl;
        
        for(x=0;x<no;x++)
            cin>>a[x];
        
        cout<<endl<<"Enter the number to be searched : ";
        cin>>n;
        
        result = binary_search_iterative( a, 0, no - 1, n);

        if(result == -1)
            cout<<endl<<"Element not found"<<endl;
        else
            cout<<endl<<"The element is at position "<<result+1<<endl;
        
        return 0;
}
