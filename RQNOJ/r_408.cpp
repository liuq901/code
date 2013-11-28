#include <cstdio>
#include <cstdlib>
int c[201][201],d[201][201],f[201][201];
bool map[201][201];
int main()
{
   int min(int,int);
   int n,m;
   scanf("%d%d%*c",&n,&m);
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
      {
         char ch;
         scanf("%c",&ch);
         map[i][j]=ch=='1';
      }
      scanf("%*c");
   }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
      {
         if (!map[i][j])
         {
            c[i][j]=d[i][j]=f[i][j]=0;
            continue;
         }
         f[i][j]=min(min(f[i-1][j-1],c[i][j-1]),d[i-1][j])+1;
         c[i][j]=c[i][j-1]+1;
         d[i][j]=d[i-1][j]+1;
      }
   int p;
   scanf("%d",&p);
   for (int i=1;i<=p;i++)
   {
      int x,ans=0;
      scanf("%d",&x);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            if (f[i][j]>=x)
               ans++;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
