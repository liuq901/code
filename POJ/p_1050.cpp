#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
   int n,s[101][101]={0};
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         int x;
         scanf("%d",&x);
         s[i][j]=s[i-1][j]+x;
      }
   int ans=-1<<30;
   for (int i=1;i<=n;i++)
      for (int j=i;j<=n;j++)
      {
         int sum=0;
         for (int k=1;k<=n;k++)
         {
            int x=s[j][k]-s[i-1][k];
            sum=max(sum+x,x);
            ans=max(ans,sum);
         }
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
