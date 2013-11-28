#include <cstdio>
#include <cstdlib>
#include <cstring>
int n,s[201],map[4][17][2];
bool f[201][201][4];
int main()
{
   void init(),print(int);
   init();
   for (int i=n;i>=1;i--)
      for (int j=i;j<=n;j++)
         for (int c=0;c<4;c++)
         {
            if (i==j)
            {
               f[i][j][c]=s[i]==c;
               continue;
            }
            for (int k=1;k<j;k++)
            {
               for (int p=1;p<=map[c][0][0];p++)
               {
                  int c1=map[c][p][0],c2=map[c][p][1];
                  f[i][j][c]=f[i][k][c1] && f[k+1][j][c2];
                  if (f[i][j][c])
                     break;
               }
               if (f[i][j][c])
                  break;
            }
         }
   bool flag=false;
   for (int i=0;i<4;i++)
      if (f[1][n][i])
      {
         flag=true;
         print(i);
      }
   if (!flag)
      printf("Nobody");
   printf("\n");
   system("pause");
   return(0);
}
void init()
{
   int get(char);
   for (int i=0;i<4;i++)
      scanf("%d",&map[i][0][0]);
   scanf("\n");
   for (int i=0;i<4;i++)
      for (int j=1;j<=map[i][0][0];j++)
      {
         char c1,c2;
         scanf("%c%c\n",&c1,&c2);
         map[i][j][0]=get(c1),map[i][j][1]=get(c2);
      }
   char st[210];
   scanf("%s",&st);
   n=strlen(st);
   for (int i=1;i<=n;i++)
      s[i]=get(st[i-1]);
}
int get(char ch)
{
   if (ch=='b')
      return(0);
   else if (ch=='r')
      return(1);
   else if (ch=='y')
      return(2);
   else
      return(3);
}
void print(int p)
{
   if (!p)
      printf("b");
   else if (p==1)
      printf("r");
   else if (p==2)
      printf("y");
   else 
      printf("w");
}
