#include <cstdio>
#include <cstdlib>
int f[32][32];
int main()
{
   void prepare(),work();
   int i,t;
   prepare();
   scanf("%d",&t);
   for (i=1;i<=t;i++)
      work();
   system("pause");
   return(0);
}
void prepare()
{
   int i,j;
   f[0][0]=1;
   for (i=1;i<=31;i++)
   {
      f[i][0]=f[i-1][0];
      for (j=1;j<=i;j++)
         f[i][j]=f[i-1][j]+f[i-1][j-1];
   }
}
void work()
{
   int calc(int,int);
   int i,t,n,m,k,flag,ans,mid;
   unsigned int l,r,tmp;
   scanf("%d%d%d",&n,&m,&k);
   if (m==0)
   {
      if (k==1)
      {
         printf("0\n");
         return;
      }
      m--;
      k--;
   }
   flag=0;
   if (n<0)
   {
      flag=1;
      n^=1<<31;
      m^=1<<31;
   }
   i=0;
   while (1)
   {
      t=calc(m,i)-calc(n-1,i);
      if (k<=t)
         break;
      k-=t;
      i++;
   }
   if (calc(n,i)-calc(n-1,i)==k)
      ans=n;
   else
   {
      l=n;
      r=m;
      tmp=calc(n-1,i);
      while (l+1<r)
      {
         mid=(l+r)/2;
         t=calc(mid,i)-tmp;
         if (t<k)
            l=mid;
         else
            r=mid;
      }
      ans=l+1;
   }
   if (flag)
      ans^=1<<31;
   printf("%d\n",ans);
}
int calc(int x,int k)
{
   int i,tot,ans;
   if (x<0)
      return(0);
   tot=ans=0;
   for (i=31;i>0;i--)
   {
      if (x&1u<<i)
      {
         tot++;
         if (tot>k)
            break;
         x^=1u<<i;
      }
      if (1<<i-1<=x)
         ans+=f[i-1][k-tot];
   }
   if (tot+x==k)
      ans++;
   return(ans);
}
