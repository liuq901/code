#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,i,x,l,r;
   int ans[101],d[101],q[101],a[101][101];
   scanf("%d",&n);
   memset(d,0,sizeof(d));
   for (i=1;i<=n;i++)
   {
      a[i][0]=0;
      while (1)
      {
         scanf("%d",&x);
         if (x==0)
            break;
         a[i][0]++;
         a[i][a[i][0]]=x;
         d[x]++;
      }
   }
   r=0;
   for (i=1;i<=n;i++)
      if (d[i]==0)
      {
         r++;
         q[r]=i;
      }
   l=1;
   while (l<=r)
   {
      for (i=1;i<=a[q[l]][0];i++)
      {
         d[a[q[l]][i]]--;
         if (d[a[q[l]][i]]==0)
         {
            r++;
            q[r]=a[q[l]][i];
         }
      }
      ans[l]=q[l];
      l++;
   }
   for (i=1;i<=n-1;i++)
      printf("%d ",ans[i]);
   printf("%d\n",ans[n]);
   system("pause");
   return(0);
}
