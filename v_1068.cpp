#include <cstdio>
#include <cstdlib>
int s[35];
long long ans,f[35];
int main()
{
   void work(int,int,int,int);
   int i,n;
   scanf("%d",&n);
   for (i=1;i<=n;i++)
      scanf("%d",&s[i]);
   f[1]=2;
   for (i=2;i<=n;i++)
   {
      f[i]=f[i-1]*2;
      f[i-1]--;
   }
   f[n]--;
   work(n,1,2,3);
   printf("%I64d\n",ans);
   system("pause");
   return(0);
}
void work(int k,int a,int b,int c)
{
   if (s[k]==c)
   {
      printf("-1\n");
      system("pause");
      exit(0);
   }
   if (k==1)
   {
      if (s[k]==b)
         ans++;
   }
   else if (s[k]==a)
      work(k-1,a,c,b);
   else
   {
      ans+=f[k-1]+1;
      work(k-1,c,b,a);
   }
}
