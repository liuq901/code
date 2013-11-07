#include <cstdio>
#include <cstdlib>
#define SQR(x) ((x)*(x))
int f[1010];
int main()
{
   int ans=0,t;
   for (int i=1;i<=1000;i++)
      for (int j=i;j<=1000-i;j++)
         for (int k=j;k<=1000-i-j;k++)
         {
            if (i+j<=k)
               break;
            if (SQR(i)+SQR(j)==SQR(k))
            {
               f[i+j+k]++;
               if (f[i+j+k]>ans)
                  ans=f[i+j+k],t=i+j+k;
            }
         }
   printf("%d\n",t);
   system("pause");
   return(0);
}
