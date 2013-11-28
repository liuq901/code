#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
double b[110];
int a[110],pre[10010],p[10010];
bool f[10010];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      double sum=0;
      for (int i=1;i<=n;i++)
      {
         scanf("%lf",&b[i]);
         sum+=b[i];
      }
      for (int i=1;i<=n;i++)
         a[i]=int(b[i]*20000/sum);
      memset(f,0,sizeof(f));
      f[0]=true;
      int ans=0;
      for (int i=1;i<=n;i++)
         for (int j=10000;j>=a[i];j--)
         {
            if (f[j] || !f[j-a[i]])
               continue;
            f[j]=true;
            pre[j]=j-a[i];
            p[j]=i;
            ans=max(ans,j);
         }
      for (int i=ans;i;i=pre[i])
      {
         if (i!=ans)
            printf(" ");
         printf("%d",p[i]);
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
