#include <cstdio>
#include <cstdlib>
const int limit=1299709;
int ans[1300000];
int main()
{
   void init();
   init();
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      printf("%d\n",ans[n]);
   }
   system("pause");
   return(0);
}
int a[100001];
bool f[1300000];
void init()
{
   for (int i=2;i<=limit;i++)
   {
      if (f[i])
         continue;
      for (int j=i;(long long)i*j<=limit;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=limit;i++)
      if (!f[i])
         a[++a[0]]=i;
   for (int i=2;i<=a[0];i++)
      for (int j=a[i-1]+1;j<=a[i]-1;j++)
         ans[j]=a[i]-a[i-1];
}
