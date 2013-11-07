#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int max(int,int);
   int i,x,l,n;
   int a[110],b[110];
   char s[110],t[110];
   scanf("%s%s",s,t);
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   l=strlen(s);
   for (i=1;i<=l;i++)
      a[i]=s[l-i]-'0';
   a[0]=l;
   l=strlen(t);
   for (i=1;i<=l;i++)
      b[i]=t[l-i]-'0';
   b[0]=l;
   x=0;
   n=max(a[0],b[0]);
   for (i=1;i<=n;i++)
   {
      a[i]+=b[i]+x;
      x=a[i]/10;
      a[i]%=10;
   }
   a[0]=n;
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10;
      x/=10;
   }
   for (i=a[0];i>=1;i--)
      printf("%d",a[i]);
   printf("\n");
   system("pause");
   return(0);
}
int max(int x,int y)
{
   if (x>y)
      return(x);
   else
      return(y);
}
