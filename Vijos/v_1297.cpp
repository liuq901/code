#include <cstdio>
#include <cstdlib>
int n,m,ans;
int main()
{
   void search(int,int,int,int,int);
   scanf("%d%d",&n,&m);
   ans=10000000;
   search(0,100,100,0,0);
   if (ans==10000000)
      ans=0;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
void search(int cost,int h,int r,int v,int k)
{
   int work(int);
   int i,s,q,j;
   if (k==1)
      cost+=r*r;
   if (k==m)
   {
      if (v==n && cost<ans)
         ans=cost;
      return;
   }
   if (v>=n)
      return;
   if (v+m*r*r*h<n)
      return;
   if (cost>ans)
      return;
   for (i=r-1;i>=m-k;i--)
   {
      s=i*i;
      q=2*i;
      for (j=h-1;j>=m-k;j--)
         search(cost+q*j,j,i,v+s*j,k+1);
   }
}
