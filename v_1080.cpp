#include <cstdio>
#include <cstdlib>
int main()
{
   int a,b,c,i,j,k;
   int f[26][26][26];
   for (i=0;i<=20;i++)
      for (j=0;j<=20;j++)
         for (k=0;k<=20;k++)
            if (i==0 || j==0 || k==0)
               f[i][j][k]=1;
            else if (i<j && j<k)
               f[i][j][k]=f[i][j][k-1]+f[i][j-1][k-1]-f[i][j-1][k];
            else
               f[i][j][k]=f[i-1][j][k]+f[i-1][j-1][k]+f[i-1][j][k-1]-f[i-1][j-1][k-1];
   while (1)
   {
      scanf("%d%d%d",&a,&b,&c);
      i=a,j=b,k=c;
      if (a==-1 && b==-1 && c==-1)
         break;
      if (a<=0 || b<=0 || c<=0)
         a=b=c=0;
      else if (a>20 || b>20 || c>20)
         a=b=c=20;
      printf("w(%d, %d, %d) = %d\n",i,j,k,f[a][b][c]);
   }
   system("pause");
   return(0);
}
