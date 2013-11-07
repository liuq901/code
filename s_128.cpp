#include <cstdio>
#include <cstdlib>
struct tree
{
   int l,r,x;
};
tree a[70000];
int max=0,x[10001],y[10001],p[10001],v[10001][3];
bool w[10001][2];
int main()
{
   void fail(),sort(int,int,int *,int *),build(int,int,int),insert(int,int),del(int,int);
   bool check(int),get(int,int,int);
   int n;
   scanf("%d",&n);
   if (n&1)
      fail();
   for (int i=1;i<=n;i++)
   {
      scanf("%d%d",&x[i],&y[i]);
      x[i]+=10000,y[i]+=10000;
      p[i]=i;
   }
   sort(1,n,x,y);
   int ans=0,tot=0;
   for (int i=1;i<=n;i+=2)
   {
      if (x[i]!=x[i+1])
         fail();
      ans+=y[i+1]-y[i];
      v[++tot][0]=p[i];
      v[tot][1]=p[i+1];
      v[tot][2]=1;
   }
   sort(1,n,y,x);
   for (int i=1;i<=n;i+=2)
   {
      if (y[i]!=y[i+1])
         fail();
      ans+=x[i+1]-x[i];
      v[++tot][0]=p[i];
      v[tot][1]=p[i+1];
      v[tot][2]=0;
   }
   if (!check(n))
      fail();
   sort(1,n,x,y);
   build(1,0,20000);
   int l=1;
   for (int i=1;i<=n;i++)
   {
      if (i!=n && x[i]==x[i+1])
         continue;
      for (int j=l;j<=i;j++)
         if (w[p[j]][0])
            del(1,y[j]);
      for (int j=l;j<=i;j++)
         if (w[p[j]][1] && get(1,y[j-1],y[j]))
            fail();
      for (int j=l;j<=i;j++)
         if (!w[p[j]][0])
            insert(1,y[j]);
      l=i+1;
   } 
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void fail()
{
   printf("0\n");
   system("pause");
   exit(0);
}
void sort(int l,int r,int *a,int *b)
{
   int i,j,x,y,t;
   i=l,j=r;
   x=a[l+r>>1];
   y=b[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x || a[i]==x && b[i]<y)
         i++;
      while (a[j]>x || a[j]==x && b[j]>y)
         j--;
      if (i<=j)
      {
         t=a[i],a[i]=a[j],a[j]=t;
         t=b[i],b[i]=b[j],b[j]=t;
         t=p[i],p[i]=p[j],p[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,a,b);
   if (l<j)
      sort(l,j,a,b);
}
void build(int x,int l,int r)
{
   a[x].l=l,a[x].r=r;
   if (x>max)
      max=x;
   if (l==r)
      return;
   int mid=l+r>>1;
   build(2*x,l,mid);
   build(2*x+1,mid+1,r);
}
void insert(int x,int pos)
{
   if (a[x].l==a[x].r)
   {
      a[x].x++;
      return;
   }
   int mid=a[x].l+a[x].r>>1;
   if (pos<=mid)
      insert(2*x,pos);
   else
      insert(2*x+1,pos);
   a[x].x=a[2*x].x+a[2*x+1].x;
}
void del(int x,int pos)
{
   if (a[x].l==a[x].r)
   {
      a[x].x--;
      return;
   }
   int mid=a[x].l+a[x].r>>1;
   if (pos<=mid)
      del(2*x,pos);
   else
      del(2*x+1,pos);
   a[x].x=a[2*x].x+a[2*x+1].x;
}
int f[10001];
bool check(int n)
{
   int get(int);
   for (int i=1;i<=n;i++)
      f[i]=i;
   for (int i=1;i<=n;i++)
   {
      int x=v[i][0],y=v[i][1];
      w[x][v[i][2]]=false;
      w[y][v[i][2]]=true;
      f[get(y)]=get(x);
   }
   int p=get(1);
   for (int i=2;i<=n;i++)
      if (get(i)!=p)
         return(false);
   return(true);
}
int get(int x)
{
   if (x!=f[x])
      f[x]=get(f[x]);
   return(f[x]);
}
bool get(int x,int left,int right)
{
   if (a[x].l==left && a[x].r==right)
      return(a[x].x>0);
   int mid=a[x].l+a[x].r>>1;
   if (right<=mid)
      return(get(2*x,left,right));
   if (left>=mid+1)
      return(get(2*x+1,left,right));
   return(get(2*x,left,mid) || get(2*x+1,mid+1,right));
}
