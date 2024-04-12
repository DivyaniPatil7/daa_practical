/*Bellman ford:
Single source shortest path problem with for negative weights
Write a program to implimante Bellman ford algorithm for solving single source shortest path problem considering negative weights for graph.
*/
#include<iostream>
using namespace std;
#define max 100
#define infinity 9999
#define nil -1
#define true 1
#define false 0
int n;
int adj[max][max];
int pre[max];
int pl[max];
int ispresent_in_queue[max];
int front ,rear;
int queue [max];
void initialize_q();
void insert_q(int u);
int delete_q();
int isempty_q();
void create_graph();
void find_path(int s,int v);
int bellmanford(int s);

int main()
{
  int flag,s,v;
  create_graph();
  cout<<"Enter the source vertex:";
  cin>>s;
  flag=bellmanford(s);
  if(flag==-1)
  {
    cout<<"error:Negative cycle in graph\n";
    exit (1);
   }
   while(1)
   {
     cout<<"Enter destination verex(-1 to exit):";
     cin>>v;
     if(v==-1)
      break;
     if(v<0||v>=n)
      cout<<"the vrtex does not exist\n";
     else if(v==s)
       cout<<"source and destination verex are same\n";
     else if (pl[v]==infinity)
     cout<<"thre is no pathfrom s to v\n";
     else 
       find_path(s,v);
    
    }
  return 0;
  
}
void find_path(int s,int v)
{
  int i,u;
  int path[max];
  int shortdis=0;
  int count=0;
  
  while(v!=s)
  {
      count++;
      path[count]=v;
      u=pre[v];
      shortdis+=adj[u][v];
      v=u;
   }
   count++;
   path[count]=s;
   cout<<"Shortest path is: ";
   for(i=count;i>=1;i--)
      cout<<path[i];
   cout<<"shortest distance is:"<<shortdis;
}

int bellmanford(int s)
{
  int k=0,i,current;
  for(i=0;i<n;i++)
   {
     pre[i]=nil;
     pl[i]=infinity;
     ispresent_in_queue[i]=false;
    }
     initialize_q();
     pl[s]=0;
     insert_q(s);
      ispresent_in_queue[i]=true;
     while(!isempty_q())
     {
      current=delete_q();
      ispresent_in_queue[current]=false;
      if(s==current)
         k++;
      if(k>n)
         return -1;
      for(i=0;i<n;i++)
      {
       if (adj[current][i]!=0)
          if(pl[i]>pl[current]+adj[current][i])
          {
             pl[i]=pl[current]+adj[current][i];
             pre[i]=current;
             if(!ispresent_in_queue[i])
             {
              insert_q(i);
              ispresent_in_queue[i]=true;
             }
           }
           
         }
       }
    return 1;
 }
 void initialize_q()
 {  int i;
    for (i=0;i<max;i++)
       queue[i]=0;
    rear=-1;front=-1;
 }
 
 int isempty_q()
 {
   if(front==-1||front>rear)
      return 1;
   else
       return 0;
 }
 void insert_q(int added_ele)
 {
   if(rear==max-1)
   {
     cout<<"queue underflow";
     exit(1);
    }
    else
    {
      if(front==-1)
        front =0;
      rear+=1;
      queue[rear]=added_ele;
    }
}
int delete_q()
{
  int d;
  if(front==-1||front>rear)
  {
    cout<<"queue underflow";
    exit(1);
  }
  else
  {
    d=queue[front];
    front=front+1;
   }
   return d;
 }
 void create_graph()
 {
   int i,max_e,orign,dest,wt;
   cout<<"enter no of vertices:"<<endl;
   cin>>n;
   max_e=n*(n-1);
   for(i=1;i<=max_e;i++)
    {
       cout<<"enter edge"<<i<<":";
       cin>>orign>>dest;
       if((orign==-1)&&(dest==-1))
         break;
       cout<<"enter the weight of this edge:"<<endl;
       cin>>wt;
       if(orign>n||dest>=n||orign<0||dest<0)
        {
           cout<<"invalid edge!";
           i--;
        }
       else
          adj[orign][dest]=wt;
      }    
 }       

 /*OUTPUT:
 enter no of vertices:
8
enter edge 1:0 2
enter the weight of this edge:
9
enter edge 2:2 0
enter the weight of this edge:
5
enter edge 3:2 1
enter the weight of this edge:
-4
enter edge 4:3 2
enter the weight of this edge:
6
enter edge 5:2 3
enter the weight of this edge:
3
enter edge 6:3 1
enter the weight of this edge:
3
enter edge 7:0 1
enter the weight of this edge:
8
enter edge 8:0 4
enter the weight of this edge:
7
enter edge 9:5 0
enter the weight of this edge:
4
enter edge 10:1 5
enter the weight of this edge:
9
enter edge 11:3 5
enter the weight of this edge:
4
enter edge 12:6 3
enter the weight of this edge:
5
enter edge 13:5 6
enter the weight of this edge:
-8
enter edge 14:6 7
enter the weight of this edge:
2
enter edge 15:5 7
enter the weight of this edge:
5
enter edge 16:4 7
enter the weight of this edge:
16
enter edge 17:-1 -1
Enter the source vertex:0
Enter destination verex(-1 to exit):7
Shortest pah is: 021567
shortest distance is:8
Enter destination verex(-1 to exit):-1
*/