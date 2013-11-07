#include <cstdio>
#include <cstdlib>
#include <cstring>
const int m=10000;
class bignum
{
   int a[260];
public:
   bignum(int x=0)
   {
      memset(a,0,sizeof(a));
      while (x)
      {
         a[++a[0]]=x%m;
         x/=m;
      }
      if (!a[0])
         a[0]=1;
   }
   void print()
   {
      printf("%d",a[a[0]]);
      for (int i=a[0]-1;i;i--)
         printf("%04d",a[i]);
      printf("\n");
   }
   int digit()
   {
      int t=a[a[0]],ans=a[0]-1<<2;
      while (t)
      {
         ans++;
         t/=10;
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
bignum operator +(const bignum &a,const bignum &b)
{
   bignum c;
   c[0]=a[0]>b[0]?a[0]:b[0];
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
bignum a[1010],b[1010];
int main()
{
   a[1]=3,b[1]=2;
   int ans=0;
   for (int i=2;i<=1000;i++)
   {
      a[i]=a[i-1]+b[i-1]+b[i-1];
      b[i]=a[i-1]+b[i-1];
      ans+=a[i].digit()>b[i].digit();
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
