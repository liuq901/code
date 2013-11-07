#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#define left _left_
#define right _right_
using namespace std;
const char out[3][10][20]={
   {"",
   "........||.../\\...",
   "........||../..\\..",
   ".../\\...||./....\\.",
   "../..\\..||/......\\",
   "./....\\.||\\______/",
   "/......\\||........",
   "\\______/||........",},
   {"",
   "........||........",
   ".../\\...||.../\\...",
   "../..\\..||../..\\..",
   "./....\\.||./....\\.",
   "/......\\||/......\\",
   "\\______/||\\______/",
   "........||........"},
   {"",
   ".../\\...||........",
   "../..\\..||........",
   "./....\\.||.../\\...",
   "/......\\||../..\\..",
   "\\______/||./....\\.",
   "........||/......\\",
   "........||\\______/"}};
char s[10][20],a[10][20];
string left,right;
int sum1,sum2,value[260];
int main()
{
   void init(),calc(int,int),print(int,int);
   int work(int,int);
   int T;
   init();
   scanf("%d",&T);
   gets(s[0]);
   while (T--)
   {
      for (int i=1;i<=8;i++)
         gets(s[i]);
      sum1=sum2=0;
      left=right="";
      int state;
      if (s[3][3]=='/')
      {
         state=-1;
         calc(6,4);
      }
      else if (s[2][3]=='/')
      {
         state=0;
         calc(5,5);
      }
      else if (s[1][3]=='/')
      {
         state=1;
         calc(4,6);
      }
      int now=work(sum1,sum2);
      static int id=0;
      printf("Case %d:\n",++id);
      if (state==now)
         printf("The figure is correct.\n");
      else if (now==-1)
      {
         memcpy(a,out[0],sizeof(out[0]));
         print(6,4);
      }
      else if (!now)
      {
         memcpy(a,out[1],sizeof(out[1]));
         print(5,5);
      }
      else
      {
         memcpy(a,out[2],sizeof(out[2]));
         print(4,6);
      }
   }
   system("pause");
   return(0);
}
void init()
{
   for (int i='A';i<='Z';i++)
   {
      int x=i,sum=0;
      while (x)
      {
         sum+=x&1?500:250;
         x>>=1;
      }
      value[i]=sum;
   }
   value['.']=0;
}
void calc(int x,int y)
{
   for (int i=1;i<=6;i++)
   {
      left+=s[x][i];
      sum1+=value[s[x][i]];
   }
   for (int i=11;i<=16;i++)
   {
      right+=s[y][i];
      sum2+=value[s[y][i]];
   }
}
void print(int x,int y)
{
   for (int i=1;i<=6;i++)
      a[x][i]=left[i-1];
   for (int i=11;i<=16;i++)
      a[y][i]=right[i-11];
   for (int i=1;i<=7;i++)
      printf("%s\n",a[i]);
}
int work(int x,int y)
{
   if (x<y)
      return(1);
   if (x>y)
      return(-1);
   return(0);
}
