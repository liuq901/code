#include <cstdio>
#include <cstdlib>
const int inf=1<<30;
struct tree
{
   int l,r,x,y;
};
struct tree a[1000000];
int n,l[100001],r[100001],x[100001],h[100001];
int main()
{
   void sort(int,int),build(),make(int,int,int),insert(int,int,int),work(int,int,int,int);
   int min(int,int),find(int,int,int),count(int,int);
   int i,t;
   int f[100001],g[100001];
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d%d",&x[i],&h[i]);
   sort(1,n);
   build();
   make(1,1,n);
   f[1]=g[1]=1;
   work(1,2,r[1],g[1]);
   for (i=2;i<=n;i++)
   {
      f[i]=min(f[i-1],g[i-1])+1;
      if (l[i]<=i-1)
         t=find(1,l[i],i-1);
      else
         t=inf;
      if (t<f[i])
         f[i]=t;
      insert(1,i,f[i]);
      g[i]=min(f[i-1],g[i-1])+1;
      t=count(1,i);
      if (t<g[i])
         g[i]=t;
      work(1,i+1,r[i],g[i]);
   }
   printf("%d\n",min(f[n],g[n]));
   system("pause");
   return(0);
}
void sort(int l,int r)
{
   int i,j,p;
   i=l,j=r;
   p=x[l+r>>1];
   while (i<=j)
   {
      while (x[i]<p)
         i++;
      while (x[j]>p)
         j--;
      if (i<=j)
      {
         int t;
         t=x[i],x[i]=x[j],x[j]=t;
         t=h[i],h[i]=h[j],h[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void build()
{
   int i,t;
   l[1]=1;
   for (i=2;i<=n;i++)
   {
      if (x[i]-x[i-1]>h[i])
      {
         l[i]=i;
         continue;
      }
      l[i]=l[i-1];
      t=l[i]-1;
      while (1)
      {
         if (t==0)
            break;
         if (x[i]-x[t]>h[i])
            break;
         l[i]=l[t];
         t=l[i]-1;
      }
   }
   r[n]=n;
   for (i=n-1;i>=1;i--)
   {
      if (x[i+1]-x[i]>h[i])
      {
         r[i]=i;
         continue;
      }
      r[i]=r[i+1];
      t=r[i]+1;
      while (1)
      {
         if (t>n)
            break;
         if (x[t]-x[i]>h[i])
            break;
         r[i]=r[t];
         t=r[i]+1;
      }
   }
}
void make(int x,int l,int r)
{
   int mid;
   a[x].l=l;
   a[x].r=r;
   a[x].x=inf;
   a[x].y=inf;
   if (l==r)
      return;
   mid=(l+r)/2;
   make(2*x,l,mid);
   make(2*x+1,mid+1,r);
}
void insert(int x,int t,int p)
{
   int mid;
   if (p<a[x].x)
      a[x].x=p;
   if (a[x].l==a[x].r)
      return;
   mid=(a[x].l+a[x].r)/2;
   if (t<=mid)
      insert(2*x,t,p);
   else
      insert(2*x+1,t,p);
}
void work(int x,int l,int r,int p)
{
   int mid;
   if (l>r)
      return;
   if (p<a[x].y)
      a[x].y=p;
   if (a[x].l==a[x].r)
      return;
   mid=(a[x].l+a[x].r)/2;
   if (r<=mid)
   {
      work(2*x,l,r,p);
      return;
   }
   if (l>mid)
   {
      work(2*x+1,l,r,p);
      return;
   }
   work(2*x,l,mid,p);
   work(2*x+1,mid+1,r,p);
}
int find(int x,int l,int r)
{
   int min(int,int);
   int mid;
   mid=(a[x].l+a[x].r)/2;
   if (l==a[x].l && r==a[x].r)
      return(a[x].x);
   if (r<=mid)
      return(find(2*x,l,r));
   if (l>mid)
      return(find(2*x+1,l,r));
   return(min(find(2*x,l,mid),find(2*x+1,mid+1,r)));
}
int count(int x,int t)
{
   int mid;
   if (a[x].l==a[x].r)
      return(a[x].y);
   mid=(a[x].l+a[x].r)/2;
   if (t<=mid)
      return(count(2*x,t));
   else
      return(count(2*x+1,t));
}
int min(int x,int y)
{
   if (x<y)
      return(x);
   else
      return(y);
}
