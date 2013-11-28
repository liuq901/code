#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[2010];
int main()
{
   bool work(int,int);
   int test_id=0;
   while (gets(s))
   {
      int l=strlen(s);
      printf("Expression %d: %c\n",++test_id,work(0,l-1)?'V':'F');
   }
   system("pause");
   return(0);
}
bool work(int l,int r)
{
   bool check(char);
   if (!check(s[l]))
      return(work(l+1,r));
   if (!check(s[r]))
      return(work(l,r-1));
   if (l==r)
      return(s[l]=='V');
   int t=0;
   for (int i=r;i>=l;i--)
   {
      if (s[i]==')')
         t++;
      if (s[i]=='(')
         t--;
      if (s[i]=='|' && !t)
         return(work(l,i-1) || work(i+1,r));
   }
   t=0;
   for (int i=r;i>=l;i--)
   {
      if (s[i]==')')
         t++;
      if (s[i]=='(')
         t--;
      if (s[i]=='&' && !t)
         return(work(l,i-1) && work(i+1,r));
   }
   t=0;
   for (int i=l;i<=r;i++)
   {
      if (s[i]=='(')
         t++;
      if (s[i]==')')
         t--;
      if (s[i]=='!' && !t)
         return(!work(i+1,r));
   }
   return(work(l+1,r-1));
}
bool check(char x)
{
   if (x=='V' || x=='F' || x=='&' || x=='|' || x=='!' || x=='(' || x==')')
      return(true);
   return(false);
}
