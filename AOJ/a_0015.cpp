#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class bignum
{
   int a[10000];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
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
      x=c[i]/10;
      c[i]%=10;
   }
   if (x)
      c[++c[0]]=x;
   return(c);
}
istream &operator >>(istream &cin,bignum &a)
{
   string s;
   cin>>s;
   a[0]=s.size();
   for (int i=1;i<=a[0];i++)
      a[i]=s[a[0]-i]-'0';
   return(cin);
}
ostream &operator <<(ostream &cout,bignum a)
{
   if (a[0]>80)
      cout<<"overflow";
   else
      for (int i=a[0];i;i--)
         cout<<a[i];
   return(cout);
}
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      bignum a,b;
      cin>>a>>b;
      cout<<a+b<<endl;
   }
   system("pause");
   return(0);
}
