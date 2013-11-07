#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
   int calc(int);
   int ans=0;
   for (int i=1;i<10000;i++)
      ans=max(ans,calc(i));
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int calc(int x)
{
   ll now=0;
   int t=0;
   while (now<100000000)
   {
      int p=++t*x,y=1;
      while (y<=p)
         y*=10;
      now=now*y+p;
   }
   if (now>=1000000000)
      return(-1);
   bool f[10]={0};
   f[0]=true;
   int ret=now;
   while (now)
   {
      if (f[now%10])
         return(false);
      f[now%10]=true;
      now/=10;
   }
   return(ret);
}
