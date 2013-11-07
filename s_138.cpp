#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,s,i,j,t;
   int a[101],b[101],ans[10001][2];
   scanf("%d",&n);
   s=0;
   for (i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      b[i]=i;
      s+=a[i];
   }
   for (i=1;i<=n-1;i++)
      for (j=i+1;j<=n;j++)
         if (a[i]>a[j])
         {
            t=a[i],a[i]=a[j],a[j]=t;
            t=b[i],b[i]=b[j],b[j]=t;
         }
   s/=2;
   memset(ans,0,sizeof(ans));
   t=n;
   for (i=1;i<=s;i++)
   {
      a[t]--;
      if (a[t]==0)
      {
         ans[i][0]=b[t-1];
         a[t-1]--;
         ans[i][1]=b[t];
         while (a[t]==0)
            t--;
      }
      else
         ans[i][0]=b[t];
   }
   for (i=1;i<=s;i++)
   {
      if (ans[i][0]==0)
      {
         ans[i][0]=b[t];
         a[t]--;
      }
      else if (ans[i][1]==0)
      {
         ans[i][1]=b[t];
         a[t]--;
      }
      if (a[t]==0)
         t--;
   }
   printf("%d\n",s);
   for (i=1;i<=s;i++)
      printf("%d %d\n",ans[i][0],ans[i][1]);
   system("pause");
   return(0);
}
