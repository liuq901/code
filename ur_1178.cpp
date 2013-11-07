#include <cstdio>
#include <cstdlib>
int a[10001],b[10001],p[10001];
int main()
{
   void sort(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&a[i],&b[i]);
      p[i]=i;
   }
   sort(1,n);
   for (int i=1;i<=n>>1;i++)
      printf("%d %d\n",p[(i<<1)-1],p[i<<1]);
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
      while (a[j]>x || a[j]==x && b[j]>y)
         j--;
      if (i<=j)
      {
         int t;
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
