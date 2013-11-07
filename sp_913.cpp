#include <cstdio>
#include <cstdlib>
#include <cstring>
int b[10001],dep[10001],dist[10001],a[20001][3],f[10001][15];
int main()
{
   void floodfill(int,int);
   int lca(int,int),find(int,int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      memset(b,0,sizeof(b));
      memset(f,0,sizeof(f));
      for (int i=1;i<n;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         a[i][0]=y;
         a[i][1]=z;
         a[i][2]=b[x];
         b[x]=i;
         a[i+n][0]=x;
         a[i+n][1]=z;
         a[i+n][2]=b[y];
         b[y]=i+n;
      }
      floodfill(1,0);
      scanf("%*c");
      while (1)
      {
         char s[10];
         scanf("%s",s);
         if (s[1]=='O')
         {
            printf("\n");
            break;
         }
         if (s[1]=='I')
         {
            int x,y;
            scanf("%d%d",&x,&y);
            int p=lca(x,y);
            printf("%d\n",dist[x]+dist[y]-2*dist[p]);
         }
         else
         {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            int p=lca(x,y);
            z--;
            if (z<=dep[x]-dep[p])
               printf("%d\n",find(x,z));
            else
            {
               z-=dep[x]-dep[p];
               printf("%d\n",find(y,dep[y]-dep[p]-z));
            }
         }
         scanf("%*c");
      }
   }
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   f[x][0]=father;
   int t=0;
   while (f[x][t])
   {
      t++;
      f[x][t]=f[f[x][t-1]][t-1];
   }
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (y==father)
         continue;
      dep[y]=dep[x]+1;
      dist[y]=dist[x]+a[i][1];
      floodfill(y,x);
   }
}
int lca(int x,int y)
{
   int find(int,int);
   int p=dep[x]<dep[y]?dep[x]:dep[y];
   x=find(x,dep[x]-p);
   y=find(y,dep[y]-p);
   if (x==y)
      return(x);
   if (f[x][0]==f[y][0])
      return(f[x][0]);
   int k;
   for (int i=0;i<15;i++)
      if (f[x][i]==f[y][i])
      {
         k=i;
         break;
      }
   return(lca(f[x][k-1],f[y][k-1]));
}
int find(int x,int p)
{
   int log(int);
   if (!p)
      return(x);
   int t=log(p);
   return(find(f[x][t],p-(1<<t)));
}
int log(int p)
{
   int ans=0;
   while (p)
   {
      ans++;
      p/=2;
   }
   return(ans-1);
}
