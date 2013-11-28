#include <cstdio>
#include <cstdlib>
int p[50001];
int main()
{
   void init(),count(int,int);
   init();
   int n,k;
   scanf("%d%d",&n,&k);
   if (n-k<k)
      k=n-k;
   for (int i=1;i<=k;i++)
   {
      count(n-i+1,1);
      count(i,-1);
   }
   int ans=0;
   for (int i=2;i<=50000;i++)
      if (p[i])
         ans++;
   printf("%d\n",ans);
   system("pause");
   return(0);
}
bool f[50001];
int a[50001];
void init()
{
   for (int i=2;i<=50000;i++)
   {
      if (f[i])
         continue;
      for (int j=i;j<=50000/i;j++)
         f[i*j]=true;
   }
   for (int i=2;i<=50000;i++)
      if (!f[i])
         a[++a[0]]=i;
}
void count(int x,int value)
{
   int t=1;
   while (f[x])
   {
      while (x%a[t])
         t++;
      p[a[t]]+=value;
      x/=a[t];
   }
   p[x]+=value;
}
