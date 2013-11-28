#include <cstdio>
#include <cstdlib>
class tree
{
   int l,r,maxl,maxr,max,sum;
   tree *left,*right;
public:
   void build(int head,int end,int *a)
   {
      l=head,r=end;
      if (l==r)
      {
         maxl=maxr=max=sum=a[l];
         return;
      }
      left=new(tree);
      right=new(tree);
      int mid=l+r>>1;
      left->build(l,mid,a);
      right->build(mid+1,r,a);
      update(left,right);
   }
   tree *find(int head,int end)
   {
      if (head==l && end==r)
         return(this);
      int mid=l+r>>1;
      if (end<=mid)
         return(left->find(head,end));
      if (head>mid)
         return(right->find(head,end));
      tree *ans;
      ans=new(tree);
      ans->update(left->find(head,mid),right->find(mid+1,end));
      return(ans);
   }
   void update(tree *left,tree *right)
   {
      sum=left->sum+right->sum;
      max=get(get(left->max,right->max),left->maxr+right->maxl);
      maxl=get(left->maxl,left->sum+right->maxl);
      maxr=get(right->maxr,right->sum+left->maxr);
   }
   int ans()
   {
      return(max);
   }
private:
   int get(int x,int y)
   {
      return(x>y?x:y);
   }
};
int a[50001];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   tree *root;
   root=new(tree);
   root->build(1,n,a);
   int m;
   scanf("%d",&m);
   while (m--)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      printf("%d\n",root->find(x,y)->ans());
   }
   system("pause");
   return(0);
}
