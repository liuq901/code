#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[10010];
int main()
{
   scanf("%s",s);
   int n=strlen(s),pos=-1,sum=0,num,now=0;
   for (int i=0;i<n;i++)
   {
      if (s[i]=='(' && sum>0)
         pos=i,num=now;
      sum+=s[i]=='('?1:-1;
      now+=s[i]=='(';
   }
   if (pos==-1)
      printf("No solution\n");
   else
   {
      for (int i=0;i<pos;i++)
         printf("%c",s[i]);
      printf(")");
      int t=0,limit=(n>>1)-num;
      for (int i=pos+1;i<n;i++)
         printf("%c",++t<=limit?'(':')');
      printf("\n");
   }
   system("pause");
   return(0);
}
