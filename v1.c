#include <stdio.h>
#include <stdlib.h>

int num_student=0;

typedef struct stuent{
    char name[15];
    char lname[15];
    int id;
    float notes[4];//store markes of the 4 modules
    float total_notes;
}student;

int is_id_exist(student* p, int id){
    int indice=0;
    for(int i=0; i<num_student;i++){
        if((p+i)->id==id){
            return 1;
            indice = 1;
        }
    }
    if(!indice){
        return 0;
    }
}

float note_calcule(int i, student* p){// take 4 markes of the 4 modules and return the total
    float a = 0;float temp=0;
    for(int j=0; j<4; j++){
        do{
            printf("Donner la %d eme note: ",(j+1));
            scanf("%f",&temp);
        } while (temp<0 || temp>20);
        (p+i)->notes[j]=temp;
        a+=temp;
    }
    a/=4;
    return a;
}
void uppercase_name(char *name){
    for(;*name;++name){
        if(*name >= 'a' && *name <= 'z') *name = *name + ('A'-'a');//for making the name and laste name upper(avoid case problems)
    }
}
void add_student(student* p, int n){
    char exit[] = "EXIT";
    int index;int i=0;
    for(i=num_student; i<200; i++){
        printf("Donner le prenom de l'eleve: ");
        scanf("%s",(p+i)->name);
        if(*(p+i)->name =='0')break;
        uppercase_name((p+i)->name);
        printf("Donner le nom de l'eleve: ");
        scanf("%s",(p+i)->lname);
        if(*(p+i)->lname =='0')break;
        uppercase_name((p+i)->lname);
        printf("Donner l'identifiant de l'eleve: ");
        scanf("%d",&((p+i)->id));
        while(is_id_exist(p, (p+i)->id)){
        printf("cette id est déja existe donner une autre id:");//id already taken
        scanf("%d",&((p+i)->id));
        }
        num_student++;
        (p+i)->total_notes=note_calcule(i, p);
        if(n==1){break;} // if we want to add one student only
    }
}
void show_all_student(student *p ,int index){
    if (index==0){
        printf("le nombres des etudiant  %d \n",num_student);
        for(int j=0; j<num_student;j++){
            printf("%-15s |  %-15s\n", ((p+j)->name), ((p+j)->lname));
        }
    }
    else{
        for(int j=0; j<num_student;j++){
            printf(" \n|%03d |%-15s| %-15s|N1: %02.2f|N2: %02.2f|N3: %02.2f|N4: %02.2f|NT: %02.2f|\n", ((p+j)->id), ((p+j)->name), ((p+j)->lname),((p+j)->notes[0]),((p+j)->notes[1]),((p+j)->notes[2]),((p+j)->notes[3]), ((p+j)->total_notes));
        }
    }
}
void search_student(student *p, int x){
    char name[10], lname[10];int exist=1; 
    int nindex = 0;
    if (x == 0){
        printf("Donner le prenom ");
        scanf("%s", name);
        uppercase_name(name);
        for(int i=0;i<num_student;i++){
            for(int j=0;name[j]!='\0';j++){
                    if(name[j] != (p+i)->name[j]){
                        nindex=1;
                    }
            }
            if(nindex!=1){
            printf(" \n|%03d |%-15s| %-15s|N1: %02.2f|N2: %02.2f|N3: %02.2f|N4: %02.2f|NT: %02.2f|\n", ((p+i)->id), ((p+i)->name), ((p+i)->lname),((p+i)->notes[0]),((p+i)->notes[1]),((p+i)->notes[2]),((p+i)->notes[3]), ((p+i)->total_notes));exist=0;}
        }
    }
    if (x == 1){
        printf("Donner le nom");
        scanf("%s", lname);
        uppercase_name(lname);
        for(int i=0;i<num_student;i++){
            for(int j=0;lname[j]!='\0';j++){
                    if(lname[j] != (p+i)->lname[j]){
                        nindex=1;
                    }
            }
            if(nindex!=1){
                printf(" \n|%03d |%-15s| %-15s|N1: %02.2f|N2: %02.2f|N3: %02.2f|N4: %02.2f|NT: %02.2f|\n", ((p+i)->id), ((p+i)->name), ((p+i)->lname),((p+i)->notes[0]),((p+i)->notes[1]),((p+i)->notes[2]),((p+i)->notes[3]), ((p+i)->total_notes));exist=0;            
                }
        }
    }
    if(x == 2){
        int id;
        printf("donner le id :");
        scanf("%d",&id);
        for(int i=0; i<num_student;i++){
            if(id == (p+i)->id){
                printf(" \n|%03d |%-15s| %-15s|N1: %02.2f|N2: %02.2f|N3: %02.2f|N4: %02.2f|NT: %02.2f|\n", ((p+i)->id), ((p+i)->name), ((p+i)->lname),((p+i)->notes[0]),((p+i)->notes[1]),((p+i)->notes[2]),((p+i)->notes[3]), ((p+i)->total_notes));exist=0;
            }
        }
    }
    if(exist)printf("Pas d'etudiant avec cette informations");
}
void sort_student(student *p){
    student temp;
    for(int i=0; i<num_student; i++){
        for(int j=i+1; j<num_student; j++){
            if((p+i)->total_notes < (p+j)->total_notes){
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    }
}

void modify(student* p){
    int id;int i;int indice;
    student* temp;
    printf("Donner l'id de l'eleve: ");
    scanf("%d", &id);
    for(i=0; i<num_student;i++){
        if(id == (p+i)->id){
        printf("Donner le prenom de l'eleve: ");
        scanf("%s",(p+i)->name);
        if(*(p+i)->name =='0')break;
        uppercase_name((p+i)->name);
        printf("Donner le nom de l'eleve: ");
        scanf("%s",(p+i)->lname);
        if(*(p+i)->name =='0')break;
        uppercase_name((p+i)->lname);
        printf("Donner l'identifiant de l'eleve: ");
        scanf("%d",&((p+i)->id));
        while(is_id_exist(p, (p+i)->id)){
        printf("Cette id est déja existe donner une autre id:");
        scanf("%d",&((p+i)->id));
        }
        (p+i)->total_notes=note_calcule(i, p);
        }
    }
}

int main(){
    student s_list[200]; // table of 200 student 
    int choice;
    do{
        printf("\n1) Ajouter plusieurs étudiants \n");
        printf("2) Ajouter un seule étudiant\n");
        printf("3) Afficher tout les étudiants\n");
        printf("4) Afficher toutes les informations de tous les étudiants\n");
        printf("5) Rechercher par prenom\n");
        printf("6) Rechercher par nom de famille\n");
        printf("7) Rechercher par identifiant\n");
        printf("8) Trier tous les étudiants\n");
        printf("9) Modifier les informations d'un étudiant");
        printf("0) EXIT\n");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Pour sortir, entrez 0 dans l'identifiant ou dans le nom \n");
                add_student(s_list, 0);
                break;
            case 2:{
                add_student(s_list,1);
                break;}
            case 3:{
                show_all_student(s_list, 0);
                break;}
            case 4:{
                show_all_student(s_list, 1);
                system("pause");
                break;}
            case 5:{
                search_student(s_list, 0);
                break;
            }
            case 6:{
                search_student(s_list, 1);
                break;
            }
            case 7:{
                search_student(s_list, 2);
                break;
            }
            case 8:{
                sort_student(s_list);
                show_all_student(s_list, 0);
                break;
            }
            case 9:{
                modify(s_list);
                break;
            }
        }
        }while(choice!=0);
return 0;
}