#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
   while (1)
   {
      bool final=false;
      int low=-1,high=26;
      while (1)
      {
         int x;
         scanf("%d",&x);
         if (!x)
         {
            final=true;
            break;
         }
         string s;
         cin>>s>>s;
         if (s=="high")
            high=min(high,x);
         else if (s=="low")
            low=max(low,x);
         else
         {
            printf("%s\n",x>low && x<high?"Sunny may be honest":"Sunny is dishonest");
            break;
         }
      }
      if (final)
         break;
   }
   system("pause");
   return(0);
}
