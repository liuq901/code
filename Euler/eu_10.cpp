#include <cstdio>
#include <cstdlib>
int a[2000010];
int main()
{
   void init();
   init();
   long long ans=0;
   for (int i=1;i<=a[0];i++)
      ans+=a[i];
   printf("%lld\n",ans);
   system("pause");
   return(0);
}
bool f[2000010];
void init()
{
   for (int i=2;i*i<=2000000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=2000000;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=2000000;i++)
      if (!f[i])
         a[++a[0]]=i;
}
