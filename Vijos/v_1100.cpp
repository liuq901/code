#include <cstdio>
#include <cstdlib>
#include <cstring>
bool flag;
int p[31][31];
int main()
{
   void print(int,int);
   long long f[31][31];
   int n,a[31];
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      scanf("%d",&a[i]);
   for (int i=n;i>=1;i--)
   {
      f[i][i]=a[i];
      p[i][i]=i;
      for (int j=i+1;j<=n;j++)
      {
         if (f[i][j-1]+a[j]>f[i+1][j]+a[i])
         {
            f[i][j]=f[i][j-1]+a[j];
            p[i][j]=j;
         }
         else
         {
            f[i][j]=f[i+1][j]+a[i];
            p[i][j]=i;
         }
         for (int k=i+1;k<=j-1;k++)
            if (f[i][k-1]*f[k+1][j]+a[k]>f[i][j])
            {
               f[i][j]=f[i][k-1]*f[k+1][j]+a[k];
               p[i][j]=k;
            }
      }
   }
   printf("%I64d\n",f[1][n]);
   flag=false;
   print(1,n);
   printf("\n");
   system("pause");
   return(0);
}
void print(int l,int r)
{
   if (l>r)
      return;
   if (flag)
      printf(" ");
   flag=true;
   int k=p[l][r];
   printf("%d",k);
   print(l,k-1);
   print(k+1,r);
}
