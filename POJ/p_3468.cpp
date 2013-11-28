#include <cstdio>
#include <cstdlib>
struct tree
{
   int l,r;
   long long x,t;
   tree *left_son,*right_son;
   void init(int left,int right,int *a)
   {
      l=left;
      r=right;
      t=0;
      if (left==right)
      {
         x=a[l];
         return;
      }
      left_son=new(tree);
      right_son=new(tree);
      int mid=(left+right)/2;
      left_son->init(left,mid,a);
      right_son->init(mid+1,right,a);
      x=left_son->x+right_son->x;
   }
   long long find(int left,int right)
   {
      x+=t*(r-l+1);
      if (l!=r)
      {
         left_son->t+=t;
         right_son->t+=t;
      }
      t=0;
      if (left==l && right==r)
         return(x);
      int mid=(l+r)/2;
      if (right<=mid)
         return(left_son->find(left,right));
      else if (left>mid)
         return(right_son->find(left,right));
      else
         return(left_son->find(left,mid)+right_son->find(mid+1,right));
   }
   void insert(int left,int right,int value)
   {
      if (l==left && r==right)
      {
         t+=value;
         return;
      }
      int mid=(l+r)/2;
      if (right<=mid)
         left_son->insert(left,right,value);
      else if (left>mid)
         right_son->insert(left,right,value);
      else
      {
         left_son->insert(left,mid,value);
         right_son->insert(mid+1,right,value);
      }
      x=left_son->x+left_son->t*(left_son->r-left_son->l+1);
      x+=right_son->x+right_son->t*(right_son->r-right_son->l+1);
   }
};
int b[100001];
int main()
{
   int n,q;
   tree *root;
   scanf("%d%d",&n,&q);
   for (int i=1;i<=n;i++)
      scanf("%d",&b[i]);
   root=new(tree);
   root->init(1,n,b);
   scanf("%*c");
   for (int i=1;i<=q;i++)
   {
      char ch;
      scanf("%c",&ch);
      if (ch=='Q')
      {
         int x,y;
         scanf("%d%d",&x,&y);
         printf("%I64d\n",root->find(x,y));
      }
      else
      {
         int x,y,t;
         scanf("%d%d%d",&x,&y,&t);
         root->insert(x,y,t);
      }
      scanf("%*c");
   }
   system("pause");
   return(0);
}
