#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int m=100000000;
class bignum
{
   int a[100];
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
         printf("%08d",a[i]);
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
bignum f[1010];
int main()
{
   void init();
   init();
   int n;
   while (scanf("%d",&n)==1)
      f[n].print();
   system("pause");
   return(0);
}
void init()
{
   f[1]=f[2]=f[3]=1;
   for (int i=4;i<=1000;i++)
      f[i]=f[i-2]+f[i-3];
}
