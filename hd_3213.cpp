#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,K,yy[900],lmy[900];
pair <int,int> a[900];
int main()
{
   void dp(int *);
   while (1)
   {
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      scanf("%d",&K);
      for (int i=1;i<=K;i++)
         scanf("%d%d",&a[i].first,&a[i].second);
      memset(yy,0,sizeof(yy));
      dp(yy);
      scanf("%d",&K);
      for (int i=1;i<=K;i++)
         scanf("%d%d",&a[i].first,&a[i].second);
      memset(lmy,0,sizeof(lmy));
      dp(lmy);
      int ans=0;
      for (int i=0;i<=m;i++)
         for (int j=0;i+j<=m;j++)
            ans=max(ans,yy[i]+lmy[j]);
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
int f[900][900];
void dp(int *ans)
{
   bool cmp(pair <int,int>,pair <int,int>);
   sort(a+1,a+K+1,cmp);
   int p=1;
   for (int i=2;i<=K;i++)
      if (a[i].second>a[p].second)
         a[++p]=a[i];
   K=p;
   int first=!a[1].first?2:1;
   memset(f,-1,sizeof(f));
   f[0][0]=0;
   for (int i=0;i<min(n,800);i++)
      for (int j=i;j<m;j++)
      {
         if (f[i][j]==-1)
            continue;
         for (int k=first;k<=K;k++)
         {
            if (j+a[k].first>m)
               break;
            f[i+1][j+a[k].first]=max(f[i+1][j+a[k].first],f[i][j]+a[k].second);
         }
      }
   for (int i=0;i<=min(n,800);i++)
      for (int j=0;j<=m;j++)
         if (f[i][j]!=-1)
         {
            if (!a[1].first)
               f[i][j]+=(n-i)*a[1].second;
            ans[j]=max(ans[j],f[i][j]);
         }
}
bool cmp(pair <int,int> a,pair <int,int> b)
{
   return(a.first<b.first || a.first==b.first && a.second>b.second);
}
