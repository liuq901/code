#include <cstdio>
#include <cstdlib>
char *a;
struct str
{
   char c;
   struct str *left;
   struct str *right;       
};
int main()
{
   void hou(struct str *);
   void del(struct str *);
   struct str *go(int,int);
   int n;
   int i,j;
   int l=1;
   struct str *head;
   scanf("%d",&n);
   for (i=0;i<n;i++)
      l*=2;
   a=(char *)malloc(sizeof(char)*(l+1));
   scanf("%s",a);
   head=go(0,l-1);
   hou(head);
   del(head);
   printf("\n");
   free(a);
   system("pause");
   return(0);
}
struct str *go(int i,int j)
{
   struct str *temp;
   int k;
   int b=0,t=0;
   temp=(struct str *)malloc(sizeof(struct str));
   for (k=i;k<=j;k++)
   {
      if (a[k]=='0')
         b++;
      else
         t++;
   }
   if (b && t)
      temp->c='F';
   else if (b)
      temp->c='B';
   else
      temp->c='I';
   if (i==j)
      temp->left=temp->right=NULL;
   else
   {
      temp->left=go(i,(i+j)/2);
      temp->right=go((i+j)/2+1,j);
   }
   return temp; 
}
void hou(struct str *temp)
{
   if (temp->left)
      hou(temp->left);
   if (temp->right)
      hou(temp->right);
   printf("%c",temp->c);
   return;
}
void del(struct str*temp)
{
   if (temp->left)
      del(temp->left);
   if(temp->right)
      del(temp->right);
   free(temp);
   return;
}
