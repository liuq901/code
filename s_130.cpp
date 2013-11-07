#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,j,k;
   long long a[31];
   scanf("%d",&k);
   memset(a,0,sizeof(a));
   a[0]=a[1]=1;
   for (i=2;i<=k;i++)
      for (j=0;j<i;j++)
         a[i]+=a[j]*a[i-j-1];
   printf("%I64d %d\n",a[k],k+1);
   system("pause");
   return(0);
}
