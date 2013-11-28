#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int a[16][4]={
   {2,3,5,9},
   {1,4,6,10},
   {1,4,7,11},
   {2,3,8,12},
   {1,6,7,13},
   {2,5,8,14},
   {3,5,8,15},
   {16,6,7,4},
   {1,10,11,13},
   {2,9,14,12},
   {9,3,12,15},
   {10,4,11,16},
   {9,14,5,15},
   {6,13,16,10},
   {11,13,16,7},
   {15,14,12,8}};
int d[70000];
int main()
{
   void init();
   init();
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      int now=0,a[17];
      for (int i=1;i<=16;i++)
         scanf("%d",&a[i]);
      for (int i=16;i;i--)
         now=now*2+a[i];
      printf("Case #%d: ",id);
      if (d[now]==-1)
         printf("more\n");
      else
         printf("%d\n",d[now]);
   }
   system("pause");
   return(0);
}
bool flag[70000];
int Q[70000];
void init()
{
   flag[65280]=true;
   memset(d,-1,sizeof(d));
   Q[1]=65280;
   d[65280]=0;
   int l,r;
   l=r=1;
   while (l<=r)
   {
      int x=Q[l];
      if (d[x]==3)
      {
         l++;
         continue;
      }
      for (int i=0;i<16;i++)
         for (int j=0;j<4;j++)
         {
            int y=a[i][j]-1,p,q;
            p=x>>i&1,q=x>>y&1;
            int t;
            t=x-(p<<i)-(q<<y)+(q<<i)+(p<<y);
            if (!flag[t])
            {
               flag[t]=true;
               Q[++r]=t;
               d[t]=d[x]+1;
            }
         }
      l++;
   }
}
