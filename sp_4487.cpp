#include <cstdio>
#include <cstdlib>
struct tree
{
   int l,r,value,max,maxl,maxr,sum,size,father;
};
tree a[200001];
int now,tot,root;
int main()
{
   void update(int),insert(int,int),del(int),replace(int,int);
   int get(int,int);
   int n;
   scanf("%d",&n);
   a[0].max=a[0].maxl=a[0].maxr=a[0].sum=-1<<26;
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d",&x);
      a[i].l=i-1;
      a[i].value=x;
      a[i-1].father=i;
      update(i);
   }
   root=n;
   tot=n;
   now=n;
   int m;
   scanf("%d",&m);
   while (m--)
   {
      char ch;
      int x,y;
      scanf("\n%c",&ch);
      switch (ch)
      {
      case 'I':
         scanf("%d%d",&x,&y);
         insert(x,y);
         break;
      case 'D':
         scanf("%d",&x);
         del(x);
         break;
      case 'R':
         scanf("%d%d",&x,&y);
         replace(x,y);
         break;
      case 'Q':
         scanf("%d%d",&x,&y);
         printf("%d\n",get(x,y));
         break;
      }
   }
   system("pause");
   return(0);
}
void insert(int pos,int v)
{
   void update(int),splay(int,int);
   int find(int);
   now++;
   if (pos==now)
   {
      a[++tot].l=root;
      a[tot].value=v;
      a[root].father=tot;
      root=tot;
      update(tot);
      return;
   }
   splay(find(pos),0);
   a[++tot].l=a[root].l;
   a[tot].value=v;
   a[a[tot].l].father=tot;
   a[root].l=tot;
   a[tot].father=root;
   update(tot);
   update(root);
}
void del(int pos)
{
   void splay(int,int),update(int);
   int find(int);
   now--;
   if (pos==now+1)
   {
      splay(find(pos),0);
      a[a[root].l].father=0;
      root=a[root].l;
      update(root);
      return;
   }
   splay(find(pos+1),0);
   splay(find(pos),root);
   a[root].l=a[a[root].l].l;
   a[a[root].l].father=root;
   update(root);
}
void replace(int pos,int v)
{
   void splay(int,int),update(int);
   int find(int);
   splay(find(pos),0);
   a[root].value=v;
   update(root);
}
int get(int l,int r)
{
   void splay(int,int);
   int find(int);
   if (l==1 && r==now)
      return(a[root].max);
   if (r==now)
   {
      splay(find(l-1),0);
      return(a[a[root].r].max);
   }
   if (l==1)
   {
      splay(find(r+1),0);
      return(a[a[root].l].max);
   }
   splay(find(r+1),0);
   splay(find(l-1),root);
   return(a[a[a[root].l].r].max);
}
void splay(int x,int father)
{
   void zig(int),zag(int),update(int);
   while (a[x].father!=father)
   {
      int k=a[x].father;
      if (x==a[k].l && k==a[a[k].father].l && a[k].father!=father)
         zig(k);
      else if (x==a[k].r && k==a[a[k].father].r && a[k].father!=father)
         zag(k);
      if (x==a[k].l)
         zig(x);
      else
         zag(x);
   }
   update(x);
   if (!father)
      root=x;
}
void zig(int x)
{
   void update(int);
   int t=a[x].r,k=a[x].father;
   if (k==a[a[k].father].l)
      a[a[k].father].l=x;
   else if (k==a[a[k].father].r)
      a[a[k].father].r=x;
   a[x].father=a[k].father;
   a[k].father=x;
   a[t].father=k;
   a[x].r=k;
   a[k].l=t;
   update(k);
}
void zag(int x)
{
   void update(int);
   int t=a[x].l,k=a[x].father;
   if (k==a[a[k].father].l)
      a[a[k].father].l=x;
   else if (k==a[a[k].father].r)
      a[a[k].father].r=x;
   a[x].father=a[k].father;
   a[k].father=x;
   a[t].father=k;
   a[x].l=k;
   a[k].r=t;
   update(k);
}
void update(int x)
{
   int max(int,int);
   if (!x)
      return;
   a[x].size=a[a[x].l].size+a[a[x].r].size+1;
   a[x].sum=a[x].value;
   int p,q;
   p=max(a[a[x].l].max,a[a[x].r].max);
   q=max(a[a[x].l].maxr+a[x].value,a[a[x].r].maxl+a[x].value);
   a[x].max=max(max(p,q),max(a[a[x].l].maxr+a[x].value+a[a[x].r].maxl,a[x].value));
   a[x].maxl=max(a[x].value,a[x].value+a[a[x].r].maxl);
   if (a[x].l)
   {
      a[x].sum+=a[a[x].l].sum;
      a[x].maxl=max(a[a[x].l].maxl,a[x].maxl+a[a[x].l].sum);
   }
   a[x].maxr=max(a[x].value,a[x].value+a[a[x].l].maxr);
   if (a[x].r)
   {
      a[x].sum+=a[a[x].r].sum;
      a[x].maxr=max(a[a[x].r].maxr,a[x].maxr+a[a[x].r].sum);
   }
}
int max(int x,int y)
{
   return(x>y?x:y);
}
int find(int pos)
{
   int x=root;
   while (a[a[x].l].size!=pos-1)
      if (a[a[x].l].size>=pos)
         x=a[x].l;
      else
      {
         pos-=a[a[x].l].size+1;
         x=a[x].r;
      }
   return(x);
}
