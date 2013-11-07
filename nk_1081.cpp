#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[100000],t[100000];
int main()
{
   while (scanf("%s%s",s,t)==2)
   {
      int n=strlen(s),m=strlen(t),now=0;
      for (int i=0;i<n;i++)
      {
         for (int &j=now;j<m;j++)
            if (s[i]==t[j])
               break;
         now++;
      }
      printf("%s\n",now<=m?"Yes":"No");
   }
   system("pause");
   return(0);
}
