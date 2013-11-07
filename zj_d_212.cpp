#include <cstdio>
#include <cstdlib>
#include <cstring>
class bignum
{
   int a[26];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   void init(int x)
   {
      while (x)
      {
         a[++a[0]]=x%10;
         x/=10;
      }
   }
   void print()
   {
      for (int i=a[0];i>=1;i--)
         printf("%d",a[i]);
      printf("\n");
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
};
bignum operator +(bignum a,bignum b)
{
   bignum c;
   c[0]=a[0]>b[0]?a[0]:b[0];
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/10;
      c[i]%=10;
   }
   if (x)
      c[++c[0]]=x;
   return(c);
}
bignum f[101];
int main()
{
   void init();
   init();
   int n;
   while (scanf("%d",&n)!=EOF)
      f[n].print();
   system("pause");
   return(0);
}
void init()
{
   f[1].init(1);
   f[2].init(2);
   for (int i=3;i<=100;i++)
      f[i]=f[i-1]+f[i-2];
}
