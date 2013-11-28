#include <cstdio>
#include <cstdlib>
int a[1000010];
int main()
{
   void init();
   init();
   long long n=600851475143LL;
   int ans;
   for (int i=1;i<=a[0];i++)
   {
      if (n%a[i])
         continue;
      while (!(n%a[i]))
         n/=a[i];
      ans=a[i];
   }
   if (n>ans)
      ans=n;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool f[1000010];
void init()
{
   for (int i=2;i<=1000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=1000000;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=1000000;i++)
      if (!f[i])
         a[++a[0]]=i;
}
