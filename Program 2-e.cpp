//Iterative version of Merge Sort.

#include <iostream>
using namespace std;

void merge(int A[], int start1, int end1, int start2, int end2);

void MergeSort(int A[], int size)
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


int main()
{
        int number_of_elements;

        cout<<"\n------------ MERGE SORT (Iterative) ------------ \n\n";

        cout<<"\nEnter number of Elements : ";
        cin>>number_of_elements;

        cout<<"\nEnter Elements : \n";

        int array[number_of_elements]; 
        int iter;
        
        for(iter = 0;iter < number_of_elements;iter++)
        {
                cin>>array[iter];
        }
        
        /* Calling this functions sorts the array */
        MergeSort(array,number_of_elements); 
        
        cout<<"\nAfter Sorting : \n";
        for(iter = 0;iter < number_of_elements;iter++)
        {
                cout<<array[iter]<<" ";
        }
        
        cout<<endl;
        
        return 0;
}