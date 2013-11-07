#include <cstdio>
#include <cstdlib>
#include <cstring>
const int dr[5][3]={{0},{0,1,0},{0,0,-1},{0,0,1},{0,-1,0}};
char e[101][101];
int ans,nx,ny,t1,t2,a,b,xx,yy,m,n;
int p[16][3],s[40001][4],d[101][101][5];
int f[40000][16][5],l[16][5][16][5];
int main()
{
   void search(int,int);
   int i,j,k,t,r;
   scanf("%d%d%d%*c",&n,&m,&t);
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=m;j++)
         scanf("%c",&e[i][j]);
      scanf("%*c");
   }
   for (i=1;i<=t;i++)
      scanf("%d%d",&p[i][1],&p[i][2]);
   scanf("%d%d",&xx,&yy);
   memset(l,-1,sizeof(l));
   for (i=1;i<=t;i++)
      for (j=1;j<=4;j++)
      {
         search(p[i][1]+dr[j][1],p[i][2]+dr[j][2]);
         for (a=1;a<=t;a++)
            for (b=1;b<=4;b++)
               l[i][j][a][b]=d[p[a][1]+dr[b][1]][p[a][2]+dr[b][2]][5-b];
      }
   search(xx,yy);
   memset(f,-1,sizeof(f));
   for (i=1;i<=t;i++)
      for (j=1;j<=4;j++)
         f[1<<(i-1)][i][j]=d[p[i][1]+dr[j][1]][p[i][2]+dr[j][2]][5-j];
   for (r=1;r<=(1<<t)-1;r++)
      for (i=1;i<=t;i++)
         for (j=1;j<=4;j++)
            if (f[r][i][j]!=-1)
               for (a=1;a<=t;a++)
                  if ((r>>((a-1)&1))==0)
                     for (b=1;b<=4;b++)
                        if (l[i][j][a][b]!=-1)
                           if (f[r+1<<(a-1)][a][b]==-1 || f[r][i][j]+l[i][j][a][b]<f[r+1<<(a-1)][a][b])
                              f[r+1<<(a-1)][a][b]=f[r][i][j]+l[i][j][a][b];
   ans=-1;
   for (i=1;i<=t;i++)
      for (j=1;j<=4;j++)
         if (f[1<<(t-1)][i][j]!=-1)
            if (ans==-1 || f[1<<(t-1)][i][j]<ans)
               ans=f[1<<(t-1)][i][j];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void search(int sx,int sy)
{
   int im(int,int);
   int i;
   memset(d,-1,sizeof(d));
   if (!im(sx,sy) || e[sx][sy]!='.')
      return;
   t1=0;
   t2=1;
   s[1][1]=sx;
   s[1][2]=sy;
   s[1][3]=0;
   d[sx][sy][0]=0;
   while (t1<t2)
   {
      t1++;
      for (i=1;i<=4;i++)
      {
         nx=s[t1][1];
         ny=s[t1][2];
         while (im(nx,ny) && e[nx][ny]=='.' && d[nx][ny][i]==-1)
         {
            d[nx][ny][i]=d[s[t1][1]][s[t1][2]][s[t1][3]]+1;
            t2++;
            s[t2][1]=nx;
            s[t2][2]=ny;
            s[t2][3]=i;
            nx+=dr[i][1];
            ny+=dr[i][2];
         }
      }
   }
}
int im(int x,int y)
{
   if (x<=0 || x>n || y<=0 || y>m)
      return(0);
   else
      return(1);
}
