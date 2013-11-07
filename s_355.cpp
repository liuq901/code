#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[10001],f[10001];
int main()
{
   int count(int);
   int n,i,j;
   int ans[10001];
   scanf("%d",&n);
   memset(f,0,sizeof(f));
   f[1]=1;
   for (i=2;i<=n;i++)
   {
      if (f[i])
         continue;
      j=1;
      while (1)
      {
         j++;
         if (i*j>n)
            break;
         f[i*j]=1;
      }
   }
   a[0]=0;
   for (i=2;i<=n;i++)
      if (!f[i])
      {
         a[0]++;
         a[a[0]]=i;
      }
   ans[0]=0;
   for (i=1;i<=n;i++)
   {
      ans[i]=count(i);
      if (ans[i]>ans[0])
         ans[0]=ans[i];
   }
   printf("%d\n",ans[0]);
   for (i=1;i<=n-1;i++)
      printf("%d ",ans[i]);
   printf("%d\n",ans[n]);
   system("pause");
   return(0);
}
int count(int x)
{
   int s,i;
   if (x==1)
      return(1);
   s=0;
   i=1;
   while (1)
   {
      if (!f[x])
         break;
      if (x%a[i]==0)
      {
         x/=a[i];
         s++;
      }
      else
         i++;
   }
   return(s+2);
}
