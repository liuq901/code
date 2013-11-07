#include <cstdio>
#include <cstdlib>
typedef long long ll;
int main()
{
   ll abs(ll);
   ll x1,y1,x2,y2,r;
   while (scanf("%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&r)==5)
      printf("%s\n",abs(x1-x2)+abs(y1-y2)>r?"alive":"die");
   system("pause");
   return(0);
}
ll abs(ll x)
{
   if (x<0)
      x=-x;
   return(x);
}
