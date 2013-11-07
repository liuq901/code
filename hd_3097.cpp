#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[1010],c[1010],a[1010][1010];
int main()
{
   void dfs(int);
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
         a[i][0]=0;
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[x][++a[x][0]]=y;
         a[y][++a[y][0]]=x;
      }
      memset(f,0,sizeof(f));
      for (int i=1;i<=n;i++)
         if (!f[i])
         {
            f[0]++;
            dfs(i);
         }
      memset(c,0,sizeof(c));
      for (int i=1;i<=n;i++)
         c[f[i]]+=a[i][0];
      bool flag=true;
      for (int i=1;i<=f[0];i++)
      {
         c[i]>>=1;
         if (c[i]&1)
         {
            flag=false;
            break;
         }
      }
      printf("%s\n",flag?"Yes":"No");
   }
   system("pause");
   return(0);
}
void dfs(int x)
{
   f[x]=f[0];
   for (int i=1;i<=a[x][0];i++)
   {
      int y=a[x][i];
      if (!f[y])
         dfs(y);
   }
}
