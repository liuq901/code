#include <cstdio>
#include <cstdlib>
int a[100001];
long long ans;
int main()
{
   int max(int,int),min(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=2;i<n;i++)
   {
      if (a[i]>a[i-1] && a[i]>a[i+1])
         ans+=a[i]-max(a[i-1],a[i+1]),a[i]=max(a[i-1],a[i+1]);
      if (a[i]<a[i-1] && a[i]<a[i+1])
         ans+=min(a[i-1],a[i+1])-a[i],a[i]=min(a[i-1],a[i+1]);
   }
   for (int i=2;i<=n;i++)
      ans+=abs(a[i]-a[i-1]);
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
