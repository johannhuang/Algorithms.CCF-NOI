#include<stdio.h>
#include<math.h>
#include<string.h>
FILE *in,*out;
char a[1001]={0};
int n,ji=0,f[5]={1,2,3,4,5},wz=0,b[101],shu[1001]={0},m=0,fu[2][1001]={0},k=0;

void swap(int x[],int i,int j)
{int tem;
 tem=x[i];
 x[i]=x[j];
 x[j]=tem;
}

int function(int i,int j)
{if(i==j)
    return(shu[i]);
 else
 {int t=0;
  while(fu[1][t]<i||fu[1][t]>=j) t++;
  int tem;
  if(fu[0][t]%6==1)
   tem=function(i,fu[1][t])+function(fu[1][t]+1,j);
  else if(fu[0][t]%6==2)
   tem=function(i,fu[1][t])-function(fu[1][t]+1,j);
  else if(fu[0][t]%6==3)
   tem=function(i,fu[1][t])*function(fu[1][t]+1,j);
  else if(fu[0][t]%6==4)
   tem=function(i,fu[1][t])/function(fu[1][t]+1,j);
  else if(fu[0][t]%6==5)
    tem=(int)(pow(function(i,fu[1][t]),function(fu[1][t]+1,j)));
  return(tem);
 }
}

main()
{in=fopen("HQ.in","r");
 out=fopen("HQ.out","w");
 fscanf(in,"%s",a);
 n=strlen(a);

 int i;
 for(i=0;i<n;i++)
   {if(a[i]>=48&&a[i]<=57)
      shu[m]=shu[m]*10+(a[i]-48);
    else if(a[i]=='(')
      {ji+=6;}
    else if(a[i]==')')
      {ji-=6;}
    else if(a[i]=='+')
      {fu[0][k]=f[0]+ji;fu[1][k++]=m;m++;}
    else if(a[i]=='-')
      {fu[0][k]=f[1]+ji;fu[1][k++]=m;m++;}
    else if(a[i]=='*')
      {fu[0][k]=f[2]+ji;fu[1][k++]=m;m++;}
    else if(a[i]=='/')
      {fu[0][k]=f[3]+ji;fu[1][k++]=m;m++;}
    else if(a[i]=='^')
      {fu[0][k]=f[4]+ji;fu[1][k++]=m;m++;}
   }

 int j;
 for(i=0;i<k-1;i++)
    for(j=i;j<k;j++)
      {if((fu[0][i]+1)/2>=(fu[0][j]+1)/2)
         {swap(fu[0],i,j);
          swap(fu[1],i,j);
         }
      }

 fprintf(out,"%d\n",function(0,k));
}
