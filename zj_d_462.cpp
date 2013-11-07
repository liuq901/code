#include <cstdio>
#include <cstdlib>
const int m=10000;
int a[5100],ans[100000];
int main()
{
   int min(int,int);
   int n,k,l,r;
   while (scanf("%d%d%d%d",&n,&k,&l,&r)!=EOF)
   {
      a[1]=a[0]=1;
      for (int i=1;i<=k;i++)
      {
         int x=0;
         for (int j=1;j<=a[0];j++)
         {
            a[j]=a[j]*n+x;
            x=a[j]/m;
            a[j]%=m;
         }
         while (x)
         {
            a[++a[0]]=x%m;
            x/=m;
         }
      }
      int p=m;
      bool flag=false;
      ans[0]=0;
      for (int i=1;i<=4;i++)
      {
         p/=10;
         if (a[a[0]]/p || flag)
         {
            ans[++ans[0]]=a[a[0]]/p;
            flag=true;
         }
         a[a[0]]%=p;
      }
      for (int i=a[0]-1;i>=1;i--)
      {
         int p=m;
         for (int j=1;j<=4;j++)
         {
            p/=10;
            ans[++ans[0]]=a[i]/p;
            a[i]%=p;
         }
      }
      for (int i=l;i<=min(l+r-1,ans[0]);i++)
         printf("%d",ans[i]);
      printf("\n");
   }
   return(0);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
