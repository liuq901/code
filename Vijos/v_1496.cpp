#include <cstdio>
#include <cstdlib>
const int w[10]={6,2,5,5,4,5,6,3,7,6};
int main()
{
   int work(int);
   int n,i,j,ans;
   scanf("%d",&n);
   n-=4;
   ans=0;
   for (i=0;i<=800;i++)
      for (j=0;j<=800;j++)
         if (work(i)+work(j)+work(i+j)==n)
            ans++;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
int work(int x)
{
   int k,ans;
   ans=0;
   while (1)
   {
      k=x%10;
      x/=10;
      ans+=w[k];
      if (x==0)
         break;
   }
   return(ans);
}
