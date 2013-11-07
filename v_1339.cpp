#include <cstdio>
#include <cstdlib>
int a[20001],f[20001],g[20001];
int main()
{
   int max(int,int),min(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   int l=0,r,ans;
   r=1<<30;
   while (l<=r)
   {
      int mid=l+r>>1;
      bool flag=true;
      f[1]=g[1]=a[1];
      for (int i=2;i<=n;i++)
      {
         if (a[i-1]+a[i]-mid>a[1])
         {
            flag=false;
            break;
         }
         f[i]=max(0,a[i-1]+a[i]-mid-g[i-1]);
         g[i]=min(a[i],a[1]-f[i-1]);
      }
      if (!f[n] && flag)
      {
         ans=mid;
         r=mid-1;
      }
      else
         l=mid+1;
   }
   printf("%d\n",ans+a[1]);
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
