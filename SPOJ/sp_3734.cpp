#include <cstdio>
#include <cstdlib>
typedef long long int64;
const int prime=1000000007;
int n,m=1,a[501];
int64 g[501],len[501],w[501],c[501][501],f[501][501];
bool d[501][501];
int main()
{
   void init(int),work(int,int,int,int);
   int k;
   scanf("%d%d",&n,&k);
   if (k>n)
      printf("0\n");
   else
   {
      init(n);
      for (int i=1;i<=n;i++)
         scanf("%d",&a[i]);
      len[1]=n,f[1][0]=d[1][0]=1;
      work(1,1,n,0);
      printf("%I64d\n",f[1][k]);
   }
   system("pause");
   return(0);
}
void init(int n)
{
   for (int i=1;i<=n;i++)
   {
      c[i][0]=c[i][i]=1;
      for (int j=1;j<i;j++)
         c[i][j]=(c[i-1][j-1]+c[i-1][j])%prime;
   }
}
void work(int x,int l,int r,int height)
{
   int min(int,int);
   int now=++m;
   len[now]=r-l+1;
   int t=1<<30;
   for (int i=l;i<=r;i++)
      t=min(t,a[i]);
   int h=t-height,limit=min(h,len[now]),p=a[l]==t?0:l;
   f[now][0]=d[now][0]=1;
   for (int i=l;i<=r;i++)
      if (i<r && !p && a[i+1]!=t)
         p=i+1;
      else if (p>0 && (i==r || a[i+1]==t))
      {
         work(now,p,i,t);
         p=0;
      }
   w[1]=h;
   for (int i=2;i<=limit;i++)
      w[i]=(w[i-1]*(h-i+1))%prime;
   for (int i=0;i<=len[now];i++)
      g[i]=f[now][i];
   for (int i=len[now];i>=0;i--)
   {
      if (!d[now][i])
         continue;
      for (int j=1;j<=limit;j++)
      {
         if (i+j>len[now])
            break;
         g[i+j]+=f[now][i]*(w[j]*c[len[now]-i][j]%prime)%prime,g[i+j]%=prime;
         d[now][i+j]=true;
      }
   }
   for (int i=len[x];i>=0;i--)
   {
      if (!d[x][i])
         continue;
      for (int j=1;j<=len[now];j++)
      {
         if (i+j>len[x] || !d[now][j])
            break;
         f[x][i+j]+=(f[x][i]*g[j])%prime,f[x][i+j]%=prime;
         d[x][i+j]=true;
      }
   }
}
int min(int x,int y)
{
   return(x<y?x:y);
}
