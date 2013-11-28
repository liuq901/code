#include <cstdio>
#include <cstdlib>
#include <cstring>
struct data
{
   int x,l,r,left,right;
};
struct data tree[200000];
int sum,b[100001],s[100001],f[100001],father[100001];
int q[100000][2],g[100001][2],h[100001][3],a[200000][3];
int main()
{
   void floodfill(int,int),build(),change(int);
   int find(int);
   int n,p,i,x,y,t;
   scanf("%d%d",&n,&p);
   memset(b,0,sizeof(b));
   for (i=1;i<=n-1;i++)
   {
      scanf("%d%d",&x,&y);
      a[2*i-1][0]=y;
      a[2*i-1][1]=b[x];
      b[x]=2*i-1;
      a[2*i][0]=x;
      a[2*i][1]=b[y];
      b[y]=2*i;
      q[i][0]=x;
      q[i][1]=y;
   }
   f[0]=0;
   floodfill(1,0);
   memset(b,0,sizeof(b));
   for (i=1;i<=n-1;i++)
   {
      x=q[i][0];
      y=q[i][1];
      if (f[x]>f[y])
         t=x,x=y,y=t;
      a[i][0]=y;
      a[i][1]=b[x];
      a[i][2]=0;
      b[x]=i;
      father[y]=x;
   }
   father[1]=0;
   build();
   for (i=1;i<=p;i++)
   {
      scanf("%d%d",&x,&y);
      if (!x)
         change(y);
      else
         printf("%d\n",find(y));
   }
   system("pause");
   return(0);
}
void floodfill(int x,int father)
{
   int i;
   f[x]=f[father]+1;
   i=b[x];
   while (i!=0)
   {
      if (a[i][0]!=father)
         floodfill(a[i][0],x);
      i=a[i][1];
   }
}
void build()
{
   int count(int);
   void calc(int),search(int,int,int),make(int);
   int i,s;
   count(1);
   calc(1);
   sum=1;
   g[1][0]=1;
   search(1,1,1);
   s=sum;
   sum=0;
   for (i=1;i<=s;i++)
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
      i=a[i][1];
   }
   return(s[x]);
}
void calc(int x)
{
   int i,max,k;
   max=0;
   k=-1;
   i=b[x];
   while (i!=0)
   {
      if (s[a[i][0]]>max)
      {
         max=s[a[i][0]];
         k=i;
      }
      calc(a[i][0]);
      i=a[i][1];
   }
   if (k!=-1)
      a[k][2]=1;
}
void search(int x,int t,int p)
{
   int i;
   i=b[x];
   h[x][0]=t;
   h[x][1]=p;
   while (i!=0)
   {
      if (a[i][2])
      {
         h[x][2]=i;
         search(a[i][0],t,p+1);
      }
      else
      {
         sum++;
         g[sum][0]=a[i][0];
         search(a[i][0],sum,1);
      }
      i=a[i][1];
   }
}
void make(int t)
{
   void buildtree(int,int,int);
   int i,len;
   i=g[t][0];
   len=0;
   while (s[i]!=1)
   {
      len++;
      i=a[h[i][2]][0];
   }
   len++;
   sum++;
   g[t][1]=sum;
   buildtree(sum,1,len);
}
void buildtree(int x,int l,int r)
{
   int mid;
   tree[x].l=l;
   tree[x].r=r;
   tree[x].x=-1;
   if (l==r)
      return;
   mid=(l+r)/2;
   sum++;
   tree[x].left=sum;
   buildtree(sum,l,mid);
   sum++;
   tree[x].right=sum;
   buildtree(sum,mid+1,r);
}
void change(int t)
{
   void insert(int,int,int);
   int x,p;
   x=g[h[t][0]][1];
   p=h[t][1];
   insert(x,p,t);
}
void insert(int x,int p,int t)
{
   int mid;
   if (tree[x].l==tree[x].r)
   {
      if (tree[x].x==-1)
         tree[x].x=t;
      else
         tree[x].x=-1;
      return;
   }
   mid=(tree[x].l+tree[x].r)/2;
   if (p<=mid)
      insert(tree[x].left,p,t);
   else
      insert(tree[x].right,p,t);
   if (tree[tree[x].left].x!=-1)
      tree[x].x=tree[tree[x].left].x;
   else
      tree[x].x=tree[tree[x].right].x;
}
int find(int x)
{
   int get(int,int,int);
   int ans,t,p,q;
   ans=-1;
   while (x!=0)
   {
      p=g[h[x][0]][0];
      q=g[h[x][0]][1];
      t=get(q,1,h[x][1]);
      if (t!=-1)
         ans=t;
      x=father[p];
   }
   return(ans);
}
int get(int x,int l,int r)
{
   int choose(int,int);
   int mid;
   if (tree[x].l==l && tree[x].r==r)
      return(tree[x].x);
   mid=(tree[x].l+tree[x].r)/2;
   if (r<=mid)
      return(get(tree[x].left,l,r));
   if (l>mid)
      return(get(tree[x].right,l,r));
   return(choose(get(tree[x].left,l,mid),get(tree[x].right,mid+1,r)));
}
int choose(int x,int y)
{
   if (x!=-1)
      return(x);
   else
      return(y);
}
