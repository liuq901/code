#include <cstdio>
#include <cstdlib>
const int a[]={1,1,2,6,24,120,720,5040,40320,362880};
bool f[1000001];
int main()
{
   void init();
   init();
   f[0]=false;
   while (1)
   {
      int x;
      scanf("%d",&x);
      if (x<0)
         break;
      printf("%s\n",f[x]?"YES":"NO");
   }
   system("pause");
   return(0);
}
void init()
{
   f[0]=true;
   for (int i=0;i<10;i++)
      for (int j=1000000;j>=a[i];j--)
         if (f[j-a[i]])
            f[j]=true;
}
