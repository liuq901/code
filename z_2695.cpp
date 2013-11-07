#include <cstdio>
#include <cstdlib>
#include <cstring>
int n;
int main()
{
   void work();
   while (1)
   {
      scanf("%d",&n);
      if (n==0)
         break;
      work();
   }
   system("pause");
   return(0);
}
int sum,ans,a[31],b[31],c[31];
void work()
{
   void search(int,int);
   int i,j,t,k,flag,max;
   int d[31],f[31][2],p[31][2];
   for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
   memset(d,0,sizeof(d));
   t=n;
   ans=0;
   while (t!=0)
   {
      memset(p,0,sizeof(p));
      for (i=1;i<=n;i++)
      {
         if (d[i])
            continue;
         f[i][0]=f[i][1]=1;
         for (j=1;j<=i-1;j++)
         {
            if (d[j])
               continue;
            if (a[j]<=a[i] && f[j][0]+1>f[i][0])
            {
               f[i][0]=f[j][0]+1;
               p[i][0]=j;
            }
            if (a[j]>=a[i] && f[j][1]+1>f[i][1])
            {
               f[i][1]=f[j][1]+1;
               p[i][1]=j;
            }
         }
      }
      max=0;
      for (i=1;i<=n;i++)
      {
         if (d[i])
            continue;
         if (f[i][0]>max)
         {
            max=f[i][0];
            k=i;
            flag=0;
         }
         if (f[i][1]>max)
         {
            max=f[i][1];
            k=i;
            flag=1;
         }
      }
      t-=max;
      ans++;
      i=k;
      while (i!=0)
      {
         d[i]=1;
         i=p[i][flag];
      }
   }
   sum=b[0]=c[0]=0;
   search(1,0);
   search(1,1);
   if (n<=3 && ans==2)
      ans=0;
   printf("%d\n",ans);
}
void search(int t,int flag)
{
   int i,k,s,x;
   if (sum>=ans)
      return;
   if (t==n+1)
   {
      ans=sum;
      return;
   }
   if (!flag)
   {
      k=-1;
      s=0;
      for (i=1;i<=b[0];i++)
         if (b[i]<=a[t] && b[i]>s)
         {
            s=b[i];
            k=i;
         }
      if (k!=-1)
      {
         x=b[k];
         b[k]=a[t];
         search(t+1,0);
         search(t+1,1);
         b[k]=x;
      }
      else
      {
         sum++;
         b[0]++;
         b[b[0]]=a[t];
         search(t+1,0);
         search(t+1,1);
         sum--;
         b[0]--;
      }
   }
   else
   {
      k=-1;
      s=20000000;
      for (i=1;i<=c[0];i++)
         if (c[i]>=a[t] && c[i]<s)
         {
            s=c[i];
            k=i;
         }
      if (k!=-1)
      {
         x=c[k];
         c[k]=a[t];
         search(t+1,0);
         search(t+1,1);
         c[k]=x;
      }
      else
      {
         sum++;
         c[0]++;
         c[c[0]]=a[t];
         search(t+1,0);
         search(t+1,1);
         sum--;
         c[0]--;
      }
   }
}
