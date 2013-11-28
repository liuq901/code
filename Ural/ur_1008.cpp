#include <cstdio>
#include <cstdlib>
#include <cstring>
const int c[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const char ans[]="RTLB";
bool map[26][26];
int main()
{
   void work(int);
   int count(char);
   char s[100];
   gets(s);
   if (!strstr(s," "))
   {
      int n;
      sscanf(s,"%d",&n);
      work(n);
   }
   else
   {
      int x0,y0;
      sscanf(s,"%d%d",&x0,&y0);
      int l,r,q[101][2];
      l=r=1,q[1][0]=x0,q[1][1]=y0;
      while (l<=r)
      {
         int x=q[l][0],y=q[l][1];
         map[x][y]=true;
         while (1)
         {
            char ch;
            scanf("%c",&ch);
            if (ch=='.' || ch==',')
               break;
            int p=count(ch);
            q[++r][0]=x+c[p][0],q[r][1]=y+c[p][1];
         }
         l++;
         scanf("%*c");
      }
      printf("%d\n",r);
      for (int i=1;i<=10;i++)
         for (int j=1;j<=10;j++)
            if (map[i][j])
               printf("%d %d\n",i,j);
   }
   system("pause");
   return(0);
}
int count(char ch)
{
   if (ch=='R')
      return(0);
   else if (ch=='T')
      return(1);
   else if (ch=='L')
      return(2);
   else
      return(3);
}
void work(int n)
{
   for (int i=1;i<=n;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      map[x][y]=true;
   }
   int l,r,q[101][2];
   l=r=1;
   for (int i=1;i<=10;i++)
   {
      bool flag=false;
      for (int j=1;j<=10;j++)
         if (map[i][j])
         {
            q[1][0]=i,q[1][1]=j;
            map[i][j]=false;
            flag=true;
            break;
         }
      if (flag)
         break;
   }
   printf("%d %d\n",q[1][0],q[1][1]);
   while (l<=r)
   {
      int x0=q[l][0],y0=q[l][1];
      for (int i=0;i<4;i++)
      {
         int x=x0+c[i][0],y=y0+c[i][1];
         if (!map[x][y])
            continue;
         printf("%c",ans[i]);
         map[x][y]=false;
         q[++r][0]=x,q[r][1]=y;
      }
      printf("%c\n",l==n?'.':',');
      l++;
   }
}
