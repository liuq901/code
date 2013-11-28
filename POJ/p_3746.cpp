#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;
map <string,int> hash;
char s[100010],t[100010];
const string kind[]={"n.","pron.","adj.","adv.","prep.","art.","vt.","vi.","v."};
int main()
{
   bool check(string);
   int n,m;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=n;i++)
   {
      string p;
      scanf("%s%s",s,t);
      p=t;
      for (int j=0;j<9;j++)
         if (t==kind[j])
            hash[s]=j+1;
   }
   gets(s);
   for (int i=1;i<=m;i++)
   {
      gets(s);
      string p=s;
      printf("%s\n",check(s)?"YES":"NO");
   }
   system("pause");
   return(0);
}
string a[100],b[100];
bool check(string s)
{
   for (int i=0;i<s.size();i++)
      if (ispunct(s[i]))
         s.erase(i,1);
   int n=1;
   a[n]="";
   for (int i=0;i<s.size();i++)
      if (s[i]==' ' && (!i || isalpha(s[i-1])))
         a[++n]="";
      else
         a[n]+=tolower(s[i]);
   while (a[n]=="")
      n--;
   int t=0;
   for (int i=1;i<=n;i++)
   {
      int p=hash[a[i]];
      if (p==1)
         return(false);
      else if (p==2)
         b[++t]=a[i];
      else if (p==3)
      {
         if (i==n || hash[a[i+1]]!=1)
            return(false);
         b[++t]=a[i+1];
         i++;
      }
      else if (p==4)
      {
         if (i==n || hash[a[i+1]]<7)
            return(false);
         b[++t]=a[i+1];
         i++;
      }
      else if (p==5)
         b[++t]=a[i];
      else if (p==6)
      {
         if (i==n)
            return(false);
         if (hash[a[i+1]]==1)
         {
            b[++t]=a[i+1];
            i++;
         }
         else if (i+1<n && hash[a[i+1]]==3 && hash[a[i+2]]==1)
         {
            b[++t]=a[i+2];
            i+=2;
         }
         else
            return(false);
      }
      else
         b[++t]=a[i];
   }
   int a_pos=-1;
   for (int i=1;i<=t;i++)
      if (hash[b[i]]==5)
      {
         if (i==n || hash[b[i+1]]>2)
            return(false);
         if (a_pos!=-1)
            return(false);
         a_pos=i;
      }
   n=0;
   for (int i=1;i<=t;i++)
   {
      if (i==a_pos || i==a_pos+1)
         continue;
      a[++n]=b[i];
   }
   if (n==2)
   {
      if (hash[a[1]]>2)
         return(false);
      int p=hash[a[2]];
      if (p!=8 && p!=9)
         return(false);
   }
   else if (n==3)
   {
      if (hash[a[1]]>2)
         return(false);
      if (hash[a[3]]>2)
         return(false);
      int p=hash[a[2]];
      if (p!=7 && p!=9)
         return(false);
   }
   else
      return(false);
   return(true);
}
