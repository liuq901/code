#include <cstdio>
#include <cstdlib>
#include <cstring>
int id,dfn[1001],low[1001],b[1001],f[1001],s[1001],a[1001][1001];
bool flag[1001];
int main()
{
   void tarjan(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         a[i][0]=0;
      for (int i=1;i<=n;i++)
      {
         int k;
         scanf("%d",&k);
         for (int j=1;j<=k;j++)
         {
            int x;
            scanf("%d",&x);
            a[x][++a[x][0]]=i;
         }
      }
      memset(dfn,0,sizeof(dfn));
      memset(flag,0,sizeof(flag));
      memset(s,0,sizeof(s));
      id=f[0]=b[0]=0;
      for (int i=1;i<=n;i++)
         if (!dfn[i])
            tarjan(i,0);
      int d[1001]={0};
      for (int i=1;i<=n;i++)
         for (int j=1;j<=a[i][0];j++)
         {
            int x=a[i][j];
            if (f[i]==f[x])
               continue;
            d[f[x]]++;
         }
      int ans=0;
      for (int i=1;i<=f[0];i++)
      {
         if (!d[i] && ans)
         {
            ans=0;
            break;
         }
         if (!d[i])
            ans=s[i];
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void tarjan(int x,int father)
{
   dfn[x]=low[x]=++id;
   flag[x]=true;
   b[++b[0]]=x;
   for (int i=1;i<=a[x][0];i++)
   {
      int y=a[x][i];
      if (y==father)
         continue;
      if (!dfn[y])
      {
         tarjan(y,x);
         if (low[y]<low[x])
            low[x]=low[y];
      }
      else if (flag[y] && dfn[y]<low[x])
         low[x]=dfn[y];
   }
   if (dfn[x]==low[x])
   {
      f[0]++;
      while (b[b[0]]!=x)
      {
         f[b[b[0]]]=f[0];
         s[f[0]]++;
         flag[b[b[0]]]=false;
         b[0]--;
      }
      f[x]=f[0];
      s[f[0]]++;
      flag[x]=false;
      b[0]--;
   }
}
