#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
const int inf=1061109567;
const int C[6]={0,1,3,5,7,9};
int n,ans,sum,tot,b[101],a[100001][4];
int main()
{
   void add(int,int,int,int);
   bool spfa();
   int m,k;
   while (scanf("%d%d%d",&n,&m,&k)!=EOF)
   {
      memset(b,0,sizeof(b));
      tot=1;
      for (int i=1;i<=m;i++)
      {
         int x,y,v,c;
         scanf("%d%d%d%d",&x,&y,&c,&v);
         for (int j=1;j<=v;j++)
            add(x,y,1,c*C[j]);
      }
      add(0,1,k,0);
      ans=sum=0;
      while (spfa());
      printf("%d\n",sum==k?ans:-1);
   }
   system("pause");
   return(0);
}
void add(int x,int y,int v,int c)
{
   a[++tot][0]=y,a[tot][1]=v,a[tot][2]=c,a[tot][3]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=0,a[tot][2]=-c,a[tot][3]=b[y],b[y]=tot;
}
int q[1000001];
int pre[101],p[101];
bool spfa()
{
   int l,r,d[101];
   bool f[101]={0};
   memset(d,63,sizeof(d));
   l=r=1,q[1]=0,f[0]=true,d[0]=0;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][3])
      {
         if (!a[i][1])
            continue;
         int y=a[i][0];
         if (d[x]+a[i][2]<d[y])
         {
            d[y]=d[x]+a[i][2];
            pre[y]=x,p[y]=i;
            if (!f[y])
            {
               f[y]=true;
               q[++r]=y;
            }
         }
      }
      f[x]=false;
      l++;
   }
   if (d[n]==inf)
      return(false);
   int cost,flow;
   flow=inf;
   for (int i=n;i;i=pre[i])
   {
      int x=p[i];
      flow=min(flow,a[x][1]);
   }
   for (int i=n;i;i=pre[i])
   {
      int x=p[i];
      a[x][1]-=flow;
      a[x^1][1]+=flow;
   }
   cost=flow*d[n];
   ans+=cost,sum+=flow;
}
