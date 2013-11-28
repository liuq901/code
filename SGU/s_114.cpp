#include <cstdio>
#include <cstdlib>
struct data
{
   int x,p;
};
struct data a[15001];
int main()
{
   void sort(int,int);
   int n,i,s,t;
   scanf("%d",&n);
   s=0;
   for (i=1;i<=n;i++)
   {
      scanf("%d%d",&a[i].x,&a[i].p);
      s+=a[i].p;
   }
   sort(1,n);
   s/=2;
   t=0;
   for (i=1;i<=n;i++)
   {
      t+=a[i].p;
      if (t>=s)
      {
         printf("%.5lf\n",(double)a[i].x);
         break;
      }
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x;
   struct data t;
   i=l;
   j=r;
   x=a[(l+r)/2].x;
   while (i<=j)
   {
      while (a[i].x<x)
         i++;
      while (a[j].x>x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
