#include <cstdio>
#include <cstdlib>
#include <cstring>
const int m=700,r=500001;
int p[701],f[500001],ans[500001],belong[500001],g[40001],a[40001][2];
int main()
{
   int get(int);
   int test_id=0;
   while (1)
   {
      int n;
      scanf("%d%*c",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
      {
         char ch;
         scanf("%c%d%*c",&ch,&a[i][1]);
         a[i][0]=ch=='B';
      }
      int s=0,t=0;
      memset(belong,0,sizeof(belong));
      memset(ans,0,sizeof(ans));
      for (int i=1;i<=n;i++)
         if (a[i][0] && !belong[a[i][1]])
            belong[a[i][1]]=++s;
         else
            g[i]=++t;
      belong[r+1]=-1;
      for (int i=1;i<=m;i++)
         p[i]=r+1;
      for (int i=1;i<=n;i++)
      {
         if (!a[i][0] && a[i][1]>m)
            continue;
         if (a[i][0])
         {
            int x=a[i][1];
            for (int j=1;j<=m;j++)
               if (p[j]==r+1 || x%j<=p[j]%j)
                  p[j]=x;
         }
         else
            ans[g[i]]=belong[p[a[i][1]]];
      }
      int tmp=r+1;
      for (int i=r;i>=0;i--)
      {
         if (belong[i])
            tmp=i;
         f[i]=tmp;
      }
      f[r+1]=r+1;
      for (int i=n;i>=1;i--)
      {
         if (!a[i][0] && a[i][1]<=m)
            continue;
         if (a[i][0])
         {
            int x=get(a[i][1]+1);
            f[get(a[i][1])]=f[x];
         }
         else
         {
            int k=0,min=r+1,t=a[i][1];
            while (1)
            {
               if (k>r)
                  break;
               int x=get(k);
               if (x==r+1)
                   break;
               if (min==r+1 || x%t<min%t || x%t==min%t && belong[x]>belong[min])
                  min=x;
               k+=t;
            }
            ans[g[i]]=belong[min];
         }
      }
      if (test_id)
         printf("\n");
      printf("Case %d:\n",++test_id);
      for (int i=1;i<=t;i++)
         printf("%d\n",ans[i]);
   }
   system("pause");
   return(0);
}
int get(int x)
{
   if (x!=f[x])
      f[x]=get(f[x]);
   return(f[x]);
}
