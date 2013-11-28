#include <cstdio>
#include <cstdlib>
int a[20],b[110];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n,m,p;
      scanf("%d%d%d",&n,&m,&p);
      for (int i=1;i<=m;i++)
         scanf("%d",&a[i]);
      for (int i=1;i<=n;i++)
      {
         b[i]=0;
         for (int j=1;j<=m;j++)
         {
            int x;
            scanf("%d",&x);
            b[i]|=x<<j-1;
         }
      }
      int ans=0;
      for (int i=0;i<1<<m;i++)
      {
         int sum=0,tot=0;
         for (int j=1;j<=m;j++)
            if (i>>j-1&1)
               tot+=a[j];
         if (tot>p)
            continue;
         for (int j=1;j<=n;j++)
            if ((b[j]|i)==i)
               sum++;
         if (sum>ans)
            ans=sum;
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
