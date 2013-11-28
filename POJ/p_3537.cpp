#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int f[2001];
   f[0]=0;
   f[1]=f[2]=f[3]=1;
   f[4]=f[5]=2;
   for (int i=6;i<=2000;i++)
   {
      bool a[2001];
      memset(a,false,sizeof(a));
      for (int j=0;j<=(i-5)/2;j++)
         a[f[j]^f[i-j-5]]=true;
      a[f[i-3]]=a[f[i-4]]=a[f[i-5]]=true;
      f[i]=0;
      while (a[f[i]])
         f[i]++;
   }
   int n;
   while (scanf("%d",&n)!=EOF)
      if (f[n]==0)
         printf("2\n");
      else
         printf("1\n");
   system("pause");
   return(0);
}
