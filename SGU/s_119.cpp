#include <cstdio>
#include <cstdlib>
int ans[10001][2];
int main()
{
   int gcd(int,int);
   void sort(int,int);
   int n,a,b,k,i;
   scanf("%d",&n);
   scanf("%d%d",&a,&b);
   k=gcd(gcd(a,b),n);
   a/=k;
   b/=k;
   n/=k;
   printf("%d\n",n);
   for (i=0;i<n;i++)
   {
      ans[i+1][0]=a*i%n;
      ans[i+1][1]=b*i%n;
   }
   sort(1,n);
   for (i=1;i<=n;i++)
      printf("%d %d\n",ans[i][0]*k,ans[i][1]*k);
   system("pause");
   return(0);
}
int gcd(int a,int b)
{
   if (b==0)
      return(a);
   else
      return(gcd(b,a%b));
}
void sort(int l,int r)
{
   int i,j,x,y,t;
   i=l;
   j=r;
   x=ans[(l+r)/2][0];
   y=ans[(l+r)/2][1];
   while (i<=j)
   {
      while (ans[i][0]<x || ans[i][0]==x && ans[i][1]<y)
         i++;
      while (ans[j][0]>x || ans[j][0]==x && ans[j][1]>y)
         j--;
      if (i<=j)
      {
         t=ans[i][0],ans[i][0]=ans[j][0],ans[j][0]=t;
         t=ans[i][1],ans[i][1]=ans[j][1],ans[j][1]=t;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r);
   if (l<j)
      sort(l,j);
}
