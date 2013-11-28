#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[110];
int main()
{
   char ch;
   scanf("%c",&ch);
   int n=0,x;
   while (scanf("%d",&x)==1)
      a[++n]=x;
   sort(a+1,a+n+1);
   n=unique(a+1,a+n+1)-a-1;
   if (ch=='D')
      reverse(a+1,a+n+1);
   for (int i=1;i<n;i++)
      printf("%d ",a[i]);
   printf("%d\n",a[n]);
   system("pause");
   return(0);
}
