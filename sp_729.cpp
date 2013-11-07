#include <cstdio>
#include <cstdlib>
const int m=100000000;
class bignum
{
   int a[300];
public:
   bignum(){}
   bignum(int x)
   {
      a[0]=0;
      while (x)
      {
         a[++a[0]]=x%m;
         x/=m;
      }
      if (!a[0])
      {
         a[0]=1;
         a[1]=0;
      }
   }
   void print()
   {
      printf("%d",a[a[0]]);
      for (int i=a[0]-1;i>=1;i--)
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
   c[0]=a[0]>b[0]?a[0]:b[0];
   for (int i=a[0]+1;i<=c[0];i++)
      a[i]=0;
   for (int i=b[0]+1;i<=c[0];i++)
      b[i]=0;
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      if (c[i]>=m)
      {
         c[i]-=m;
         x=1;
      }
      else
         x=0;
   }
   if (x)
      c[++c[0]]=x;
   return(c);
}
bignum a[5001],b[5001];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      a[0]=b[0]=0;
      for (int i=1;i<=n;i++)
      {
         bool flag=true;
         for (int j=2;j*j<=(n-i+1);j++)
            if (!((n-i+1)%j))
            {
               flag=false;
               break;
            }
         if (flag)
         {
            a[i]=b[i-1]+b[i-1]+1;
            b[i]=a[i]+a[i-1]+1;
         }
         else
         {
            b[i]=a[i-1]+a[i-1]+1;
            a[i]=b[i]+b[i-1]+1;
         }
      }
      b[n].print();
   }
   system("pause");
   return(0);
}
