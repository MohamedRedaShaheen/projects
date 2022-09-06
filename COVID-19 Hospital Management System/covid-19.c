#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char p_name[30];
    int p_age;
    char p_address[30];
    char p_date[13];
    int hospital_id;
    int ID;

}central;
void Main_menu(central *hospital);
void Store(central *hospital);
void Print(central *hospital);
void Assign(central *hospital);
void Delete(central *hospital);
int hos=0;
int is_exist;
int is_deleted;
long size=0;
int is_data_entered;

int main()
{

    int password=1234;
    int tries=3;
    int enter;
    central *hospital =malloc(sizeof(central)*2);
    while(1){
    printf("Enter Password: ");
    scanf("%d",&enter);

    if(enter==password){ //password check

       Main_menu(hospital);

    }else{
        tries-=1;
        if(tries!=0){//tries left check
            puts("Wrong password,Try again");
        }else{
            puts("Access Denied");
            break;
        }
    }
    }

    return 0;

}
//******************************Main_menu****************************************
void Main_menu(central *hospital){
    int choice;
    puts("\n\n1-Store Patient Data\n\n2-Assign ID\n\n3-Print Patient Data\n\n4-Delete Patient Data\n\n5-Exit\n\n");
    printf("Chose: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            Store(hospital);
            puts("\n");
        case 2:
           Assign(hospital);
            puts("\n");
        case 3:
          Print(hospital);
            puts("\n");
        case 4:
           Delete(hospital);
            puts("\n");
        case 5:
            exit(0);

        }


}
//****************************Store ******************************

void Store(central *hospital){
    int i=0;
    is_exist=0;
    is_data_entered=0;
    char p_name[30];
    printf("\n Enter p_name: ");
    fflush(stdin);
    gets(p_name);
    fflush(stdin);
     while(i<=size){
        if(strcmp(p_name,(hospital+i)->p_name)==0){//check if the p_name already exists
        puts("\n\n\tPatient exists\n");
        is_exist=1;
        break;

        }else{
            i+=1;
        }
    }
    if(is_exist==0){
            strcpy((hospital+size)->p_name,p_name);
            printf("\n Enter p_age: ");
            scanf("%d",&(hospital+size)->p_age);
            printf("\n Enter p_date OF Infection: ");
            fflush(stdin);
            gets((hospital+size)->p_date);
            fflush(stdin);
            printf("\n Enter p_address: ");
            fflush(stdin);
            gets((hospital+size)->p_address);
            fflush(stdin);
            size+=1;
            hospital = realloc(hospital,sizeof(central)*(size+1));//reallocating the memory
            is_data_entered=1;
    }

Main_menu(hospital);
}

//***********************************Print ***********************************
void Print(central *hospital){
    int x=0;
    int hospital_id=0;
    is_exist=0;
    int id=0;
    printf("\nEnter Hospital ID: ");
    scanf("%d",&hospital_id);
    printf("\nEnter Patient Code: ");
    scanf("%d",&id);
    while(x<size){
        if(hospital[x].ID == id && hospital[x].hospital_id == hospital_id){
            printf("\n\tp_name: %s\n\n",hospital[x].p_name);
            printf("\tp_age: %d\n\n",hospital[x].p_age);
            printf("\tp_address: %s\n\n",hospital[x].p_address);
            printf("\tp_date of infection: %s\n\n",hospital[x].p_date);
            printf("\tHospital: %d\n\n\tPatient Code: %d\n\n",hospital[x].hospital_id,hospital[x].ID);
            is_exist=1;
            break;
        }else{
            x+=1;
        }
    }
    if(is_exist==0){
        puts("\n\tID Not Found\n");
    }
Main_menu(hospital);
}
//************************************Assign Id ****************************
void Assign(central *hospital){
    static int id=1;
    if(is_data_entered==1){
     if(id==50){
        hos+=1;
        id=1;
    }
    hospital[size-1].hospital_id=hos;
    hospital[size-1].ID=id;
    printf("\nHospital ID: %d\n\n",hos);
    printf("Patient Code: %d\n\n",id);
    id+=1;
 }else{
    puts("\n\t You didn't enter data\n");
 }
 is_data_entered=0;
 Main_menu(hospital);
}
//***************************************Delete****************************
void Delete(central *hospital){
    int x=0;
    is_deleted=0;
    int id=0;
    int hospital_id=0;
    printf("\nEnter Hospital ID: ");
    scanf("%d",&hospital_id);
    printf("\nEnter Patient Code: ");
    scanf("%d",&id);
    while(x<size){
        if(hospital[x].ID == id && hospital[x].hospital_id == hospital_id){
            strcpy(hospital[x].p_name,"");
            strcpy(hospital[x].p_address,"");
            strcpy(hospital[x].p_date,"");
            hospital[x].p_age=0;
            hospital[x].ID=0;
            hospital[x].hospital_id=0;
            is_deleted=1;
            break;

        }else{
            x+=1;
        }

    }
    if(is_deleted==1){
        free(hospital+x);
        puts("\n\tPatient Data deleted\n");
    }else{
        puts("\n\tID Not Found\n");
    }
    Main_menu(hospital);
}

