#include <cstdio>
#include <cstdlib>
#include <cstring>
int tot,f[10001],dfn[10001],low[10001],b[10001],son[10001][2],ans[10001][2],a[40001][2];
int main()
{
   void tarjan(int,int),print(int);
   int t;
   scanf("%d",&t);
   bool flag=false;
   while (t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      m+=n;
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[i][0]=y;
         a[i][1]=b[x];
         b[x]=i;
         a[i+m][0]=x;
         a[i+m][1]=b[y];
         b[y]=i+m;
      }
      memset(dfn,0,sizeof(dfn));
      memset(ans,0,sizeof(ans));
      memset(son,0,sizeof(son));
      tot=0;
      if (flag)
         printf("\n");
      flag=true;
      tarjan(1,0);
      print(n);
   }
   system("pause");
   return(0);
}
void tarjan(int x,int father)
{
   void get_ans(int,int);
   low[x]=dfn[x]=++tot;
   f[x]=father;
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      if (!dfn[y])
      {
         tarjan(y,x);
         if (low[y]<low[x])
            low[x]=low[y];
         son[x][0]++;
         son[x][1]=y;
         if (son[y][0]>1)
            continue;
         if (!son[y][0] || x==1 || low[son[y][1]]<dfn[x])
         {
            get_ans(x,y);
            get_ans(y,x);
         }
         if (!son[y][0] || son[y][0]==1 && x!=1 && low[son[y][1]]>=dfn[x])
         {
            dfn[0]=20000000;
            int k=0;
            for (int j=b[y];j;j=a[j][1])
            {
               int t=a[j][0];
               bool flag=false;
               if (dfn[k]<dfn[t])
                  continue;
               for (int p=y;p;p=f[p])
                  if (p==t)
                  {
                     flag=true;
                     break;
                  }
               if (flag)
                  k=t;
            }
            get_ans(y,k);
            get_ans(k,y);
         }
      }
      else if (dfn[y]<low[x])
         low[x]=dfn[y];
   }
}
void get_ans(int x,int y)
{
   if (!ans[x][0])
      ans[x][0]=y;
   else
      ans[x][1]=y;
}
void print(int n)
{
   printf("1");
   int t,k=1;
   if (ans[1][0]<ans[1][1])
      t=ans[1][0];
   else
      t=ans[1][1];
   while (t!=1)
   {
      printf(" %d",t);
      if (ans[t][0]==k)
      {
         k=t;
         t=ans[t][1];
      }
      else
      {
         k=t;
         t=ans[t][0];
      }
   }
   printf("\n");
}
