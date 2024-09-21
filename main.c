#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define pf printf
#define sf scanf
#define MAX_NUM_COURSES 7
#define MAX_NAME_LENGTH 50
typedef struct
{
    char name[50];
    char department[10];
    float per;
    int pay;
    struct Courses
    {
        char n_course[50];
        char code[8];
        int credit_hours;
    } cours[MAX_NUM_COURSES];
    int ESP;
    char esp[10];
} student;
//=============================================================================================================
typedef enum
{
    A, B, C, D, F
} Grade;

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char reg_num[MAX_NAME_LENGTH];
    char pin[MAX_NAME_LENGTH];
    float gpa;
    struct Corse
    {
        char name[50];
        char c_course[10];
        int credit_hours;
        float attend;
        char grade[2];
    } courses[MAX_NUM_COURSES];
} Student;
//===============================================================================================================
//new student
void input_data(student s1)
{
    char c='%';
    FILE *Fnew = fopen("registration.txt", "a");
    if (Fnew == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    fprintf(Fnew, "\n\nName: %s\n", s1.name);
    fprintf(Fnew, "Department: %s\n", s1.department);
    fprintf(Fnew,"High school grade: %.2f %c\n",s1.per,c);
    fprintf(Fnew,"Payment: %d\\nn",s1.pay);
    for(int i=0; i<6; i++)
    {
        fprintf(Fnew,"Course: %s\n",s1.cours[i].n_course);
        fprintf(Fnew,"Code course: %s\n",s1.cours[i].code);
        fprintf(Fnew,"Credit hour: %d\n",s1.cours[i].credit_hours);
        fprintf(Fnew,"\n\n");
    }
    fprintf(Fnew,"you will enroll in %s",s1.esp);
    fclose(Fnew);

    printf("\nStudent registered successfully!\n");
}
void online_registration()
{
    student s1;
    printf("Enter the student's name: ");
    getchar();
    fgets(s1.name, sizeof(s1.name), stdin);
    pf("Choose your Department :\n1- Math\n2- Science\n");
    {
        int choice=0;
        pf("Choice= ");
        sf("%d",&choice);

        pf("\nEnter your high school degree: ");
        sf("%f",&s1.per);
        if(s1.per<60)
        {
            pf("Sorry you cannot register .\n");
            return ;
        }
        else
        {
            if(s1.per<65)
            {
                s1.pay=30877;
            }
            else if(s1.per>=65||s1.per<70)
            {
                s1.pay=28843;
            }
            else if(s1.per>=70)
            {
                s1.pay=22741;
            }
        }
        if(choice==1)
        {
            {
                strcpy(s1.department,"Math");
                strcpy(s1.cours[0].n_course, "introduction to computing");
                strcpy(s1.cours[0].code, "CCS1101");
                s1.cours[0].credit_hours = 3;
                strcpy(s1.cours[1].n_course, "Calculas I");
                strcpy(s1.cours[1].code, "EBA1203");
                s1.cours[1].credit_hours = 3;
                strcpy(s1.cours[2].n_course, "Introduction to information systems");
                strcpy(s1.cours[2].code, "CIS1000");
                s1.cours[2].credit_hours = 3;
                strcpy(s1.cours[3].n_course, "Physics");
                strcpy(s1.cours[3].code, "EBA1110");
                s1.cours[3].credit_hours = 3;
                strcpy(s1.cours[4].n_course, "Fundamentals of business");
                strcpy(s1.cours[4].code, "UNR1302");
                s1.cours[4].credit_hours = 2;
                strcpy(s1.cours[5].n_course, "Creativity and innovationn");
                strcpy(s1.cours[5].code, "UNR1102");
                s1.cours[5].credit_hours = 2;
            }


        }
        else if(choice==2)
        {
            strcpy(s1.department,"Science");
            strcpy(s1.cours[0].n_course, "Introduction to computing");
            strcpy(s1.cours[0].code, "CCS1101");
            s1.cours[0].credit_hours = 3;
            strcpy(s1.cours[1].n_course, "Precalculas");
            strcpy(s1.cours[1].code, "BA003");
            s1.cours[1].credit_hours =0;
            strcpy(s1.cours[2].n_course, "Introduction to information systems");
            strcpy(s1.cours[2].code, "CIS1000");
            s1.cours[2].credit_hours = 3;
            strcpy(s1.cours[3].n_course, "Physics");
            strcpy(s1.cours[3].code, "EBA1110");
            s1.cours[3].credit_hours = 3;
            strcpy(s1.cours[4].n_course, "Fundamentals of business");
            strcpy(s1.cours[4].code, "UNR1302");
            s1.cours[4].credit_hours = 2;
            strcpy(s1.cours[5].n_course, "Creativity and innovationn");
            strcpy(s1.cours[5].code, "UNR1102");
            s1.cours[5].credit_hours = 2;
        }
    }
    pf("Enter your degree in ESP: ");
    sf("%d",&s1.ESP);
    if(s1.ESP<20)
    {
        strcpy(s1.esp, "Esp 0");
    }
    else
    {
        strcpy(s1.esp, "Esp 1");
    }
    input_data(s1);
}
//=============================================================================================================================
void teacher_assis()
{
    Student s;
    char reg[10];
    float gpa;
l:
    printf("Enter the registration number : ");
    getchar();
    fgets(reg, sizeof(reg), stdin);



    if (strcmp(reg, "200015200") == 0)
    {
        FILE* Fstd = fopen("200015200.txt", "w+");
        if (Fstd == NULL)
        {
            printf("Error opening file\n");
            return;
        }

        strcpy(s.name,"Khaled Mohammed");
        strcpy(s.reg_num,reg);
        fprintf(Fstd,"Name: %s\n",s.name);
        fprintf(Fstd,"Registeration number: %s\n",s.reg_num);
        pf("Enter the GPA: ");
        sf("%f",&gpa);
        if(gpa<2)
        {
            printf("\t\t\t\t\tThe student with registration number %s has been registered for 4 subjects.\n", reg);


            int num_subjects = 4;

            for (int i = 0; i < num_subjects; i++)
            {
                printf("\nEnter the name of subject %d: ", i + 1);
                scanf("%s",s.courses[i].name);
                printf("Enter the name of subject %d: ", i + 1);
                scanf("%d",&s.courses[i].credit_hours);
                fprintf(Fstd,"\nCourse: %s\n",s.courses[i].name);
                fprintf(Fstd,"Credit hour: %d\n",s.courses[i].credit_hours);
                fprintf(Fstd,"\n\n");
                printf("\n\n");
            }
        }
        else
        {
            for (int i = 0; i < 7; i++)
            {
                printf("\nEnter the name of subject %d: ", i + 1);
                getchar();
                fgets(s.courses[i].name, sizeof(s.courses[i].name), stdin);
                fprintf(Fstd, "Course: %s\n", s.courses[i].name);
                printf("Enter the credit hour: ");
                scanf("%d",&s.courses[i].credit_hours);
                fprintf(Fstd, "Credit hour: %d\n", s.courses[i].credit_hours);
                fprintf(Fstd,"\n\n");
                printf("\n\n");
            }

        }
        fclose(Fstd);

    }
    else if (strcmp(reg, "210005465") == 0)
    {
        FILE* Fstd = fopen("210005465.txt", "w+");
        if (Fstd == NULL)
        {
            printf("Error opening file\n");
            return;
        }

        strcpy(s.name,"Salah Eldin Gamal");
        strcpy(s.reg_num,reg);
        fprintf(Fstd,"Name: %s\n",s.name);
        fprintf(Fstd,"Registeration number: %s\n",s.reg_num);
        pf("Enter the GPA: ");
        sf("%f",&gpa);
        if(gpa<2)
        {
            printf("\t\t\t\t\tThe student with registration number %s has been registered for 4 subjects.\n", reg);


            int num_subjects = 4;
            for (int i = 0; i < num_subjects; i++)
            {
                printf("\nEnter the name of subject %d: ", i + 1);
                scanf("%s",s.courses[i].name);
                printf("Enter the name of subject %d: ", i + 1);
                scanf("%d",&s.courses[i].credit_hours);
                fprintf(Fstd,"Course: %s\n",s.courses[i].name);
                fprintf(Fstd,"Credit hour: %d\n",s.courses[i].credit_hours);
                fprintf(Fstd,"\n\n");
                printf("\n\n");
            }
        }
        else
        {
            for (int i = 0; i < 7; i++)
            {
                printf("\nEnter the name of subject %d: ", i + 1);
                getchar();
                fgets(s.courses[i].name, sizeof(s.courses[i].name), stdin);
                 printf("Enter the credit hour: ");
                scanf("%d",&s.courses[i].credit_hours);
               fprintf(Fstd, "Course: %s\n", s.courses[i].name);
                fprintf(Fstd, "Credit hour: %d\n", s.courses[i].credit_hours);
                fprintf(Fstd,"\n\n");
                printf("\n\n");
            }

        }
        fclose(Fstd);
    }

    else if (strcmp(reg, "210086545") == 0)
    {
        FILE* Fstd = fopen("210086545.txt", "w+");
        if (Fstd == NULL)
        {
            printf("Error opening file\n");
            return;
        }

        strcpy(s.name,"Hamza Mamdouh");
        strcpy(s.reg_num,reg);
        fprintf(Fstd,"Name: %s\n",s.name);
        fprintf(Fstd,"Registeration number: %s\n",s.reg_num);
        pf("Enter the GPA: ");
        sf("%f",&gpa);
        if(gpa<2)
        {
            printf("\t\t\t\t\tThe student with registration number %s has been registered for 4 subjects.\n", reg);


            int num_subjects = 4;
            for (int i = 0; i < num_subjects; i++)
            {
                printf("\nEnter the name of subject %d: ", i + 1);
                scanf("%s",s.courses[i].name);
                printf("Enter the name of subject %d: ", i + 1);
                scanf("%d",&s.courses[i].credit_hours);
                fprintf(Fstd,"Course: %s\n",s.courses[i].name);
                fprintf(Fstd,"Credit hour: %d\n",s.courses[i].credit_hours);
                fprintf(Fstd,"\n\n");
                printf("\n\n");
            }
        }
        else
        {
            for (int i = 0; i < 7; i++)
            {
                printf("\nEnter the name of subject %d: ", i + 1);
                getchar();
                fgets(s.courses[i].name, sizeof(s.courses[i].name), stdin);
                printf("Enter the credit hour: ");
                scanf("%d",&s.courses[i].credit_hours);
                fprintf(Fstd, "Course: %s\n", s.courses[i].name);
                fprintf(Fstd, "Credit hour: %d\n", s.courses[i].credit_hours);
                fprintf(Fstd,"\n\n");
                printf("\n\n");
            }

            fclose(Fstd);
        }
    }
    else if(strcmp(reg,"221008774")==0)
    {
        FILE* Fstd = fopen("221008774.txt", "w+");
        if (Fstd == NULL)
        {
            printf("Error opening file\n");
            return;
        }

        strcpy(s.name,"Mohammed Khaled");
        strcpy(s.reg_num,reg);
        fprintf(Fstd,"Name: %s\n",s.name);
        fprintf(Fstd,"Registeration number: %s\n",s.reg_num);
        fprintf(Fstd,"\n\n");
        pf("Enter the GPA: ");
        sf("%f",&gpa);
        if(gpa<2)
        {
            printf("\t\t\t\t\tThe student with registration number %s has been registered for 4 subjects.\n", reg);


            int num_subjects = 4;
            for (int i = 0; i < num_subjects; i++)
            {
                printf("\nEnter the name of subject %d: ", i + 1);
                scanf("%s",s.courses[i].name);
                printf("Enter the name of subject %d: ", i + 1);
                scanf("%d",&s.courses[i].credit_hours);
                fprintf(Fstd,"Course: %s\n",s.courses[i].name);
                fprintf(Fstd,"Credit hour: %d\n",s.courses[i].credit_hours);
                fprintf(Fstd,"\n\n");
                printf("\n\n");
            }
        }
        else
        {
            for (int i = 0; i < 7; i++)
            {
                printf("\nEnter the name of subject %d: ", i + 1);
                getchar();
                fgets(s.courses[i].name, sizeof(s.courses[i].name), stdin);
                printf("Enter the credit hour: ");
                scanf("%d",&s.courses[i].credit_hours);
                fprintf(Fstd, "Course: %s", s.courses[i].name);
                fprintf(Fstd, "Credit hour: %d\n\n", s.courses[i].credit_hours);
                fprintf(Fstd,"\n\n");
                printf("\n\n");

            }

        }
        fclose(Fstd);

    }
    else
    {
        pf("Incorrect Registration Number\n\n");
        goto l;
    }
}
//=============================================================================================================================

void grades()
{
    int week7, week12, year_work, final_exam, total = 0;
    Student s;
    char regist[MAX_NAME_LENGTH];
    l:printf("\n\nRegistration number of the student: ");
    scanf("%s", regist);


    if (strcmp(regist, "210086545") == 0)
    {
        FILE *fstd = fopen("210086545.txt", "w+");
        if (fstd == NULL)
        {
            printf("Error opening file\n");
            return;
        }
        strcpy(s.name, "Hamza Mamdouh");
        fprintf(fstd,"Name: %s\n", s.name);
        fprintf(fstd,"Registration number: %s",s.reg_num);
        /////////
        strcpy(s.courses[0].name, "Introduction to Networks");

        strcpy(s.courses[0].c_course, "CE231");

        s.courses[0].credit_hours = 3;

        s.courses[0].attend = 6.7;



/////
        strcpy(s.courses[1].name, "Intro. to Computer Architecture");

        strcpy(s.courses[1].c_course, "CE243");

        s.courses[1].credit_hours = 3;

        s.courses[1].attend = 3.3;


        /////
        strcpy(s.courses[2].name, "Professional Training in Entrepreneurship");

        strcpy(s.courses[2].c_course, "IT291");

        s.courses[2].credit_hours = 2;

        s.courses[2].attend = 0;





        strcpy(s.courses[3].name, "Data Structures and Algorithms");

        strcpy(s.courses[3].c_course, "CS212");

        s.courses[3].credit_hours = 3;

        s.courses[3].attend = 0;



        strcpy(s.courses[4].name, "Advanced Programming Applications");

        strcpy(s.courses[4].c_course, "CS244");

        s.courses[4].credit_hours = 3;

        s.courses[4].attend = 0;



        strcpy(s.courses[5].name, "Database Systems");

        strcpy(s.courses[5].c_course, "IS273");

        s.courses[5].credit_hours = 3;

        s.courses[5].attend = 0;





        strcpy(s.courses[6].name, "Introduction to Software Engineering");

        strcpy(s.courses[6].c_course, "SE291");
        s.courses[6].credit_hours = 3;
        s.courses[6].attend = 0;
        strcpy(s.courses[6].grade,"A");

        for (int i = 0; i < 7; i++)
        {
            pf("Course: %s\n",s.courses[i].name);
            pf("Code: %s\n",s.courses[i].c_course);
            pf("Credit Hour: %d\n",s.courses[i].credit_hours);

r:
            printf("\n\n\t\t\t\t\t\t\tEnter the grade for week 7 of course %d: ", i + 1);
            scanf("%d", &week7);
            if(week7>30)
            {
                printf("\n\n\t\t\tShould be lessthan or equal 30\n");
                goto r;
            }
r1:
            printf("\n\n\t\t\t\t\t\t\tEnter the grade for week 12 of course %d Should be lees than or equal 20 : ", i + 1);
            scanf("%d", &week12);
            if(week12>20)
            {
                printf("\n\n\t\t\tShould be lessthan or equal 30\n");
                goto r1;
            }
l1:
            printf("\n\n\t\t\t\t\t\t\tThe year work degree should be between 0 and 10");
            printf("\n\n\t\t\t\t\t\t\tEnter the grade for year work of course %d: ", i + 1);
            scanf("%d", &year_work);
            if(year_work>10||year_work<0)
            {
                printf("\n\n\t\t\t\t\t\t\tThe year work degree should be between 0 and 10");
                goto l1;
            }

            printf("\n\n\t\t\t\t\t\t\tEnter the grade for final exam of course %d: ", i + 1);
            scanf("%d", &final_exam);

            int course_total = week7 + week12 + year_work + final_exam;

            total += course_total;
            if (course_total>=90 && course_total<=100)
            {
                strcpy(s.courses[i].grade,"A+");

            }
            else if(course_total>=85 && course_total<=89)
            {
                strcpy(s.courses[i].grade,"A");
            }
            else if(course_total>=80 && course_total<=84)
            {

                strcpy(s.courses[i].grade,"B+");

            }
            else if(course_total>=75 && course_total<=79)
            {

                strcpy(s.courses[i].grade,"B");

            }
            else if(course_total>=70 && course_total<=74)
            {

                strcpy(s.courses[i].grade,"B-");

            }
            else if(course_total>=65 && course_total<=69)
            {

                strcpy(s.courses[i].grade,"C+");

            }
            else if(course_total>=60 && course_total<=64)
            {

                strcpy(s.courses[i].grade,"C");

            }
            else if(course_total>=55 && course_total<=59)
            {

                strcpy(s.courses[i].grade,"D+");

            }
            else if(course_total>=50 && course_total<=54)
            {
                strcpy(s.courses[i].grade,"D-");

            }
            else if(course_total>=0 && course_total<=50)
            {

                strcpy(s.courses[i].grade,"F");
            }
        }

        float per=0.0;
        per=total/175;


        for (int i = 0; i < 7; i++)
        {
            fprintf(fstd, "\n\tCourse: %s",s.courses[i].name);
            fprintf(fstd, "\n\tCredit hours for course %s: %d", s.courses[i].name, s.courses[i].credit_hours);
            fprintf(fstd, "\n\tGrade for course %s: %s",s.courses[i].name, s.courses[i].grade);
            fprintf(fstd,"\n\n");
        }
        s.gpa=per;
        printf("GPA: %f",s.gpa);

        fprintf(fstd, "\n\n\t\t\tGPA of the student: %.2f", s.gpa);
        fclose(fstd);
    }
    else if(strcmp(regist,"221008774")==0)
    {

        FILE *fstd = fopen("221008774.txt", "w+");
        if (fstd == NULL)
        {
            printf("Error opening file\n");
            return;
        }
        strcpy(s.name, "Mohammed Khaled");
        fprintf(fstd,"Name: %s\n", s.name);
        strcpy(s.courses[0].name, "Calculus I");
        strcpy(s.courses[0].c_course, "BA101");

        s.courses[0].credit_hours = 3;

        s.courses[0].attend = 6.7;



/////
        strcpy(s.courses[1].name, "Introduction to computing");

        strcpy(s.courses[1].c_course, "CCS1101");

        s.courses[1].credit_hours = 3;

        s.courses[1].attend = 3.3;





        strcpy(s.courses[2].name, "English for Specific Purposes I (ESP I)");
        strcpy(s.courses[2].c_course, "LH135");
        s.courses[2].credit_hours = 2;
        s.courses[2].attend = 0;



        strcpy(s.courses[3].name, "Fundamentals of Business");
        strcpy(s.courses[3].c_course, "NC172");
        s.courses[3].credit_hours = 2;
        s.courses[3].attend = 0;



        strcpy(s.courses[4].name, "Creativity and innovation");
        strcpy(s.courses[4].c_course, "CS111");
        s.courses[4].credit_hours = 2;
        s.courses[4].attend = 0;



        strcpy(s.courses[5].name, "Introduction to Information Systems");
        strcpy(s.courses[5].c_course, "IS171");
        s.courses[5].credit_hours = 3;
        s.courses[5].attend = 0;



        strcpy(s.courses[6].name, "Physics");
        strcpy(s.courses[6].c_course, "BA113");
        s.courses[6].credit_hours = 3;
        s.courses[6].attend = 0;
        for (int i = 0; i < 7; i++)
        {
            pf("Course: %s\n",s.courses[i].name);
            pf("Code: %s\n",s.courses[i].c_course);
            pf("Credit Hour: %d\n",s.courses[i].credit_hours);

r2:
            printf("\n\n\t\t\t\t\t\t\tEnter the grade for week 7 of course %d: ", i + 1);
            scanf("%d", &week7);
            if(week7>30)
            {
                printf("\n\n\t\t\tShould be lessthan or equal 30\n");
                goto r2;
            }
r3:
            printf("\n\n\t\t\t\t\t\t\tEnter the grade for week 12 of course %d: ", i + 1);
            scanf("%d", &week12);
            if(week12>20)
            {
                printf("\n\n\t\t\tShould be lessthan or equal 20\n");
                goto r3;
            }
l2:
            printf("\n\n\t\t\t\t\tThe year work degree should be between 0 and 10");
            printf("\n\n\t\t\t\t\tEnter the grade for year work of course %d: ", i + 1);
            scanf("%d", &year_work);
            if(year_work>10||year_work<0)
            {
                goto l2;
                printf("\n\n\t\t\t\t\tThe year work degree should be between 0 and 10");
            }

            printf("\n\n\t\t\t\t\t\t\tEnter the grade for final exam of course %d: ", i + 1);
            scanf("%d", &final_exam);

            int course_total = week7 + week12 + year_work + final_exam;

            total += course_total;
            if (course_total>=90 && course_total<=100)
            {
                strcpy(s.courses[i].grade,"A+");

            }
            else if(course_total>=85 && course_total<=89)
            {
                strcpy(s.courses[i].grade,"A");
            }
            else if(course_total>=80 && course_total<=84)
            {

                strcpy(s.courses[i].grade,"B+");

            }
            else if(course_total>=75 && course_total<=79)
            {

                strcpy(s.courses[i].grade,"B");

            }
            else if(course_total>=70 && course_total<=74)
            {

                strcpy(s.courses[i].grade,"B-");

            }
            else if(course_total>=65 && course_total<=69)
            {

                strcpy(s.courses[i].grade,"C+");

            }
            else if(course_total>=60 && course_total<=64)
            {

                strcpy(s.courses[i].grade,"C");

            }
            else if(course_total>=55 && course_total<=59)
            {

                strcpy(s.courses[i].grade,"D+");

            }
            else if(course_total>=50 && course_total<=54)
            {
                strcpy(s.courses[i].grade,"D-");

            }
            else if(course_total>=0 && course_total<=50)
            {

                strcpy(s.courses[i].grade,"F");
            }
        }

        float per=0.0;
        per=total/175;
        s.gpa=per;

        for (int i = 0; i < 7; i++)
        {
            fprintf(fstd, "\n\tCourse: %s",s.courses[i].name);
            fprintf(fstd, "\n\tCredit hours for course %s: %d", s.courses[i].name, s.courses[i].credit_hours);
            fprintf(fstd, "\n\tGrade for course %s: %s",s.courses[i].name, s.courses[i].grade);
                       fprintf(fstd,"\n\n");
        }
        printf("GPA: %.2f",s.gpa);

        fprintf(fstd, "\n\n\t\t\tGPA of the student: %.2f", s.gpa);
        fclose(fstd);
    }
    else if(strcmp(regist,"210005465")==0)
    {
        FILE *fstd = fopen("210005465.txt", "w+");
        if(fstd == NULL)
        {
            printf("Cannot open the file\n");
            return;
        }
        strcpy(s.name, "Salah Eldin Gamal");
        fprintf(fstd,"Name: %s\n", s.name);
        /////////
        strcpy(s.courses[0].name, "Advanced Statistics");
        strcpy(s.courses[0].c_course, "BA301");
        s.courses[0].credit_hours = 3;
        s.courses[0].attend = 6.7;


/////
        strcpy(s.courses[1].name, "Linear Algebra");
        strcpy(s.courses[1].c_course, "BA304");
        s.courses[1].credit_hours = 3;
        s.courses[1].attend = 3.3;



        strcpy(s.courses[2].name, "Theory of Computation");
        strcpy(s.courses[2].c_course, "CS311");
        s.courses[2].credit_hours = 3;
        s.courses[2].attend = 0;



        strcpy(s.courses[3].name, "Systems Programming");
        strcpy(s.courses[3].c_course, "CS321");
        s.courses[3].credit_hours = 3;
        s.courses[3].attend = 0;



        strcpy(s.courses[4].name, "Web Programming");
        strcpy(s.courses[4].c_course, "CS333");
        s.courses[4].credit_hours = 3;
        s.courses[4].attend = 0;


        strcpy(s.courses[5].name, "Computer Graphics");
        strcpy(s.courses[5].c_course, "CS352");
        s.courses[5].credit_hours = 3;
        s.courses[5].attend = 0;



        strcpy(s.courses[6].name, "Professional Training in Programming I (.Net 1)");
        strcpy(s.courses[6].c_course, "IT321");
        s.courses[6].credit_hours = 3;
        s.courses[6].attend = 0;


        for (int i = 0; i < 7; i++)
        {
            pf("Course: %s\n",s.courses[i].name);
            pf("Code: %s\n",s.courses[i].c_course);
            pf("Credit Hour: %d\n",s.courses[i].credit_hours);

r4:
            printf("\n\n\t\t\t\t\t\t\tEnter the grade for week 7 of course %d: ", i + 1);
            scanf("%d", &week7);
            if(week7>30)
            {
                printf("\n\n\t\t\tShould be lessthan or equal 30\n");
                goto r4;
            }
r5:
            printf("\n\n\t\t\t\t\t\t\tEnter the grade for week 12 of course %d: ", i + 1);
            scanf("%d", &week12);
            if(week12>20)
            {
                printf("\n\n\t\t\tShould be lessthan or equal 20\n");
                goto r5;
            }
l3:
            printf("\n\n\t\t\t\t\tThe year work degree should be between 0 and 10");
            printf("\n\n\t\t\t\t\tEnter the grade for year work of course %d: ", i + 1);
            scanf("%d", &year_work);
            if(year_work>10||year_work<0)
            {
                goto l3;
                printf("\n\n\t\t\t\t\tThe year work degree should be between 0 and 10");
            }

            printf("\n\n\t\t\t\t\t\t\tEnter the grade for final exam of course %d: ", i + 1);
            scanf("%d", &final_exam);

            int course_total = week7 + week12 + year_work + final_exam;
if (course_total>=90 && course_total<=100)
            {
                strcpy(s.courses[i].grade,"A+");

            }
            else if(course_total>=85 && course_total<=89)
            {
                strcpy(s.courses[i].grade,"A");
            }
            else if(course_total>=80 && course_total<=84)
            {

                strcpy(s.courses[i].grade,"B+");

            }
            else if(course_total>=75 && course_total<=79)
            {

                strcpy(s.courses[i].grade,"B");

            }
            else if(course_total>=70 && course_total<=74)
            {

                strcpy(s.courses[i].grade,"B-");

            }
            else if(course_total>=65 && course_total<=69)
            {

                strcpy(s.courses[i].grade,"C+");

            }
            else if(course_total>=60 && course_total<=64)
            {

                strcpy(s.courses[i].grade,"C");

            }
            else if(course_total>=55 && course_total<=59)
            {

                strcpy(s.courses[i].grade,"D+");

            }
            else if(course_total>=50 && course_total<=54)
            {
                strcpy(s.courses[i].grade,"D-");

            }
            else if(course_total>=0 && course_total<=50)
            {

                strcpy(s.courses[i].grade,"F");
            }
            total += course_total;

        }

        float per=0.0;
        per=total/175;
        s.gpa=per;
        for (int i = 0; i < 7; i++)
        {
            fprintf(fstd, "\n\tCourse: %s",s.courses[i].name);
            fprintf(fstd, "\n\tCredit hours for course %s: %d", s.courses[i].name, s.courses[i].credit_hours);
            fprintf(fstd, "\n\tGrade for course %s: %s",s.courses[i].name, s.courses[i].grade);
                       fprintf(fstd,"\n\n");
        }
        printf("GPA: %f",s.gpa);

        fprintf(fstd, "\n\n\t\t\tGPA of the student: %.2f", s.gpa);
        fclose(fstd);
    }
    else if(strcmp(regist,"200015200")==0)
    {
        FILE *fstd = fopen("200015200.txt", "w+");
        if(fstd == NULL)
        {
            printf("Cannot open the file\n");
            return;
        }
        strcpy(s.name, "Khaled Mohammed");
        fprintf(fstd,"Name: %s\n", s.name);
        /////////
        strcpy(s.courses[0].name, "Calculus II");
        strcpy(s.courses[0].c_course, "BA102");
        s.courses[0].credit_hours = 3;
        s.courses[0].attend = 6.7;


/////
        strcpy(s.courses[1].name, "Introduction to Problem Solving and Programming");
        strcpy(s.courses[1].c_course, "CS143");
        s.courses[1].credit_hours = 3;
        s.courses[1].attend = 3.3;



        strcpy(s.courses[2].name, "Advanced Physics");
        strcpy(s.courses[2].c_course, "BA216");
        s.courses[2].credit_hours = 3;
        s.courses[2].attend = 0;



        strcpy(s.courses[3].name, "Fundamentals of Electronics");
        strcpy(s.courses[3].c_course, "EC134");
        s.courses[3].credit_hours = 3;
        s.courses[3].attend = 0;



        strcpy(s.courses[4].name, "Discrete Structures");
        strcpy(s.courses[4].c_course, "CS202");
        s.courses[4].credit_hours = 3;
        s.courses[4].attend = 0;
        strcpy(s.courses[4].grade,"B");


        strcpy(s.courses[5].name, "English for Specific Purposes II (ESP II)");
        strcpy(s.courses[5].c_course, "LH136");
        s.courses[5].credit_hours = 2;
        s.courses[5].attend = 0;



        strcpy(s.courses[6].name, "Communication Skills");
        strcpy(s.courses[6].c_course, "NC133");
        s.courses[6].credit_hours = 2;
        s.courses[6].attend = 0;

        for (int i = 0; i < 7; i++)
        {
            pf("Course: %s\n",s.courses[i].name);
            pf("Code: %s\n",s.courses[i].c_course);
            pf("Credit Hour: %d\n",s.courses[i].credit_hours);

r6:
            printf("\n\n\t\t\t\t\t\t\tEnter the grade for week 7 of course %d: ", i + 1);
            scanf("%d", &week7);
            if(week7>30)
            {
                printf("\n\n\t\t\tShould be lessthan or equal 30\n");
                goto r6;
            }
r7:
            printf("\n\n\t\t\t\t\t\t\tEnter the grade for week 12 of course %d: ", i + 1);
            scanf("%d", &week12);
            if(week12>20)
            {
                printf("\n\n\t\t\tShould be lessthan or equal 20\n");
                goto r7;
            }
l4:
            printf("\n\n\t\t\t\t\tThe year work degree should be between 0 and 10");
            printf("\n\n\t\t\t\t\tEnter the grade for year work of course %d: ", i + 1);
            scanf("%d", &year_work);
            if(year_work>10||year_work<0)
            {
                goto l4;
                printf("\n\n\t\t\t\t\tThe year work degree should be between 0 and 10");
            }

            printf("\n\n\t\t\t\t\t\t\tEnter the grade for final exam of course %d: ", i + 1);
            scanf("%d", &final_exam);

            int course_total = week7 + week12 + year_work + final_exam;
if (course_total>=90 && course_total<=100)
            {
                strcpy(s.courses[i].grade,"A+");

            }
            else if(course_total>=85 && course_total<=89)
            {
                strcpy(s.courses[i].grade,"A");
            }
            else if(course_total>=80 && course_total<=84)
            {

                strcpy(s.courses[i].grade,"B+");

            }
            else if(course_total>=75 && course_total<=79)
            {

                strcpy(s.courses[i].grade,"B");

            }
            else if(course_total>=70 && course_total<=74)
            {

                strcpy(s.courses[i].grade,"B-");

            }
            else if(course_total>=65 && course_total<=69)
            {

                strcpy(s.courses[i].grade,"C+");

            }
            else if(course_total>=60 && course_total<=64)
            {

                strcpy(s.courses[i].grade,"C");

            }
            else if(course_total>=55 && course_total<=59)
            {

                strcpy(s.courses[i].grade,"D+");

            }
            else if(course_total>=50 && course_total<=54)
            {
                strcpy(s.courses[i].grade,"D-");

            }
            else if(course_total>=0 && course_total<=50)
            {

                strcpy(s.courses[i].grade,"F");
            }
            total += course_total;
        }

        float per=0.0;
        per=total/175;



        for (int i = 0; i < 7; i++)
        {
            fprintf(fstd, "\n\tCourse: %s",s.courses[i].name);
            fprintf(fstd, "\n\tCredit hours for course %s: %d", s.courses[i].name, s.courses[i].credit_hours);
            fprintf(fstd, "\n\tGrade for course %s: %s",s.courses[i].name, s.courses[i].grade);
            fprintf(fstd,"\n\n");
        }
        s.gpa=per;
        printf("GPA: %.2f",s.gpa);

        fprintf(fstd, "\n\n\t\t\tGPA of the student: %.2f", s.gpa);
        fclose(fstd);

    }
    else
    {
        pf("\nIncorrect Registration Number\n\n");
        goto l;
    }
}

void lecturer()
{
    grades();
}
//=============================================================================================================================
void saved(Student s)
{
    printf("\n\n\t\t\t\t\t\t\t=============================\n");
    printf("\t\t\t\t\t\t\t Student\n");
    printf("\t\t\t\t\t\t\t=============================\n");

    printf("\n1. Attendance\n\n2. Grades\n");
    int choice;
    pf("\nChoice: ");
    scanf("%d", &choice);
    system("cls");
    printf("\nHello, %s\n", s.name);
    if(choice == 1)
    {
        for(int i = 0; i < 7; i++)
        {
            printf("\n\t\tCourse: %s\n", s.courses[i].name);
            printf("\t\tCourse code: %s\n", s.courses[i].c_course);
            printf("\t\tAttendance: %f\n", s.courses[i].attend);
            printf("\n\n\t\t\t\t\t\t\t=============================\n");
        }
    }
    else if(choice==2)
    {
        for(int i = 0; i < 7; i++)
        {
            printf("\n\t\tCourse: %s\n", s.courses[i].name);
            printf("\t\tCourse code: %s\n", s.courses[i].c_course);
            printf("\t\tAttendance: %s\n", s.courses[i].grade);
            printf("\n\n\t\t\t\t\t\t\t=============================\n");
        }
    }
}
void load_from_file(char id[], char pass[])
{
    Student s;

    if(strcmp(id, "221008774") == 0 && strcmp(pass, "531426") == 0)
    {



        FILE *fstd = fopen("221008774.txt", "w+");
        if(fstd == NULL)
        {
            printf("Cannot open the file\n");
            return;
        }
        strcpy(s.name, "Mohammed Khaled");
        fprintf(fstd,"Name: %s\n", s.name);
        strcpy(s.courses[0].name, "Calculus I");
        fprintf(fstd, "Course: %s\n", s.courses[0].name);
        strcpy(s.courses[0].c_course, "BA101");
        fprintf(fstd, "Code: %s\n", s.courses[0].c_course);
        s.courses[0].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[0].credit_hours);
        s.courses[0].attend = 6.7;
        fprintf(fstd, "Attendance: %f\n", s.courses[0].attend);
        strcpy(s.courses[0].grade,"A-");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[0].grade);

/////
        strcpy(s.courses[1].name, "Introduction to computing");
        fprintf(fstd, "Course: %s\n", s.courses[1].name);
        strcpy(s.courses[1].c_course, "CCS1101");
        fprintf(fstd, "Code: %s\n", s.courses[1].c_course);
        s.courses[1].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[1].credit_hours);
        s.courses[1].attend = 3.3;
        fprintf(fstd, "Attendance: %f\n", s.courses[1].attend);
        strcpy(s.courses[1].grade,"A");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[1].grade);


        strcpy(s.courses[2].name, "English for Specific Purposes I (ESP I)");
        fprintf(fstd, "Course: %s\n", s.courses[2].name);
        strcpy(s.courses[2].c_course, "LH135");
        fprintf(fstd, "Code: %s\n", s.courses[2].c_course);
        s.courses[2].credit_hours = 2;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[2].credit_hours);
        s.courses[2].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[2].attend);
        strcpy(s.courses[2].grade,"B-");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[2].grade);


        strcpy(s.courses[3].name, "Fundamentals of Business");
        fprintf(fstd, "Course: %s\n", s.courses[3].name);
        strcpy(s.courses[3].c_course, "NC172");
        fprintf(fstd, "Code: %s\n", s.courses[3].c_course);
        s.courses[3].credit_hours = 2;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[3].credit_hours);
        s.courses[3].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[3].attend);
        strcpy(s.courses[3].grade,"A");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[3].grade);


        strcpy(s.courses[4].name, "Creativity and innovation");
        fprintf(fstd, "Course: %s\n", s.courses[4].name);
        strcpy(s.courses[4].c_course, "CS111");
        fprintf(fstd, "Code: %s\n", s.courses[4].c_course);
        s.courses[4].credit_hours = 2;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[4].credit_hours);
        s.courses[4].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[4].attend);
        strcpy(s.courses[4].grade,"C");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[4].grade);


        strcpy(s.courses[5].name, "Introduction to Information Systems");
        fprintf(fstd, "Course: %s\n", s.courses[5].name);
        strcpy(s.courses[5].c_course, "IS171");
        fprintf(fstd, "Code: %s\n", s.courses[5].c_course);
        s.courses[5].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[5].credit_hours);
        s.courses[5].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[5].attend);
        strcpy(s.courses[5].grade,"D+");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[5].grade);


        strcpy(s.courses[6].name, "Physics");
        fprintf(fstd, "Course: %s\n", s.courses[6].name);
        strcpy(s.courses[6].c_course, "BA113");
        fprintf(fstd, "Code: %s\n", s.courses[6].c_course);
        s.courses[6].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[6].credit_hours);
        s.courses[6].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[6].attend);
        strcpy(s.courses[6].grade,"A");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[6].grade);


        fclose(fstd);
        saved(s);
    }

   else if(strcmp(id,"210086545")==0&&strcmp(pass, "111111") == 0)
    {
        FILE *fstd = fopen("210086545.txt", "w+");
        if(fstd == NULL)
        {
            printf("Cannot open the file\n");
            return;
        }
        strcpy(s.name, "Khaled Mohammed");
        fprintf(fstd,"Name: %s\n", s.name);
        /////////
        strcpy(s.courses[0].name, "Introduction to Networks");
        fprintf(fstd, "Course: %s\n", s.courses[0].name);
        strcpy(s.courses[0].c_course, "CE231");
        fprintf(fstd, "Code: %s\n", s.courses[0].c_course);
        s.courses[0].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[0].credit_hours);
        s.courses[0].attend = 6.7;
        fprintf(fstd, "Attendance: %f\n", s.courses[0].attend);
        strcpy(s.courses[0].grade,"A+");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[0].grade);

/////
        strcpy(s.courses[1].name, "Intro. to Computer Architecture");
        fprintf(fstd, "Course: %s\n", s.courses[1].name);
        strcpy(s.courses[1].c_course, "CE243");
        fprintf(fstd, "Code: %s\n", s.courses[1].c_course);
        s.courses[1].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[1].credit_hours);
        s.courses[1].attend = 3.3;
        fprintf(fstd, "Attendance: %f\n", s.courses[1].attend);
        strcpy(s.courses[1].grade,"B+");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[1].grade);


        strcpy(s.courses[2].name, "Professional Training in Entrepreneurship");
        fprintf(fstd, "Course: %s\n", s.courses[2].name);
        strcpy(s.courses[2].c_course, "IT291");
        fprintf(fstd, "Code: %s\n", s.courses[2].c_course);
        s.courses[2].credit_hours = 2;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[2].credit_hours);
        s.courses[2].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[2].attend);
        strcpy(s.courses[2].grade,"B");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[2].grade);


        strcpy(s.courses[3].name, "Data Structures and Algorithms");
        fprintf(fstd, "Course: %s\n", s.courses[3].name);
        strcpy(s.courses[3].c_course, "CS212");
        fprintf(fstd, "Code: %s\n", s.courses[3].c_course);
        s.courses[3].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[3].credit_hours);
        s.courses[3].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[3].attend);
        strcpy(s.courses[3].grade,"B-");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[3].grade);


        strcpy(s.courses[4].name, "Advanced Programming Applications");
        fprintf(fstd, "Course: %s\n", s.courses[4].name);
        strcpy(s.courses[4].c_course, "CS244");
        fprintf(fstd, "Code: %s\n", s.courses[4].c_course);
        s.courses[4].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[4].credit_hours);
        s.courses[4].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[4].attend);
        strcpy(s.courses[4].grade,"B");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[4].grade);


        strcpy(s.courses[5].name, "Database Systems");
        fprintf(fstd, "Course: %s\n", s.courses[5].name);
        strcpy(s.courses[5].c_course, "IS273");
        fprintf(fstd, "Code: %s\n", s.courses[5].c_course);
        s.courses[5].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[5].credit_hours);
        s.courses[5].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[5].attend);
        strcpy(s.courses[5].grade,"A-");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[5].grade);


        strcpy(s.courses[6].name, "Introduction to Software Engineering");
        fprintf(fstd, "Course: %s\n", s.courses[6].name);
        strcpy(s.courses[6].c_course, "SE291");
        fprintf(fstd, "Code: %s\n", s.courses[6].c_course);
        s.courses[6].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[6].credit_hours);
        s.courses[6].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[6].attend);
        strcpy(s.courses[6].grade,"A");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[6].grade);


        fclose(fstd);
        saved(s);
    }
    else if(strcmp(id,"210005465")==0&&strcmp(pass, "465798") == 0)
    {
        FILE *fstd = fopen("210005465.txt", "w+");
        if(fstd == NULL)
        {
            printf("Cannot open the file\n");
            return;
        }
        strcpy(s.name, "Salah Eldin Gamal");
        fprintf(fstd,"Name: %s\n", s.name);
        /////////
        strcpy(s.courses[0].name, "Advanced Statistics");
        fprintf(fstd, "Course: %s\n", s.courses[0].name);
        strcpy(s.courses[0].c_course, "BA301");
        fprintf(fstd, "Code: %s\n", s.courses[0].c_course);
        s.courses[0].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[0].credit_hours);
        s.courses[0].attend = 6.7;
        fprintf(fstd, "Attendance: %f\n", s.courses[0].attend);
        strcpy(s.courses[0].grade,"A+");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[0].grade);

/////
        strcpy(s.courses[1].name, "Linear Algebra");
        fprintf(fstd, "Course: %s\n", s.courses[1].name);
        strcpy(s.courses[1].c_course, "BA304");
        fprintf(fstd, "Code: %s\n", s.courses[1].c_course);
        s.courses[1].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[1].credit_hours);
        s.courses[1].attend = 3.3;
        fprintf(fstd, "Attendance: %f\n", s.courses[1].attend);
        strcpy(s.courses[1].grade,"B+");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[1].grade);


        strcpy(s.courses[2].name, "Theory of Computation");
        fprintf(fstd, "Course: %s\n", s.courses[2].name);
        strcpy(s.courses[2].c_course, "CS311");
        fprintf(fstd, "Code: %s\n", s.courses[2].c_course);
        s.courses[2].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[2].credit_hours);
        s.courses[2].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[2].attend);
        strcpy(s.courses[2].grade,"B");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[2].grade);


        strcpy(s.courses[3].name, "Systems Programming");
        fprintf(fstd, "Course: %s\n", s.courses[3].name);
        strcpy(s.courses[3].c_course, "CS321");
        fprintf(fstd, "Code: %s\n", s.courses[3].c_course);
        s.courses[3].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[3].credit_hours);
        s.courses[3].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[3].attend);
        strcpy(s.courses[3].grade,"B-");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[3].grade);


        strcpy(s.courses[4].name, "Web Programming");
        fprintf(fstd, "Course: %s\n", s.courses[4].name);
        strcpy(s.courses[4].c_course, "CS333");
        fprintf(fstd, "Code: %s\n", s.courses[4].c_course);
        s.courses[4].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[4].credit_hours);
        s.courses[4].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[4].attend);
        strcpy(s.courses[4].grade,"B");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[4].grade);


        strcpy(s.courses[5].name, "Computer Graphics");
        fprintf(fstd, "Course: %s\n", s.courses[5].name);
        strcpy(s.courses[5].c_course, "CS352");
        fprintf(fstd, "Code: %s\n", s.courses[5].c_course);
        s.courses[5].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[5].credit_hours);
        s.courses[5].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[5].attend);
        strcpy(s.courses[5].grade,"A-");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[5].grade);


        strcpy(s.courses[6].name, "Professional Training in Programming I (.Net 1)");
        fprintf(fstd, "Course: %s\n", s.courses[6].name);
        strcpy(s.courses[6].c_course, "IT321");
        fprintf(fstd, "Code: %s\n", s.courses[6].c_course);
        s.courses[6].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[6].credit_hours);
        s.courses[6].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[6].attend);
        strcpy(s.courses[6].grade,"A");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[6].grade);


        fclose(fstd);
        saved(s);
    }

    else if(strcmp(id,"200015200")==0&&strcmp(pass, "152097") == 0)
    {
        FILE *fstd = fopen("200015200.txt", "w+");
        if(fstd == NULL)
        {
            printf("Cannot open the file\n");
            return;
        }
        strcpy(s.name, "Khaled Mohammed");
        fprintf(fstd,"Name: %s\n", s.name);
        /////////
        strcpy(s.courses[0].name, "Calculus II");
        fprintf(fstd, "Course: %s\n", s.courses[0].name);
        strcpy(s.courses[0].c_course, "BA102");
        fprintf(fstd, "Code: %s\n", s.courses[0].c_course);
        s.courses[0].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[0].credit_hours);
        s.courses[0].attend = 6.7;
        fprintf(fstd, "Attendance: %f\n", s.courses[0].attend);
        strcpy(s.courses[0].grade,"A+");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[0].grade);

/////
        strcpy(s.courses[1].name, "Introduction to Problem Solving and Programming");
        fprintf(fstd, "Course: %s\n", s.courses[1].name);
        strcpy(s.courses[1].c_course, "CS143");
        fprintf(fstd, "Code: %s\n", s.courses[1].c_course);
        s.courses[1].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[1].credit_hours);
        s.courses[1].attend = 3.3;
        fprintf(fstd, "Attendance: %f\n", s.courses[1].attend);
        strcpy(s.courses[1].grade,"B+");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[1].grade);


        strcpy(s.courses[2].name, "Advanced Physics");
        fprintf(fstd, "Course: %s\n", s.courses[2].name);
        strcpy(s.courses[2].c_course, "BA216");
        fprintf(fstd, "Code: %s\n", s.courses[2].c_course);
        s.courses[2].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[2].credit_hours);
        s.courses[2].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[2].attend);
        strcpy(s.courses[2].grade,"B");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[2].grade);


        strcpy(s.courses[3].name, "Fundamentals of Electronics");
        fprintf(fstd, "Course: %s\n", s.courses[3].name);
        strcpy(s.courses[3].c_course, "EC134");
        fprintf(fstd, "Code: %s\n", s.courses[3].c_course);
        s.courses[3].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[3].credit_hours);
        s.courses[3].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[3].attend);
        strcpy(s.courses[3].grade,"A-");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[3].grade);


        strcpy(s.courses[4].name, "Discrete Structures");
        fprintf(fstd, "Course: %s\n", s.courses[4].name);
        strcpy(s.courses[4].c_course, "CS202");
        fprintf(fstd, "Code: %s\n", s.courses[4].c_course);
        s.courses[4].credit_hours = 3;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[4].credit_hours);
        s.courses[4].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[4].attend);
        strcpy(s.courses[4].grade,"F");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[4].grade);


        strcpy(s.courses[5].name, "English for Specific Purposes II (ESP II)");
        fprintf(fstd, "Course: %s\n", s.courses[5].name);
        strcpy(s.courses[5].c_course, "LH136");
        fprintf(fstd, "Code: %s\n", s.courses[5].c_course);
        s.courses[5].credit_hours = 2;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[5].credit_hours);
        s.courses[5].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[5].attend);
        strcpy(s.courses[5].grade,"C-");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[5].grade);


        strcpy(s.courses[6].name, "Communication Skills");
        fprintf(fstd, "Course: %s\n", s.courses[6].name);
        strcpy(s.courses[6].c_course, "NC133");
        fprintf(fstd, "Code: %s\n", s.courses[6].c_course);
        s.courses[6].credit_hours = 2;
        fprintf(fstd, "Credit Hours: %d\n", s.courses[6].credit_hours);
        s.courses[6].attend = 0;
        fprintf(fstd, "Attendance: %f\n", s.courses[6].attend);
        strcpy(s.courses[6].grade,"D");
        fprintf(fstd,"Grade: %s\n\n\n",s.courses[6].grade);


        fclose(fstd);
        saved(s);
    }

    else
    {
        printf("\n\n\t\t\t\t\t=============================\n");
        pf("\t\t\t\tIncorrect Registeraion number or Password\n\n");
        printf("\n\n\t\t\t\t\t=============================\n");
    }
}
//==============================================================================================================================
void menu()
{
    int choice;

    while (1)
    {
        printf("\n\n\t\t\t\t\t\t\t\t=============================\n");
        printf("\t\t\t\t\t\t\t\t\t Welcome to AAST's page\n");
        printf("\t\t\t\t\t\t\t\t=============================\n");
        printf("1. Login\n");
        printf("2. Online registration\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice==1)
        {
            int role_choice;
            printf("\n\n\t\t\t\t\t\t\t\t=============================\n");
            printf("\t\t\t\t\t\t\t\t\t LOGIN MENU\n");
            printf("\t\t\t\t\t\t\t\t=============================\n");
            printf("1. Lecturer\n");
            printf("2. Teacher assistant\n");
            printf("3. Student\n");
            printf("\nEnter your role: ");
            scanf("%d", &role_choice);

            if(role_choice==1)
            {
                    system("cls");
                lecturer();
            }
            else if(role_choice==2)
            {
                    system("cls");
                teacher_assis();
            }

            else if(role_choice==3)
            {
                char id[20], pass[20];
                    system("cls");
                printf("\nEnter your Registration number: ");
                scanf("%s", id);
                printf("\nEnter your Password: ");
                scanf("%s", pass);
                load_from_file(id, pass);
            }
            else
            {
                printf("\n\nInvalid input. Please try again.\n\n");
            }
        }

        else if(choice==2)
        {
                system("cls");
            online_registration();
            printf("\n\nThank you!\n\n");
        }
        else if(choice==3)
        {
            printf("\n\nExiting program...\n\n");
            exit(0);
        }
        else
            printf("\n\nInvalid input. Please try again.\n\n");
    }
}
//==============================================================================================================================
int main()
{
    menu();
    return 0;
}
