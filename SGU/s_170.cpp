#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,l,ans;
   int a[10000],b[10000];
   char s[10000],t[10000];
   scanf("%s",s);
   scanf("%s",t);
   if (strlen(s)!=strlen(t))
      printf("-1\n");
   else
   {
      l=strlen(s);
      a[0]=b[0]=0;
      for (i=0;i<l;i++)
      {
         if (s[i]=='-')
         {
            a[0]++;
            a[a[0]]=i;
         }
         if (t[i]=='-')
         {
            b[0]++;
            b[b[0]]=i;
         }
      }
      if (a[0]!=b[0])
         printf("-1\n");
      else
      {
         ans=0;
         for (i=1;i<=a[0];i++)
            ans+=abs(a[i]-b[i]);
         printf("%d\n",ans);
      }
   }
   system("pause");
   return(0);
}
