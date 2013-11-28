#include <cstdio>
#include <cstdlib>
#include <cstring>
int d[501][501],f[501][501];
int m,n,k=1;
struct adf
{
   int x,y,h;
}p[250001];
int main()
{  
   void input(),dp();
   input();
   dp();
   system("pause");
   return(0);
}
void input()
{  
   void build();
   int i,j;
   scanf("%d%d",&n,&m);
   for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      { 
         scanf("%d",&d[i][j]);
         p[k].h=d[i][j];
         p[k].x=i,p[k].y=j;
         k++;
      }
   k--;
   memset(f,0,sizeof(f)); 
   build();
}
void build()
{
   void sift(int,int);
   struct adf t;
   int i;
   for (i=k/2;i>0;i--)
      sift(i,k);
   for (i=k;i>1;i--)
   {
      t=p[1];
      p[1]=p[i];
      p[i]=t;
      sift(1,i-1);
   }
}
void sift(int low,int high)
{ 
   int i=low,j=2*i;
   int t=p[i].h;
   struct adf tmp=p[i];
   while (j<=high)
   {
      if (j<high && p[j].h>p[j+1].h)
         j++;
      if(t>p[j].h)
      { 
         p[i]=p[j];
         i=j;
         j=i*2;
      }
      else 
         break;
   }
   p[i]=tmp;
}
void dp()
{
   int i,s,t,x,y;
   int best=0;
   const int fx[4]={0,1,0,-1};
   const int fy[4]={1,0,-1,0};
   for (i=1;i<=k;i++)
   { 
      t=p[i].h,x=p[i].x,y=p[i].y;
      for (s=0;s<4;s++) 
      { 
         if (x+fx[s]>n || x+fx[s]<1)
            continue;
         if (y+fy[s]>m || y+fy[s]<1)
            continue;
         if (d[x+fx[s]][y+fy[s]]<t && f[x][y]+1>f[x+fx[s]][y+fy[s]])
            f[x+fx[s]][y+fy[s]]=f[x][y]+1;
         if (best<f[x+fx[s]][y+fy[s]])
            best=f[x+fx[s]][y+fy[s]];
      }
   }
   printf("%d\n",best+1);
}
