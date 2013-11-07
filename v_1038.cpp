#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,a[201],f[201][201],s[201][201],p[201][201];
int main()
{
   void print(int,int),work(int,int);
   int i,j,k;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   memset(s,0,sizeof(s));
   for (i=1;i<=n;i++)
      for (j=i;j<=n;j++)
         s[i][j]=s[i][j-1]+a[j];
   memset(f,26,sizeof(f));
   for (i=n;i>=1;i--)
      for (j=i;j<=n;j++)
      {
         if (i==j)
         {
            f[i][j]=0;
            continue;
         }
         for (k=i;k<=j-1;k++)
            if (f[i][k]+f[k+1][j]<=f[i][j])
            {
               f[i][j]=f[i][k]+f[k+1][j];
               p[i][j]=k;
            }
         f[i][j]+=s[i][j];
      }
   print(1,n);
   printf("\n");
   printf("%d\n",f[1][n]);
   work(1,n);
   system("pause");
   return(0);
}
void print(int l,int r)
{
   int mid;
   if (l==r)
   {
      printf("%d",a[l]);
      return;
   }
   mid=p[l][r];
   printf("(");
   print(l,mid);
   printf("+");
   print(mid+1,r);
   printf(")");
}
void work(int l,int r)
{
   int mid;
   if (l==r)
      return;
   mid=p[l][r];
   work(l,mid);
   work(mid+1,r);
   if (l==1 && r==n)
      printf("%d\n",s[1][n]);
   else
      printf("%d ",s[l][r]);
}
