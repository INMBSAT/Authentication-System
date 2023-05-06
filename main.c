#include <stdio.h>
#include <stdlib.h>
/*"In this project, students are supposed to design 
a system which has capability to conduct online
test from candidates and 

1) Candidate should have login/signup option
2) Candidate may select any available date 
TBE"*/

struct Candidate{
	char f_name[50];	//first name
	char l_name[50];	//last name
	char email[25];
	char password[25];
	char c_num[11];		//contact number
	int date;			//test date
};

//global variables
struct Candidate candidate_list[100];	//Maximum 100 candidates can register
int list_size = 0;


int welcome_page(){
	 
	  printf("********************************************************************************************************************");
    printf("\n********************************************************************************************************************");
    printf("\n**                                                                                                                **");  
	printf("\n**                                                                                                                **");
    printf("\n**                                                                                                                **");
    printf("\n**                                                                                                                **");
    printf("\n**                                                                                                                **");
    printf("\n**                                                                                                                **");
    printf("\n**                                                                                                                **");    
    printf("\n**                                              WELCOME                                                           **");
    printf("\n**                                                TO                                                              **");
    printf("\n**                                          Aplitude Test                                                     **");
    printf("\n**                                                                                                                **");      
    printf("\n**                                                                                                                **");
    printf("\n**                                                                                                                **");      
	printf("\n**                                                                                                                **");
	printf("\n**                                                                                                                **");
    printf("\n**                                                                                                                **");                                                    	                                                                                                   
	printf("\n********************************************************************************************************************");	 	
	printf("\n********************************************************************************************************************");
	
	return ;	
}

int menu(){
	int choice;
	
	do{
		printf("\n\n*** MENU ***\n");
		printf("1- Login (for existing user).\n");
		printf("2- Sign up (for new user).\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
		if(choice<1 || choice>2){
			printf("Invalid input!!!");
		}
	}while(choice<1 || choice>2);
	
	return choice;
}

// -1=unsuccessful log in, 	index=successful log in.
int log_in( ){
	char email[25], pass[25];
	
	printf("Enter your email: ");
	scanf("%s",&email);

	int index=srch_usr(email);
	
	if(index<0){
		printf("No user exist with this email.");
		return -1;
	}
	
	printf("Enter your password: ");
	scanf("%s",&pass);
	
	if(verify_pswrd(pass,index)==0){
		printf("Invalid password, Try again.");
		return -1;
	}else{
		printf("Loged in successfully.");
		return index;
	}
}
//searching email in array. return index of array of user and return -1 if no user is found.
int srch_usr(char email[]){
	int i,j;
	
	//traverse all candidates
	for(i=0;i<list_size;i++){
		//match email
		for(j=0; candidate_list[i].email[j]!='\0'; j++){
			if(email[j] != candidate_list[i].email[j]){
				break;
			}	
		}
		if(candidate_list[i].email[j] == '\0' && email[j] == '\0'){
			return i;
		}
	}
	
	return -1;
}


//Function to show instructions
void show_ins(){
	printf("Instructions:\n");
	printf("Now please choose a email and password as credentials for system login.\n");
	printf("Email must contains @ symbol.\n");
	printf("Ensure your password is at least 8 characters long.\n\n"); 

}

//0=invalid email
//1=valid email
int is_valid_email(char email[]){
	int i;
	
 	for(i=0;email[i]!='\0';i++){
	 	if(email[i]=='@'){
			return 1;
		}
	}
	
	printf("Invalid email.\n");
	return 0;
}

int pass_len(char pass[]){
	int i;
	
 	for(i=0;pass[i]!='\0';i++){
	 	
	}
	if(i<8){
		printf("Password is too short.\n");
	}
	return i;
}

void sign_up(){
	struct Candidate temp;
	int valid = 0;
		
	printf("\n*** Input Candidate Information ***\n");
	show_ins();
	
	printf("Enter first name: ");
    scanf("%s",&temp.f_name);
    
    printf("Enter last name: ");
    scanf("%s",&temp.l_name);
    
    printf("Enter your contact number: ");
    scanf("%s",&temp.c_num);
     
    do{
    	printf("Enter email: ");
    	scanf("%s",&temp.email);
    }while(is_valid_email(temp.email) == 0);
    
	do{
		printf("Enter Password: ");
	    scanf("%s",&temp.password);
    }while(pass_len(temp.password) < 8);
    
    temp.date = 0;
    
    candidate_list[list_size] = temp;
    list_size++;
    
    printf("Congratulations! You are successfully signed up.");
}

//0=password not matched
//1=password matched
int verify_pswrd(char pass[],int index){
	int i;
	
	for(i=0; candidate_list[index].password[i]!='\0'; i++){
		if(pass[i] != candidate_list[index].password[i]){
			return 0;
		}	
	}
	return 1;	
}


int select_date(int index){
	int date;
	
	printf("\nAvailable days are:\nDAY:'1' 01-02-2022 (Tuesday) \nDAY:'2' 02-02-2022 (Wednesday) \nDAY:'3' 03-02-2022 (Thursday)");
	printf("\nEnter your desired DAY = ");
	
	do{
		scanf("%d",&date);
		switch(date){
			case 1:
				printf("Your test will be held on 01-02-2022(Tuesday).");
				candidate_list[index].date = date;
				break;
			case 2:
				printf("Your test will be held on 02-02-2022(Wednesday).");
				candidate_list[index].date = date;
				break;
			case 3:
				printf("Your test will be held on 03-02-2022(Thursday).");
				candidate_list[index].date = date;
				break;
			default:
				printf("Date is not available.\n");
				printf("Enter date again: ");
		}
	}while(date<1 || date>3);	
	
}


void display_candidate_info(int index){
	
	printf("\n\n*** Candidate Information ***\n");
	printf("First Name: %s\n",candidate_list[index].f_name);
	printf("Last Name: %s\n",candidate_list[index].l_name);
	printf("Contact Number: %s\n",candidate_list[index].c_num);
	printf("Email: %s\n",candidate_list[index].email);
	
	switch(candidate_list[index].date){
		case 1:
			printf("Your test will be held on 01-02-2022(Tuesday).\n");
			break;
		case 2:
			printf("Your test will be held on 02-02-2022(Wednesday).\n");
			break;
		case 3:
			printf("Your test will be held on 03-02-2022(Thursday).\n");
			break;
		default:
			printf("No test date is selected yet.\n");
	}
	
}

void display_all_candidates(){
	int i;
	
	for(i=0;i<list_size;i++){
		printf("\nCandidate # %d\n",i+1);
		printf("First Name: %s\n",candidate_list[i].f_name);
		printf("Last Name: %s\n",candidate_list[i].l_name);
		printf("Contact Number: %s\n",candidate_list[i].c_num);
		printf("Email: %s\n",candidate_list[i].email);
	}
}
int main(int argc, char *argv[]) {
	
	//start
	welcome_page();
	
	int choice,index;
	
	while(1){
		
		choice = menu();
		
		switch(choice){
			case 1:
				index = log_in();
				if(index>=0){
					display_candidate_info(index);
					if(candidate_list[index].date == 0){	//mean not date is selected yet
						select_date(index);
					}
					printf("\nPress any key to continue...");
					getchar();
				}
				break;
			case 2:
				sign_up();
				break;
		}
		
		//display_all_candidates();
	}
	return 0;
}
