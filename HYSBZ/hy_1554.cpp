#include <cstdio>
#include <cstdlib>
#include <cstring>
int s,a[20];
long long n,m,f[20][10][200],g[20][10][200];
int main()
{
   void prepare(),work();
   scanf("%I64d%I64d",&n,&m);
   while (n!=0 && m!=0)
   {
      prepare();
      work();
      scanf("%I64d%I64d",&n,&m);
   }
   system("pause");
   return(0);
}
void prepare()
{
   void str(long long,char *);
   int i,j,k,l;
   char st[260];
   memset(a,0,sizeof(a));
   memset(f,0,sizeof(f));
   memset(g,0,sizeof(g));
   str(n,st);
   s=strlen(st);
   for (i=1;i<=s;i++)
      a[i]=st[i-1]-'0';
   for (i=0;i<=9;i++)
      f[s][i][i]=1;
   for (i=0;i<=a[s];i++)
      g[s][i][i]=1;
   for (i=s;i>=2;i--)
   {
      for (j=0;j<=9;j++)
         for (k=0;k<=9*(s-i+1);k++)
            for (l=0;l<=9;l++)
            {
               f[i-1][l][k+l]+=f[i][j][k];
               if (l<a[i-1] || (l==a[i-1] && j<a[i]))
                  g[i-1][l][k+l]+=f[i][j][k];
               if (l==a[i-1] && j==a[i])
                  g[i-1][l][k+l]+=g[i][j][k];
            }
   }
}
void work()
{
   void str(long long,char *);
   long long calc(long long);
   int i,c,d;
   long long left,right,mid,k;
   char st[260],stt[260];
   str(m,stt);
   c=0;
   for (i=0;i<strlen(stt);i++)
      c+=stt[i]-'0';
   left=1;
   right=n;
   while (1)
   {
      mid=(left+right)/2;
      k=calc(mid+1);
      str(k,st);
      d=0;
      for (i=0;i<strlen(st);i++)
         d+=st[i]-'0';
      if (k==m)
         break;
      if (d<c || (d==c && strcmp(st,stt)<0))
         left=mid+1;
      else
         right=mid-1;
   }
   printf("%I64d %I64d\n",mid,calc(m+1));
}
void str(long long n,char *st)
{
   int s,i;
   int a[20];
   s=-1;
   while (1)
   {
      s++;
      a[s]=n%10;
      n/=10;
      if (n==0)
         break;
   }
   for (i=s;i>=0;i--)
      st[i]=a[s-i]+'0';
   st[s+1]='\0';
}
long long calc(long long p)
{
   int i,j,w,r,last,flag;
   long long q,ans;
   ans=0;
   for (r=0;r<=9*s;r++)
   {
      q=0;
      for (i=0;i<=a[1];i++)
         q+=g[1][i][r];
      if (q<p)
         p-=q;
      else
         break;
   }
   last=0;
   flag=1;
   if (r>9*s)
      r=9*s;
   while (p>0)
   {
      if (last==0)
         w=1;
      else
         w=0;
      for (i=w;i<=9;i++)
      {
         q=0;
         for (j=last+1;j<=s;j++)
            if (j==last+1 && flag)
               q+=g[j][i][r];
            else
               q+=f[j][i][r];
         if (q<p)
            p-=q;
         else
            break;
      }
      if (i>9)
         i=9;
      if (flag && i>a[last+1])
      {
         last++;
         flag=0;
      }
      if (i!=a[last+1])
         flag=0;
      last++;
      ans=ans*10+i;
      r-=i;
      if (r==0)
         p--;
   }
   return(ans);
}
