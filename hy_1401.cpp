#include <cstdio>
#include <cstdlib>
#include <cstring>
int m,ans,a[1500],x[1500],y[1500];
int main()
{
   void work();
   int i,j,n;
   char ch,temp;
   while (1)
   {
      scanf("%d%*c",&n);
      if (n==0)
         break;
      m=0;
      for (i=1;i<=n;i++)
      {
         for (j=1;j<=n-i;j++)
            scanf("%*c");
         for (j=1;j<=n+i-1;j++)
         {
            scanf("%c%c",&ch,&temp);
            m++;
            if (ch=='.')
               a[m]=0;
            else
               a[m]=ch-'A'+1;
            x[m]=i;
            y[m]=j;
         }
         while (temp!='\n')
            scanf("%c",&temp);
      }
      for (i=n+1;i<=2*n-1;i++)
      {
         for (j=1;j<=i-n;j++)
            scanf("%*c");
         for (j=i-n+1;j<=2*n-1;j++)
         {
            scanf("%c%c",&ch,&temp);
            m++;
            if (ch=='.')
               a[m]=0;
            else
               a[m]=ch-'A'+1;
            x[m]=i;
            y[m]=j;
         }
         while (temp!='\n')
            scanf("%c",&temp);
      }
      ans=20000000;
      work();
      printf("You have to buy %d parcels.\n",ans);
   }
   system("pause");
   return(0);
}
void work()
{
   int dist(int,int);
   int i,j,k,x,y,s;
   int b[5],flag[5],f[5][5],g[5][1500];
   memset(f,26,sizeof(f));
   memset(g,26,sizeof(g));
   for (i=1;i<=m;i++)
   {
      if (a[i]==0)
         continue;
      for (j=1;j<=m;j++)
      {
         x=dist(i,j);
         if (a[j]!=0 && x<f[a[i]][a[j]])
            f[a[i]][a[j]]=x;
         if (x<g[a[i]][j])
            g[a[i]][j]=x;
      }
   }
   memset(flag,0,sizeof(flag));
   memcpy(b,f[1],sizeof(f[1]));
   flag[1]=1;
   s=0;
   for (i=2;i<=4;i++)
   {
      k=1;
      while (flag[k])
         k++;
      for (j=1;j<=4;j++)
         if (!flag[j] && b[j]<b[k])
            k=j;
      flag[k]=1;
      s+=b[k];
      for (j=1;j<=4;j++)
         if (!flag[j] && f[k][j]<b[j])
            b[j]=f[k][j];
   }
   if (s<ans)
      ans=s;
   for (i=1;i<=m;i++)
   {
      if (a[i]!=0)
         continue;
      x=0;
      for (j=1;j<=4;j++)
         x+=g[j][i];
      for (j=1;j<=4;j++)
      {
         y=g[j][i];
         for (k=1;k<=4;k++)
         {
            if (j==k)
               continue;
            if (f[j][k]<y)
               y=f[j][k];
            if (x-g[j][i]+y+1<ans)
               ans=x-g[j][i]+y+1;
         }
      }
   }
   for (i=1;i<=m-1;i++)
   {
      if (a[i]!=0)
         continue;
      for (j=i+1;j<=m;j++)
      {
         if (a[j]!=0)
            continue;
         x=dist(i,j);
         for (k=1;k<=4;k++)
            if (g[k][i]<g[k][j])
               x+=g[k][i];
            else
               x+=g[k][j];
         if (x+2<ans)
            ans=x+2;
      }
   }
}
int dist(int i,int j)
{
   if (i==j)
      return(0);
   if (x[i]>x[j] && y[i]<=y[j])
      return(abs(x[i]-x[j])+abs(y[i]-y[j])-1);
   if (x[i]<=x[j] && y[i]>y[j])
      return(abs(x[i]-x[j])+abs(y[i]-y[j])-1);
   if (abs(x[i]-x[j])>abs(y[i]-y[j]))
      return(abs(x[i]-x[j])-1);
   else
      return(abs(y[i]-y[j])-1);
}
