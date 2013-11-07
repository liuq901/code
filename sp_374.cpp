#include <cstdio>
#include <cstdlib>
int s[201][201],a[201][201];
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      int sum,ans=-1<<30;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            scanf("%d",&a[i][j]);
            if (!a[i][j])
               a[i][j]=-1;
            s[i][j]=s[i-1][j]+a[i][j];
         }
      for (int i=1;i<=n;i++)
         for (int j=i+1;j<=n;j++)
         {
            int p=s[j][1]-s[i-1][1],time=1;
            for (int k=2;k<=m;k++)
            {
               int now=s[j][k]-s[i-1][k]+p;
               if (now>ans)
               {
                  ans=now;
                  sum=time;
               }
               else if (now==ans)
                  sum+=time;
               p+=a[i][k]+a[j][k];
               if (s[j][k]-s[i-1][k]>p)
               {
                  p=s[j][k]-s[i-1][k];
                  time=1;
               }
               else if (s[j][k]-s[i-1][k]==p)
                  time++;
            }
         }
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            int s=0;
            for (int k=j;k<=m;k++)
            {
               s+=a[i][k];
               if (s>ans)
               {
                  ans=s;
                  sum=1;
               }
               else if (s==ans)
                  sum++;
            }
         }
      for (int i=1;i<=m;i++)
         for (int j=1;j<=n;j++)
         {
            int s=a[j][i];
            for (int k=j+1;k<=n;k++)
            {
               s+=a[k][i];
               if (s>ans)
               {
                  ans=s;
                  sum=1;
               }
               else if (s==ans)
                  sum++;
            }
         }
      printf("%d %d\n",ans,sum);
   }
   system("pause");
   return(0);
}
