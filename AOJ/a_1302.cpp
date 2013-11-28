#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
char a[130][20];
int n,m,f[180000];
int main()
{
   int solve(int);
   while (1)
   {
      scanf("%d%d",&m,&n);
      if (!m && !n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%s",a[i]+1);
      int limit=1;
      for (int i=1;i<=m;i++)
         limit*=3;
      memset(f,-1,sizeof(f));
      printf("%d\n",solve(limit-1));
   }
   system("pause");
   return(0);
}
int solve(int x)
{
   int calc(int);
   if (f[x]!=-1)
      return(f[x]);
   int t=x,p[20];
   for (int i=1;i<=m;i++)
   {
      p[i]=t%3;
      t/=3;
   }
   int num=calc(x);
   if (num==1)
      f[x]=0;
   else if (!num)
      f[x]=inf;
   else
   {
      int ret=inf,now=1;
      for (int i=1;i<=m;i++)
      {
         if (p[i]==2)
            ret=min(ret,max(solve(x-now),solve(x-now*2))+1);
         now*=3;
      }
      f[x]=ret;
   }
   return(f[x]);
}
bool flag[130];
int calc(int x)
{
   int p[20];
   for (int i=1;i<=m;i++)
   {
      p[i]=x%3;
      x/=3;
   }
   memset(flag,0,sizeof(flag));
   for (int i=1;i<=m;i++)
   {
      if (p[i]==2)
         continue;
      for (int j=1;j<=n;j++)
         if (a[j][i]-'0'!=p[i])
            flag[j]=true;
   }
   return(count(flag+1,flag+n+1,false));
}
