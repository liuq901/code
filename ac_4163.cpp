#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
string s,a[20];
char buf[100000];
bool f[5010][5010];
vector <int> b[5010];
int main()
{
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      for (int i=1;i<=n;i++)
      {
         scanf("%s",buf);
         a[i]=buf;
      }
      s="";
      for (int i=1;i<=m;i++)
      {
         scanf("%s",buf);
         s+=buf;
      }
      for (int i=0;i<s.size();i++)
         b[i].clear();
      for (int i=1;i<=n;i++)
         for (int j=0;j<s.size();j++)
         {
            if (j+a[i].size()>s.size())
               break;
            bool flag=true;
            for (int k=0;k<a[i].size();k++)
               if (a[i][k]!=s[j+k])
               {
                  flag=false;
                  break;
               }
            if (flag)
               b[j+a[i].size()-1].push_back(i);
         }
      f[0][0]=true;
      int ans=0;
      for (int i=0;i<s.size();i++)
      {
         f[i+1][0]=true;
         for (int k=1;k<1<<n;k++)
         {
            f[i+1][k]=false;
            for (int j=0;j<b[i].size();j++)
            {
               int x=b[i][j];
               if ((k>>x-1&1) && f[i-a[x].size()+1][k-(1<<x-1)])
               {
                  f[i+1][k]=true;
                  ans+=k==(1<<n)-1;
                  break;
               }
            }
         }
      }
      printf("%d\n",ans);
   }
   system("pause");
   return(0);
}
