#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[1010];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      memset(a,0,sizeof(a));
      bool flag=true;
      for (int i=1;i<=n;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         if (i+y>0 && i+y<=n && !a[i+y])
            a[i+y]=x;
         else
            flag=false;
      }
      if (!flag)
         printf("-1\n");
      else
         for (int i=1;i<=n;i++)
            printf("%d%c",a[i],i==n?'\n':' ');
   }
   system("pause");
   return(0);
}
