#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map <string,int> s,t;
vector <string> a[20],b[20];
int main()
{
   int n,m;
   while (scanf("%d%d",&n,&m)==2)
   {
      int t0,t1;
      t0=t1=0;
      s.clear(),t.clear();
      for (int i=1;i<=n;i++)
      {
         string car,color;
         cin>>car>>color;
         if (!s.count(car))
         {
            s[car]=++t0;
            a[t0].clear();
         }
         if (!t.count(color))
         {
            t[color]=++t1;
            b[t1].clear();
         }
         a[s[car]].push_back(color);
         b[t[color]].push_back(car);
      }
      for (int i=1;i<=m;i++)
      {
         string op,x;
         cin>>op>>x;
         if (op=="brand")
         {
            int p=s[x];
            for (int j=0;j<a[p].size();j++)
               printf("%s %s\n",x.c_str(),a[p][j].c_str());
         }
         else
         {
            int p=t[x];
            for (int j=0;j<b[p].size();j++)
               printf("%s %s\n",b[p][j].c_str(),x.c_str());
         }
      }
      printf("\n");
   }
   system("pause");
   return(0);
}
