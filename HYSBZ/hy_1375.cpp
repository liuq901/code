#include <cstdio>
#include <cstdlib>
#include <cstring>
int s[101],c[101],q[1000001][2],d[101][10001],a[101][101][3];
bool f[101][10001];
int main()
{
   void init(int,int);
   int n,m,s_p,t_p;
   scanf("%d%d%d%d",&n,&m,&s_p,&t_p);
   for (int i=1;i<=m;i++)
   {
      int x,y,p,q;
      scanf("%d%d%d%d",&x,&y,&p,&q);
      a[x][++s[x]][0]=p;
      a[x][s[x]][1]=q;
      a[x][s[x]][2]=y;
      a[y][++s[y]][0]=p;
      a[y][s[y]][1]=q;
      a[y][s[y]][2]=x;
   }
   init(n,s_p);
   int l,r;
   l=0,r=1;
   q[1][0]=s_p;
   q[1][1]=0;
   memset(d,26,sizeof(d));
   d[s_p][0]=0;
   f[s_p][0]=true;
   while (l!=r)
   {
      l++;
      if (l>1000000)
         l=1;
      int x0=q[l][0],x1=q[l][1];
      for (int i=1;i<=s[x0];i++)
      {
         int y0=a[x0][i][2],y1=x1+a[x0][i][0];
         if (y1>c[y0])
            continue;
         if (d[x0][x1]+a[x0][i][1]<d[y0][y1])
         {
            d[y0][y1]=d[x0][x1]+a[x0][i][1];
            if (!f[y0][y1])
            {
               f[y0][y1]=true;
               r++;
               if (r>1000000)
                  r=1;
               q[r][0]=y0;
               q[r][1]=y1;
            }
         }
      }
      f[x0][x1]=false;
   }
   int min=20000000,ans=0;
   for (int i=0;i<=c[t_p];i++)
      if (d[t_p][i]<min)
      {
         min=d[t_p][i];
         ans++;
      }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void init(int n,int s_p)
{
   bool f[101]={0};
   int cost[101];
   memset(cost,26,sizeof(cost));
   cost[s_p]=c[s_p]=0;
   for (int i=1;i<=n;i++)
   {
      int k=0,min=20000000;
      for (int j=1;j<=n;j++)
         if (cost[j]<min && !f[j])
         {
            k=j;
            min=cost[j];
         }
      if (!k)
         break;
      f[k]=true;
      for (int j=1;j<=s[k];j++)
      {
         int p=a[k][j][2];
         if (cost[k]+a[k][j][1]<cost[p])
         {
            cost[p]=cost[k]+a[k][j][1];
            c[p]=c[k]+a[k][j][0];
         }
      }
   }
}
