#include <cstdio>
#include <cstdlib>
bool f[10010];
int main()
{
   int calc(int);
   for (int i=1;i<=10000;i++)
   {
      int p=calc(i);
      if (p<=10000)
         f[p]=true;
   }
   for (int i=1;i<=10000;i++)
      if (!f[i])
         printf("%d\n",i);
   system("pause");
   return(0);
}
int calc(int x)
{
   int ans=x;
   while (x)
   {
      ans+=x%10;
      x/=10;
   }
   return(ans);
}
