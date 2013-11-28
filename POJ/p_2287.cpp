#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[1001],b[1001],f[1001][1001];
int main()
{
   void sort(int,int,int *);
   int cost(int,int),max(int,int);
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      for (int i=1;i<=n;i++)
         scanf("%d",&b[i]);
      sort(1,n,a);
      sort(1,n,b);
      memset(f,-26,sizeof(f));
      f[0][0]=0;
      for (int i=1;i<=n;i++)
      {
         f[i][0]=f[i-1][0]+cost(a[n-i+1],b[i]);
         for (int j=1;j<=n;j++)
            f[i][j]=max(f[i-1][j]+cost(a[n-i+j+1],b[i]),f[i-1][j-1]+cost(a[j],b[i]));
      }
      int ans=-20000000;
      for (int i=0;i<=n;i++)
         if (f[n][i]>ans)
            ans=f[n][i];
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void sort(int l,int r,int *a)
{
   int i,j,x,t;
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
         t=a[i],a[i]=a[j],a[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,a);
   if (l<j)
      sort(l,j,a);
}
int cost(int x,int y)
{
   if (x>y)
      return(200);
   if (x<y)
      return(-200);
   return(0);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
