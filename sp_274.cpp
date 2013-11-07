#include <cstdio>
#include <cstdlib>
struct tree
{
   int l,r,x,k;
};
tree a[2600];
int limit,ans,x[1010],y[1010],v[1010];
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   while (t--)
      work();
   system("pause");
   return(0);
}
void work()
{
   void sort(int,int),work(int);
   int n;
   scanf("%d%d",&n,&limit);
   for (int i=1;i<=n;i++)
      scanf("%d%d%d",&x[i],&y[i],&v[i]);
   sort(1,n);
   ans=x[n+1]=1<<30;
   for (int i=0;i<1000;i++)
      work(i);
   printf("%d\n",ans);
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
         t=y[i],y[i]=y[j],y[j]=t;
         t=v[i],v[i]=v[j],v[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void work(int height)
{
   void build(int,int,int),insert(int,int,int,int);
   int l,now,pos;
   l=now=pos=1;
   build(1,1,1000);
   for (int i=1;i<=1000;i++)
   {
      while (x[now]==i)
      {
         insert(1,y[now]-height,y[now],v[now]);
         now++;
      }
      while (a[1].x>=limit)
      {
         if ((i-l)*height<ans)
            ans=(i-l)*height;
         while (x[pos]==l)
         {
            insert(1,y[pos]-height,y[pos],-v[pos]);
            pos++;
         }
         l++;
      }
   }
}
void build(int x,int left,int right)
{
   a[x].l=left,a[x].r=right,a[x].x=a[x].k=0;   
   if (left==right)
      return;
   int mid=left+right>>1,ls=x<<1,rs=ls+1;
   build(ls,left,mid);
   build(rs,mid+1,right);
}
void insert(int x,int left,int right,int value)
{
   void update(int);
   int max(int,int);
   if (left<1)
      left=1;
   if (a[x].l==left && a[x].r==right)
   {
      a[x].k+=value;
      a[x].x+=value;
      return;
   }
   int mid=a[x].l+a[x].r>>1,ls=x<<1,rs=ls+1;
   if (right<=mid)
      insert(ls,left,right,value);
   else if (left>mid)
      insert(rs,left,right,value);
   else
   {
      insert(ls,left,mid,value);
      insert(rs,mid+1,right,value);
   }
   a[x].x=max(a[ls].x,a[rs].x)+a[x].k;
}
int max(int x,int y)
{
   return(x>y?x:y);
}
