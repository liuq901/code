#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;
const int inf=1000000000;
int l[1001],r[1001],s[1001],h[1001],v[1001],fa[1001],f[1001][26];
int main()
{
   int solve(int,int);
   int n,k,t[1010];
   scanf("%d%d",&n,&k);
   t[0]=inf;
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&t[i]);
      if (t[i]<t[0])
         t[0]=t[i];
   }
   stack <int> a;
   int m=1;
   a.push(1);
   h[1]=t[0];
   t[n+1]=t[0];
   for (int i=1;i<=n+1;i++)
   {
      int x=t[i];
      int min=i;
      while (h[a.top()]>x)
      {
         int p=a.top();
         a.pop();
         if (s[p]<min)
            min=s[p];
         s[p]=i-s[p];
         int q;
         if (h[a.top()]>=x)
            q=a.top();
         else
            q=m+1;
         fa[p]=q;
         if (!l[q])
         {
            l[q]=p;
            continue;
         }
         int j=l[q];
         while (r[j])
            j=r[j];
         r[j]=p;
      }
      if (h[a.top()]<x)
      {
         a.push(++m);
         s[m]=min;
         h[m]=x;
      }
   }
   int sum=0;
   for (int i=1;i<=m;i++)
      if (!l[i])
         sum++;
   for (int i=2;i<=m;i++)
      v[i]=(h[i]-h[fa[i]])*s[i];
   if (sum<=k)
      printf("0\n");
   else
   {
      memset(f,-1,sizeof(f));
      printf("%d\n",solve(1,k));
   }
   system("pause");
   return(0);
}
int solve(int x,int k)
{
   int min(int,int);
   if (k<0)
      return(inf);
   if (f[x][k]!=-1)
      return(f[x][k]);
   if (!x)
      if (!k)
         f[x][k]=0;
      else
         f[x][k]=inf;
   else if (!l[x])
      if (x==1)
         f[x][k]=0;
      else
         f[x][k]=min(solve(r[x],k-1),solve(r[x],k)+v[x]);
   else
   {
      f[x][k]=inf;
      for (int i=1;i<=k;i++)
         f[x][k]=min(f[x][k],solve(l[x],i)+solve(r[x],k-i));
      f[x][k]=min(f[x][k],solve(l[x],0)+solve(r[x],k)+v[x]);
   }
   return(f[x][k]);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
