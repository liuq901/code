#include <cstdio>
#include <cstdlib>
#include <cstring>
int s[501],t[501],f[501][501];
int main()
{
   int min(int,int);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      s[i]=s[i-1]+x;
      t[i]=t[i-1]+1-x;
   }
   memset(f,26,sizeof(f));
   f[0][0]=0;
   for (int i=1;i<=m;i++)
      for (int j=1;j<=n;j++)
         for (int k=0;k<j;k++)
            f[i][j]=min(f[i][j],f[i-1][k]+(t[j]-t[k])*(s[j]-s[k]));
   printf("%d\n",f[m][n]);
   system("pause");
   return(0);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
