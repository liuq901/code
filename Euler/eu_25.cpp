#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int m=100000000;
class bignum
{
   int a[130];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   bignum(int x)
   {
      memset(a,0,sizeof(a));
      a[a[0]=1]=x;
   }
   int digit()
   {
      int x=a[a[0]],ans=0;
      while (x)
         ans++,x/=10;
      return(ans+((a[0]-1)<<3));
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
   int operator [](int x) const
   {
      return(a[x]);
   }
};
bignum operator +(const bignum &a,const bignum &b)
{
   bignum c;
   c[0]=max(a[0],b[0]);
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/m;
      c[i]%=m;
   }
   if (x)
      c[++c[0]]=x;
   return(c);
}
bignum a(1),b(1);
int main()
{
   int now=2;
   while (1)
   {
      bignum c=a+b;
      a=b,b=c;
      now++;
      if (c.digit()==1000)
      {
         printf("%d\n",now);
         break;
      }
   }
   system("pause");
   return(0);
}
