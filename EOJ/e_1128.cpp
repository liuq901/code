#include <cstdio>
#include <cstdlib>
int f[55];
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
   f[1]=1;
   f[2]=2;
   f[3]=3;
   for (int i=4;i<55;i++)
      f[i]=f[i-1]+f[i-3];
}
