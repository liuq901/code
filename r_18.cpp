#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
const int q=32767,c[10]={1,10,20,23,26,28,49,100,126,260};
int ans,a[10];
char s[100];
int main()
{
   int count(int,int);
   int n,i,j,l,x;
   int f[30];
   char t[100];
   gets(t);
   l=strlen(t);
   for (i=0;i<10;i++)
   {
      memcpy(s,t,sizeof(t));
      ans=c[i];
      a[i]=count(0,l-1);
      while (a[i]<0)
         a[i]+=q;
   }
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      gets(t);
      l=strlen(t);
      int sum=0;
      for (j=0;j<l;j++)
      {
         if (t[j]=='(')
            sum++;
         if (t[j]==')')
            sum--;
      }
      if (sum==1)
      {
         l++;
         t[l-1]=')';
         t[l]='\0';
      }
      if (sum==-1)
      {
         memmove(t+1,t,sizeof(t));
         t[0]='(';
         l++;
      }
      for (j=0;j<10;j++)
      {
         ans=c[j];
         memcpy(s,t,sizeof(t));
         x=count(0,l-1);
         while (x<0)
            x+=q;
         if (x!=a[j])
            break;
      }
      if (j==10)
         f[i]=1;
      else
         f[i]=0;
   }
   for (i=1;i<=n;i++)
      if (f[i])
         printf("%c",i+'A'-1);
   printf("\n");
   system("pause");
   return(0);
}
int count(int l,int r)
{
   int calc(int,int);
   int i,j,k,t;
   char ch;
   i=l;
   j=r;
   while (1)
   {
      if (isdigit(s[i]) || s[i]=='a' || s[i]=='(' || s[i]==')')
         break;
      if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='^')
         break;
      i++;
   }
   while (1)
   {
      if (isdigit(s[j]) || s[j]=='a' || s[j]=='(' || s[j]==')')
         break;
      if (s[j]=='+' || s[j]=='-' || s[j]=='*' || s[j]=='^')
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
         return(count(i+1,j-1)%q);
   }
   if (i>l || j<r)
      return(count(i,j)%q);
   if (i==j && s[i]=='a')
      return(ans);
   k=-1;
   t=0;
   for (i=r;i>=l;i--)
   {
      if (s[i]=='(')
         t++;
      if (s[i]==')')
         t--;
      if (t!=0)
         continue;
      if (s[i]=='+' || s[i]=='-')
      {
         ch=s[i];
         k=i;
         break;
      }
      if ((k==-1 || ch=='^') && s[i]=='*')
      {
         ch='*';
         k=i;
      }
      if (k==-1 && s[i]=='^')
      {
         ch='^';
         k=i;
      }
   }
   t=0;
   if (k==-1)
   {
      for (i=l;i<=r;i++)
         t=t*10+s[i]-'0';
      return(t%q);
   }
   else if (ch=='-')
   {
      for (i=k+1;i<=r;i++)
      {
         if (s[i]=='(')
            t++;
         if (s[i]==')')
            t--;
         if (t!=0)
            continue;
         if (s[i]=='+')
            s[i]='-';
         else if (s[i]=='-')
            s[i]='+';
      }
      return((count(l,k-1)-count(k+1,r))%q);
   }
   else if (ch=='+')
      return((count(l,k-1)+count(k+1,r))%q);
   else if (ch=='*')
      return((count(l,k-1)*count(k+1,r))%q);
   else
      return(calc(count(l,k-1),count(k+1,r))%q);
}
int calc(int x,int y)
{
   int i,s;
   s=1;
   for (i=1;i<=y;i++)
      s=s*x%q;
   return(s);
}
