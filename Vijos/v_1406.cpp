#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char ch[26][26];
   int n,m,i,j,k,t,min;
   int a[500][500];
   scanf("%d%d%*c",&m,&n);
   memset(ch,0,sizeof(ch));
   for (i=1;i<=m;i++)
   {
      for (j=1;j<=n;j++)
         scanf("%c",&ch[i][j]);
      scanf("%*c");
   }
   t=0;
   for (i=1;i<=m*n;i++)
      for (j=1;j<=m*n;j++)
         if (i==j)
            a[i][j]=0;
         else
            a[i][j]=200000;
   for (i=1;i<=m;i++)
      for (j=1;j<=n;j++)
      {
         t++;
         if (j-1>=1)
            if (ch[i][j-1]==ch[i][j])
               a[t][t-1]=0;
            else
               a[t][t-1]=1;
         if (j+1<=n)
            if (ch[i][j+1]==ch[i][j])
               a[t][t+1]=0;
            else
               a[t][t+1]=1;
         if (i-1>=1)
            if (ch[i-1][j]==ch[i][j])
               a[t][t-n]=0;
            else
               a[t][t-n]=1;
         if (i+1<=m)
            if (ch[i+1][j]==ch[i][j])
               a[t][t+n]=0;
            else
               a[t][t+n]=1;
      }
   for (i=1;i<=t;i++)
      for (j=1;j<=t;j++)
         for (k=1;k<=t;k++)
            if (a[j][i]+a[i][k]<a[j][k])
               a[j][k]=a[j][i]+a[i][k];
   min=200000;
   for (i=1;i<=n;i++)
      for (j=(m-1)*n+1;j<=n*m;j++)
         if (a[i][j]<min)
            min=a[i][j];
   printf("%d\n",min+1);
   system("pause");
   return(0);
}
