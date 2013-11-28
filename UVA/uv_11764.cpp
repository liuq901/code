#include <cstdio>
#include <cstdlib>
int a[60];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      int x,y;
      x=y=0;
      for (int i=1;i<n;i++)
         if (a[i]<a[i+1])
            x++;
         else if (a[i]>a[i+1])
            y++;
      static int id=0;
      printf("Case %d: %d %d\n",++id,x,y);
   }
   system("pause");
   return(0);
}
