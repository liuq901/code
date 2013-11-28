#include <cstdio>
#include <cstdlib>
int n,a[101][101],s,ans[5001];
int main()
{
   void work(int,int);
   int i,j,k,m,p,x,y;
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         if (i==j)
            a[i][j]=0;
         else
            a[i][j]=20000000;
   for (i=1;i<=m;i++)
   {
      scanf("%d%d",&x,&y);
      a[x][y]=1;
      a[y][x]=1;
   }
   for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
         for (k=1;k<=n;k++)
            if (a[j][i]+a[i][k]<a[j][k])
               a[j][k]=a[j][i]+a[i][k];
   scanf("%d",&p);
   s=0;
   for (i=1;i<=p;i++)
   {
      scanf("%d%d",&x,&y);
      work(x,y);
   }
   for (i=1;i<=s;i++)
      printf("%d\n",ans[i]);
   system("pause");
   return(0);
}
void work(int x,int y)
{
   int i,sum;
   sum=0;
   for (i=1;i<=n;i++)
      if (i!=x && i!=y && a[i][x]+a[i][y]==a[x][y])
         sum++;
   s++;
   ans[s]=sum+2;
}
