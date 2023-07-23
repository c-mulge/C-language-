//Name- Channaveer Mulge
//Class- S.Y.Bsc CS
//Hamming Code

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int max=6;
    int a[100],b[100],c[100];
    int h,i,j,k,l,n,o,sum=0,position=0;

    printf("Enter Length of Data: ");
    scanf("%d",&l);
    printf("Enter Data: \n");
    for(i=0;i<l;i++)
    {
        scanf("%d",&a[i]);
    }
        
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");

       for(i=0,j=0;i<l;i++)
    {
        for(k=0;k<max;k++)
        {
            h=pow(2,k)-1;
            if(j==h)
            {
                b[j]=0;
                j++;
            }
        }
        b[j]=a[i];
        j++;
    }
        
    printf("Length of Hamming code: %d bits\n",o=j);
    printf("Number of Parity Bits: %d \n",n=o-l);

    int x[n];
    int m=n-1;
    for(k=0;k<n;k++)
    {
        h=pow(2,k)-1;

        for(i=h;i<o;)
        {
            for(j=0;j<=h;j++)
            {
                sum=sum+b[i];
                i++;
                if(i>=o)
                break;
            }

            if(i>=o)
            break;

            for(j=0;j<=h;j++)
            {
                i++;
                if(i>=o)
                break;
            }

            if(i>=o)
            break;
        }
        b[h]=sum%2;
        sum=0;
        printf("P%d: %d\n",h+1,b[h]);
    }


    printf("\nTransmitter:   ");
    for(i=0;i<o;i++)
    {
        printf("%d ",b[i]);
    }


    printf("\nReceiver: \n");
    for(i=0;i<o;i++)
    {
        scanf("%d",&c[i]);
    }
    sum=0;
    for(k=0;k<n;k++)
    {
        h=pow(2,k)-1;

        for(i=h;i<o;)
        {
            for(j=0;j<=h;j++)
            {
                sum=sum+c[i];
                i++;
                if(i>=o)
                break;
            }

            if(i>=o)
            break;

            for(j=0;j<=h;j++)
            {
                i++;
                if(i>=o)
                break;
            }

            if(i>=o)
            break;
        }
        x[m]=sum%2;
        sum=0;
        printf("P%d: %d\n",h+1,x[m]);
        m--;
    }
    for(m=0;m<n;m++)
    {
        position= position+x[n-m-1]*pow(2,m);
    }
    printf("Error position: %d\n",position);               //Error position
    	if(c[position-1]==0)
    	    c[position-1]=1;
    	else
    	    c[position-1]=0;

    if(position==0)
        printf("\nThere is no error\n");

    else
    {
		printf("\nError Corrected:  \n");                 //Error correct
    	for(i=0;i<o;i++)
    	{
        	printf("%d \n",c[i]);
    	}
    }


}