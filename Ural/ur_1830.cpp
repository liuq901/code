#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
typedef long long ll;
char s[60],t[60];
ll f[60];
int main()
{
   ll calc(int,string);
   int n;
   scanf("%d%s%s",&n,s,t);
   f[1]=1;
   for (int i=2;i<=n;i++)
      f[i]=(f[i-1]<<1)+1;
   printf("%lld\n",calc(n,s));
   system("pause");
   return(0);
}
ll calc(int n,string s)
{
   ll work(int,string);
   if (!n)
      return(0);
   if (s[n-1]==t[n-1])
      return(calc(n-1,s));
   if (n==1)
      return(1);
   string now="";
   for (int i=1;i<n-1;i++)
      now+='0';
   now+='1';
   return(work(n-1,s)+calc(n-1,now)+1);
}
ll work(int n,string s)
{
   if (!n)
      return(0);
   if (s[n-1]=='0')
      return(work(n-1,s)+1+f[n-1]);
   int k=-1;
   for (int i=n-2;i>=0;i--)
      if (s[i]=='1')
      {
         k=i+1;
         break;
      }
   return(k==-1?0:work(k-1,s)+1+f[k-1]);
}
