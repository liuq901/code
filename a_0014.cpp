#include <cstdio>
#include <cstdlib>
#define SQR(x) ((x)*(x))
int main()
{
   int x;
   while (scanf("%d",&x)==1)
   {
      int ans=0;
      for (int i=x;i<600;i+=x)
         ans+=SQR(i)*x;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
