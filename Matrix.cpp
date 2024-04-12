/*Strassens Matrix:
Problem statement : Write a program to implement Strassen’s Matrix Multiplication.
*/

#include<iostream>
using namespace std;
int main()
{    int i,j;
     int a[2][2],b[2][2],c[2][2];
     int m1,m2,m3,m4,m5,m6,m7;
     cout<<"Enter elements of first matrix:\n";
     for(i=0;i<2;i++)
      { for(j=0;j<2;j++)
         { 
           cin>>a[i][j];
         }
       }  
    cout<<"\nEnter elements of second matrix:\n";
      for(i=0;i<2;i++)
       {for(j=0;j<2;j++)
         { 
           cin>>b[i][j];
         }
        }
     cout<<"\nprint the first matrix:\n";
      for(i=0;i<2;i++)
       {
          cout<<"\n";
          
         for(j=0;j<2;j++)
         { 
           cout<<a[i][j];
         } 
        }
      cout<<"\nprint the second matrix:\n";
       for(i=0;i<2;i++)
        {
          cout<<"\n";
          
         for(j=0;j<2;j++)
         { 
           cout<<b[i][j];
         } 
        } 
       
     m1=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
     m2=(a[1][0]+a[1][1])*b[0][0];
     m3=a[0][0]*(b[0][1]-b[1][1]);  
     m4=a[1][1]*(b[1][0]-b[0][0]);
     m5=(a[0][0]+a[0][1])*b[1][1];
     m6=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
     m7=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
     
     c[0][0]=m1+m4-m5+m7;
     c[0][1]=m3+m5;
     c[1][0]=m2+m4;
     c[1][1]=m1-m2+m3+m6;
     
   cout<<"\nafter multiplication using strassen's algorithm\n";
   for(i=0;i<2;i++)
   {
     cout<<"\n";
     for(j=0;j<2;j++)
       cout<<c[i][j];
    }
   return 0;
   
}

/*OUTPUT:
Enter elements of first matrix:
3 4 
6 7

Enter elements of second matrix:
2 7
9 8

print the first matrix:

3 4
6 7
print the second matrix:

2 7
9 8
after multiplication using strassen's algorithm

42 53
75 98
*/