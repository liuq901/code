#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a[1010];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=0;i<n;i++)
      cin>>a[i];
   sort(a,a+n);
   int t=unique(a,a+n)-a;
   for (int i=0;i<t;i++)
      printf("%s\n",a[i].c_str());
   system("pause");
   return(0);
}
