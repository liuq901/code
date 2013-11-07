#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[300],ans[300];
int main()
{
   scanf("%s",s);
   int l=strlen(s),n,k=0;
   scanf("%d",&n);
   for (int i=1;i<=l-n;i++)
   {
      int min=260,t;
      for (int j=k;j<n+i;j++)
         if (s[j]<min)
         {
            min=s[j];
            t=j;
         }
      ans[i-1]=s[t];
      k=t+1;
   }
   ans[l-n]='\0';
   while (ans[0]=='0' && strlen(ans)!=1)
      memmove(ans,ans+1,sizeof(char)*strlen(ans));
   printf("%s\n",ans);
   system("pause");
   return(0);
}
