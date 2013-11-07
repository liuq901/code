#include <cstdio>
#include <cstdlib>
#include <cstring>
bool a[1001][1001];
int main()
{
   while (1)
   {
      int n,m;
      scanf("%d%d",&n,&m);
      if (!n && !m)
         break;
      memset(a,0,sizeof(a));
      for (int i=1;i<=m;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         a[x][y]=a[y][x]=true;
      }
      bool f[1001]={0};
      int b[1001],s[1001]={0};
      for (int i=n;i>=1;i--)
      {
         int max=-1,k;
         for (int j=1;j<=n;j++)
         {
            if (f[j])
               continue;
            if (s[j]>max)
            {
               max=s[j];
               k=j;
            }
         }
         b[i]=k;
         f[k]=true;
         for (int j=1;j<=n;j++)
            s[j]+=a[k][j];
      }
      int c[1001];
      bool flag=true;
      for (int i=1;i<=n-1;i++)
      {
         c[0]=0;
         int x=b[i];
         for (int j=i+1;j<=n;j++)
         {
            int y=b[j];
            if (a[x][y])
               c[++c[0]]=b[j];
         }
         if (c[0]<=1)
            continue;
         for (int j=2;j<=c[0];j++)
            if (!a[c[1]][c[j]])
            {
               flag=false;
               break;
            }
         if (!flag)
            break;
      }
      printf("%s\n\n",flag?"Perfect":"Imperfect");
   }
   system("pause");
   return(0);
}
