#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
struct data
{
   int x,l,r,left,right;
};
struct data tree[20000];
int sum,c[10001],d[10001],b[10001],r[10001],s[10001],g[10001],father[10001],heavy[10001];
int w[10001],len[10001],l[20000],e[20000],a[20000][4],h[10001][7],f[16][20000][2];
int main()
{
   void work();
   int i,t;
   scanf("%d",&t);
   for (i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void work()
{
   void init(int),build(),floodfill(int),change(int,int);
   int lca(int,int),find(int,int);
   int n,m,x,y,z,i,j,t,ans;
   char order[10];
   scanf("%d",&n);
   init(n);
   build();
   e[0]=e[1]=1;
   memset(g,0,sizeof(g));
   g[1]=1;
   l[1]=0;
   floodfill(1);
   memset(g,0,sizeof(g));
   for (i=1;i<=e[0];i++)
      l[i]=d[e[i]];
   for (i=1;i<=e[0];i++)
   {
      if (g[e[i]])
         continue;
      g[e[i]]=1;
      r[e[i]]=i;
   }
   m=(int)(log(e[0])/log(2)+0.00001);
   memset(f,26,sizeof(f));
   for (i=1;i<=e[0];i++)
   {
      f[0][i][0]=l[i];
      f[0][i][1]=e[i];
   }
   t=1;
   for (i=1;i<=m;i++)
   {
      for (j=1;j<=e[0];j++)
      {
         if (j+t>e[0])
            break;
         if (f[i-1][j][0]<f[i][j][0])
         {
            f[i][j][0]=f[i-1][j][0];
            f[i][j][1]=f[i-1][j][1];
         }
         if (f[i-1][j+t][0]<f[i][j][0])
         {
            f[i][j][0]=f[i-1][j+t][0];
            f[i][j][1]=f[i-1][j+t][1];
         }
      }
      t*=2;
   }
   while (1)
   {
      scanf("%s",order);
      if (order[0]=='D')
         break;
      scanf("%d%d%*c",&x,&y);
      if (order[0]=='C')
         change(x,y);
      else
      {
         ans=-2147483647;
         if (x!=y)
         {
            z=lca(x,y);
            t=find(x,z);
            if (t>ans)
               ans=t;
            t=find(y,z);
            if (t>ans)
               ans=t;
         }
         printf("%d\n",ans);
      }
   }
}
void init(int n)
{
   void dfs(int,int);
   int i,t,x,y,z;
   int p[10000][3];
   memset(b,0,sizeof(b));
   for (i=1;i<=n-1;i++)
   {
      scanf("%d%d%d",&x,&y,&z);
      a[2*i-1][0]=y;
      a[2*i-1][1]=b[x];
      b[x]=2*i-1;
      a[2*i][0]=x;
      a[2*i][1]=b[y];
      b[y]=2*i;
      p[i][0]=x;
      p[i][1]=y;
      p[i][2]=z;
   }
   c[0]=0;
   dfs(1,0);
   memset(b,0,sizeof(b));
   for (i=1;i<=n-1;i++)
   {
      if (c[p[i][0]]>c[p[i][1]])
         t=p[i][0],p[i][0]=p[i][1],p[i][1]=t;
      x=p[i][0];
      y=p[i][1];
      z=p[i][2];
      father[y]=x;
      w[y]=z;
      a[i][0]=y;
      a[i][1]=z;
      a[i][2]=b[x];
      a[i][3]=0;
      b[x]=i;
   }
}
void dfs(int x,int father)
{
   int i;
   i=b[x];
   c[x]=c[father]+1;
   while (i!=0)
   {
      if (a[i][0]!=father)
         dfs(a[i][0],x);
      i=a[i][1];
   }
}
void build()
{
   int count(int);
   void calc(int),search(int,int,int),make(int);
   int i;
   count(1);
   calc(1);
   sum=1;
   h[1][2]=1;
   search(1,1,1);
   len[0]=0;
   for (i=1;i<=sum;i++)
      make(i);
}
int count(int x)
{
   int i,t;
   s[x]=1;
   i=b[x];
   while (i!=0)
   {
      t=count(a[i][0]);
      s[x]+=t;
      i=a[i][2];
   }
   return(s[x]);
}
void calc(int x)
{
   int i,max,k;
   k=-1;
   max=0;
   i=b[x];
   while (i!=0)
   {
      heavy[a[i][0]]=0;
      if (s[a[i][0]]>max)
      {
         max=s[a[i][0]];
         k=i;
      }
      calc(a[i][0]);
      i=a[i][2];
   }
   if (k!=-1)
   {
      a[k][3]=1;
      heavy[a[k][0]]=1;
   }
}
void search(int x,int t,int p)
{
   int i;
   i=b[x];
   h[x][0]=t;
   h[x][1]=p;
   h[t][3]=x;
   h[x][4]=h[x][5]=0;
   while (i!=0)
   {
      if (a[i][3])
      {
         h[x][4]=a[i][0];
         h[x][5]=i;
         if (s[a[i][0]]!=1)
            search(a[i][0],t,p+1);
      }
      else if (s[a[i][0]]!=1)
      {
         sum++;
         h[sum][2]=a[i][0];
         search(a[i][0],sum,1);
      }
      i=a[i][2];
   }
}
void make(int t)
{
   void buildtree(int,int,int);
   int i,s;
   i=h[t][2];
   s=0;
   while (i!=h[t][3])
   {
      s++;
      len[s]=a[h[i][5]][1];
      i=a[h[i][5]][0];
   }
   s++;
   len[s]=a[h[i][5]][1];
   len[0]++;
   h[t][6]=len[0];
   buildtree(len[0],1,s);
}
void buildtree(int x,int l,int r)
{
   int mid;
   mid=(l+r)/2;
   tree[x].l=l;
   tree[x].r=r;
   if (l==r)
   {
      tree[x].x=len[l];
      return;
   }
   len[0]++;
   tree[x].left=len[0];
   buildtree(len[0],l,mid);
   len[0]++;
   tree[x].right=len[0];
   buildtree(len[0],mid+1,r);
   if (tree[tree[x].left].x>tree[tree[x].right].x)
      tree[x].x=tree[tree[x].left].x;
   else
      tree[x].x=tree[tree[x].right].x;
}
void floodfill(int x)
{
   int i;
   i=b[x];
   while (i!=0)
   {
      g[a[i][0]]=1;
      d[a[i][0]]=d[x]+1;
      e[0]++;
      e[e[0]]=a[i][0];
      floodfill(a[i][0]);
      e[0]++;
      e[e[0]]=x;
      i=a[i][2];
   }
}
void change(int x,int y)
{
   void insert(int,int,int);
   int t,p;
   if (!a[x][3])
   {
      a[x][1]=y;
      w[a[x][0]]=y;
      return;
   }
   t=h[h[father[a[x][0]]][0]][6];
   p=h[father[a[x][0]]][1];
   insert(t,p,y);
}
void insert(int x,int p,int t)
{
   int mid;
   if (tree[x].l==tree[x].r)
   {
      tree[x].x=t;
      return;
   }
   mid=(tree[x].l+tree[x].r)/2;
   if (p<=mid)
      insert(tree[x].left,p,t);
   else
      insert(tree[x].right,p,t);  
   if (tree[tree[x].left].x>tree[tree[x].right].x)
      tree[x].x=tree[tree[x].left].x;
   else
      tree[x].x=tree[tree[x].right].x;
}
int lca(int x,int y)
{
   int t,i;
   if (r[x]>r[y])
      t=x,x=y,y=t;
   t=(int)(log(r[y]-r[x])/log(2)+0.0001);
   if (f[t][r[x]][0]<f[t][r[y]-(1<<t)+1][0])
      return(f[t][r[x]][1]);
   else
      return(f[t][r[y]-(1<<t)+1][1]);      
}
int find(int x,int root)
{
   int get(int,int,int);
   int t,p,q,ans;
   ans=-2147483647;
   while (x!=root)
   {
      if (!heavy[x])
      {
         if (w[x]>ans)
            ans=w[x];
         x=father[x];
         continue;
      }
      p=h[father[x]][0];
      q=h[root][0];
      if (p==q)
      {
         t=get(h[p][6],h[root][1],h[father[x]][1]);
         if (t>ans)
            ans=t;
         break;
      }
      t=get(h[p][6],1,h[father[x]][1]);
      if (t>ans)
         ans=t;
      x=h[p][2];
   }
   return(ans);
}
int get(int x,int l,int r)
{
   int max(int,int);
   int mid;
   if (l==tree[x].l && r==tree[x].r)
      return(tree[x].x);
   mid=(tree[x].l+tree[x].r)/2;
   if (r<=mid)
      return(get(tree[x].left,l,r));
   if (l>mid)
      return(get(tree[x].right,l,r));
   return(max(get(tree[x].left,l,mid),get(tree[x].right,mid+1,r)));
}
int max(int x,int y)
{
   if (x>y)
      return(x);
   else
      return(y);
}
