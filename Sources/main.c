#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../Headers/fonctions.h"

int main(){

    int choix; 

    do
    {
        system("cls");
        printf("----MENU GESTION DES ETUDIANTS----\n");
        printf("1-Nouvel Etudiant\n");
        printf("2-Afficher bulletin\n");
        printf("3-Modifier le nom\n");
        printf("4-Supprimer un Etudiant\n");
        printf("0-Fin de traitement\n");
        printf("votre choix !");
        scanf("%d", &choix);

        switch (choix){
            case 1: ajouterETD(); break;

            case 2: recherchETD(); break;

            case 3: modifierETD(); break; 

            case 4: supprimerETD(); break;

            case 0: printf("fin de traitement!"); break;
    
            default: printf("Choix errone! choix entre [1-4]\n\n"); break;
        }
        getch();

    } while (choix!=0);

    return 0;
}