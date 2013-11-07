#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,b[201],c[40001],e[40001][5],a[80001][5];
int main()
{
   void sort(int,int);
   bool work(int,int);
   int m,p;
   scanf("%d%d%d",&n,&m,&p);
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      a[i][0]=y;
      a[i][1]=1;
      a[i][2]=z;
      a[i][3]=i+m;
      a[i][4]=b[x];
      b[x]=i;
      a[i+m][0]=x;
      a[i+m][1]=1;
      a[i+m][2]=z;
      a[i+m][3]=i;
      a[i+m][4]=b[y];
      b[y]=i+m;
      c[i]=z;
   }
   sort(1,m);
   int l=1,r=m,ans;
   while (l<=r)
   {
      for (int i=1;i<=m;i++)
         a[i][1]=a[i+m][1]=1;
      int mid=l+r>>1;
      if (work(c[mid],p))
      {
         ans=c[mid];
         r=mid-1;
      }
      else
         l=mid+1;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l,j=r;
   x=c[l+r>>1];
   while (i<=j)
   {
      while (c[i]<x)
         i++;
      while (c[j]>x)
         j--;
      if (i<=j)
      {
         t=c[i],c[i]=c[j],c[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
bool work(int mid,int p)
{
   bool build(int);
   int dinic(int,int,int);
   int ans=0;
   while (build(mid))
   {
      ans+=dinic(1,100000,mid);
      if (ans>=p)
         return(true);
   }
   return(false);
}
int d[201];
bool build(int mid)
{
   int l,r,q[201];
   l=r=1,q[1]=1;
   memset(d,0,sizeof(d));
   d[1]=1;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][4])
      {
         if (d[a[i][0]] || !a[i][1] || a[i][2]>mid)
            continue;
         q[++r]=a[i][0];
         d[a[i][0]]=d[x]+1;
         if (a[i][0]==n)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow,int mid)
{
   int min(int,int);
   if (x==n)
      return(flow);
   int s=flow;
   for (int i=b[x];i;i=a[i][4])
   {
      int y=a[i][0];
      if (d[y]!=d[x]+1 || !a[i][1] || a[i][2]>mid)
         continue;
      int k=dinic(y,min(s,a[i][1]),mid);
      s-=k;
      a[i][1]-=k;
      a[a[i][3]][1]+=k;
      if (!s)
         return(flow);
   }
   if (s==flow)
      d[x]=-1;
   return(flow-s);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
