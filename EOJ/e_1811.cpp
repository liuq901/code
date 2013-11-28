#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int l[30],r[30],now[30];
int main()
{
   void print(int);
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
   {
      string s;
      cin>>s;
      int dep,x;
      char ch;
      sscanf(s.c_str(),"(%d,%c)",&dep,&ch);
      x=ch-'A'+1;
      if (dep)
      {
         int p=now[dep-1];
         if (!l[p])
            l[p]=x;
         else
         {
            p=l[p];
            while (r[p])
               p=r[p];
            r[p]=x;
         }
      }
      now[dep]=x;
   }
   print(now[0]);
   printf("\n");
   system("pause");
   return(0);
}
void print(int x)
{
   for (int i=l[x];i;i=r[i])
      print(i);
   printf("%c",x+'A'-1);
}
