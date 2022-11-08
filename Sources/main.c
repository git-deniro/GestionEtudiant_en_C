#include <stdio.h>
#include <stdlib.h>

int main(){

    int choix; 

    do
    {
        printf("----MENU GESTION DES ETUDIANTS----\n");
        printf("1-Nouvel Etudiant\n");
        printf("2-Afficher bulletin\n");
        printf("3-Modifier le nom\n");
        printf("4-Supprimer un Etudiant\n");
        printf("5-Afficher la moyenne de la classe\n");
        printf("6-Liste des admis\n");
        printf("0-Fin de traitement\n");
        printf("votre choix !");
        scanf("%d", &choix);

    } while (choix!=0);

    switch (choix)
    {
    case 1: 
        break;

    case 0: printf("fin de traitement!");
        break;
    
    default: printf("Choix errone! choix entre [1-6]\n\n");
        break;
    }
    
    return 0;
}
