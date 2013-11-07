#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char s[2][26];
   scanf("%s%s",s[0],s[1]);
   int l1=strlen(s[0]),l2=strlen(s[1]);
   int sum=0;
   for (int i=0;i<l1;i++)
      for (int j=0;j<l2;j++)
         sum+=(s[0][i]-'0')*(s[1][j]-'0');
   printf("%d\n",sum);
   system("pause");
}
