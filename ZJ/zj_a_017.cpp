#include <cstdio>
#include <cstdlib>
#include <cctype>
char s[100];
int main()
{
   int count(int,int);
   int l;
   char ch;
   l=0;
   while (scanf("%c",&ch)!=EOF)
   {
      if (ch=='\n')
      {
         printf("%d\n",count(1,l));
         l=0;
      }
      l++;
      s[l]=ch;
   }
   system("pause");
   return(0);
}
int count(int l,int r)
{
   int i,j,k,t;
   int q[260];
   char ch;
   i=l;
   j=r;
   while (1)
   {
      if (isdigit(s[i]) || s[i]=='(' || s[i]==')')
         break;
      if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
         break;
      i++;
   }
   while (1)
   {
      if (isdigit(s[j]) || s[j]=='(' || s[j]==')')
         break;
      if (s[j]=='+' || s[j]=='-' || s[j]=='*'  || s[j]=='/')
         break;
      j--;
   }
   if (s[i]=='(' && s[j]==')')
   {
      t=0;
      for (k=i;k<=j;k++)
      {
         if (s[k]=='(')
            t++;
         if (s[k]==')')
            t--;
         if (t==0)
            break;
      }
      if (k==j)
         return(count(i+1,j-1));
   }
   if (i>l || j<r)
      return(count(i,j));
   t=q[0]=0;
   for (i=l;i<=r;i++)
   {
      if (s[i]=='(')
         t++;
      if (s[i]==')')
         t--;
      if (t!=0)
         continue;
      if (s[i]=='+' || s[i]=='-')
      {
         q[0]++;
         q[q[0]]=i;
      }
   }
   if (q[0]!=0)
   {
      t=count(l,q[1]-1);
      for (i=1;i<=q[0]-1;i++)
      {
         if (s[q[i]]=='+')
            t+=count(q[i]+1,q[i+1]-1);
         if (s[q[i]]=='-')
            t-=count(q[i]+1,q[i+1]-1);
      }
      if (s[q[q[0]]]=='+')
         t+=count(q[q[0]]+1,r);
      if (s[q[q[0]]]=='-')
         t-=count(q[q[0]]+1,r);
      return(t);
   }
   t=q[0]=0;
   for (i=l;i<=r;i++)
   {
      if (s[i]=='(')
         t++;
      if (s[i]==')')
         t--;
      if (t!=0)
         continue;
      if (s[i]=='*' || s[i]=='/' || s[i]=='%')
      {
         q[0]++;
         q[q[0]]=i;
      }
   }
   if (q[0]!=0)
   {
      t=count(l,q[1]-1);
      for (i=1;i<=q[0]-1;i++)
      {
         if (s[q[i]]=='*')
            t*=count(q[i]+1,q[i+1]-1);
         if (s[q[i]]=='/')
            t/=count(q[i]+1,q[i+1]-1);
         if (s[q[i]]=='%')            
            t%=count(q[i]+1,q[i+1]-1);
      }
      if (s[q[q[0]]]=='*')
         t*=count(q[q[0]]+1,r);
      if (s[q[q[0]]]=='/')
         t/=count(q[q[0]]+1,r);
      if (s[q[q[0]]]=='%')
         t%=count(q[q[0]]+1,r);
      return(t);
   }
   t=0;
   for (i=l;i<=r;i++)
      t=t*10+s[i]-'0';
   return(t);
}
