#include <cstdio>
#include <cstdlib>
int main()
{
   int T;
   scanf("%d",&T);
   printf("Lumberjacks:\n");
   while (T--)
   {
      int a[20];
      for (int i=1;i<=10;i++)
         scanf("%d",&a[i]);
      bool p,q;
      p=q=true;
      for (int i=2;i<=10;i++)
      {
         if (a[i]>a[i-1])
            p=false;
         if (a[i]<a[i-1])
            q=false;
      }
      printf("%s\n",p || q?"Ordered":"Unordered");
   }
   system("pause");
   return(0);
}
