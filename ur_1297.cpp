#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,p,q,n,max,ans,t;
   char s[1010];
   scanf("%s",&s[1]);
   n=strlen(&s[1]);
   max=0;
   for (i=1;i<=n;i++)
   {
      t=1;
      p=q=i;
      while (1)
      {
         p--,q++;
         if (p==0 || q>n)
            break;
         if (s[p]!=s[q])
            break;
         t+=2;
      }
      if (t>max)
      {
         max=t;
         ans=i-t/2;
      }
      if (i+1>n)
         continue;
      t=0;
      p=i+1;
      q=i;
      while (1)
      {
         p--,q++;
         if (p==0 || q>n)
            break;
         if (s[p]!=s[q])
            break;
         t+=2;
      }
      if (t>max)
      {
         max=t;
         ans=i-t/2+1;
      }
   }
   for (i=1;i<=max;i++)
      printf("%c",s[i+ans-1]);
   printf("\n");
   system("pause");
   return(0);
}
