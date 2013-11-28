#include <cstdio>
#include <cstdlib>
#include <cstring>
const int p=9973;
class matrix
{
   int n,a[11][11];
   friend matrix operator *(matrix,matrix);
public:
   matrix()
   {
      memset(a,0,sizeof(a));
   }
   void size(int x)
   {
      n=x;
   }
   void get(int x,int y,int z)
   {
      a[x][y]=z;
   }
   void print()
   {
      int sum=0;
      for (int i=1;i<=n;i++)
         sum=(sum+a[i][i])%p;
      printf("%d\n",sum);
   }
};
matrix operator *(matrix a,matrix b)
{
   matrix c;
   c.n=a.n;
   for (int i=1;i<=c.n;i++)
      for (int j=1;j<=c.n;j++)
         for (int k=1;k<=c.n;k++)
            c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%p;
   return(c);
}
matrix one;
int main()
{
   matrix count(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      one.size(n);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
         {
            int x;
            scanf("%d",&x);
            one.get(i,j,x);
         }
      matrix ans=count(m);
      ans.print();
   }
   system("pause");
   return(0);
}
matrix count(int m)
{
   matrix ans,t;
   if (m==1)
      return(one);
   t=count(m/2);
   ans=t*t;
   if (m&1)
      ans=ans*one;
   return(ans);
}
