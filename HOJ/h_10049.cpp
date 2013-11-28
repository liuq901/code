#include <cstdio>
#include <cstdlib>
char s[100];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%s",s);
      int a,b,c,d;
      a=b=c=d=0;
      for (int i=0;i<8;i++)
         a=(a<<1)+s[i]-'0';
      for (int i=8;i<16;i++)
         b=(b<<1)+s[i]-'0';
      for (int i=16;i<24;i++)
         c=(c<<1)+s[i]-'0';
      for (int i=24;i<32;i++)
         d=(d<<1)+s[i]-'0';
      printf("%d.%d.%d.%d\n",a,b,c,d);
   }
   system("pause");
   return(0);
}
