#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[5],flag[5];
int main()
{
   void search(int,double);
   char s[4][10];
   int i;
   for (i=0;i<=3;i++)
   {
      scanf("%s",s[i]);
      if (strlen(s[i])==2)
         a[i+1]=10;
      else
      {
         if (s[i][0]>='0' && s[i][0]<='9')
            a[i+1]=s[i][0]-'0';
         if (s[i][0]=='A')
            a[i+1]=1;
         if (s[i][0]=='J')
            a[i+1]=11;
         if (s[i][0]=='Q')
            a[i+1]=12;
         if (s[i][0]=='K')
            a[i+1]=13;
      }
   }
   memset(flag,0,sizeof(flag));
   for (i=1;i<=4;i++)
   {
      flag[i]=1;
      search(1,a[i]);
      flag[i]=0;
   }
   printf("0\n");
   system("pause");
   return(0);
}
void search(int n,double x)
{
   void print();
   int i;
   for (i=1;i<=4;i++)
      if (!flag[i])
      {
         if (n==3)
         {
            if (a[i]+x==24 || a[i]-x==24 || x-a[i]==24)
               print();
            if (a[i]*x==24 || x/a[i]==24)
               print();
            if (x!=0 && a[i]/x==24)
               print();
         }
         flag[i]=1;
         search(n+1,x+a[i]);
         search(n+1,x-a[i]);
         search(n+1,a[i]-x);
         search(n+1,x*a[i]);
         search(n+1,x/a[i]);
         if (x!=0)
            search(n+1,a[i]/x);
         flag[i]=0;
      }
}
void print()
{
   printf("1\n");
   system("pause");
   exit(0);
}
