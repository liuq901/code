#include <cstdio>
#include <cstdlib>
int sum=1,n,a[501][501],ans[501][501];
bool b[501][501];
int main()
{
   bool search(int,int,int);
   scanf("%d",&n);
   if (n==1)
      printf("YES\n1 2\n");
   else
   {
      for (int i=1;i<=n;i++)
      {
         int m;
         scanf("%d",&m);
         for (int j=1;j<=m;j++)
         {
            int x;
            scanf("%d",&x);
            a[i][0]++;
            a[i][a[i][0]]=x;
            b[i][x]=true;
         }
         b[i][i]=true;
      }
      if (a[1][0]==0)
         printf("NO\n");
      else
      {
         int t=a[1][1];
         b[0][1]=b[1][0]=true;
         a[0][0]=a[0][1]=1;
         for (int i=1;i<=a[1][0];i++)
            if (!b[a[1][i]][t])
            {
               a[0][0]++;
               a[0][a[0][0]]=a[1][i];
               a[a[1][i]][0]++;
               a[a[1][i]][a[a[1][i]][0]]=0;
               b[0][a[1][i]]=b[a[1][i]][0]=true;
            }
         a[1][0]++;
         a[1][a[1][0]]=0;
         if (!search(1,0,-1) || sum!=n+1)
            printf("NO\n");
         else
         {
            printf("YES\n");
            for (int i=1;i<=n;i++)
               printf("%d %d\n",ans[i][0],ans[i][1]);
         }
      }
   }
   system("pause");
   return(0);
}
bool search(int x,int p,int father)
{
   for (int i=1;i<=a[p][0];i++)
   {
      int t=a[p][i];
      if (t==father || father!=-1 && b[t][father])
         continue;
      if (ans[t][0]!=0)
         return(false);
      ans[t][0]=x;
      sum++;
      ans[t][1]=sum;
      if (!search(sum,t,p))
         return(false);
   }
   return(true);
}
