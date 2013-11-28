#include <cstdio>
#include <cstdlib>
#include <cmath>
double a[10001],b[10001];
int main()
{
   void sort(int,int);
   int n;
   double l,w;
   while (scanf("%d%lf%lf",&n,&l,&w)!=EOF)
   {
      w/=2;
      for (int i=1;i<=n;i++)
      {
         double o,r;
         scanf("%lf%lf",&o,&r);
         if (r<w)
         {
            a[i]=b[i]=0;
            continue;
         }
         double x=sqrt(r*r-w*w);
         a[i]=o-x;
         b[i]=o+x;
      }
      sort(1,n);
      double k=0,max=0;
      int s=0;
      for (int i=1;i<=n;i++)
      {
         if (a[i]==b[i])
            continue;
         if (a[i]>k)
         {
            k=max;
            max=0;
            s++;
         }
         if (k>=l)
            break;
         if (a[i]<=k && b[i]>max)
            max=b[i];
      }
      if (max>=l)
         printf("%d\n",s+1);
      else
         printf("-1\n");
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j;
   double x,t;
   i=l;
   j=r;
   x=a[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
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
