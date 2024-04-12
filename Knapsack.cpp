/*knapsack:
Fractional knapsack problem using greedy method
Using greedy method write a program to implement fractional knapsack problem.
*/
#include<iostream>
using namespace std;
void knapsac(int n,float wt[],float profit[], float capacity)
{ float x[20],tp=0;
int i,j,u;

u=capacity;

for(i=0;i<n;i++)
   x[i]=0,0;
for(i=0;i<n;i++)
{
   if (wt[i]>u)
    break;
   else
     {
       x[i]=1.0;
       tp=tp+profit[i];
       u=u-wt[i];
     }
 }
 if(i<n)
   x[i]=u/wt[i];
   tp=tp+(x[i]*profit[i]);
   cout<<"\n the resultvector is:";
   
 for(i=0;i<n;i++)
     cout<<x[i];
     cout<<"\n Maximum profit is:";
     cout<<tp;
}


int main()
{
   float wt[20],profit[20],capacity;
   int n,i,j;
   float ratio[20],temp;
   cout<<"Enter no.of objects:";
   cin>>n;
   
   
   
   
   cout<<"\n Enter wt and profit of each object";
   for(i=0;i<n;i++)
    {
      cin>>wt[i];
      cin>>profit[i];
    }
    cout<<"Enter the capacity of knapsac:";
    cin>>capacity;
      for(i=0;i<n;i++)
       {
        ratio[i]=profit[i]/wt[i];
       }
      for(i=0;i<n;i++)
       {
          for(j=i+1;j<n;j++)
           {
             if (ratio[i]<ratio[j])
                {
                  temp=ratio[j];
                  ratio[j]=ratio[i];
                  ratio[i]=temp;
                  
                  temp=wt[j];
                  wt[j]=wt[i];
                  wt[i]=temp;
                  
                  temp=profit[j];
                  profit[j]=profit[i];
                  profit[i]=temp;
                 }
           }
       } 
  knapsac(n,wt,profit,capacity);
  return 0;
}

/*OUTPUT:
Enter no.of objects:7

 Enter wt and profit of each object 2 10 
3 5
5 15
7 7
1 6
4 18 
1 3
Enter the capacity of knapsac:15

 the resultvector is:111110.6666670
 Maximum profit is:55.3333
 */