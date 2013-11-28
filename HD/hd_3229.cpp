#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;
const int m=7;
int now[7],s[7],a[7][1001],c[129];
int f[1001][129];
pair <int,bool> p[7][1001];
bool g[7],flag[129];
int main()
{
   bool check(int,int),check(int);
   int calc(int,int),count(int,int,int);
   void work(int,int),move(int);
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      int n;
      scanf("%d",&n);
      for (int i=0;i<m;i++)
      {
         int tmp,sum=0;
         scanf("%d",&tmp);
         for (int j=1;j<=tmp;j++)
         {
            int x;
            char ch;
            scanf("%d%c",&x,&ch);
            p[i][++sum]=make_pair(x,false);
            a[i][x]=1;
            if (ch=='-')
            {
               int y;
               scanf("%d",&y);
               for (int k=x+1;k<y;k++)
               {
                  p[i][++sum]=make_pair(k,true);
                  a[i][k]=0;
               }
               p[i][++sum]=make_pair(y,true);
               a[i][y]=1;
            }
         }
         sort(p[i]+1,p[i]+sum+1);
         s[i]=sum;
      }
      int tmp;
      scanf("%d",&tmp);
      memset(flag,0,sizeof(flag));
      for (int i=1;i<=tmp;i++)
      {
         string s;
         cin>>s;
         int now=0;
         for (int j=6;j>=0;j--)
            now=now*2+s[j]-'0';
         for (int j=0;j<128;j++)
            if ((now&j)==now)
               flag[j]=true;
      }
      c[0]=0;
      for (int i=0;i<128;i++)
         if (!flag[i])
            c[++c[0]]=i;
      memset(f,0,sizeof(f));
      int ans=0;
      for (int i=0;i<7;i++)
         now[i]=1;
      for (int i=1;i<=n;i++)
      {
         for (int p=1;p<=c[0];p++)
         {
            int j=c[p];
            if (!check(i,j))
               continue;
            int value=calc(i,j);
            work(i,j);
            for (int l=1;l<=c[0];l++)
            {
               int k=c[l];
               if (check(k))
                  f[i][j]=max(f[i][j],f[i-1][k]+value-count(i,j,k));
            }
            ans=max(ans,f[i][j]);
         }
         move(i);
      }
      printf("Case #%d: %d\n",id,ans);
   }
   system("pause");
   return(0);
}
bool check(int i,int j)
{
   for (int k=0;k<7;k++)
   {
      int q=j>>k&1;
      if (!q)
         continue;
      if (now[k]>s[k] || p[k][now[k]].first>i)
         return(false);
   }
   return(true);
}
bool check(int k)
{
   for (int i=0;i<7;i++)
      if (g[i] && !(k>>i&1))
         return(false);
   return(true);
}
int calc(int i,int j)
{
   int ret=0;
   for (int k=0;k<7;k++)
   {
      int q=j>>k&1;
      if (now[k]<=s[k] && p[k][now[k]].first==i)
         if (p[k][now[k]].second && !q || !p[k][now[k]].second && q)
            ret+=a[k][i];
   }
   return(ret);
}
int count(int i,int j,int k)
{
   int ret=0;
   for (int l=0;l<7;l++)
   {
      if (now[l]<=s[l] && p[l][now[l]].first==i && p[l][now[l]].second)
      {
         if (!a[l][i])
            continue;
         if (!(j>>l&1) && !(k>>l&1))
            ret++;
      }
   }
   return(ret);
}
void work(int i,int j)
{
   memset(g,0,sizeof(g));
   for (int k=0;k<7;k++)
   {
      int q=j>>k&1;
      if (now[k]<=s[k] && p[k][now[k]].first==i && p[k][now[k]].second && q)
         g[k]=true;
   }
}
void move(int i)
{
   for (int k=0;k<7;k++)
      if (now[k]<=s[k] && p[k][now[k]].first==i)
         now[k]++;
}
