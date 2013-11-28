#include <cstdio>
#include <cstdlib>
#include <cstring>
int n;
char s[3001][2600];
int main()
{
   int i,j,p,l,k,ans,max,flag;
   char t;
   char ss[26]="reioxzsj";              
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
      scanf("%s",s[i]);
   l=200000000;
   max=0;
   for (i=1;i<=n;i++)
   {
      if (strlen(s[i])>=strlen(ss))
         for (j=0;j<strlen(s[i])-strlen(ss);j++)
         {
            flag=1;
            for (p=0;p<strlen(ss);p++)
               if (s[i][j+p]!=ss[p])
               {
                  flag=0;
                  break;
               }
            if (flag)
               break;
         }
      else
         flag=0;
      if (flag)
      {
         ans=0;
         for (j=0;j<strlen(s[i]);j++)
         {
            if (s[i][j]=='r' || s[i][j]=='p')
               ans+=5;
            if (s[i][j]=='p' && s[i][j+1]=='r')
               ans+=20;
            if (s[i][j]=='w' && s[i][j+1]=='o' && s[i][j+2]=='c')
               ans+=5;
         }
         if (ans>max)
         {
            max=ans;
            k=i;
            l=strlen(s[i]);
         }
         if (ans==max && strlen(s[i])<l)
         {
            k=i;
            l=strlen(s[i]);
         }
      }
   }
   printf("%s\n",s[k]);
   printf("%d\n",max);
   system("pause");
   return(0);
}
