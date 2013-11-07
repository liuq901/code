#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   while (1)
   {
      char s[5010];
      scanf("%s",s+1);
      int l=strlen(s+1);
      if (l==1 && s[1]=='0')
         break;
      long long f[5001]={0};
      f[0]=1;
      for (int i=1;i<=l;i++)
      {
         if (s[i]!='0')
            f[i]+=f[i-1];
         if (i!=1)
         {
            int p=(s[i-1]-'0')*10+s[i]-'0';
            if (p>=10 && p<=26)
               f[i]+=f[i-2];
         }
      }
      printf("%lld\n",f[l]);
   }
   system("pause");
   return(0);
}
