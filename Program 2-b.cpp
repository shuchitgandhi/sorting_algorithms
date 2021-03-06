// SELECTION SORT

#include <iostream>
using namespace std;

void selectionSort(int a[], int n) 
{
      int p,min,loc,k,temp;

      for(p=1;p<=n-1;p++)              // Loop for Pass 
      {
            min=a[p];                        // Element Selection
            loc=p;

            for(k=p+1;k<=n;k++)              // Finding Min Value
            {
                  if(min>a[k])
                  {
                        min=a[k];
                        loc=k;
                  }
            }

            temp = a[p];                        // Swap Selected Element and Min Value
            a[p] = a[loc];
            a[loc] = temp;

      }
}

int main()
{
            int a[100],i,n;

            cout<<"\n------------ SELECTION SORT ------------ \n\n";

            cout<<"Enter No. of Elements : ";
            cin>>n;

            cout<<"\nEnter Elements : \n";
            for(i=1;i<=n;i++)
            {
            cin>>a[i];
            }

            a[0]=0;

            selectionSort(a,n);

            cout<<"\nAfter Sorting : \n";
            
            for(i=1;i<=n;i++)
            {
                  cout<<a[i]<<" ";
            }

            cout<<endl;

            return 0;
}