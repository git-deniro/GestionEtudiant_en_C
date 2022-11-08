#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

int code;
char nom[20], prenom[20];
float noteE, noteO;
FILE * fp;

void ajouterETD(void);
void bulletin(void);
void modifier(void);
void supprimerETD(void);
void moyenneClase(void);
void listeAdmis(void);

#endif  // FONCTIONS_H_INCLUDED