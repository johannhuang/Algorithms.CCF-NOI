#include<stdio.h>
#include<string.h>
#define MAX 2147483647
FILE *in,*out;

int n,m,f[101]={0},flag[101]={0};

typedef struct node1
{int dot;
 int data;
 struct node1 *next;
}bian;

typedef struct node2
{struct node1 *first;
 struct node1 *last;
 int flag;
}dian;

dian ddot[101];

void dfs()//深度优先搜索输出
{int i;
 bian *p;
 for(i=1;i<=m;i++)
    {p=ddot[i].first;
     while(p!=NULL)
       {printf("%d=%d ",p->dot,p->data);
        p=p->next;
       }
     printf("\n");
    }
}

main()
{in=fopen("HQ.in","r");
 out=fopen("HQ.out","w");
 memset(ddot,0,sizeof(ddot));
// printf("%d",sizeof(ddot[1])*101);getch();
 fscanf(in,"%d%d",&n,&m);
 int i,x;
 bian *p;
 for(i=1;i<=n;i++)
    {p=(bian*)malloc(sizeof(bian));
     p->next=NULL;
     fscanf(in,"%d",&x);
     fscanf(in,"%d%d",&p->dot,&p->data);
     if(ddot[x].first==NULL)
       {ddot[x].first=p;
        ddot[x].last=p;
       }
     else
       {ddot[x].last->next=p;
        ddot[x].last=p;
       }
    }
// dfs();

 for(i=2;i<=n;i++)
    f[i]=MAX;

 int q=1,min,r;
 ddot[1].flag=1;
 for(i=1;i<n;i++)
   {min=MAX;
    p=ddot[q].first;
    while(p!=NULL)
       {if(ddot[p->dot].flag==0&&f[p->dot]>(p->data+f[q]))
          f[p->dot]=p->data+f[q];
        if(ddot[p->dot].flag==0&&min>f[p->dot])
          {min=f[p->dot];
           r=p->dot;
          }
        p=p->next;
       }
    ddot[r].flag=1;
    q=r;
   }

 for(i=1;i<=m;i++)
     fprintf(out,"%d ",f[i]);
 for(i=1;i<=m;i++)
     printf("%d ",f[i]);
 getch();
}
