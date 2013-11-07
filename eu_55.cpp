#include <cstdio>
#include <cstdlib>
typedef unsigned long long ll;
int main()
{
   bool check(int);
   int ans=0;
   for (int i=1;i<10000;i++)
      ans+=check(i);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool check(int x)
{
   ll calc(ll);
   bool check(ll);
   ll now=x;
   for (int i=1;i<=50;i++)
   {
      now+=calc(now);
      if (check(now))
         return(false);
   }
   return(true);
}
ll calc(ll x)
{
   ll ret=0;
   while (x)
   {
      ret=ret*10+x%10;
      x/=10;
   }
   return(ret);
}
bool check(ll x)
{
   ll y=x,t=0;
   while (y)
   {
      t=t*10+y%10;
      y/=10;
   }
   return(t==x);
}
