#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct {
    int idAvion ;
    char modele[30] ;
    int capacite ;
    char statut[30] ;
} Avion ;



typedef struct {
    char nom[30];
    int nbAvions;
    Avion avions[200];

} Aeroport ;

Aeroport a ;


//functions

    void ajouterAvion(){
        int n;
        char input[30];
        printf("combien d avions voulez vous entrer : ");
        scanf("%d" , &n);

        for(int i = 0 ; i < n ; i++){
            printf("entrer le modele de l avion : ");
            scanf(" %[^\n]" , a.avions[a.nbAvions].modele);

            printf("entrer la capacite de l avion : ");
            scanf("%d" , &a.avions[a.nbAvions].capacite);
            
            do{
                printf("entrer le statut de l avion : ");
                
                scanf(" %[^\n]" , input);
            }
            while( strcmp(input ,"disponible")!=0  && strcmp(input ,"en vol")!=0 && strcmp(input ,"en maintenance")!=0);

            strcpy(a.avions[a.nbAvions].statut ,input);
        

            a.nbAvions++;
            a.avions[a.nbAvions - 1].idAvion = a.nbAvions;
            
        }
        
        

        

    }

    void afficherAvions(){
        for(int i = 0 ; i< a.nbAvions ; i++){
            printf(" %s  |  %d  |  %s\n",a.avions[i].modele,
                                a.avions[i].capacite,
                                a.avions[i].statut);
        }
    }


int main(){ 

    a.nbAvions = 0;


    int choix;

    printf("name : ");
    scanf("%s" , a.nom);

    do
    {
        printf("\n%s=========== MENU PRINCIPAL ===========%s\n", HEADER, RESET);
        printf("%s1) %sAjouter une avion%s\n", NUMBER, GOLD, RESET);
        printf("%s2) %sAfficher tous les avions%s\n", NUMBER, GREEN, RESET);
        printf("%s3) %sCalculer la moyenne d un etudiant%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s4) %sCalculer la moyenne generale%s\n", NUMBER, GOLD, RESET);
        printf("%s5) %sAfficher tous les etudiants%s\n", NUMBER, GREEN, RESET);
        printf("%s6) %sAfficher le bulletin d un etudiant%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s7) %stri par CNE%s\n", NUMBER, GOLD, RESET);
        printf("%s8) %srecherche de bulletin par CNE%s\n", NUMBER, GREEN, RESET);
        printf("%s9) %srecherche de binaire par CNE%s\n", NUMBER, TURQUOISE, RESET);
        printf("%s0) %sQuitter%s\n", QUIT_NUMBER, QUIT_NUMBER, RESET);
        printf("%s======================================%s\n", HEADER, RESET);
        printf("%sFaire le choix : %s", PROMPT, RESET);
        

        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
        ajouterAvion();
           break;
        case 2:
        afficherAvions();
           break;
        case 0:
            exit(0); 
        }

    } while (1);

}



//ajouter
// a.nbAvions = 
// a.nbAvions++;