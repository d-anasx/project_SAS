#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ESC "\033["

#define HEADER ESC "38;5;51m"
#define NUMBER ESC "38;5;201m"
#define GOLD ESC "38;5;220m"
#define GREEN ESC "38;5;82m"
#define TURQUOISE ESC "38;5;45m"
#define QUIT_NUMBER ESC "38;5;196m"
#define QUIT_TEXT ESC "38;5;51m"
#define PROMPT ESC "38;5;201m"
#define RESET ESC "0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    int idAvion ;
    char modele[30] ;
    int capacite ;
    char statut[30] ;
    Date Av_date;
} Avion ;



typedef struct {
    char nom[30];
    int nbAvions;
    Avion avions[200];

} Aeroport ;

Aeroport a ;

int id = 4;
int maxC = 500;


//functions

    int ValidateInt(char prompt[])
{
    int number;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &number) == 1){
            if (number >= 0 && number <= maxC){
                break;
            }
        }
            
        while (getchar() != '\n')
            ;
        printf("%sentrer un nombre valid !!%s\n",RED,RESET);
    }
    return number;
}

    void ajouterAvion(){
        int n;
        char input[30];
        printf("combien d avions voulez vous entrer : ");
        scanf("%d" , &n);

        
        for(int i = 0 ; i < n ; i++){
            printf("----------------------------------------------------------\n\n");
            printf("entrer le modele de l avion %d: ",i + 1);
            scanf(" %[^\n]" , a.avions[a.nbAvions].modele);

            
            a.avions[a.nbAvions].capacite = ValidateInt("entrer la capacite de l avion : ");
            
            do{
                printf("entrer le statut de l avion : ");
                
                scanf(" %[^\n]" , input);
            }
            while( strcmp(input ,"disponible")!=0  && strcmp(input ,"en vol")!=0 && strcmp(input ,"en maintenance")!=0);

            strcpy(a.avions[a.nbAvions].statut ,input);

            //****** entree de la date ******* */
            printf("Entrer la date (jj mm aaaa) : ");
            scanf("%d %d %d", &a.avions[a.nbAvions].Av_date.jour, &a.avions[a.nbAvions].Av_date.mois, &a.avions[a.nbAvions].Av_date.annee);
            //******************************* */

            a.avions[a.nbAvions].idAvion =  id++;
            a.nbAvions++;

            
            
        }
        
        

        

    }

    void afficherAvions() {
    printf("\n------Liste des avions dans l'aeroport%s------\n", a.nom);
    printf("ID | Modele | Capacite | Statut | Date\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < a.nbAvions; i++) {
        printf("%d | %s | %d | %s | %d/%d/%d\n",
            a.avions[i].idAvion,
            a.avions[i].modele,
            a.avions[i].capacite,
            a.avions[i].statut,
            a.avions[i].Av_date.jour,
            a.avions[i].Av_date.mois,
            a.avions[i].Av_date.annee);
    }
}


    void afficherAeroport(){
        printf("\nInformations sur l'aeroport\n");
        printf("Nom: %s\n", a.nom);
        printf("Nombre total d'avions: %d\n", a.nbAvions);
    }



    void modifierAvion(){
    int av_id;
    char input[30];
    printf("donner l'id de l'avion : ");
    scanf("%d", &av_id);

    int found = 0;
    for (int i = 0; i < a.nbAvions; i++) {
        if (a.avions[i].idAvion == av_id) {
            printf("entrer le modele de l avion : ");
            scanf(" %[^\n]" , a.avions[i].modele);

            printf("entrer la capacite de l avion : ");
            scanf("%d" , &a.avions[i].capacite);
                
            do {
                printf("entrer le statut de l avion : ");
                scanf(" %[^\n]" , input);
            } while (strcmp(input ,"disponible")!=0 && strcmp(input ,"en vol")!=0 && strcmp(input ,"en maintenance")!=0);

            strcpy(a.avions[i].statut ,input);    
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("%sAucun avion avec l id %d%s\n",RED, av_id, RESET);
    }
}


    void supprimerAvion(){
        int av_id;
        printf("donner l id de l avion : ");
        scanf("%d", &av_id);
        int found = 0 ;

        for(int i=0 ; i<a.nbAvions ; i++){
            if(a.avions[i].idAvion == av_id){
                for(int j=i ; j < a.nbAvions - 1 ; j++){
                a.avions[j] = a.avions[j + 1];
        }
            a.nbAvions--;
            found = 1;
            printf("%sAvion avec id %d supprime avec succes%s\n",GREEN, av_id,RESET);
            break;
            }
        }
        if(!found) printf("%sAucun avion avec l id %d%s\n",RED, av_id,RESET);



        
    }

    

    void rechercherAvionById(){
        int found = 0;
        int av_id;
        printf("donner l id de l avion : ");
        scanf("%d", &av_id) ;

        for (int i = 0; i < a.nbAvions; i++){

            if (a.avions[i].idAvion == av_id)
            {
                found = 1;
                printf("%s  |  %d  |  %s\n",
                                a.avions[i].modele,
                                a.avions[i].capacite,
                                a.avions[i].statut);

        }
    }
    if(!found) printf("Aucune avion trouve avec cet id\n");
            
        
    }

    void rechercherAvionByModel(){

        char av_modele[30];
        printf("donner le modele de l avion : ");
        scanf(" %[^\n]", av_modele) ;
        int found = 0;

        
        for (int i = 0; i < a.nbAvions; i++){

            if (stricmp(a.avions[i].modele,av_modele) == 0)
            {
                found = 1;
                printf("%s  |  %d  |  %s\n",
                                a.avions[i].modele,
                                a.avions[i].capacite,
                                a.avions[i].statut);

        }
    }
    if(!found) printf("Aucune avion trouve avec ce modele.\n");
}

    void triParCapacite(){

    for(int i=0 ; i<a.nbAvions-1 ; i++ ){
        for(int j = 0 ; j<a.nbAvions-1 ; j++){

            if(a.avions[j].capacite > a.avions[j+1].capacite ){
            Avion temp = a.avions[j];
            a.avions[j] = a.avions[j+1];
            a.avions[j+1] = temp;
        }
        }
        
    }
    

    }


    void triParModele(){

    for(int i=0 ; i<a.nbAvions-1 ; i++ ){
        for(int j = 0 ; j<a.nbAvions-1 ; j++){

            if(stricmp(a.avions[j].modele , a.avions[j+1].modele) > 0){

            Avion temp = a.avions[j];
            a.avions[j] = a.avions[j+1];
            a.avions[j+1] = temp;
        }
        }
        
    }
    afficherAvions();

    }

    int TotalEnParc(){
        int count = 0;
        for(int i = 0 ; i < a.nbAvions ; i++){

            if (stricmp(a.avions[i].statut,"disponible") == 0) count++;
           
        }
        
        return count ;
    }

    void TotalParStatut(){
        int Dispo_count = 0;
        int vol_count = 0;
        int maint_count = 0;

        for(int i = 0 ; i < a.nbAvions ; i++){

             (stricmp(a.avions[i].statut,"disponible") == 0)
             ? Dispo_count++
             : (stricmp(a.avions[i].statut,"en vol") == 0)
             ? vol_count++
             : maint_count++;
        }
        printf("le total des avions disponibles est : %d\n",Dispo_count);
        printf("le total des avions en vol est : %d\n",vol_count);
        printf("le total des avions en maintenance est : %d\n",maint_count);
    }

    void CapaciteTotal(){
        int count = 0;
        for(int i = 0 ; i < a.nbAvions ; i++){

            count+=a.avions[i].capacite;
           
        }
        printf("le total des capacites est : %d",count);
    
    }

    void MaxMinCapacite(){

         triParCapacite();
         printf("avion ayant la plus petite capacite : ~ %s  |  %d  |  %s ~\n",
                                a.avions[0].modele,
                                a.avions[0].capacite,
                                a.avions[0].statut);

        printf("avion ayant la plus grande capacite : ~ %s  |  %d  |  %s ~\n",
                                a.avions[a.nbAvions-1].modele,
                                a.avions[a.nbAvions-1].capacite,
                                a.avions[a.nbAvions-1].statut);

    }

    void averageAvionsDispo(){
    
        float average = (TotalEnParc() * 100  ) / a.nbAvions ;
        float coef = average / 100;
         printf("pourcentage d avions disponibles est : %.0f%%\n" , average);
         printf("le coefficient est : %.2f" , coef);
    }

    

    

    void statistique(){
        int c;

            do{
                printf("\n" BLUE "============================================" RESET "\n");
                printf(CYAN "              STATISTIQUES      " RESET "\n");
                printf(BLUE "============================================" RESET "\n\n");

                printf(GREEN "1" RESET " => " YELLOW "total des avions dans le parc" RESET "\n");
                printf(GREEN "2" RESET " => " YELLOW "total des avions par statut" RESET "\n");
                printf(GREEN "3" RESET " => " YELLOW "total des capacites" RESET "\n");
                printf(GREEN "4" RESET " => " YELLOW "L'avion ayant la plus grande / petite capacite " RESET "\n");
                printf(GREEN "5" RESET " => " YELLOW "le pourcentage et le coefficient d avions disponibles dans l aeroport" RESET "\n");
                printf(GREEN "0" RESET " => " QUIT_NUMBER "Quitter" RESET "\n");

                c = ValidateInt("Faire le choix : ");

                switch (c)
                {
                case 1 :
                    printf("le total des avions dans le parc est : %d",TotalEnParc()); 
                    break;
                case 2 :
                    TotalParStatut();
                    break;
                case 3 : 
                    CapaciteTotal();
                    break;
                case 4 :
                    MaxMinCapacite();
                    break;
                case 5 :
                     averageAvionsDispo();
                    break;
                case 0 :
                    return;

}
            } while(1);
                
    }

    //********************/ Traitment Des DATES*****************

    time_t convertToTime(Date d){
            struct tm t= {0};
            t.tm_mday = d.jour;
            t.tm_mon = d.mois - 1;
            t.tm_year = d.annee - 1900;
            return mktime(&t);
    }

    int datesCompare(Date d1 , Date d2){
        time_t t1 = convertToTime(d1);
        time_t t2 = convertToTime(d2);

        if (t1 < t2) return -1;
        if (t1 > t2) return 1;
        return 0;
    }


    void triParDates(){
        for (int i = 0; i < a.nbAvions; i++) {
        for (int j = 0; j < a.nbAvions - 1; j++) {
            if (datesCompare(a.avions[j].Av_date, a.avions[j+1].Av_date) > 0) {
                Avion temp = a.avions[j];
                a.avions[j] = a.avions[j+1];
                a.avions[j+1] = temp;
            }
        }
    }
    afficherAvions();
    }

    


    


int main(){ 

    a.nbAvions = 3;
    int choix;

    //some Data 
    strcpy(a.avions[0].modele, "Boeing 737");
    a.avions[0].capacite = 180;
    strcpy(a.avions[0].statut, "disponible");
    a.avions[0].idAvion = 1;

    a.avions[0].Av_date.jour = 15;
    a.avions[0].Av_date.mois = 3;
    a.avions[0].Av_date.annee = 2020;


    strcpy(a.avions[1].modele, "Airbus A320");
    a.avions[1].capacite = 150;
    strcpy(a.avions[1].statut, "en vol");
    a.avions[1].idAvion = 2;

    a.avions[1].Av_date.jour = 04;
    a.avions[1].Av_date.mois = 9;
    a.avions[1].Av_date.annee = 2023;


    strcpy(a.avions[2].modele, "Cessna 172");
    a.avions[2].capacite = 4;
    strcpy(a.avions[2].statut, "en maintenance");
    a.avions[2].idAvion = 3;

    a.avions[2].Av_date.jour = 22;
    a.avions[2].Av_date.mois = 1;
    a.avions[2].Av_date.annee = 2019;



    printf("donner le nom de l Aeroport : ");
    scanf("%s" , a.nom);

    do
    {
        printf("\n%s================== MENU PRINCIPAL ==================%s\n", HEADER, RESET);
        printf("%s1) %sAjouter une avion%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s2) %sAfficher tous les avions%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s3) %sAfficher tous les infos de l Aeroport%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s4) %smodifier une avion%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s5) %ssupprimer une avion%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s6) %srechercher un avion par ID%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s7) %srechercher des avions par Modele%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s8) %strier par capacite%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s9) %strier par Modele%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s10) %strier par date%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s11) %sstatiqtiques%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s0) %sQuitter%s\n", QUIT_NUMBER, QUIT_NUMBER, RESET);
        printf("%s====================================================%s\n", HEADER, RESET);
        
        choix = ValidateInt("Faire le choix : ");
        switch (choix)
        {
        case 1:
        ajouterAvion();
           break;
        case 2:
        afficherAvions();
           break;
        case 3:
        afficherAeroport();
           break;
        case 4:
        modifierAvion();
           break;
        case 5:
        supprimerAvion();
           break;
        case 6:
        rechercherAvionById();
           break;
        case 7:
        rechercherAvionByModel();
           break;
        case 8:
        triParCapacite();
        afficherAvions();
           break;
        case 9:
        triParModele();
           break;
        case 10:
        triParDates();
           break;
        case 11:
        statistique();
           break;
        case 0:
            printf("%sAu revoir !%s\n",YELLOW,RESET);
            exit(0); 
        }

    } while (1);

}


