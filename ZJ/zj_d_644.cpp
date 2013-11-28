#include <cstdio>
#include <cstdlib>
#include <cmath>
typedef long long ll;
const int mod=100019;
const double pi=acos(-1.0);
const double eps=0.5;
struct matrix
{
   int a[2][2];
};
matrix operator *(matrix a,matrix b)
{
   matrix c;
   for (int i=0;i<2;i++)
      for (int j=0;j<2;j++)
      {
         ll tmp=0;
         for (int k=0;k<2;k++)
            tmp+=ll(a.a[i][k])*b.a[k][j];
         c.a[i][j]=tmp%mod;
      }
   return(c);
}
matrix zero,one;
int main()
{
   matrix calc(int);
   zero.a[0][0]=zero.a[1][1]=one.a[1][0]=one.a[0][1]=one.a[1][1]=1;
   int n;
   scanf("%d",&n);
   n--;
   matrix ans=calc(n-1);
   double x=(1-cos(2*pi*n/3))/3;
   int p=(ans.a[0][0]+ans.a[1][0])%mod,q=(ans.a[0][1]+ans.a[1][1])%mod;
   q=(q-int(p/2.0-x+eps))%mod;
   if (q<0)
      q+=mod;
   printf("%d\n",q);
   system("pause");
   return(0);
}
matrix calc(int n)
{
   if (!n)
      return(zero);
   matrix ret=calc(n>>1);
   ret=ret*ret;
   if (n&1)
      ret=ret*one;
   return(ret);
}
