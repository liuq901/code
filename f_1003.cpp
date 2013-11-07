#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s[4][4];
int weight[20];
int main()
{
   bool check();
   int T;
   scanf("%d",&T);
   while (T--)
   {
      for (int i=1;i<=3;i++)
         for (int j=1;j<=3;j++)
            cin>>s[i][j];
      fill(weight+1,weight+13,1);
      int ans;
      for (int i=1;i<=12;i++)
      {
         weight[i]=0;
         if (check())
         {
            ans=i;
            break;
         }
         weight[i]=2;
         if (check())
         {
            ans=i;
            break;
         }
         weight[i]=1;
      }
      printf("%c is the counterfeit coin and it is %s.\n",ans+'A'-1,weight[ans]?"heavy":"light");
   }
   system("pause");
   return(0);
}
bool check()
{
   for (int i=1;i<=3;i++)
   {
      int sum0=0,sum1=0;
      for (int j=0;j<s[i][1].size();j++)
         sum0+=weight[s[i][1][j]-'A'+1];
      for (int j=0;j<s[i][2].size();j++)
         sum1+=weight[s[i][2][j]-'A'+1];
      if (sum0<sum1 && s[i][3]!="down")
         return(false);
      if (sum0==sum1 && s[i][3]!="even")
         return(false);
      if (sum0>sum1 && s[i][3]!="up")
         return(false);
   }
   return(true);
}
