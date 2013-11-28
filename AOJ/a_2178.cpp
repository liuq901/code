#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
const int C[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct point
{
   int x,y;
   point(){}
   point(int x,int y):x(x),y(y){}
};
bool operator <(point a,point b)
{
   return(a.x<b.x || a.x==b.x && a.y<b.y);
}
map <point,int> s1,s2;
point c[20010][2];
int n,tot,b[40010],dfn[40010],low[40010],pos[40010],S[40010],a[1000010][2];
bool f[40010];
int main()
{
   void add(int,int),tarjan(int);
   while (1)
   {
      scanf("%d",&n);
      if (!n)
         break;
      s1.clear();
      s2.clear();
      for (int i=1;i<=n;i++)
      {
         int x,y;
         char ch;
         scanf("%d %d %c",&x,&y,&ch);
         s1[point(x,y)]=i;
         c[i][0]=point(x,y);
         if (ch=='x')
            x++;
         else
            y++;
         s2[point(x,y)]=i+n;
         c[i][1]=point(x,y);
      }
      memset(b,0,sizeof(b));
      tot=0;
      for (int i=1;i<=n;i++)
      {
         int x0=c[i][0].x,y0=c[i][0].y;
         for (int j=0;j<4;j++)
         {
            int x=x0+C[j][0],y=y0+C[j][1];
            if (s1.count(point(x,y)))
            {
               add(i,s1[point(x,y)]);
               add(s1[point(x,y)]+n,i+n);
            }
            if (s2.count(point(x,y)))
            {
               add(i,s2[point(x,y)]);
               add(s2[point(x,y)]-n,i+n);
            }
         }
         x0=c[i][1].x,y0=c[i][1].y;
         for (int j=0;j<4;j++)
         {
            int x=x0+C[j][0],y=y0+C[j][1];
            if (s1.count(point(x,y)))
            {
               add(i+n,s1[point(x,y)]);
               add(s1[point(x,y)]+n,i);
            }
            if (s2.count(point(x,y)))
            {
               add(i+n,s2[point(x,y)]);
               add(s2[point(x,y)]-n,i);
            }
         }
      }
      memset(dfn,0,sizeof(dfn));
      memset(f,0,sizeof(f));
      tot=0;
      pos[0]=S[0]=0;
      for (int i=1;i<=n<<1;i++)
         if (!dfn[i])
            tarjan(i);
      bool flag=true;
      for (int i=1;i<=n;i++)
         if (pos[i]==pos[i+n])
         {
            flag=false;
            break;
         }
      printf("%s\n",flag?"Yes":"No");
   }
   system("pause");
   return(0);
}
void add(int x,int y)
{
   if (x==y+n || y==x+n)
      return;
   a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
void tarjan(int x)
{
   dfn[x]=low[x]=++tot;
   S[++S[0]]=x;
   f[x]=true;
   for (int i=b[x];i;i=a[i][1])
   {
      int y=a[i][0];
      if (!dfn[y])
      {
         tarjan(y);
         low[x]=min(low[x],low[y]);
      }
      else if (f[y])
         low[x]=min(low[x],dfn[y]);
   }
   if (dfn[x]==low[x])
   {
      pos[0]++;
      while (S[S[0]]!=x)
      {
         int p=S[S[0]--];
         pos[p]=pos[0];
         f[p]=false;
      }
      pos[x]=pos[0],f[x]=false,S[0]--;
   }
}
