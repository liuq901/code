#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;
int c,m,p[10001],b[10001],ans[10001],a[20001][2];
int main()
{
   int count(int,int),print(int,int,int);
   int n;
   scanf("%d%d",&n,&c);
   memset(b,0,sizeof(b));
   memset(ans,0,sizeof(ans));
   for (int i=1;i<=n-1;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      a[2*i-1][0]=y;
      a[2*i-1][1]=b[x];
      b[x]=2*i-1;
      a[2*i][0]=x;
      a[2*i][1]=b[y];
      b[y]=2*i;
   }
   m=1;
   if (count(1,0)<c)
      m--;
   p[m]=1;
   ans[1]=m;
   print(1,0,m);
   printf("%d\n",m);
   for (int i=1;i<=n;i++)
      if (ans[i]==m+1)
         ans[i]=m;
   for (int i=1;i<=n-1;i++)
      printf("%d ",ans[i]);
   printf("%d\n",ans[n]);
   for (int i=1;i<=m-1;i++)
      printf("%d ",p[i]);
   printf("%d\n\n",p[m]);
   system("pause");
   return(0);
}
int count(int x,int father)
{
   int i=b[x],sum=0;
   stack <int> s;
   while (i!=0)
   {
      if (a[i][0]!=father)
      {
         s.push(a[i][0]);
         sum+=count(a[i][0],x);
         if (sum>=c)
         {
            p[m]=x;
            while (!s.empty())
            {
               ans[s.top()]=m;
               s.pop();
            }
            m++;
            sum=0;
         }
      }
      i=a[i][1];
   }
   return(sum+1);
}
void print(int x,int father,int t)
{
   int i=b[x];
   ans[x]=t;
   while (i!=0)
   {
      if (a[i][0]!=father)
      {
         int k;
         if (ans[a[i][0]]==0)
            k=t;
         else
            k=ans[a[i][0]];
         print(a[i][0],x,k);
      }
      i=a[i][1];
   }
}
