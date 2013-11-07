#include <cstdio>
#include <cstdlib>
#include <cstring>
long long dist[100][10];
int p,b[100],a[10001][3];
int main()
{
   void spfa(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      memset(b,0,sizeof(b));
      for (int i=1;i<=m;i++)
      {
         int x,y,z;
         scanf("%d%d%d",&x,&y,&z);
         a[i][0]=y;
         a[i][1]=z;
         a[i][2]=b[x];
         b[x]=i;
      }
      int s,t;
      scanf("%d%d%d",&s,&t,&p);
      spfa(s);
      if (dist[t][0]>1LL<<60)
         printf("No Answer!\n");
      else
         printf("%I64d\n",dist[t][0]);
   }
   system("pause");
   return(0);
}
void spfa(int s)
{
   int l,r,q[1001][2];
   bool f[100][10]={0};
   l=0,r=1;
   q[1][0]=s,q[1][1]=0;
   memset(dist,26,sizeof(dist));
   dist[s][0]=0;
   f[s][0]=true;
   while (l!=r)
   {
      l++;
      if (l>1000)
         l=1;
      int x=q[l][0],now=q[l][1]+1;
      f[x][q[l][1]]=false;
      if (now==p)
         now=0;
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (dist[x][q[l][1]]+a[i][1]<dist[y][now])
         {
            dist[y][now]=dist[x][q[l][1]]+a[i][1];
            if (!f[y][now])
            {
               f[y][now]=true;
               r++;
               if (r>1000)
                  r=1;
               q[r][0]=y,q[r][1]=now;
            }
         }
      }
   }
}
