/*Merge sort:
Using divide and conquer method and recursive approch write a proram to sort the list using top down merge sort.
*/
#include<iostream>
using namespace std;
void mergeR(int arr[],int low,int up);
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2);
void copy(int arr[],int temp[],int low,int up);

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
mergeR(arr,0,n-1);
cout<<"\nThe merge sort result is :";
for(i=0;i<n;i++)
{
cout<<arr[i]<<"\t";
}
return 0;
}

void mergeR(int arr[],int low,int up)
{
int mid;
int temp[10];
if(low<up)
{
mid=(low+up)/2;
mergeR(arr,low,mid);
mergeR(arr,mid+1,up);
merge(arr,temp,low,mid,mid+1,up);
copy(arr,temp,low,up);
}
}

void merge(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
int i=low1;
int j=low2;
int k=low1;
while((i<=up1)&&(j<=up2))
{
if(arr[i]<arr[j])
{
temp[k++]=arr[i++];
}
else
{
temp[k++]=arr[j++];
}
}
while(i<=up1)
{
temp[k++]=arr[i++];
}
while(j<=up2)
{
temp[k++]=arr[j++];
}
}

void copy(int arr[],int temp[],int low,int up)
{
int i;
for(i=low;i<=up;i++)
{
arr[i]=temp[i];
}
}

/*OUTPUT:
Enter the size of an array :7

Enter the elements in an array :22 45 37 28 56 93 11

The merge sort result is :11	22	28	37	45	56	93	
*/