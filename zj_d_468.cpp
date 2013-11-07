#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   while (1)
   {
      char s[1000],t[1000];
      scanf("%s %s",s,t);
      int n,m,l=strlen(s),k=strlen(t);
      n=m=0;
      if (l>11)
      {
         if (t[0]=='0')
            printf("1\n");
         else
            printf("%s\n",s);
         continue;
      }
      else if (k>11)
      {
         if (s[0]=='-' && t[k-1]-'0'&1)
            printf("-1\n");
         else if (s[l-1]=='1')
            printf("1\n");
         else
            printf("0\n");
         continue;
      }
      int p=0;
      if (s[0]=='-')
         p=1;
      for (int i=p;i<l;i++)
         n=n*10+s[i]-'0';
      for (int i=0;i<k;i++)
         m=m*10+t[i]-'0';
      if (!n && !m)
      {
         if (l==1 && k==1)
         {
            printf("All Over.\n");
            break;
         }
         printf("0\n");
         continue;
      }
      if (p)
         n*=-1;
      long long ans=1;
      for (int i=1;i<=m;i++)
         ans*=n;
      printf("%lld\n",ans);
   }
   system("pause");
   return(0);
}
