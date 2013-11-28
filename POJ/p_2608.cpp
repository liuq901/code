#include <cstdio>
#include <cstdlib>
#include <cstring>
const int a[26]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
int main()
{
   char s[100];
   while (scanf("%s",s+1)!=EOF)
   {
      s[0]='a';
      int l=strlen(s);
      for (int i=1;i<l;i++)
      {
         if (a[s[i]-'A']==a[s[i-1]-'A'])
            continue;
         if (a[s[i]-'A']!=0)
            printf("%d",a[s[i]-'A']);
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
