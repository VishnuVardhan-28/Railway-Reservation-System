#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>

int seats[5];
typedef struct node node;
struct node
{
	char passname[20];
	int passage;
	int pnr;
	char passgen[20];
	char trainname[32];
	int trainnum;
	node *link;
};
node *root =NULL;
void booktickets()
{
    int sh;
	srand(time(0));
    node *temp;
	temp=(node*)malloc(sizeof(struct node));
	printf("\n\n * SELECT YOUR STARTING POINT AND DESTINATION * \n\n");
	printf("    1.SECUNDERABAD TO TIRUPATI  \n\n");
	printf("    2.SECUNDERABAD TO DELHI   \n\n");
	printf("    3.SECUNDERABAD TO CHENNAI  \n\n");
	printf("    4.SECUNDERABAD TO BENGALURU \n\n");
	printf("    5.SECUNDERABAD TO  PUNE     \n\n");
	printf("    6.IF DONE BOOKING     \n\n");
	scanf("%d",&sh);
	switch(sh)
	{
    case 1: strcpy(temp->trainname, "VENKATADHRI_EXPRESS");
            temp->trainnum=100;
           // seats[temp->trainnum] -= 1;
            break;
    case 2: strcpy(temp->trainname, "MANMAD EXPRESS");
            temp->trainnum=101;
           // seats[temp->trainnum] -= 1;
            break;
    case 3: strcpy(temp->trainname, "CHENNAI EXPRESS");
            temp->trainnum=102;
          //  seats[temp->trainnum] -= 1;
            break;
    case 4: strcpy(temp->trainname, "COROMANDAL EXPRESS");
            temp->trainnum=103;
            //seats[temp->trainnum] -= 1;
            break;
    case 5: strcpy(temp->trainname, "PUNE EXPRESS");
            temp->trainnum=104;
           // seats[temp->trainnum] -= 1;
            break;
    case 6:
        printf("\n\nTHANK YOU ********** VISIT AGAIN\n\n");
        exit(0);
    default:
        printf("-----/INVALID CHOICE/------");
	}

	//printf("  ENTER YOUR STARTING POINT :  ");
	//scanf("%s",temp->passtart);
	//printf("  ENTER YOUR DESTINATION :  ");
	//scanf("%s",temp->passend);
	printf("\n ENTER PASSENGER NAME :  ");
	scanf("%s",temp->passname);
	printf(" \n ENTER PASSENGER AGE :  ");
	scanf("%d",&temp->passage);
	printf("\n  ENTER PASSENGER GENGER : ");
	scanf("%s",temp->passgen);
	temp->pnr=rand();
	printf(" \n\n YOUR TICKET HAS BEEN BOOKED SUCCESSFULLY \n\n");
	temp->link=NULL;
	seats[temp->trainnum] -= 1;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		node *p = root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}
	if(temp==NULL)
	{
		printf("  NO TICKETS BOOKED  \n\n");
	}
	else
	{
		while(temp!= NULL)
		{
			printf("*****/\ SOUTH CENTRAL RAILWAYS_/\_******\n");
			printf("             PASSENGER TICKET        \n");
			printf("   PASSENGER NAME IS :  %s\n",temp->passname);
			printf("   PASSENGER AGE IS :   %d\n",temp->passage);
			printf("   PASSENGER GENDER IS :  %s\n",temp->passgen);
			printf("   PASSENGER PNR NUMBER IS : %d\n",temp->pnr);
			printf("   YOUR TRAIN NAME IS : %s ",temp->trainname);
			printf("   YOUR TRAIN NUMBER IS : %d ",temp->trainnum);
			temp=temp->link;
		}
		printf("\n\n");
	}


}
void display()
{
    int pnr;
    printf("Enter pnr number: ");
    scanf("%d", &pnr);
    node* temp = root;
    while(temp)
    {
        if(temp->pnr == pnr)
            break;
        temp = temp->link;
    }

    if(!temp){
    printf("pnr not found");
    }
else{
    if(temp->pnr == pnr){
            printf("*****/\ SOUTH CENTRAL RAILWAYS_/\_******\n");
			printf("             PASSENGER TICKET        \n");
			printf("   PASSENGER NAME IS :  %s\n",temp->passname);
			printf("   PASSENGER AGE IS :   %d\n",temp->passage);
			printf("   PASSENGER GENDER IS :  %s\n",temp->passgen);
			printf("   PASSENGER PNR NUMBER IS : %d\n",temp->pnr);
			printf("   YOUR TRAIN NAME IS : %s ",temp->trainname);
    }

    else{
        printf("pnr not found");
    }
}
}

void canceltickets()
{
    int pnr;
    printf("Enter pnr number: ");
    scanf("%d", &pnr);
    node* temp = root;

    while(temp->link)
    {
        if(temp->link->pnr == pnr)
            break;
        temp = temp->link;
    }
    if(!temp){
    printf("pnr not found");
    }
    else if(!temp->link){
    printf("pnr not found");
    }
    else if(temp->link->pnr == pnr){
        node * delptr = temp->link->link;
        seats[temp->link->trainnum] += 1;
        temp->link->link = NULL;
        temp->link = delptr;
        printf("\n\nCANCELLED TICKET SUCCESSFLLY\n\n");
    }


}
void seatsremaining()
{
    int trainnum;
    printf("Enter train number");
    scanf("%d",&trainnum);
    printf("%d\n",seats[trainnum]);
}
int main()
{
    int i;
    for(i=0;i<5;i++)
    {
        seats[i]=100;
    }

	int ch;
	while(1)
	{
		printf("*WELCOME TO SOUTH CENTRAL RAILWAYS*8 \n");
		printf("\n\n");
		printf("      1. BOOK TICKETS \n\n");
		printf("      2. CANCEL TICKETS \n\n");
		printf("      3. SEATS REMAINING \n\n");
		printf("      4. DISPLAY RESERVATION TICKET \n\n");
		printf("      5. EXIT \n");
		printf("ENTER YOUR CHOICE(enter a number from 1-6 as per your requirement) :\n\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1 : booktickets();
					 break;
			case 2 : canceltickets();
					 break;
			case 3 : seatsremaining();
					 break;
			case 4 : display();
					break;
			case 5 :
			    printf("\n\nTHANK YOU ********** VISIT AGAIN\n\n");
			    goto out;
			default :
					printf("  INVALIED CHOICE  \n");

		}

	}
	out:
	return 0;
}
