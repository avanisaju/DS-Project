#include<stdio.h>
#include<string.h>
typedef struct crew
{
	int cno;
	char cname[30];
	char caddress[100];
	char ccontact[10];
	int stat;
};

typedef struct ship
{
	int sno;
	char sname[20];
	int scaptain;
	int scook;
	int soiler;
};

typedef struct signon
{
	int shno;	
	char crno;
	char date_signon[20];
	char date_signoff[20];
};
	struct crew c[20];
	struct ship s[5];
	struct signon so[30];
	int k=0;

int checkstatus(struct crew x[],int xc,struct signon y[],int yc,int cpno)
{
	int j;
	int flag=0;
	int sflag=0;
	for(j=0;j<=yc;j++)
	{
		if(y[j].crno==cpno)
		{
			
			if(strlen(y[j].date_signoff)!=0)
			{
				sflag=1;
				flag=1;
				printf("still working");
			}
		}
	}
	if(sflag==0)
	{
		for(j=0;j<=xc;j++)
		{
			if(x[j].cno==cpno)
			{
				if(x[j].stat==0)
				{
				flag=1;	
				printf("add crew members");
				x[j].stat=1;
				}
			}
		}
	}
	
	return flag;
}

void crew()
{

	
	int j,m,op,cn,pos;
	do
	{
		printf("\n1.Add\n2.Edit\n3.Delete\n4.View\n5.Exit\nenter your option:");
		scanf("%d",&op);
		if(op==1)
		{
			if(k>19)
			{
				printf("\ncrew members are full");
			}
			else
			{
				printf("\nenter the crew no:");
				scanf("%d",&c[k].cno);
				fflush(stdin);
				printf("\nenter the crew member name:");
				gets(c[k].cname);
				fflush(stdin);
				printf("\nenter the crew member address:");
				gets(c[k].caddress);
				fflush(stdin);
				printf("\nenter the crew member contact no:");
				gets(c[k].ccontact);
				c[k].stat=0;
				k++;
			}
		}
		else if(op==4)
		{
			for(j=0;j<k;j++)
			{
				printf("\n%d\n%s\n%s\n%s\n",c[j].cno,c[j].cname,c[j].caddress,c[j].ccontact);
			}
		}
		else if(op==2)
		{
			printf("\nenter the crew member to edit:");
			scanf("%d",&m);
			for(j=0;j<k;j++)
			{
				if(c[j].cno==m)
				{
					fflush(stdin);
					printf("\nenter the new name:");
					gets(c[j].cname);
					printf("\nenter the new address:");
					gets(c[j].caddress);
					printf("\nenter the new contact:");
					gets(c[j].ccontact);
				}
			}
		}
		else if(op==3)
		{
			printf("\nenter the crew member to delete:");
			scanf("%d",&cn);
			pos = -1;
			for(j=0;j<k;j++)
			{
				if(c[j].cno==cn)
				{
					pos = j;
				}
			}
			if(pos==-1)
			{
				printf("\nno such crew is deleted");
			}
			else
			{
				for(j=pos;j<k;j++)
				{
					c[j]=c[j+1];
				}
				k--;
			}
			
		}
		else
		{
			printf("\nThank You");
		}
	}
	while(op!=5);
}

void ship()
{

 
	int n=0;
	int j,m,op,sh,pos;
	do
	{
		printf("\n1.Add\n2.edit\n3.delete\n4.view\n5.exit\nenter your option:");
		scanf("%d",&op);
		if(op==1)
		{
			if(n>4)
			{
				printf("\nship is full");
			}
			else
			{
				printf("\nenter the ship no:");
				scanf("%d",&s[n].sno);
				fflush(stdin);
				printf("\nenter the ship name:");
				gets(s[n].sname);
				printf("\nenter the no of captain:");
				scanf("%d",&s[n].scaptain);
				printf("\nenter no of cook:");
				scanf("%d",&s[n].scook);
				printf("\nenter no of oilers:");
				scanf("%d",&s[n].soiler);
				n++;
			}
		}
		else if(op==4)
		{
			for(j=0;j<n;j++)
			{
			printf("\n%d\n%s\n%d\n%d\n%d\n",s[j].sno,s[j].sname,s[j].scaptain,s[j].scook,s[j].soiler);
			}
		}

		else if(op==2)
		{
			printf("\nenter the ship to edit");
			scanf("%d",&m);
			for(j=0;j<n;j++)
			{
				if(s[j].sno==m)
				{
					fflush(stdin);
					printf("\nenter the ship name");
					gets(s[j].sname);
					printf("\nenter the no of captain");
					scanf("%d",&s[j].scaptain);
					printf("\nenter the no of cook");
					scanf("%d",&s[j].scook);
					printf("\nenter the no of oiler");
					scanf("%d",&s[j].soiler);
				}	
			}
		}
		else if(op==3)
		{
			printf("\nenter the ship to delete");
			scanf("%d",&sh);
			pos = -1;
			for(j=0;j<n;j++)
			{
				if(s[j].sno==sh)
				{
					pos = j;
				}
			}
			if(pos==-1)
			{
				printf("\nno such no is deleted");
			}
			else
			{
				for(j=pos;j<n;j++)
				{
					s[j]=s[j+1];
				}
				n--;
			}
		}
			
		else
		{
			printf("\nThank You");
		}
	}
	while(op!=5);
}

void signon()
{
	
	struct signon tmp;
	int si=-1;
	int j,i;
	int crno;
	int op=0;
	while(op!=4)
	{
		printf("\n1.signon\n2.signoff\n3.list\n4.Exit\nenter your option:");
		scanf("%d",&op);
	if(op==1)
	{
		if(si>30)
		{
			printf("\ncrew in a ship is full");
		}
		else
		{
		
			
			printf("\nenter the crew no :");
			scanf("%d",&crno);
			if(checkstatus(c,k,so,si,crno)==1)
			{
				si++;
				printf("\nenter the ship no :");
				scanf("%d",&so[si].shno);
				fflush(stdin);
				so[si].crno=crno;
				printf("\nenter the date of sign on :");
				gets(so[si].date_signon);
				fflush(stdin);
			
			}
			else
			{
				printf("crew not eligible or not found");
			}
		}
	}
	if(op==2)
	{
		tmp.shno=so[0].shno;
		tmp.crno=so[0].crno;
		strcpy(tmp.date_signon,so[0].date_signon);
	
		for(j=0;j<si;j++)
		{
			so[j]=so[j+1];
		}
		so[si]=tmp;
	}
	if(op==3)
	{
		for(j=0;j<=si;j++)
		{
			printf("\n%d",so[j].crno);
			
		}
	}
}
}

	

			

int main()
{
	int ch;
	do
	{
		printf("\n1.crew\n2.ship\n3.signon\n4.Exit\nenter your option:");
		scanf("%d",&ch);
		if(ch==1)
		{
			crew();			
		}
		if(ch==2)
		{
			ship();
		}
		if(ch==3)
		{
			signon();
		}
	}while(ch!=4);
}
