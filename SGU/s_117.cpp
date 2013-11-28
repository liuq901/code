#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   int n,m,k,x,s,t,i,j,ans,flag;
   int a[10001],b[10001],c[10001],d[10001],f[10001];
   memset(f,0,sizeof(f));
   f[1]=1;
   for (i=2;i<=10000;i++)
   {
      if (f[i])
         continue;
      j=1;
      while (1)
      {
         j++;
         if (i*j>10000)
            break;
         f[i*j]=1;
      }
   }
   a[0]=0;
   for (i=2;i<=10000;i++)
      if (!f[i])
      {
         a[0]++;
         a[a[0]]=i;
      }
   scanf("%d%d%d",&n,&m,&k);
   if (k==1)
   {
      printf("%d\n",n);
      system("pause");
      exit(0);
   }
   t=1;
   x=a[t];
   s=0;
   memset(b,0,sizeof(b));
   while (1)
   {
      if (!f[k])
         break;
      if (k%x==0)
      {
         k/=x;
         b[x]++;
         if (b[x]==1)
         {
            s++;
            c[s]=x;
         }
      }
      else
      {
         t++;
         x=a[t];
      }
   }
   b[k]++;
   if (b[k]==1)
   {
      s++;
      c[s]=k;
   }
   ans=0;
   for (i=1;i<=n;i++)
   {
      scanf("%d",&k);
      if (k==1)
         continue;
      memset(d,0,sizeof(d));
      t=1;
      x=a[t];
      while (1)
      {
         if (!f[k])
            break;
         if (k%x==0)
         {
            k/=x;
            d[x]+=m;
         }
         else
         {
            t++;
            x=a[t];
         }
      }
      d[k]+=m;
      flag=1;
      for (j=1;j<=s;j++)
         if (b[c[j]]>d[c[j]])
         {
            flag=0;
            break;
         }
      ans+=flag;
   }
   printf("%d\n",ans);
   system("pause");
   return(0);
}
