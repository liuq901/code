#include <cstdio>
#include <cstdlib>
#include <cstdarg>
struct binary_tree
{
   int l,r,a,b,left_plus,left_minus,right_plus,right_minus,dis;
};
const int inf=200000000;
int n,b[100001],c[200001][2];
int main()
{
   void init(),build(),work();
   init();
   build();
   work();
   system("pause");
   return(0);
}
void init()
{
   scanf("%d",&n);
   for (int i=1;i<=n-1;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      c[2*i-1][0]=y;
      c[2*i-1][1]=b[x];
      b[x]=2*i-1;
      c[2*i][0]=x;
      c[2*i][1]=b[y];
      b[y]=2*i;
   }
}
int sum,p[300001];
void build()
{
   void floodfill(int,int),build_tree(int,int,int);
   floodfill(1,0);
   build_tree(1,1,sum);
}
void floodfill(int x,int father)
{
   int i=b[x];
   sum++;
   p[sum]=-1;
   sum++;
   p[sum]=x;
   while (i!=0)
   {
      if (c[i][0]!=father)
         floodfill(c[i][0],x);
      i=c[i][1];
   }
   sum++;
   p[sum]=0;
}
binary_tree a[1100000];
int f[100001];
void build_tree(int x,int l,int r)
{
   void update(int);
   a[x].l=l,a[x].r=r;
   if (l==r)
   {
      if (p[l]>0)
         a[x].dis=a[x].left_minus=a[x].left_plus=a[x].right_minus=a[x].right_plus=0;
      else
         a[x].dis=a[x].left_minus=a[x].left_plus=a[x].right_minus=a[x].right_plus=-inf;
      if (p[l]>0)
         a[x].a=a[x].b=0;
      else if (p[l]==0)
         a[x].a=1,a[x].b=0;
      else
         a[x].a=0,a[x].b=1;
      if (p[l]>0)
         f[p[l]]=l;
      return;
   }
   int mid=(l+r)/2;
   build_tree(2*x,l,mid);
   build_tree(2*x+1,mid+1,r);
   update(x);
}
bool color[100001];
void work()
{
   int print(int);
   void change(int,int,int);
   int m;
   scanf("%d%*c",&m);
   for (int i=1;i<=m;i++)
   {
      char ch;
      scanf("%c",&ch);
      if (ch=='G')
         printf("%d\n",print(a[1].dis));
      else
      {
         int x;
         scanf("%d",&x);
         change(1,f[x],x);
      }
      scanf("%*c");
   }
}
int print(int x)
{
   if (x<0)
      return(-1);
   else
      return(x);
}
void change(int x,int t,int p)
{
   void update(int);
   if (a[x].l==a[x].r)
   {
      color[p]=!color[p];
      if (color[p])
         a[x].dis=a[x].left_minus=a[x].left_plus=a[x].right_minus=a[x].right_plus=-inf;
      else
         a[x].dis=a[x].left_minus=a[x].left_plus=a[x].right_minus=a[x].right_plus=0;
      return;
   }
   int mid=(a[x].l+a[x].r)/2;
   if (t<=mid)
      change(2*x,t,p);
   else
      change(2*x+1,t,p);
   update(x);
}
void update(int x)
{
   int max(int,...);
   binary_tree &s=a[x],s1=a[2*x],s2=a[2*x+1];
   int a,b,c,d;
   a=s1.a,b=s1.b;
   c=s2.a,d=s2.b;
   if (b>=c)
   {
      s.a=a;
      s.b=b-c+d;
   }
   else
   {
      s.a=a-b+c;
      s.b=d;
   }
   s.dis=max(4,s1.right_plus+s2.left_minus,s1.right_minus+s2.left_plus,s1.dis,s2.dis);
   s.right_plus=max(3,s1.right_plus-c+d,s1.right_minus+c+d,s2.right_plus);
   s.right_minus=max(2,s1.right_minus+c-d,s2.right_minus);
   s.left_plus=max(3,s2.left_plus-b+a,s2.left_minus+b+a,s1.left_plus);
   s.left_minus=max(2,s2.left_minus+b-a,s1.left_minus);
}
int max(int s,...)
{
   va_list p;
   va_start(p,s);
   int ans=-inf;
   for (int i=1;i<=s;i++)
   {
      int t=va_arg(p,int);
      if (t>ans)
         ans=t;
   }
   va_end(p);
   return(ans);
}
