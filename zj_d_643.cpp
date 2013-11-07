#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
char S[100010];
string s,ans[100010];
int m,a[100010];
int main()
{
   void init(int),work(int,int);
   gets(S);
   s=S;
   init(s.size());
   for (int i=1;i<=a[0];i++)
      work(a[i],s.size());
   if (!m)
      printf("bomb!\n");
   system("pause");
   return(0);
}
bool f[100010];
int t,now,p[100010][2];
void init(int n)
{
   void search(int);
   for (int i=2;i*i<=n;i++)
   {
      if (f[i])
         continue;
      for (int j=i;i*j<=n;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=n;i++)
   {
      if (i==1)
         break;
      if (f[i] || n%i)
         continue;
      p[++t][0]=i;
      while (!(n%i))
      {
         p[t][1]++;
         n/=i;
      }
   }
   now=1;
   search(1);
   sort(a+1,a+a[0]+1);
}
void search(int dep)
{
   if (dep==t+1)
   {
      a[++a[0]]=now;
      return;
   }
   int tmp=now;
   for (int i=0;i<=p[dep][1];i++)
   {
      search(dep+1);
      now*=p[dep][0];
   }
   now=tmp;
}
string d[100010];
void work(int x,int n)
{
   int t=0;
   for (int i=0;i<n;i+=x)
      d[++t]=s.substr(i,x);
   sort(d+1,d+t+1);
   d[0]="";
   for (int i=1;i<=t;i++)
      d[0]+=d[i];
   if (d[0]!=s)
   {
      m++;
      printf("%s\n",d[0].c_str());
   }
}
