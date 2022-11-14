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

    void modifierETD(){
        int codeR, tr = 0;
        FILE* temp;

        //Ouverture fichier bulletin.txt
        fp = fopen("note.txt","rt");
        if(fp==NULL){
            printf("Impossible d'ouvrir le fichier\n");
            exit(1);
        }

        //Ouverture fichier temp.txt
        temp = fopen("temp.txt","wt");
        if(temp==NULL){
            printf("Impossible d'ouvrir le fichier\n");
            exit(1);
        }

        printf("DONNEZ le code : "); scanf("%d",&codeR);

        while (fscanf(fp, "%d\n%s\n%s\n%f\n",&code,nom,prenom,&noteE) == 4)
        {
            if (code == codeR){
                tr = 1;
                printf("Donnez le mouveau nom : "); scanf("%s",nom);
            }

            fprintf(temp, "%d\n%s\n%s\n%f\n",code,nom,prenom,noteE);
        }
        if (tr==0) { printf("L'etudiant n'existe pas!!\n"); }
        fclose(fp); fclose(temp);
        remove("note.txt");
        rename("temp.txt","note.txt");                              
    }
    
    void supprimerETD(){
        int codeR, tr = 0;
        FILE* temp;

        //Ouverture fichier bulletin.txt
        fp = fopen("note.txt","rt");
        if(fp==NULL){
            printf("Impossible d'ouvrir le fichier\n");
            exit(1);
        }

        //Ouverture fichier temp.txt
        temp = fopen("temp.txt","wt");
        if(temp==NULL){
            printf("Impossible d'ouvrir le fichier\n");
            exit(1);
        }

        printf("DONNEZ le code a sipprimer : "); scanf("%d",&codeR);

        while (fscanf(fp, "%d\n%s\n%s\n%f\n",&code,nom,prenom,&noteE) == 4)
        {
            if (code != codeR){
                fprintf(temp, "%d\n%s\n%s\n%f\n",code,nom,prenom,noteE);
            }
            else {tr = 1;}
        }
        if (tr==0) { printf("L'etudiant n'existe pas!!\n"); }
        else { printf("L'etudiant est supprimer!"); }
        fclose(fp); fclose(temp);
        remove("note.txt");
        rename("temp.txt","note.txt");                              
    } 

#endif  // FONCTIONS_H_INCLUDED