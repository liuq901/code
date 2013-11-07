#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[100000];
int main()
{
   int i,t,n,max;
   int a[27];
   char ch;
   n=0;
   while ((ch=getchar())!=EOF)
   {
      n++;
      s[n]=ch;
   }
   memset(a,0,sizeof(a));
   for (i=1;i<=n;i++)
   {
      if (s[i]>='A' && s[i]<='Z')
         a[s[i]-'A'+1]++;
      if (s[i]>='a' && s[i]<='z')
         a[s[i]-'a'+1]++;
   }
   max=0;
   t=0;
   for (i=1;i<=26;i++)
      if (a[i]>max)
      {
         t=i;
         max=a[i];
      }
   t-=5;
   for (i=1;i<=n;i++)
   {
      if (s[i]>='A' && s[i]<='Z')
      {
         s[i]-=t;
         if (s[i]<'A')
            s[i]+=26;
         if (s[i]>'Z')
            s[i]-=26;
      }
      if (s[i]>='a' && s[i]<='z')
      {
         s[i]-=t;
         if (s[i]<'a')
            s[i]+=26;
         if (s[i]>'z')
            s[i]-=26;
      }
      printf("%c",s[i]);
   }
   system("pause");
   return(0);
}
