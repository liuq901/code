#include <cstdio>
#include <cstdlib>
#include <cstring>
class bignum
{
   int a[110];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
   }
   bignum(int x)
   {
      memset(a,0,sizeof(a));
      while (x)
      {
         a[++a[0]]=x%10;
         x/=10;
      }
   }
   bignum(char *s)
   {
      memset(a,0,sizeof(a));
      a[0]=strlen(s);
      for (int i=1;i<=a[0];i++)
         a[i]=s[a[0]-i]-'0';
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
bignum operator *(bignum a,int b)
{
   bignum c;
   int x=0;
   c[0]=a[0];
   for (int i=1;i<=c[0];i++)
   {
      c[i]=a[i]*b+x;
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
   for (int i=1;i<=a[0];i++)
   {
      c[i]+=a[i]-b[i];
      if (c[i]<0)
      {
         c[i]+=10;
         c[i+1]--;
      }
   }
   while (!c[c[0]] && c[0]>1)
      c[0]--;
   return(c);
}
int main()
{
   int t;
   char s[110];
   while (scanf("%s",s)!=EOF)
   {
      if (s[0]=='1' && s[1]=='\0')
         printf("1\n");
      else
      {
         bignum ans(s);
         ans=ans*2-bignum(2);
         ans.print();
      }
   }
   system("pause");
   return(0);
}
