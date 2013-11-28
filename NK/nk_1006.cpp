#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
char a[20][20],b[20][20];
int main()
{
   int n;
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
         cin>>a[i][j];
   bool flag=true;
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         cin>>b[i][j];
         if (b[i][j]=='x' && a[i][j]=='*')
            flag=false;
      }
   for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
      {
         if (b[i][j]!='x' || a[i][j]=='*')
            continue;
         int now=0;
         for (int x=-1;x<=1;x++)
            for (int y=-1;y<=1;y++)
               if (a[i+x][j+y]=='*')
                  now++;
         b[i][j]=now+'0';
      }
   if (!flag)
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
            if (a[i][j]=='*')
               b[i][j]='*';
   for (int i=1;i<=n;i++)
   {
      for (int j=1;j<=n;j++)
         printf("%c",b[i][j]);
      printf("\n");
   }
   system("pause");
   return(0);
}
