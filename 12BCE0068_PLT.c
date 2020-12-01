#include<stdio.h>
#include<conio.h>
#include<string.h>
int ch;
char stmt[50];


int i=1,j=0,no=0,tmpch=90;
char str[100],left[15],right[15];
void findopr();
void explore();
void fleft(int);
void fright(int);
struct exp
{
	int pos;
	char op;
}k[15];



int main() {
	printf("\t|||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("\t||                                                   ||\n");
	printf("\t||INTERMEDIATE CODE GENERATION FOR CONTROL STATEMENTS||\n");
	printf("\t||      Topic : covert loops to if statements        ||\n");
	printf("\t||            by - Omprakash Chaudhary               ||\n");
	printf("\t||                Reg No. 12BCE0068                  ||\n");
	printf("\t||              Prof. : Vijaya Kumar                 ||\n");
	printf("\t||                     Slot: G2                      ||\n");
	printf("\t||                                                   ||\n");
	printf("\t|||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	
	printf("Enter the loop statement : ");
	scanf("%s", stmt);
	printf("Enter the Expression :");
	scanf("%s",str);
	if(stmt[0]=='f') {
		ch=1;
	}
	else if(stmt[0]=='w'){
		ch=2;
	}
	else {
		printf("\nWrong Input\n");
	}
	
	switch(ch)
	{
		case 1 : 
			
			printf("\nThe 3AC code is : \n");
			printf("\n %c := %c", stmt[4],stmt[6]);
			printf("\n L0 :");
			printf("\n if ( %c %c %c) goto L1", stmt[8],stmt[9], stmt[10]);
			printf("\n goto L1");
			printf("\n L1 :");
			findopr();
			explore();
			printf("\n t1 := %c %c %c", stmt[14],stmt[15],stmt[16]);
			printf("\n %c := t1", stmt[12]);
			printf("\n goto L0");
			printf("\n L1 :");
			printf("\n END");
			
			break;
			
		case 2 : 
			
			printf("\n The 3AC code is : \n");
			printf("\n L0 :");
			printf("\n if ( %c %c %c) goto L1", stmt[6],stmt[7],stmt[8]);
			printf("\n goto L2");
			printf("\n L1 :");
			findopr();
			explore();
			printf("\n goto L0");
			printf("\n L2 :");
			printf("\n END");
			
			break;
		
		default : 
				printf("\nEnter correct value");
			
		
	}
	
	return 0;
}


void findopr()
{
	for(i=0;str[i]!='\0';i++)
		if(str[i]==':')
		{
		k[j].pos=i;
		k[j++].op=':';
		}
	for(i=0;str[i]!='\0';i++)
		if(str[i]=='/')
		{
		k[j].pos=i;
		k[j++].op='/';
		}
	for(i=0;str[i]!='\0';i++)
		if(str[i]=='*')
		{
		k[j].pos=i;
		k[j++].op='*';
		}
	for(i=0;str[i]!='\0';i++)
		if(str[i]=='+')
		{
		k[j].pos=i;
		k[j++].op='+';
		}
	for(i=0;str[i]!='\0';i++)
		if(str[i]=='-')
		{
		k[j].pos=i;
		k[j++].op='-';
		}
}
void explore()
{
	i=1;
	while(k[i].op!='\0')
	{
		fleft(k[i].pos);
		fright(k[i].pos);
		str[k[i].pos]=tmpch--;
		printf("\n %c := %s%c%s\t\t",str[k[i].pos],left,k[i].op,right);
		for(j=0;j<strlen(str);j++)
			if(str[j]!='$')
				printf("");
		printf("");
		i++;
	}
	fright(-1);
	if(no==0)
	{
		fleft(strlen(str));
		printf("\n %s := %s",right,left);
		getch();
	
	}
	printf("");
	getch();
}
void fleft(int x)
{
	int w=0,flag=0;
	x--;
	while(x!= -1 &&str[x]!= '+' &&str[x]!='*'&&str[x]!='='&&str[x]!='\0'&&str[x]!='-'&&str[x]!='/'&&str[x]!=':')
	{
		if(str[x]!='$'&& flag==0)
		{
		left[w++]=str[x];
		left[w]='\0';
		str[x]='$';
		flag=1;
		}
		x--;
	}
}
void fright(int x)
{
	int w=0,flag=0;
	x++;
	while(x!= -1 && str[x]!= '+'&&str[x]!='*'&&str[x]!='\0'&&str[x]!='='&&str[x]!=':'&&str[x]!='-'&&str[x]!='/')
	{
		if(str[x]!='$'&& flag==0)
		{
		right[w++]=str[x];
		right[w]='\0';
		str[x]='$';
		flag=1;
		}
		x++;
	}
}


