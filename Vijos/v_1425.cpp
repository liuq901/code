#include <cstdio>
#include <cstdlib>
#include <cstring>
int l,ans,n;
char ch,s[260],a[1000000];
int main()
{
   void check();
   char ch;
   scanf("%s%*c",s);
   n=0;
   ans=0;
   l=strlen(s);
   while (scanf("%c",&ch)!=EOF)
   {
      if (ch=='\n')
         break;
      n++;
      a[n]=ch;
      check();
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void check()
{
   int i,j,flag;
   if (n<l)
      return;
   j=n+1;
   flag=1;
   for (i=l-1;i>=0;i--)
   {
      j--;
      if (a[j]!=s[i])
      {
         flag=0;
         break;
      }
   }
   if (flag)
   {
      ans++;
      n-=l;
   }
}
