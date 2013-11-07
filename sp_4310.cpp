#include <cstdio>
#include <cstdlib>
class tree
{
   int s,l,r,k;
   tree *left,*right;
public:
   void build(int begin,int end)
   {
      l=begin,r=end,k=0;
      if (l==r)
      {
         s=-l;
         return;
      }
      int mid=l+r>>1;
      left=new(tree),right=new(tree);
      left->build(l,mid);
      right->build(mid+1,r);
      s=max(left->s,right->s);
   }
   void insert(int begin,int end,int value)
   {
      update();
      if (l==begin && r==end)
      {
         k+=value;
         return;
      }
      int mid=l+r>>1;
      if (end<=mid)
         left->insert(begin,end,value);
      else if (begin>mid)
         right->insert(begin,end,value);
      else
      {
         left->insert(begin,mid,value);
         right->insert(mid+1,end,value);
      }
      s=max(left->s+left->k,right->s+right->k);
   }
   bool ok()
   {
      update();
      return(s<=0);
   }
private:
   int max(int x,int y)
   {
      return(x>y?x:y);
   }
   void update()
   {
      if (l!=r)
      {
         left->k+=k;
         right->k+=k;
      }
      s+=k;
      k=0;
   }
};
int a[200001];
int main()
{
   int n;
   scanf("%d",&n);
   tree *root=new(tree);
   root->build(1,n);
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      root->insert(a[i],n,1);
   }
   printf("%s\n",root->ok()?"TAK":"NIE");
   int m;
   scanf("%d",&m);
   for (int i=1;i<=m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      root->insert(a[x],n,-1);
      root->insert(y,n,1);
      a[x]=y;
      printf("%s\n",root->ok()?"TAK":"NIE");
   }
   system("pause");
   return(0);
}
