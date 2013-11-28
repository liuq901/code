#include <cstdio>
#include <cstdlib>
const int g[6]={1,10,100,1000,10000,100000};
int a[1000000],f[6][1000000];
int main()
{
   int i,j,k,t,n,m;  
   int ch[10][10];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&t);
      a[t]=1;
   }
   for (i=0;i<=9;i++)
      for (j=0;j<=9;j++)
         scanf("%d",&ch[i][j]);
   for (i=0;i<1000000;i++)
   {
      f[0][i]=0;
      t=i%10;
      for (j=0;j<=9;j++)
         f[0][i]+=a[i+j-t]*ch[t][j];
   }
   for (i=1;i<6;i++)
      for (j=0;j<1000000;j++)
      {
         f[i][j]=0;
         t=(j/g[i])%10;
         for (k=0;k<=9;k++)
            f[i][j]+=f[i-1][j+(k-t)*g[i]]*ch[t][k];
      }
   scanf("%d",&m);
   for (i=1;i<=m;i++)
   {
      scanf("%d",&t);
      k=1;
      for (j=0;j<6;j++)
         k*=ch[(t/g[j])%10][(t/g[j])%10];
      printf("%d\n",f[5][t]-k);
   }
   system("pause");
   return(0);
}
