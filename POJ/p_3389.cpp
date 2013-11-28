#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
typedef map <string,int>::iterator iter;
map <string,int> a;
vector <int> ans,b[26000];
string s[26000];
char S[26000];
int main()
{
   int hash(const string &),length();
   bool work();
   void print(int,int);
   int w,l,n;
   scanf("%d%d%d",&w,&l,&n);
   gets(S);
   for (int i=1;i<=n;i++)
   {
      gets(S);
      stringstream sin(S);
      string t;
      sin>>t;
      int id=hash(t);
      while (sin>>t)
         b[id].push_back(hash(t));
   }
   int eoln=hash("");
   while (gets(S))
   {
      stringstream sin(S);
      string t;
      while (sin>>t)
         ans.push_back(hash(t));
      ans.push_back(eoln);
   }
   for (iter k=a.begin();k!=a.end();k++)
      s[k->second]=k->first;
   while (length()<l && work());
   if (length()<l)
      printf("No result\n");
   else
      print(eoln,w);
   system("pause");
   return(0);
}
int hash(const string &s)
{
   int ret;
   if (!a.count(s))
   {
      ret=a.size();
      a[s]=ret;
   }
   else
      ret=a[s];
   return(ret);
}
int length()
{
   int ret=0;
   for (int i=0;i<ans.size();i++)
      ret+=s[ans[i]].size();
   return(ret);
}
bool work()
{
   bool flag=false;
   vector <int> ret;
   for (int i=0;i<ans.size();i++)
   {
      int x=ans[i];
      if (b[x].empty())
      {
         ret.push_back(x);
         continue;
      }
      flag=true;
      for (int j=0;j<b[x].size();j++)
         ret.push_back(b[x][j]);
   }
   ans=ret;
   return(flag);
}
void print(int eoln,int w)
{
   int i=0;
   while (1)
   {
      while (i<ans.size() && ans[i]==eoln)
         i++;
      if (i==ans.size())
         break;
      int x=ans[i++],sum=s[x].size();
      printf("%s",s[x].c_str());
      while (1)
      {
         if (i==ans.size() || ans[i]==eoln || sum+s[ans[i]].size()+1>w)
            break;
         printf(" %s",s[ans[i]].c_str());
         sum+=s[ans[i++]].size()+1;
      }
      printf("\n");
   }
}
