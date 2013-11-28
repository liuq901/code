#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
char S[100],s[10000010];
string t;
int main()
{
   void itoa(int,char *);
   int n;
   scanf("%d",&n);
   gets(s),gets(s);
   char ch=s[0];
   int num=1,pos=0;
   for (int i=1;i<=n;i++)
   {
      if (s[i]!=ch)
      {
         itoa(num,S);
         t+=S;
         t+=ch;
         num=1,ch=s[i];
      }
      else
         num++;
      if (t.size()>n)
         break;
   }
   printf("%s\n",t.size()<n?t.c_str():s);
   system("pause");
   return(0);
}
void itoa(int x,char *s)
{
   int n=0;
   while (x)
   {
      s[n++]=x%10+'0';
      x/=10;
   }
   reverse(s,s+n);
   s[n]='\0';
}
