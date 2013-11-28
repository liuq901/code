#include <cstdio>
#include <cstdlib>
#include <cstring>
const int p=1000;
int n,a[2000],b[2000],s[2000],l[5000],r[5000],v[5000],f[5000][2000];
int main()
{
   void calc(int),work();
   int m,i,j,rt;
   int ans[2000];
   char ch;
   scanf("%d%d%d",&n,&m,&rt);
   for (i=1;i<=m;i++)
      scanf("%d%d",&l[i+p],&r[i+p]);
   memset(v,0,sizeof(v));
   memset(f,0,sizeof(f));
   memset(b,0,sizeof(b));
   memset(ans,0,sizeof(ans));
   calc(rt);
   memcpy(b,f[rt+p],sizeof(f[rt+p]));
   scanf("%*c");
   for (i=1;i<=n;i++)
   {
      scanf("%c",&ch);
      a[i+p]=ch-'0';
   }
   scanf("%*c");
   work();
   for (i=0;i<=n;i++)
      s[i+p]=-s[i+p];
   j=0;
   for (i=1;i<=n;i++)
   {
      scanf("%c",&ch);
      a[i+p]=ch-'0';
      if (a[i+p] && b[i+p])
         j^=1;
   }
   s[0+p]+=j;
   work();
   for (i=0;i<=n-1;i++)
   {
      while (s[i+p]<0)
      {
         s[i+1+p]--;
         s[i+p]+=2;
      }
      while (s[i+p]>1)
      {
         s[i+1+p]++;
         s[i+p]-=2;
      }
   }
   ans[0+p]=1;
   for (i=n-1;i>=0;i--)
   {
      for (j=1;j<=ans[0+p];j++)
         ans[j+p]<<=1;
      if (s[i+p]==1)
         ans[1+p]++;
      for (j=1;j<=ans[0+p];j++)
         if (ans[j+p]>=10)
         {
            ans[j+1+p]++;
            ans[j+p]-=10;
         }
      if (ans[ans[0+p]+1+p]>0)
         ans[0+p]++;
   }
   for (i=ans[0+p];i>=1;i--)
      printf("%d",ans[i+p]);
   printf("\n");
   system("pause");
   return(0);
}
void calc(int rt)
{
   int i,ll,rr;
   if (v[rt+p])
      return;
   v[rt+p]=1;
   if (rt<0)
      f[rt+p][-rt+p]=1;
   else
   {
      ll=l[rt+p];
      calc(ll);
      rr=r[rt+p];
      calc(rr);
      for (i=1;i<=n;i++)
         f[rt+p][i+p]=f[ll+p][i+p]^f[rr+p][i+p];
   }
}
void work()
{
   int i,pre,next;
   pre=next=0;
   for (i=1;i<=n;i++)
      if (b[i+p])
         next++;
   for (i=1;i<=n;i++)
   {
      if (b[i+p])
         next--;
      if (a[i+p])
         if (next>0)
            s[n-i-1+p]++;
         else if (pre)
            s[n-i+p]++;
      if (a[i+p] && b[i+p])
         pre=1-pre;
   }
}
