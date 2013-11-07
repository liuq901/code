#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
char s[260];
int main()
{
   int address();
   int n,i;
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      gets(s);
      if (address())
         printf("YES\n");
      else
         printf("NO\n");
   }
   system("pause");
   return(0);
}
int address()
{
   int prefix(int,int),suffix(int,int);
   int i,k,l;
   k=-1;
   l=strlen(s);
   for (i=0;i<l;i++)
      if (s[i]=='@')
      {
         k=i;
         break;
      }
   if (k==-1)
      return(0);
   if (prefix(0,k-1) && suffix(k+1,l-1))
      return(1);
   else
      return(0);
}
int suffix(int l,int r)
{
   int prefix(int,int),domain(int,int);
   int i,k;
   if (l>r)
      return(0);
   k=-1;
   for (i=r;i>=l;i--)
      if (s[i]=='.')
      {
         k=i;
         break;
      }
   if (k==-1)
      return(0);
   if (prefix(l,k-1) && domain(k+1,r))
      return(1);
   else
      return(0);
}
int prefix(int l,int r)
{
   int word(int,int);
   int i,k;
   if (l>r)
      return(0);
   k=-1;
   for (i=l;i<=r;i++)
      if (s[i]=='.')
      {
         k=i;
         break;
      }
   if (k==-1 && word(l,r))
      return(1);
   else if (k==-1)
      return(0);
   else if (word(l,k-1) && prefix(k+1,r))
      return(1);
   else
      return(0);
}
int word(int l,int r)
{
   int i;
   if (l>r)
      return(0);
   for (i=l;i<=r;i++)
   {
      if (isalnum(s[i]) || s[i]=='-' || s[i]=='_')
         continue;
      return(0);
   }
   return(1);
}
int domain(int l,int r)
{
   int i;
   if (r-l!=1 && r-l!=2)
      return(0);
   for (i=l;i<=r;i++)
   {
      if (isalpha(s[i]))
         continue;
      return(0);
   }
   return(1);
}
