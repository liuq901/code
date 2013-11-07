#include <cstdio>
#include <cstdlib>
char s[100010];
int a[100010];
int main()
{
   int n;
   scanf("%d%s",&n,s+1);
   for (int i=1;i<=n;i++)
      if (s[i]=='u')
         a[i]=a[i-1]+1;
      else if (s[i]=='d')
         a[i]=a[i-1]-1;
      else
         a[i]=a[i-1];
   int k=-1;
   for (int i=n-1;i>1;i--)
   {
      if (s[i]=='u')
         continue;
      if (a[i]+1<=n-i)
      {
         k=i;
         break;
      }
   }
   if (k==-1)
      printf("No solution");
   else
   {
      for (int i=1;i<k;i++)
         printf("%c",s[i]);
      if (s[k]=='d')
         printf("h");
      else
         printf("u");
      int now=k;
      for (int i=1;i<=a[k];i++)
      {
         printf("d");
         now++;
      }
      while (now+2<n)
      {
         printf("du");
         now+=2;
      }
      if (now==n-2)
         printf("h");
      printf("d\n");
   }
   system("pause");
   return(0);
}
