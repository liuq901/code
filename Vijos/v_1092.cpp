#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   long long jc(long long);
   long long i,j,k,n,m,x,y;
   long long flag[26];
   scanf("%I64d%I64d",&n,&m);
   memset(flag,0,sizeof(flag));
   m-=1;
   for (i=n;i>=2;i--)
   {
      x=jc(i-1);
      y=m/x+1;
      m=m%x;
      k=0;
      for (j=1;j<=n;j++)
      {
         if (!flag[j])
            k++;
         if (k==y)
         {
            printf("%I64d ",j);
            flag[j]=1;
            break;
         }
      }
   }
   for (i=1;i<=n;i++)
      if (!flag[i])
      {
         printf("%I64d\n",i);
         break;
      }
   system("pause");
   return(0);
}
long long jc(long long x)
{
   if (x==0)
      return(1);
   else
      return(x*jc(x-1));
}
