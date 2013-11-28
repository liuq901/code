#include <cstdio>
#include <cstdlib>
int a[2001],b[2001],f[2001][2001];
int main()
{
   int max(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n=0,ans=0;
      while (1)
      {
         int x;
         scanf("%d",&x);
         if (!x)
            break;
         a[++n]=x;
      }
      while (1)
      {
         int m=0;
         while (1)
         {
            int x;
            scanf("%d",&x);
            if (!x)
               break;
            b[++m]=x;
         }
         if (!m)
            break;
         for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
               if (a[i]==b[j])
                  f[i][j]=f[i-1][j-1]+1;
               else
                  f[i][j]=max(f[i-1][j],f[i][j-1]);
         ans=max(ans,f[n][m]);
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
