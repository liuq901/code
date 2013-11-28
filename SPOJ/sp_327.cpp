#include <cstdio>
#include <cstdlib>
#include <cstring>
int l,r,n,ans[11000][2];
bool f[11000];
int main()
{
   bool check(int);
   void count(int);
   int test;
   scanf("%d",&test);
   for (int id=1;id<=test;id++)
   {
      scanf("%d%d",&l,&r);
      l++,r--;
      for (int i=l+l+1;i<=r+r-1;i++)
         f[i]=check(i);
      n=0;
      for (int i=l+l+1;i<=r+r-1;i++)
      {
         if (!f[i])
            continue;
         count(i);
      }
      printf("case %d\n%d\n",id,n);
      for (int i=1;i<=n;i++)
         printf("%d %d\n",ans[i][0],ans[i][1]);
   }
   system("pause");
   return(0);
}
bool check(int x)
{
   bool get(int);
   int sum=0;
   for (int i=l;i<=r;i++)
   {
      int p=x-i;      
      if (i>=p)
         break;
      if (p<l || p>r)
         continue;
      if (get(i*p))
         sum++;
      else
         return(false);
   }
   return(sum>=2);
}
bool get(int x)
{
   int sum=0;
   for (int i=l;i<=r;i++)
   {
      if (i*i>=x || sum==2)
         break;
      if (x%i)
         continue;
      int p=x/i;
      if (p>=l && p<=r)
         sum++;
   }
   return(sum==2);
}
void count(int x)
{
   bool did(int);
   int sum=0,k;
   for (int i=l;i<=r;i++)
   {
      int p=x-i;
      if (i>=p || sum==2)
         break;
      if (did(i*p))
      {
         sum++;
         k=i;
      }
   }
   if (sum==1)
      ans[++n][0]=k,ans[n][1]=x-k;
}
bool did(int x)
{
   int sum=0;
   for (int i=l;i<=r;i++)
   {
      if (i*i>=x || sum==2)
         break;
      if (x%i)
         continue;
      int p=x/i;
      if (p>=l && p<=r && f[i+p])
         sum++;
   }
   return(sum==1);
}
