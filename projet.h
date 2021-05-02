#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
programme : projet.h
auteur : Manoah Levy-Valensi & Loup Rusak & Vincent Vialette & Max Manin
finalite : Definitions des structures des fichiers
*/

typedef enum { mme , mr }Sexe;	

typedef enum { non , oui }Booleen;	

typedef struct {		// fichier : logement 
	int idLogement;
	char nomCite[20];
	char typeLog[10];
	char dispo[4];
	char handicap[4];
	int idEtud;
}Logement;


typedef struct {		// fichier : etudiant 
	int idEtud;
	char civilite[4];
	char nom[20];
	char prenom[20];
	char bourse[4];
	char handicap[4];
	int echellonBourse;
}Etudiant;

typedef struct {		// fichier : demandesEnAttente
	int idDemande;
	int idEtudD;
	int echellonBourseD; 
	char nomCiteD[20];
	char typeLogD[10];
}Demandes;

typedef struct listeDem{	// Demandes sera une liste, on définit donc sa structure
	Demandes l;
	struct 	listeDem *next;
}ListeDem, *Liste;

/*
programme : projet.h
auteur : Manoah Levy-Valensi & Loup Rusak & Vincent Vialette & Max Manin
finalite : Definitions des structures des fichiers
*/

int main(void);
void test(void);
Liste nouvelleListe(void);
int reaffichermenu(void);
int menuDem(void);
Liste insererDem(Liste LDem, Demandes d);
int chargeFichierDem(Liste *LDem, char *fichier);
Liste insererEnTete(Liste LDem, Demandes d);
Booleen listevide(Liste LDem);
Demandes lireDem(FILE *flot);
void afficherliste(Liste LDem);
Liste choixSuppression(Liste LDem);
Liste supprimerDansListe(Liste LDem, int s);
Liste supprimerEntete(Liste LDem);
Liste insererDansListe(Liste LDem,  Etudiant **tab, int *nb, int *max, char *fichier);
Booleen trouveID(Liste LDem, int d);
void LieuSauv(Liste LDem, Demandes d, int *sauv);
void SauvElement(Demandes d, int *sauv, char *fichier);
void sauvegardeElement(Demandes d, int *sauv, char * fichier, FILE *flot);
void sauvegarde(Liste LDem, char *fichier);
void sauvegardeFich(Liste LDem, FILE *flot);
void sauvFichTxt(Liste LDem, char *fichier);
void sauvegardeFichTxt(Liste LDem, FILE *flot);

// Loup Rusak

Etudiant **chargeEtudiants(FILE *flot, int *nb, int *max);
Etudiant lireEtudiant(FILE *flot);
void afficherEtudiant(Etudiant e);
void afficherTabEtud(Etudiant **tab, int nb);
int rechercherEtudiant(Etudiant **tab, int nb, Etudiant e);
Etudiant **insertionEtudiant(Etudiant **tab, int *nb, int *max, Etudiant e);
void afficherMenuEtud(void);
Etudiant saisieEtudiant(void);
Etudiant** menuEtudiant(Etudiant **tab, int *nb, int *max);
void sauvegardeEtudiant(FILE *flot, Etudiant **tab, int nb);

// Manoah Levy-Valensi

Logement** chargeLog(FILE *fic,int *nb, int *max);
Logement lireLog(FILE *fic);
void afficheLog(Logement l);
void afficheTabLog(Logement **tab, int nb);
void afficheTabLogOccupe(Logement **tab,int nb);
void afficheTabLogLibre(Logement **tab,int nb);
void triFusionCiteTabLog(Logement **tab,int nb);
void copie(Logement **tab,int i,int j, Logement **r);
void fusion(Logement **r,int n,Logement **s,int m,Logement **tab);
void sauvegardeLog(FILE *fic, Logement **tab, int nb);
int rechercheIdLog(int *idtemp,Logement **tab,int *nb);
void libererLog(int *idtemp,Logement **tab,int u);
int menuLog(int *test);

// Vialette Vincent

int rechercherEtudiantDem(Etudiant **tab, int nb, int e);
int menuGestion ();
void gestionViaDem(Liste LDem, Etudiant **tabe, Logement **tabl ,int  nbe, int nbl);
Demandes initialiseDem(Liste LDem, int s);
void gestionViaEtu(Liste LDem, Etudiant **tabe, Logement **tabl ,int  nbe, int nbl);
Demandes initialiseDem2(Liste LDem, int s);

// Max Manin & Vincent Vialette

int menu(Liste LDem);
int affichermenu(void);