/*QUICK SORT:
Problem statement : Sort a given set of n integer elements using quick sort method and compute its time complexity . Run the program for varied values of n and record the time taken to sort. Demonstrate how divide and conquer method works along with complexity analysis: worst case ,average case and best case.
*/
#include<iostream>
using namespace std;
void quick(int arr[] , int low , int up);
int partition(int arr[],int low,int up);

int main()
{
int i;
int n;
cout<<"\nEnter the size of an array :";
cin>>n;
int arr[n];
cout<<"\nEnter the elements in an array :";
for(i=0;i<n;i++)
{
cin>>arr[i];
}
quick(arr,0,n-1); 
cout<<"\nThe quick sort result is :";
for(i=0;i<n;i++)
{
cout<<arr[i]<<" ";
}
return 0;
}

void quick(int arr[],int low,int up) 
{
int pvtloc;
if(low>=up)
return;
pvtloc=partition(arr,low,up);
quick(arr,low,pvtloc-1); 
quick(arr,pvtloc+1,up); 
}

int partition(int arr[],int low,int up){
int temp,i,j,pivot;
i = low+1; 
j = up;
pivot = arr[low];
while(i<=j)
{
while((arr[i]<pivot)&&(i<up))
i++;
while(arr[j]>pivot)
j--;
if(i<j)
{
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
i++;
j--;
}
else
{
i++;
}
}
arr[low] = arr[j];
arr[j] = pivot;
return j;
}

/*OUTPUT:
Enter the size of an array :6

Enter the elements in an array :66 34 12 98 56 99

The quick sort result is :12 34 56 66 98 99 
*/