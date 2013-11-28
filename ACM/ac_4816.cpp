#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int m=10000;
typedef long long ll;
struct bignum
{
   bool flag;
   int len,a[2600];
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   bignum(int x)
   {
      flag=x>=0;
      x=abs(x);
      memset(a,0,sizeof(a));
      len=0;
      while (x)
      {
         a[++len]=x%m;
         x/=m;
      }
      if (!len)
         len=1;
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
};
bignum operator *(bignum a,ll b)
{
   bignum c;
   if (!b)
   {
      c.len=1,c.flag=true;
      return(c);
   }
   c.len=a.len;
   c.flag=a.flag;
   if (b<0)
      c.flag=!c.flag;
   if (b<0)
      b=-b;
   ll x=0;
   for (int i=1;i<=c.len;i++)
   {
      ll t=ll(a[i])*b+x;
      x=t/m;
      c[i]=t%m;
   }
   while (x)
   {
      c[++c.len]=x%m;
      x/=m;
   }
   if (c.len==1 && c[1]==0)
      c.flag=true;
   return(c);
}
bool operator >=(bignum a,bignum b)
{
   if (a.flag && !b.flag)
      return(true);
   if (!a.flag && b.flag)
      return(false);
   if (!a.flag && !b.flag)
   {
      a.flag=true,b.flag=true;
      return(b>=a);
   }
   if (a.len<b.len)
      return(false);
   if (a.len>b.len)
      return(true);
   for (int i=a.len;i;i--)
   {
      if (a[i]>b[i])
         return(true);
      if (a[i]<b[i])
         return(false);
   }
   return(true);
}
int a[1010][30];
int main()
{
   int n,m;
   while (scanf("%d%d",&m,&n)==2)
   {
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
      bignum ans;
      int k;
      for (int i=1;i<=m;i++)
      {
         bignum now(1);
         for (int j=1;j<=n;j++)
            now=now*a[j][i];
         if (i==1)
            ans=now,k=1;
         else if (now>=ans)
            ans=now,k=i;
      }
      printf("%d\n",k);
   }
   system("pause");
   return(0);
}
