#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[16][101][100];
int main()
{
   void plus(int *,int *,int *);
   int n,m,i,j;
   memset(f,0,sizeof(f));
   scanf("%d%d",&m,&n);
   for (i=1;i<=m;i++)
   {
      f[1][i][0]=1;
      f[1][i][1]=2*i;
   }
   for (i=2;i<=n;i++)
   {
      f[i][1][0]=1;
      f[i][1][1]=2;
      for (j=2;j<=m;j++)
         plus(f[i][j-1],f[i-1][j-1],f[i][j]);
   }
   for (i=f[n][m][0];i>=1;i--)
      printf("%d",f[n][m][i]);
   printf("\n");
   system("pause");
   return(0);
}
void plus(int *a,int *b,int *c)
{
   int i,x;
   if (a[0]>b[0])
      c[0]=a[0];
   else
      c[0]=b[0];
   x=0;
   for (i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/10;
      c[i]%=10;
   }
   while (x!=0)
   {
      c[0]++;
      c[c[0]]=x%10;
      x/=10;
   }
}
