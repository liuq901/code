#include <cstdio>
#include <cstdlib>
bool f[1000010];
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
      printf("%d\n",f[n]);
   }
   system("pause");
   return(0);
}
void init()
{
   f[1]=true;
   for (int i=2;i<=1000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=1000000;j++)
         f[i*j]=true;
   }
}
