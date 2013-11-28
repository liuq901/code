#include <cstdio>
#include <cstdlib>
int a[20001],b[20001];
int main()
{
   void sort(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d%d",&a[i],&b[i]);
   sort(1,n);
   int ans=0,max=-1<<30;
   for (int i=1;i<=n;i++)
   {
      if (b[i]<=max)
         continue;
      if (a[i]>max)
         max=a[i];
      ans+=b[i]-max;
      if (b[i]>max)
         max=b[i];
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,y;
   i=l,j=r;
   x=a[l+r>>1];
   y=b[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x || a[i]==x && b[i]<y)
         i++;
      while (a[j]>x || a[j]==x && a[j]>y)
         j--;
      if (i<=j)
      {
         int t;
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
