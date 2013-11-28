#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,m,sum,r,b[2001],dfn[2001],low[2001],a[200001][2];
bool f[2001];
int main()
{
   void floodfill(int,int);
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[2*i-1][0]=y;
      a[2*i-1][1]=b[x];
      b[x]=2*i-1;
      a[2*i][0]=x;
      a[2*i][1]=b[y];
      b[y]=2*i;
   }
   floodfill(1,0);
   long long ans;
   ans=(long long)sum*(m-sum)+(long long)sum*(sum-1)/2+r;
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
int g[2001],d[2001],s[2001],t[2001],p[2001],l[2001][2001];
bool flag[2001][2001];
void floodfill(int x,int father)
{
   void update(int,int);
   f[x]=true;
   g[x]=father;
   d[x]=d[father]+1;
   int i=b[x];
   while (i!=0)
   {
      if (a[i][0]==father)
         p[x]++;
      else if (!f[a[i][0]])
      {
         floodfill(a[i][0],x);
         for (int j=1;j<=d[x]-1;j++)
            l[x][j]+=l[a[i][0]][j];
      }
      else if (d[a[i][0]]<d[x])
         l[x][d[a[i][0]]]++;
      i=a[i][1];
   }
   s[x]=p[x];
   for (int i=1;i<=d[x]-1;i++)
   {
      s[x]+=l[x][i];
      if (l[x][i]>0)
         t[x]=i;
   }
   if (s[x]==1)
   {
      sum++;
      return;
   }
   if (s[x]==2)
      r++;
   if (p[x]!=1)
      return;
   i=b[x];
   while (i!=0)
   {
      if (g[a[i][0]]==x)
         update(x,a[i][0]);
      i=a[i][1];
   }
}
void update(int x,int y)
{
   if (flag[x][y])
      return;
   flag[x][y]=true;
   if (p[y]==1 && s[x]==s[y] && d[x]>t[y])
      r++;
   int i=b[y];
   while (i!=0)
   {
      if (g[a[i][0]]==y)
         update(x,a[i][0]);
      i=a[i][1];
   }
}
