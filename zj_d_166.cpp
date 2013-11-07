#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
int main()
{
   char s[1000];
   while (gets(s))
   {
      if (s[0]=='-')
         break;
      int n=1,l=strlen(s),a[51]={0};
      for (int i=0;i<l;i++)
      {
         if (i!=0 && !isdigit(s[i-1]) && isdigit(s[i]))
            n++;
         if (isdigit(s[i]))
            a[n]=a[n]*10+s[i]-'0';
      }
      int ans[51];
      memset(ans,26,sizeof(ans));
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
         {
            if (!a[i] && ans[j]>20000000)
            {
               ans[j]=i;
               break;
            }
            if (ans[j]>i)
               a[i]--;
         }
      for (int i=1;i<n;i++)
         printf("%d ",ans[i]);
      printf("%d\n",ans[n]);
   }
   system("pause");
   return(0);
}
