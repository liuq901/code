#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int i,k,ans;
   int f[11];
   scanf("%d",&k);
   memset(f,0,sizeof(f));
   f[1]=f[2]=f[5]=1;
   if (k==1)
      f[4]=f[8]=1;
   if ((k-1)%3==0)
      f[3]=f[6]=1;
   if ((k-1)%6==0)
      f[7]=1;
   if ((k-1)%9==0)
      f[9]=1;
   ans=0;
   for (i=0;i<=9;i++)
      if (f[i] && f[i+1])
         ans++;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
