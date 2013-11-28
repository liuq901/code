/*
ID: liuq9011
LANG: C++
TASK: butter
*/
#include <cstdio>
#include <cstring>
FILE *in,*out;
int s[801][801],t[801][801];
int main()
{
   in=fopen("butter.in","r");
   out=fopen("butter.out","w");
   int i,j,n,p,c,x,y,z,l,r,ans,sum;
   int b[501],a[100000],f[801],cost[801];
   fscanf(in,"%d%d%d",&n,&p,&c);
   for (i=1;i<=n;i++)
      fscanf(in,"%d",&b[i]);
   for (i=1;i<=p;i++)
      for (j=1;j<=p;j++)
         s[i][j]=2000000;
   memset(t,0,sizeof(t));
   for (i=1;i<=c;i++)
   {
      fscanf(in,"%d%d%d",&x,&y,&z);
      t[x][0]++;
      t[x][t[x][0]]=y;
      t[y][0]++;
      t[y][t[y][0]]=x;
      s[x][y]=z;
      s[y][x]=z;
   }
   ans=2000000;
   for (x=1;x<=p;x++)
   {
      memset(a,0,sizeof(a));
      memset(f,0,sizeof(f));
      for (i=1;i<=p;i++)
         cost[i]=2000000;
      cost[x]=0;
      f[x]=1;
      a[1]=x;
      l=r=1;
      while (l<=r)
      {
         y=a[l];
         for (i=1;i<=t[y][0];i++)
            if (cost[t[y][i]]>cost[y]+s[y][t[y][i]])
            {
               cost[t[y][i]]=cost[y]+s[y][t[y][i]];
               if (!f[t[y][i]])
               {
                  r++;
                  a[r]=t[y][i];
                  f[t[y][i]]=1;
               }
            }
         f[y]=0;
         l++;
      }
      sum=0;
      for (i=1;i<=n;i++)
         sum+=cost[b[i]];
      if (sum<ans)
         ans=sum;
   }
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
