#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
long long f[2][55][37][19][19],g[2][55][37][19][19];
int n,p[40],ans[50],q[10][5];
int main()
{
   long long power(int,int);
   void add(long long,long long),init(),work(),print(int);
   scanf("%d%*c",&n);
   char s[40];
   int a[40];
   scanf("%s",&s);
   for (int i=1;i<=2*n;i++)
      if (isdigit(s[i-1]))
         a[i]=s[i-1]-'0';
      else
         a[i]=-1;
   bool flag1,flag2;
   long long s1,s2;
   flag1=flag2=false;
   int sum=0,tot;
   for (int i=1;i<=n;i++)
   {
      if (a[i]==0)
         flag1=true;
      if (a[i]==-1)
         sum++;
   }
   if (flag1)
      s1=power(10,sum);
   else
      s1=power(10,sum)-power(9,sum);
   tot=sum;
   sum=0;
   for (int i=n+1;i<=2*n;i++)
   {
      if (a[i]==0)
         flag2=true;
      if (a[i]==-1)
         sum++;
   }
   if (flag2)
      s2=power(10,sum);
   else
      s2=power(10,sum)-power(9,sum);
   tot+=sum;
   ans[0]=1;
   add(s1,s2);
   if (!flag1 && !flag2)
   {
      memcpy(p,a,sizeof(a));
      init();
      work();
   }
   print(tot);
   system("pause");
   return(0);
}
long long power(int x,int t)
{
   long long ans=1;
   for (int i=1;i<=t;i++)
      ans*=x;
   return(ans);
}
void init()
{
   q[2][1]=1;
   q[3][2]=1;
   q[4][1]=2;
   q[5][3]=1;
   q[6][1]=1;
   q[6][2]=1;
   q[7][4]=1;
   q[8][1]=3;
   q[9][2]=2;
}
void work()
{
   void add(long long,long long);
   f[0][0][0][0][0]=1;
   for (int i=0;i<=n-1;i++)
   {
      int k1=i&1,k2=1-(i&1);
      for (int a=0;a<=3*i;a++)
         for (int b=0;b<=2*i;b++)
            for (int c=0;c<=i;c++)
               for (int d=0;d<=i;d++)
               {
                  if (f[k1][a][b][c][d]==0)
                     continue;
                  int x=p[i+1];
                  if (x>0)
                     f[k2][a+q[x][1]][b+q[x][2]][c+q[x][3]][d+q[x][4]]=f[k1][a][b][c][d];
                  else
                     for (int t=1;t<=9;t++)
                        f[k2][a+q[t][1]][b+q[t][2]][c+q[t][3]][d+q[t][4]]+=f[k1][a][b][c][d];
                  f[k1][a][b][c][d]=0;
               }
   }
   g[0][0][0][0][0]=1;
   for (int i=0;i<=n-1;i++)
   {
      int k1=i&1,k2=1-(i&1);
      for (int a=0;a<=3*i;a++)
         for (int b=0;b<=2*i;b++)
            for (int c=0;c<=i;c++)
               for (int d=0;d<=i;d++)
               {
                  if (g[k1][a][b][c][d]==0)
                     continue;
                  int x=p[i+n+1];
                  if (x>0)
                     g[k2][a+q[x][1]][b+q[x][2]][c+q[x][3]][d+q[x][4]]=g[k1][a][b][c][d];
                  else
                     for (int t=1;t<=9;t++)
                        g[k2][a+q[t][1]][b+q[t][2]][c+q[t][3]][d+q[t][4]]+=g[k1][a][b][c][d];
                  g[k1][a][b][c][d]=0;
               }
   }
   int k=n&1;
   for (int a=0;a<=3*n;a++)
      for (int b=0;b<=2*n;b++)
         for (int c=0;c<=n;c++)
            for (int d=0;d<=n;d++)
               add(f[k][a][b][c][d],g[k][a][b][c][d]);
}
void add(long long x,long long y)
{
   if (x==0 || y==0)
      return;
   int a[30]={0},b[30]={0};
   while (x!=0)
   {
      a[0]++;
      a[a[0]]=x%10000;
      x/=10000;
   }
   while (y!=0)
   {
      b[0]++;
      b[b[0]]=y%10000;
      y/=10000;
   }
   int c[50]={0};
   for (int i=1;i<=a[0];i++)
      for (int j=1;j<=b[0];j++)
      {
         c[i+j-1]+=a[i]*b[j];
         c[i+j]+=c[i+j-1]/10000;
         c[i+j-1]%=10000;
      }
   c[0]=a[0]+b[0];
   while (c[c[0]]==0 && c[0]>1)
      c[0]--;
   if (c[0]>ans[0])
      ans[0]=c[0];
   int t=0;
   for (int i=1;i<=ans[0];i++)
   {
      ans[i]+=c[i]+t;
      t=ans[i]/10000;
      ans[i]%=10000;
   }
   while (t!=0)
   {
      ans[0]++;
      ans[ans[0]]=t%10000;
      t/=10000;
   }
}
void print(int tot)
{
   printf("%d",ans[ans[0]]);
   for (int i=ans[0]-1;i>=1;i--)
      printf("%04d",ans[i]);
   printf("\n");
   int sum[50]={0};
   sum[0]=sum[1]=1;
   for (int i=1;i<=tot;i++)
   {
      int x=0;
      for (int j=1;j<=sum[0];j++)
      {
         sum[j]=sum[j]*10+x;
         x=sum[j]/10000;
         sum[j]%=10000;
      }
      while (x!=0)
      {
         sum[0]++;
         sum[sum[0]]=x%10000;
         x/=10000;
      }
   }
   int a[50]={0};
   for (int i=1;i<=sum[0];i++)
   {
      a[i]+=sum[i]-ans[i];
      if (a[i]<0)
      {
         a[i]+=10000;
         a[i+1]--;
      }
   }
   a[0]=sum[0];
   while (a[a[0]]==0 && a[0]>1)
      a[0]--;
   printf("%d",a[a[0]]);
   for (int i=a[0]-1;i>=1;i--)
      printf("%04d",a[i]);
   printf("\n");
}
