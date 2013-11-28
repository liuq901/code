#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;
stack <int> s;
int a[20];
int main()
{
   int T;
   scanf("%d",&T);
   while (T--)
   {
      int n;
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
      {
         char ch;
         cin>>ch;
         a[i]=ch-'0';
      }
      int p=1;
      for (int i=1;i<=n;i++)
      {
         while ((s.empty() || s.top()!=a[i]) && p<=n)
            s.push(p++);
         if (s.top()==a[i])
            s.pop();
         else
            break;
      }
      printf("%s\n",s.empty()?"yes":"no");
      while (!s.empty())
         s.pop();
   }
   system("pause");
   return(0);
}
