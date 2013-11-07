#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[101][101];
int main()
{
   void print(int,int);
   int i,j,k,n,m,l,p,q,ans;
   int f[101][101],g[101][101],c[101][101];
   scanf("%d",&n);
   while (n!=-1)
   {                
      scanf("%d",&m);
      memset(g,0,sizeof(g));
      memset(c,0,sizeof(c));
      for(i=1;i<=m;i++)
      {
         scanf("%d%d%d",&j,&k,&l);
         if (g[j][k]>l || g[j][k]==0)
         {
            g[j][k]=l;
            g[k][j]=l;
         }
      }
      memcpy(f,g,sizeof(g));
      ans=0;
      p=0;
      q=0;
      l=0;
      for (k=1;k<=n;k++)
      {         
         for (i=1;i<=n;i++)
            if (g[i][k]>0)
               for (j=i+1;j<=n;j++)
                  if (g[k][j]>0 && f[i][j]>0)
                     if (ans==0 || ans>g[i][k]+g[k][j]+f[i][j])
                     {
                        ans=g[i][k]+g[k][j]+f[i][j];
                        p=i;
                        q=j;
                        l=k;
                        memcpy(a,c,sizeof(c));
                     }
         for (i=1;i<=n;i++)
            if (f[i][k]>0)
               for (j=i+1;j<=n;j++)
                  if (f[k][j]>0)
                     if (f[i][j]==0 || f[i][j]>f[i][k]+f[k][j])
                     {
                        f[i][j]=f[i][k]+f[k][j];
                        f[j][i]=f[i][j];
                        c[i][j]=k;
                        c[j][i]=k;                        
                     }        
      }
      if (ans==0)
         printf("No solution.\n");
      else 
      {
         printf("%d %d ",l,p);
         if (a[p][q]>0)
            print(p,q);
         printf("%d\n",q);
      }
      scanf("%d",&n);               
   }    
   system("pause");
   return(0);
}
void print(int l,int r)
{   
   int t;
   t=a[l][r];
   if (a[l][t]>0)
      print(l,t);
   printf("%d ",t);
   if (a[t][r]>0)
      print(t,r);
}
