#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
struct state
{
   int x,len;
   state(int _x,int _len):x(_x),len(_len){}
};
int h[1001];
bool operator <(state a,state b)
{
   return(a.len+h[a.x]>b.len+h[b.x]);
}
int n,start,end,b[1001],a[100001][3],e[100001][3];
int main()
{
   void add(int,int,int,int),dijkstra();
   int search(int);
   int m,k;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
   {
      scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
      add(i,e[i][1],e[i][0],e[i][2]);
   }
   scanf("%d%d%d",&start,&end,&k);
   if (start==end)
      k++;
   dijkstra();
   memset(b,0,sizeof(b));
   for (int i=1;i<=m;i++)
      add(i,e[i][0],e[i][1],e[i][2]);
   printf("%d\n",search(k));
   system("pause");
   return(0);
}
void add(int id,int x,int y,int v)
{
   a[id][0]=y,a[id][1]=v,a[id][2]=b[x],b[x]=id;
}
void dijkstra()
{
   bool flag[1001]={0};
   memset(h,26,sizeof(h));
   h[end]=0;
   for (int i=1;i<=n;i++)
   {
      int k=0;
      for (int j=1;j<=n;j++)
         if (!flag[j] && h[j]<h[k])
            k=j;
      flag[k]=true;
      for (int j=b[k];j;j=a[j][2])
      {
         int y=a[j][0];
         if (h[k]+a[j][1]<h[y])
            h[y]=h[k]+a[j][1];
      }
   }
}
int search(int k)
{
   if (h[start]>400000000)
      return(-1);
   int c[1001]={0};
   priority_queue <state> p;
   p.push(state(start,0));
   while (!p.empty())
   {
      int x=p.top().x,len=p.top().len;
      p.pop();
      c[x]++;
      if (c[end]==k)
         return(len);
      if (c[x]>k)
         continue;
      for (int i=b[x];i;i=a[i][2])
         p.push(state(a[i][0],len+a[i][1]));
   }
   return(-1);
}
