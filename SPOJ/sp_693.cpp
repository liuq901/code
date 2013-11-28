#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[30010],ans[30010];
int main()
{
   int t;
   scanf("%d",&t);
   while (t--)
   {
      scanf("%s",s);
      int l=strlen(s);
      bool flag=true;
      for (int i=0;i<l;i++)
         if (flag==(s[i]=='0'))
         {
            for (int j=i;j<l;j++)
            {
               if (flag)
               {
                  ans[j]=s[j];
                  continue;
               }
               if (s[j]=='0')
                  ans[j]='1';
               else
                  ans[j]='0';
            }
            break;
         }
         else
         {
            ans[i]='1';
            flag=1-flag;
         }
      ans[l]='\0';
      printf("%s\n",ans);
   }
   system("pause");
   return(0);
}
