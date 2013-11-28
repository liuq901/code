#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
const string b[10]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001"};
const int mod=1000000009;
struct trie
{
   bool danger;
   int father,suffix,num,son[2];
};
trie a[2010];
char s[10000];
int m;
int main()
{
   void clear(int),insert(char *,int,int,int),build();
   int calc(char *),work(char *);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      m=1;
      clear(m);
      for (int i=1;i<=n;i++)
      {
         scanf("%s",s);
         insert(s,1,strlen(s),0);
      }
      build();
      scanf("%s",s);
      int ans=-calc(s)+work(s);
      scanf("%s",s);
      ans=(ans+calc(s))%mod;
      if (ans<0)
         ans+=mod;
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
void insert(char *s,int x,int len,int now)
{
   void clear(int);
   int p=s[now]-'0';
   if (!a[x].son[p])
   {
      a[x].son[p]=++m;
      clear(m);
      a[m].father=x;
      a[m].num=p;
   }
   int k=a[x].son[p];
   if (now==len-1)
      a[k].danger=true;
   else
      insert(s,k,len,now+1);
}
void clear(int x)
{
   a[x].son[0]=a[x].son[1]=0;
   a[x].danger=false;
}
int q[2010];
void build()
{
   int child(int,int);
   int l,r;
   q[l=r=1]=1;
   while (l<=r)
   {
      int x=q[l++];
      for (int i=0;i<=1;i++)
         if (a[x].son[i])
            q[++r]=a[x].son[i];
   }
   a[1].suffix=1;
   for (int i=2;i<=r;i++)
   {
      int x=q[i];
      if (a[x].father==1)
         a[x].suffix=1;
      else
         a[x].suffix=child(a[a[x].father].suffix,a[x].num);
      if (a[a[x].suffix].danger)
         a[x].danger=true;
   }
}
int f[210][2010][3];
int calc(char *s)
{
   int child(int,int);
   memset(f,0,sizeof(f));
   f[0][1][1]=1;
   int n=strlen(s),ans=0;
   for (int i=0;i<n;i++)
      for (int j=1;j<=m;j++)
         for (int k=0;k<=2;k++)
         {
            if (!f[i][j][k])
               continue;
            ans=(ans+f[i][j][k])%mod;
            int begin=i?0:1;
            for (int l=begin;l<=9;l++)
            {
               bool fail=false;
               int now=j;
               for (int p=0;p<4;p++)
               {
                  now=child(now,b[l][p]-'0');
                  if (a[now].danger)
                  {
                     fail=true;
                     break;
                  }
               }
               if (!fail)
               {
                  int state,p=s[i]-'0';
                  if (k==1 && l==p)
                     state=1;
                  else if (k==2 || k==1 && l>p)
                     state=2;
                  else
                     state=0;
                  f[i+1][now][state]=(f[i+1][now][state]+f[i][j][k])%mod;
               }
            }
         }
   for (int i=1;i<=m;i++)
      for (int j=0;j<2;j++)
         ans=(ans+f[n][i][j])%mod;
   return(ans);
}
int work(char *s)
{
   int child(int,int);
   int x=1;
   int n=strlen(s);
   for (int i=0;i<n;i++)
   {
      int p=s[i]-'0';
      for (int j=0;j<4;j++)
      {
         x=child(x,b[p][j]-'0');
         if (a[x].danger)
            return(0);
      }
   }
   return(1);
}
int child(int x,int num)
{
   if (a[x].son[num])
      return(a[x].son[num]);
   if (x==1)
      return(1);
   return(child(a[x].suffix,num));
}
