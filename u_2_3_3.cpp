/*
ID: liuq9011
LANG: C++
TASK: zerosum
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int n;
char s[10];
int main()
{
   in=fopen("zerosum.in","r");
   out=fopen("zerosum.out","w");
   void search(char,int);
   fscanf(in,"%d",&n);
   s[1]=' ';
   search(' ',1);
   s[1]='+';
   search('+',1);
   s[1]='-';
   search('-',1);
   fclose(in),fclose(out);
   return(0);
}
void search(char ch,int t)
{
   void print();
   if (t==n-1)
   {
      print();
      return;
   }
   s[t+1]=' ';
   search(' ',t+1);
   s[t+1]='+';
   search('+',t+1);
   s[t+1]='-';
   search('-',t+1);
}
void print()
{
   int i,t,ans;
   int a[10];
   char b[10];
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   a[1]=1;
   t=1;
   for (i=2;i<=n;i++)
      if (s[i-1]==' ')
         a[t]=a[t]*10+i;
      else
      {
         t++;
         a[t]=i;
         b[t]=s[i-1];
      }
   ans=a[1];
   for (i=2;i<=t;i++)
      if (b[i]=='+')
         ans+=a[i];
      else
         ans-=a[i];
   if (ans==0)
   {
      for (i=1;i<=n-1;i++)
         fprintf(out,"%d%c",i,s[i]);
      fprintf(out,"%d\n",n);
   }
}
