#include <cstdio>
#include <cstdlib>
#include <cstring>
int a[2505],b[2505],x[5010]={0};
int main()
{
   int i,j,k;
   int lena,lenb;
   char temp[10010];
   int t;
   scanf("%s",temp);
   lena=strlen(temp);
   if (lena%4)
   {
      t=4-lena%4;
      for (i=t+lena-1;i>=t;i--) 
         temp[i]=temp[i-t];
      temp[t+lena]='\0';
      lena+=t;
      for (i=0;i<t;i++) 
         temp[i]='0';
   }
   for (i=0,j=1;i<lena;i+=4,j++)
      a[j]=(temp[i]-'0')*1000+(temp[i+1]-'0')*100+(temp[i+2]-'0')*10+temp[i+3]-'0';
   lena=j;
   scanf("%s",temp);
   lenb=strlen(temp);
   if (lenb%4)
   {
      t=4-lenb%4;
      for (i=t+lenb-1;i>=t;i--) 
         temp[i]=temp[i-t];
      temp[t+lenb]='\0';
      lenb+=t;
      for (i=0;i<t;i++) 
         temp[i]='0';
   }
   for (i=0,j=1;i<lenb;i+=4,j++)
      b[j]=(temp[i]-'0')*1000+(temp[i+1]-'0')*100+(temp[i+2]-'0')*10+temp[i+3]-'0';
   lenb=j;
   for (i=lena-1;i>0;i--)
      for (j=lenb-1;j>0;j--)
      {
         t=i+j; 
         x[t]+=a[i]*b[j];
         x[t-1]+=x[t]/10000; 
         x[t]=x[t]%10000; 
      }
   while (!x[i]) 
      i++;
   printf("%d",x[i]);
   i++;
   for (;i<lena+lenb-1;i++)
      if(x[i]>1000) 
         printf("%d",x[i]);
      else if(x[i]>100) 
         printf("0%d",x[i]);
      else if(x[i]>10) 
         printf("00%d",x[i]);
      else
         printf("000%d",x[i]);
   printf("\n");
   system("pause");
   return(0);
}
