#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[21][21][100];
int main()
{
   void multi(int *,int *,int),plus(int *,int *,int *);
   int i,j,n,m;
   int a[100];
   scanf("%d%d",&n,&m);
   if (n<m)
      printf("0\n");
   else
   {
      memset(f,0,sizeof(f));
      for (i=1;i<=n;i++)
      {
         f[i][1][0]=1;
         f[i][1][1]=1;
      }
      for (i=2;i<=n;i++)
         for (j=2;j<=m;j++)
         {
            memset(a,0,sizeof(a));
            multi(a,f[i-1][j],j);
            plus(f[i][j],f[i-1][j-1],a);
         }
      for (i=1;i<=m;i++)
         multi(f[n][m],f[n][m],i);
      for (i=f[n][m][0];i>=1;i--)
         printf("%d",f[n][m][i]);
      printf("\n");
   }
   system("pause");
   return(0);
}
void multi(int *a,int *b,int t)
{
   int i,x;
   x=0;
   for (i=1;i<=b[0];i++)
   {
      a[i]=b[i]*t+x;
      x=a[i]/10;
      a[i]%=10;
   }
   a[0]=b[0];
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
}
void plus(int *a,int *b,int *c)
{
   int max(int,int);
   int i,x;
   a[0]=max(b[0],c[0]);
   x=0;
   for (i=1;i<=a[0];i++)
   {
      a[i]=b[i]+c[i]+x;
      x=a[i]/10;
      a[i]%=10;
   }
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
}
int max(int x,int y)
{
   if (x>y)
      return(x);
   else
      return(y);
}
