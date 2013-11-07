#include <cstdio>
#include <cstdlib>
const int limit=1<<15;
int ans[70000];
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
int a[70000];
bool f[70000];
void init()
{
   for (int i=2;i<=limit;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=limit;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=limit;i++)
      if (!f[i])
         a[++a[0]]=i;
   for (int i=1;i<=a[0];i++)
      for (int j=i;j<=a[0];j++)
      {
         if (a[i]+a[j]>limit)
            break;
         ans[a[i]+a[j]]++;
      }
}
