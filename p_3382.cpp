#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
const ll inf=1000000000000000000LL;
char S[1010],s[5010][30];
int m,len,b[20][20],a[5010][20];
ll f[1010][20][20];
vector <pair <int,int > > c[1010];
bool first;
int main()
{
   ll dp(int,int,int);
   void print(int,int,int);
   int n;
   scanf("%d%d%*d",&n,&m);
   for (int i=1;i<=n;i++)
   {
      scanf("%s%d",s[i],&a[i][0]);
      for (int j=1;j<=a[i][0];j++)
         scanf("%d",&a[i][j]);
   }
   for (int i=1;i<=m;i++)
   {
      scanf("%d",&b[i][0]);
      for (int j=1;j<=b[i][0];j++)
         scanf("%d",&b[i][j]);
   }
   scanf("%s",S);
   len=strlen(S);
   for (int i=0;i<len;i++)
      for (int j=1;j<=n;j++)
      {
         int t=strlen(s[j]);
         if (i+t>len)
            continue;
         bool flag=true;
         for (int k=0;k<t;k++)
            if (S[i+k]!=s[j][k])
            {
               flag=false;
               break;
            }
         if (flag)
            c[i].push_back(make_pair(j,t));
      }
   memset(f,-1,sizeof(f));
   ll ans=dp(0,0,0);
   if (!ans)
      printf("0\n");
   else
   {
      if (ans==-26)
         printf("TOO MANY\n");
      else
         cout<<ans<<endl;
      first=true;
      print(0,0,0);
   }
   system("pause");
   return(0);
}
ll dp(int x,int y,int z)
{
   ll &ret=f[x][y][z];
   if (ret!=-1)
      return(ret);
   if (y && z==b[y][0])
      ret=dp(x,0,0);
   else if (x==len)
      ret=!z;
   else if (y)
   {
      ret=0;
      int type=b[y][z+1];
      for (int i=0;i<c[x].size();i++)
      {
         int now=c[x][i].first;
         for (int j=1;j<=a[now][0];j++)
            if (a[now][j]==type)
            {
               ll tmp=dp(x+c[x][i].second,y,z+1);
               if (tmp==-26 || ret+tmp>inf)
               {
                  ret=-26;
                  goto last;
               }
               ret+=tmp;
               break;
           }
      }
   }
   else
   {
      ret=0;
      for (int i=1;i<=m;i++)
      {
         ll tmp=dp(x,i,0);
         if (tmp==-26 || ret+tmp>inf)
         {
            ret=-26;
            goto last;
         }
         ret+=tmp;
      }
   }
last:
   return(ret);
}
void print(int x,int y,int z)
{
   if (y && z==b[y][0])
   {
      printf(".");
      print(x,0,0);
      return;
   }
   if (x==len)
   {
      printf("\n");
      return;
   }
   if (y)
   {
      int type=b[y][z+1];
      for (int i=0;i<c[x].size();i++)
      {
         int now=c[x][i].first;
         for (int j=1;j<=a[now][0];j++)
            if (a[now][j]==type && f[x+c[x][i].second][y][z+1])
            {
               if (!first)
                  printf(" ");
               first=false;
               printf("%s",s[c[x][i].first]);
               print(x+c[x][i].second,y,z+1);
               return;
            }
      }
   }
   for (int i=1;i<=m;i++)
      if (f[x][i][0])
      {
         print(x,i,0);
         return;
      }
}
