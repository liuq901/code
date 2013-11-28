#include <cstdio>
#include <cstdlib>
#include <cctype>
int sum,a[1000001],b[1000001];
int main()
{
   void read(int &);
   int work(int);
   int m,n;
   scanf("%d%d",&m,&n);
   int s,t;
   scanf("%d%*c",&t);
   s=1;
   for (int i=2;i<=n;i++)
   {
      int x;
      read(x);
      if (x!=t+1)
      {
         sum++;
         a[sum]=s;
         b[sum]=m-t-n+i-1;
         s=1;
      }
      else
         s++;
      t=x;
   }
   sum++;
   a[sum]=s;
   b[sum]=m-t;
   if (t==m-1)
      printf("%d\n",s);
   else
   {
      int x=0;
      for (int i=1;i<=sum;i++)
         if (b[i]&1)
            x^=a[i];
      if (!x)
         printf("0\n");
      else
         printf("%d\n",work(x));
   }
   system("pause");
   return(0);
}
void read(int &x)
{
   char c;
   x=0;
   while (1)
   {
      c=getchar();
      if (isdigit(c))
         x=x*10+c-'0';
      else
         return;
   }
}
int work(int x)
{
   int ans=0;
   for (int i=1;i<=sum;i++)
      if (b[i]&1)
      {
         if ((a[i]^x)<a[i])
            ans++;
      }
      else if (b[i]!=2)
      {
         int t;
         if (i==sum || b[i+1]+1!=b[i])
            t=0;
         else
            t=a[i+1];
         int p=(t^x)-t;
         if (p>0 && a[i]>=p)
            ans++;
      }
   return(ans);
}
