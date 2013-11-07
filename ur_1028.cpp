#include <cstdio>
#include <cstdlib>
int ans[15001],a[32010];
int main()
{
   void insert(int);
   int find(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int x;
      scanf("%d%*d",&x);
      x++;
      insert(x);
      ans[find(x)]++;
   }
   for (int i=1;i<=n;i++)
      printf("%d\n",ans[i]);
   system("pause");
   return(0);
}
void insert(int x)
{
   while (x<=32001)
   {
      a[x]++;
      x+=x&-x;
   }
}
int find(int x)
{
   int s=0;
   while (x>0)
   {
      s+=a[x];
      x-=x&-x;
   }
   return(s);
}
