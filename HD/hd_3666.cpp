#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,tot,c[401][401];
int b[801],a[400001][2];
double len[400001];
int main()
{
   void add(int,int,double);
   bool spfa();
   double l,u;
   while (scanf("%d%d%lf%lf",&n,&m,&l,&u)!=EOF)
   {
      memset(b,0,sizeof(b));
      tot=0;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            scanf("%d",&c[i][j]);
            add(j+n,i,log(u/c[i][j]));
            add(i,j+n,-log(l/c[i][j]));
         }
      printf("%s\n",spfa()?"YES":"NO");
   }
   system("pause");
   return(0);
}
void add(int x,int y,double cost)
{
   a[++tot][0]=y,a[tot][1]=b[x],len[tot]=cost,b[x]=tot;
}
int q[810],visit[810];
double d[810];
bool flag[810];
bool spfa()
{
   memset(visit,0,sizeof(visit));
   memset(flag,0,sizeof(flag));
   int l,r;
   for (int i=1;i<=n+m;i++)
      d[i]=1e100;
   l=0,r=1,q[1]=1,d[1]=0;
   flag[1]=true;
   while (l!=r)
   {
      l++;
      if (l>805)
         l=1;
      int x=q[l];
      for (int i=b[x];i;i=a[i][1])
      {
         int y=a[i][0];
         if (d[x]+len[i]<d[y])
         {
            d[y]=d[x]+len[i];
            visit[y]++;
            if (visit[y]>n+m)
               return(false);
            if (!flag[y])
            {
               flag[y]=true;
               r++;
               if (r>805)
                  r=1;
               q[r]=y;
            }
         }
      }
      flag[x]=false;
   }
}
