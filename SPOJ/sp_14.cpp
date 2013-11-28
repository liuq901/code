#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[91],b[91];
int p[91][91];
int main()
{
   void work();
   int t,i;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
   {
      printf("Keypad #%d:\n",i);
      work();
      printf("\n");
   }
   system("pause");
   return(0);
}
void work()
{
   void print(int,int);
   int n,m,i,j,k,x,t;
   int a[91],f[91][91];
   scanf("%d%d%*c",&m,&n);
   for (i=1;i<=m;i++)
      scanf("%c",&s[i]);
   scanf("%*c");
   for (i=1;i<=n;i++)
      scanf("%c",&b[i]);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   memset(p,0,sizeof(p));
   memset(f,26,sizeof(f));
   x=t=0;
   for (i=1;i<=n;i++)
   {
      x++;
      t+=x*a[i];
      if (t<f[1][i])
         f[1][i]=t;
      else
         break;
   }
   for (i=1;i<=m-1;i++)
      for (j=1;j<=n;j++)
      {
         x=t=0;
         for (k=j+1;k<=n;k++)
         {
            x++;
            t+=x*a[k];
            if (t<0)
               break;
            if (t+f[i][j]<f[i+1][k])
            {
               f[i+1][k]=t+f[i][j];
               p[i+1][k]=j;
            }
         }
      }
   print(m,n);
}
void print(int x,int y)
{
   int i;
   if (x==0)
      return;
   print(x-1,p[x][y]);
   printf("%c: ",s[x]);
   for (i=p[x][y]+1;i<=y;i++)
      printf("%c",b[i]);
   printf("\n");
}
