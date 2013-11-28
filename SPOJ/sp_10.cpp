#include <cstdio>
#include <cstdlib>
#include <cstring>
char s[260];
int a[260],f[260];
int main()
{
   void make(),work(),print();
   int n,i;
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%s",s);
      make();
      work();
      print();
   }
   system("pause");
   return(0);
}
void make()
{
   int i,l;
   int t[260];
   memset(a,0,sizeof(a));
   memset(t,0,sizeof(t));
   l=strlen(s);
   for (i=0;i<l;i++)
   {
      if (s[i]=='(')
      {
         t[0]++;
         t[t[0]]=i;
      }
      else if (s[i]==')')
      {
         a[i]=t[t[0]];
         a[t[t[0]]]=i;
         t[0]--;
      }
      else
         a[i]=t[0];
   }
}
void work()
{
   void check(int);
   int i,l;
   memset(f,0,sizeof(f));
   l=strlen(s);
   for (i=0;i<l;i++)
      if (s[i]=='(')
         check(i);
}
void check(int x)
{
   int i,t,k,l;
   char c1,c2,c3;
   c1=c2=c3=' ';
   t=x;
   while (1)
   {
      t--;
      if (t<0)
         break;
      if (s[t]=='(' && !f[t])
         break;
      if (s[t]=='+' || s[t]=='-' || s[t]=='*' || s[t]=='/')
      {
         c1=s[t];
         break;
      }
   }
   t=0;
   for (i=x+1;i<=a[x]-1;i++)
   {
      if (s[i]=='(')
         t++;
      if (s[i]==')')
         t--;
      if (t!=0)
         continue;
      if (s[i]=='*' || s[i]=='/')
         c2=s[i];
      if (s[i]=='+' || s[i]=='-')
      {
         c2=s[i];
         break;
      }
   }
   t=a[x];
   l=strlen(s);
   while (1)
   {
      t++;
      if (t>=l)
         break;
      if (s[t]==')' && !f[t])
         break;
      if (s[t]=='+' || s[t]=='-' || s[t]=='*' || s[t]=='/')
      {
         c3=s[t];
         break;
      }
   }
   if (c1==' ' || c1=='+')
   {
      if (c3==' ' || c3=='+' || c3=='-')
      {
         f[x]=1;
         f[a[x]]=1;
         return;
      }
      if (c2==' ' || c2=='*' || c2=='/')
      {
         f[x]=1;
         f[a[x]]=1;
         return;
      }
      return;
   }
   if (c1=='-')
   {
      if (c2==' ' || c2=='*' || c2=='/')
      {
         f[x]=1;
         f[a[x]]=1;
         return;
      }
      return;
   }
   if (c1=='*')
   {
      if (c2==' ' || c2=='*' || c2=='/')
      {
         f[x]=1;
         f[a[x]]=1;
         return;
      }
      return;
   }
   if (c1=='/')
   {
      if (c2==' ')
      {
         f[x]=1;
         f[a[x]]=1;
      }
      return;
   }
}
void print()
{
   int i,l;
   l=strlen(s);
   for (i=0;i<l;i++)
      if (!f[i])
         printf("%c",s[i]);
   printf("\n");
}
