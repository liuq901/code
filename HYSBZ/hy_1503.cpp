#include <cstdio>
#include <cstdlib>
struct treap
{
   int l,r,f,x,s,p;
};
treap a[100001];
int root,tot;
int main()
{
   void insert(int,int),del(int,int);
   int size(),count(int,int);
   int n,min,s,q;
   scanf("%d%d%*c",&n,&min);
   s=q=0;
   for (int i=1;i<=n;i++)
   {
      char ch;
      int x;
      scanf("%c%d%*c",&ch,&x);
      if (ch=='I')
      {
         x+=q;
         if (x<min)
            continue;
         insert(root,x);
         s++;
      }
      else if (ch=='A')
      {
         min-=x;
         q-=x;
      }
      else if (ch=='S')
      {
         min+=x;
         q+=x;
         del(root,min);
      }
      else
      {
         if (x>size())
         {
            printf("-1\n");
            continue;
         }
         printf("%d\n",count(root,size()-x+1)-q);
      }
   }
   printf("%d\n",s-size());
   system("pause");
   return(0);
}
void insert(int x,int value)
{
   int build(int,int);
   void zig(int),zag(int);
   if (!x)
   {
      build(0,value);
      root=tot;
      return;
   }
   if (value<=a[x].x)
   {
      if (a[x].l)
         insert(a[x].l,value);
      else
         a[x].l=build(x,value);
      a[x].s=a[a[x].l].s+a[a[x].r].s+1;
      if (a[a[x].l].p<a[x].p)
         zig(x);
   }
   else
   {
      if (a[x].r)
         insert(a[x].r,value);
      else
         a[x].r=build(x,value);
      a[x].s=a[a[x].l].s+a[a[x].r].s+1;
      if (a[a[x].r].p<a[x].p)
         zag(x);
   }
}
int build(int father,int value)
{
   tot++;
   a[tot].l=a[tot].r=0,a[tot].f=father;
   a[tot].x=value,a[tot].s=1,a[tot].p=rand();
   return(tot);
}
void zig(int x)
{
   int t=a[x].l,p=a[t].r;
   if (!a[x].f)
      root=t;
   else if (x==a[a[x].f].l)
      a[a[x].f].l=t;
   else
      a[a[x].f].r=t;
   a[t].r=x,a[x].l=p;
   a[t].f=a[x].f,a[x].f=t,a[p].f=x;
   a[t].s=a[x].s;
   a[x].s=a[p].s+a[a[x].r].s+1;
}
void zag(int x)
{
   int t=a[x].r,p=a[t].l;
   if (!a[x].f)
      root=t;
   else if (x==a[a[x].f].l)
      a[a[x].f].l=t;
   else
      a[a[x].f].r=t;
   a[t].l=x,a[x].r=p;
   a[t].f=a[x].f,a[x].f=t,a[p].f=x;
   a[t].s=a[x].s;
   a[x].s=a[p].s+a[a[x].l].s+1;
}
void del(int x,int value)
{
   if (!x)
      return;
   if (a[x].x<value)
   {
      int p=a[x].f,t=a[x].r;
      if (!p)
         root=t;
      else
         a[p].l=t;
      a[t].f=p;
      del(t,value);
   }
   else
   {
      del(a[x].l,value);
      a[x].s=a[a[x].l].s+a[a[x].r].s+1;
   }
}
int size()
{
   return(a[root].s);
}
int count(int x,int pos)
{
   if (pos==a[a[x].l].s+1)
      return(a[x].x);
   else if (pos<a[a[x].l].s+1)
      return(count(a[x].l,pos));
   else
      return(count(a[x].r,pos-a[a[x].l].s-1));
}
