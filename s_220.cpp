#include <cstdio>
#include <cstdlib>
#include <cstring>
int ans[10000],f[51][100][100],g[51][100][100];
int main()
{
   void multi(int *,int,int *),plus(int *,int *,int *),print(int,int,int);
   int n,k,i,j,t;
   int a[51],b[51],s[100];
   scanf("%d%d",&n,&k);
   if (k>2*n-1)
      printf("0\n");
   else
   {
      memset(a,-1,sizeof(a));
      memset(b,-1,sizeof(b));
      a[0]=n;
      for (i=1;i<=n/2;i++)
      {
         a[2*i-1]=2*i-1;
         a[2*i]=2*i-1;
      }
      if (n%2==1)
         a[n]=n;
      b[0]=n-1;
      for (i=1;i<=(n-1)/2;i++)
      {
         b[2*i-1]=2*i;
         b[2*i]=2*i;
      }
      if (n%2==0)
         b[n-1]=n;
      memset(f,0,sizeof(f));
      memset(g,0,sizeof(g));
      for (i=1;i<=k;i++)
      {
         f[0][i][0]=1;
         f[0][i][1]=0;
      }
      for (i=0;i<=a[0];i++)
      {
         f[i][0][0]=1;
         f[i][0][1]=1;
      }
      for (i=1;i<=a[0];i++)
         for (j=1;j<=k;j++)
         {
            memset(s,0,sizeof(s));
            multi(s,a[i]-j+1,f[i-1][j-1]);
            plus(f[i][j],f[i-1][j],s);
         }
      for (i=1;i<=k;i++)
      {
         g[0][i][0]=1;
         g[0][i][1]=0;
      }
      for (i=0;i<=b[0];i++)
      {
         g[i][0][0]=1;
         g[i][0][1]=1;
      }
      for (i=1;i<=b[0];i++)
         for (j=1;j<=k;j++)
         {
            memset(s,0,sizeof(s));
            multi(s,b[i]-j+1,g[i-1][j-1]);
            plus(g[i][j],g[i-1][j],s);
         }
      f[a[0]][0][0]=1;
      f[a[0]][0][1]=1;
      g[b[0]][0][0]=1;
      g[b[0]][0][1]=1;
      print(a[0],b[0],k);
   }
   system("pause");
   return(0);
}
void multi(int *b,int t,int *a)
{
   int i,x;
   x=0;
   for (i=1;i<=a[0];i++)
   {
      b[i]=a[i]*t+x;
      x=b[i]/10;
      b[i]%=10;
   }
   b[0]=a[0];
   while (x!=0)
   {
      b[0]++;
      b[b[0]]=x%10;
      x/=10;
   }
}
void plus(int *c,int *a,int *b)
{
   int i,x;
   x=0;
   if (a[0]>b[0])
      c[0]=a[0];
   else
      c[0]=b[0];
   for (i=1;i<=c[0];i++)
   {
      c[i]+=a[i]+b[i]+x;
      x=c[i]/10;
      c[i]%=10;
   }
   while (x!=0)
   {
      c[0]++;
      c[c[0]]=x%10;
      x/=10;
   }
}
void print(int x,int y,int k)
{
   void count(int,int,int,int);
   int i;
   memset(ans,0,sizeof(ans));
   for (i=0;i<=k;i++)
      count(x,y,i,k-i);
   if (ans[0]==0)
   {
      ans[0]=1;
      ans[1]=0;
   }
   for (i=ans[0];i>=1;i--)
      printf("%d",ans[i]);
   printf("\n");
}
void count(int x,int y,int p,int q)
{
   int i,j,t;
   int s[10000];
   memset(s,0,sizeof(s));
   for (i=1;i<=f[x][p][0];i++)
      for (j=1;j<=g[y][q][0];j++)
      {
         s[i+j-1]+=f[x][p][i]*g[y][q][j];
         s[i+j]+=s[i+j-1]/10;
         s[i+j-1]%=10;
      }
   s[0]=f[x][p][0]+g[y][q][0];
   while (s[s[0]]==0 && s[0]>0)
      s[0]--;
   if (s[0]>ans[0])
      ans[0]=s[0];
   t=0;
   for (i=1;i<=ans[0];i++)
   {
      ans[i]+=s[i]+t;
      t=ans[i]/10;
      ans[i]%=10;
   }
   while (t!=0)
   {
      ans[0]++;
      ans[ans[0]]=t%10;
      t/=10;
   }
}
