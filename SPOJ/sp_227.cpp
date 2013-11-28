#include <cstdio>
#include <cstdlib>
class tree
{
   int x,l,r;
   tree *left,*right;
public:
   void build(int begin,int end)
   {
      l=begin,r=end;
      if (begin==end)
      {
         x=1;
         return;
      }
      left=new(tree),right=new(tree);
      int mid=l+r>>1;
      left->build(l,mid);
      right->build(mid+1,r);
      x=left->x+right->x;
   }
   int find(int p)
   {
      if (l==r)
         return(l);
      if (p<=right->x)
         return(right->find(p));
      else
         return(left->find(p-right->x));
   }
   void modify(int p)
   {
      if (l==r)
      {
         x=0;
         return;
      }
      int mid=l+r>>1;
      if (p<=mid)
         left->modify(p);
      else
         right->modify(p);
      x=left->x+right->x;
   }
   void destory()
   {
      if (l!=r)
      {
         left->destory();
         right->destory();
      }
      delete(this);
   }
};
int a[200001],ans[200001];
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      tree *root=new(tree);
      root->build(1,n);
      for (int i=n;i>=1;i--)
      {
         int t=root->find(a[i]+1);
         ans[i]=t;
         root->modify(t);
      }
      root->destory();
      for (int i=1;i<n;i++)
         printf("%d ",ans[i]);
      printf("%d\n",ans[n]);
   }
   system("pause");
   return(0);
}
