#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
const int inf=1<<30;
struct trie
{
   char ch;
   int son,next,father,suffix;
   vector <int> danger;
};
int S,T,tot,now,m,u[160],b[1000],e[1000000][3];
bool vis[160];
char s[1010];
trie a[10000];
int main()
{
   void clear(int),insert(char *,int,int,int),build_trie(),add(int,int,int);
   bool build();
   int child(int,char),dinic(int,int);
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      int n,K;
      scanf("%d%d",&n,&K);
      clear(m=1);
      tot=1,S=0,T=n+K+1;
      memset(b,0,sizeof(b));
      for (int i=1;i<=n;i++)
      {
         int x;
         scanf("%d%d%s",&u[i],&x,s);
         now=i;
         insert(s,strlen(s),0,1);
         add(i+K,T,x);
      }
      build_trie();
      int ans=0;
      for (int i=1;i<=K;i++)
      {
         scanf("%s",s);
         int now=1,len=strlen(s),value=0;
         memset(vis,0,sizeof(vis));
         for (int j=0;j<len;j++)
         {
            now=child(now,s[j]);
            for (int k=0;k<a[now].danger.size();k++)
            {
               int x=a[now].danger[k];
               value+=u[x];
               vis[x]=true;
            }
         }
         add(S,i,value);
         ans+=value;
         for (int j=1;j<=n;j++)
            if (vis[j])
               add(i,j+K,inf);
      }
      while (build())
         ans-=dinic(S,inf);
      printf("Case %d: %d\n",id,ans);
   }
   system("pause");
   return(0);
}
void insert(char *s,int l,int t,int x)
{
   void clear(int);
   if (!a[x].son)
   {
      a[x].son=++m;
      clear(m);
      a[m].father=x;
      a[m].ch=s[t];
      if (t+1==l)
         a[m].danger.push_back(now);
      else
         insert(s,l,t+1,m);
      return;
   }
   int i=a[x].son;
   while (1)
   {
      if (!a[i].next || a[i].ch==s[t])
         break;
      i=a[i].next;
   }
   if (a[i].ch==s[t] && t+1==l)
      a[i].danger.push_back(now);
   else if (a[i].ch==s[t])
      insert(s,l,t+1,i);
   else
   {
      a[i].next=++m;
      clear(m);
      a[m].father=x;
      a[m].ch=s[t];
      if (t+1==l)
         a[m].danger.push_back(now);
      else
         insert(s,l,t+1,m);
   }
}
void clear(int x)
{
   a[x].son=a[x].next=0;
   a[x].danger.clear();
}
int q[100000];
void build_trie()
{
   int child(int,char);
   int i,l,r;
   l=r=1;
   q[1]=1;
   while (l<=r)
   {
      int x=q[l++];
      for (int i=a[x].son;i;i=a[i].next)
         q[++r]=i;
   }
   a[1].suffix=1;
   for (i=2;i<=r;i++)
   {
      int x=q[i];
      if (a[x].father==1)
      {
         a[x].suffix=1;
         continue;
      }
      a[x].suffix=child(a[a[x].father].suffix,a[x].ch);
      for (int j=0;j<a[a[x].suffix].danger.size();j++)
         a[x].danger.push_back(a[a[x].suffix].danger[j]);
   }
}
void add(int x,int y,int c)
{
   e[++tot][0]=y,e[tot][1]=c,e[tot][2]=b[x],b[x]=tot;
   e[++tot][0]=x,e[tot][1]=0,e[tot][2]=b[y],b[y]=tot;
}
int child(int x,char ch)
{
   for (int i=a[x].son;i;i=a[i].next)
      if (a[i].ch==ch)
         return(i);
   if (x==1)
      return(1);
   return(child(a[x].suffix,ch));
}
int d[1000];
int dinic(int x,int flow)
{
   if (x==T)
      return(flow);
   int k=flow;
   for (int i=b[x];i;i=e[i][2])
   {
      int y=e[i][0];
      if (d[y]!=d[x]+1 || !e[i][1])
         continue;
      int t=dinic(y,min(k,e[i][1]));
      k-=t;
      e[i][1]-=t;
      e[i^1][1]+=t;
      if (!k)
         return(flow);
   }
   if (k==flow)
      d[x]=-1;
   return(flow-k);
}
bool build()
{
   memset(d,0,sizeof(d));
   int l,r;
   l=r=1,q[1]=S,d[S]=1;
   while (l<=r)
   {
      int x=q[l++];
      for (int i=b[x];i;i=e[i][2])
      {
         int y=e[i][0];
         if (d[y] || !e[i][1])
            continue;
         d[y]=d[x]+1;
         q[++r]=y;
         if (y==T)
            return(true);
      }
   }
   return(false);
}
