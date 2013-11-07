#include <cstdio>
#include <cstdlib>
class tree
{
   int l,r,x,k;
   tree *left,*right;
public:
   void build(int begin,int end,int *a)
   {
      l=begin,r=end,k=0;
      if (l==r)
      {
         x=a[l];
         return;
      }
      left=new(tree);
      right=new(tree);
      int mid=l+r>>1;
      left->build(l,mid,a);
      right->build(mid+1,r,a);
      x=min(left->x,right->x);
   }
   void modify(int begin,int end,int value)
   {
      update();
      if (l==begin && r==end)
      {
         k=value;
         return;
      }
      int mid=l+r>>1;
      if (end<=mid)
         left->modify(begin,end,value);
      else if (begin>mid)
         right->modify(begin,end,value);
      else
      {
         left->modify(begin,mid,value);
         right->modify(mid+1,end,value);
      }
      x=min(left->x+left->k,right->x+right->k);
   }
   bool correct()
   {
      update();
      return(x>=0);
   }
   void destroy()
   {
      if (l!=r)
      {
         left->destroy();
         right->destroy();
      }
      delete(this);
   }
private:
   void update()
   {
      if (l!=r)
      {
         left->k+=k;
         right->k+=k;
      }
      x+=k;
      k=0;
   }
   int min(int x,int y)
   {
      return(x<y?x:y);
   }
};
int a[30001],s[30001];
int main()
{
   for (int i=1;i<=10;i++)
   {
      printf("Test %d:\n",i);
      int n;
      scanf("%d\n",&n);
      for (int i=1;i<=n;i++)
      {
         char ch;
         scanf("%c",&ch);
         a[i]=ch=='('?1:-1;
         s[i]=s[i-1]+a[i];
      }
      tree *root=new(tree);
      root->build(1,n,s);
      int m;
      scanf("%d",&m);
      for (int i=1;i<=m;i++)
      {
         int x;
         scanf("%d",&x);
         if (x)
         {
            int k=a[x];
            a[x]*=-1;
            k=a[x]-k;
            s[n]+=k;
            root->modify(x,n,k);
         }
         else
            printf("%s\n",root->correct() && !s[n]?"YES":"NO");
      }
      root->destroy();
   }
   system("pause");
   return(0);
}
