#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef vector <pair <int,int> >::iterator iter;
vector <pair <int,int> > f[260];
char s[260];
int a[260][260],b[260][260];
bool ans[260];
int main()
{
   void work(int,int);
   bool cmp(const pair <int,int> &,const pair <int,int> &);
   f[0].push_back(make_pair(0,0));
   while (1)
   {
      scanf("%s",s);
      if (!strcmp(s,"0=0"))
         break;
      int len=strlen(s),k;
      for (int i=0;i<len;i++)
         if (s[i]=='=')
         {
            k=i;
            break;
         }
      s[k]='\0';
      len=k;
      memset(a,-1,sizeof(a));
      memset(b,-1,sizeof(b));
      work(1,len);
      len=k;
      int sum;
      sscanf(s+k+1,"%d",&sum);
      for (int i=1;i<=len;i++)
      {
         f[i].clear();
         for (int j=1;j<=5;j++)
         {
            if (i-j<0)
               break;
            if (s[i-j]=='0')
               continue;
            int now=0;
            for (int k=i-j;k<i;k++)
               now=now*10+s[k]-'0';
            for (int k=0;k<f[i-j].size();k++)
            {
               int x=now+f[i-j][k].first,t=f[i-j][k].second+1;
               if (x<=sum && (i==len || a[i+1][len]+x<=sum && b[i+1][len]+x>=sum))
                  f[i].push_back(make_pair(x,t));
            }
         }
         sort(f[i].begin(),f[i].end());
         f[i].erase(unique(f[i].begin(),f[i].end(),cmp),f[i].end());
      }
      static int id=0;
      printf("%d. ",++id);
      iter K=lower_bound(f[len].begin(),f[len].end(),make_pair(sum,0));
      if (K==f[len].end() || K->first!=sum)
         printf("IMPOSSIBLE\n");
      else
      {
         memset(ans,0,sizeof(ans));
         int i=len,tmp=sum,T=K->second;
         while (1)
         {
            for (int j=1;j<=5;j++)
            {
               if (i-j<0)
                  break;
               if (s[i-j]=='0')
                  continue;
               int now=0;
               for (int k=i-j;k<i;k++)
                  now=now*10+s[k]-'0';
               K=lower_bound(f[i-j].begin(),f[i-j].end(),make_pair(tmp-now,0));
               if (K!=f[i-j].end() && K->first==tmp-now && K->second+1==T)
               {
                  ans[i-1]=true;
                  tmp-=now;
                  i-=j;
                  T--;
               }
            }
            if (!i)
               break;
         }
         for (int i=0;i<len;i++)
         {
            printf("%c",s[i]);
            if (ans[i])
               printf("%c",i==len-1?'=':'+');
         }
         printf("%d\n",sum);
      }
   }
   system("pause");
   return(0);
}
void work(int l,int r)
{
   if (a[l][r]!=-1)
      return;
   a[l][r]=1<<30,b[l][r]=0;
   for (int i=l+1;i<=r;i++)
   {
      work(l,i-1),work(i,r);
      a[l][r]=min(a[l][r],a[l][i-1]+a[i][r]);
      b[l][r]=max(b[l][r],b[l][i-1]+b[i][r]);
   }
   if (l==r)
   {
      a[l][r]=min(a[l][r],s[l-1]-'0'),b[l][r]=max(b[l][r],s[l-1]-'0');
      return;
   }
   if (r-l<5)
   {
      if (s[l-1]=='0')
         return;
      int now=0;
      for (int i=l-1;i<r;i++)
         now=now*10+s[i]-'0';
      a[l][r]=min(a[l][r],now);
      b[l][r]=max(b[l][r],now);
   }
}
bool cmp(const pair <int,int> &a,const pair <int,int> &b)
{
   return(a.first==b.first);
}
