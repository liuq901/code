#include <cstdio>
#include <cstdlib>
int n,e[200001][2];
int main()
{
   bool get(int);
   int t;
   scanf("%d",&t);
   while (t--)
   {
      int m;
      scanf("%d%d",&m,&n);
      for (int i=1;i<=n;i++)
         scanf("%d%d",&e[i][0],&e[i][1]);
      bool ans0=get(m),ans1=get(0);
      if (ans0==ans1)
      {
         for (int i=1;i<=m;i++)
            printf("0");
         printf("\n");
         continue;
      }
      int l=0,r=m,ans;
      while (l<=r)
      {
         int mid=l+r>>1;
         if (get(mid)==ans0)
         {
            ans=mid;
            r=mid-1;
         }
         else
            l=mid+1;
      }
      for (int i=1;i<=ans-1;i++)
         printf("0");
      printf("x");
      for (int i=ans+1;i<=m;i++)
         printf("1");
      printf("\n");
   }
   system("pause");
   return(0);
}
bool f[200001];
bool get(int mid)
{
   for (int i=1;i<=n;i++)
   {
      bool t1,t2;
      if (e[i][0]>0)
         t1=f[e[i][0]];
      else if (-e[i][0]<=mid)
         t1=false;
      else
         t1=true;
      if (e[i][1]>0)
         t2=f[e[i][1]];
      else if (-e[i][1]<=mid)
         t2=false;
      else
         t2=true;
      f[i]=!(t1 && t2);
   }
   return(f[n]);
}
