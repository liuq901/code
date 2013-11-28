#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;
typedef long long ll;
string s,t;
int main()
{
   void calc(ll &,ll &,string &);
   pair <ll,ll> solve(ll,ll,ll,ll);
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      ll a,b,c,d;
      cin>>s>>t;
      calc(a,b,s);
      calc(c,d,t);
      pair <ll,ll> ans=solve(a,b,c,d);
      cout<<"Case "<<id<<": "<<ans.first<<"/"<<ans.second<<endl;
   }
   system("pause");
   return(0);
}
void calc(ll &a,ll &b,string &s)
{
   ll gcd(ll,ll);
   int k,t,p,len;
   k=t=p=-1;
   len=s.size();
   for (int i=0;i<len;i++)
      if (s[i]=='.')
         k=i;
      else if (s[i]=='[')
         t=i;
      else if (s[i]==']')
         p=i;
   if (k==-1)
   {
      a=0;
      for (int i=0;i<len;i++)
         a=a*10+s[i]-'0';
      b=1;
      return;
   }
   else if (t==-1)
   {
      b=1;
      for (int i=k+1;i<len;i++)
         b*=10;
      a=0;
      for (int i=0;i<len;i++)
         if (isdigit(s[i]))
            a=a*10+s[i]-'0';
      ll c=gcd(a,b);
      a/=c,b/=c;
      return;
   }
   else
   {
      ll x=0;
      for (int i=t+1;i<p;i++)
         x=x*10+9;
      b=x;
      for (int i=k+1;i<t;i++)
         b*=10;
      ll now=0;
      for (int i=0;i<t;i++)
         if (isdigit(s[i]))
            now=now*10+s[i]-'0';
      a=0;
      for (int i=t+1;i<p;i++)
         a=a*10+s[i]-'0';
      a+=now*x;
      ll c=gcd(a,b);
      a/=c,b/=c;
   }
}
pair <ll,ll> solve(ll a,ll b,ll c,ll d)
{
   ll gcd(ll,ll);
   ll tp=a/b+1;
   if (d*tp<c)
      return(make_pair(tp,1));
   ll g1=gcd(d,c%d),g2=gcd(b,a%b);
   pair <ll,ll> tmp=solve(d/g1,(c%d)/g1+(c%d==0),b/g2,(a%b)/g2);
   ll ggg=gcd(tmp.second+(a/b)*tmp.first,tmp.first);
   return(make_pair((tmp.second+(a/b)*tmp.first)/ggg,tmp.first/ggg));
}
ll gcd(ll a,ll b)
{
   return(b?gcd(b,a%b):a);
}
