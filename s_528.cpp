#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
char s[1000010];
int dep=-1,i=0,pos=-1,m,l;
int main()
{
   void read(),fail(int);
   scanf("%d",&m);
   gets(s),gets(s);
   l=strlen(s);
   try
   {
      read();
      i++;
      if (i!=l)
         fail(i);
      if (l>m)
         fail(m);
      printf("ok\n");
   }
   catch (int x)
   {
      printf("Error at position %d!\n",x);
   }
   system("pause");
   return(0);
}
void read()
{
   void fail(int);
   dep++;
   if (isdigit(s[i]))
   {
      long long len=0;
      bool flag=false;
      if (s[i]=='0')
         flag=true;
      int t=i;
      while (isdigit(s[i]))
      {
         len=len*10+s[i]-'0';
         if (flag && i!=t)
            fail(i);
         if (i+len+dep+1>=m)
            fail(i);
         i++;
      }
      if (flag && len==1)
         fail(t+1);
      if (s[i]!=':')
         fail(i);
      for (int j=1;j<=len;j++)
      {
         i++;
         if (i==l)
            fail(i);
      }
      dep--;
   }
   else if (s[i]=='i')
   {
      if (i+dep+2>=m)
         fail(i);
      int t=++i;
      bool flag=s[i]=='0',tt=false;
      while (1)
      {
         if (s[i]=='e')
         {
            if (!tt)
               fail(i);
            dep--;
            return;
         }
         if (i+dep+1>=m)
            fail(i);
         if (!isdigit(s[i]))
            fail(i);
         if (flag && i!=t)
            fail(i);
         tt=true;
         i++;
      }
      if (flag && i-t!=1)
         fail(t+1);
   }
   else if (s[i]=='l')
   {
      if (i+dep+1>=m)
         fail(i);
      while (1)
      {
         i++;
         if (s[i]=='e')
         {
            dep--;
            return;
         }
         if (i+2+dep>=m)
            fail(i);
         read();
      }
   }
   else if (s[i]=='d')
   {
      if (i+dep+1>=m)
         fail(i);
      while (1)
      {
         i++;
         if (s[i]=='e')
         {
            dep--;
            return;
         }
         if (i+4+dep>=m)
            fail(i);
         read();
         i++;
         if (i+2+dep>=m)
            fail(i);
         read();
      }
   }
   else
      fail(i);
}
void fail(int x)
{
   x=min(x,m);
   throw(x);
}
