/* 
    Project : Students Database Management using C programming language
    Students Name : Ganesh Yashwant Sargar
    Roll No : 99
*/
#include<stdio.h>
#include<string.h>

    void addStudent();
    void studentRecorD();
    void searchStudent();
    void delete();

struct student{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char class[20];
};


void main(){
    int choice;
    
    while(choice != 5){
        system("cls");
        printf("\t\t===============> WELCOME TO STUDENT DATABASE MANAGEMENT <===============");
        printf("\n\n\t\t\t\t 1. Add Student Record\n");
        printf("\t\t\t\t 2. Student Record\n");
        printf("\t\t\t\t 3. Search Student\n");
        printf("\t\t\t\t 4. Delete Record\n");
        printf("\t\t\t\t 5. Exit\n");
        printf("\t\t________________________________________________________\n");
        scanf("%d", &choice);

        switch(choice){
            case 1 :
                    system("cls");
                    addStudent();
                    system("cls");
                    break;
            case 2 :
                    studentRecord();
                    printf("\n\t\t\t\tpress any key to exit\n");
                    getch();
                    break;
            case 3 : 
                    searchStudent();
                    printf("\n\t\t\t\tPress any key to exit\n");
                    getch();
                    break;
            case 4 :
                    delete();
                    printf("\n\t\t\t\tPress any key to exit\n");
                    getch();
                    break;
            case 5 :
                    system("cls");
                    printf("\n\t\t\t\t Thank you for used this software \n");
                    printf("\t\t\t______________________________________________________\n");
                    getch();
                    exit(0);
                    break;

            default : 
                    printf("\n\t\t\t\t Please enter a valid number ");
                    printf("\n\t\t\t\t Press any key to continue....\n");
                    getch();
        }       
    }
}
void addStudent(){
    char another;
    FILE *fptr;
    struct student info;
    do{
        system("cls");
        printf("\t\t\t===============> Add Students Information <===============\n");
        fptr = fopen("student_info.txt", "a");
        printf("\n\t\t\t\t Enter First Name : ");
        scanf("%s", &info.first_name);
        printf("\n\t\t\t\t Enter Last Name  : ");
        scanf("%s", &info.last_name);
        printf("\n\t\t\t\t Enter Roll No    : ");
        scanf("%d", &info.roll_no);
        printf("\n\t\t\t\t Enter Class      : ");
        scanf("%s", &info.class);
        printf("\t\t\t\t_________________________________________");
 
        if(fptr == NULL){
            fprintf(stderr, "\t\t\t\tCan't open file\n");
        }
        else{
            printf("\n\t\t\t\t\tRecord stored successfuly\n\n");
        }

        fwrite(&info,sizeof(struct student),1,fptr);
        fclose(fptr);

        printf("\t\t\t Do you want to add another record?(Y/N) : ");
        scanf("%s", &another);

    }while(another =='y' || another == 'Y');
}

void studentRecord(){
    system("cls");
    FILE *fptr;
    struct student info;
    fptr = fopen("student_info.txt", "r");
    printf("\t\t\t\tSTUDENTS RECORD\n");
    if(fptr == NULL){
        printf("\t\t\t\tCan't open file\n");
    }
    else{
        printf("\t\t\t ________________________________________\n");
    }

    while(fread(&info,sizeof(struct student),1,fptr)){
        printf("\n\t\t\t\tStudent name : %s %s", info.first_name, info.last_name);
        printf("\n\t\t\t\tRoll No      : %d", info.roll_no);
        printf("\n\t\t\t\tClass        : %s", info.class);
        printf("\n\t\t\t_______________________________________\n");
    }
    fclose(fptr);
    
}

void searchStudent(){
    system("cls");
    FILE *fptr;
    struct student info;
    int roll_no, found = 0;

    fptr = fopen("student_info.txt", "r");

    printf("\n\t\t\t\t\tSEARCH STUDENT\n");
    printf("\n\t\t\t\tEnter roll No : ");
    scanf("%d", &roll_no);
    printf("\n\t\t\t_______________________________________\n");

    while(fread(&info, sizeof(struct student),1,fptr)){
        if(info.roll_no == roll_no){
            found =1;
             printf("\n\t\t\t\tStudent name : %s %s", info.first_name, info.last_name);
             printf("\n\t\t\t\tRoll No      : %d", info.roll_no);
             printf("\n\t\t\t\tClass        : %s", info.class);
             printf("\n\t\t\t_______________________________________\n");

        }
    }

    if(!found){
        printf("\t\t\t\tRecord not found");
    }
    fclose(fptr);
    
}

void delete(){
    system("cls");
    FILE *fptr, *fptr1;
    struct student info;
    int roll_no, found = 0;

    printf("\n\t\t\t\tDELETE STUDENT RECORD\n\n");
    fptr = fopen("student_info.txt", "r");
    fptr1 = fopen("temp.txt", "w");

    printf("\t\t\t\tEnter roll No : ");
    scanf("%d", &roll_no);
    printf("\n\t\t\t_______________________________________");

    while(fread(&info, sizeof(struct student),1,fptr)){
        if(info.roll_no == roll_no){
            found =1;
         }
         else{
            fwrite(&info,sizeof(struct student),1,fptr1);
         }
    }
    fclose(fptr);
    fclose(fptr1);

    if(found){
        remove("student_info.txt");
        rename("temp.txt", "student_info.txt");
        printf("\n\t\t\t\tRecord deleted successfuly\n");
    }
    if(!found){
        printf("\n\t\t\t\tRecord is not found");
    }
}