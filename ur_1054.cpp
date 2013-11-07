#include <cstdio>
#include <cstdlib>
int ans,a[51];
int main()
{
   void work(int,int,int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   work(n,1,2,3);
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void work(int p,int x,int y,int z)
{
   if (!p || ans==-1)
      return;
   if (a[p]==x)
      work(p-1,x,z,y);
   else if (a[p]==y)
   {
      ans+=1<<p-1;
      work(p-1,z,y,x);
   }
   else
      ans=-1;
}
