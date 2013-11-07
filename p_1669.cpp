#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
char S[100000];
bool f[260];
int v[260];
int main()
{
   bool calc(int,int,int,const string &);
   int T;
   scanf("%d",&T);
   gets(S);
   while (T--)
   {
      gets(S);
      int len=strlen(S);
      string s;
      for (int i=0;i<len;i++)
         if (islower(S[i]) || S[i]=='(' | S[i]==')' || S[i]=='|' || S[i]=='^' || S[i]=='&' || S[i]=='~')
            s+=S[i];
      string a,b;
      for (int i=0;i<s.size();i++)
         if ((islower(s[i]) || s[i]==')') && (islower(s[i+1]) || s[i+1]=='(' || s[i+1]=='~'))
         {
            a=s.substr(0,i+1),b=s.substr(i+1);
            break;
         }
      memset(f,0,sizeof(f));
      for (int i=0;i<s.size();i++)
         if (islower(s[i]))
            f[s[i]]=true;
      int tot=0;
      for (int i='a';i<='z';i++)
         if (f[i])
            v[i]=tot++;
      bool flag=true;
      for (int i=0;i<1<<tot;i++)
         if (calc(0,a.size()-1,i,a)!=calc(0,b.size()-1,i,b))
         {
            flag=false;
            break;
         }
      static int id=0;
      printf("Data set %d: %s\n",++id,flag?"Equivalent":"Different");
   }
   system("pause");
   return(0);
}
bool calc(int l,int r,int value,const string &s)
{
   if (l==r)
   {
      int x=v[s[l]];
      return(value>>x&1);
   }
   int now=0;
   char op='-';
   for (int i=l;i<=r;i++)
   {
      if (s[i]=='(')
         now++;
      if (s[i]==')')
         now--;
      if (!now)
      {
         if (s[i]=='|')
            op='|';
         if (s[i]=='^' && op!='|')
            op='^';
         if (s[i]=='&' && op!='|' && op!='^')
            op='&';
      }
   }
   if (op=='-')
   {
      if (s[l]=='~')
         return(!calc(l+1,r,value,s));
      return(calc(l+1,r-1,value,s));
   }
   now=0;
   for (int i=r;i;i--)
   {
      if (s[i]==')')
         now++;
      if (s[i]=='(')
         now--;
      if (!now && s[i]==op)
      {
         bool a=calc(l,i-1,value,s),b=calc(i+1,r,value,s);
         if (op=='&')
            return(a&b);
         else if (op=='|')
            return(a|b);
         else
            return(a^b);
      }
   }
}
