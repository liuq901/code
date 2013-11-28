#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int m=100000000;
class bignum
{
   int a[10010];
   friend bignum operator *(bignum,int);
   friend bignum operator +(bignum,bignum);
public:
   bignum()
   {
      memset(a,0,sizeof(a));
      a[0]=1;
   }
   bignum(int x)
   {
      memset(a,0,sizeof(a));
      a[1]=x,a[0]=1;
   }
   bignum(char *s)
   {
      bignum a;
      int l=strlen(s);
      for (int i=l-1;i>=0;i--)
         a=a*2+int(s[i]-'0');
      *this=a;
   }
   bool zero()
   {
      return(a[0]==1 && a[1]==0);
   }
   bool even()
   {
      return(!(a[1]&1));
   }
   int &operator [](int x)
   {
      return(a[x]);
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
         c[i]+=m;
      }
   }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
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
   if (x)
      c[++c[0]]=x;
   return(c);
}
bignum operator /(bignum a,int b)
{
   bignum c;
   c[0]=a[0];
   int x=0;
   for (int i=a[0];i;i--)
   {
      int t=x*m+a[i];
      c[i]=t/b;
      x=t%b;
   }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   return(c);
}
bignum a,b;
char s[1000010];
int main()
{
   void print(bignum);
   gets(s);
   a=s;
   gets(s);
   b=s;
   while (1)
   {
      if (a<b)
         swap(a,b);
      if (b.zero())
      {
         print(a);
         break;
      }
      if (a.even() && b.even())
         a=a/2,b=b/2;
      else if (a.even())
         a=a/2;
      else if (b.even())
         b=b/2;
      else
      {
         bignum c=(a+b)/2,d=(a-b)/2;
         a=c,b=d;
      }
   }
   system("pause");
   return(0);
}
string ans;
void print(bignum a)
{
   while (!a.zero())
   {
      ans+=(a[1]&1)+'0';
      a=a/2;
   }
   reverse(ans.begin(),ans.end());
   printf("%s\n",ans.c_str());
}
