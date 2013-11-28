#include <cstdio>
#include <cstdlib>
#include <cstring>
char a[2600],b[2600],*s;
int main()
{
   void work1(),work2(),work3(int,int);
   char ss[2600],ans[2600];
   int i,j,m,n,p;
   s=ans;
   gets(ss);
   scanf("%d%d%d",&m,&n,&p);
   for (i=0;i<=m-2;i++)
      a[i]=ss[i];
   a[m-1]='\0';
   for (i=m-1;i<strlen(ss);i++)
      b[i-m+1]=ss[i];
   b[strlen(ss)-m+1]='\0';
   switch (n)
   {
   case 1:
      work1();
      break;
   case 2:
      work2();
      break;
   case 3:
      work3(n,m);
      break;
   }
   for (i=0;i<strlen(s);i++)
      for (j=1;j<=p+1;j++)
         printf("%c",s[i]);
   printf("\n");
   system("pause");
   return(0);
}
void work1()
{
   char t[9]="Immorta1";
   int i;
   strcat(a,b);
   for (i=0;i<strlen(a);i++)
   {
      if (a[i]>='a' && a[i]<='z')
         a[i]=a[i]-'a'+'A';
      else if (a[i]>='A' && a[i]<='Z')
         a[i]=a[i]-'A'+'a';
      s[i]=a[i];
   }
   s[strlen(a)]='\0';
   strcat(s,t);
}
void work2()
{
   int i,j,flag;
   char x[5]="1013",y[10]="hh4742",k[2600],t[2600];
   strcpy(s,a);
   for (i=0;i<=strlen(s)-strlen(b);i++)
   {
      if (strlen(s)<strlen(b))
         break;
      flag=0;
      for (j=0;j<strlen(b);j++)
         if (b[j]!=s[i+j])
         {
            flag=1;
            break;
         }
      if (!flag)
      {
         for (j=i;j<strlen(s)-strlen(b);j++)
            s[j]=s[j+strlen(b)];
         s[strlen(s)-strlen(b)]='\0';
      }
   }
   for (i=0;i<=strlen(s)-strlen(x);i++)
   {
      if (strlen(s)<strlen(x))
         break;
      flag=0;
      for (j=0;j<strlen(x);j++)
         if (x[j]!=s[i+j])
         {
            flag=1;
            break;
         }
      if (!flag)
      {
         for (j=0;j<i;j++)
            k[j]=s[j];
         k[i]='\0';
         for (j=i+strlen(x);j<strlen(s);j++)
            t[j-i-strlen(x)]=s[j];
         t[strlen(s)-i-strlen(x)]='\0';
         strcat(k,y);
         strcat(k,t);
         strcpy(s,k);
      }
   }
}
void work3(int n,int m)
{
   int i,k,x;
   x=abs(n-m);
   if (x>=1 && x<=strlen(a))
   {
      k=-1;
      for (i=0;i<x-1;i++)
      {
         k++;
         s[k]=a[i];
      }
      for (i=0;i<strlen(b);i++)
      {
         k++;
         s[k]=b[i];
      }
      for (i=x-1;i<strlen(a);i++)
      {
         k++;
         s[k]=a[i];
      }
      s[k+1]='\0';
   }
   else
   {
      strcat(a,b);
      strcpy(s,a);
   }
}
