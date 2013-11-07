#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class bignum
{
   int a[100];
public:
   bignum()
   {
      memset(a,0,sizeof(a));
      a[0]=a[1]=1;
   }
   void print()
   {
      for (int i=a[0];i;i--)
         printf("%d",a[i]);
      printf("\n");
   }
   void operator *=(int x)
   {
      int k=0;
      for (int i=1;i<=a[0];i++)
      {
         a[i]=a[i]*x+k;
         k=a[i]/10;
         a[i]%=10;
      }
      while (k)
      {
         a[++a[0]]=k%10;
         k/=10;
      }
   }
};
char s[1000];
vector <char> a[1000];
bool f[1000];
int main()
{
   void search(char);
   cin>>s;
   int m;
   scanf("%d",&m);
   while (m--)
   {
      char x,y;
      cin>>x>>y;
      a[x].push_back(y);
   }
   bignum ans;
   int n=strlen(s);
   for (int i=0;i<n;i++)
   {
      memset(f,0,sizeof(f));
      search(s[i]);
      ans*=count(f,f+1000,true);
   }
   ans.print();
   system("pause");
   return(0);
}
void search(char x)
{
   if (f[x])
      return;
   f[x]=true;
   for (int i=0;i<a[x].size();i++)
      search(a[x][i]);
}
