#include <cstdio>
#include <cstdlib>
#include <cstring>
struct tree
{
   int x,v,father,left,right;
};
struct tree heap[8000000];
int n,head,min,pos,sum,tot,num,com;
int f[200010],s[200010],b[200010],dep[200010],dist[200010],color[200010],ans[800000][2];
int len[200010][3],p[100010][2],e[200010][3],a[400010][4],g[800000][8],h[3][20][200010];
int main()
{
   void build(int),change(int);
   int m,i,x,y,z;
   char ch;
   memset(b,0,sizeof(b));
   scanf("%d",&n);
   for (i=1;i<=n-1;i++)
   {
      scanf("%d%d%d",&x,&y,&z);
      a[2*i-1][0]=y;
      a[2*i-1][1]=z;
      a[2*i-1][2]=b[x];
      b[x]=2*i-1;
      a[2*i][0]=x;
      a[2*i][1]=z;
      a[2*i][2]=b[y];
      b[y]=2*i;
   }
   build(n);
   scanf("%d%*c",&m);
   for (i=1;i<=m;i++)
   {
      scanf("%c",&ch);
      if (ch=='C')
      {
         scanf("%d",&x);
         change(x);
      }
      else if (color[0]==0)
         printf("They have disappeared.\n");
      else
         printf("%d\n",ans[1][0]);
      scanf("%*c");
   }
   system("pause");
   return(0);
}
void build(int n)
{
   void turn(int),cut(int,int,int),buildheap(int),getans();
   int i;
   turn(n);
   num=0;
   h[0][0][0]=0;
   cut(1,sum,1);
   head=0;
   for (i=1;i<=num;i++)
      buildheap(i);
   memset(color,0,sizeof(color));
   color[0]=n;
   getans();
}
void turn(int n)
{
   int count(int,int);
   void buildtree(int,int),addedge();
   sum=n;
   memset(f,0,sizeof(f));
   count(1,0);
   tot=0;
   buildtree(1,0);
   addedge();
}
int count(int x,int father)
{
   int i;
   i=b[x];
   s[x]=1;
   while (i!=0)
   {
      if (a[i][0]!=father)
         s[x]+=count(a[i][0],x);
      i=a[i][2];
   }
   return(s[x]);
}
void buildtree(int x,int father)
{
   void addpoint(int,int,int);
   int i,z;
   if (s[x]==1)
      return;
   i=b[x];
   z=0;
   while (i!=0)
   {
      if (a[i][0]!=father)
      {                     
         z++;
         p[z][0]=a[i][0];
         p[z][1]=a[i][1];
      }
      i=a[i][2];
   }
   addpoint(x,1,z);
   i=b[x];
   while (i!=0)
   {
      if (a[i][0]!=father)
         buildtree(a[i][0],x);
      i=a[i][2];
   }
}
void addpoint(int x,int l,int r)
{
   int mid;
   if (l==r)
   {
      tot++;
      e[tot][0]=x;
      e[tot][1]=p[l][0];
      e[tot][2]=p[l][1];
      return;
   }
   mid=(l+r)/2;
   if (l==mid)
   {
      tot++;
      e[tot][0]=x;
      e[tot][1]=p[l][0];
      e[tot][2]=p[l][1];
   }
   else
   {
      sum++;
      tot++;
      e[tot][0]=x;
      e[tot][1]=sum;
      e[tot][2]=0;
      addpoint(sum,l,mid);
   }
   if (mid+1==r)
   {
      tot++;
      e[tot][0]=x;
      e[tot][1]=p[r][0];
      e[tot][2]=p[r][1];
   }
   else
   {
      sum++;
      tot++;
      e[tot][0]=x;
      e[tot][1]=sum;
      e[tot][2]=0;
      addpoint(sum,mid+1,r);
   }
}
void addedge()
{
   int i,x,y,z;
   memset(b,0,sizeof(b));
   for (i=1;i<=tot;i++)
   {
      x=e[i][0];
      y=e[i][1];
      z=e[i][2];
      a[2*i-1][0]=y;
      a[2*i-1][1]=z;
      a[2*i-1][2]=b[x];
      a[2*i-1][3]=x;
      b[x]=2*i-1;
      a[2*i][0]=x;
      a[2*i][1]=z;
      a[2*i][2]=b[y];
      a[2*i][3]=y;
      b[y]=2*i;
   }
}
void cut(int x,int sum,int time)
{
   void calc(int,int,int,int);
   int p,q,t;
   min=20000000;
   pos=-1;
   dep[0]=0;   
   num++;
   if (time>h[0][0][0])
      h[0][0][0]=time;
   calc(x,0,sum,time);
   g[num][0]=pos;
   g[num][1]=x;
   g[num][2]=time;
   if (pos==-1)
      return;
   p=a[pos][0];
   q=a[pos][3];
   if (dep[p]<dep[q])
   {
      t=s[q];
      f[p]=1;
      cut(q,t,time+1);
      f[p]=0;
      f[q]=1;
      cut(p,sum-t,time+1);
      f[q]=0;
   }
   else
   {
      t=s[p];
      f[q]=1;
      cut(p,t,time+1);
      f[q]=0;
      f[p]=1;
      cut(q,sum-t,time+1);
      f[p]=0;
   }
}
void calc(int x,int father,int sum,int time)
{
   int i,t;
   h[0][time][x]=num;
   s[x]=1;
   i=b[x];
   dep[x]=dep[father]+1;
   while (i!=0)
   {
      if (!f[a[i][0]] && a[i][0]!=father)
      {
         calc(a[i][0],x,sum,time);
         t=s[a[i][0]];
         if (abs(sum-2*t)<min)
         {
            min=abs(sum-2*t);
            pos=i;
         }
         s[x]+=t;
      }
      i=a[i][2];
   }
}
void buildheap(int t)
{
   void add(int,int,int,int,int),makeheap(int);
   int p,q,time;
   if (g[t][0]==-1)
      return;
   p=a[g[t][0]][0];
   q=a[g[t][0]][3];
   time=g[t][2];
   com=0;
   g[t][3]=head+1;
   add(p,q,time,h[0][time+1][p],0);
   g[h[0][time+1][p]][6]=head+1;
   makeheap(time+1);
   g[h[0][time+1][p]][7]=head;
   com=0;
   g[t][4]=head+1;
   g[h[0][time+1][q]][6]=head+1;
   add(q,p,time,h[0][time+1][q],0);
   makeheap(time+1);
   g[h[0][time+1][q]][7]=head;
}
void add(int x,int father,int time,int flag,int value)
{
   int i;
   com++;
   if (x<=n)
      len[com][0]=value;
   else
      len[com][0]=-10000000;
   len[com][1]=x;
   i=b[x];
   while (i!=0)
   {
      if (a[i][0]!=father && h[0][time+1][a[i][0]]==flag)
         add(a[i][0],x,time,flag,value+a[i][1]);
      i=a[i][2];
   }
}
void makeheap(int time)
{
   void down(int,int);
   int i;
   for (i=com/2;i>=1;i--)
      down(i,com);
   for (i=1;i<=com;i++)
   {
      heap[head+i].v=len[i][0];
      heap[head+i].x=len[i][1];
      h[1][time][len[i][1]]=head+i;
      h[2][time][len[i][1]]=len[i][0];
      if (2*i<=com)
         heap[head+i].left=head+2*i;
      else
         heap[head+i].left=0;
      if (2*i+1<=com)
         heap[head+i].right=head+2*i+1;
      else
         heap[head+i].right=0;
      if (i/2!=0)
         heap[head+i].father=head+i/2;
      else
         heap[head+i].father=0;
   }
   head+=com;
}
void down(int x,int n)
{
   int p,q,t;
   if (2*x>n && 2*x+1>n)
      return;
   if (2*x+1>n)
   {
      p=len[2*x][0];
      q=-1000000;
   }
   else
   {
      p=len[2*x][0];
      q=len[2*x+1][0];
   }
   if (len[x][0]>=p && len[x][0]>=q)
      return;
   if (p>q)
   {
      t=len[x][0],len[x][0]=len[2*x][0],len[2*x][0]=t;
      t=len[x][1],len[x][1]=len[2*x][1],len[2*x][1]=t;
      down(2*x,n);
   }
   else
   {
      t=len[x][0],len[x][0]=len[2*x+1][0],len[2*x+1][0]=t;
      t=len[x][1],len[x][1]=len[2*x+1][1],len[2*x+1][1]=t;
      down(2*x+1,n);
   }
}
void getans()
{
   void ansdown(int);
   int i,t,p,q,r;
   for (i=1;i<=num;i++)
   {
      g[i][5]=i;
      ans[i][1]=i;
      if (g[i][0]==-1)
         ans[i][0]=0;
      else
      {
         t=g[i][0];
         p=g[i][3];
         q=g[i][4];
         if (heap[p].x<=n && heap[q].x<=n)
            ans[i][0]=heap[p].v+heap[q].v+a[t][1];
         else
            ans[i][0]=-10000000;
      }
   }
   for (i=num/2;i>=1;i--)
      ansdown(i);
}
void ansdown(int x)
{
   int p,q,t;
   if (2*x>num)
      return;
   p=ans[2*x][0];
   if (2*x+1<=num)
      q=ans[2*x+1][0];
   else
      q=-10000000;
   if (ans[x][0]>=p && ans[x][0]>=q)
      return;
   if (p>q)
   {
      t=ans[x][0],ans[x][0]=ans[2*x][0],ans[2*x][0]=t;
      t=ans[x][1],ans[x][1]=ans[2*x][1],ans[2*x][1]=t;
      g[ans[x][1]][5]=x;
      g[ans[2*x][1]][5]=2*x;
      ansdown(2*x);
   }
   else
   {
      t=ans[x][0],ans[x][0]=ans[2*x+1][0],ans[2*x+1][0]=t;
      t=ans[x][1],ans[x][1]=ans[2*x+1][1],ans[2*x+1][1]=t;
      g[ans[x][1]][5]=x;
      g[ans[2*x+1][1]][5]=2*x+1;
      ansdown(2*x+1);
   }
}
void change(int x)
{
   void del(int,int,int),insert(int,int,int,int),update(int);
   int i,t,p,q,tmp;
   if (!color[x])
   {
      color[x]=1;
      color[0]--;
      for (i=2;i<=h[0][0][0];i++)
      {
         t=h[0][i][x];
         del(h[1][i][x],g[t][7],i);
         g[h[0][i][x]][7]--;
         if (g[t][0]==-1)
            break;
      }
   }
   else
   {
      color[x]=0;
      color[0]++;
      for (i=2;i<=h[0][0][0];i++)
      {
         t=h[0][i][x];
         insert(h[1][i][x],g[t][7],h[2][i][x],i);
         g[h[0][i][x]][7]++;
         if (g[t][0]==-1)
            break;
      }
   }
   for (i=1;i<=h[0][0][0];i++)
   {
      t=h[0][i][x];
      if (g[t][0]==-1)
         break;
      p=g[t][3];
      q=g[t][4];
      if (heap[p].x<=n && heap[q].x<=n)
         tmp=heap[p].v+heap[q].v+a[g[t][0]][1];
      else
         tmp=-100000000;
      ans[g[t][5]][0]=tmp;
      update(g[t][5]);
   }
}
void del(int x,int tail,int p)
{
   void maintain(int,int,int);
   int t;
   if (heap[x].father==0 && x==tail)
   {
      heap[x].v=-1000000000;
      return;
   }
   t=heap[x].x,heap[x].x=heap[tail].x,heap[tail].x=t;
   t=heap[x].v,heap[x].v=heap[tail].v,heap[tail].v=t;
   h[1][p][heap[x].x]=x;
   h[1][p][heap[tail].x]=tail;
   maintain(x,p,tail-1);
}
void insert(int x,int tail,int value,int p)
{
   void maintain(int,int,int);
   int t;
   t=heap[x].x,heap[x].x=heap[tail+1].x,heap[tail+1].x=t;
   heap[x].v=heap[tail+1].v;
   heap[tail+1].v=value;
   h[1][p][heap[x].x]=x;
   h[1][p][heap[tail+1].x]=tail+1;
   maintain(tail+1,p,tail+1);
}
void maintain(int x,int time,int tail)
{
   int unfair(int,int);
   int t,p,q;
   if (heap[x].father!=0 && heap[x].v>heap[heap[x].father].v)
   {
      t=heap[x].v,heap[x].v=heap[heap[x].father].v,heap[heap[x].father].v=t;
      t=heap[x].x,heap[x].x=heap[heap[x].father].x,heap[heap[x].father].x=t;
      h[1][time][heap[x].x]=x;
      h[1][time][heap[heap[x].father].x]=heap[x].father;
      maintain(heap[x].father,time,tail);
      return;
   }
   if (unfair(heap[x].left,tail))
   {
      p=heap[heap[x].left].v;
      if (unfair(heap[x].right,tail))
         q=heap[heap[x].right].v;
      else
         q=-10000000;
      if (heap[x].v>=p && heap[x].v>=q)
         return;
      if (p>q)
      {
         t=heap[x].v,heap[x].v=heap[heap[x].left].v,heap[heap[x].left].v=t;
         t=heap[x].x,heap[x].x=heap[heap[x].left].x,heap[heap[x].left].x=t;
         h[1][time][heap[x].x]=x;
         h[1][time][heap[heap[x].left].x]=heap[x].left;
         maintain(heap[x].left,time,tail);
      }
      else
      {
         t=heap[x].v,heap[x].v=heap[heap[x].right].v,heap[heap[x].right].v=t;
         t=heap[x].x,heap[x].x=heap[heap[x].right].x,heap[heap[x].right].x=t;
         h[1][time][heap[x].x]=x;
         h[1][time][heap[heap[x].right].x]=heap[x].right;
         maintain(heap[x].right,time,tail);
      }
   }
}
int unfair(int x,int y)
{
   if (x==0)
      return(0);
   if (x>y)
      return(0);
   return(1);
}
void update(int x)
{
   int t,p,q;
   if (x/2!=0 && ans[x][0]>ans[x/2][0])
   {
      t=ans[x][0],ans[x][0]=ans[x/2][0],ans[x/2][0]=t;
      t=ans[x][1],ans[x][1]=ans[x/2][1],ans[x/2][1]=t;
      g[ans[x][1]][5]=x;
      g[ans[x/2][1]][5]=x/2;
      update(x/2);
      return;
   }
   if (2*x<=num)
   {
      p=ans[2*x][0];
      if (2*x+1<=num)
         q=ans[2*x+1][0];
      else
         q=-100000000;
      if (ans[x][0]>=p && ans[x][0]>=q)
         return;
      if (p>q)
      {
         t=ans[x][0],ans[x][0]=ans[2*x][0],ans[2*x][0]=t;
         t=ans[x][1],ans[x][1]=ans[2*x][1],ans[2*x][1]=t;
         g[ans[x][1]][5]=x;
         g[ans[2*x][1]][5]=2*x;
         update(2*x);
      }
      else
      {
         t=ans[x][0],ans[x][0]=ans[2*x+1][0],ans[2*x+1][0]=t;
         t=ans[x][1],ans[x][1]=ans[2*x+1][1],ans[2*x+1][1]=t;
         g[ans[x][1]][5]=x;
         g[ans[2*x+1][1]][5]=2*x+1;
         update(2*x+1);
      }
   }
}
