#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans,k,f[30001],b[30001],a[30001][4];
int main()
{
   int work(int,int);
   int n,i,x,y;
   scanf("%d%d",&n,&k);
   if (n==1)
   {
      printf("1\n");
      printf("1\n");
   }
   else
   {
      memset(b,0,sizeof(b));
      for (i=1;i<=n-1;i++)
      {
         scanf("%d%d",&x,&y);
         a[i][0]=x;
         a[i][1]=y;
         a[i][2]=b[x];
         a[i][3]=b[y];
         b[x]=b[y]=i;
      }
      ans=0;
      if (work(0,1)>=0)
      {
         ans++;
         f[ans]=1;
      }
      printf("%d\n",ans);
      for (i=1;i<=ans;i++)
         printf("%d\n",f[i]);
   }
   system("pause");
   return(0);
}
int work(int father,int x)
{
   int min,max,i,t;
   max=-20000000;
   min=20000000;
   i=b[x];
   while (i!=0)
   {
      if (a[i][0]==x)
      {
         if (a[i][1]!=father)
         {
            t=work(x,a[i][1]);
            if (t>max)
               max=t;
            if (t<min)
               min=t;
         }
         i=a[i][2];
      }
      if (a[i][1]==x)
      {
         if (a[i][0]!=father)
         {
            t=work(x,a[i][0]);
            if (t>max)
               max=t;
            if (t<min)
               min=t;
         }
         i=a[i][3];
      }
   }
   if (max==-20000000)
      return(0);
   if (max<0 || max+min<-2)
      return(min+1);
   if (max+1==k)
   {
      ans++;
      f[ans]=x;
      return(-k-1);
   }
   return(max+1);
}
