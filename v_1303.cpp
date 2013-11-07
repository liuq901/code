#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int a[26],b[26];
   int n,i,j,ans;
   char ch;
   i=0;
   while (1)
   {
      i++;
      scanf("%d%c",&a[i],&ch);
      if (ch=='\n')
      {
         n=i;
         break;
      }
   }
   memset(b,0,sizeof(b));
   for (i=n;i>=1;i--)
   {
      b[i]=1;
      for (j=n;j>=i+1;j--)
         if (b[j]+1>b[i] && a[j]<a[i])
            b[i]=b[j]+1;
   }
   ans=0;
   for (i=1;i<=n;i++)
      if (b[i]>ans)
         ans=b[i];
   printf("%d\n",ans);
   memset(b,0,sizeof(b));
   for (i=1;i<=n;i++)
   {
      b[i]=1;
      for (j=1;j<=i-1;j++)
         if (b[j]+1>b[i] && a[i]>a[j])
            b[i]=b[j]+1;
   }
   ans=0;
   for (i=1;i<=n;i++)
      if (b[i]>ans)
         ans=b[i];
   printf("%d\n",ans);
   system("pause");
   return(0);
}
