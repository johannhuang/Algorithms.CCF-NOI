#include<stdio.h>
#define MAX 2147483647
FILE *in,*out;
int m,n,dis[101][101]={0},d[101][101]={0},via[101][101][101]={0};

main()
{in=fopen("HQ.in","r");
 out=fopen("HQ.out","w");
 fscanf(in,"%d",&n);
 int i,j,k;
 for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
       {fscanf(in,"%d",&dis[i][j]);
        if(dis[i][j]==-1)
          dis[i][j]=MAX;
       }
 for(i=1;i<=n;i++)
    {for(j=1;j<=n;j++)
        d[i][j]=dis[i][j];
     for(k=1;k<=n;k++)
          via[i][j][k]=0;
     if(d[i][j]<MAX)
       via[i][j][i]=via[i][j][j]=1;
    }

 int l;
 for(k=1;k<=n;k++)
   for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        if(d[i][k]+d[k][j]<d[i][j])
            {d[i][j]=d[i][k]+d[k][j];
             for(l=1;l<=n;l++)
                via[i][j][l]=via[i][k][l]||via[k][j][l];
            }

 for(i=1;i<=n;i++)
    {for(j=1;j<=n;j++)
        fprintf(out,"%d ",d[i][j]);
     fprintf(out,"\n");
    }
 for(i=1;i<=n;i++)
    {for(j=1;j<=n;j++)
       printf("%d ",d[i][j]);
     printf("\n");
    }
 getch();
}
