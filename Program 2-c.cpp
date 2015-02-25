// BUBBLE SORT

#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) 
{
      int p,j,temp;

      for(p=1;p<=n-1;p++)             // Loop for Pass
      {

            for(j=1;j<=n-1;j++)
            {
                  if(a[j]>a[j+1])
                  {
                        temp=a[j];                      // Interchange Values
                        a[j]=a[j+1];
                        a[j+1]=temp;
                  }
            }

      }
}

int main()
{
            int a[100],i,n;

            cout<<"\n------------ BUBBLE SORT ------------ \n\n";

            cout<<"Enter No. of Elements : ";
            cin>>n;

            cout<<"\nEnter Elements : \n";
            for(i=1;i<=n;i++)
            {
            cin>>a[i];
            }

            a[0]=0;

            bubbleSort(a,n);

            cout<<"\nAfter Sorting : \n";
            
            for(i=1;i<=n;i++)
            {
                  cout<<a[i]<<" ";
            }

            cout<<endl;

            return 0;
}