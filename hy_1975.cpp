#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
struct state
{
   int x;
   double len;
   state(){}
   state(int _x,double _len):x(_x),len(_len){}
};
double h[5001];
bool operator <(state a,state b)
{
   return(a.len+h[a.x]>b.len+h[b.x]);
}
int n,b[5001],a[200001][2],e[200001][2];
double c[200001];
int main()
{
   void add(int,int,int),spfa();
   int search(double);
   int m;
   double p;
   scanf("%d%d%lf",&n,&m,&p);
   for (int i=1;i<=m;i++)
   {
      scanf("%d%d%lf",&e[i][0],&e[i][1],&c[i]);
      add(i,e[i][1],e[i][0]);
   }
   spfa();
   memset(b,0,sizeof(b));
   for (int i=1;i<=m;i++)
      add(i,e[i][0],e[i][1]);
   printf("%d\n",search(p));
   system("pause");
   return(0);
}
void add(int id,int x,int y)
{
   a[id][0]=y,a[id][1]=b[x],b[x]=id;
}
void spfa()
{
   bool f[5001]={0};
   int l,r,q[5001];
   l=0,r=1;
   f[n]=true;
   for (int i=1;i<=n;i++)
      h[i]=1e100;
   h[n]=0;
   q[1]=n;
   while (l!=r)
   {
      l=l==n?1:l+1;
      int x=q[l];
      for (int i=b[x];i;i=a[i][1])
      {
         int y=a[i][0];
         if (h[x]+c[i]<h[y])
         {
            h[y]=h[x]+c[i];
            if (!f[y])
            {
               f[y]=true;
               r=r==n?1:r+1;
               q[r]=y;
            }
         }
      }
      f[x]=false;
   }
}
int search(double limit)
{
   priority_queue <state> p;
   int f[5001]={0};
   p.push(state(1,0));
   double sum=0;
   int k=1;
   while (!p.empty())
   {
      int x=p.top().x;
      double len=p.top().len;
      p.pop();
      f[x]++;
      if (x==n && f[n]==k)
      {
         sum+=len;
         if (sum>limit)
            return(k-1);
         else
            k++;
         continue;
      }
      for (int i=b[x];i;i=a[i][1])
         p.push(state(a[i][0],len+c[i]));
   }
}
