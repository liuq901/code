#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
typedef map <string,int>::iterator iter;
map <string,int> man,woman;
int n;
char s[100000];
bool a[20][20];
string men[20],women[20];
ll f[1<<16];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      man.clear();
      for (int i=1;i<=n;i++)
      {
         scanf("%s",s);
         man[s]=0;
      }
      int t=0;
      for (iter k=man.begin();k!=man.end();k++)
      {
         k->second=++t;
         men[t]=k->first;
      }
      woman.clear();
      for (int i=1;i<=n;i++)
      {
         scanf("%s",s);
         woman[s]=0;
      }
      t=0;
      for (iter k=woman.begin();k!=woman.end();k++)
      {
         k->second=++t;
         women[t]=k->first;
      }
      gets(s);
      memset(a,0,sizeof(a));
      for (int i=1;i<=n;i++)
      {
         gets(s);
         stringstream sin(s);
         string name;
         sin>>name;
         name.erase(name.size()-1);
         int x=man[name];
         while (sin>>name)
         {
            int y=woman[name];
            a[x][y]=true;
         }
      }
      f[0]=1;
      for (int i=1;i<1<<n;i++)
      {
         int m=0;
         for (int j=0;j<n;j++)
            m+=i>>j&1;
         m=n-m+1;
         f[i]=0;
         for (int j=1;j<=n;j++)
            if ((i>>j-1&1) && a[m][j])
               f[i]+=f[i^1<<j-1];
      }
      static int id=0;
      printf("Case %d:\n",++id);
      if (f[(1<<n)-1])
      {
         cout<<f[(1<<n)-1]<<endl;
         int now=(1<<n)-1;
         for (int i=1;i<=n;i++)
         {
            for (int j=1;j<=n;j++)
               if (a[i][j] && (now>>j-1&1) && f[now^1<<j-1])
               {
                  printf("%s %s",men[i].c_str(),women[j].c_str());
                  now^=1<<j-1;
                  break;
               }
            printf("%c",i==n?'\n':' ');
         }
      }
      else
         printf("No Way\n");
   }
   system("pause");
   return(0);
}
