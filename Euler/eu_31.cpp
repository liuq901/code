#include <cstdio>
#include <cstdlib>
const int a[]={0,1,2,5,10,20,50,100,200};
int f[210];
int main()
{
   int n=8,m=200;
   f[0]=1;
   for (int i=1;i<=n;i++)
      for (int j=a[i];j<=m;j++)
         f[j]+=f[j-a[i]];
   printf("%d\n",f[m]);
   system("pause");
   return(0);
}
