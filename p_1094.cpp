#include <cstdio>
#include <cstdlib>
int main()
{
   while (1)
   {
      int n,m,pos,p,a[26][26]={0};
      bool flag=false;
      scanf("%d%d%*c",&n,&m);
      if (!n || !m)
         break;
      for (int i=1;i<=m;i++)
      {
         char c1,c2;
         scanf("%c<%c%*c",&c1,&c2);
         if (flag)
            continue;
         int x=c1-'A',y=c2-'A';
         if (a[x][y]==1)
         {
            flag=true;
            p=i;
            continue;
         }
         if (!a[x][y])
            pos=i;
         a[x][y]=-1,a[y][x]=1;
         for (int j=0;j<n;j++)
         {
            if (a[y][j]==-1)
            {
               if (a[x][j]==1)
               {
                  flag=true;
                  p=i;
                  break;
               }
               if (!a[x][j])
                  pos=i;
               a[x][j]=-1,a[j][x]=1;
            }
            if (a[j][x]==-1)
            {
               if (a[j][y]==1)
               {
                  flag=true;
                  p=i;
                  break;
               }
               if (!a[j][y])
                  pos=i;
               a[j][y]=-1,a[y][j]=1;
            }
         }
      }
      int sum=0;
      for (int i=0;i<n;i++)
         for (int j=0;j<n;j++)
            if (i!=j && !a[i][j])
               sum++;
      if (!sum)
         flag=false;
      if (flag)
         printf("Inconsistency found after %d relations.\n",p);
      else
      {
         int s[26]={0};
         for (int i=0;i<n;i++)
         {
            for (int j=0;j<n;j++)
            {
               if (i==j)
                  continue;
               if (!a[i][j])
               {
                  flag=true;
                  break;
               }
               if (a[i][j]==1)
                  s[i]++;
            }
            if (flag)
               break;
         }
         if (flag)
            printf("Sorted sequence cannot be determined.\n");
         else
         {
            int ans[26];
            for (int i=0;i<n;i++)
               ans[s[i]]=i;
            printf("Sorted sequence determined after %d relations: ",pos);
            for (int i=0;i<n;i++)
               printf("%c",ans[i]+'A');
            printf(".\n");
         }
      }
   }
   system("pause");
   return(0);
}
