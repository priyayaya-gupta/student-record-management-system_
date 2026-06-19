#include<stdio.h>
#include<stdlib.h>
struct student{
    int id;
    char name[100];
    float marks;
};

void addstudent(){
    struct student s;
    struct student temp;
FILE *fp;
fp = fopen("student.dat", "ab+");
if(fp == NULL){
        printf("File error!\n");
        return;
    }
printf("enter student id: \n");
scanf("%d" , &s.id);

rewind(fp);
while(fread(&temp , sizeof(temp) , 1 , fp)){
    if(s.id == temp.id){
        printf("ID already exists! please try again! \n");
        fclose(fp);
        return;
    }
}


printf("enter student's name: \n");
scanf("%s" , s.name);
printf("enter student's marks: \n");
scanf("%f" , &s.marks);

fwrite(&s , sizeof(s) , 1 , fp);
fclose(fp);

printf("Student added! \n");
}

void displaystudents(){
    FILE *fp;
    struct student s;
    fp= fopen("student.dat" , "rb");
    if(fp == NULL){
        printf("File error!\n");
        return;
    }
    printf("--students' records-- \n");
    while(fread(&s , sizeof(s) , 1 , fp)){
        printf("ID: %d |" , s.id);
        printf("Name: %s |" , s.name);
        printf("Marks: %f |" , s.marks);
        printf("\n");

    }
    fclose(fp);
    }
    


    
void searchstudent(){
    FILE *fp;
    struct student s;
    fp = fopen("student.dat" , "rb");
    int id;
    printf("enter id to search :  ");
    scanf("%d" , &id);
    if(fp == NULL){
        printf("File error!\n");
        return;
    }
    while(fread(&s , sizeof(s) , 1 , fp)){
        if(s.id==id){
            printf("FOUND: \n");
            printf("ID: %d |, Name: %s |, marks: %f | \n" , s.id , s.name , s.marks);
            fclose(fp);
            return;
        }

        }
        printf("Student Not Found! \n");
        fclose(fp);
    }
    void updatestudent(){
    struct student s;
    int id;
    int found=0;
    FILE *fp;
    FILE *temp;
    fp = fopen("student.dat" , "rb");
    temp = fopen("temp.dat" , "wb");
    if(fp == NULL){
        printf("File error! \n");
        return;
    }
    printf("enter the student's ID you want to update: \n");
    scanf("%d" , &id);

    while(fread(&s , sizeof(s) ,1,fp)){
        if(id==s.id){
            printf("Enter new name: \n");
            scanf("%s" , s.name);
            printf("Enter new Marks: \n");
            scanf("%f" , &s.marks);
            found = 1;
            
    }
    fwrite(&s , sizeof(s) , 1, temp);
}
fclose(fp);
fclose(temp);
remove("student.dat");
rename("temp.dat" , "student.dat");

if(found){
    printf("student details updated! \n");
}
else{
    printf("record not found \n");
}
}

    void deletestudent(){
        FILE *fp , *temp;
        int id;
        int found = 0;
        struct student s;
        fp = fopen("student.dat" , "rb");
        temp = fopen("temp.dat" , "wb");
        if(fp == NULL){
        printf("File error!\n");
        return;
    }
        printf("Enter the student id you want to delete:  \n");
        scanf("%d" , &id);
        while (fread(&s , sizeof(s) , 1, fp)){
            if(s.id!=id){
                fwrite(&s , sizeof(s) , 1 , temp);
            }
            else{
                found = 1;
            }
        }
        fclose(fp);
        fclose(temp);
        remove("student.dat");
        rename("temp.dat" , "student.dat");
        
        if (found){
            printf("Student deleted");
        }
        else{
            printf("Student not found.");
        }
        
        }


int main(){
    int choice;
    while (1){
        printf(" ***MENU*** \n");
        printf("1. Add student \n");
        printf("2. search student \n");
        printf("3. Update Details \n");
        printf("4. delete student \n");
        printf("5. Display all the records \n");
        printf("6. Exit \n");
        printf("Enter your choice: \n");
        scanf("%d" , &choice);
        switch(choice){
            case 1 : addstudent(); break;
            case 2 : searchstudent(); break;
            case 3 : updatestudent() ; break;
            case 4 : deletestudent(); break;
            case 5 : displaystudents(); break;
            case 6: exit(0);
            default: printf("Invalid choice! \n");

        }
    }

    return 0;
}