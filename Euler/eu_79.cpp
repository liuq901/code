#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[100],a[100][10];
int main()
{
   int n=50;
   for (int i=1;i<=50;i++)
      scanf("%s",a[i]);
   for (int x=1;;x++)
   {
      x=73162890;
      itoa(x,s,10);
      bool flag=true;
      int len=strlen(s);
      for (int i=1;i<=n;i++)
      {
         int now=0;
         for (int j=0;j<len;j++)
            if (s[j]==a[i][now])
            {
               now++;
               if (now==3)
                  break;
            }
         if (now!=3)
         {
            flag=false;
            break;
         }
      }
      if (flag)
      {
         printf("%d\n",x);
         break;
      }
   }
   system("pause");
   return(0);
}
