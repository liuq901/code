#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
int N,M,K;
int n,a[100010],sa[100010],rank[100010],height[100010];
long long ans;
int main()
{
   void build(),calc(int,int,int);
   while (scanf("%d%d%d",&N,&M,&K)==3)
   {
      for (int i=1;i<=N;i++)
      {
         scanf("%d",&a[i]);
         a[i]++;
      }
      a[N+1]=0;
      for (int i=1;i<=M;i++)
      {
         scanf("%d",&a[i+N+1]);
         a[i+N+1]++;
      }
      n=N+M+1;
      a[n+1]=-1;
      build();
      int left=1;
      ans=0;
      for (int i=2;i<=n;i++)
         if (height[i]<K)
         {
            calc(left,i-1,1);
            left=i;
         }
      calc(left,n,1);
      left=1;
      for (int i=2;i<=n;i++)
         if (height[i]<=K)
         {
            calc(left,i-1,-1);
            left=i;
         }
      calc(left,n,-1);
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
int b[100010],c[100010];
void build()
{
   void sort(int *);
   int count(int *,int *);
   for (int i=1;i<=n;i++)
   {
      c[i]=a[i];
      b[i]=-1;
      sa[i]=i;
   }
   sort(c);
   count(c,b);
   int k=1;
   while (1)
   {
      for (int i=1;i<=n;i++)
      {
         c[i]=rank[i];
         if (i+k<=n)
            b[i]=rank[i+k];
         else
            b[i]=0;
      }
      sort(b),sort(c);
      if (count(c,b)>=n)
         break;
      k<<=1;
   }
   k=0;
   for (int i=1;i<=n;i++)
   {
      k=k?k-1:0;
      if (rank[i]==1)
      {
         height[rank[i]]=0;
         continue;
      }
      int p=sa[rank[i]-1],q=sa[rank[i]];
      while (a[p+k]==a[q+k])
         k++;
      height[rank[i]]=k;
   }
}
int f[100010],x[100010];
void sort(int *a)
{
   int t=0;
   memset(f,0,sizeof(f));
   for (int i=1;i<=n;i++)
   {
      f[a[i]]++;
      if (a[i]>t)
         t=a[i];
   }
   for (int i=1;i<=t;i++)
      f[i]+=f[i-1];
   for (int i=n;i;i--)
   {
      x[f[a[sa[i]]]]=sa[i];
      f[a[sa[i]]]--;
   }
   for (int i=1;i<=n;i++)
      sa[i]=x[i];
}
int count(int *a,int *b)
{
   rank[sa[1]]=1;
   int t=1;
   for (int i=2;i<=n;i++)
   {
      if (a[sa[i]]!=a[sa[i-1]] || b[sa[i]]!=b[sa[i-1]])
         t++;
      rank[sa[i]]=t;
   }
   return(t);
}
void calc(int l,int r,int value)
{
   int sum0,sum1;
   sum0=sum1=0;
   for (int i=l;i<=r;i++)
   {
      if (sa[i]<=N)
         sum0++;
      if (sa[i]>=N+2)
         sum1++;
   }
   ans+=(long long)sum0*(sum1!=0)*value;
}
