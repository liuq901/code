#include <cstdio>
#include <cstdlib>
#include <cstring>
struct tree
{
   int sum,min;
};
const int inf=1<<30;
int n,k,d[20010],c[20010],s[20010],e[20010],b[20010],pos[20010],w[20010];
tree t[100010],tt[100010];
int main()
{
   int find(double),count(int,int,int,int,int),min(int,int);
   void sort(int,int),insert(int,int,int,int,int,int,tree *);
   scanf("%d%d",&n,&k);
   for (int i=2;i<=n;i++)
      scanf("%d",&d[i]);
   for (int i=1;i<=n;i++)
      scanf("%d",&c[i]);
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&s[i]);
      e[i]=find(d[i]+s[i]+1e-1);
      b[i]=find(d[i]-s[i]-1e-1)+1;
      pos[i]=i;
   }
   for (int i=1;i<=n;i++)
      scanf("%d",&w[i]);
   n++;
   k++;
   d[n]=c[n]=inf;
   e[n]=b[n]=pos[n]=n;
   sort(1,n);
   int sum=inf;
   for (int i=1;i<=n;i++)
   {
      sum+=w[i];
      insert(1,0,n,i,i,sum,t);
   }
   int ans=2147483647;
   for (int i=1;i<=k;i++)
   {
      int h=1,tmp;
      for (int j=1;j<=n;j++)
      {
         while (e[h]<j)
         {
            insert(1,0,n,0,b[pos[h]]-1,w[pos[h]],t);
            h++;
         }
         tmp=count(1,0,n,0,j-1)+c[j];
         insert(1,0,n,j,j,tmp,tt);
      }
      ans=min(ans,tmp);
      memcpy(t,tt,sizeof(tt));
      memset(tt,0,sizeof(tt));
   }
   printf("%d\n",ans-inf);
   system("pause");
   return(0);
}
int find(double x)
{
   int l=1,r=n;
   while (l<=r)
   {
      int mid=l+r>>1;
      if (d[mid]<x)
         l=mid+1;
      else
         r=mid-1;
   }
   return(l-1);
}
int count(int p,int b,int e,int l,int r)
{
   int min(int,int);
   if (b==l && e==r)
      return(t[p].min+t[p].sum);
   int mid=b+e>>1;
   int ls=p<<1,rs=ls+1;
   if (r<=mid)
      return(count(ls,b,mid,l,r)+t[p].sum);
   else if (l>mid)
      return(count(rs,mid+1,e,l,r)+t[p].sum);
   else
      return(min(count(ls,b,mid,l,mid),count(rs,mid+1,e,mid+1,r)+t[p].sum));
}
void sort(int l,int r)
{
   int i,j,x;
   i=l,j=r;
   x=e[l+r>>1];
   while (i<=j)
   {
      while (e[i]<x)
         i++;
      while (e[j]>x)
         j--;
      if (i<=j)
      {
         int t;
         t=e[i],e[i]=e[j],e[j]=t;
         t=pos[i],pos[i]=pos[j],pos[j]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
void insert(int p,int b,int e,int l,int r,int c,tree *t)
{
   int min(int,int);
   if (b==l && e==r)
   {
      t[p].sum+=c;
      return;
   }
   int mid=b+e>>1;
   int ls=p<<1,rs=ls+1;
   if (r<=mid)
      insert(ls,b,mid,l,r,c,t);
   else if (l>mid)
      insert(rs,mid+1,e,l,r,c,t);
   else
   {
      insert(ls,b,mid,l,mid,c,t);
      insert(rs,mid+1,e,mid+1,r,c,t);
   }
   t[p].min=min(t[ls].min+t[ls].sum,t[rs].min+t[rs].sum);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
