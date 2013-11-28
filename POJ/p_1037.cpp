#include <cstdio>
#include <cstdlib>
int main()
{
   void init(),work(int,long long);
   int k;
   init();
   scanf("%d",&k);
   while (k--)
   {
      int n;
      long long c;
      scanf("%d%I64d",&n,&c);
      work(n,c);
   }
   system("pause");
   return(0);
}
long long f[21][21],g[21][21];
void init()
{
   f[1][1]=g[1][1]=1;
   for (int i=2;i<=20;i++)
      for (int j=1;j<=i;j++)
      {
         for (int k=1;k<=j-1;k++)
            f[i][j]+=g[i-1][k];
         for (int k=j;k<=i-1;k++)
            g[i][j]+=f[i-1][k];
      }
}
int ans[21];
void work(int n,long long c)
{
   void search(int,int,int,int,long long,bool),print(int);
   for (int i=1;i<=n;i++)
   {
      if (c<=f[n][i])
      {
         ans[1]=i;
         search(2,1,i-1,n,c,false);
         break;
      }
      else
         c-=f[n][i];
      if (c<=g[n][i])
      {
         ans[1]=i;
         search(2,i,n-1,n,c,true);
         break;
      }
      else
         c-=g[n][i];
   }
   print(n);
}
void search(int dep,int l,int r,int n,long long c,bool flag)
{
   if (dep==n+1)
      return;
   for (int i=l;i<=r;i++)
      if (!flag)
      {
         if (c<=g[n-dep+1][i])
         {
            ans[dep]=i;
            search(dep+1,i,n-dep,n,c,true);
            return;
         }
         c-=g[n-dep+1][i];
      }
      else
      {
         if (c<=f[n-dep+1][i])
         {
            ans[dep]=i;
            search(dep+1,1,i-1,n,c,false);
            return;
         }
         c-=f[n-dep+1][i];
      }
}
void print(int n)
{
   bool flag[21]={0};
   for (int i=1;i<=n;i++)
   {
      int s=0;
      for (int j=1;j<=n;j++)
      {
         if (!flag[j])
            s++;
         if (s==ans[i])
         {
            printf("%d",j);
            flag[j]=true;
            break;
         }
      }
      printf("%c",i==n?'\n':' ');
   }
}
