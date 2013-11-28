#include <cstdio>
#include <cstdlib>
int a[10011],b[10011];
int main()
{
   void sort(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d%d",&a[i],&b[i]);
      sort(1,n);
      int sum=0,x=-1;
      for (int i=1;i<=n;i++)
         if (x<a[i])
         {
            sum++;
            x=b[i];
         }
      printf("%d\n",sum);
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,y,t;
   i=l,j=r;
   x=a[l+r>>1];
   y=b[l+r>>1];
   while (i<=j)
   {
      while (b[i]<y || b[i]==y && a[i]<x)
         i++;
      while (b[j]>y || b[j]==y && a[j]>x)
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
