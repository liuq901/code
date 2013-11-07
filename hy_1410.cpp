#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   void init(),prepare(),find(),astar();
   init();
   prepare();
   find();
   astar();
   system("pause");
   return(0);
}
int dia,n,m,map[20][20];
void init()
{
   scanf("%d%d%*c",&n,&m);
   dia=0;
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=m;j++)
      {
         char ch;
         scanf("%c",&ch);
         if (ch=='#')
            map[i][j]=-1;
         else if (ch=='*')
         {
            map[i][j]=1;
            dia++;
         }
         else
            map[i][j]=0;
      }
      scanf("%*c");
   }
   for (int i=1;i<=n;i++)
      map[i][0]=map[i][m+1]=-1;
   for (int i=1;i<=m;i++)
      map[0][i]=map[0][n+1]=-1;
}
int b[11][2],a[20][20];
void prepare()
{
   void calc_dist(),calc_w(),calc_opt();
   int s;
   s=0;
   memset(a,0,sizeof(a));
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         if (map[i][j]==1)
         {
            s++;
            a[i][j]=s;
            b[s][0]=i;
            b[s][1]=j;
         }
   calc_dist();
   calc_w();
   calc_opt();
}
int sum;
void calc_dist()
{
   void bfs(int),count_dist();
   sum=0;
   for (int i=1;i<=dia;i++)
      bfs(i);
   count_dist();
}
int d[11][11];
void bfs(int t)
{
   const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
   int l,r;
   int q[200][3];
   bool f[20][20];
   memset(f,false,sizeof(f));
   f[b[t][0]][b[t][1]]=true;
   l=r=1;
   q[l][0]=b[t][0];
   q[l][1]=b[t][1];
   q[l][2]=0;
   d[t][0]=20000000;
   while (l<=r)
   {
      for (int i=0;i<4;i++)
      {
         int x,y;
         x=q[l][0]+c[i][0];
         y=q[l][1]+c[i][1];
         if (f[x][y] || map[x][y]==-1)
         {
            if (map[x][y]==-1 && q[l][2]<d[t][0])
               d[t][0]=q[l][2];
            continue;
         }
         r++;
         f[x][y]=true;
         q[r][0]=x;
         q[r][1]=y;
         q[r][2]=q[l][2]+1;
         if (map[x][y]==1)
            d[t][a[x][y]]=q[r][2];
      }
      l++;
   }
   d[t][t]=0;
   if (d[t][0]>sum)
      sum=d[t][0];
}
int dist[1100][11];
void count_dist()
{
   for (int i=1;i<=dia;i++)
      dist[0][i]=1;
   for (int i=1;i<=(1<<dia)-1;i++)
      for (int j=1;j<=dia;j++)
      {
         dist[i][j]=20000000;
         for (int k=1;k<=dia;k++)
            if (i>>k-1&1 && d[k][j]<dist[i][j])
               dist[i][j]=d[k][j];
      }
}
int w[1100];
void calc_w()
{
   int count_w(int);
   memset(w,-1,sizeof(w));
   w[0]=0;
   for (int i=1;i<=(1<<dia)-1;i++)
      count_w(i);
   for (int i=1;i<=(1<<dia)-1;i++)
   {
      int min;
      min=2000000;
      for (int j=1;j<=dia;j++)
         if (i>>j-1&1 && d[j][0]<min)
            min=d[j][0];
      w[i]+=min;
   }
}
int count_w(int t)
{
   if (w[t]!=-1)
      return(w[t]);
   w[t]=20000000;
   for (int i=1;i<=dia;i++)
      if (t>>i-1&1 && count_w(t-(1<<i-1))+dist[t-(1<<i-1)][i]<w[t])
         w[t]=count_w(t-(1<<i-1))+dist[t-(1<<i-1)][i];
   return(w[t]);
}
int opt[1100];
void calc_opt()
{
   int count_opt(int);
   memset(opt,-1,sizeof(opt));
   opt[0]=0;
   for (int i=1;i<=(1<<dia)-1;i++)
      count_opt(i);
}
int k;
int count_opt(int t)
{
   void get_opt(int,int);
   if (opt[t]!=-1)
      return(opt[t]);
   opt[t]=20000000;
   k=0;
   get_opt(1,t);
   return(opt[t]);
}
void get_opt(int dep,int t)
{
   if (dep==dia+1)
   {
      if (count_opt(t-k)+w[k]<opt[t])
         opt[t]=count_opt(t-k)+w[k];
      return;
   }
   if (t>>dep-1&1)
   {
      k+=1<<dep-1;
      get_opt(dep+1,t);
      k-=1<<dep-1;
   }
   get_opt(dep+1,t);
}
int tot,begin[200][2];
void find()
{
   const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
   tot=0;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
         if (map[i][j]!=-1)
         {
            bool flag;
            flag=false;
            for (int k=0;k<4;k++)
               if (map[i+c[k][0]][j+c[k][1]]==-1)
               {
                  flag=true;
                  break;
               }
            if (flag)
            {
               tot++;
               begin[tot][0]=i;
               begin[tot][1]=j;
            }
         }
}
int ans,finish;
bool f[20][20];
void astar()
{
   void search(int,int,int,int,int);
   const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
   finish=(1<<dia)-1;
   ans=w[finish]+1;
   memset(f,false,sizeof(f));
   for (int i=1;i<=tot;i++)
   {
      int x,y;
      x=begin[i][0];
      y=begin[i][1];
      f[x][y]=true;
      if (map[x][y]==0)
         search(x,y,1,0,i);
      else
         search(x,y,1,1<<a[x][y]-1,i);
      f[x][y]=false;
   }
   printf("%d\n",ans);
}
void search(int x,int y,int dep,int t,int k)
{
   if (opt[finish-t]+dep>=ans+sum)
      return;
   if (t==finish)
   {
      if (dep<ans)
         ans=dep;
      return;
   }
   if (map[x][y]==1)
      for (int i=k+1;i<=tot;i++)
      {
         int x0,y0;
         x0=begin[i][0];
         y0=begin[i][1];
         if (f[x0][y0])
            continue;
         f[x0][y0]=true;
         if (map[x0][y0]==0)
            search(x0,y0,dep+1,t,i);
         else
            search(x0,y0,dep+1,t+(1<<a[x0][y0]-1),i);
         f[x0][y0]=false;
      }
   const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
   for (int i=0;i<4;i++)
   {
      int x0,y0;
      x0=x+c[i][0];
      y0=y+c[i][1];
      if (f[x0][y0] || map[x0][y0]==-1)
         continue;
      f[x0][y0]=true;
      if (map[x0][y0]==0)
         search(x0,y0,dep+1,t,i);
      else
         search(x0,y0,dep+1,t+(1<<a[x0][y0]-1),i);
      f[x0][y0]=false;
   }
}
