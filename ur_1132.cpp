#include <cstdio>
#include <cstdlib>
#include <cstring>
int sum,f[100001],a[100001],b[100001],p[100001],v[100001],ans[100001][2];
int main()
{
   void sort(int,int),work(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&a[i],&b[i]);
      a[i]%=b[i];
      p[i]=i;
   }
   sort(1,n);
   for (int i=1;i<=n;i++)
   {
      if (b[i]!=b[i-1])
         work(b[i]);
      if (f[a[i]]!=sum)
         ans[p[i]][0]=-1;
      else
      {
         ans[p[i]][0]=v[a[i]];
         ans[p[i]][1]=b[i]-v[a[i]];
      }
   }
   for (int i=1;i<=n;i++)
   {
      if (ans[i][0]==-1)
      {
         printf("No root\n");
         continue;
      }
      if (ans[i][0]==ans[i][1])
         printf("%d\n",ans[i][0]);
      else
         printf("%d %d\n",ans[i][0],ans[i][1]);
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=b[(l+r)/2];
   while (i<=j)
   {
      while (b[i]<x)
         i++;
      while (b[j]>x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         t=p[i],p[i]=p[j],p[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void work(int x)
{
   sum++;
   for (int i=1;i<=x/2;i++)
   {
      int t=i*i%x;
      f[t]=sum;
      v[t]=i;
   }
}
