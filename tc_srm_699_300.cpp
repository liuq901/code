#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct BallsConverter
{
   string theGood(vector <string> convert)
   {
      int n=convert.size();
      for (int i=0;i<n;i++)
         for (int j=0;j<n;j++)
            a[i][j]=isupper(convert[i][j])?convert[i][j]-'A':convert[i][j]-'a'+26;
      for (int i=0;i<n;i++)
         for (int j=0;j<n;j++)
            for (int k=0;k<n;k++)
            {
               int p1=a[a[i][j]][k],p2=a[a[i][k]][j],p3=a[a[j][k]][i];
               if (p1!=p2 || p1!=p3)
                  return("Bad");
            }
      return("Good");
   }
private:
   int a[50][50];
};
int main()
{
   int n;
   scanf("%d",&n);
   vector <string> a;
   a.resize(n);
   for (int i=0;i<n;i++)
      cin>>a[i];
   BallsConverter p;
   printf("%s\n",p.theGood(a).c_str());
   system("pause");
   return(0);
}
