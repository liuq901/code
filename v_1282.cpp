#include <cstdio>
#include <cstdlib>
int a[50001],p[50001];
int main()
{
   void sort(int,int);
   int n,k,e[10];
   scanf("%d%d",&n,&k);
   for (int i=0;i<10;i++)
      scanf("%d",&e[i]);
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      p[i]=i;
   }
   sort(1,n);
   for (int i=1;i<=n;i++)
      a[i]+=e[(i-1)%10];
   sort(1,n);
   for (int i=1;i<k;i++)
      printf("%d ",p[i]);
   if (k)
      printf("%d\n",p[k]);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,y;
   i=l,j=r;
   x=a[l+r>>1];
   y=p[l+r>>1];
   while (i<=j)
   {
      while (a[i]>x || a[i]==x && p[i]<y)
         i++;
      while (a[j]<x || a[j]==x && p[j]>y)
         j--;
      if (i<=j)
      {
         int t;
         t=a[i],a[i]=a[j],a[j]=t;
         t=p[i],p[i]=p[j],p[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
