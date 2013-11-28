#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   void work(int,int,int);
   int c,n,m;
   while (1)
   {
      scanf("%d",&c);
      if (c==0)
         break;
      scanf("%d%d",&n,&m);
      if (m<=n && m<=c && (n-m)%2==0)
         work(c,n,m);
      else
         printf("0.000\n");
   }
   system("pause");
   return(0);
}   
double f[1010][101];
void work(int c,int n,int m)
{
   int i,j;
   if (n>1000)
      n=1000+n%2;
   memset(f,0,sizeof(f));
   f[0][0]=1;
   for (i=1;i<=n;i++)
   {
      f[i][1]+=f[i-1][0];
      f[i][c-1]+=f[i-1][c];
      for (j=1;j<c;j++)
      {
         f[i][j-1]+=f[i-1][j]*j/c;
         f[i][j+1]+=f[i-1][j]*(c-j)/c;
      }
   }
   printf("%.3lf\n",f[n][m]);
}
