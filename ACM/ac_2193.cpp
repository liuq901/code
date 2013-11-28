#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int c[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000};
char s[1000],a[1000];
bool f[1000];
int b[1000];
int main()
{
   void work(int,int,bool);
   int T;
   scanf("%d",&T);
   while (T--)
   {
      scanf("%s%s",s,a);
      int n=strlen(s),m=strlen(a);
      sort(a,a+m);
      memset(b,0,sizeof(b));
      work(0,n,true);
      for (int i=n-2;i>=0;i--)
         if (b[i] && b[i+1])
            b[i]=b[i+1]+1;
      int ans=0;
      for (int i=0;i<m;i++)
      {
         int k=-1;
         for (int j=0;j<n;j++)
         {
            if (s[j]!='#')
               continue;
            if (k==-1 || !f[j] && f[k] || f[j] && f[k] && b[j]<b[k] || !f[j] && !f[k] && b[j]>b[k])
               k=j;
         }
         ans+=c[b[k]]*(a[i]-'0')*(f[k]?1:-1);
         s[k]=a[i];
      }
      static int id=0;
      printf("Case %d:\n%s\n%d\n",++id,s,ans);
   }
   system("pause");
   return(0);
}
void work(int l,int r,bool now)
{
   bool flag=true;
   for (int i=l;i<=r;i++)
   {
      if (s[i]=='#')
      {
         b[i]=1;
         f[i]=now==flag;
      }
      if (s[i]=='+')
         flag=true;
      if (s[i]=='-')
         flag=false;
      if (s[i]=='(')
      {
         int t=0;
         for (int j=i;j<=r;j++)
         {
            if (s[j]=='(')
               t++;
            if (s[j]==')')
               t--;
            if (!t)
            {
               work(i+1,j-1,now==flag);
               i=j;
               break;
            }
         }
      }
   }
}
