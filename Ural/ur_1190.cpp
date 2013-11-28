#include <cstdio>
#include <cstdlib>
int a[5001];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      int p;
      scanf("%*s %d",&p);
      if (!p)
         a[i]=-1;
      else
         scanf("%d",&a[i]);
   }
   int t=1,s=0;
   for (int i=n;i>=1;i--)
   {
      if (a[i]!=-1)
         t=a[i];
      s+=t;
   }
   if (s>10000)
      printf("NO\n");
   else
   {
      s=0;
      t=10000;
      for (int i=1;i<=n;i++)
      {
         if (a[i]!=-1)
            t=a[i];
         s+=t;
      }
      if (s<10000)
         printf("NO\n");
      else
         printf("YES\n");
   }
   system("pause");
   return(0);
}
