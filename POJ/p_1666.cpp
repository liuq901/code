#include <cstdio>
#include <cstdlib>
int a[1000010];
int main()
{
   bool work(int);
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      int ans=0;
      while (work(n))
         ans++;
      printf("%d %d\n",ans,a[1]);
   }
   system("pause");
   return(0);
}
int b[1000010];
bool work(int n)
{
   bool flag=true;
   for (int i=1;i<=n;i++)
      if (a[i]!=a[1])
      {
         flag=false;
         break;
      }
   if (flag)
      return(false);
   for (int i=1;i<=n;i++)
      b[i]=a[i]>>1;
   b[0]=b[n];
   for (int i=1;i<=n;i++)
   {
      a[i]=b[i]+b[i-1];
      if (a[i]&1)
         a[i]++;
   }
   return(true);
}
