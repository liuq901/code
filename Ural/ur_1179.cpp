#include <cstdio>
#include <cstdlib>
#include <cctype>
bool b[40];
int a[40];
int main()
{
   void push(int),pop(int);
   char ch;
   while (scanf("%c",&ch)!=EOF)
   {
      if (isdigit(ch) || isupper(ch))
      {
         int x;
         if (isdigit(ch))
            x=ch-'0';
         else
            x=ch-'A'+10;
         for (int i=2;i<=36;i++)
            if (i>x)
               push(i);
            else
               pop(i);
         continue;
      }
      for (int i=2;i<=36;i++)
         pop(i);
   }
   int ans=2;
   for (int i=3;i<=36;i++)
      if (a[i]>a[ans])
         ans=i;
   printf("%d %d\n",ans,a[ans]);
   system("pause");
   return(0);
}
void push(int x)
{
   b[x]=true;
}
void pop(int x)
{
   if (b[x])
      a[x]++;
   b[x]=false;
}
