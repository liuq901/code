#include <cstdio>
#include <cstdlib>
int a[1001];
int main()
{
   void sort(int,int);
   int n,k,s;
   scanf("%d%d%d",&n,&k,&s);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   sort(1,n);
   int ans=0,sum=0;
   for (int i=1;i<=n;i++)
   {
      sum+=a[i];
      ans++;
      if (sum>=k*s)
         break;
   }
   printf("%d\n",ans);
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
      while (a[i]>x)
         i++;
      while (a[j]<x)
         j--;
      if (i<=j)
      {
         int t;
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
