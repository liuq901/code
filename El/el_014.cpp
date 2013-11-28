#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdarg>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <complex>
#include <iterator>
#include <memory>
#define SQR(x) ((x)*(x))
#define MAXN 1010
#define MAXM 1010
using namespace std;
typedef long long ll;
typedef long double ld;
const double pi=acos(-1.0);
const double eps=1e-7;
const int mod=1000000007;
const int inf=1061109567;
struct trie
{
   char ch;
   int son,next,father,suffix,w,c;
};
trie a[20010];
int m,value,f[20010][110];
char s[110];
int main()
{
   void insert(char *,int,int,int),build(),print(int,int);
   int count(int,int);
   int n,k;
   scanf("%d%*d%d%*c%*s",&n,&k);
   m=1;
   for (int i=1;i<=k;i++)
   {
      scanf("%s%d",s,&value);
      int l=strlen(s);
      insert(s,l,0,1);
   }
   build();
   memset(f,-1,sizeof(f));
   printf("%d\n",count(1,n));
   print(1,n);
   printf("\n");
   system("pause");
   return(0);
}
void insert(char *s,int l,int t,int x)
{
   int i;
   if (!a[x].son)
   {
      m++;
      a[x].son=m;
      a[m].father=x;
      a[m].ch=s[t];
      if (t+1==l)
         a[m].w=value;
      else
         insert(s,l,t+1,m);
   }
   else
   {
      i=a[x].son;
      while (1)
      {
         if (a[i].next==0 || a[i].ch==s[t])
            break;
         i=a[i].next;
      }
      if (a[i].ch==s[t] && t+1==l)
         a[m].w=value;
      else if (a[i].ch==s[t])
         insert(s,l,t+1,i);
      else
      {
         m++;
         a[i].next=m;
         a[m].father=x;
         a[m].ch=s[t];
         if (t+1==l)
            a[m].w=value;
         else
            insert(s,l,t+1,m);
      }
   }
}
int q[20010];
void build()
{
   int child(int,char);
   int i,l,r;
   l=r=1;
   q[1]=1;
   a[1].suffix=1;
   if (a[1].son==0)
      return;
   while (l<=r)
   {
      if (a[q[l]].son)
      {
         i=a[q[l]].son;
         while (1)
         {
            r++;
            q[r]=i;
            i=a[i].next;
            if (i==0)
               break;
         }
      }
      l++;
   }
   for (i=2;i<=r;i++)
   {
      int x=q[i];
      if (a[x].father==1)
         a[x].suffix=1;
      else
         a[x].suffix=child(a[a[x].father].suffix,a[x].ch);
      a[x].c=a[a[x].suffix].c+a[x].w;
   }
}
int child(int x,char ch)
{
   int i;
   i=a[x].son;
   while (i!=0)
   {
      if (a[i].ch==ch)
         break;
      i=a[i].next;
   }
   if (i!=0)
      return(i);
   else if (x==1)
      return(1);
   else
      return(child(a[x].suffix,ch));
}
void print(int x,int y)
{
   if (x!=1 && f[x][y]==f[a[x].suffix][y]+a[x].w)
   {
      if (a[x].suffix==1)
         printf("%c",a[x].ch);
      print(a[x].suffix,y);
   }
   else
   {
      if (x!=1)
         printf("%c",a[x].ch);
      if (!y)
         return;
      for (int i=a[x].son;i;i=a[i].next)
         if (f[x][y]==f[i][y-1]+a[x].c)
         {
            print(i,y-1);
            break;
         }
   }
}
int count(int x,int len)
{
   if (f[x][len]!=-1)
      return(f[x][len]);
   int ret=a[x].w;
   if (len)
      for (int i=a[x].son;i;i=a[i].next)
         ret=max(ret,count(i,len-1)+a[x].c);
   if (x!=1)
      ret=max(ret,count(a[x].suffix,len)+a[x].w);
   f[x][len]=ret;
   return(ret);
}
