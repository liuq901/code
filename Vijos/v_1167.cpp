#include <cstdio>
#include <cstdlib>
const int c[]={1,2,4,8,16,32,64,128,256,512,1024,2048};
char ans[3010][3010];
int main()
{
   void work(int,int,int);
   int n;
   scanf("%d",&n);
   work(0,0,n);
   for (int i=0;i<c[n];i++)
   {
      for (int j=0;j<=c[n]+i;j++)
         if (ans[i][j])
            printf("%c",ans[i][j]);
         else
            printf(" ");
      printf("\n");
   }
   system("pause");
   return(0);
}
void work(int x,int y,int size)
{
   if (size==1)
   {
      ans[x][y+1]=ans[x+1][y]='/';
      ans[x][y+2]=ans[x+1][y+3]='\\';
      ans[x+1][y+1]=ans[x+1][y+2]='_';
      return;
   }
   work(x,y+c[size-1],size-1);
   work(x+c[size-1],y,size-1);
   work(x+c[size-1],y+c[size],size-1);
}
