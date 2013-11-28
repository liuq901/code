#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class bignum
{
   int a[510];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   bignum(string s)
   {
      memset(a,0,sizeof(a));
      a[0]=s.size();
      for (int i=1;i<=a[0];i++)
         a[i]=s[a[0]-i]-'0';
      while (!a[a[0]] && a[0]>1)
         a[0]--;
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
   void print()
   {
      for (int i=a[0];i;i--)
         printf("%d",a[i]);
      printf("\n");
   }
};
bool operator <(bignum a,bignum b)
{
   if (a[0]!=b[0])
      return(a[0]<b[0]);
   for (int i=a[0];i;i--)
      if (a[i]!=b[i])
         return(a[i]<b[i]);
   return(false);
}
bignum operator -(bignum a,bignum b)
{
   bignum c;
   c[0]=a[0];
   for (int i=1;i<=c[0];i++)
   {
      c[i]+=a[i]-b[i];
      if (c[i]<0)
      {
         c[i+1]--;
         c[i]+=10;
      }
   }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   return(c);
}
int main()
{
   string s,t;
   while (cin>>s>>t)
   {
      bignum a(s),b(t);
      if (a<b)
      {
         printf("-");
         swap(a,b);
      }
      (a-b).print();
   }
   system("pause");
   return(0);
}
