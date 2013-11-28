#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
const int n=20;
const double eps=1e-8;
struct data
{
   int a[n+10];
   data()
   {
      memset(a,0,sizeof(a));
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
   int operator [](int x) const
   {
      return(a[x]);
   }
};
data operator +(const data &a,const data &b)
{
   data c;
   for (int i=0;i<=n;i++)
      c[i]=a[i]+b[i];
   return(c);
}
data operator -(const data &a,const data &b)
{
   data c;
   for (int i=0;i<=n;i++)
      c[i]=a[i]-b[i];
   return(c);
}
data operator *(const data &a,const data &b)
{
   data c;
   for (int i=0;i<=n;i++)
      for (int j=0;j<=n;j++)
      {
         if (i+j>n)
            break;
         c[i+j]+=a[i]*b[j];
      }
   return(c);
}
vector <int> ans;
char s[100000];
int main()
{
   data calc(int,int);
   bool check(const data &,int,int);
   while (1)
   {
      scanf("%s",s);
      if (s[0]=='=')
         break;
      int len=strlen(s),m=2,k;
      for (int i=0;i<len;i++)
      {
         if (s[i]=='=')
            k=i;
         if (isdigit(s[i]))
            m=max(m,s[i]-'0'+1);
      }
      data a=calc(0,k-1)-calc(k+1,len-1);
      int t=0;
      while (t<=n && !a[t])
         t++;
      if (t>n)
         printf("%d+\n",m);
      else
      {
         ans.clear();
         int limit=abs(a[t]);
         for (int i=1;i*i<=limit;i++)
         {
            if (limit%i)
               continue;
            if (check(a,i,m))
               ans.push_back(i);
            if (check(a,limit/i,m))
               ans.push_back(limit/i);
         }
         sort(ans.begin(),ans.end());
         ans.erase(unique(ans.begin(),ans.end()),ans.end());
         if (ans.empty())
            printf("*\n");
         else
            for (int i=0;i<ans.size();i++)
               printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
      }
   }
   system("pause");
   return(0);
}
data calc(int l,int r)
{
   char op=' ';
   for (int i=l;i<=r;i++)
   {
      if (s[i]=='+')
         op=s[i];
      if (s[i]=='*' && op!='+')
         op=s[i];
   }
   if (op==' ')
   {
      data ret;
      for (int i=l;i<=r;i++)
         ret[r-i]=s[i]-'0';
      return(ret);
   }
   int k;
   for (int i=r;i>=l;i--)
      if (s[i]==op)
      {
         k=i;
         break;
      }
   if (op=='*')
      return(calc(l,k-1)*calc(k+1,r));
   else
      return(calc(l,k-1)+calc(k+1,r));
}
bool check(const data &a,int b,int limit)
{
   if (b<limit)
      return(false);
   double ans=0;
   for (int i=n;i>=0;i--)
      ans=ans*b+a[i];
   return(fabs(ans)<eps);
}
