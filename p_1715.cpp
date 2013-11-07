#include <cstdio>
#include <cstdlib>
int main()
{
   long long n,c[16];
   scanf("%I64d",&n);
   int len=9;
   long long t=n;
   c[0]=1;
   for (int i=1;i<=15;i++)
      c[i]=c[i-1]*i;
   while (1)
   {
      len--;
      t-=c[15]/c[16-len]*15;
      if (t<=0)
      {
         t+=c[15]/c[16-len]*15;
         break;
      }
   }
   int ans[10];
   bool f[20]={0};
   for (int i=len;i>=1;i--)
      for (int j=15;j>=0;j--)
      {
         if (i==len && j==0 || f[j])
            continue;
         long long k=c[15-len+i]/c[16-len];
         if (t-k<=0)
         {
            ans[len-i+1]=j;
            f[j]=true;
            break;
         }
         t-=k;
      }
   for (int i=1;i<=len;i++)
   {
      if (ans[i]>=10)
      {
         printf("%c",'A'+ans[i]-10);
         continue;
      }
      printf("%d",ans[i]);
   }
   printf("\n");
   system("pause");
   return(0);
}
