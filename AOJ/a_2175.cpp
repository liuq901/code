#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
char trump,a[4][13],b[4][13];
int score[2],value[260];
int main()
{
   int work(int,int);
   for (int i=2;i<=9;i++)
      value[i+'0']=i;
   value['T']=10,value['J']=11,value['Q']=12,value['K']=13,value['A']=26;
   while (1)
   {
      cin>>trump;
      if (trump=='#')
         break;
      for (int i=0;i<4;i++)
         for (int j=0;j<13;j++)
            cin>>a[i][j]>>b[i][j];
      score[0]=score[1]=0;
      int now=0;
      for (int i=0;i<13;i++)
      {
         int p=work(i,now);
         score[p&1]++;
         now=p;
      }
      if (score[0]>score[1])
         printf("NS %d\n",score[0]-6);
      else
         printf("EW %d\n",score[1]-6);
   }
   system("pause");
   return(0);
}
int work(int x,int first)
{
   int k=first,v=value[a[first][x]];
   char now=b[first][x];
   for (int i=0;i<4;i++)
   {
      if (b[i][x]==now && value[a[i][x]]>v)
      {
         v=value[a[i][x]];
         k=i;
      }
      if (b[i][x]==trump && now!=trump)
      {
         v=value[a[i][x]];
         now=trump;
         k=i;
      }
   }
   return(k);
}
