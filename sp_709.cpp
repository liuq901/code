#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[100001],b[100001],c[100001],f[100001];
int main()
{
   void sort(int,int),insert(int,int);
   int count(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d%d%d",&a[i],&b[i],&c[i]);
      sort(1,n);
      memset(f,26,sizeof(f));
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         int t=count(b[i]-1);
         if (t>c[i])
            ans++;
         insert(b[i],c[i]);
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x;
   i=l,j=r;
   x=a[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         int t;
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         t=c[i],c[i]=c[j],c[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void insert(int x,int v)
{
   int min(int,int);
   for (int i=x;i<=n;i+=i&-i)
      f[i]=min(f[i],v);
}
int count(int x)
{
   int min(int,int);
   int ans=1<<30;
   for (int i=x;i;i-=i&-i)
      ans=min(ans,f[i]);
   return(ans);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
