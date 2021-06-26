#include<stdio.h>
#include<string.h>
#include<math.h>
int c[40][101]={0},answer[201]={0};
int a[101]={0},b[101]={0};

void Sum(int x[],int y[],int tem[])
{int i;
 tem[200]=(y[100]>=x[100]? y[100]:x[100]);
 for(i=0;i<tem[200];i++)
       {tem[i]+=x[i]+y[i];
        tem[i+1]=tem[i]/10000;
        tem[i]=tem[i]%10000;
       }
 if(tem[tem[200]]>0)
    tem[200]++;
}

void Quadrature(int x[],int y[],int tem[])
{int i,j;
 tem[200]=y[100]+x[100]-1;
 for(i=0;i<x[100];i++)
    for(j=0;j<y[100];j++)
       {tem[i+j]+=x[i]*y[j];
        tem[i+j+1]+=tem[i+j]/10000;
        tem[i+j]=tem[i+j]%10000;
       }
 if(tem[tem[200]]>0)
    tem[200]++;
}
void Subtract(int x[],int y[],int tem[])
{int i;
 tem[200]=x[100];
 for(i=0;i<tem[200];i++)
    tem[i]=x[i]-y[i];
 for(i=0;i<tem[200]-1;i++)
   if(tem[i]<0)
     {tem[i+1]=tem[i+1]-1;
      tem[i]=tem[i]+10000;
     }
 while(tem[tem[200]-1]==0) tem[200]--;
}

void shuru(int x[])
{int i=0,wz,quan;
 char tmp[401];
 scanf("%s",tmp);
 tmp[400]=strlen(tmp);
 wz=-1;
 quan=1;
 for(i=tmp[400]-1;i>=0;i--)
    {if(quan==1)
       wz++;
     x[wz]+=(tmp[i]-48)*quan;
     quan*=10;
     if(quan>1000) quan=1;
    }
 x[100]=tmp[400]/4+1;
}

void shuchu(int first,int end,int x[])
{int i;
 printf("%d",x[first]);
 for(i=first-1;i>=end;i--)
     {printf("%d%d%d%d",x[i]/1000,x[i]/100%10,x[i]/10%10,x[i]%10);}
 printf("\n");
 getch();
}

main()
{int i;
 shuru(a);
 shuru(b);

 memset(answer,0,sizeof(answer));//求和
 Sum(a,b,answer);
 shuchu(answer[200]-1,0,answer);

 memset(answer,0,sizeof(answer));//求积
 Quadrature(a,b,answer);
 shuchu(answer[200]-1,0,answer);

 memset(answer,0,sizeof(answer));//求差
 if(a[100]<b[100]||(a[100]==b[100]&&a[a[100]-1]<b[b[100]-1]))
   {Subtract(b,a,answer);printf("-");
    shuchu(answer[200]-1,0,answer);}
 else
   {Subtract(a,b,answer);
    shuchu(answer[200]-1,0,answer);}
}
