#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   void work();
   int t;
   scanf("%d",&t);
   while (t--)
      work();
   system("pause");
   return(0);
}
void work()
{
   int n=0,m,s,y,c,w[20],v[20],f[330]={0};
   scanf("%d%d%d%d",&m,&s,&y,&c);
   for (int i=1;i<=m;i++)
   {
      int p,q;
      scanf("%d%d",&p,&q);
      if (!f[q])
      {
         w[++n]=p;
         v[n]=q;
         f[q]=n;
      }
      else
         w[f[q]]>?=p;
   }
   double max=0;
   int k;
   for (int i=1;i<=n;i++)
      if (double(w[i])/v[i]>max || double(w[i])/v[i]==max && v[i]<v[k])
      {
         max=double(w[i])/v[i];
         k=i;
      }
   int limit=n*v[k];
   memset(f,0,sizeof(f));
   for (int i=1;i<=n;i++)
      for (int j=v[i];j<=limit;j++)
         f[j]>?=f[j-v[i]]+w[i];
   long long x[1001]={0};
   for (int i=1;i<=s;i++)
      for (int j=1;j<=i;j++)
      {
         long long p,t,s;
         p=(long long)y*j;
         t=(p-limit)/v[k]>?0;
         s=p-t*v[k];
         while (s>limit)
         {
            s-=v[k];
            t++;
         }
         x[i]>?=x[i-j]+t*w[k]+f[s]-(long long)c*(j-1);
      }
   printf("%lld\n",x[s]);
}
