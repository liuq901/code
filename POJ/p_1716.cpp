#include <cstdio>
#include <cstdlib>
int a[10001],b[10001];
int main()
{
   void sort(int,int);
   int n,i,ans,x,y;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d%d",&a[i],&b[i]);
   sort(1,n);
   ans=2;
   x=b[1]-1;
   y=b[1];
   for (i=2;i<=n;i++)
   {
      if (x>=a[i] && x<=b[i])
         continue;
      if (y>=a[i] && y<=b[i])
      {
         ans++;
         x=y;
         y=b[i];
      }
      else
      {
         ans+=2;
         x=b[i]-1;
         y=b[i];
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,y,t;
   i=l;
   j=r;
   x=b[(l+r)/2];
   y=a[(l+r)/2];
   while (i<=j)
   {
      while (b[i]<x || b[i]==x && a[i]<y)
         i++;
      while (b[j]>x || b[j]==x && a[j]>y)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
