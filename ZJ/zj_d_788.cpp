#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[100010];
int main()
{
   void insert(int);
   int find(int);
   while (scanf("%d",&n)==1)
   {
      memset(a,0,sizeof(a));
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         insert(x);
         printf("%d\n",i-find(x)+1);
      }
   }
   system("pause");
   return(0);
}
void insert(int x)
{
   for (int i=x;i<=n;i+=i&-i)
      a[i]++;
}
int find(int x)
{
   int ans=0;
   for (int i=x;i;i-=i&-i)
      ans+=a[i];
   return(ans);
}
