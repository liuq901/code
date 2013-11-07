#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
int main()
{
   int check(int);
   int n,i,j,k,t,flag;
   int f[100001];
   memset(f,0,sizeof(f));
   for (i=2;i<=100000;i++)
   {
      if (f[i])
         continue;    
      f[i]=0;
      j=1;
      while (1)
      {
         j++;
         if (i*j>100000)
            break;
         f[i*j]=1;
      }
   }
   f[1]=1;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d",&k);
      flag=0;
      for (j=2;j<=sqrt(k)+1;j++)
      {
         if (k%j!=0)
            continue;
         t=k/j;
         if (f[j])
            continue;
         if (t<=100000 && !f[t])
         {
            flag=1;
            break;
         }
         if (t>100000 && check(t))
         {
            flag=1;
            break;
         }
      }
      if (flag)
         printf("Yes\n");
      else
         printf("No\n");
   }
   system("pause");
   return(0);
}
int check(int t)
{
   int i;
   for (i=2;i<=sqrt(t)+1;i++)
      if (t%i==0)
         return(0);
   return(1);
}
