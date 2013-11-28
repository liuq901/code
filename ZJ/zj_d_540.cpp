#include <cstdio>
#include <cstdlib>
#include <cstring>
int tot,b[10010],a[1000010][3];
int main()
{
   void add(int,int,int);
   bool spfa(int);
   int T;
   while (scanf("%d",&T)==1)
      while (T--)
      {
         memset(b,0,sizeof(b));
         tot=0;
         int n,m1,m2;
         scanf("%d%d%d",&n,&m1,&m2);
         for (int i=1;i<=m1;i++)
         {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
            add(y,x,z);
         }
         for (int i=1;i<=m2;i++)
         {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,-z);
         }
         printf("%s\n",spfa(n)?"YES":"NO");
      }
   system("pause");
   return(0);
}
void add(int x,int y,int z)
{
   a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
}
int vis[10010],q[10010],d[10010];
bool f[10010];
bool spfa(int n)
{
   memset(vis,0,sizeof(vis));
   memset(f,0,sizeof(f));
   memset(d,63,sizeof(d));
   int l=0,r=1;
   q[1]=1,d[1]=0,f[1]=true;
   while (l!=r)
   {
      l=l==n?1:l+1;
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[x]+a[i][1]<d[y])
         {
            d[y]=d[x]+a[i][1];
            vis[y]++;
            if (vis[y]>n)
               return(true);
            if (!f[y])
            {
               f[y]=true;
               q[r=r==n?1:r+1]=y;
            }
         }
      }
      f[x]=false;
   }
   return(false);
}
