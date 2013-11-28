#include <cstdio>
#include <cstdlib>
int main()
{
   int n,i,s;
   long long ans;
   char ch;
   scanf("%d",&n);
   i=s=0;
   ans=0;
   while (i!=n)
   {
      scanf("%c",&ch);
      if (ch=='>')
      {
         i++;
         s++;
      }
      if (ch=='<')
      {
         i++;
         ans+=s;
      }
   }
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
