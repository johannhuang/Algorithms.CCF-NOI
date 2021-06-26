#include<stdio.h>
#define MAX 2147483647
FILE *in,*out;
int m,n,dis[101][101]={0},f[101]={0},flag[101]={0};

main()
{in=fopen("HQ.in","r");
 out=fopen("HQ.out","w");
 fscanf(in,"%d",&n);
 int i,j;
 for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
       {fscanf(in,"%d",&dis[i][j]);
        if(dis[i][j]==-1)
          dis[i][j]=MAX;
       }
 for(i=2;i<=n;i++)
    f[i]=MAX;
 int min,q=1;
 flag[1]=1;
 for(i=1;i<=n;i++)
    {for(j=1;j<=n;j++)
        if(flag[j]==0&&dis[q][j]!=MAX&&(f[j]>f[q]+dis[q][j]))
          f[j]=f[q]+dis[q][j];
     min=MAX;
     for(j=1;j<=n;j++)
        if(flag[j]==0&&f[j]<min)
          {min=f[j];q=j;}
     flag[q]=1;
    }

 for(i=1;i<=n;i++)
     fprintf(out,"%d ",f[i]);
}
