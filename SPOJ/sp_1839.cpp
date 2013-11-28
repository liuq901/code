#include <cstdio>
#include <cstdlib>
#include <cstring>
int f[900][900];
int main()
{ 
   int min(int,int),max(int,int);
   bool illegal(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int n,sum=0,a[71],b[71];
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&a[i],&b[i]);
         sum+=b[i];
      }
      for (int i=1;i<n;i++)
         for (int j=i+1;j<=n;j++)
            if (a[i]<a[j])
            {
               int t;
               t=a[i],a[i]=a[j],a[j]=t;
               t=b[i],b[i]=b[j],b[j]=t;
            }
      memset(f,26,sizeof(f));
      sum=sum*2/5;
      int s=0;
      f[0][0]=a[1];
      for (int i=2;i<=n;i++)
      {
         for (int j=min(sum,s);j>=0;j--)
            for (int k=min(sum,s-j);k>=0;k--)
            {
               if (illegal(f[j][k]))
                  continue;
               f[j+b[i]][k]=min(f[j+b[i]][k],f[j][k]+a[i]*(j==0));
               f[j][k+b[i]]=min(f[j][k+b[i]],f[j][k]+a[i]*(k==0));
            }
         s+=b[i];
      }
      s+=b[1],sum+=30;
      int ans=1<<30;
      for (int i=1;i<=sum;i++)
         for (int j=1;j<=sum;j++)
         {
            if (illegal(f[i][j]))
               continue;
            ans=min(ans,(f[i][j])*max(max(i,j),s-i-j));
         }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int min(int x,int y)
{
   return(x<y?x:y);
}
int max(int x,int y)
{
   return(x>y?x:y);
}
bool illegal(int x)
{
   return(x>1000000);
}
