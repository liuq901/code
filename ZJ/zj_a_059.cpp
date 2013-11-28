#include <cstdio>
#include <cstdlib>
int ans[1010];
int main()
{
   void init();
   init();
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int a,b;
      scanf("%d%d",&a,&b);
      if (a==0)
         a=1;
      static int id=0;
      printf("Case %d: %d\n",++id,ans[b]-ans[a-1]);
   }
   system("pause");
   return(0);
}
bool f[1010];
void init()
{
   for (int i=1;i<32;i++)
      f[i*i]=true;
   for (int i=1;i<=1000;i++)
      ans[i]=ans[i-1]+i*f[i];
}
