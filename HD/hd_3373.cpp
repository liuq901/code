#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
pair <int,pair <int,int> > a[3*maxn];
int N,c[maxn],X[maxn],Y[maxn],l[maxn],r[maxn],mid[maxn],p[maxn],in[maxn];
bool ok[maxn];
int main()
{
   void insert(int);
   int find(int);
   int n;
   while (scanf("%d",&n)==1)
   {
      for (int i=1;i<=n;i++)
      {
         scanf("%d%d",&X[i],&Y[i]);
         l[i]=0,r[i]=1000000000,p[i]=Y[i];
      }
      sort(Y+1,Y+n+1);
      N=unique(Y+1,Y+n+1)-Y-1;
      while (1)
      {
         bool flag=false;
         int tot=0;
         for (int i=1;i<=n;i++)
         {
            a[++tot]=make_pair(X[i],make_pair(1,i));
            if (l[i]!=r[i])
            {
               flag=true;
               mid[i]=l[i]+r[i]>>1;
               a[++tot]=make_pair(X[i]-mid[i],make_pair(0,i));
               a[++tot]=make_pair(X[i]+mid[i],make_pair(2,i));
            }
         }
         if (!flag)
            break;
         sort(a+1,a+tot+1);
         memset(c,0,sizeof(c));
         for (int i=1;i<=tot;i++)
         {
            int x=a[i].second.second,y=p[x];
            if (a[i].second.first==1)
            {
               y=lower_bound(Y+1,Y+N+1,y)-Y;
               insert(y);
            }
            else
            {
               int left,right;
               left=lower_bound(Y+1,Y+N+1,y-mid[x])-Y-1;
               right=upper_bound(Y+1,Y+N+1,y+mid[x])-Y-1;
               if (!a[i].second.first)
                  in[x]=find(right)-find(left);
               else
                  ok[x]=find(right)-find(left)-in[x]>1;
            }
         }
         for (int i=1;i<=n;i++)
         {
            if (l[i]==r[i])
               continue;
            if (ok[i])
               r[i]=mid[i];
            else
               l[i]=mid[i]+1;
         }
      }
      long long ans=0;
      for (int i=1;i<=n;i++)
         ans+=l[i];
      cout<<ans<<endl;
   }
   system("pause");
   return(0);
}
void insert(int x)
{
   for (int i=x;i<=N;i+=i&-i)
      c[i]++;
}
int find(int x)
{
   int ans=0;
   for (int i=x;i;i-=i&-i)
      ans+=c[i];
   return(ans);
}
