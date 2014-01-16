#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans,n,x,y,t,flag[20],a[20];
main()
{
   void test(int,int,int),search(int);
   scanf("%d",&n);
   ans=0;
   t=(1<<n)-1;
   test(0,0,0);
   printf("%d\n",ans);
   if (ans)
   {
      ans=0;
      for (int i=1;i<=n;i++)
      {
         x=y=0;
         memset(flag,0,sizeof(flag));
         memset(a,0,sizeof(a));
         flag[i]=1;
         x|=1<<n-i;
         y|=1<<i-1;
         a[1]=i;
         search(2);
         flag[i]=0;
         x&=~(1<<n-i);
         y&=~(1<<i-1);
      }
   }
   system("pause");
   return(0);
}
void test(int x,int y,int z)
{
   int pos,p;
   if (x!=t)
   {
      pos=~(x|y|z)&t;
      while (pos!=0)
      {
         p=pos&(~pos+1);
         pos-=p;
         test(x+p,(y+p)<<1,(z+p)>>1);
      }
   }
   else
      ans++;
}
void search(int t)
{
   int i;
   if (ans>1)
      return;
   if (t>n)
   {
      ans++;
      if (ans==1)
         for (i=1;i<=n;i++)
            printf("%d %d\n",i,a[i]);
      return;
   }
   for (i=1;i<=n;i++)
      if (flag[i])
         continue;
      else if ((x>>t-i+n-1)&1==1)
         continue;
      else if ((y>>t+i-2)&1==1)
         continue;
      else
      {
         flag[i]=1;
         x|=1<<t-i+n-1;
         y|=1<<t+i-2;
         a[t]=i;
         search(t+1);
         flag[i]=0;
         x&=~(1<<t-i+n-1);
         y&=~(1<<t+i-2);
      }
}
