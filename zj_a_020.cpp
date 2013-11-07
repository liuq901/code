#include <cstdio>
#include <cstdlib>
int main()
{
   char ch;
   int sum,i;
   int a[26],b[26];
   for (i=0;i<26;i++)
   {
      if (i>=0 && i<=7 || i==9 || i==10)
         a[i]=1;
      else if (i>=11 && i<=21 && i!=14)
         a[i]=2;
      else
         a[i]=3;
      if (i==0 || i==11 || i==23)
         b[i]=0;
      else if (i==1 || i==12 || i==24)
         b[i]=1;
      else if (i==2 || i==13 || i==22)
         b[i]=2;
      else if (i==3 || i==15 || i==25)
         b[i]=3;
      else if (i==4 || i==8 || i==16)
         b[i]=4;
      else if (i==5 || i==14 || i==17)
         b[i]=5;
      else if (i==6 || i==18)
         b[i]=6;
      else if (i==7 || i==19)
         b[i]=7;
      else if (i==9 || i==20)
         b[i]=8;
      else if (i==10 || i==21)
         b[i]=9;
   }
   while (scanf("%c",&ch)!=EOF)
   {
      sum=a[ch-'A']+b[ch-'A']*9;
      for (i=8;i>=1;i--)
      {
         scanf("%c",&ch);
         sum+=i*(ch-'0');
      }
      scanf("%c",&ch);
      sum+=ch-'0';
      if (sum%10==0)
         printf("real\n");
      else
         printf("fake\n");
      scanf("%*c");
   }
   system("pause");
   return(0);
}
