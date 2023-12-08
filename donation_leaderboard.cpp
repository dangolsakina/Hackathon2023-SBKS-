#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include <string.h>
#include<conio.h>
#include<Windows.h>
struct registration_structure
{
    char name[100];
	char address[100];
	long long int phone;
	char email[100];
	char formUsername[100];
	char password[100];
	 //long long int unique_id;
};
struct Donor{
	char first_name[20];
	char last_name[20];
	float totalpoints;
};
//void entryadmin();
FILE *file_ptr;
int name_is_valid(char firstname[], char lastname[]);
void menu();
void adminmenu();
void contribution_criteria();
void contribution_type();
void add_donor_record();
void view_donor_record();
void add_donor_record();
void view_donor_record();
int name_is_valid(char[],char[]);
void contribution_calculation();
 float prev_points=0;
void registrationPage();
int loginPage();
void entryMenu();
int entryChoice=0, hotel_display_choice;
int returnloginValue;
char login_error_then_register;

struct registration_structure form, login[100], password_check;

int i = 0, j = 0, count1 = 0;
char ch, ch1, username[100], pass[100], password_map_char[8];

int main()
{
    adminmenu();
	//entryMenu();
	 contribution_type();	 
	return 0;
}
void registrationPage()
{
	//VARIABLES FOR STRONG PASSWORD CKECK
	int count_numbers=0, count_alphabets=0, count_special_characters=0, password_len=0;
	char strong_password_check[15], confirmation_password[15];
	//struct registration_structure account_check, account_check_array[100];
	system("cls");
	fflush(stdin);
	FILE *fileLogin;
	fileLogin = fopen("D:\\LoginPage.DAT", "ab+");
	if (fileLogin == NULL)
	{
		printf("\n File Not Found");
		exit(0);
	}
	fseek(fileLogin, 0, SEEK_END);
	printf("\n\t\t\t\t\t\t\t\t*********************************************");
	printf("\n\t\t\t\t\t\t\t\t               REGESTRATION ");
	printf("\n\t\t\t\t\t\t\t\t*********************************************");
	printf("\n\n\n");
	printf("\n\t\t\t\t\t\t\t\t---------------------------------------------");
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\tName: ");
	gets(form.name);

	printf("\n\t\t\t\t\t\t\t\t---------------------------------------------");
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\tAddress: ");
	gets(form.address);

	printf("\n\t\t\t\t\t\t\t\t---------------------------------------------");
	printf("\n\t\t\t\t\t\t\t\tPhone Number: ");
	scanf("%lld", &form.phone);
	printf("\n\t\t\t\t\t\t\t\t---------------------------------------------");
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\tEmail: ");
	gets(form.email);
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\t---------------------------------------------");
	/*printf("\n\t\t\t\t\t\t\tDonor unique_id: ");
	scanf("%lld",&form.unique_id);*/
	system("cls");
	//printf("\n                        :*****************************************************:");
	printf("\n\t\t\t\t\t\t\t\t*********************************************     ");
	printf("\n\t\t\t\t\t\t\t\t              Set New Username and Password               ");
	printf("\n\t\t\t\t\t\t\t\t*********************************************     ");
	//printf("\n                        :*****************************************************:");

	printf("\n\n\n\n\n");
	printf("\n\t\t\t\t\t\t\t\t:--------------------------------------------:");
	printf("\n\t\t\t\t\t\t\t\t:      Username: ");
	fflush(stdin);
	gets(form.formUsername);
	printf("\n\t\t\t\t\t\t\t\t:--------------------------------------------:");

	// Code for Strong Password
	fflush(stdin);

	password_check:

	system("cls");
	//system("color 0B");
	printf("\n\t\t\t\t\t\t\t\t*******************************************************************");
	printf("\n\t\t\t\t\t\t\t\tEnter the Strong Password");
	printf("\n\t\t\t\t\t\t\t\t*******************************************************************");
	printf("\n\t\t\t\t\t\t\t\tThe Password Must Contain");
	printf("\n\t\t\t\t\t\t\t\t1. Maximum 15 Characters");
	printf("\n\t\t\t\t\t\t\t\t2. Must contain atleast One Digit/Number");
	printf("\n\t\t\t\t\t\t\t\t3. Must contain atleast One Symbol '@', '#', '*', '$'");
	printf("\n\t\t\t\t\t\t\t\t*******************************************************************");
	printf("\n\n");
	Sleep(666);
	system("color 07");
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\t:--------------------------------------------:");

	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\t            :Password: ");
	gets(form.password);

	//printf("\n                :---------------------------------------------");
	strcpy(strong_password_check, form.password);
	password_len = strlen(form.password);
	if(password_len>15)
	{
		printf("\n *************************************************************");
		printf("\n Password is too Long.... Must have maximum 15 Characters");
		printf("\n *************************************************************");
		Sleep(666);
	}
	i=0;
	fflush(stdin);
	
	count_numbers=0;
	count_alphabets=0;
	count_special_characters=0;

	for(i=0; i<15; i++)
	{
		if(strong_password_check[i]>=48 && strong_password_check[i]<=57)
		{
			count_numbers++;
		}
		if((strong_password_check[i]>='A' && strong_password_check[i]<='Z')||(strong_password_check[i]>='a' && strong_password_check[i]<='z'))
		{
			count_alphabets++;
		}
		if(strong_password_check[i]=='@' || strong_password_check[i]=='#' || strong_password_check[i]=='*' || strong_password_check[i]=='$')
		{
			count_special_characters++;
		}
	}

	if(count_numbers>0 && count_alphabets>0 && count_special_characters>0 )
	{
		printf("\n\t\t\t\t\t\t\t\tThe Entered Password is Strong");
		password_conformation:
		fflush(stdin);
		printf("\n\n");
		printf("\n\t\t\t\t\t\t\t\t******************************");
		printf("\n\t\t\t\t\t\t\t\tConfirm Password: ");
		gets(confirmation_password);
		printf("\n\t\t\t\t\t\t\t\t******************************");
		if(strcmp(confirmation_password,strong_password_check)==0)
		{
			system("cls");
			printf("\n\t\t\t\t\t\t\t\t**********PASSWORD MATCHED**********");
			printf("\n\n");
		}
		else
		{
			printf("\n\t\t\t\t\t\t\t\t*************PASSWORD NOT MATCHED**********");
			goto password_conformation;
		}
	}
	else
	{
		printf("\n\n");
		printf("\n\t\t\t\t\t\t\t\t*************************************************");
		printf("\n\t\t\t\t\t\t\t\t\tThe Entered Password is not Strong Enough");
		printf("\n\t\t\t\t\t\t\t\t*************************************************");
		Sleep(666);
		goto password_check;
	}
	fwrite(&form, sizeof(struct registration_structure), 1, fileLogin);
	
	printf("\n\t\t\t\t\t\t\t\tAccount Regestered Successfully.....\n\n");
	fclose(fileLogin);
	system("pause");
	system("cls");
	
	entryMenu();
	// printf("\n Name = %s", form.name);
}

// int loginPage()
int loginPage()
{
	fflush(stdin);
	FILE *fileLogin;
//	login_flag:
	printf("\n---------Login Page--------");
	system("cls");

	fileLogin = fopen("D:\\LoginPage.DAT", "rb+");
	if (fileLogin == NULL)
	{
		printf("\n File Not Found.....");
		exit(0);
	}

	fread(&login, sizeof(login), 1, fileLogin);

	//printf("\n                       :------------------------------------------------------:");
	printf("\n\t\t\t\t\t\t\t\t************************************************    ");
	printf("\n\t\t\t\t\t\t\t\t                  LOGIN                          ");
	printf("\n\t\t\t\t\t\t\t\t***********************************************    ");
	//printf("\n                       :------------------------------------------------------:");
	printf("\n\n\n\n");
	printf("\n\t\t\t\t\t\t\t\t-------------------------------------------");
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\tUsername: ");
	gets(username);
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\t*-------------------------------------------");
	printf("\n\t\t\t\t\t\t\t\tPassword: ");
//	gets(pass);
	i=0;
	while (1)
	{
		ch1 = _getch();
		if (ch1 == 13)
		{
			pass[i] = '\0';
			break;
		}
		else if (ch1 == 8)
		{
			if (i > 0)
			{
				i--;
				printf("\b \b");
			}
		}
		else if (ch1 == 9 || ch1 == 32)
		{
			continue;
		}
		else
		{
			pass[i] = ch1;
			printf("*");
			i++;
		}
		
	}
	
	printf("\n\t\t\t\t\t\t\t\t-------------------------------------------\n\n");
	//system("pause");
	count1 = 0;
	rewind(fileLogin);
	//printf("\n Name=%s", login[1].name);
	getchar();

	//system("color 0B");
	printf("\n\t\t\t\t\t\t\t\t");
	printf("PLEASE WAIT");
	printf("\n\t\t\t\t\t\t\t\t .");
	Sleep(666);
	printf("");
	Sleep(666);
	printf(".");
	Sleep(666);
	printf(".");
	Sleep(666);
	printf(".");
	Sleep(666);
	printf(".");
	Sleep(666);
	printf(".");
	Sleep(666);
	printf(".");
	Sleep(666);
	//system("color 07");

	for (i = 0; i < 100; i++)
	{
		if ((strcmp(username, login[i].formUsername) == 0) && (strcmp(pass, login[i].password) == 0))
		{
			system("cls");
			printf("\n\t\t\t\t\t\t\t\t*********************************************");
			printf("\n\t\t\t\t\t\t\t\tSuccessfully Logged in into System");
			printf("\n\t\t\t\t\t\t\t\t*********************************************");
			printf("\n\n");
			system("pause");
			fclose(fileLogin);
			count1++;
			return 1;
		}
	}

	if (count1 == 0)
	{
		fclose(fileLogin);
		return 0;
	}
}

void forgotPassword()
{
	long long int forgot_password_number;
	char forgot_password_name[100];
	struct registration_structure forgot_password_check[100];
	int i=0, count_not_found=0;
	FILE* fileLogin;
	fileLogin = fopen("D:\\LoginPage.DAT", "rb");
	if (fileLogin == NULL)
	{
		printf("\n\t\t\t\t\t\t\t\tFile Not Found");
		exit(0);
	}
	fflush(stdin);
	rewind(fileLogin);
	fread(&forgot_password_check,sizeof(forgot_password_check),1,fileLogin);
	//printf("\n Name = %s", forgot_password_check[4].name);

	system("cls");
	//printf("\n Name = %s", forgot_password_check[4].name);
	printf("\n\t\t\t\t\t\t\t\t*****************SEARCH*****************");
	printf("\n\t\t\t\t\t\t\t\tEnter Applicants Name: ");
	fflush(stdin);
	gets(forgot_password_name);
	printf("\n\t\t\t\t\t\t\t\tEnter Applicants Number: ");
	scanf("%lld", &forgot_password_number);
	//fclose(fileLogin);
	for(i=0; i<100; i++)
	{
		//printf("\n Name = %s", forgot_password_check[0].name);
		//system("pause");
		//break;
		//printf("\n ");
		if(strcmp(forgot_password_name, forgot_password_check[i].name)==0)
		{
			if(forgot_password_number==forgot_password_check[i].phone)
			{
				system("cls");
				printf("\n\t\t\t\t\t\t\t\t*************** DETAILS ****************");
				printf("\n\t\t\t\t\t\t\t\t----------------------------------------------------------------------------------");
				printf("\n\t\t\t\t\t\t\t\tUsername                       |                 Password                    ");
				printf("\n\t\t\t\t\t\t\t\t----------------------------------------------------------------------------------");
				printf("\n\t\t\t\t\t\t\t\tUsername = %s                            Password = %s", forgot_password_check[i].formUsername, forgot_password_check[i].password);
				printf("\n\t\t\t\t\t\t\t\t-----------------------------------------------------------------------------------");
				count_not_found++;
				
			}
		}
	}
	if(count_not_found==0)
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\t\t*****************************************");
		printf("\n\t\t\t\t\t\t\t\tThe Account is not Registered");
	//	printf("\n\t\t\t\t\t\t\t\tPlease register ")
		printf("\n\t\t\t\t\t\t\t\t*****************************************");
		printf("\n\n");
		system("pause");
		system("cls");
		entryMenu();
	}
	printf("\n\n");
	system("pause");
	system("cls");
	entryMenu();
	fclose(fileLogin);


	
}
void entryMenu()
{
    flag_wrong_choice:
   // fflush(stdin);
    printf("\n\t\t\t\t\t\t\t\t----------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t\t                     WELCOME                         ");
    printf("\n\t\t\t\t\t\t\t\t----------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t\t-------------------------------------");
    printf("\n\t\t\t\t\t\t\t\t| 1. | Login                       |");
    printf("\n\t\t\t\t\t\t\t\t-------------------------------------");
    printf("\n\t\t\t\t\t\t\t\t| 2. |  Registration               |");
    printf("\n\t\t\t\t\t\t\t\t------------------------------------- ");
   // printf("\n\t\t\t\t\t\t\t\t| 3. | Contribution            |");
    //printf("\n\t\t\t\t\t\t\t\t------------------------------------- ");
    printf("\n\t\t\t\t\t\t\t\t| 3. | Forgot Password             |");
    printf("\n\t\t\t\t\t\t\t\t------------------------------------- ");
    printf("\n\t\t\t\t\t\t\t\t| 4. | Exit                        |");
    printf("\n\t\t\t\t\t\t\t\t------------------------------------- ");
    
    fflush(stdin);
    printf("\n\n\n\n\t\t\t\t\t\t\t\tEnter Your Choice: ");
    scanf("%d", &entryChoice);
    if(entryChoice<1 || entryChoice>4)
    {
        printf("\n\t\t\t\t\t\t\t\tWrong Input of Choice......... Enter the Choice again.....");
        Sleep(666);
        goto flag_wrong_choice;
    }
    switch (entryChoice)
    {
        case 1:
        
            returnloginValue= loginPage();
            if(returnloginValue==1)
            {
                printf("\n\t\t\t\t\t\t\t\tSuccessfully Entered to the System");
               menu();
            }
            else
            {
                system("cls");
                printf("\n\t\t\t\t\t\t\t\t***********************ERROR*************************");
                printf("\n\t\t\t\t\t\t\t\t******************************************************");
                printf("\n\t\t\t\t\t\t\t\tNo record Found");
                printf("\n\t\t\t\t\t\t\t\tPlease Register your account and then Login");
                printf("\n\t\t\t\t\t\t\t\t******************************************************");
                printf("\n\n");
                system("pause");
                system("cls");
                entryMenu();
            }
            break;
        case 2:
            registrationPage();
        break;
        //case 3:
        	
        	
        	
        case 3:
            forgotPassword();
        break;
        case 4:
        exit(0);
        default:
            printf("\n\t\t\t\t\t\t\t\tYou Entered Wrong Choice......");
            break;
    }
}
void contribution_type()
{
	printf("\n\t\t\t\t\t\t\t\t--------CONTRIBUTION TYPES-------\n ");
	printf("\n\t\t\t\t\t\t\t\t1.blood \n ");
	printf("\n\t\t\t\t\t\t\t\t2.Clothes \n ");
	printf("\n\t\t\t\t\t\t\t\t3.Volunteer works \n ");
	Sleep(2000);
}
void contribution_criteria()
{
   printf("\n\t\t\t\t\t\t\t\t-----------DASHBOARD--------------\n ");
	printf("\n\t\t\t\t\t\t\t\t1.blood:1ml\t\t\t\t  5points\n ");
	printf("\n\t\t\t\t\t\t\t\t2.Clothes:1kg\t\t\t\t  1points \n ");
	printf("\n\t\t\t\t\t\t\t\t3.Volunteer works:1hour \t\t 10points \n ");
	Sleep(2000);
}
void menu()
{
    while (1)
    {
        system("cls");
        int choice = 0;
        printf("\n\n\n\t\t\t\t\t\t\t\t-------Donation-------");
        printf("\n\t\t\t\t\t\t\t\t1.Add Donor Record\n");
        printf("\n\t\t\t\t\t\t\t\t2.Display Donor Leaderboard\n");
        printf("\n\t\t\t\t\t\t\t\t3.Exit\n");
        
        printf("\n\t\t\t\t\t\t\t\t------------------------------------\n");
    re_choice:
        printf("\n\t\t\t\t\t\t\t\tEnter your choice:");
        scanf("%d",&choice);
        system("cls");
        fflush(stdin);
        switch (choice)
        {
        case 1:
            add_donor_record();
            break;
           

        case 2:
            view_donor_record();
            break;
           case 3:
           	exit(0);

        default:
            printf("\n\t\t\t\t\t\t\t\tInvalid Choice");
            Sleep(1000);
            menu();
            break;
        }
        choice = 0;
    }
}
void add_donor_record()
{
  struct Donor input_donor;
  struct Donor read_donor;
  //      FILE *file_ptr;
  int name_valid;
  int is_donor_present = 0;
  char type1[] = "blood";
  char type2[] = "clothes";
  char type3[] = "volunteer";
  float n, pts1 = 0, m, pts2 = 0, p, pts3 = 0;
  int count = 0;
  char choose;
  char type[25];

  file_ptr = fopen("donor_info.DAT", "ab+");
  if (file_ptr == NULL)
  {
    printf("\nFILE DOESN'T EXIST\n");
    getchar();
    exit(0);
  }
  printf("\n\n\n\n\t\t\t\t\t\t\t\t======Add Donor Record=======\n");
  fflush(stdin);
again_name:
  printf("\n\t\t\t\t\t\t\t\tEnter first name: ");
  scanf("%s", input_donor.first_name);
  fflush(stdin);
  printf("\n\t\t\t\t\t\t\t\tEnter last name: ");
  scanf("%s", input_donor.last_name);
  fflush(stdin);
  system("cls");
  rewind(file_ptr);

  while (fread(&read_donor, sizeof(struct Donor), 1, file_ptr))
  {
    if (strcmp(read_donor.first_name, input_donor.first_name) == 0)
    {
      prev_points = read_donor.totalpoints;
    }
  }

again:
  contribution_type();
  printf("\n\t\t\t\t\t\t\t\tEnter Contribution Type: ");
  scanf("%s", type);
  if (strcmp(type, type1) == 0 || type[0]== '1' )
  {
    printf("\n\t\t\t\t\t\t\t\tEnter the ml of blood that donor have donated: ");
    scanf("%f", &n);
    pts1 = n*5;
    printf("\n\t\t\t\t\t\t\t\tpoints=%.2f", pts1);
  }
  fflush(stdin);
  if (strcmp(type, type2) == 0 || type[0]== '2' )
  {
    printf("\n\t\t\t\t\t\t\t\tEnter kilos of clothes that donor have donated: ");
    scanf("%2f", &m);
    pts2 = 1 * m;
    printf("\n\t\t\t\t\t\t\t\tpoints=%.2f", pts2);
  }
  fflush(stdin);
  if (strcmp(type, type3) == 0 || type[0]== '3' )
  {
    printf("\n\t\t\t\t\t\t\t\tEnter how many hours that donor have volunteered:  ");
    scanf("%f", &p);
    pts3 = 10 * p;
    printf("\n\t\t\t\t\t\t\t\tpoints=%.2f", pts3);
  }
alpha:
  fflush(stdin);
  printf("\n\n\n\t\t\t\t\t\t\t\tDo you want to add your donation?If yes then press 'Y' else 'N': ");
  scanf("%c", &choose);
  if (choose == 'Y' || choose == 'y')
  {
    goto again;
  }
  else if (choose == 'N' || choose == 'n')
  {
    input_donor.totalpoints = pts1 + pts2 + pts3 + prev_points;
    printf("\n\t\t\t\t\t\t\t\tthe total points gained is %.2f ", input_donor.totalpoints);
    sleep(2);
  }
  else
  {
    printf("\n\t\t\t\t\t\t\t\tenter valid choice: ");
    goto alpha;
  }
  fseek(file_ptr,0,SEEK_END);
  fwrite(&input_donor, sizeof(struct Donor), 1, file_ptr);
  printf("\n\t\t\t\t\t\t\t\tFILE HAS BEEN SUCCESSFULLY ADDED");
  fclose(file_ptr);
  //  Sleep(3000);
  //    prev_points=0;
}




/*int name_is_valid(char firstname[], char lastname[])
{
	int i=0;
    for ( i = 0; i < strlen(firstname); i++)
    {
        if (!isalpha(firstname[i]))
        {
            printf("\nInvalid input! Only alphabets are accepted.\n");
            return 0;
        }
    }
    for (i = 0; i < strlen(lastname); i++)
    {
        if (!isalpha(lastname[i]))
        {
            printf("\nInvalid input! Only alphabets are accepted.\n");
            return 0;
        }
    }
    return 1;
}*/
 /*void view_donor_record()
{
	struct Donor read_donor[10];;
	 FILE *file_ptr;
	 int i=0;
	 file_ptr = fopen("D:\\donor_info.DAT", "rb+");
	 //donor_info = fopen("D:\\donor_info.DAT", "rb");
     if (file_ptr == NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tFILE DOESN'T EXIST\n");
        getchar();
        exit(0);
    }
//	while (fread(&read_donor, sizeof(struct Donor), 1, donor_info)=0)
        fread(&read_donor, sizeof(struct Donor), 1,file_ptr  );
        
		for(i=0;i<9;i++)
		{
		
		//system("cls");
		printf("\n\t\t\t\t\t\t\t\t Donor name %s %s :",read_donor[i].first_name,read_donor[i].last_name);
		printf("\n\t\t\t\t\t\t\t\t Total contribution points of the donor .2%f ",read_donor[i].totalpoints);
		 getchar();
		 //sleep(1000);
	  }
	fclose(file_ptr );
	printf("\n\t\t\t\t\t\t\t\t FILE SUCCESSFULLY READ");
}*/

void view_donor_record()
{
  //	system("cls");
  struct Donor read_donor;

  int i = 0, j = 0;
  file_ptr = fopen("donor_info.DAT", "rb+");
  if (file_ptr == NULL)
  {
    printf("\n\t\t\t\t\t\t\t\tFILE DOESN'T EXIST\n");
    getchar();
    exit(0);
  }
  printf("\n\t\t\t\t\t\t\t\tDonation Contribution Leaderboard:\n");
  printf("\n\t\t\t\t\t\t\t\t--------------------------------------------------------------------------------------------\n");
  printf("\n\t\t\t\t\t\t%30s %55s\n\t\t\t\t\t\t\t\t", "Donor Name", "Contribution points");
  printf("\n\t\t\t\t\t\t\t\t _______________________________________________________________________");
  rewind(file_ptr);
  while (fread(&read_donor, sizeof(read_donor), 1, file_ptr))
  {
    printf("\n\t\t\t\t\t\t\t\t|  %s %-25s", read_donor.first_name, read_donor.last_name);
    printf("\t\t\t  %10.2f    |", read_donor.totalpoints);
  }
  printf("\n\t\t\t\t\t\t\t\t _______________________________________________________________________");


  fclose(file_ptr);
  printf("\n\t\t\t\t\t\t\t\t FILE SUCCESSFULLY READ");
  fflush(stdin);
  getchar();
}
void adminmenu()
{

while (1)
    {
        system("cls");
        int choice = 0;
        printf("\n\n\n\t\t\t\t\t\t\t\t-------Main menu-------");
        printf("\n\t\t\t\t\t\t\t\t1.Admin\n");
        printf("\n\t\t\t\t\t\t\t\t2.Donor\n");
        printf("\n\t\t\t\t\t\t\t\t3.Exit\n");
        
        printf("\n\t\t\t\t\t\t\t\t------------------------------------\n");
    re_choice:
        printf("\n\t\t\t\t\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);
        system("cls");
        fflush(stdin);
        switch (choice)
        {
        case 1:
            //entrymenu();
            entryMenu();
            //printf("\nsdsc");
            break;
           

        case 2:
           // view_donor_record();
          // entryadmin();
            //printf("\nsdsc");
            view_donor_record();
            break;
           case 3:
           	exit(0);

        default:
            printf("\n\t\t\t\t\t\t\t\tInvalid Choice");
            Sleep(1000);
            break;
        }
        choice = 0;
    }
}

