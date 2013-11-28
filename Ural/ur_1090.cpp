#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[50001],c[50001];
int main()
{
   void insert(int);
   int count(int);
   int k,ans,max;
   scanf("%d%d",&n,&k);
   max=-1;
   for (int i=1;i<=k;i++)
   {
      memset(c,0,sizeof(c));
      int sum=0;
      for (int j=1;j<=n;j++)
         scanf("%d",&a[j]);
      for (int j=n;j>=1;j--)
      {
         sum+=count(a[j]);
         insert(a[j]);
      }
      if (sum>max)
         max=sum,ans=i;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void insert(int x)
{
   for (int i=x;i<=n;i+=i&-i)
      c[i]++;
}
int count(int x)
{
   int ans=0;
   for (int i=x;i;i-=i&-i)
      ans+=c[i];
   return(ans);
}
