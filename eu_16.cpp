#include <cstdio>
#include <cstdlib>
#include <cstring>
const int m=100000000;
class bignum
{
   int a[50];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   bignum(int x)
   {
      memset(a,0,sizeof(a));
      a[0]=1,a[1]=x;
   }
   int digit()
   {
      int ans=0;
      for (int i=1;i<=a[0];i++)
         while (a[i])
         {
            ans+=a[i]%10;
            a[i]/=10;
         }
      return(ans);
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
   if (x)
      c[++c[0]]=x;
   return(c);
}
int main()
{
   bignum ans(1);
   for (int i=1;i<=1000;i++)
      ans=ans*2;
   printf("%d\n",ans.digit());
   system("pause");
   return(0);
}
