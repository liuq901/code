#include <cstdio>
#include <cstdlib>
int a[100001];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      bool flag=true;
      for (int i=1;i<=n;i++)
         if (a[a[i]]!=i)
         {
            flag=false;
            break;
         }
      printf("%s\n",flag?"ambiguous":"not ambiguous");
   }
   system("pause");
   return(0);
}
