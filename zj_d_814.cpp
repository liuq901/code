#include <cstdio>
#include <cstdlib>
class splay
{
   int x,y,z;
public:
   int l()
   {
      return(x&131071);
   }
   int r()
   {
      return(y&131071);
   }
   int f()
   {
      return(z&131071);
   }
   int s()
   {
      int a,b;
      a=x>>20&511;
      b=y>>20&255;
      return((a<<8)+b);
   }
   bool flag()
   {
      return(z>>20&1);
   }
   void l(int l)
   {
      x&=-131072;
      x|=l;
   }
   void r(int r)
   {
      y&=-131072;
      y|=r;
   }
   void f(int f)
   {
      z&=-131072;
      z|=f;
   }
   void s(int s)
   {
      int a,b;
      a=s>>8,b=s&255;
      x&=-535822337;
      x|=a<<20;
      y&=-267386881;
      y|=b<<20;
   }
   void flag(bool flag)
   {
      z&=-1048577;
      z|=flag<<20;
   }
};
splay a[130010];
int root;
bool first;
int main()
{
   int build(int,int,int),find(int,int);
   void splay(int,int),reverse(int),print(int);
   int n,m;
   while (scanf("%d%d",&n,&m)==2)
   {
      a[0].s(0);
      root=build(0,1,n);
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         if (x==1 && y==n)
            reverse(root);
         else if (x==1)
         {
            splay(find(root,y+1),0);
            reverse(a[root].l());
         }
         else if (y==n)
         {
            splay(find(root,x-1),0);
            reverse(a[root].r());
         }
         else
         {
            splay(find(root,x-1),0);
            splay(find(root,y+1),root);
            reverse(a[a[root].r()].l());
         }
      }
      first=true;
      print(root);
      printf("\n");
   }
   system("pause");
   return(0);
}
int build(int father,int l,int r)
{
   int x=l+r>>1;
   a[x].flag(false);
   a[x].f(father);
   a[x].l(l<x?build(x,l,x-1):0);
   a[x].r(x<r?build(x,x+1,r):0);
   a[x].s(a[a[x].l()].s()+a[a[x].r()].s()+1);
   return(x);
}
int find(int x,int value)
{
   void update(int);
   update(x);
   if (a[a[x].l()].s()+1==value)
      return(x);
   return(a[a[x].l()].s()>=value?find(a[x].l(),value):find(a[x].r(),value-a[a[x].l()].s()-1));
}
void splay(int x,int aim)
{
   void up(int);
   while (a[x].f()!=aim)
      up(x);
   if (!aim)
      root=x;
}
void up(int x)
{
   int s=a[x].f(),p;
   if (x==a[s].l())
   {
      p=a[x].r();
      a[s].l(p),a[x].r(s);
   }
   else
   {
      p=a[x].l();
      a[s].r(p),a[x].l(s);
   }
   a[p].f(s),a[x].f(a[s].f()),a[s].f(x);
   a[s].s(a[a[s].l()].s()+a[a[s].r()].s()+1);
   a[x].s(a[a[x].l()].s()+a[a[x].r()].s()+1);
   if (!a[x].f())
      return;
   if (s==a[a[x].f()].l())
      a[a[x].f()].l(x);
   else
      a[a[x].f()].r(x);
}
void reverse(int x)
{
   void update(int);
   update(x);
   a[x].flag(!a[x].flag());
}
void print(int x)
{
   void update(int);
   update(x);
   if (a[x].l())
      print(a[x].l());
   if (!first)
      printf(" ");
   first=false;
   printf("%d",x);
   if (a[x].r())
      print(a[x].r());
}
void update(int x)
{
   if (a[x].flag())
   {
      a[a[x].l()].flag(!a[a[x].l()].flag());
      a[a[x].r()].flag(!a[a[x].r()].flag());
      int t=a[x].l();
      a[x].l(a[x].r()),a[x].r(t);
      a[x].flag(false);
   }
}
