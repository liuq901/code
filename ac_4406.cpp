#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int m=10000000;
int main()
{
   void gcd(int,int,int &,int &);
   while (1)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      if (!a && !b)
         break;
      if (!a || !b)
         printf("%d\n",m+1);
      else
      {
         int t;
         t=__gcd(a,b);
         a/=t,b/=t;
         int x,y;
         gcd(a,b,x,y);
         int ans=0;
         if (x<=m && x>=-m && y<=m && y>=-m)
            ans=min((m-x)/b,(m+y)/a)+min((m+x)/b,(m-y)/a)+1;
         printf("%d\n",ans);
      }
   }
   system("pause");
   return(0);
}
void gcd(int a,int b,int &x,int &y)
{
   if (!b)
   {
      x=1,y=0;
      return;
   }
   int p,q;
   gcd(b,a%b,p,q);
   x=q,y=p-a/b*q;
}
