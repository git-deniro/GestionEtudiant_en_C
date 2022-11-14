#include <stdio.h>
#include <stdlib.h>

#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

int code = 0;
char nom[20], prenom[20];
float noteE;
FILE * fp;

void ajouterETD(void);
void recherchETD(void);
void modifierETD(void);
void supprimerETD(void);

    void ajouterETD(){
    int codeR = 0, tr=0;  
    fp = fopen("note.txt", "at+");
    if(fp==NULL){
        printf("Impossible d'ouvrire le fichier \n");
        exit(1);
    }
    printf("Donnez le code : "); scanf("%d",&codeR);

    while(!feof(fp)){
        fscanf(fp, "%d\n%s\n%s\n%f\n",&code,nom,prenom,&noteE);
        if (code == codeR){ tr = 1; break; }
    }   

    if (tr==1) printf("etudiant exist deja!! \n");
    else{
        printf("NOM : "); scanf("%s",nom);
        printf("PRENOM : "); scanf("%s",prenom);
        do{ printf("NOTE : "); scanf("%f",&noteE); } while(noteE<0 || noteE>20);
        fprintf(fp, "%d\n%s\n%s\n%f\n",codeR,nom,prenom,noteE);
        }
    fclose(fp);
    }

    void recherchETD(){
        int codeR, tr = 0;
        fp = fopen("note.txt","r");
        if(fp==NULL){
            printf("Impossible d'ouvrire le fichier \n");
            exit(1);
        }
        printf("Donnez le code : "); scanf("%d",&codeR);
        while (!feof(fp))
        {
            fscanf(fp, "%d\n%s\n%s\n%f\n",&code,nom,prenom,&noteE);

            if (code == codeR){
                tr = 1;
                printf("CODE\tNOM\tPRENOM\tNOTE\n");
                printf("%d\t%s\t%s\t%.2f",code, nom, prenom, noteE);
            }
        }
            if (tr==0){
                printf("L'etudiant n'existe pas!!\n");
            }
        fclose(fp);   
    }



#endif  // FONCTIONS_H_INCLUDED