#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
const int limit=3;
const int w[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
const double eps=1e-10,oo=1e100;
int n,m,xx,yy,num;
char map[20][20];
int sign[1200],id[3][20][20],flag[3][20][20];
double ans[1200],cnt[20][20],f[1200][1200];
int main()
{
   void prepare(),work();
   prepare();
   work();
   system("pause");
   return(0);
}
void prepare()
{
   void build();
   int i,j,k,u,v;
   num=0;
   scanf("%d%d",&n,&m);
   gets(map[0]);
   for (i=0;i<n;i++)
   {
      gets(map[i]);
      for (j=0;j<m;j++)
         if (map[i][j]=='$')
         {
            xx=i;
            yy=j;
         }
   }
   memset(cnt,0,sizeof(cnt));
   for (i=0;i<n;i++)
      for (j=0;j<m;j++)
         if (map[i][j]<'a' || map[i][j]>'z')
            for (k=0;k<4;k++)
            {
               u=i+w[k][0];
               v=j+w[k][1];
               if (u>=0 && u<n && v>=0 && v<m && map[u][v]!='#')
                  cnt[i][j]++;
            }
   build();
}
void build()
{
   int i,j,k,l,u,v;
   for (k=0;k<limit;k++)
      for (i=0;i<n;i++)
         for (j=0;j<m;j++)
         {
            id[k][i][j]=num;
            num++;
            flag[k][i][j]=1;
         }
   for (k=0;k<limit;k++)
      for (i=0;i<n;i++)
         for (j=0;j<m;j++)
         {
            f[id[k][i][j]][id[k][i][j]]=1;
            if (map[i][j]>='a' && map[i][j]<='z')
            {
               for (u=0;u<n;u++)
                  for (v=0;v<m;v++)
                     if (map[u][v]-'A'+'a'==map[i][j])
                        f[id[k][i][j]][id[k][u][v]]=-1;
            }
            else if (map[i][j]!='!')
               for (l=0;l<4;l++)
               {
                  u=i+w[l][0];
                  v=j+w[l][1];
                  if (u>=0 && u<n && v>=0 && v<m && map[u][v]!='#')
                     f[id[k][i][j]][id[k][u][v]]=-1/cnt[i][j];
               }
         }
   for (k=0;k<limit-1;k++)
      for (i=0;i<n;i++)
         for (j=0;j<m;j++)
            if (map[i][j]=='!')
               for (l=0;l<4;l++)
               {
                  u=i+w[l][0];
                  v=j+w[l][1];
                  if (u>=0 && u<n && v>=0 && v<m && map[u][v]!='#')
                     f[id[k][i][j]][id[k+1][u][v]]=-1/cnt[i][j];
               }
   for (k=0;k<limit;k++)
      for (i=0;i<n;i++)
         for (j=0;j<m;j++)
            if (map[i][j]>='0' && map[i][j]<='9')
               f[id[k][i][j]][num]=map[i][j]-'0';
}
void work()
{
   double divide(double,double),mul(double,double);
   double temp;
   int tmp,i,j,k;
   for (i=0;i<num;i++)
   {
      sign[i]=1;
      if (fabs(f[i][i])>eps)
      {
         for (j=i+1;j<num;j++)
            if (fabs(f[j][i])>eps)
            {
               temp=divide(f[j][i],f[i][i]);
               for (k=i;k<=num;k++)
                  f[j][k]-=mul(f[i][k],temp);
            }
      }
   }
   for (i=num-1;i>=0;i--)
   {
      if (sign[i])
         ans[i]=divide(f[i][num],f[i][i]);
      if (ans[i]==oo)
         sign[i]=0;
      for (j=i-1;j>=0;j--)
         if (fabs(f[j][i])>eps)
         {
            if (!sign[i])
               sign[j]=0;
            f[j][num]-=mul(f[j][i],ans[i]);
         }
   }
   temp=ans[id[0][xx][yy]];
   if (!sign[id[0][xx][yy]])
      printf("-1\n");
   else
      printf("%.9lf\n",temp);
}
double divide(double x,double y)
{
   if (fabs(x)<=eps)
      return(0);
   if (fabs(y)<=eps)
      return(oo);
   return(x/y);
}
double mul(double x,double y)
{
   if (fabs(x)<=eps || fabs(y)<=eps)
      return(0);
   return(x*y);
}
