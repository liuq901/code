#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int work(char *);
   void print(int);
   int a,b;
   char s[260];
   while (1)
   {
      scanf("%s",s);
      if (s[0]=='#')
         break;
      a=work(s);
      scanf("%s",s);
      b=work(s);
      a-=b;
      if (a<0)
         a=-a;
      print(a);
   }
   system("pause");
   return(0);
}
int work(char *s)
{
   int i,l,ans;
   ans=0;
   l=strlen(s);
   for (i=0;i<l;i++)
   {
      if (s[i]=='M')
         ans+=1000;
      if (s[i]=='D')
         ans+=500;
      if (s[i]=='C' && (s[i+1]=='M' || s[i+1]=='D'))
         ans-=100;
      if (s[i]=='C' && (s[i+1]!='M' && s[i+1]!='D'))
         ans+=100;
      if (s[i]=='L')
         ans+=50;
      if (s[i]=='X' && (s[i+1]=='C' || s[i+1]=='L'))
         ans-=10;
      if (s[i]=='X' && (s[i+1]!='C' && s[i+1]!='L'))
         ans+=10;
      if (s[i]=='V')
         ans+=5;
      if (s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X'))
         ans--;
      if (s[i]=='I' && (s[i+1]!='V' && s[i+1]!='X'))
         ans++;
   }
   return(ans);
}
void print(int n)
{
   int i,x;
   if (n==0)
   {
      printf("ZERO\n");
      return;
   }
   x=n/1000;
   n%=1000;
   for (i=1;i<=x;i++)
      printf("M");
   x=n/100;
   n%=100;
   if (x==9)
   {
      printf("CM");
      x-=9;
   }
   if (x>=5)
   {
      printf("D");
      x-=5;
   }
   if (x==4)
   {
      printf("CD");
      x-=4;
   }
   for (i=1;i<=x;i++)
      printf("C");
   x=n/10;
   n%=10;
   if (x==9)
   {
      printf("XC");
      x-=9;
   }
   if (x>=5)
   {
      printf("L");
      x-=5;
   }
   if (x==4)
   {
      printf("XL");
      x-=4;
   }
   for (i=1;i<=x;i++)
      printf("X");
   x=n;
   if (x==9)
   {
      printf("IX");
      x-=9;
   }
   if (x>=5)
   {
      printf("V");
      x-=5;
   }
   if (x==4)
   {
      printf("IV");
      x-=4;
   }
   for (i=1;i<=x;i++)
      printf("I");
   printf("\n");
}
