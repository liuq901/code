#include <cstdio>
#include <cstdlib>
const int m=100000000;
class bignum
{
   int a[1001];
public:
   bignum(){}
   bignum(int x)
   {
      a[0]=1;
      a[1]=x;
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
int main()
{
   bignum ans(1);
   int n;
   scanf("%d",&n);
   if (n>1)
   {
      int p=n/3,q=n%3;
      if (q==1)
         p--,q=4;
      for (int i=1;i<=p;i++)
         ans=ans*3;
      if (q)
         ans=ans*q;
   }
   ans.print();
   system("pause");
   return(0);
}
