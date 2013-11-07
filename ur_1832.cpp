#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
int m,c[300010],b[300010];
char ans[300010];
int main()
{
   void work(int);
   int n;
   scanf("%d",&n);
   work(n);
   for (int i=1;i<=n;i++)
   {
      bool flag[30]={0};
      for (int j=1;j<=m;j++)
      {
         if (i-c[j]<=0)
            break;
         flag[b[i-c[j]]]=true;
         if (i+c[j]>n)
            flag[b[i+c[j]-n]]=true;
      }
      int k=-1;
      for (int j=0;j<26;j++)
         if (!flag[j])
         {
            k=j;
            break;
         }
      if (k==-1)
      {
         b[0]=-1;
         break;
      }
      b[i]=k;
   }
   if (b[0]==-1)
      printf("Impossible\n");
   else
   {
      for (int i=1;i<=n;i++)
         ans[i-1]=b[i]+'a';
      ans[n]='\0';
      printf("%s\n",ans);
   }
   system("pause");
   return(0);
}
bool f[300010];
int a[300010];
void work(int n)
{
   void dfs(int,int,int);
   for (int i=2;i<=n;i++)
   {
      if (f[i])
         continue;
      for (int j=i;ll(i)*j<=n;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=n;i++)
      if (!f[i] && !(n%i))
         a[++a[0]]=i;
   dfs(1,1,n);
   sort(c+1,c+m+1);
   m=unique(c+1,c+m+1)-c-1;
}
void dfs(int x,int now,int n)
{
   c[++m]=x;
   if (!(n%a[now]))
      dfs(x*a[now],now,n/a[now]);
   if (now<a[0])
      dfs(x,now+1,n);
}
