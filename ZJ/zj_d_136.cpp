#include <cstdio>
#include <cstdlib>
#include <cctype>
unsigned long long a[1000010],b[1000010];
int main()
{
   unsigned long long init();
   int n,m,i,j,s,p,q;
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
   {
      for (j=1;j<=m;j++)
         a[j]=init();
      for (j=1;j<=m;j++)
         b[j]=init();
      s=0;
      p=q=1;
      while (p<=m && q<=m)
         if (a[p]==b[q])
         {
            p++;
            q++;
            s++;
         }
         else if (a[p]<b[q])
            p++;
         else
            q++;
      printf("%d\n",s);
   }
   system("pause");
   return(0);
}
unsigned long long init()
{
   char ch;
   unsigned long long x;
   while (1)
   {
      ch=getchar();
      if (isdigit(ch))
      {
         x=ch-'0';
         break;
      }
   }
   while (1)
   {
      ch=getchar();
      if (ch==' ' || ch=='\n')
         break;
      x=x*10+ch-'0';
   }
   return(x);
}
