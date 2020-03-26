#include <stdlib.h>
#include <stdio.h>
int sort(double p)
{
    static unsigned long long int seed = 123456789;
    seed = (1103515245 * seed + 12345) % 2147483648;
    return seed <= (2147483648*p);
}

int cont(int i, int j, int n, int m, int *M[0])
{
    int x=0,y=0,u,h,c=0;
    for(u=-1; u<=1; u++)
    {
        x=u+i;
        if(x>=n)
            x=0;

        if(x<0)
            x=n-1;

        for(h=-1; h<=1; h++)
        {
            y=h+j;
            if(y>=m)
                y=0;
            if(y<0)
                y=m-1;

            if(M[x][y]==1)
                c++;
        }


    }

    return c-M[i][j];
    }

    int main()
    {
        int i,n,m,t,j,c,k;
        double p;
        scanf("%d %d %lf %d",&n,&m,&p,&t);
        int **M[2];
        M[0]=malloc(sizeof(int*)*n);

        for(i=0; i<n; i++)
        {
            M[0][i]=malloc(sizeof(int)*m);
            for(j=0; j<m; j++)
            {
                M[0][i][j]=sort(p);

            }

        }
        M[1]=malloc(sizeof(int*)*n);
        for(i=0; i<n; i++)
        {
            M[1][i]=malloc(sizeof(int)*m);

        }

        for(k=0;k<t;k++){
            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                {
                    c=cont(i,j,n,m, M[k%2]);
                    if(t>1){
                    M[(k+1)%2][i][j] = 0;
                    if(M[k%2][i][j]==1 && c==2)
                        M[(k+1)%2][i][j]=1;
                    if(c==3)
                        M[(k+1)%2][i][j]=1;

                    }

                }
            }
        }
            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                {
                    /*if(t==1)

                        printf("%d ",M[0][i][j]);

                    if(k!=0)
*/
                        printf("%d ",M[(t+1)%2][i][j]);

                }
                printf("\n");
            }





    for(i=0;i<n;i++){
        free(M[0][i]);
        free(M[1][i]);
    }
    free(M[1]);
    free(M[0]);

        return 0;
    }
