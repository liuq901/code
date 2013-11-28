#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;
typedef long long ll;
map <ll,int> s;
int main()
{
   int get(ll);
   int ans=0,k=0;
   for (int i=1;i<=1000000;i++)
   {
      int p=get(i);
      if (p>k)
         k=p,ans=i;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int get(ll x)
{
   if (s.count(x))
      return(s[x]);
   int ret;
   if (x==1)
      ret=1;
   else if (x&1)
      ret=get(3*x+1)+1;
   else
      ret=get(x>>1);
   s[x]=ret;
   return(ret);
}
