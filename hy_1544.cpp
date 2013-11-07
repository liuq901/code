#include <cstdio>
#include <cstdlib>
#include <cstring>
struct data
{
   int num,d;
   int a[4];
};
struct data g[200001],ls[200001],xyz[200001],yzx[200001],zxy[200001];
int w1[200001],w2[200001],w3[200001],map[200001][6];
int main()
{
   void sort(int,int,int,int,int);
   int i,j,k,n,m,p,q,aim,len;
   int ans[6],total[6],b[6][6];
   memset(b,-1,sizeof(b));
   b[0][4]=3,b[0][5]=2,b[0][3]=4,b[0][2]=5;
   b[1][4]=2,b[1][5]=3,b[1][3]=5,b[1][2]=4;
   b[2][4]=1,b[2][5]=0,b[2][1]=4,b[2][0]=5;
   b[3][4]=0,b[3][5]=1,b[3][1]=5,b[3][0]=4;
   b[4][3]=0,b[4][2]=1,b[4][1]=2,b[4][0]=3;
   b[5][3]=1,b[5][2]=0,b[5][1]=3,b[5][0]=2;
   for (i=0;i<=5;i++)
      for (j=0;j<=5;j++)
         if (b[i][j]==-1)
            b[i][j]=j;
   scanf("%d",&len);
   scanf("%d",&n);
   for (i=1;i<=n;i++)
   {
      scanf("%d%d%d%d",&g[i].a[1],&g[i].a[2],&g[i].a[3],&g[i].d);
      g[i].num=i;
   }
   m=n;
   memcpy(ls,g,sizeof(g));
   sort(1,m,1,2,3);
   memcpy(xyz,g,sizeof(g));
   memcpy(g,ls,sizeof(ls));
   sort(1,m,2,3,1);
   memcpy(yzx,g,sizeof(g));
   memcpy(g,ls,sizeof(ls));
   sort(1,m,3,1,2);
   memcpy(zxy,g,sizeof(g));
   memcpy(g,ls,sizeof(ls));
   for (i=1;i<=m;i++)
   {
      w1[xyz[i].num]=i;
      w2[yzx[i].num]=i;
      w3[zxy[i].num]=i;
   }
   for (i=1;i<=m;i++)
   {
      j=w1[i];
      if (j==1 || xyz[j-1].a[1]!=xyz[j].a[1] || xyz[j-1].a[2]!=xyz[j].a[2])
         map[i][1]=-1;
      else
         map[i][1]=xyz[j-1].num;
      if (j==m || xyz[j+1].a[1]!=xyz[j].a[1] || xyz[j+1].a[2]!=xyz[j].a[2])
         map[i][0]=-1;
      else
         map[i][0]=xyz[j+1].num;
      j=w2[i];
      if (j==1 || yzx[j-1].a[2]!=yzx[j].a[2] || yzx[j-1].a[3]!=yzx[j].a[3])
         map[i][3]=-1;
      else
         map[i][3]=yzx[j-1].num;
      if (j==m || yzx[j+1].a[2]!=yzx[j].a[2] || yzx[j+1].a[3]!=yzx[j].a[3])
         map[i][2]=-1;
      else
         map[i][2]=yzx[j+1].num;
      j=w3[i];
      if (j==1 || zxy[j-1].a[3]!=zxy[j].a[3] || zxy[j-1].a[1]!=zxy[j].a[1])
         map[i][5]=-1;
      else
         map[i][5]=zxy[j-1].num;
      if (j==m || zxy[j+1].a[3]!=zxy[j].a[3] || zxy[j+1].a[1]!=zxy[j].a[1])
         map[i][4]=-1;
      else
         map[i][4]=zxy[j+1].num;
   }
   memset(ans,0,sizeof(ans));
   memset(total,0,sizeof(total));
   k=0;
   for (i=1;i<=m;i++)
      if (map[i][5]==-1)
      {
         k++;
         p=i;
         q=4;
         j=0;
         while (1)
         {
            aim=b[g[p].d][q];
            if (aim!=q)
               j++;
            p=map[p][aim];
            q=aim;
            if (p==-1)
               break;
         }
         ans[q]++;
         total[q]+=j;
      }
   ans[4]+=(len+1)*(len+1)-k;
   for (i=0;i<=5;i++)
   {
      printf("%d\n",ans[i]);
      printf("%d\n",total[i]);
   }
   system("pause");
   return(0);
}
void sort(int l,int r,int p1,int p2,int p3)
{
   int i,j;
   struct data x,ls;
   i=l;
   j=r;
   x=g[(l+r)/2];
   while (i<j)
   {
      while (g[i].a[p1]<x.a[p1] || (g[i].a[p1]==x.a[p1] && g[i].a[p2]<x.a[p2])
         || (g[i].a[p1]==x.a[p1] && g[i].a[p2]==x.a[p2] && g[i].a[p3]<x.a[p3]))
         i++;
      while (g[j].a[p1]>x.a[p1] || (g[j].a[p1]==x.a[p1] && g[j].a[p2]>x.a[p2])
         || (g[j].a[p1]==x.a[p1] && g[j].a[p2]==x.a[p2] && g[j].a[p3]>x.a[p3]))
         j--;
      if (i<=j)
      {
         ls=g[i],g[i]=g[j],g[j]=ls;
         i++,j--;
      }
   }
   if (i<r)
      sort(i,r,p1,p2,p3);
   if (l<j)
      sort(l,j,p1,p2,p3);
}
