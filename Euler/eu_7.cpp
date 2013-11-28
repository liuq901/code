#include <cstdio>
#include <cstdlib>
int a[1000010];
int main()
{
   void init();
   init();
   printf("%d\n",a[10001]);
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
