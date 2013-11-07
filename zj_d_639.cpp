#include <cstdio>
#include <cstdlib>
const int mod=10007;
struct matrix
{
   int a[3][3];
};
matrix operator *(matrix a,matrix b)
{
   matrix c;
   for (int i=0;i<3;i++)
      for (int j=0;j<3;j++)
      {
         c.a[i][j]=0;
         for (int k=0;k<3;k++)
            c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
      }
   return(c);
}
matrix zero,one;
int main()
{
   matrix calc(int);
   zero.a[0][0]=zero.a[1][1]=zero.a[2][2]=one.a[1][0]=one.a[2][1]=one.a[0][2]=one.a[1][2]=one.a[2][2]=1;
   int n;
   scanf("%d",&n);
   matrix ans=calc(n-1);
   printf("%d\n",(ans.a[0][0]+ans.a[1][0]+ans.a[2][0])%mod);
   system("pause");
   return(0);
}
matrix calc(int n)
{
   if (!n)
      return(zero);
   matrix ret=calc(n>>1);
   ret=ret*ret;
   if (n&1)
      ret=ret*one;
   return(ret);
}
