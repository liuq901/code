#include <cstdio>
#include <cstdlib>
int main()
{
   void sort(int,int,int *,int *);
   int n,l[101],r[101];
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&l[i],&r[i]);
      if (l[i]>r[i])
      {
         int t;
         t=l[i],l[i]=r[i],r[i]=t;
      }
   }
   sort(1,n,r,l);
   int ans=0,t=-1<<30;
   for (int i=1;i<=n;i++)
      if (l[i]>=t)
      {
         t=r[i];
         l[++ans]=l[i],r[ans]=r[i];
      }
   sort(1,ans,l,r);
   printf("%d\n",ans);
   for (int i=1;i<=ans;i++)
      printf("%d %d\n",l[i],r[i]);
   system("pause");
   return(0);
}
void sort(int l,int r,int *a,int *b)
{
   int i,j,x;
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
         int t;
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,a,b);
   if (l<j)
      sort(l,j,a,b);
}
