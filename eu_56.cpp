#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int m=10000;
class bignum
{
   int a[60];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
      a[0]=1;
   }
   bignum(int x)
   {
      memset(a,0,sizeof(a));
      while (x)
      {
         a[++a[0]]=x%m;
         x/=m;
      }
      if (!a[0])
         a[0]++;
   }
   int digit() const
   {
      int sum=0;
      for (int i=1;i<=a[0];i++)
      {
         int x=a[i];
         while (x)
         {
            sum+=x%10;
            x/=10;
         }
      }
      return(sum);
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
bignum operator *(const bignum a,int b)
{
   bignum c;
   c[0]=a[0];
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]*b+x;
      x=c[i]/m;
      c[i]%=m;
   }
   while (x)
   {
      c[++c[0]]=x%m;
      x/=m;
   }
   return(c);
}
int main()
{
   int ans=0;
   for (int i=1;i<=100;i++)
   {
      bignum x=1;
      for (int j=1;j<=100;j++)
      {
         x=x*i;
         ans=max(ans,x.digit());
      }
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
