#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[3][100001];
int main()
{
   void sort1(int,int,int[]),sort2(int,int,int[]);
   int i,k,n,m;
   int a[100001];
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (i=1;i<=m;i++)
   {
      scanf("%d",&b[0][i]);
      b[1][i]=i;
   }
   sort1(1,n,a);
   sort2(1,m,b[0]);
   memset(b,0,sizeof(b[2]));
   k=m+1;
   for (i=n;i>=1;i--)
   {
      k--;
      if (k==0)
         k=m;
      b[2][k]+=a[i];
   }
   sort2(1,m,b[1]);
   for (i=1;i<=m-1;i++)
      printf("%d ",b[2][i]);
   printf("%d\n",b[2][m]);
   system("pause");
   return(0);
}
void sort1(int l,int r,int a[])
{
   int i,j,x,t;
   i=l;
   j=r;
   x=a[(l+r)/2];
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
      sort1(i,r,a);
   if (l<j)
      sort1(l,j,a);
}
void sort2(int l,int r,int a[])
{
   int i,j,k,x,t;
   i=l;
   j=r;
   x=a[(l+r)/2];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         for (k=0;k<=2;k++)
            t=b[k][i],b[k][i]=b[k][j],b[k][j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort2(i,r,a);
   if (l<j)
      sort2(l,j,a);
}
