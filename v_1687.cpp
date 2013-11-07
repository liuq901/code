#include <cstdio>
#include <cstdlib>
#include <cstring>
const int m=10000;
class bignum
{
   int a[2600];
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
   void print()
   {
      printf("%d",a[a[0]]);
      for (int i=a[0]-1;i;i--)
         printf("%04d",a[i]);
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
      x=c[i]/m;
      c[i]%=m;
   }
   if (x)
      c[++c[0]]=x;
   return(c);
}
bignum operator *(bignum a,int b)
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
bignum f[1001];
int main()
{
   int n;
   scanf("%d",&n);
   f[1]=0,f[2]=1;
   for (int i=3;i<=n;i++)
      f[i]=(f[i-1]+f[i-2])*(i-1);
   f[n].print();
   system("pause");
   return(0);
}
