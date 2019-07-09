#include<stdio.h>
#include<conio.h>

//Lominoque John Philip O.
//Caballero Bea
//Malco Paul Anthony
//Buag John Mark
int main()

{

    int tn[10],wt[10],num,ind,x,t=0,tturn=0,dist[10],psngr[10];

    float avg;
	printf(">>>>>CANLUBANG TERMINAL<<<<<");
	go:
    printf("\n Enter the number of Passengers:");
    scanf("%d",&num);
    if(num<11)
    {
    for(ind=0;ind<num;ind++)
    {
        printf("\n Enter the passenger's number:");
        scanf("%d",&psngr[ind]);
        printf("\n Enter the distance (km):");
        scanf("%d",&dist[ind]);
    }
    for(ind=0;ind<num;ind++)
    {
        for(x=ind+1;x<num;x++)
        {
            if(dist[ind]>dist[x])
            {
                int temp;
                temp=psngr[ind];
                psngr[ind]=psngr[x];
                psngr[x] = temp;
                temp = dist[ind];
                dist[ind] = dist[x];
                dist[x] = temp;
            }
        }
    }
    wt[0] = 0;
    tn[0] = dist[0];
    for(ind=1;ind<num;ind++)
    {
        wt[ind]=tn[ind-1];
        tn[ind] = wt[ind] + dist[ind];
    }
    printf("\n\n Distance of passenger's off (km):");
    printf("\n\n");
    printf("|  p%d\t|",psngr[0]);
    for(ind=1;ind<num;ind++)
	
        printf("  p%d\t|",psngr[ind]);
    printf("\n");
    printf("%d",wt[0]);
    printf("\t%d",tn[0]);


    for(ind=1;ind<num;ind++)
	
        printf("\t%d",tn[ind]);
         printf("\n\n\n No. of Passenger \t Distance \t Waiting time \t Turnaround time");

    printf("\n");

    for(ind=0;ind<num;ind++)

    {

        printf("\n       [p%d]\t\t    [%d]\t\t      [%d]\t      [%d]",psngr[ind],dist[ind],wt[ind],tn[ind]);

        t = t + wt[ind];

        tturn = tturn + tn[ind];

    }

    avg=(float)t/num;

    printf("\n\n The average waiting time is: %.2f",avg);

    avg = (float)tturn/num;

    printf("\n\n The average turn around time is %.2f",avg);


}
else
{
	printf("Invalid too much load");
	goto go;
}
getch();
return 0;
}
