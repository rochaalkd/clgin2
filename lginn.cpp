#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8
void LogIn();
void SignUp();
struct user{
	char fullName[50];
	char email[50];
	char password[50];
	char username[50];
	char phone[50];
};
char generateUsername(char email[50],char username[50]){
	int i;
	
	for( i=0;i<strlen(email);i++){
		if(email[i] == '@') break;
		else username[i] = email[i];
	}
}

void takepassword(char pwd[50]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++] = ch;
			printf("* \b");
		}
	}
}
int main(){
	system("color 79");
	FILE *fp;
	int op,usrFound = 0;
	struct user user;
	char password2[50];

	printf("\n\t\t\t\t----------Crypto's Portfolio Management----------");
	printf("\n\t\t\t\tThis is a Program to  record the transcation of your Cryptos.\t\t\t ");
	printf("\nPlease choose your operation");
	printf("\n1.Signup");
	printf("\n2.Login");
	printf("\n3.Exit");

	printf("\n\nOperation:\t");
	scanf("%d",&op);
	fgetc(stdin);
	
		switch(op){
		case 1:
			SignUp();
		
		break;
		
		case 2:
			LogIn();
			break;
			
		case 3:
			printf("You Have Been exited.");
			break;
	}
	return 0;	
}
    void LogIn(){
    	int usrFound;
    	FILE *fp;
	
		char username[50],pword[50];
		struct user usr;

			printf("\nEnter your username:\t");
			gets(username);
			printf("Enter your password:\t");
			takepassword(pword);

			fp = fopen("data.txt","r");
			while(fread(&usr,sizeof(struct user),1,fp)){
				if(!strcmp(usr.username,username)){
					if(!strcmp(usr.password,pword)){
						system("cls");
						printf("\n\t\t\t\t\t\tWelcome %s",usr.fullName);
						printf("\n\n|Full Name:\t%s",usr.fullName);
						printf("\n|Email:\t\t%s",usr.email);
						printf("\n|Username:\t%s",usr.username);
						printf("\n|Contact no.:\t%s",usr.phone);	
					}
					else {
						printf("\n\nInvalid Password!");
						Beep(800,300);
					}
					usrFound = 1;
				}
			}
			if(!usrFound){
				printf("\n\nUser is not registered!");
				Beep(800,300);
			}
			fclose(fp);
			}
			void SignUp(){	
			FILE *fp;
			

	struct user user;
	char password2[50];
			
			system("cls");
			printf("\nEnter your full name:\t");
			gets(user.fullName);
			printf("Enter your email:\t");
			gets(user.email);
			printf("Enter your contact no:\t");
			gets(user.phone);
			printf("Enter your password:\t");
			takepassword(user.password);
			printf("\nConfirm your password:\t");
			takepassword(password2);
				if(!strcmp(user.password,password2)){
				generateUsername(user.email,user.username);
				fp = fopen("data.txt","a+");
				fwrite(&user,sizeof(struct user),1,fp);
				if(fwrite != 0) printf("\n\nUser resgistration success, Your username is %s",user.username);
				else printf("\n\nSorry! Something went wrong :(");
				fclose(fp);
			}
			else{
				printf("\n\nPassword not matched");
				Beep(750,300);
				
			}
			printf("Your Account Has Been Created.Please LogIn to continue.\n\n\n");
			LogIn();
		}
