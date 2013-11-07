#include <cstdio>
#include <cstdlib>
const int m=10000;
int a[20000],ans[100000];
int main()
{
   void work(int,int);
   int min(int,int);
   int n,k,l,r;
   while (scanf("%d%d%d%d",&n,&k,&l,&r)!=EOF)
   {
      work(n,k);
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
   system("pause");
   return(0);
}
int b[20000];
void work(int n,int p)
{
   if (!p)
   {
      a[0]=a[1]=1;
      return;
   }
   work(n,p>>1);
   for (int i=1;i<=a[0]<<1;i++)
      b[i]=0;
   for (int i=1;i<=a[0];i++)
      for (int j=1;j<=a[0];j++)
      {
         b[i+j-1]+=a[i]*a[j];
         b[i+j]+=b[i+j-1]/m;
         b[i+j-1]%=m;
      }
   a[0]<<=1;
   for (int i=1;i<=a[0];i++)
      a[i]=b[i];
   while (!a[a[0]] && a[0]>1)
      a[0]--;
   if (p&1)
   {
      int x=0;
      for (int i=1;i<=a[0];i++)
      {
         long long p=(long long)n*a[i]+x;
         x=p/m;
         a[i]=p%m;
      }
      while (x)
      {
         a[++a[0]]=x%m;
         x/=m;
      }
   }
}
int min(int x,int y)
{
   return(x<y?x:y);
}
