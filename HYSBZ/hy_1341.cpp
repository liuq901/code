#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[1010],move[1010],pos[1010],f[1010][1010],g[1010][1010];
int main()
{
   void sort(int,int);
   int i,j,x,y,min,ans;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      pos[i]=i;
   }
   sort(1,n);
   for (i=1;i<=n;i++)
      a[pos[i]]=i;
   a[n+1]=pos[n+1]=n+1;
   for (i=1;i<=n;i++)
      f[n+1][i]=100000000;
   f[n+1][n+1]=0;
   for (i=n;i>=1;i--)
   {
      x=1;
      for (j=1;j<=pos[i];j++)
         if (a[j]<i)
            x++;
      y=1;
      for (j=1;j<=n+1;j++)
      {
         if (a[j]<i)
            y++;
         f[i][j]=f[i+1][j]+x+y;
         g[i][j]=j;
      }
      x=0;
      for (j=pos[i]+1;j<=n+1;j++)
      {
         y=f[i+1][j]+x;
         if (y<f[i][pos[i]])
         {
            f[i][pos[i]]=y;
            g[i][pos[i]]=j;
         }
         if (a[j]<i)
            x+=(i-a[j]);
      }
   }
   min=20000000;
   for (i=1;i<=n;i++)
      if (f[1][i]<min)
      {
         min=f[1][i];
         x=g[1][i];
      }
   memset(move,0,sizeof(move));
   ans=0;
   for (i=1;i<=n;i++)
   {
      if (x!=pos[i])
      {
         ans++;
         move[i]=1;
      }
      x=g[i][x];
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,x,t;
   i=l;
   j=r;
   x=a[(l+r)/2];
   while (i<=j)
   {
      while (a[i]>x)
         i++;
      while (a[j]<x)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=pos[i],pos[i]=pos[j],pos[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
