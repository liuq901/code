#include <cstdio>
#include <cstdlib>
int a[70000],b[70000];
long long ans;
int main()
{
   void sort(int,int);
   int i,n;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   ans=0;
   sort(1,n);
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int mid,i,j;
   if (l==r)
      return;
   mid=(l+r)/2;
   sort(l,mid);
   sort(mid+1,r);
   i=l;
   j=mid+1;
   b[0]=l-1;
   while (1)
   {
      if (i>mid && j>r)
         break;
      if (i>mid)
      {
         for (i=j;i<=r;i++)
         {
            b[0]++;
            b[b[0]]=a[i];
         }
         break;
      }
      if (j>r)
      {
         for (j=i;j<=mid;j++)
         {
            b[0]++;
            b[b[0]]=a[j];
         }
         break;
      }
      if (a[i]<=a[j])
      {
         b[0]++;
         b[b[0]]=a[i];
         i++;
      }
      else
      {
         b[0]++;
         b[b[0]]=a[j];
         j++;
         ans+=mid-i+1;
      }
   }
   for (i=l;i<=r;i++)
      a[i]=b[i];
}
