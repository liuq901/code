#include <cstdio>
#include <cstdlib>
class tree
{
   int l,r;
   long long ans,value,k,p;
   tree *left,*right;
public:
   void build(int _l,int _r)
   {
      l=_l,r=_r;
      ans=value=p=k=0;
      if (l==r)
         return;
      left=new(tree),right=new(tree);
      int mid=l+r>>1;
      left->build(l,mid);
      right->build(mid+1,r);
   }
   void insert(int begin,int end,int v)
   {
      update();
      if (begin==l && end==r)
      {
         k=p=v;
         return;
      }
      int mid=l+r>>1;
      if (end<=mid)
         left->insert(begin,end,v);
      else if (begin>mid)
         right->insert(begin,end,v);
      else
      {
         left->insert(begin,mid,v);
         right->insert(mid+1,end,v);
      }
      left->update();
      right->update();
      value=max(left->value,right->value);
      ans=max(max(left->ans,right->ans),ans);
   }
   long long get(int begin,int end)
   {
      update();
      if (begin==l && end==r)
         return(ans);
      int mid=l+r>>1;
      if (end<=mid)
         return(left->get(begin,end));
      if (begin>mid)
         return(right->get(begin,end));
      return(max(left->get(begin,mid),right->get(mid+1,end)));
   }
private:
   void update()
   {
      ans=max(ans,value+p);
      value+=k;
      if (l!=r)
      {
         left->p=max(left->p,left->k+p);
         left->k+=k;
         right->p=max(right->p,right->k+p);
         right->k+=k;
      }
      k=p=0;
   }
   long long max(long long x,long long y)
   {
      return(x>y?x:y);
   }
};
int a[100001],l[100001],r[100001],pos[100001],pre[200001];
long long ans[100001];
int main()
{
   void sort(int,int,int *,int *,int *);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   tree *root=new(tree);
   root->build(1,n);
   int m;
   scanf("%d",&m);
   for (int i=1;i<=m;i++)
   {
      scanf("%d%d",&l[i],&r[i]);
      pos[i]=i;
   }
   sort(1,m,r,l,pos);
   int tot=1;
   for (int i=1;i<=n;i++)
   {
      root->insert(pre[a[i]+100000]+1,i,a[i]);
      pre[a[i]+100000]=i;
      while (tot!=m+1 && r[tot]<=i)
      {
         ans[tot]=root->get(l[tot],r[tot]);
         if (ans[tot]<0)
            ans[tot]=0;
         tot++;
      }
      if (tot==m+1)
         break;
   }
   for (int i=1;i<=m;i++)
      l[pos[i]]=i;
   for (int i=1;i<=m;i++)
      printf("%lld\n",ans[l[i]]);
   system("pause");
   return(0);
}
void sort(int l,int r,int *a,int *b,int *c)
{
   void swap(int &,int &);
   int i,j,x;
   i=l,j=r;
   x=a[l+r>>1];
   while (i<=j)
   {
      while (a[i]<x)
         i++;
      while (a[j]>x)
         j--;
      if (i<=j)
      {
         swap(a[i],a[j]);
         swap(b[i],b[j]);
         swap(c[i],c[j]);
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,a,b,c);
   if (l<j)
      sort(l,j,a,b,c);
}
void swap(int &a,int &b)
{
   int t;
   t=a,a=b,b=t;
}
