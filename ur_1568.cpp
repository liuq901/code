#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[10001],b[10001];
int main()
{
   void work(bool);
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   memcpy(b,a,sizeof(a));
   work(false);
   memcpy(a,b,sizeof(b));
   work(true);
   system("pause");
   return(0);
}
int c[10001],f[10001],p[10001];
void work(bool flag)
{
   int ans=0;
   while (1)
   {
      ans++;
      for (int i=1;i<=n;i++)
         c[a[i]]=i;
      if (flag)
      {
         for (int i=1;i<=n-1;i++)
            printf("%d ",a[i]);
         printf("%d\n",a[n]);
      }
      f[n]=1;
      int sum=1;
      for (int i=n-1;i>=1;i--)
      {
         if (c[i]>c[i+1])
         {
            f[i]=f[i+1]+1;
            if (f[i]>sum)
               sum=f[i];
            continue;
         }
         f[i]=f[i+1];
      }
      int s=0;
      for (int i=1;i<=n;i++)
      {
         if (f[a[i]]%2==1)
            continue;
         s++;
         p[s]=a[i];
      }
      for (int i=1;i<=n;i++)
      {
         if (f[a[i]]%2==0)
            continue;
         s++;
         p[s]=a[i];
      }
      for (int i=1;i<=n;i++)
         a[i]=p[i];
      if (sum==1)
         break;
   }
   if (!flag)
      printf("%d\n",ans-1);
}
