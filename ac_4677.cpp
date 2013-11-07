#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      string s;
      cin>>s;
      bool f[2]={0};
      for (int i=0;i<s.size();i++)
         f[s[i]-'0']=true;
      printf("%d\n",f[0]+f[1]);
   }
   system("pause");
   return(0);
}
