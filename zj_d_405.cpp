#include <cstdio>
#include <cstdlib>
int a[5001][31];
int main()
{
   while (1)
   {
      int n;
      scanf("%d",&n);
      if (!n)
         break;
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&a[i][0]);
         for (int j=1;j<=a[i][0];j++)
            scanf("%d",&a[i][j]);
      }
      int t;
      scanf("%d",&t);
      for (int i=1;i<=t;i++)
      {
         int x,y;
         scanf("%d%d",&x,&y);
         if (y<=0 || y>a[x][0])
            printf("啊!!!抄錯第%d號女生的班級座號了啦!!\n",i);
         else
         {
            int p=a[x][y];
            if (p>=90)
               printf("第%d號女生  第%d班的第%d號  成績為%d 成績優\n",i,x,y,p);
            else if (p>=60)
               printf("第%d號女生  第%d班的第%d號  成績為%d\n",i,x,y,p);
            else
               printf("第%d號女生  第%d班的第%d號  成績為%d 不及格呀~~\n",i,x,y,p);
         }
      }
   }
   system("pause");
   return(0);
}
