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
using namespace std;
const int inf=1061109567;
struct state
{
   int i,j,k,l;
   state(){}
   state(int _i,int _j,int _k,int _l):i(_i),j(_j),k(_k),l(_l){}
};
state q[1000001];
int now,a[101],f[2][101][9][260];
int main()
{
   int check(int);
   memset(f,63,sizeof(f));
   int id=0;
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      now=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         a[i]=x-25;
         now|=1<<a[i];
      }
      int L=0,R=1,ans=inf;
      f[0][0][8][0]=0;
      q[1]=state(0,0,8,0);
      while (L!=R)
      {
         L++;
         if (L==1000000)
            L=1;
         int i=q[L].i,j=q[L].j,k=q[L].k,l=q[L].l;
         if (i!=n)
         {
            if (a[i+1]==k && f[i&1][j][k][l]<f[i+1&1][j][k][l])
            {
               if (f[i+1&1][j][k][l]==inf)
               {
                  R++;
                  if (R==1000000)
                     R=1;
                  q[R]=state(i+1,j,k,l);
               }
               f[i+1&1][j][k][l]=f[i&1][j][k][l];
            }
            if (a[i+1]!=k && f[i&1][j][k][l]+1<f[i+1&1][j][a[i+1]][l|(1<<a[i+1])])
            {
               if (f[i+1&1][j][a[i+1]][l|(1<<a[i+1])]==inf)
               {
                  R++;
                  if (R==1000000)
                     R=1;
                  q[R]=state(i+1,j,a[i+1],l|(1<<a[i+1]));
               }
               f[i+1&1][j][a[i+1]][l|(1<<a[i+1])]=f[i&1][j][k][l]+1;
            }
            if (j<m && f[i&1][j][k][l]<f[i+1&1][j+1][k][l])
            {
               if (f[i+1&1][j+1][k][l]==inf)
               {
                  R++;
                  if (R==1000000)
                     R=1;
                  q[R]=state(i+1,j+1,k,l);
               }
               f[i+1&1][j+1][k][l]=f[i&1][j][k][l];
            }
         }
         else
            ans=min(ans,f[i&1][j][k][l]+check(l));
         f[i&1][j][k][l]=inf;
      }
      printf("Case %d: %d\n\n",++id,ans);
   }
   system("pause");
   return(0);
}
int check(int x)
{
   int ans=0;
   for (int i=0;i<8;i++)
      if ((now>>i&1) && (!(x>>i&1)))
         ans++;
   return(ans);
}
