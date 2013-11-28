#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
char to[70],s[510];
int a[70];
string ans;
int main()
{
   int calc(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%s",s);
      int len=strlen(s);
      memset(a,0,sizeof(a));
      for (int i=0;i<len;i++)
         if (isdigit(s[i]))
         {
            a[s[i]-'0'+1]++;
            to[s[i]-'0'+1]=s[i];
         }
         else if (isupper(s[i]))
         {
            a[s[i]-'A'+11]++;
            to[s[i]-'A'+11]=s[i];
         }
         else
         {
            a[s[i]-'a'+37]++;
            to[s[i]-'a'+37]=s[i];
         }
      int n=calc(0);
      ans="";
      for (int i=1;i<=n;i++)
         for (int j=62;j;j--)
         {
            if (!a[j])
               continue;
            a[j]--;
            if (calc(j)==n-i && (ans.empty() || to[j]!=ans[i-2]))
            {
               ans+=to[j];
               break;
            }
            a[j]++;
         }
      printf("%s\n",ans.c_str());
   }
   system("pause");
   return(0);
}
int calc(int id)
{
   int sum=0,k=-1;
   for (int i=1;i<=62;i++)
   {
      sum+=a[i];
      k=max(k,a[i]);
   }
   bool same=true;
   for (int i=1;i<=62;i++)
      if (a[i]==k && i!=id)
      {
         same=false;
         break;
      }
   int p=sum-k,support;
   support=same?p<<1:(p<<1)+1;
   return(min(support,sum));
}
