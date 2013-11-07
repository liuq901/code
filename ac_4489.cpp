#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
struct state
{
   int i,j,k,l;
   state(){}
   state(int _i,int _j,int _k,int _l):i(_i),j(_j),k(_k),l(_l){}
};
state q[1000001];
int a[301],b[301],c[301],f[2][501][51][2];
int main()
{
   void sort(int,int);
   memset(f,-1,sizeof(f));
   int id=0;
   while (1)
   {
      int v1,v2,n;
      scanf("%d%d%d",&v1,&v2,&n);
      if (!v1 && !v2&& !n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d%d%d",&a[i],&b[i],&c[i]);
      sort(1,n);
      f[0][v1][v2][0]=0;
      int L,R;
      L=0,R=1;
      q[1]=state(0,v1,v2,0);
      int ans=-1;
      while (L!=R)
      {
         L++;
         if (L==1000000)
            L=1;
         int i=q[L].i,j=q[L].j,k=q[L].k,l=q[L].l;
         if (i!=n)
         {
            if (!l && f[i&1][j][k][l]+b[i+1]>f[i+1&1][j][k][1])
            {
               if (f[i+1&1][j][k][1]==-1)
               {
                  R++;
                  if (R==1000000)
                     R=1;
                  q[R]=state(i+1,j,k,1);
               }
               f[i+1&1][j][k][1]=f[i&1][j][k][l]+b[i+1];
            }
            if (j>=a[i+1] && f[i&1][j][k][l]+b[i+1]>f[i+1&1][j-a[i+1]][k][l])
            {
               if (f[i+1&1][j-a[i+1]][k][l]==-1)
               {
                  R++;
                  if (R==1000000)
                     R=1;
                  q[R]=state(i+1,j-a[i+1],k,l);
               }
               f[i+1&1][j-a[i+1]][k][l]=f[i&1][j][k][l]+b[i+1];
            }
            if (k>=a[i+1] && f[i&1][j][k][l]+b[i+1]>f[i+1&1][j][k-a[i+1]][l])
            {
               if (f[i+1&1][j][k-a[i+1]][l]==-1)
               {
                  R++;
                  if (R==1000000)
                     R=1;
                  q[R]=state(i+1,j,k-a[i+1],l);
               }
               f[i+1&1][j][k-a[i+1]][l]=f[i&1][j][k][l]+b[i+1];
            }
            if (!c[i+1] && f[i&1][j][k][l]>f[i+1&1][j][k][l])
            {
               if (f[i+1&1][j][k][l]==-1)
               {
                  R++;
                  if (R==1000000)
                     R=1;
                  q[R]=state(i+1,j,k,l);
               }
               f[i+1&1][j][k][l]=f[i&1][j][k][l];
            }
         }
         if (i==n)
            ans=max(ans,f[i&1][j][k][l]);
         f[i&1][j][k][l]=-1;
      }
      printf("Case %d: %d\n\n",++id,ans);
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x;
   i=l,j=r;
   x=c[l+r>>1];
   while (i<=j)
   {
      while (c[i]>x)
         i++;
      while (c[j]<x)
         j--;
      if (i<=j)
      {
         swap(a[i],a[j]);
         swap(b[i],b[j]);
         swap(c[i],c[j]);
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
