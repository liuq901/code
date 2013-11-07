#include <cstdio>
#include <cstdlib>
int t,q[5000][3],d[7][1000000][2],f[7][1000000][2];
int main()
{
   void work();
   scanf("%d",&t);
   while (t--)
      work();
   system("pause");
   return(0);
}
void work()
{
   int a,b;
   scanf("%d%d",&a,&b);
   int l=1,r=1;
   q[1][0]=a;
   q[1][1]=1;
   q[1][2]=0;
   f[1][a][0]=t+1;
   d[1][a][0]=0;
   while (l<=r)
   {
      int p[7],x=q[l][0];
      for (int i=6;i>=1;i--)
      {
         p[i]=x%10;
         x/=10;
      }
      p[0]=q[l][1];
      for (int i=1;i<=3;i++)
      {
         int a[7];
         for (int j=0;j<=6;j++)
            a[j]=p[j];
         switch (i)
         {
         int t;
         case 1:
            t=a[1],a[1]=a[a[0]],a[a[0]]=t;
            break;
         case 2:
            t=a[6],a[6]=a[a[0]],a[a[0]]=t;
            break;
         case 3:
            if (a[0]!=6)
               a[0]++;
            break;
         }
         int tmp=0,p;
         if (q[l][2] || i==2)
            p=1;
         else
            p=0;
         for (int i=1;i<=6;i++)
            tmp=tmp*10+a[i];
         if (f[a[0]][tmp][p]!=t+1)
         {
            q[++r][0]=tmp;
            if (a[0]>q[l][1])
               q[r][1]=a[0];
            else
               q[r][1]=q[l][1];
            q[r][2]=p;
            d[a[0]][tmp][p]=d[q[l][1]][q[l][0]][q[l][2]]+1;
            f[a[0]][tmp][p]=t+1;
         }
      }
      l++;
   }
   int t[7];
   for (int i=6;i>=1;i--)
   {
      t[i]=b%10;
      b/=10;
   }
   int ans=1<<30;
   for (int i=1;i<=r;i++)
   {
      int p[7],x=q[i][0],sum=0;
      for (int j=6;j>=1;j--)
      {
         p[j]=x%10;
         x/=10;
      }      
      if (t[6]!=p[6] && !q[i][2] && q[i][1]!=6)
         continue;      
      sum+=abs(t[6]-p[6]);
      for (int j=2;j<=5;j++)
      {
         if (t[j]==p[j])
            continue;
         if (q[i][1]<j)
         {
            sum=-1;
            break;
         }
         sum+=abs(t[j]-p[j]);
      }
      if (sum==-1)
         continue;
      sum+=abs(t[1]-p[1]);
      if (sum+d[q[i][1]][q[i][0]][q[i][2]]<ans)
         ans=sum+d[q[i][1]][q[i][0]][q[i][2]];
   }
   printf("%d\n",ans);
}
