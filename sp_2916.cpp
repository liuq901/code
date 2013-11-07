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
   int ans(int x1,int y1,int x2,int y2)
   {
      int ans=0;
      if (y1<x2)
      {
         if (y1+1<=x2-1)
            ans+=find(y1+1,x2-1)->sum;
         ans+=find(x1,y1)->maxr+find(x2,y2)->maxl;
      }
      else
      {
         ans=find(x2,y1)->max;
         if (x1<=x2-1)
            ans=get(ans,find(x1,x2-1)->maxr+find(x2,y2)->maxl);
         if (y1+1<=y2)
            ans=get(ans,find(x1,y1)->maxr+find(y1+1,y2)->maxl);
      }
      return(ans);
   }
private:
   int get(int x,int y)
   {
      return(x>y?x:y);
   }
};
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
int a[10001];
void work()
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
      int x1,y1,x2,y2;
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      printf("%d\n",root->ans(x1,y1,x2,y2));
   }
}
