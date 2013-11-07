#include <cstdio>
#include <cstdlib>
class tree
{
   int l,r,x0,x1;
   tree *left,*right;
public:
   void build(int begin,int end,int *a)
   {
      l=begin,r=end;
      if (l==r)
      {
         x0=a[l],x1=-1<<30;
         return;
      }
      int mid=l+r>>1;
      left=new(tree),right=new(tree);
      left->build(l,mid,a);
      right->build(mid+1,r,a);
      x0=max(left->x0,right->x0);
      x1=max(max(left->x1,right->x1),min(left->x0,right->x0));
   }
   void modify(int pos,int value)
   {
      if (l==r)
      {
         x0=value;
         return;
      }
      int mid=l+r>>1;
      if (pos<=mid)
         left->modify(pos,value);
      else
         right->modify(pos,value);
      x0=max(left->x0,right->x0);
      x1=max(max(left->x1,right->x1),min(left->x0,right->x0));
   }
   int count(int begin,int end)
   {
      if (begin==l && end==r)
         return(x0);
      int mid=l+r>>1;
      if (end<=mid)
         return(left->count(begin,end));
      else if (begin>mid)
         return(right->count(begin,end));
      else
         return(max(left->count(begin,mid),right->count(mid+1,end)));
   }
   int find(int begin,int end)
   {
      if (begin==l && end==r)
         return(x1);
      int mid=l+r>>1;
      if (end<=mid)
         return(left->find(begin,end));
      else if (begin>mid)
         return(right->find(begin,end));
      else
         return(max(max(left->find(begin,mid),right->find(mid+1,end)),min(left->count(begin,mid),right->count(mid+1,end))));
   }
private:
   int max(int x,int y)
   {
      return(x>y?x:y);
   }
   int min(int x,int y)
   {
      return(x<y?x:y);
   }
};
int a[100001];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   tree *root=new(tree);
   root->build(1,n,a);
   int p;
   scanf("%d%*c",&p);
   for (int i=1;i<=p;i++)
   {
      char ch;
      int x,y;
      scanf("%c%d%d%*c",&ch,&x,&y);
      if (ch=='U')
         root->modify(x,y);
      else
         printf("%d\n",root->count(x,y)+root->find(x,y));
   }
   system("pause");
   return(0);
}
