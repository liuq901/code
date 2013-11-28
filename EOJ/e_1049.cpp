#include <cstdio>
#include <cstdlib>
long long a[100001];
int s[100001];
int main()
{
   void sort(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      scanf("%I64d",&a[i]);
   sort(1,n);
   a[0]=-1;
   for (int i=1;i<=n;i++)
      if (a[i]==a[i-1])
         s[i]=s[i-1]+1;
      else
         s[i]=1;
   for (int i=1;i<=m;i++)
   {
      int l=1,r=n,ans=1;
      long long x;
      scanf("%I64d",&x);
      while (l<=r)
      {
         int mid=l+r>>1;
         if (a[mid]<=x)
         {
            ans=mid;
            l=mid+1;
         }
         else
            r=mid-1;
      }
      if (a[ans]!=x)
         printf("0\n");
      else
         printf("%d\n",s[ans]);
   }
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j;
   long long x,t;
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
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
