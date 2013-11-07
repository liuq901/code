#include <cstdio>
#include <cstdlib>
int main()
{
   bool check(int);
   int ans=0;
   for (int i=1;i<=1000000;i++)
      if (check(i))
         ans+=i;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool check(int x)
{
   int t=x,now=0;
   while (t)
   {
      now=now*10+t%10;
      t/=10;
   }
   if (now!=x)
      return(false);
   t=x,now=0;
   while (t)
   {
      now=now<<1|t&1;
      t>>=1;
   }
   return(now==x);
}
