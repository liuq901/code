#include <cstdio>
#include <cstdlib>
struct tree
{
   int l,r,x,k;
};
tree a[140000];
int main()
{
   void build(int,int,int,int),insert(int,int,int,int);
   int get(int,int,int);
   int n,p,m;
   scanf("%d%d%d",&n,&p,&m);
   build(1,1,n,p);
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      if (get(1,x,y-1)<z)
         printf("N\n");
      else
      {
         printf("T\n");
         insert(1,x,y-1,z);
      }
   }
   system("pause");
   return(0);
}
void build(int x,int l,int r,int num)
{
   a[x].l=l,a[x].r=r,a[x].x=num,a[x].k=0;
   if (l==r)
      return;
   int mid=l+r>>1;
   build(2*x,l,mid,num);
   build(2*x+1,mid+1,r,num);
}
void insert(int x,int l,int r,int p)
{
   int min(int,int);
   a[x].x-=a[x].k;
   if (a[x].l!=a[x].r)
   {
      a[2*x].k+=a[x].k;
      a[2*x+1].k+=a[x].k;
   }
   a[x].k=0;
   if (a[x].l==l && a[x].r==r)
   {
      a[x].k=p;
      return;
   }
   int mid=a[x].l+a[x].r>>1;
   if (r<=mid)
      insert(2*x,l,r,p);
   else if (l>=mid+1)
      insert(2*x+1,l,r,p);
   else
   {
      insert(2*x,l,mid,p);
      insert(2*x+1,mid+1,r,p);
   }
   a[x].x=min(a[2*x].x-a[2*x].k,a[2*x+1].x-a[2*x+1].k);
}
int get(int x,int l,int r)
{
   int min(int,int);
   a[x].x-=a[x].k;
   if (a[x].l!=a[x].r)
   {
      a[2*x].k+=a[x].k;
      a[2*x+1].k+=a[x].k;
   }
   a[x].k=0;
   if (a[x].l==l && a[x].r==r)
      return(a[x].x);
   int mid=a[x].l+a[x].r>>1;
   if (r<=mid)
      return(get(2*x,l,r));
   if (l>=mid+1)
      return(get(2*x+1,l,r));
   return(min(get(2*x,l,mid),get(2*x+1,mid+1,r)));
}
int min(int x,int y)
{
   return(x<y?x:y);
}
