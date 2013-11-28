#include <cstdio>
#include <cstdlib>
#include <cstring>
class bignum
{
   int a[1100];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
      a[0]=1;
   }
   void init(char *s)
   {
      int l=strlen(s);
      a[0]=l;
      for (int i=0;i<l;i++)
         a[l-i]=s[i]-'0';
   }
   void print()
   {
      for (int i=a[0];i>=1;i--)
         printf("%d",a[i]);
      printf("\n");
   }
   int &operator [](int x)
   {
      return(a[x]);
   }
};
bignum operator +(bignum a,bignum b)
{
   bignum c;
   c[0]=a[0];
   int x=0;
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]+b[i]+x;
      x=c[i]/10;
      c[i]%=10;
   }
   while (x)
   {
      c[++c[0]]=x%10;
      x/=10;
   }
   return(c);
}
bignum operator -(bignum a,bignum b)
{
   bignum c;
   c[0]=a[0];
   for (int i=1;i<=c[0];i++)
   {
      c[i]+=a[i]-b[i];
      if (c[i]<0)
      {
         c[i+1]--;
         c[i]+=10;
      }
   }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   return(c);
}
bignum operator /(bignum a,int b)
{
   bignum c;
   c[0]=a[0];
   int x=0;
   for (int i=c[0];i>=1;i--)
   {
      c[i]=(a[i]+x*10)/b;
      x=(a[i]+x*10)%b;
   }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   return(c);
}
int main()
{
   char s[1100],t[1100];
   for (int i=1;i<=10;i++)
   {
      bignum a,b,c;
      scanf("%s%s",s,t);
      a.init(s),b.init(t);
      c=(a+b)/2;
      c.print();
      c=(a-b)/2;
      c.print();
   }
   system("pause");
   return(0);
}
