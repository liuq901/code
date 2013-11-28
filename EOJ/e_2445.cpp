#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main()
{
   int calc(string);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int ans=-1;
      string boy,girl;
      cin>>boy;
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         string now;
         cin>>now;
         int p=calc(now+boy);
         if (p>ans || p==ans && now<girl)
            ans=p,girl=now;
      }
      printf("%s\n",girl.c_str());
   }
   system("pause");
   return(0);
}
int calc(string s)
{
   int l,o,v,e;
   l=o=v=e=0;
   for (int i=0;i<s.size();i++)
   {
      if (s[i]=='L')
         l++;
      if (s[i]=='O')
         o++;
      if (s[i]=='V')
         v++;
      if (s[i]=='E')
         e++;
   }
   return((l+o)*(l+v)*(l+e)*(o+v)*(o+e)*(v+e)%100);
}
