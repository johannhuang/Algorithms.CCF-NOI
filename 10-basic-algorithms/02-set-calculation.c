#include<stdio.h>
#include<string.h>
FILE *in,*out;
int an,bn,a[101]={0},b[101]={0},d,z=0;
char c;

void swap(int x[],int i,int j)
{int tem;
 tem=x[i];
 x[i]=x[j];
 x[j]=tem;
}

void paixu(int x[],int len)
{int i,j;
 for(i=0;i<len-1;i++)
   for(j=i;j<len;j++)
      if(x[i]>x[j])
        swap(x,i,j);
}

void bingji(int x[],int y[])
{int i=0,j=0;
 while(i<an&&j<bn)
  {if(x[i]<y[j])
     fprintf(out,"%d ",x[i++]);
   else if(x[i]==y[j])
     {fprintf(out,"%d ",x[i++],j++);}
   else
     fprintf(out,"%d ",y[j++]);
  }
 while(i<an)
   fprintf(out,"%d ",x[i++]);
 while(j<bn)
   fprintf(out,"%d ",y[j++]);
 fprintf(out,"\n");
}

void chaji(int x[],int y[])
{int i=0,j=0;
 while(i<an&&j<bn)
  {if(x[i]<y[j])
     fprintf(out,"%d ",x[i++]);
   else if(x[i]==y[j])
     {i++;j++;}
   else
     j++;
  }
 while(i<an)
   fprintf(out,"%d ",x[i++]);
 fprintf(out,"\n");
}

void jiaoji(int x[],int y[])
{int i=0,j=0;
 while(i<an&&j<bn)
  {if(x[i]==y[j])
     fprintf(out,"%d ",x[i++],j++);
   else if(x[i]<y[j])
     i++;
   else
     j++;
  }
 fprintf(out,"\n");
}

void heji(int x[],int y[])
{int i=0,j=0;
 while(i<an&&j<bn)
  {if(x[i]<y[j])
     fprintf(out,"%d ",x[i++]);
   else if(x[i]==y[j])
     {i++;j++;}
   else
     fprintf(out,"%d ",y[j++]);
  }
 while(i<an)
   fprintf(out,"%d ",x[i++]);
 while(j<bn)
   fprintf(out,"%d ",y[j++]);
 fprintf(out,"\n");
}

main()
{in=fopen("set.in","r");
 out=fopen("set.out","w");
 z=0;
 while(1)
 {fscanf(in,"%d%c",&d,&c);
  if(c!=10)
    a[z++]=d;
  else
    {a[z++]=d;
     break;
    }
 }
 an=z; z=0;
 while(1)
 {fscanf(in,"%d%c",&d,&c);
  if(c!=10)
    b[z++]=d;
  else
    {b[z++]=d;
     break;
    }
 }
 bn=z;

 paixu(a,an);
 paixu(b,bn);

 bingji(a,b);
 chaji(a,b);
 jiaoji(a,b);
 heji(a,b);
}
