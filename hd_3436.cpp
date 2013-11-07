#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef set <int>::iterator data;
int limit,a[200010],size[200010],pos[200010],to[300100],c[300100],order[100010][2];
char s[10];
set <int> p;
map <int,int> hash;
int main()
{
   void modify(int,int);
   int find(int),log(int);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int N,m;
      scanf("%d%d",&N,&m);
      p.clear();
      hash.clear();
      memset(c,0,sizeof(c));
      for (int i=1;i<=m;i++)
      {
         scanf("%s%d",s,&order[i][1]);
         if (s[0]=='T')
         {
            order[i][0]=0;
            p.insert(order[i][1]);
         }
         else if (s[0]=='R')
            order[i][0]=1;
         else
            order[i][0]=2;
         s[0]=' ';
      }
      int n=0;
      if (!p.count(1))
         a[++n]=1;
      for (data k=p.begin();k!=p.end();k++)
      {
         int t=*k;
         a[++n]=t;
         if (!p.count(t+1))
            a[++n]=t+1;
      }
      for (int i=1;i<n;i++)
         size[i]=a[i+1]-a[i];
      size[n]=N-a[n]+1;
      limit=n+m;
      for (int i=1;i<=n;i++)
      {
         modify(i+m,size[i]);
         pos[i]=i+m;
         to[i+m]=i;
         hash[a[i]]=i;
         p.insert(a[i]);
      }
      static int id=0;
      printf("Case %d:\n",++id);
      int now=m;
      for (int i=1;i<=m;i++)
      {
         if (!order[i][0])
         {
            int t=order[i][1];
            data k=p.upper_bound(t);
            k--;
            int num;
            num=*k;
            int x=hash[num];
            modify(pos[x],-size[x]);
            modify(now,size[x]);
            pos[x]=now;
            to[now--]=x;
         }
         else if (order[i][0]==1)
         {
            int pos=0,num=0;
            for (int j=log(limit);j>=0;j--)
            {
               if (pos+(1<<j)>limit)
                  continue;
               if (num+c[pos+(1<<j)]<order[i][1])
                  pos+=1<<j,num+=c[pos];
            }
            pos++;
            printf("%d\n",order[i][1]-num+a[to[pos]]-1);
         }
         else
         {
            int t=order[i][1];
            data k=p.upper_bound(t);
            k--;
            int num;
            num=*k;
            int x=hash[num];
            int s=find(pos[x]);
            printf("%d\n",s-size[x]+order[i][1]-a[x]+1);
         }
      }
   }
   system("pause");
   return(0);
}
void modify(int x,int value)
{
   for (int i=x;i<=limit;i+=i&-i)
      c[i]+=value;
}
int find(int x)
{
   int ans=0;
   for (int i=x;i;i-=i&-i)
      ans+=c[i];
   return(ans);
}
int log(int x)
{
   int ans=0;
   while (x)
   {
      ans++;
      x>>=1;
   }
   return(ans-1);
}
