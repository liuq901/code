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
int h[5001];
bool operator <(state a,state b)
{
   return(a.len+h[a.x]>b.len+h[b.x]);
}
int n,b[5001],a[200001][3];
int main()
{
   void add(int,int,int,int),dijkstra();
   int search(int);
   int m,k;
   scanf("%d%d",&n,&m);
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      add(i,x,y,z);
      add(i+m,y,x,z);
   }
   dijkstra();
   printf("%d\n",search(2));
   system("pause");
   return(0);
}
void add(int id,int x,int y,int v)
{
   a[id][0]=y,a[id][1]=v,a[id][2]=b[x],b[x]=id;
}
void dijkstra()
{
   bool flag[5001]={0};
   memset(h,26,sizeof(h));
   h[n]=0;
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
   int c[5001]={0};
   priority_queue <state> p;
   p.push(state(1,0));
   while (!p.empty())
   {
      int x=p.top().x,len=p.top().len;
      p.pop();
      c[x]++;
      if (c[n]==k)
         return(len);
      if (c[x]>k)
         continue;
      for (int i=b[x];i;i=a[i][2])
         p.push(state(a[i][0],len+a[i][1]));
   }
}
