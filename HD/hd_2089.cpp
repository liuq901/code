#include <cstdio>
#include <cstdlib>
int f[1000010];
int main()
{
   void init();
   init();
   while (1)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      if (!x && !y)
         break;
      printf("%d\n",f[y]-f[x-1]);
   }
   system("pause");
   return(0);
}
void init()
{
   bool check(int);
   for (int i=1;i<=1000000;i++)
      f[i]=f[i-1]+check(i);
}
bool check(int x)
{
   while (x)
   {
      if (x%10==4 || x%100==62)
         return(false);
      x/=10;
   }
   return(true);
}
