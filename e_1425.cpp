#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[100010],t[100010];
int main()
{
   while (scanf("%s%s",s,t)==2)
   {
      int n=strlen(t),now=0;
      for (int i=0;i<n;i++)
         if (t[i]==s[now])
            now++;
      printf("%s\n",now==strlen(s)?"Yes":"No");
   }
   system("pause");
   return(0);
}
