#include <cstdio>
#include <cstdlib>
#include <cstring>
const int c[11]={0,1,5,10,20,50,100,200,500,1000,2000};
long long f[50001];
int main()
{
   char ch;
   int i,j,n,x,k;
   memset(f,0,sizeof(f));
   f[0]=1;
   for (i=1;i<=10;i++)
      for (j=0;j<=50000;j++)
      {
         if (j<c[i])
            continue;
         f[j]+=f[j-c[i]];
      }
   while (1)
   {
      n=0;
      while (1)
      {
         scanf("%d%c",&x,&ch);
         n+=x;
         if (ch=='\n')
            break;
      }
      if (n==0)
         break;
      printf("%lld\n",f[n]-1);
   }
   system("pause");
   return(0);
}
