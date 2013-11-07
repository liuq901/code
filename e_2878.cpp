#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;
string a[110];
char s[100];
int main()
{
   bool cmp(const string &,const string &);
   int n=0;
   while (scanf("%s",s)==1)
      a[++n]=s;
   sort(a+1,a+n+1,cmp);
   for (int i=1;i<=n;i++)
      printf("%s%c",a[i].c_str(),i==n?'\n':' ');
   system("pause");
   return(0);
}
bool cmp(const string &a,const string &b)
{
   int x=0,y=0;
   bool p=false,q=false;
   for (int i=0;i<a.size();i++)
      if (isdigit(a[i]))
      {
         p=true;
         x=x*10+a[i]-'0';
      }
   for (int i=0;i<b.size();i++)
      if (isdigit(b[i]))
      {
         q=true;
         y=y*10+b[i]-'0';
      }
   if (!p && !q)
      return(a<b);
   if (!p && q)
      return(true);
   if (p && !q)
      return(false);
   if (x==y)
      return(a<b);
   return(x<y);
}
