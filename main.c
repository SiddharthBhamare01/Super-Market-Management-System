
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct
{
    int pno;
    char pdet[20];
    float stock;
    float rate;
}product;

typedef struct
{
    char cno[10];
    int pno;
    float qty;
    float amt;

}bill;
int i,nr;
FILE *pfptr;
FILE *pfbill;
product P,pary[20];
bill B,billary[20];

void read_prod()
{
    pfptr=fopen("prod.dat","r");
    i=0;
    while(!feof(pfptr))
    {
        fscanf(pfptr,"%d",&pary[i].pno);
        fscanf(pfptr,"%s",pary[i].pdet);
        fscanf(pfptr,"%f",&pary[i].stock);
        fscanf(pfptr,"%f",&pary[i].rate);
        i++;
    }
    nr=i;
    fclose(pfptr);
}

int main()
{

    char delmark[20];

    //=fopen("bill.dat","a");
    int ch1,ch2,prono,flag;
    float rprice,rstock,q,bill;
    char mobno[10];
    char ans[5],yn[5];
    do
    {
        //clrscr();
        printf("******************************************************************\n");
        printf("\t\t\tSiddharth Super Market\t\t\t\t\n");
        printf("******************************************************************\n");
        printf("1. Product master maintenance\n");
        printf("2. Purchases\n");
        printf("3. Print Bill\n");
        printf("4. Exit\n");
        printf("Enter choice from 1 to 4 :");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1:
            {
                do
                {
                    //clrscr();
                    printf("\n=============Product Master Maintenance==============\n");
                    printf("1. New Product\n2. Edit Price\n3. Edit Stock\n4. Remove Product\n5. Product list\n6. Return to main Menu\n");
                    printf("\t\t\tEnter choice from 1 to 6 :");
                    scanf("%d",&ch2);
                    switch(ch2)
                    {
                        case 1:
                        {
                        if((pfptr=fopen("prod.dat","a"))==NULL)
                            {
                                pfptr=fopen("prod.dat","w");
                            }
                        printf("File is open");
                        do
                        {
                            printf("\n\t\t\tEnter product number :");
                            scanf("%d",&P.pno);
                            printf("\t\t\tEnter product details :");
                            scanf("%s",P.pdet);
                            printf("\t\t\tEnter stock :");
                            scanf("%f",&P.stock);
                            printf("\t\t\tEnter price per item :");
                            scanf("%f",&P.rate);
                            fprintf(pfptr,"\n%d",P.pno);
                            fprintf(pfptr,"\n%s",P.pdet);
                            fprintf(pfptr,"\n%f",P.stock);
                            fprintf(pfptr,"\n%f",P.rate);
                            printf("Want to add any more product?");
                            scanf("%s",ans);

                        }
                        while(strcmp(ans,"yes")==0);
                        fclose(pfptr);
                        }
                        break;
                        case 2:
                        {
                            /*pfptr=fopen("prod.dat","r");
                            i=0;
                            while(!feof(pfptr))
                            {
                                    fscanf(pfptr,"%d",&pary[i].pno);
                                    fscanf(pfptr,"%s",pary[i].pdet);
                                    fscanf(pfptr,"%f",&pary[i].stock);
                                    fscanf(pfptr,"%f",&pary[i].rate);
                                    i++;
                            }
                            nr=i; //total number of records*/
                            //THIS CODE IS REPLACED BY FUNCTION
                            read_prod();
                            bill=0;
                            do
                            {
                                flag=0;
                                printf("\t\t\tEnter product number to change the price :");
                                scanf("%d",&prono);
                                //printf("\t\t\tno of records %d",nr);
                                for(i=0;i<nr;i++)
                                {
                                    if(prono==pary[i].pno)
                                    {
                                        printf("\t\t\tCurrent price of %s is %.2f .",pary[i].pdet,pary[i].rate);
                                        printf("\n\t\t\tEnter revised price :");
                                        scanf("%f",&pary[i].rate);
                                        flag=1;
                                        break;
                                    }
                                }
                                if(flag==0)
                                {
                                    printf("\nNo product found !!\n");
                                }
                               printf("\n\nDo you want to edit any more product's price?");
                               scanf("%s",ans);

                            }
                            while(strcmp(ans,"yes")==0);
                            pfptr=fopen("prod.dat","w");
                            for(i=0;i<nr;i++)
                            {
                                fprintf(pfptr,"\n%d",pary[i].pno);
                                fprintf(pfptr,"\n%s",pary[i].pdet);
                                fprintf(pfptr,"\n%f",pary[i].stock);
                                fprintf(pfptr,"\n%f",pary[i].rate);
                            }
                            fclose(pfptr);
                            //printf("Edit Price");
                        }
                        break;
                        case 3:
                        {
                            /*pfptr=fopen("prod.dat","r");
                            i=0;
                            while(!feof(pfptr))
                            {
                                    fscanf(pfptr,"%d",&pary[i].pno);
                                    fscanf(pfptr,"%s",pary[i].pdet);
                                    fscanf(pfptr,"%f",&pary[i].stock);
                                    fscanf(pfptr,"%f",&pary[i].rate);
                                    i++;
                            }
                            nr=i; //total number of records*/
                            //THIS CODE IS REPLACED BY FUNCTION
                            read_prod();
                            bill=0;
                            do
                            {
                                flag=0;
                                printf("\t\t\tEnter product number to change the stock :");
                                scanf("%d",&prono);
                                for(i=0;i<nr;i++)
                                {
                                    if(prono==pary[i].pno)
                                    {
                                        printf("\t\t\tCurrent stock of %s is %.2f.",pary[i].pdet,pary[i].stock);
                                        printf("\n\t\t\tEnter revised stock :");
                                        scanf("%f",&pary[i].stock);
                                        flag=1;
                                        break;
                                    }
                                }
                               printf("\nDo you want to edit any more product's stock?");
                               scanf("%s",ans);

                            }
                            while(strcmp(ans,"yes")==0);
                            pfptr=fopen("prod.dat","w");
                            for(i=0;i<nr;i++)
                            {
                                fprintf(pfptr,"\n%d",pary[i].pno);
                                fprintf(pfptr,"\n%s",pary[i].pdet);
                                fprintf(pfptr,"\n%f",pary[i].stock);
                                fprintf(pfptr,"\n%f",pary[i].rate);
                            }
                            fclose(pfptr);

                            //printf("Edit stock");
                        }
                        break;
                        case 4:
                        {
                            /*pfptr=fopen("prod.dat","r");
                            i=0;
                            while(!feof(pfptr))
                            {
                                    fscanf(pfptr,"%d",&pary[i].pno);
                                    fscanf(pfptr,"%s",pary[i].pdet);
                                    fscanf(pfptr,"%f",&pary[i].stock);
                                    fscanf(pfptr,"%f",&pary[i].rate);
                                    i++;
                            }
                            nr=i; //total number of records*/
                            //THIS CODE IS REPLACED BY FUNCTION
                            read_prod();
                            bill=0;
                            do
                            {
                                flag=0;
                                printf("\t\t\tEnter product number to remove :");
                                scanf("%d",&prono);
                                for(i=0;i<nr;i++)
                                {
                                    if(prono==pary[i].pno)
                                    {
                                        printf("\t\t\tProduct Details :%s\n",pary[i].pdet);
                                        printf("\t\t\tAre you sure to remove this product?");
                                        scanf("%s",yn);
                                        if(strcmp(yn,"yes")==0)
                                        {
                                            delmark[i]='*';
                                        }
                                        flag=1;
                                        break;
                                    }
                                }
                                if(flag==0)
                                {
                                    printf("No such product found !!");
                                }
                                printf("Do you want to remove any more product?");
                                scanf("%s",ans);
                            }
                            while(strcmp(ans,"yes")==0);
                            pfptr=fopen("prod.dat","w");
                            for(i=0;i<nr;i++)
                            {
                                if(delmark[i]!='*')
                                {
                                    fprintf(pfptr,"\n%d",pary[i].pno);
                                    fprintf(pfptr,"\n%s",pary[i].pdet);
                                    fprintf(pfptr,"\n%f",pary[i].stock);
                                    fprintf(pfptr,"\n%f",pary[i].rate);
                                }
                                else
                                {
                                    delmark[i]='-';
                                }
                            }
                            fclose(pfptr);
                            //printf("remove product");
                        }
                        break;
                        case 5:
                        {
                            //printf("Product List");
                            pfptr=fopen("prod.dat","r");
                            printf("\n=====================Anand Super Market=======================\n");
                            printf("Product List\n");
                            printf("---------------------------------\n");
                            printf("Product ID\tDetails\tStock\tPrice\n");
                            printf("---------------------------------\n");
                            i=0;
                            while(!feof(pfptr))
                            {
                                    fscanf(pfptr,"%d",&pary[i].pno);
                                    fscanf(pfptr,"%s",pary[i].pdet);
                                    fscanf(pfptr,"%f",&pary[i].stock);
                                    fscanf(pfptr,"%f",&pary[i].rate);
                                    printf("%d\t%s\t%.2f\t%.2f\n",pary[i].pno,pary[i].pdet,pary[i].stock,pary[i].rate);
                                    i++;
                            }
                            fclose(pfptr);

                        }
                        break;
                        case 6:
                        {

                        }
                        break;
                        default:
                        {
                            printf("\n\tInvalid choice .. Please retry");
                        }

                    }
                }
                while(ch2!=6);
            }
            break;
            case 2:
            {
                pfptr=fopen("prod.dat","r");
                i=0;
                while(!feof(pfptr))
                {
                    fscanf(pfptr,"%d",&pary[i].pno);
                    fscanf(pfptr,"%s",pary[i].pdet);
                    fscanf(pfptr,"%f",&pary[i].stock);
                    fscanf(pfptr,"%f",&pary[i].rate);
                    i++;
                }
                nr=i; //total number of records
                printf("\t\t\tPlease enter your mobile number :");
                scanf("%s",mobno);
                do
                {
                    flag=0;
                    printf("\t\t\tEnter product number to purchase :");
                    scanf("%d",&prono);
                    printf("\n------------------------------------------------------------------");
                    for(i=0;i<nr;i++)
                    {
                        if(prono==pary[i].pno)
                        {
                            printf("\n\tProduct Details :%s\tCurrent price is %.2f",pary[i].pdet,pary[i].rate);
                            printf("\tEnter quantity to purchase :");
                            scanf("%f",&q);
                            if(q>pary[i].stock)
                            {
                                printf("\tInsufficient stock !!");
                            }
                            else
                            {

                                bill+=q*pary[i].rate;
                                printf("\tAmount for %s is %.2f.\n",pary[i].pdet,(q*pary[i].rate));
                                pary[i].stock-=q;
                            }
                            flag=1;
                            pfbill=fopen("bill.dat","a");
                            fprintf(pfbill,"%s\n",mobno);
                            fprintf(pfbill,"%d\n",pary[i].pno);
                            fprintf(pfbill,"%f\n",q);
                            fprintf(pfbill,"%f\n",(q*pary[i].rate));

                            break;
                        }
                    }
                    if(flag==0)
                    {
                        printf("\n\tProduct is not in a stock !!\n");
                    }
                    printf("\tDo you want to purchase  any more product?");
                    scanf("%s",ans);

                }
                while(strcmp(ans,"yes")==0);
                fclose(pfbill);
                pfptr=fopen("prod.dat","w");
                for(i=0;i<nr;i++)
                {
                    fprintf(pfptr,"\n%d",pary[i].pno);
                    fprintf(pfptr,"\n%s",pary[i].pdet);
                    fprintf(pfptr,"\n%f",pary[i].stock);
                    fprintf(pfptr,"\n%f",pary[i].rate);
                }
                fclose(pfptr);


            }
            break;
            case 3:
            {
                pfbill=fopen("bill.dat","r");
                i=0;
                while(!feof(pfbill))
                {
                    fscanf(pfbill,"%s",billary[i].cno);
                    fscanf(pfbill,"%d",&billary[i].pno);
                    fscanf(pfbill,"%f",&billary[i].qty);
                    fscanf(pfbill,"%f",&billary[i].amt);
                    i++;
                }
                nr=i;
                flag=0;
                do
                {
                    printf("\n\t\t\tPlease enter mobile number to get the bill :");
                    scanf("%s",mobno);
                    for(i=0;i<nr;i++)
                    {
                        if(strcmp(mobno,billary[i].cno)==0)
                        {
                            printf("\n===========================================================\n");
                            printf("\t\t\tCustomer Number:%s\n",mobno);
                            printf("\t\t\t--------------------------\n");
                            while(strcmp(mobno,billary[i].cno)==0)
                            {
                                printf("Product Number :%d\tQuantity:%.2f\tAmount:%.2f\n",billary[i].pno,billary[i].qty,billary[i].amt);
                                i++;
                            }
                            flag=1;
                            printf("\n===========================================================\n");
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        printf("Please check your mobile number !!");
                    }
                    printf("\n\nDo you want to print any more bill?");
                    scanf("%s",ans);
                }
                while(strcmp(ans,"yes")==0);

            }
            break;
            case 4:
            {
                exit(0);
            }
            default:
            {
                printf("\t\tInvalid Choice!! please retry\n\n");
            }
            break;
        }

    }
    while(ch1!=4);

    return 0;
}

