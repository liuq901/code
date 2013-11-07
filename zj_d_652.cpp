#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[60],f[60][60];
int main()
{
   int solve(int,int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   memset(f,-1,sizeof(f));
   printf("%d\n",solve(1,n));
   system("pause");
   return(0);
}
int solve(int l,int r)
{
   if (f[l][r]!=-1)
      return(f[l][r]);
   if (l+1==r)
      f[l][r]=0;
   else
   {
      f[l][r]=1<<30;
      for (int k=l+1;k<r;k++)
         f[l][r]=min(f[l][r],solve(l,k)+solve(k,r)+a[l]*a[k]*a[r]);
   }
   return(f[l][r]);
}
