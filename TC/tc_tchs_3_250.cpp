#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct BestSeller
{
   string findBestSeller(vector <string> a)
   {
      sort(a.begin(),a.end());
      string ans=a[0];
      int max=1,sum=1;
      for (int i=1;i<a.size();i++)
      {
         if (a[i]==a[i-1])
            sum++;
         else
            sum=1;
         if (sum>max)
            ans=a[i],max=sum;
      }
      return(ans);
   }
};
int main()
{
   vector <string> a;
   char s[1100];
   while (scanf("%s",s)!=EOF)
      a.push_back(s);
   BestSeller p;
   printf("%s\n",p.findBestSeller(a).c_str());
   system("pause");
   return(0);
}
