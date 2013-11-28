#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[201][201],g[201][201];
char st[10][201];
int main()
{
   int n,m,i,j,k,p,t,flag;
   int a[201];
   char s[201];
   scanf("%d%d%*c",&n,&p);
   t=0;
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=20;j++)
      {
         t++;
         scanf("%c",&s[t]);
      }
      scanf("%*c");
   }
   scanf("%d%*c",&m);
   for (i=1;i<=m;i++)
      scanf("%s",st[i]);
   n*=20;
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
         flag=1;
         for (k=0;k<strlen(st[j]);k++)
            if (s[i+k]!=st[j][k])
            {
               flag=0;
               break;
            }
         if (flag && (a[i]==0 || strlen(st[j])<a[i]))
            a[i]=strlen(st[j]);
      }
   memset(g,0,sizeof(g));
   for (i=1;i<=n;i++)
      for (j=1;j<=n-i+1;j++)
         for (k=i;k<=i+j-1;k++)
            if (a[k]!=0 && k+a[k]-1<=i+j-1)
               g[i][j]++;      
   memset(f,-127,sizeof(f));
   for (i=1;i<=n;i++)
      f[i][1]=g[1][i];
   for (i=1;i<=n;i++)
      for (j=1;j<=p;j++)
         for (k=1;k<=i-1;k++)
            if (f[i-k][j-1]+g[i-k+1][k]>f[i][j])
               f[i][j]=f[i-k][j-1]+g[i-k+1][k];
   printf("%d\n",f[n][p]);
   system("pause");
   return(0);
}
