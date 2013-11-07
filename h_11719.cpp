#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
int p[26],f[26],g[26];
int main()
{
   bool search(int);
   while (1)
   {
      int n;
      scanf("%d%*c",&n);
      if (!n)
         break;
      char s[26];
      scanf("%s",s);
      int l=strlen(s);
      if (l%3)
      {
         printf("No\n");
         continue;
      }
      int a[10]={0},b[10]={0};
      for (int i=0;i<l;i++)
         if (isupper(s[i]))
            a[s[i]-'A']++;
         else
            b[s[i]-'a']++;
      for (int i=0;i<10;i++)
      {
         if (a[i]==3)
            a[i]=0;
         if (b[i]==3)
            b[i]=0;
      }
      p[0]=f[0]=g[0]=0;
      for (int i=0;i<10;i++)
      {
         for (int j=1;j<=a[i];j++)
            p[++p[0]]=i;
         for (int j=1;j<=b[i];j++)
            p[++p[0]]=i+10;
      }
      printf("%s\n",search(1)?"Yes":"No");
   }
   system("pause");
   return(0);
}
bool search(int dep)
{
   if (dep==p[0]+1)
   {
      if (f[0]%3)
         return(false);
      int a[15]={0},b[15]={0};
      for (int i=1;i<=f[0];i++)
         a[f[i]%10]++;
      for (int i=0;i<10;i++)
      {
         if (a[i]%3)
            return(false);
         a[i]=0;
      }
      for (int i=1;i<=g[0];i++)
         if (g[i]<10)
            a[g[i]]++;
         else
            b[g[i]-10]++;
      for (int i=0;i<=12;i++)
      {
         if (a[i]<0)
            return(false);
         a[i+1]-=a[i],a[i+2]-=a[i],a[i]=0;
         if (b[i]<0)
            return(false);
         b[i+1]-=b[i],b[i+2]-=b[i],b[i]=0;
      }
      return(true);
   }
   f[++f[0]]=p[dep];
   if (search(dep+1))
      return(true);
   f[0]--;
   g[++g[0]]=p[dep];
   if (search(dep+1))
      return(true);
   g[0]--;
   return(false);
}
