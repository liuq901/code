#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class bignum
{
   int a[1010];
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
bignum operator *(bignum a,bignum b)
{
   bignum c;
   c[0]=a[0]+b[0];
   for (int i=1;i<=a[0];i++)
      for (int j=1;j<=b[0];j++)
      {
         c[i+j-1]+=a[i]*b[j];
         c[i+j]+=c[i+j-1]/10;
         c[i+j-1]%=10;
      }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
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
      cout<<a*b<<endl;
   }
   system("pause");
   return(0);
}
