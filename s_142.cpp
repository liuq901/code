#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[500001],f[600000];
int main()
{
   int work(int);
   int i;
   char ch;
   scanf("%d%*c",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%c",&ch);
      a[i]=ch-'a';
   }
   i=0;
   while (1)
   {
      i++;
      if (work(i))
         break;
   }
   system("pause");
   return(0);
}
int work(int t)
{
   void print(int,int);
   int i,j,s,flag;
   memset(f,0,sizeof(f));
   for (i=1;i<=n-t+1;i++)
   {
      s=0;
      for (j=1;j<=t;j++)
         s=s*2+a[i+j-1];
      f[s]=1;
   }
   s=1<<t;
   flag=0;
   for (i=0;i<=s-1;i++)
      if (!f[i])
      {
         flag=1;
         print(t,i);
         break;
      }
   return(flag);
}
void print(int t,int x)
{
   int i;
   int ans[26];
   printf("%d\n",t);
   for (i=1;i<=t;i++)
   {
      ans[i]=x%2;
      x/=2;
   }
   for (i=t;i>=1;i--)
      printf("%c",ans[i]+'a');
   printf("\n");
}
