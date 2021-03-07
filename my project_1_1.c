#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_HEADER_SIZE  sizeof(sFileHeader)

/*Global Variables*/
int countStudent = 0;
int mathCount = 0;
int phyCount = 0;
int biosCount = 0;
int chmCount = 0;
int geosCount = 0;
int ictCount = 0;
int otherCount = 0;
int admisCount = 0;

/*Files*/
FILE *fp;
FILE *fp_res;
FILE *fp_admis;
FILE *fp_maths;
FILE *fp_phy;
FILE *fp_bios;
FILE *fp_chm;
FILE *fp_geos;
FILE *fp_ict;
FILE *fp_other;

/*
typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;
*/

struct Candidate
{
	int NCIN;
	char NOM[20];
	char PRENOM[20];
	int AGE;
	float DECISION;
	//Date studentJoiningDate;
};

struct Bacc
{
	//int NCIN;
	float MOYENNE;
	float NOTEPHY;
	float NOTEMATH;
	char SERIEBAC[5];
};

struct Choix
{
	//int NCIN;
	char CHOIX_2[10];
	char CHOIX_3[10];
	char CHOIX_1[10];
};

//Align the message
void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
//Head message
void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############   Student Record Management System Project in C   ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t---------------------------------------------------------------------------");
}
//Display message
void welcomeMessage()
{
    headMessage("By Dejon Fah Joel and Mouga Mouga Ian - 20U2806 - 20U2818");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                __WELCOME__                =");
    printf("\n\t\t\t        =                   To The                  =");
    printf("\n\t\t\t        =               STUDENT RECORD              =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =                   Of The                  =");
    printf("\n\t\t\t        =        Computer Science Department        =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Press Enter to continue.....");
    getch();
}


int isNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}

/*
int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}

// returns 1 if given date is valid.
int isValidDate(Date *validDate)
{
    //check range of year,month and day
    if (validDate->yyyy > MAX_YR ||
            validDate->yyyy < MIN_YR)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    //Handle feb days in leap year
    if (validDate->mm == 2)
    {
        if (IsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    //handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 || validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}
*/

/*Function to Add a student's record*/
void addStudent()
{
	int num_stud;
	int status = 0;
	int choix_filliere_2;
	int choix_filliere_3;
	int choix_Bacc;
	char addAgain = 'Y';
	//int countStudent = 0;
	//int admisCount = 0;
	//char add_again;
	//char add_again = 1;

	//FILE *fp_res;
	//FILE *fp_admis;
	struct Candidate can;
	struct Bacc bac;
	struct Choix choix;
	//FILE *fp;

	/*printf("We are going to feed information!!!\n");*/

	fp = fopen("Candidate.txt", "a+");

		if(fp == NULL)
		{
			printf("File does not exists");
			exit(1);
			//return;
		}
		else
		{
			while(addAgain == 'y' || addAgain == 'Y')
			{
			    headMessage("ADD NEW STUDENTS");
    		printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    		printf("\n\t\t\t---------------------------------------------------------------------------\n");
				/*Taking in personal information*/
				printf("\n\t\t\tEnter the National Identification Card number of the student: ");
				fflush(stdin);
				scanf("%d", &can.NCIN);
				fprintf(fp, "%d ", can.NCIN);

				do
				{
					printf("\n\t\t\tEnter the Name of the student: ");
					fflush(stdin);
					gets(can.NOM);
					status = isNameValid(can.NOM);
				}
				while(!status);
				fprintf(fp, "%s ", can.NOM);

				do
				{
					printf("\n\t\t\tEnter the Surname of the student: ");
					fflush(stdin);
					gets(can.PRENOM);
					status = isNameValid(can.PRENOM);
				}
				while(!status);
				fprintf(fp, "%s ", can.PRENOM);

				printf("\n\t\t\tEnter the Age of the student: ");
				fflush(stdin);
				scanf("%d", &can.AGE);
				fprintf(fp, "%d ", can.AGE);

				/*Taking in Baccalaureate information*/
				printf("\n\t\t\tEnter the Average at the Baccalaureate of the student: ");
				fflush(stdin);
				scanf("%f", &bac.MOYENNE);
				fprintf(fp, "%f ", bac.MOYENNE);

				printf("\n\t\t\tEnter the Physics Note of the student: ");
				fflush(stdin);
				scanf("%f", &bac.NOTEPHY);
				fprintf(fp, "%f ", bac.NOTEPHY);

				printf("\n\t\t\tEnter the Mathematics Note of the student: ");
				fflush(stdin);
				scanf("%f", &bac.NOTEMATH);
				fprintf(fp, "%f ", bac.NOTEMATH);

				do
				{
					printf("\n\t\t\tChoose the Baccalaureate series of the student from the list below: \n");
					printf("\n\t\t\t    1..... GCEAL\n");
					printf("\n\t\t\t    2..... C\n");
					printf("\n\t\t\t    3..... D\n");
					printf("\n\t\t\t    4..... TI\n");
					printf("\n\t\t\t    5..... F\n");
					printf("\n\t\t\t    6..... OTHER\n");
					printf("\n\t\t\tChoice>>> ");
					fflush(stdin);
					scanf("%d", &choix_Bacc);
					switch(choix_Bacc)
					{
					    case 1: strcpy(bac.SERIEBAC, "GCEAL");
                                break;
					    case 2: strcpy(bac.SERIEBAC, "C");
                                break;
					    case 3: strcpy(bac.SERIEBAC, "D");
                                break;
					    case 4: strcpy(bac.SERIEBAC, "TI");
                                break;
					    case 5: strcpy(bac.SERIEBAC, "F");
                                break;
					    default: strcpy(bac.SERIEBAC, "OTHER");
					}
					printf("\n\t\t\tBaccalaureate series of the student: %s\n", bac.SERIEBAC);
					status = isNameValid(bac.SERIEBAC);
				}
				while(!status);
				fprintf(fp, "%s ", bac.SERIEBAC);

				/*Taking in Choice information*/
				do
				{
					printf("\n\t\t\tChoose the Second (2) Choice of the student from the list below: \n");
					printf("\n\t\t\t    1..... MATHEMATICS\n");
					printf("\n\t\t\t    2..... CHEMISTRY\n");
					printf("\n\t\t\t    3..... PHYSICS\n");
					printf("\n\t\t\t    4..... GEOLOGY\n");
					printf("\n\t\t\t    5..... ICTFORDEV\n");
					printf("\n\t\t\t    6..... BIOSCIENCES\n");
					printf("\n\t\t\t    7..... OTHER\n");
					printf("\n\t\t\tChoice>>> ");
					scanf("%d", &choix_filliere_2);
					switch(choix_filliere_2)
					{
					    case 1: strcpy(choix.CHOIX_2, "MATHEMATICS");
                                break;
					    case 2: strcpy(choix.CHOIX_2, "CHEMISTRY");
                                break;
					    case 3: strcpy(choix.CHOIX_2, "PHYSICS");
                                break;
					    case 4: strcpy(choix.CHOIX_2, "GEOLOGY");
                                break;
					    case 5: strcpy(choix.CHOIX_2, "ICTFORDEV");
                                break;
                        case 6: strcpy(choix.CHOIX_2, "BIOSCIENCES");
                                break;
					    default: strcpy(choix.CHOIX_2, "OTHER");
					}
					printf("\n\t\t\tSecond Choice of the student: %s\n", choix.CHOIX_2);
					status = isNameValid(choix.CHOIX_2);
				}
				while(!status);
				fprintf(fp, "%s ", strupr(choix.CHOIX_2));

				do
				{
					printf("\n\t\t\tChoose the Third (3) Choice of the student from the list below: \n");
					printf("\n\t\t\t    1..... MATHEMATICS\n");
					printf("\n\t\t\t    2..... CHEMISTRY\n");
					printf("\n\t\t\t    3..... PHYSICS\n");
					printf("\n\t\t\t    4..... GEOLOGY\n");
					printf("\n\t\t\t    5..... ICTFORDEV\n");
					printf("\n\t\t\t    6..... BIOSCIENCES\n");
					printf("\n\t\t\t    7..... OTHER\n");
					printf("\n\t\t\tChoice>>> ");
					scanf("%d", &choix_filliere_3);
					switch(choix_filliere_3)
					{
					    case 1: strcpy(choix.CHOIX_3, "MATHEMATICS");
                                break;
					    case 2: strcpy(choix.CHOIX_3, "CHEMISTRY");
                                break;
					    case 3: strcpy(choix.CHOIX_3, "PHYSICS");
                                break;
					    case 4: strcpy(choix.CHOIX_3, "GEOLOGY");
                                break;
					    case 5: strcpy(choix.CHOIX_3, "ICTFORDEV");
                                break;
                        case 6: strcpy(choix.CHOIX_3, "BIOSCIENCES");
                                break;
					    default: strcpy(choix.CHOIX_3, "OTHER");
					}
					printf("\n\t\t\tThird choice of the student: %s\n", choix.CHOIX_3);
					status = isNameValid(choix.CHOIX_3);
				}
				while(!status);
				fprintf(fp, "%s\n", strupr(choix.CHOIX_3));

				/*
				do
				{
					//get date year,month and day from user
					printf("\n\t\t\tEnter Registration date in format (day/month/year): ");
					scanf("%d/%d/%d",&can.studentJoiningDate.dd,&can.studentJoiningDate.mm,&can.studentJoiningDate.yyyy);
					//check date validity
					status = isValidDate(&can.studentJoiningDate);
					if (!status)
					{
						printf("\n\t\t\tPlease enter a valid date.\n");
					}
				}
				while(!status);
				fprintf(fp, "\n\t\t\tRegistration Date: %d/%d/%d\n\n", can.studentJoiningDate.dd, can.studentJoiningDate.mm, can.studentJoiningDate.yyyy);
                */

				printf("\n\t\t\t===============================================================================================\n");
                printf("\n\t\t\tStudent Informations added successfully!!!\n");

                countStudent++;
                printf("\n\t\t\tDo you want to add another student? (Y/N): ");
                fflush(stdin);
                addAgain = getche( );
			}
			if(countStudent <= 1)
			{
			    printf("\n\n\t\t\tYou added %d student successfully!", countStudent);
			    printf("\n\n\t\t\tPress Enter to continue...");
			}
			else
            {
                printf("\n\n\t\t\tYou added %d students successfully!", countStudent);
                printf("\n\n\t\t\tPress Enter to continue...");
            }
            //fclose(fp);
        }
    fclose(fp);
	fflush(stdin);
	getchar();
}

/*Function to Display a student's record*/
void displayStudent()
{
	int displayNCIN;
	int choiceList;
	char searchAgain = 'Y';

	struct Candidate can;
	struct Bacc bac;
	struct Choix choix;
	//FILE *fp;
	headMessage("DISPLAY STUDENT INFORMATION");

	fp = fopen("Candidate.txt", "r");
	if(fp == NULL)
		{
			printf("\n\t\t\tFile did not opened successfully");
			exit(1);
			//return;
		}
	else
	{
	    printf("\n\t\t\tSelect one option from the menu below........");
	    printf("\n\t\t\t1.Display a student's record using its NCIN.......<Press 1>");
	    printf("\n\t\t\t2.Display all student's records...................<Press 2>");
	    printf("\n\n\n\t\t\tYour choice here...... ");
	    scanf("%d", &choiceList);
	    switch(choiceList)
	    {
            case 1:
                while(searchAgain == 'Y' || searchAgain == 'y')
                {
                    printf("\n\t\t\tEnter the student's Identification Number (NCIN) to proceed: ");
                    scanf("%d", &displayNCIN);

                    while( !feof( fp ) )
                    {
                        fscanf(fp, "%d %s %s %d %f %f %f %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2, &choix.CHOIX_3);
                        if(can.NCIN == displayNCIN)
                        {
                            printf("\n\t\t\tIdentification Number                           :	%d", can.NCIN);
                            printf("\n\t\t\tName				    	        :	%s", can.NOM);
                            printf("\n\t\t\tSurname 					:	%s", can.PRENOM);
                            printf("\n\t\t\tAge						:	%d", can.AGE);
                            printf("\n\t\t\tBacc. Series            			:	%s", bac.SERIEBAC);
                            printf("\n\t\t\tBacc. Average           			:	%f", bac.MOYENNE);
                            printf("\n\t\t\tPhysics mark            			:	%f", bac.MOYENNE);
                            printf("\n\t\t\tMathematics mark                		:	%f", bac.MOYENNE);
                            printf("\n\t\t\t2nd Choice      				:	%s", choix.CHOIX_2);
                            printf("\n\t\t\t3rd Choice      				:	%s", choix.CHOIX_3);
                            printf("\n\t\t\t==========================================================================");
                            printf("\n\n");
                            break;
                        }
                    }
                    printf("\n\t\t\tDo you want to display another student's record? (Y/N): ");
                    fflush(stdin);
                    searchAgain = getche( );
                }
                break;
            case 2:
                while( !feof( fp ) )
                    {
                        fscanf(fp, "%d %s %s %d %f %f %f %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2, &choix.CHOIX_3);
                            printf("\n\t\t\tIdentification Number                           :	%d", can.NCIN);
                            printf("\n\t\t\tName				    	        :	%s", can.NOM);
                            printf("\n\t\t\tSurname 					:	%s", can.PRENOM);
                            printf("\n\t\t\tAge						:	%d", can.AGE);
                            printf("\n\t\t\tBacc. Series            			:	%s", bac.SERIEBAC);
                            printf("\n\t\t\tBacc. Average           			:	%f", bac.MOYENNE);
                            printf("\n\t\t\tPhysics mark            			:	%f", bac.MOYENNE);
                            printf("\n\t\t\tMathematics mark                		:	%f", bac.MOYENNE);
                            printf("\n\t\t\t2nd Choice      				:	%s", choix.CHOIX_2);
                            printf("\n\t\t\t3rd Choice      				:	%s", choix.CHOIX_3);
                            printf("\n\t\t\t==========================================================================");
                            printf("\n\n");
                    }
                    printf("\n\t\t\tPress enter to go to main menu...");
                    break;
            default:
                printf("\n\t\t\tYour choice is invalid....!");
	    }
	}
	fclose(fp);
	fflush(stdin);
	getchar();
}

/*Function to Modify a student's record*/
void modifyStudent(int modifyNCIN)
{
	//int modifyNCIN;
	int status = 0;
	int found = 0;
	int new_choix_Bacc;
	int new_choix_filliere_2;
	int new_choix_filliere_3;
	char modifyAgain = 'Y';
	struct Candidate can;
	struct Bacc bac;
	struct Choix choix;
	FILE *fp;
	FILE *fp_tmp;
	headMessage("MODIFY STUDENT INFORMATION");

	fp = fopen("Candidate.txt", "r");
    fp_tmp = fopen("Candidate_temp.txt", "w");
	if(fp == NULL)
		{
			printf("\n\t\t\tFile does not exists");
			exit(1);
		}
	if(fp_tmp == NULL)
		{
			printf("\n\t\t\tFile does not exists");
			exit(1);
		}
	else
	{
		while(modifyAgain == 'Y' || modifyAgain == 'y')
		{
			//printf("\n\t\t\tEnter the student's Identification Number (NCIN) to proceed to modification: ");
			//scanf("%d", &modifyNCIN);

			while( !feof( fp ) )
			{
			    fscanf(fp, "%d %s %s %d %f %f %f %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2, &choix.CHOIX_3);
				if(can.NCIN == modifyNCIN)
				{
                    /*Taking in Personal information*/
                    printf("\n\t\t\tEnter the new National Identification Card number of the student: ");
                    fflush(stdin);
                    scanf("%d", &can.NCIN);
                    fprintf(fp_tmp, "%d ", can.NCIN);

                    do
                    {
                        printf("\n\t\t\tEnter the new Name of the student: ");
                        fflush(stdin);
                        gets(can.NOM);
                        status = isNameValid(can.NOM);
                    }
                    while(!status);
                    fprintf(fp_tmp, "%s ", can.NOM);

                    do
                    {
                        printf("\n\t\t\tEnter the new Surname of the student: ");
                        fflush(stdin);
                        gets(can.PRENOM);
                        status = isNameValid(can.PRENOM);
                    }
                    while(!status);
                    fprintf(fp_tmp, "%s ", can.PRENOM);

                    printf("\n\t\t\tEnter the new Age of the student: ");
                    fflush(stdin);
                    scanf("%d", &can.AGE);
                    fprintf(fp_tmp, "%d ", can.AGE);

                    /*Taking in Baccalaureate information*/
                    printf("\n\t\t\tEnter the new Average at the Baccalaureate of the student: ");
                    fflush(stdin);
                    scanf("%f", &bac.MOYENNE);
                    fprintf(fp_tmp, "%f ", bac.MOYENNE);

                    printf("\n\t\t\tEnter the new Physics Note of the student: ");
                    fflush(stdin);
                    scanf("%f", &bac.NOTEPHY);
                    fprintf(fp_tmp, "%f ", bac.NOTEPHY);

                    printf("\n\t\t\tEnter the new Mathematics Note of the student: ");
                    fflush(stdin);
                    scanf("%f", &bac.NOTEMATH);
                    fprintf(fp_tmp, "%f ", bac.NOTEMATH);

                    do
                    {
                        printf("\n\t\t\tChoose the new Baccalaureate series of the student from the list below: \n");
                        printf("\n\t\t\t    1..... GCEAL\n");
                        printf("\n\t\t\t    2..... C\n");
                        printf("\n\t\t\t    3..... D\n");
                        printf("\n\t\t\t    4..... TI\n");
                        printf("\n\t\t\t    5..... F\n");
                        printf("\n\t\t\t    6..... OTHER\n");
                        printf("\n\t\t\tChoice>>> ");
                        fflush(stdin);
                        scanf("%d", &new_choix_Bacc);
                        switch(new_choix_Bacc)
                        {
                            case 1: strcpy(bac.SERIEBAC, "GCEAL");
                                    break;
                            case 2: strcpy(bac.SERIEBAC, "C");
                                    break;
                            case 3: strcpy(bac.SERIEBAC, "D");
                                    break;
                            case 4: strcpy(bac.SERIEBAC, "TI");
                                    break;
                            case 5: strcpy(bac.SERIEBAC, "F");
                                    break;
                            default: strcpy(bac.SERIEBAC, "OTHER");
                        }
                        printf("\n\t\t\tNew Baccalaureate series of the student: %s\n", bac.SERIEBAC);
                        status = isNameValid(bac.SERIEBAC);
                    }
                    while(!status);
                    fprintf(fp_tmp, "%s ", bac.SERIEBAC);

                    /*Taking in Choice information*/
                   do
                    {
                        printf("\n\t\t\tChoose the new Second (2) Choice of the student from the list below: \n");
                        printf("\n\t\t\t    1..... MATHEMATICS\n");
                        printf("\n\t\t\t    2..... CHEMISTRY\n");
                        printf("\n\t\t\t    3..... PHYSICS\n");
                        printf("\n\t\t\t    4..... GEOLOGY\n");
                        printf("\n\t\t\t    5..... ICTFORDEV\n");
                        printf("\n\t\t\t    6..... BIOSCIENCES\n");
                        printf("\n\t\t\t    7..... OTHER\n");
                        printf("\n\t\t\tChoice>>> ");
                        scanf("%d", &new_choix_filliere_2);
                        switch(new_choix_filliere_2)
                        {
                            case 1: strcpy(choix.CHOIX_2, "MATHEMATICS");
                                    break;
                            case 2: strcpy(choix.CHOIX_2, "CHEMISTRY");
                                    break;
                            case 3: strcpy(choix.CHOIX_2, "PHYSICS");
                                    break;
                            case 4: strcpy(choix.CHOIX_2, "GEOLOGY");
                                    break;
                            case 5: strcpy(choix.CHOIX_2, "ICTFORDEV");
                                    break;
                            case 6: strcpy(choix.CHOIX_2, "BIOSCIENCES");
                                    break;
                            default: strcpy(choix.CHOIX_2, "OTHER");
                        }
                        printf("\n\t\t\tNew Second choice of the student: %s\n", choix.CHOIX_2);
                        status = isNameValid(choix.CHOIX_2);
                    }
                    while(!status);
                    fprintf(fp_tmp, "%s ", strupr(choix.CHOIX_2));

                    do
                    {
                        printf("\n\t\t\tChoose the new Third (3) Choice of the student from the list below: \n");
                        printf("\n\t\t\t    1..... MATHEMATICS\n");
                        printf("\n\t\t\t    2..... CHEMISTRY\n");
                        printf("\n\t\t\t    3..... PHYSICS\n");
                        printf("\n\t\t\t    4..... GEOLOGY\n");
                        printf("\n\t\t\t    5..... ICTFORDEV\n");
                        printf("\n\t\t\t    6..... BIOSCIENCES\n");
                        printf("\n\t\t\t    7..... OTHER\n");
                        printf("\n\t\t\tChoice>>> ");
                        scanf("%d", &new_choix_filliere_3);
                        switch(new_choix_filliere_3)
                        {
                            case 1: strcpy(choix.CHOIX_3, "MATHEMATICS");
                                    break;
                            case 2: strcpy(choix.CHOIX_3, "CHEMISTRY");
                                    break;
                            case 3: strcpy(choix.CHOIX_3, "PHYSICS");
                                    break;
                            case 4: strcpy(choix.CHOIX_3, "GEOLOGY");
                                    break;
                            case 5: strcpy(choix.CHOIX_3, "ICTFORDEV");
                                    break;
                            case 6: strcpy(choix.CHOIX_3, "BIOSCIENCES");
                                    break;
                            default: strcpy(choix.CHOIX_3, "OTHER");
                        }
                        printf("\n\t\t\tNew Third choice of the student: %s\n", choix.CHOIX_3);
                        status = isNameValid(choix.CHOIX_3);
                    }
                    while(!status);
                    fprintf(fp_tmp, "%s", strupr(choix.CHOIX_3));


                    /*
                    do
                    {
                        //get date year,month and day from user
                        printf("\n\t\t\tEnter modification date in format (day/month/year): ");
                        scanf("%d/%d/%d",&can.studentJoiningDate.dd,&can.studentJoiningDate.mm,&can.studentJoiningDate.yyyy);
                        //check date validity
                        status = isValidDate(&can.studentJoiningDate);
                        if (!status)
                        {
                            printf("\n\t\t\tPlease enter a valid date.\n");
                        }
                    }
                    while(!status);
                    fprintf(fp_tmp, "\n\t\t\tRegistration Date: %d/%d/%d\n\n", can.studentJoiningDate.dd, can.studentJoiningDate.mm, can.studentJoiningDate.yyyy);
                    */
                    found = 1;
				}
			}
			printf("\n\t\t\tModify another student's information? (Y/N): ");
			fflush(stdin);
			modifyAgain = getche( );
		}
	}
	if(found == 1)
	{
	    printf("\n\t\t\t==========================================================================");
	    printf("\n\t\t\tStudent's information modified successfully!!!");
        printf("\n\t\t\tPress Enter to go to main menu!");
	}
	else
    {
        printf("\n\t\t\t==========================================================================");
        printf("Student with NCIN: %d was not found in file.", modifyNCIN);
    }

	fclose(fp_tmp);
	fclose(fp);
	remove("Candidate.txt");
	rename("Candidate_temp.txt", "Candidate.txt");
	fflush(stdin);
	getchar();
}

/*Function to Delete a student's record*/
void deleteStudent(int studentDelete)
{
	int found = 0;
	char deleteAgain = 'Y';
	//int studentDelete;
	struct Candidate can;
	struct Bacc bac;
	struct Choix choix;
	FILE *fp;
	FILE *tempfp;
	headMessage("DELETE STUDENT INFORMATION");

	fp = fopen("Candidate.txt", "r");
	if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }

	tempfp = fopen("Delete_Stud.txt", "a");
	if(tempfp == NULL)
	{
		printf("\n\t\t\tFile is not opened\n");
		exit(1);
	}

	//printf("\n\t\t\tEnter Student's Identification Number to proceed to deletion: ");
	//scanf("%d", &studentDelete);
	while(deleteAgain == 'y' || deleteAgain == 'Y')
    {
        while( !feof(fp))
        {
            fscanf(fp, "%d %s %s %d %f %f %f %s %s %s", can.NCIN, can.NOM, can.PRENOM, can.AGE, bac.MOYENNE, bac.NOTEPHY, bac.NOTEMATH, bac.SERIEBAC, choix.CHOIX_2, choix.CHOIX_3);
            while (can.NCIN != studentDelete)
            {
                fprintf(tempfp, "%d %s %s %d %f %f %f %s %s %s", can.NCIN, can.NOM, can.PRENOM, can.AGE, bac.MOYENNE, bac.NOTEPHY, bac.NOTEMATH, bac.SERIEBAC, choix.CHOIX_2, choix.CHOIX_3);
                //found = 1;
            }
            found = 1;
        }
        printf("\n\t\t\tDelete another student's information? (Y/N): ");
        fflush(stdin);
        deleteAgain = getche( );
    }
	//(found) ? printf("\n\t\t\tRecord Deleted Successfully!!!"):printf("\n\t\t\tRecord not found...");
	//printf("\nRecord Deleted Successfully!!!");
	if(found == 1)
	{
	    printf("\n\t\t\t==========================================================================");
	    printf("\n\t\t\tRecord with NCIN: %d was deleted Successfully!!!", studentDelete);
	}
	else
    {
        printf("\n\t\t\t==========================================================================");
        printf("\n\t\t\tRecord with NCIN: %d was not found or...\n\n\t\t\tThere was a problem deleting a file...", studentDelete);
    }
	fclose(fp);
	fclose(tempfp);
	remove("Candidate.txt");
	rename("Delete_Stud.txt", "Candidate.txt");
	fflush(stdin);
	getchar();
}

/*Function to decide on admitted students to INFO*/
void results()
{
    int done = 0;
    float studentDecision;
    char DECISION[] = "info";
	float S1 = 12.0, S2 = 9.0, S3 = 14.0;

	struct Candidate can;
	struct Bacc bac;
	struct Choix choix;
	//choix.CHOIX_1[5] = "info";
		/*Creating the Result.txt file to store results*/
		fp = fopen("Candidate.txt", "r");
		if(fp == NULL)
		{
			printf("\n\t\t\tFile is not opened.");
			exit(1);
		}
		fp_res = fopen("Resultat.txt", "a");
		if(fp_res == NULL)
		{
			printf("\n\t\t\tFile is not opened.");
			exit(1);
		}
		else
		{
			while(!feof(fp));
			{
			    fscanf(fp, "%d %s %s %d %f %f %f %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2, &choix.CHOIX_3);
			    /*Generate file for admitted students*/
			    if(bac.MOYENNE >= S1)
			    {
			        //DECISION = &choix.CHOIX_1;
			        //strcpy(DECISION, choix.CHOIX_1);
			        fprintf(fp_res, "%d %s %s %f %f %f %s\n", can.NCIN, can.NOM, can.PRENOM, bac.MOYENNE, bac.NOTEPHY, bac.NOTEMATH, DECISION);
			    }
			    else
                if(((bac.MOYENNE >= S2 && bac.MOYENNE <= S1) && (bac.NOTEPHY && bac.NOTEMATH) >= S3))
                {
                    //DECISION = &choix.CHOIX_1;
			        //strcpy(DECISION, &choix.CHOIX_1);
			        fprintf(fp_res, "%d %s %s %f %f %f %s\n", can.NCIN, can.NOM, can.PRENOM, bac.MOYENNE, bac.NOTEPHY, bac.NOTEMATH, DECISION);
                }
                else
                {
                    //DECISION = &choix.CHOIX_2;
                    strcpy(DECISION, choix.CHOIX_2);
                    fprintf(fp_res, "%d %s %s %f %f %f %s\n", can.NCIN, can.NOM, can.PRENOM, bac.MOYENNE, bac.NOTEPHY, bac.NOTEMATH, DECISION);
                }
                //fprintf(fp_res, "%d %s %s %f %f %f %s\n", can.NCIN, can.NOM, can.PRENOM, bac.MOYENNE, bac.NOTEPHY, bac.NOTEMATH, DECISION);
                done++;
			}
			if(done != 0)
            {
                printf("\n\t\t\tResults File was generated succesfully!");
            }
            else
            {
                printf("\n\t\t\tThere was a problem generating the Results' File...");
            }
        }

		fclose(fp);
        fclose(fp_res);
        fflush(stdin);
        getchar();
}

/*Function to create file for admitted students into INFO*/
void admis()
{
    int done = 0;
    char decision[10];

    struct Candidate can;
	struct Bacc bac;
	struct Choix choix;
	headMessage("STUDENTS ADMITTED INTO INFORMATICS");

    fp_admis = fopen("Admis.txt", "a");
    if(fp_admis == NULL)
    {
        printf("File is not opened.");
        exit(1);
    }
    else
    {
        while (!feof(fp_res))
        {
            fscanf(fp, "%d %s %s %f %f %f %s", &can.NCIN, &can.NOM, &can.PRENOM, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &decision);
            if(strcmp(decision, "INFO") == 0)
            {
                fprintf(fp_admis, "%d ", can.NCIN);
                fprintf(fp_admis, "%s ", can.NOM);
                fprintf(fp_admis, "%s ", can.PRENOM);
                fprintf(fp_admis, "%d ", can.AGE);
                fprintf(fp_admis, "%s ", bac.SERIEBAC);
                fprintf(fp_admis, "%f ", bac.MOYENNE);
                fprintf(fp_admis, "%f ", bac.NOTEPHY);
                fprintf(fp_admis, "%f ", bac.NOTEMATH);
                fprintf(fp_admis, "%s\n", decision);

                admisCount++;
                done = 1;
            }
        }
    }
    fclose(fp_admis);
    if(done == 1)
    {
        printf("\n\t\t\tFile of admitted students was generated succesfully!");
        printf("\n\t\t\tA total of %d students were admitted into INFO.", admisCount);
        printf("\n\t\t\tNow, let us print its content...\n\n\n");
        /*Let us display the admitted students...*/
        fp_admis = fopen("Admis.txt", "r");
        if(fp_admis == NULL)
        {
            printf("\n\t\t\tFile is not opened.");
            exit(1);
        }
        else
        {
            while (!feof(fp_admis))
            {
                fscanf(fp, "%d %s %s %f %f %f %s", &can.NCIN, &can.NOM, &can.PRENOM, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &decision);
                printf("\n\t\t\tNCIN            = %d ", can.NCIN);
                printf("\n\t\t\tName            = %s ", can.NOM);
                printf("\n\t\t\tSurname         = %s ", can.PRENOM);
                printf("\n\t\t\tAge             = %d ", can.AGE);
                printf("\n\t\t\tBacc. Series    = %s ", bac.SERIEBAC);
                printf("\n\t\t\tAverage         = %f ", bac.MOYENNE);
                printf("\n\t\t\tPhysics Note    = %f ", bac.NOTEPHY);
                printf("\n\t\t\tMaths Note      = %f ", bac.NOTEMATH);
                printf("\n\t\t\tDECISION     = %s ", decision);
                printf("\n\t\t\t==========================================================================");
                printf("\n\n");
            }
        }
        fclose(fp_admis);
    }
    else
    {
        printf("\n\t\t\tThere was a problem generating the File of admitted students...");
    }
    fflush(stdin);
    getchar();
}

/*Function to carry out selections and send each non selected student to his second choice*/
void selection()
{
    //Verifiers
    int done_maths = 0;
    int done_phy = 0;
    int done_bios = 0;
    int done_chm = 0;
    int done_geos = 0;
    int done_ict = 0;
    int done_other = 0;

    //Files local to this function
	FILE *fp_maths;
	FILE *fp_phy;
	FILE *fp_bios;
	FILE *fp_chm;
	FILE *fp_geos;
	FILE *fp_ict;
	FILE *fp_other;

	struct Candidate can;
	struct Bacc bac;
	struct Choix choix;

	while (!feof(fp))
	{
	    fscanf(fp, "%d %s %s %d %f %f %f %s %s %s", can.NCIN, can.NOM, can.PRENOM, can.AGE, bac.MOYENNE, bac.NOTEPHY, bac.NOTEMATH, bac.SERIEBAC, choix.CHOIX_2, choix.CHOIX_3);
        if(strcmp(choix.CHOIX_2, "MATHEMATICS") == 0)
        {
             fp_maths = fopen("Maths_Students.txt", "a+");
                if(fp_maths == NULL)
                {
                    printf("\n\t\t\tFile is not opened.");
                    exit(1);
                }
                fprintf(fp_maths, "%d ", can.NCIN);
                fprintf(fp_maths, "%s ", can.NOM);
                fprintf(fp_maths, "%s ", can.PRENOM);
                fprintf(fp_maths, "%d ", can.AGE);
                fprintf(fp_maths, "%s ", bac.SERIEBAC);
                fprintf(fp_maths, "%f ", bac.MOYENNE);
                fprintf(fp_maths, "%f ", bac.NOTEPHY);
                fprintf(fp_maths, "%f\n", bac.NOTEMATH);

                fclose(fp_maths);
                done_maths = 1;
                mathCount++;
        }

        else
        if(strcmp(choix.CHOIX_2, "PHYSICS") == 0)
        {
            fp_phy = fopen("Physics_Students.txt", "a+");
                if(fp_phy == NULL)
                {
                    printf("\n\t\t\tFile is not opened.");
                    exit(1);
                }
                fprintf(fp_phy, "%d ", can.NCIN);
                fprintf(fp_phy, "%s ", can.NOM);
                fprintf(fp_phy, "%s ", can.PRENOM);
                fprintf(fp_phy, "%d ", can.AGE);
                fprintf(fp_phy, "%s ", bac.SERIEBAC);
                fprintf(fp_phy, "%f ", bac.MOYENNE);
                fprintf(fp_phy, "%f ", bac.NOTEPHY);
                fprintf(fp_phy, "%f\n", bac.NOTEMATH);

                fclose(fp_phy);
                done_phy = 1;
                phyCount++;
        }

        else
        if(strcmp(choix.CHOIX_2, "BIOSCIENCES") == 0)
        {
            fp_bios = fopen("BIOS_Students.txt", "a+");
                if(fp_bios == NULL)
                {
                    printf("\n\t\t\tFile is not opened.");
                    exit(1);
                }
                fprintf(fp_bios, "%d ", can.NCIN);
                fprintf(fp_bios, "%s ", can.NOM);
                fprintf(fp_bios, "%s ", can.PRENOM);
                fprintf(fp_bios, "%d ", can.AGE);
                fprintf(fp_bios, "%s ", bac.SERIEBAC);
                fprintf(fp_bios, "%f ", bac.MOYENNE);
                fprintf(fp_bios, "%f ", bac.NOTEPHY);
                fprintf(fp_bios, "%f\n", bac.NOTEMATH);

                fclose(fp_bios);
                done_bios = 1;
                biosCount++;
        }

        else
        if(strcmp(choix.CHOIX_2, "CHEMISTRY") == 0)
        {
            fp_chm = fopen("Chemistry_Students.txt", "a+");
                if(fp_chm == NULL)
                {
                    printf("\n\t\t\tFile is not opened.");
                    exit(1);
                }
                fprintf(fp_chm, "%d ", can.NCIN);
                fprintf(fp_chm, "%s ", can.NOM);
                fprintf(fp_chm, "%s ", can.PRENOM);
                fprintf(fp_chm, "%d ", can.AGE);
                fprintf(fp_chm, "%s ", bac.SERIEBAC);
                fprintf(fp_chm, "%f ", bac.MOYENNE);
                fprintf(fp_chm, "%f ", bac.NOTEPHY);
                fprintf(fp_chm, "%f\n", bac.NOTEMATH);

                fclose(fp_chm);
                done_chm = 1;
                chmCount++;
        }

        else
        if(strcmp(choix.CHOIX_2, "GOELOGY") == 0)
        {
            fp_geos= fopen("Geology_Students.txt", "a+");
                if(fp_geos == NULL)
                {
                    printf("\n\t\t\tFile is not opened.");
                    exit(1);
                }
                fprintf(fp_geos, "%d ", can.NCIN);
                fprintf(fp_geos, "%s ", can.NOM);
                fprintf(fp_geos, "%s ", can.PRENOM);
                fprintf(fp_geos, "%d ", can.AGE);
                fprintf(fp_geos, "%s ", bac.SERIEBAC);
                fprintf(fp_geos, "%f ", bac.MOYENNE);
                fprintf(fp_geos, "%f ", bac.NOTEPHY);
                fprintf(fp_geos, "%f\n", bac.NOTEMATH);

                fclose(fp_geos);
                done_geos = 1;
                geosCount++;
        }

        else
        if(strcmp(choix.CHOIX_2, "ICTFORDEV") == 0)
        {
            fp_ict= fopen("ICT_Students.txt", "a+");
                if(fp_ict == NULL)
                {
                    printf("\n\t\t\tFile is not opened.");
                    exit(1);
                }
                fprintf(fp_ict, "%d ", can.NCIN);
                fprintf(fp_ict, "%s ", can.NOM);
                fprintf(fp_ict, "%s ", can.PRENOM);
                fprintf(fp_ict, "%d ", can.AGE);
                fprintf(fp_ict, "%s ", bac.SERIEBAC);
                fprintf(fp_ict, "%f ", bac.MOYENNE);
                fprintf(fp_ict, "%f ", bac.NOTEPHY);
                fprintf(fp_ict, "%f\n", bac.NOTEMATH);

                fclose(fp_ict);
                done_ict = 1;
                ictCount++;
        }

        else
        {
            fp_other = fopen("Other_Students.txt", "a+");
                if(fp_other == NULL)
                {
                    printf("\n\t\t\tFile is not opened.");
                    exit(1);
                }

                fprintf(fp_other, "%d ", can.NCIN);
                fprintf(fp_other, "%s ", can.NOM);
                fprintf(fp_other, "%s ", can.PRENOM);
                fprintf(fp_other, "%d ", can.AGE);
                fprintf(fp_other, "%s ", bac.SERIEBAC);
                fprintf(fp_other, "%f ", bac.MOYENNE);
                fprintf(fp_other, "%f ", bac.NOTEPHY);
                fprintf(fp_other, "%f\n", bac.NOTEMATH);

                fclose(fp_other);
                done_other = 1;
                otherCount++;
        }
    }
    if((done_maths && done_phy && done_bios && done_chm && done_geos && done_ict && done_other) == 1)
    {
        printf("\n\t\t\tThe File for the different selections was generated succesfully!");
    }
    else
    {
        printf("\n\t\t\tThere was a problem generating the File different selections...");
    }
    fflush(stdin);
    getchar( );
}

/*Function to evaluate statistics of students*/
float statistiques()
{
    float percent_admis, percent_bios, percent_chm , percent_geos , percent_ict, percent_maths, percent_phy, percent_other;
    headMessage("STATISTICS");
    /*Globals used here include:**************************************************************************
    countStudent, mathCount, phyCount, biosCount, chmCount, geosCount, ictCount, otherCount, admisCount
    *****************************************************************************************************/
    /*Files used here include:************************************************
    fp_admis, fp_bios, fp_chm, fp_geos, fp_ict, fp_maths, fp_phy, fp_other
    **************************************************************************/

    /*
    if((fp_admis || fp_bios || fp_chm || fp_geos || fp_ict || fp_maths || fp_phy || fp_other) == NULL)
    {
        printf("\n\t\t\tFile does not exists");
		exit(1);
		//return;
    }
    */
    //else
    //{
        /*Admis Percentage*/
         percent_admis = (admisCount / countStudent) * 100;
        //percent = (num_students / tot_students) * 100;

        /*Bios Percentage*/
         percent_bios = (biosCount / countStudent) * 100;
        //percent = (num_students / tot_students) * 100;

        /*Chemistry Percentage*/
         percent_chm = (chmCount / countStudent) * 100;
        //percent = (num_students / tot_students) * 100;

        /*Geology Percentage*/
         percent_geos = (geosCount / countStudent) * 100;
        //percent = (num_students / tot_students) * 100;

        /*ICTFORDEV Percentage*/
         percent_ict = (ictCount / countStudent) * 100;
        //percent = (num_students / tot_students) * 100;

        /*Maths Percentage*/
         percent_maths = (mathCount / countStudent) * 100;
        //percent = (num_students / tot_students) * 100;

        /*Physics Percentage*/
         percent_phy = (phyCount / countStudent) * 100;
        //percent = (num_students / tot_students) * 100;

        /*Other Percentage*/
         percent_other = (otherCount / countStudent) * 100;
        //percent = (num_students / tot_students) * 100;

        /*Displaying the results on the screen*/
        printf("\n\t\t\t****************************************************");
		printf("\n\t\t\t                    INFORMATICS");
		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\tPercentage Number of students = %.3f", percent_admis);
		printf("\n\t\t\t****************************************************\n");

		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\t                    BIOSCCIENCES");
		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\tPercentage Number of students = %.3f", percent_bios);
		printf("\n\t\t\t****************************************************\n");

		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\t                    CHEMISTRY");
		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\tPercentage Number of students = %.3f", percent_chm);
		printf("\n\t\t\t****************************************************\n");

		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\t                    GEOLOGY");
		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\tPercentage Number of students = %.3f", percent_geos);
		printf("\n\t\t\t****************************************************\n");

		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\t                    ICT FOR DEV");
		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\tPercentage Number of students = %.3f", percent_ict);
		printf("\n\t\t\t****************************************************\n");

		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\t                    MATHEMATICS");
		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\tPercentage Number of students = %.3f", percent_maths);
		printf("\n\t\t\t****************************************************\n");

		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\t                    PHYSICS");
		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\tPercentage Number of students = %.3f", percent_phy);
		printf("\n\t\t\t****************************************************\n");

		printf("\n\t\t\t****************************************************");
		printf("\n\t\t\t                    OTHERS");
		printf("\n\t\t\t****************************************************");
        printf("\n\t\t\tPercentage Number of students = %.3f",  percent_other);
        printf("\n\t\t\t****************************************************\n");
    //}
    /*
    fclose(fp_admis);
    fclose(fp_bios);
    fclose(fp_chm);
    fclose(fp_geos);
    fclose(fp_ict);
    fclose(fp_maths);
    fclose(fp_phy);
    fclose(fp_other);
    */
    fflush(stdin);
    getchar( );
}

/*Function to delete student with age greater than 20*/
void supprimerAge()
{
    char decision[10];
	//FILE *fp_admis;
	FILE *fp_admis_del;
	struct Candidate can;
	struct Bacc bac;
	struct Choix choix;

	fp_admis_del = fopen("Admis_Deleted.txt", "w");
    if(fp_admis_del == NULL)
    {
        printf("File does not exists");
		exit(1);
    }

    fp_admis = fopen("Admis.txt", "a+");
    if(fp_admis == NULL)
    {
        printf("File does not exists");
		exit(1);
    }

	while(!feof(fp_admis_del))
	{
	    fscanf(fp_admis, "%d %s %s %d %f %f %f %s %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2, &choix.CHOIX_3, &decision);
		while (can.AGE <= 20)
		{
		    fprintf(fp_admis_del, "%d %s %s %d %s %f %f %f %s %s %s\n", can.NCIN, can.NOM, can.PRENOM, can.AGE, bac.SERIEBAC, bac.MOYENNE, bac.NOTEPHY, bac.NOTEMATH, choix.CHOIX_2, choix.CHOIX_3, decision);
		}
	}
	fclose(fp_admis);
	fclose(fp_admis_del);
	remove("Admis.txt");
	rename("Admis_Deleted.txt", "Admis.txt");

	/*Let us display the admitted students...*/
    fp_admis = fopen("Admis.txt", "r");
    if(fp_admis == NULL)
    {
        printf("File is not opened.");
        exit(1);
    }
    else
    {
        while (!feof(fp_admis))
        {
            fscanf(fp, "%d %s %s %f %f %f %s", &can.NCIN, &can.NOM, &can.PRENOM, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &decision);
            printf("\n\t\t\tNCIN                    = %d ", can.NCIN);
            printf("\n\t\t\tName                    = %s ", can.NOM);
            printf("\n\t\t\tSurname                 = %s ", can.PRENOM);
            printf("\n\t\t\tAge                 = %d ", can.AGE);
            printf("\n\t\t\tBacc. Series                    = %s ", bac.SERIEBAC);
            printf("\n\t\t\tAverage                 = %f ", bac.MOYENNE);
            printf("\n\t\t\tPhysics Note                    = %f ", bac.NOTEPHY);
            printf("\n\t\t\tMaths Note                  = %f ", bac.NOTEMATH);
            printf("\n\t\t\tDECISION                    = %s ", decision);
        }
    }
    fclose(fp_admis);
    fflush(stdin);
    getchar( );
}

/*Function to print each student's record from each file.txt*/
//void printStudInfo()
void affiche_filliere()
{
    char decision[10];
	struct Candidate can;
	struct Bacc bac;
	struct Choix choix;

    /*Files used here include:************************************************
    fp_admis, fp_bios, fp_chm, fp_geos, fp_ict, fp_maths, fp_phy, fp_other
    **************************************************************************/
    headMessage("STUDENTS INFORMATION PER SERIES");

    /*Print Info Students*/
	fp_admis = fopen("Info_Students.txt", "r");

	if(fp_admis== NULL)
	{
		printf("\n\t\t\tFile does not exists");
		exit(1);
		//return;
	}
	else
	{
		printf("\n");
		printf("\n\t\t\t****************************************************\n");
		printf("\n\t\t\t            INFORMATICS STUDENTS...\n");
		printf("\n\t\t\t****************************************************\n");
		while(!feof(fp_admis))
		{
		    fscanf(fp_admis, "%d %s %s %d %f %f %f %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &decision);
			printf("\n\t\t\tIdentification Number	                :	%d", can.NCIN);
			printf("\n\t\t\tNames					:	%s %s", can.NOM, can.PRENOM);
			printf("\n\t\t\tAge					:	%d", can.AGE);
			printf("\n\t\t\tBacc. Series			        :	%s", bac.SERIEBAC);
			printf("\n\t\t\tBacc. Average       			:	%f", bac.MOYENNE);
			printf("\n\t\t\tPhysics mark				    :	%f", bac.MOYENNE);
			printf("\n\t\t\tMathematics mark            		:	%f", bac.MOYENNE);
			printf("\n\t\t\tDECISION            		:	%s", bac.MOYENNE);
		}
	}
	fclose(fp_admis);

	while(!feof(fp))
    {
        fscanf(fp, "%d %s %s %d %f %f %f %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2, &choix.CHOIX_3);
        /*Print Maths Students*/
        if(strcmp(choix.CHOIX_2, "MATHEMATICS") == 0)
        {
            fp_maths = fopen("Maths_Students.txt", "r");

            if(fp_maths == NULL)
            {
                printf("\n\t\t\tFile does not exists");
                exit(1);
            }
            else
            {
                printf("\n");
                printf("\n\t\t\t****************************************************\n");
                printf("\n\t\t\t            MATHEMATICS STUDENTS...\n");
                printf("\n\t\t\t****************************************************\n");
                while(!feof(fp_maths))
                {
                    fscanf(fp_maths, "%d %s %s %d %f %f %f %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2);
                    printf("\n\t\t\tIdentification Number	                :	%d", can.NCIN);
                    printf("\n\t\t\tNames					:	%s %s", can.NOM, can.PRENOM);
                    printf("\n\t\t\tAge 					:	%d", can.AGE);
                    printf("\n\t\t\tBacc. Series			        :	%s", bac.SERIEBAC);
                    printf("\n\t\t\tBacc. Average       			:	%f", bac.MOYENNE);
                    printf("\n\t\t\tPhysics mark				    :	%f", bac.MOYENNE);
                    printf("\n\t\t\tMathematics mark            		:	%f", bac.MOYENNE);
                    printf("\n\t\t\t2nd Choice  				:	%s", choix.CHOIX_2);
                    //printf("\n\t\t\t3rd Choice				:	%s", choix.CHOIX_3);
                }
            }
            fclose(fp_maths);
        }

        /*Print Physics Students*/
        if(strcmp(choix.CHOIX_2, "PHYSICS") == 0)
        {
            fp_phy = fopen("Physics_Students.txt", "r");

            if(fp_phy == NULL)
            {
                printf("\n\t\t\tFile does not exists");
                exit(1);
            }
            else
            {
                printf("\n\n");
                printf("\n\t\t\t****************************************************\n");
                printf("\n\t\t\t               PHYSICS STUDENTS...\n");
                printf("\n\t\t\t****************************************************\n");
                while(!feof(fp_phy))
                {
                    fscanf(fp_phy, "%d %s %s %d %f %f %f %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2);
                    printf("\n\t\t\tIdentification Number			        :	%d", can.NCIN);
                    printf("\n\t\t\tNames			        :	%s %s", can.NOM, can.PRENOM);
                    printf("\n\t\t\tAge			        :	%d", can.AGE);
                    printf("\n\t\t\tBacc. Series			        :	%s", bac.SERIEBAC);
                    printf("\n\t\t\tBacc. Average			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\tPhysics mark			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\tMathematics mark			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\t2nd Choice			        :	%s", choix.CHOIX_2);
                    //printf("\n\t\t\t3rd Choice				:	%s", choix.CHOIX_3);
                }
            }
            fclose(fp_phy);
        }

        /*Print BIOS Students*/
        if(strcmp(choix.CHOIX_2, "BIOSCIENCES") == 0)
        {
            fp_bios = fopen("BIOS_Students.txt", "r");

            if(fp_bios == NULL)
            {
                printf("\n\t\t\tFile does not exists");
                exit(1);
            }
            else
            {
                printf("\n\n");
                printf("\n\t\t\t****************************************************\n");
                printf("\n\t\t\t            BIOSCIENCES STUDENTS...\n");
                printf("\n\t\t\t****************************************************\n");
                while(!feof(fp_bios))
                {
                    fscanf(fp_bios, "%d %s %s %d %f %f %f %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2);
                    printf("\n\t\t\tIdentification Number			        :	%d", can.NCIN);
                    printf("\n\t\t\tNames					:	%s %s", can.NOM, can.PRENOM);
                    printf("\n\t\t\tAge			        :	%d", can.AGE);
                    printf("\n\t\t\tBacc. Series			        :	%s", bac.SERIEBAC);
                    printf("\n\t\t\tBacc. Average			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\tPhysics mark			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\tMathematics mark			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\t2nd Choice			        :	%s", choix.CHOIX_2);
                    //printf("\n\t\t\t3rd Choice				:	%s", choix.CHOIX_3);
                }
            }
            fclose(fp_bios);
        }

        /*Print CHEMISTRY Students*/
        if(strcmp(choix.CHOIX_2, "CHEMISTRY") == 0)
        {
            fp_chm = fopen("Chemistry_Students.txt", "r");

            if(fp_chm == NULL)
            {
                printf("\n\t\t\tFile does not exists");
                exit(1);
            }
            else
            {
                printf("\n\n");
                printf("\n\t\t\t****************************************************\n");
                printf("\n\t\t\t            CHEMISTRY STUDENTS...\n");
                printf("\n\t\t\t****************************************************\n");
                while(!feof(fp_chm))
                {
                    fscanf(fp_chm, "%d %s %s %d %f %f %f %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2);
                    printf("\n\t\t\tIdentification Number			        :	%d", can.NCIN);
                    printf("\n\t\t\tNames			        :	%s %s", can.NOM, can.PRENOM);
                    printf("\n\t\t\tAge			        :	%d", can.AGE);
                    printf("\n\t\t\tBacc. Series			        :	%s", bac.SERIEBAC);
                    printf("\n\t\t\tBacc. Average			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\tPhysics mark			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\tMathematics mark			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\t2nd Choice			        :	%s", choix.CHOIX_2);
                    //printf("\n\t\t\t3rd Choice				:	%s", choix.CHOIX_3);
                }
            }
            fclose(fp_chm);
        }

        /*Print ICTFORDEV Students*/
        if(strcmp(choix.CHOIX_2, "ICTFORDEV") == 0)
        {
            fp_ict = fopen("ICT_Students.txt", "r");

            if(fp_ict == NULL)
            {
                printf("\n\t\t\tFile does not exists");
                exit(1);
            }
            else
            {
                printf("\n\n");
                printf("\n\t\t\t****************************************************\n");
                printf("\n\t\t\t            ICT FOR DEV STUDENTS...\n");
                printf("\n\t\t\t****************************************************\n");
                while(!feof(fp_ict))
                {
                    fscanf(fp_ict, "%d %s %s %d %f %f %f %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2);
                    printf("\n\t\t\tIdentification Number			        :	%d", can.NCIN);
                    printf("\n\t\t\tNames					:	%s %s", can.NOM, can.PRENOM);
                    printf("\n\t\t\tAge			        :	%d", can.AGE);
                    printf("\n\t\t\tBacc. Series			        :	%s", bac.SERIEBAC);
                    printf("\n\t\t\tBacc. Average			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\tPhysics mark			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\tMathematics mark			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\t2nd Choice			        :	%s", choix.CHOIX_2);
                    //printf("\n\t\t\t3rd Choice				:	%s", choix.CHOIX_3);
                }
            }
            fclose(fp_ict);
        }

        /*Print Geology Students*/
        if(strcmp(choix.CHOIX_2, "GOELOGY") == 0)
        {
            fp_geos = fopen("Geology_Students.txt", "r");

            if(fp_geos == NULL)
            {
                printf("\n\t\t\tFile does not exists");
                exit(1);
                //return;
            }
            else
            {
                printf("\n\n");
                printf("\n\t\t\t****************************************************\n");
                printf("\n\t\t\t            GEOLOGY STUDENTS...\n");
                printf("\n\t\t\t****************************************************\n");
                while(!feof(fp_geos))
                {
                    fscanf(fp_geos, "%d %s %s %d %f %f %f %s %s %s", &can.NCIN, &can.NOM, &can.PRENOM, &can.AGE, &bac.MOYENNE, &bac.NOTEPHY, &bac.NOTEMATH, &bac.SERIEBAC, &choix.CHOIX_2);
                    printf("\n\t\t\tIdentification Number			        :	%d", can.NCIN);
                    printf("\n\t\t\tNames					:	%s %s", can.NOM, can.PRENOM);
                    printf("\n\t\t\tAge			        :	%d", can.AGE);
                    printf("\n\t\t\tBacc. Series			        :	%s", bac.SERIEBAC);
                    printf("\n\t\t\tBacc. Average			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\tPhysics mark			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\tMathematics mark			        :	%f", bac.MOYENNE);
                    printf("\n\t\t\t2nd Choice			        :	%s", choix.CHOIX_2);
                    //printf("\n\t\t\t3rd Choice				:	%s", choix.CHOIX_3);
                }
            }
            fclose(fp_geos);
        }

        /*Print Other Students*/
        fp_other = fopen("Other_Students.txt", "r");

        if(fp_other == NULL)
        {
            printf("\n\t\t\tFile does not exists");
            exit(1);
            //return;
        }
        else
        {
            printf("\n\n");
            printf("\n\t\t\t****************************************************\n");
            printf("\n\t\t\t               OTHER STUDENTS...\n");
            printf("\n\t\t\t****************************************************\n");
            while(!feof(fp_other))
            {
                fscanf(fp_other, "%d %s %s %d %f %f %f %s %s %s", can.NCIN, can.NOM, can.PRENOM, can.AGE, bac.MOYENNE, bac.NOTEPHY, bac.NOTEMATH, bac.SERIEBAC, choix.CHOIX_2, choix.CHOIX_3);
                printf("\n\t\t\tIdentification Number			        :	%d", can.NCIN);
                printf("\n\t\t\tNames					:	%s %s", can.NOM, can.PRENOM);
                printf("\n\t\t\tAge			        :	%d", can.AGE);
                printf("\n\t\t\tBacc. Series			        :	%s", bac.SERIEBAC);
                printf("\n\t\t\tBacc. Average			        :	%f", bac.MOYENNE);
                printf("\n\t\t\tPhysics mark			        :	%f", bac.MOYENNE);
                printf("\n\t\t\tMathematics mark			        :	%f", bac.MOYENNE);
                printf("\n\t\t\t2nd Choice			        :	%s", choix.CHOIX_2);
                //printf("\n\t\t\t3rd Choice			        :	%s", choix.CHOIX_3);
            }
        }
        fclose(fp_other);
    }
}


int main()
{
    int modify;
    int Delete;
    int choice = 0;

    welcomeMessage();

    do
    {
		headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add a student record........................................<Press 1>\n");
        printf("\n\t\t\t2.Display a student's record..................................<Press 2>\n");
        printf("\n\t\t\t3.Modify a student's record...................................<Press 3>\n");
		printf("\n\t\t\t4.Delete a student's record...................................<Press 4>\n");
		printf("\n\t\t\t5.Generate Results File.......................................<Press 5>\n");
		printf("\n\t\t\t6.Generate and Print List of Admitted Students................<Press 6>\n");
		printf("\n\t\t\t7.Generate Other Series' Files................................<Press 7>\n");
		printf("\n\t\t\t8.Generate Statistics for each Series.........................<Press 8>\n");
		printf("\n\t\t\t9.Filter Admitted Students and Print New List.................<Press 9>\n");
		printf("\n\t\t\t10.Print Students' List for each Series.......................<Press 10>\n");
		printf("\n\t\t\t0.Exit........................................................<Press 0>\n");
        printf("\n\n\n\t\t\tEnter your choice here.....");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudent();
            break;
        case 3:
            printf("\n\t\t\tEnter the student's Identification Number (NCIN) to proceed to modification: ");
			scanf("%d", &modify);
            modifyStudent(modify);
            break;
        case 4:
            printf("\n\t\t\tEnter Student's Identification Number to proceed to deletion: ");
            scanf("%d", &Delete);
            deleteStudent(Delete);
			break;
        case 5:
            results();
            break;
        case 6:
            admis();
            break;
        case 7:
            selection();
            break;
        case 8:
            statistiques();
            break;
        case 9:
            supprimerAge();
            break;
        case 10:
            affiche_filliere();
            break;
        case 0:
            //printf("Thanks for using our student Management software...\nSee you soon!");
            headMessage("Thanks for using our student Management software.\n\t\t\t\tSee you soon!........................................");
            printf("\n\n\n\n\n\n\n\n");
			exit(1);
        default:
            printf("\n\n\n\t\t\tInvalid Input!!! Try Again....\n");
        }
    }
	while(choice != 0);
    return 0;
}
