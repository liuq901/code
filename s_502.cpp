#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[10],ans[20];
int main()
{
   bool search(int,int);
   char s[20];
   scanf("%s",s);
   n=strlen(s);
   for (int i=0;i<n;i++)
      a[s[i]-'0']++;
   if (!search(1,0))
      printf("-1\n");
   system("pause");
   return(0);
}
bool search(int dep,int x)
{
   if (dep==n+1)
   {
      if (!x)
      {
         for (int i=1;i<=n;i++)
            printf("%d",ans[i]);
         printf("\n");
         return(true);
      }
      return(false);
   }
   for (int i=0;i<=9;i++)
   {
      if (!i && dep==1 || !a[i])
         continue;
      a[i]--;
      ans[dep]=i;
      if (search(dep+1,(x*10+i)%17))
         return(true);
      a[i]++;
   }
   return(false);
}
