#include <cstdio>
#include <cstdlib>
struct treap
{
   int l,r,f,x,s,p;
};
treap a[100001];
int tot,root;
int main()
{
   void insert(int,int),del(int,int);
   int find(int,int);
   int test;
   scanf("%d",&test);
   while (test--)
   {
      int n,min,s,q;
      scanf("%d%d%*c",&n,&min);
      s=q=tot=root=0;
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
            if (x>a[root].s)
            {
               printf("-1\n");
               continue;
            }
            printf("%d\n",find(root,a[root].s-x+1)-q);
         }
      }
      printf("%d\n",s-a[root].s);
   }
   system("pause");
   return(0);
}
void insert(int x,int value)
{
   int build(int,int);
   void turn(int,bool);
   if (!x)
   {
      root=build(0,value);
      return;
   }
   if (value<=a[x].x)
   {
      if (a[x].l)
         insert(a[x].l,value);
      else
         a[x].l=build(x,value);
      a[x].s=a[a[x].l].s+a[a[x].r].s+1;
      if (a[a[x].l].p>a[x].p)
         turn(x,false);
   }
   else
   {
      if (a[x].r)
         insert(a[x].r,value);
      else
         a[x].r=build(x,value);
      a[x].s=a[a[x].l].s+a[a[x].r].s+1;
      if (a[a[x].r].p>a[x].p)
         turn(x,true);
   }
}
int build(int father,int value)
{
   tot++;
   a[tot].l=a[tot].r=0,a[tot].f=father;
   a[tot].x=value,a[tot].s=1,a[tot].p=rand();
   return(tot);
}
void turn(int x,bool flag)
{
   int t,p;
   if (flag)
      t=a[x].r,p=a[t].l;
   else
      t=a[x].l,p=a[t].r;
   if (!a[x].f)
      root=t;
   else if (x==a[a[x].f].l)
      a[a[x].f].l=t;
   else
      a[a[x].f].r=t;
   if (flag)
      a[t].l=x,a[x].r=p;
   else
      a[t].r=x,a[x].l=p;
   a[t].f=a[x].f,a[x].f=t,a[p].f=x;
   a[t].s=a[x].s,a[x].s=a[a[x].l].s+a[a[x].r].s+1;
}
void del(int x,int value)
{
   if (!x)
      return;
   if (a[x].x<value)
   {
      int t=a[x].r;
      if (!a[x].f)
         root=t;
      else
         a[a[x].f].l=t;
      a[t].f=a[x].f;
      del(t,value);
   }
   else
   {
      del(a[x].l,value);
      a[x].s=a[a[x].l].s+a[a[x].r].s+1;
   }
}
int find(int x,int pos)
{
   if (a[a[x].l].s+1==pos)
      return(a[x].x);
   if (a[a[x].l].s+1>pos)
      return(find(a[x].l,pos));
   return(find(a[x].r,pos-a[a[x].l].s-1));
}
