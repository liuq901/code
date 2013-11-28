#include <cstdio>
#include <cstdlib>
int main()
{
   int n;
   while (scanf("%d",&n)==1)
   {
      int s0,s1,t0,t1;
      s0=s1=t0=t1=0;
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d",&x);
         if (x&1)
            s0+=x,t0++;
         else
            s1+=x,t1++;
      }
      if (t0)
         printf("%.3f ",double(s0)/t0);
      else
         printf("None ");
      if (t1)
         printf("%.3f\n",double(s1)/t1);
      else
         printf("None\n");
   }
   system("pause");
   return(0);
}
