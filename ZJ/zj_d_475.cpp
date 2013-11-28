#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[100010],t[100010];
int main()
{
   while (scanf("%s %s",s,t)==2)
   {
      int n,m,l=strlen(s),k=strlen(t);
      n=m=0;
      int p=0;
      if (s[0]=='-')
         p=1;
      for (int i=p;i<l;i++)
         n=n*10+s[i]-'0';
      if (p)
         n*=-1;
      if (n==1)
      {
         printf("1\n");
         continue;
      }
      else if (n==-1)
      {
         printf("%d\n",t[k-1]-'0'&1?-1:1);
         continue;
      }
      for (int i=0;i<k;i++)
         m=m*10+t[i]-'0';
      if (!n)
      {
         if (l==1 && k==1 && t[0]=='0')
            break;
         printf("0\n");
         continue;
      }
      if (!m)
      {
         printf("1\n");
         continue;
      }
      long long ans=1;
      for (int i=1;i<=m;i++)
         ans*=n;
      printf("%lld\n",ans);
   }
   int time=0;
   while (gets(s))
      time++;
   printf("All Over. Exceeded %d lines!\n",time-1);
   system("pause");
   return(0);
}
