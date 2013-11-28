#include <cstdio>
#include <cstdlib>
#include <cstring>
int main()
{
   char s[260];
   int a[26];
   int i,j,l,x,y,k,flag;
   scanf("%s",s);
   l=strlen(s);
   if (s[0]=='-')
   {
      printf("F");
      x=1;
   }
   else if (s[0]=='+')
      x=1;
   else if (s[0]=='.')
      x=-1;
   else
      x=0;
   k=x;
   while (1)
   {
      k++;
      if (x==-1)
      {
         k=0;
         x=26;
         break;
      }
      if (s[k]=='.' || s[k]=='\0')
         break;
   }
   memset(a,0,sizeof(a));
   j=0;
   for (i=k-1;i>=x;i--)
   {
      j++;
      a[j]=s[i]-'0';
   }
   flag=0;
   for (i=10;i>=9;i--)
   {
      if (a[i]!=0)
         printf("%d",a[i]);
      if (i==10 && a[i]!=0)
         printf("S");
      if (i==9 && (a[10]!=0 || a[9]!=0))
         printf("Y");
   }
   if (!a[8] && !a[7] && !a[6] && !a[5])
      flag=0;
   else
      flag=1;
   if (flag)
      for (i=8;i>=5;i--)
         if (a[i]==0)
         {
            if (flag==1)
            {
               x=0;
               for (j=1;j<=i;j++)
                  if (a[j]!=0)
                  {
                     x=1;
                     break;
                  }
               y=0;
               for (j=i;j<=10;j++)
                  if (a[j]!=0)
                  {
                     y=1;
                     break;
                  }
               if (x && y)
                  printf("0");
               flag=2;
            }
         }
         else
         {
            flag=1;
            printf("%d",a[i]);
            if (i==8)
               printf("Q");
            if (i==7)
               printf("B");
            if (i==6)
               printf("S");
            if (i==5)
               printf("W");
         }
   if (!a[4] && !a[3] && !a[2] && !a[1])
      flag=0;
   else
      flag=1;
   if (flag)
      for (i=4;i>=1;i--)
         if (a[i]==0)
         {
            if (flag==1)
            {
               x=0;
               for (j=1;j<=i;j++)
                  if (a[j]!=0)
                  {
                     x=1;
                     break;
                  }
               y=0;
               for (j=i;j<=10;j++)
                  if (a[j]!=0)
                  {
                     y=1;
                     break;
                  }
               if (x && y)
                  printf("0");
               flag=2;
            }
         }
         else
         {
            printf("%d",a[i]);
            flag=1;
            if (i==4)
               printf("Q");
            if (i==3)
               printf("B");
            if (i==2)
               printf("S");
         }
   flag=0;
   for (i=1;i<=10;i++)
      if (a[i]!=0)
      {
         flag=1;
         break;
      }
   if (!flag)
      printf("0");  
   if (s[k]=='.' && k!=l-1)
   {
      printf("D");
      for (i=k+1;i<l;i++)
         printf("%c",s[i]);
   }
   printf("\n");
   system("pause");
   return(0);
}
