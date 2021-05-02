#include "projet.h"

/*
programme : projet.c
auteur : Max Manin 
finalite : Création de la liste : LDem
*/

Liste nouvelleListe(void){
	return NULL;
}

/*
programme : projet.c
auteur : Max Manin & Vincent Vialette
finalite : permet de dirriger l'utilisateur vers son choix grace aux fonctions appellés qui retournent son choix 
*/

int menu(Liste LDem){
	int menu=-1, p=0;
	int nbe, maxe, ouv=0;
	Etudiant **tabe;
	char fichier[40]="demandeEnAttente.bin";	 // on dit que le nom de fichier de "base" est "demandeEnAttente.bin"
	int nbl,maxl,test=0, u=-1, idtemp;																						//On déclare les variables de type "entier" "nb","max","menu" et "test"=0
	Logement **tabl;																								//On déclare un tableau de pointeurs sur les type "Logement"
	char nomfichier[40]="logement.don";			//on déclare un tableau de caractères de longueur 40
	while(menu==-1 || reaffichermenu()){	// si le menu n'a pas été affiché on demande à l'utilisateur si il veut l'afficher
		p=0;
		menu=affichermenu();	// on demande à une fonction d'afficher le menu
		if (menu==1){		// test menu
			while (menu!=0){
				menu=menuDem();		// on affiche un sous menu coportant les fonction permettant d'utiliser le fichier des demandes
				if (menu==1 || menu==2){	// pour éviter d'appeller à deux endroits différents la fonction "chargeFichierDem" avec deux "if" on 
					if (menu==2){	
						printf("\nsaisir le nom du fichier, de type  : xxxxxx.yy : ");	// demande à l'utilisateur le nom de son fichier
						scanf("%*c%s", fichier);	// lit le nom du fichier
					}
					p=chargeFichierDem(&LDem, fichier);		// on appel la fonction et elle nous retourne "p" qui nous permet de savoir si il y a une erreur
					if (p==-1)
						printf("\nerreur d'ouverture du fichier : %s\n", fichier);		// on forme l'utilisateur de l'erreur 
				}
				if (menu==3)
					LDem=choixSuppression(LDem);	// appel la fonction qui permet de supprimer un element de la liste 
				if (menu==4)
					LDem=insererDansListe(LDem, tabe, &nbe, &maxe, fichier);	// appel de la fonction qui permet d'inserer un element de la liste 
				if (menu==5)
					afficherliste(LDem);		// appel de la fonction qui permet d'afficher la liste
				if (menu==6)
					sauvegarde(LDem, fichier);		// appel de la fonction qui permet de sauvegarder la lite dans un fichier binaire
				if (menu==7)
					sauvFichTxt(LDem, "Demandes.txt");
			}
		}
		else if (menu==2){
// Manoah Levy-Valensi{			
			int menu;															
			FILE *fic;																									//On déclare une variable "fic" qui permet d'utiliser un fichier
			menu=menuLog(&test);																						//On affiche le menu à l'utilisateur et on lui demande de choisir une option
			while(menu!=0 && menu!=-1)																						//Tant que l'utilisateur ne souhaite pas quitter le menu
			{
				if(menu==1 && test==0)																							//Si l'utilisateur choisit l'option 1 sans avoir chargé de fichier
				{
					fic=fopen(nomfichier, "r");																						//On ouvre le fichier 'logement.don' en lecture
					if (fic==NULL)																										//On quitte le programme si le fichier n'existe pas
						exit (1);
					tabl=chargeLog(fic,&nbl,&maxl);																					//On charge le fichier dans le tableau de pointeurs "tab"
					fclose(fic);																									//On ferme le fichier
					printf("\nLe fichier à bien été chargé.\n\n");																	//Message destiné à l'utilisateur
					test=1;																											//On confirme avoir un tableau en mémoire
					menu=-1;																										//Permet de revenir sur le menu
				}
				if(menu==2 && test==0)																							//Si l'utilisateur choisit l'option 2 sans avoir chargé de fichier
				{
					printf("\nEntrez le nom exact de votre fichier (exemple : logement.don) : ");									//Message destiné à l'utilisateur
					scanf("%*c%s",nomfichier);																						//On récupère le nom du fichier que l'utilisateur souhaite ouvrir
					fic=fopen(nomfichier, "r");																						//On ouvre le fichier choisit par l'utilisateur en lecture
						if (fic==NULL)																									//On quitte le programme si le fichier n'existe pas
							exit (1);
					tabl=chargeLog(fic,&nbl,&maxl);																					//On charge le fichier choisit par l'utilisateur dans le tableau de pointeurs "tab"
					fclose(fic);																									//On ferme le fichier
					printf("\nLe fichier %s à bien été chargé.\n\n",nomfichier);													//Message destiné à l'utilisateur
					test=1;																											//On confirme avoir un tableau en mémoire
					menu=-1;																										//Permet de revenir sur le menu
				}
				if(menu==1 && test==1)																							//Si l'utilisateur choisit l'option 1 après avoir chagé un fichier
					test=0;																											//On met la variable "test" à 0 pour revenir dans le menu supérieur
				if(menu==2 && test==1)																							//Si l'utilisateur choisit l'option 2 après avoir chagé un fichier
				{
					int x=nbl;																										//On déclare une variable temporaire "x"
					triFusionCiteTabLog(tabl,x);																						//On appelle la fonction qui va permettre le tri du tableau
					printf("\nLe fichier à bien été trié selon le nom des cités.\n\n");												//Message destiné à l'utilisateur
					menu=-1;																										//Permet de revenir sur le menu
				}
				if(menu==3 && test==1)																							//Si l'utilisateur choisit l'option 3 après avoir chagé un fichier
					{
						afficheTabLog(tabl,nbl);																						//On appelle la fonction qui affiche le tableau
						menu=-1;																									//Permet de revenir sur le menu
					}
				if(menu==4 && test==1)																							//Si l'utilisateur choisit l'option 4 après avoir chagé un fichier
				{
					afficheTabLogOccupe(tabl,nbl);																					//On appelle la fonction qui afficheles logements occupés du tableau
					menu=-1;																										//Permet de revenir sur le menu
				}
				if(menu==5 && test==1)																							//Si l'utilisateur choisit l'option 5 après avoir chagé un fichier
				{
					afficheTabLogLibre(tabl,nbl);																						//On appelle la fonction qui afficheles logements libres du tableau
					menu=-1;																										//Permet de revenir sur le menu
				}
				if(menu==6 && test==1)																							//Si l'utilisateur choisit l'option 6 après avoir chagé un fichier
  			      {
        			    u=rechercheIdLog(&idtemp,tabl,&nbl);                                                                                //On cherche le rang du logement indiqué par l'utilisateur ou on retourne "-1" si l'utilisateur veut annuler l'opération
         			   if(u>=0)                                                                                                                //Si l'utilisateur n'a pas voulu annuler l'opération
        			    {
       			         libererLog(&idtemp,tabl,u);                                                                                                //On libère le logement si nécessaire
      			          afficheLog(*tabl[u]);                                                                                                    //On affiche le logement concerné par l'opération
      		      }
		            menu=-1;                                                                                                            //Permet de revenir sur le menu
		        }
				if(menu==7 && test==1)																							//Si l'utilisateur choisit l'option 7 après avoir chagé un fichier
				{
					fic=fopen(nomfichier, "w");																							//On ouvre le fichier choisit par l'utilisateur en écriture
					if (fic==NULL)																											//On quitte le programme si le fichier n'existe pas
						exit (1);
					sauvegardeLog(fic,tabl,nbl);																							//On appelle la fonction qui va sauvegarder le tableau dans le fichier ouvert précédemment
					fclose(fic);																										//On ferme le fichier
					printf("\nLe tableau à bien été enregistré dans le fichier %s.\n\n",nomfichier);									//Message destiné à l'utilisateur
					menu=-1;																										//Permet de revenir sur le menu
				}
				menu=menuLog(&test);																							//On ré affiche le menu à l'utilisateur et on attends qu'il choisisse une option
			}
//}Manoah Levy-Valensi
		}
		else if (menu==3){
//Rusak Loupx			
			if (ouv==0){
				ouv=ouv+1;
				FILE *flot;
				flot=fopen("etudiants.txt","r");
				if(flot==NULL)
				{
					printf("Erreur d'ouverture du fichier des demandes\n");
					exit(1);
				}
				tabe=chargeEtudiants(flot,&nbe,&maxe);
				fclose(flot);
			}
			menuEtudiant(tabe, &nbe, &maxe);
//}Rusak Loup
		}
		else if (menu==4){
			ouv=1;
			p=chargeFichierDem(&LDem, fichier);		// on appel la fonction et elle nous retourne "p" qui nous permet de savoir si il y a une erreur
			if (p==-1)
				printf("\nerreur d'ouverture du fichier : %s\n", fichier);		// on forme l'utilisateur de l'erreur 
//Rusak Loup{
			
			FILE *flot;
			flot=fopen("etudiants.txt","r");
			if(flot==NULL)
			{
				printf("Erreur d'ouverture du fichier des demandes\n");
				exit(1);
			}
			
			tabe=chargeEtudiants(flot,&nbe,&maxe);
			fclose(flot);
			printf("\nle fichier : etudiants.txt  a été enregistré\n");
//}Rusak Loup
//Manoah Levy-Valensi{
			FILE *fic;																									//On déclare une variable "fic" qui permet d'utiliser un fichier
			fic=fopen(nomfichier, "r");																						//On ouvre le fichier 'logement.don' en lecture
			if (fic==NULL)																										//On quitte le programme si le fichier n'existe pas
				exit (1);
			tabl=chargeLog(fic,&nbl,&maxl);																					//On charge le fichier dans le tableau de pointeurs "tab"
			fclose(fic);																									//On ferme le fichier
			printf("\nle fichier : %s  a été enregistré\n", nomfichier);	
//}Manoah Levy-Valensi
		}
		else if (menu==5){
			printf("Fichier des demandes :\n");
			afficherliste(LDem);		// appel de la fonction qui permet d'afficher la liste
			printf("\n************************************************************************\n"); 	// affiche un ligne pour simplifier la lecture
			printf("\nFichier des étudiants :\n\n");
			afficherTabEtud(tabe, nbe);		// appel de la fonction qui permet d'afficher le tableau d'etudiant
			printf("\n\n************************************************************************\n"); 	// affiche un ligne pour simplifier la lecture
			printf("\nFichier des logements (non trié) :\n\n");
			afficheTabLog(tabl,nbl);	// appel de la fonction qui permet d'afficher le tableau de logement
		}
		else if (menu==6){
			while (menu != 0){
				menu=menuGestion();
				if(menu==1)
					gestionViaDem(LDem,tabe,tabl,nbe,nbl);
				if(menu==2)
					gestionViaEtu(LDem,tabe,tabl,nbe,nbl);
			}				
		}
		else if (menu==0)
			exit(1);	// quand l'utilisateur selectionne 0 le programme s'arrète
	}
}

/*
programme : projet.c
auteur : Max Manin & Vincent Vialette
finalite : affichage du menu et lit le choix de l'utilisateur 
*/

int affichermenu(void){
	int menu=0;	
	printf("\nMenu :\n");												// affiche les posibilitées du menu principale
	printf("\t 1. Fichier des demandes en attentes\n");							
	printf("\t 2. Fichier des logements\n");									
	printf("\t 3. Fichier des étudiants\n");	
	printf("\t 4. Charger tous les fichiers (fichiers de bases)\n");			
	printf("\t 5. Afficher le contenu de tous les fichiers\n");															
	printf("\t 6. Attribution de logements\n");																
	printf("\t 0. Quitter\n");													
	printf("\nSelectionnez une option :  ");	
	scanf("%d",&menu);		// lecture du choix de l'utilisateur
	while (menu>7 || menu<=0){		// on verifie que le choix existe 
		printf("\nErreur lors du choix veuillez resaissir une option :\t");		// si le choix n'existe pas on redemande à l'utilisateur de faire son choix
		scanf("%d",&menu);		
	}
	printf("\n************************************************************************\n"); 	// affiche un ligne pour simplifier la lecture
	return menu;	// on retourn le choix pour permettre à la fonction : menu d'executer le choix de l'utilisateur 
}

/*
programme : projet.c
auteur : Max Manin 
finalite : réaffiche le menu qui a été afficher précédement si l'utilisateur le souhaite
*/

int reaffichermenu(void){
	int rep;		
	printf("\nVoulez-vous afficher à nouveau le menu principale (1 : oui / 0 : non) ?\t ");		// demande à l'utilisateur 
	scanf("%d",&rep);		// lit le choix de l'utilisateur 
	return rep;		// retourne le choix de l'utilisateur 
}

/*
programme : projet.c
auteur : Max Manin 
finalite : affiche le menu comportant toutes les options applicables au fichier des demandes 
*/

int menuDem(void){
	int menu;
	printf("\nMenu des demandes :\n");	 	// affiche les posibilitées du menu secondaire
	printf("\n\t1. Utiliser les données du fichier de base : \"demandeEnAttente.bin\" (fichier binaire)"); 
	printf("\n\t2. Utiliser les données du fichier de votre choix (fichier binaire nécessaire)");
	printf("\n\t3. Supprimer une demande");
	printf("\n\t4. Ajouter une demande");
	printf("\n\t5. Afficher les demandes");	
	printf("\n\t6. Sauvegarder les valeurs dans le fichier \"demandeEnAttente.bin\"");
	printf("\n\t7. Sauvegarder les valeurs dans le fichier \"Demandes.txt\" (fichier texte)");
	printf("\n\t0. Quitter\n");
	printf("\nSelectionnez une option :  ");
	scanf("%d", &menu);		// lecture du choix de l'utilisateur
	while (menu>7 || menu<0){		 // on verifie que le choix existe 
			printf("\nErreur : Reselectionnez une option :  ");		// si le choix n'existe pas on redemande à l'utilisateur de faire son choix
			scanf("%d", &menu);	
		}
	printf("\n************************************************************************\n");		// affiche un ligne pour simplifier la lecture
	return menu;		// on retourn le choix pour permettre à la fonction : menu d'executer le choix de l'utilisateur 
}

/*
programme : projet.c
auteur : Max Manin 
finalite : permet de charger la liste des demandes grace au nom de fichier de la fonction fichierDem
*/

int chargeFichierDem(Liste *LDem, char *fichier){
	Demandes d;		// on crée une "Demandes" qui vas nous permettre de remplir la liste  
	FILE *flot;		// on crée un lien 
	flot=fopen(fichier, "rb");	 // on relit le lien au fichier de base ou choisit par l'utilisateur de façon à pouvoir le lire 
	if (flot==NULL) 	// on retourne -1 si il y a une erreur d'ouverture
		return -1;
	d=lireDem(flot); 	// on lit le premier argument 
	while (!feof(flot)){	 // tant que le fichier n'est pas fini on lit puis on insert la demande dans la liste créée au paravant  
		*LDem=insererDem(*LDem, d);
		d=lireDem(flot);
	}
	if (!feof(flot))	// j'ai du rajouter un insertion sinon il manquait une ligne ( et le if pour si le fichier était vide)
		*LDem=insererDem(*LDem, d);
	fclose(flot); 	// on ferme le fichier 
	printf("\nle fichier : %s  a été enregistré\n", fichier); 	// on informe l'utilisateur 
	return 1;	 // on retourne 1 pour dire qu'il n'y a pas eu de problème
}

/*
programme : projet.c
auteur : Max Manin 
finalite : permet de lire une demande dans le fichier donner et la renvoie sous la forme de la structure Demande 
*/

Demandes lireDem(FILE *flot){
	Demandes d;		
	fread(&d,sizeof(Demandes),1,flot); 		// on lit dans le fichier binaire un article et on le renvoit  
	return d;
}

/*
programme : projet.c
auteur : Max Manin 
finalite : permet d'insérer la demande en respectant l'ordre de la liste  (decroissant)
*/

Liste insererDem(Liste LDem, Demandes d){
	if (listevide(LDem))	// on recevera 1 ou 0 / si on recoit 1 la fonction ce lance 
		return insererEnTete(LDem, d); 	// on insert d au début de la liste 
	if (LDem->l.echellonBourseD < d.echellonBourseD) // si l'echellon de bourse a ajouter est plus grand ou égal à la première demande de la liste la fonction ce lance
		return insererEnTete(LDem, d);	// on insert d au début de la liste 
	LDem->next=insererDem(LDem->next, d);	 // si les deux boucles précédentes ne ce sont pas lancer on relance la fonction en enlevant la première demande
	return LDem; 	// on retourne la liste 
}

/*
programme : projet.c
auteur : Max Manin 
finalite : insert une demande au début de la liste 
*/

Liste insererEnTete(Liste LDem, Demandes d){
	ListeDem *m;	// on crée une nouvelle liste 
	m=(ListeDem*)malloc(sizeof(ListeDem));		// on lui attribue un espace 
	if (m==NULL){	// on regarde si l'attribution a correctement fonctionnée 
		printf("Problème de malloc->Liste\n");
		exit(1);
	}
	m->l=d;		// on crée une liste avec une seule demande 
	m->next=LDem; 	// on racroche la liste principale à notre nouvelle liste pour rajouter les demandes déjà enregistrées
	return m;	// on retourne la liste "m"
}

/*
programme : projet.c
auteur : Max Manin 
finalite : regarde si la liste est vide ou non et renvoie le résultat sous une structure Boolleene 
*/

Booleen listevide(Liste LDem){
	if(LDem == NULL)
		return oui;		// si la liste est vide on retourn oui : 1 (booleen) 
	return non;		// sinon on retourne non : 0
}

/*
programme : projet.c
auteur : Max Manin 
finalite : permet d'afficher le contenu du fichier placé dans une liste 
*/

void afficherliste(Liste LDem){
	if (listevide(LDem)){		// on recevera 1 ou 0 / si on recoit 1 la fonction ce lance 
		printf("\nAucun élément n'a été enregistré veuilliez vérifier le comptenus du fichier.\n"); 	// on informe l'utilisateur 
		return; // on quitte a fonction pour retourner su le menu précédent
	}
	printf("\nID Demande\tID Etudiant\tEchellon\tNom Cité\tType Logement \n\n"); 	// on affiche à quoi correspondent les valeurs 
	while (LDem!=NULL){		// tant que la liste a des articles on affiche les valeurs des demandes 
		printf("\t%d\t\t%d\t\t%d\t%s\t\t  %s\n",LDem->l.idDemande, LDem->l.idEtudD, LDem->l.echellonBourseD, LDem->l.nomCiteD, LDem->l.typeLogD);
		if (LDem->next==NULL || LDem->l.echellonBourseD!=LDem->next->l.echellonBourseD) 	// si la bourse change on passe à la ligne suivante pour afficher la demande 
			printf("\n");
		LDem=LDem->next;	// on regarde le prochaine article 
	}
	printf("\n");
}

/*
programme : projet.c
auteur : Max Manin 
finalite : 
*/

Liste choixSuppression(Liste LDem){
	int s, p;
	printf("\ndonner l'identifiant de la demande à supprimer :\t"); 	// on demande à l'utilisateur la demande à suprimer 
	scanf("%d", &s);	 // on récupère son choix 
	printf("\n");	
	if (trouveID(LDem, s))		// on vérifie que l'id passé existe 
		LDem=supprimerDansListe(LDem, s);	// si il existe on effectue la suppression
	else printf("la demande avec l'identifiant %d n'existe pas\n", s);	// on informe l'utilisateur que l'id n'existe pas 
	return LDem;	// on retourne la liste modifié ou non
}

/*
programme : projet.c
auteur : Max Manin 
finalite : 
*/

Liste supprimerDansListe(Liste LDem, int s){
	if (listevide(LDem)){	// si la liste est vide on retourne la liste en informant l'utilisateur 
		printf("la liste est vide veuilliez la remplir avant d'executer cette fonction\n"); 	
		return LDem;
	}
	if (LDem->l.idDemande == s){ 	//  si l'id à supprimer est le meme que l'id de la première demande de la liste 
		printf("la demande avec l'identifiant %d a été supprimer\n", s);	
		return supprimerEntete(LDem); 		// on appel la fonction qui supprime la première demande 
	}
	LDem->next=supprimerDansListe(LDem->next, s); 	// si les deux boucles précédentes ne ce sont pas lancer on relance la fonction en enlevant la première demande
return LDem; 	// on retourn la liste 
}

/*
programme : projet.c
auteur : Max Manin 
finalite : 
*/

Liste supprimerEntete(Liste LDem){
	LDem=LDem->next;	// on dit que LDem est égale à elle même mais sans la première demande 
	return LDem;	// on retourne LDem
}

/*
programme : projet.c
auteur : Max Manin 
finalite : permet de saisir les informations de la demande à rajouter en vérifiant si il n'y a pas d'erreurs
*/ 

Liste insererDansListe(Liste LDem,  Etudiant **tab, int *nb, int *max, char *fichier){
	int val, enr=0, n, sauv=0, s;
	Etudiant e;
	Demandes d; 	// on crée la demande que l'on vas ajouter à la liste 
	printf("\nSelectionnez l'identifiant de la demande :  "); 	// on demande idDemande 
	scanf("%d",&d.idDemande);	// on lit la saisit de l'utilisateur
	while (d.idDemande<0 || trouveID(LDem, d.idDemande)){	// on vérifie que l'id de la demande est supérieur à 0 et qu'il n'existe pas 
		printf("Erreur : Reselectionnez l'identifiant de la demande :  "); 	// on redemande idDemande
		scanf("%d",&d.idDemande);		// on lit la saisit de l'utilisateur
	}
	printf("Selectionnez l'identifiant de l'étudiant :  ");		// on demande idEtudD
	scanf("%d",&d.idEtudD);		// on lit la saisit de l'utilisateur
	while (d.idEtudD<0){	// on vérifie que l'id de l'etudiant est supérieur à 0
		printf("Erreur : Reselectionnez l'identifiant de l'étudiant :  ");		// on redemande idEtudD
		scanf("%d",&d.idEtudD);		// on lit la saisit de l'utilisateur
	}
// Vincent Vialette {
	if (rechercherEtudiantDem(tab, *nb, d.idEtudD)!=-1){		// on regarde si l'etudiant existe ou non si il n'extiste pas on continue
		printf("l'étudiant n'existe pas voulez vous le rajouter ? (1 : oui / 0 : non)\t");		//on propose à l'utilisateur de le rajouter
		scanf("%d", &val);		// on lit la réponse de l'utilisateur 
		if (val==1){		// si il veut on l'ajoute :	
			e=saisieEtudiant();		// on receuille toutes les informations sur l'etudiant
			tab=insertionEtudiant(tab, nb, max, e);		// on ajoute l'etudiant au tableau
			enr=1;	// pour ne pas ressaisir la bourse on modifie la variable à 1
			*nb++;	// on incrémente nb de 1 pour dire que l'on as ajouté une demande
		}
		else return LDem;		// si il ne veut pas on ne continue pas la saisie de la nouvelle demande 
	}
	if (enr==0){	// si l'etudiant n'a pas été ajouté précédement on demande :
		printf("Selectionnez l'echellon de la bourse de l'étudiant :  ");	// on demandes echellonBourseD
		scanf("%d%*c",&d.echellonBourseD);		// on lit la saisit de l'utilisateur
	}
	if(enr==1){		// si il a été ajouté le remplissage de la bourse se fait automatiquement 
		if (strcmp(e.bourse,"oui")==0)		// si l'etudiant a une bourse 
			d.echellonBourseD=e.echellonBourse;	// on l'enregiste directement 
		else d.echellonBourseD=0;	//sinon on le met à 0
	}
//} Vincent Vialette
	while (d.echellonBourseD>7 || d.echellonBourseD<0){		// on vérifie que l'echellonde la bourse de l'étudiant est supérieur à 0 et inférieur à 7
		printf("Erreur : Reselectionnez l'echellon de la bourse de l'étudiant :  ");	// on redemande echellonBourseD
		scanf("%d%*c",&d.echellonBourseD);		// on lit la saisit de l'utilisateur
	}
	printf("Selectionnez le nom de la cité voulut : ");		// on demande nomCiteD
	scanf("%s%*c",d.nomCiteD);		// on lit la saisit de l'utilisateur
	printf("Selectionnez le type de logement voulut (chambre / studio / T1 / T2) :  ");		// on demande typeLogD
	scanf("%s%*c",d.typeLogD);		// on lit la saisit de l'utilisateur
	while (strcmp(d.typeLogD,"chambre")!=0 && strcmp(d.typeLogD,"studio")!=0 && strcmp(d.typeLogD,"T1")!=0 && strcmp(d.typeLogD,"T2")!=0){ // on vérifie que le type de logement existe (chambre / studio / T1 / T2)
		printf("Erreur : Reselectionnez le type de logement voulut (chambre / studio / T1 / T2) :  ");		// on redemande typeLogD
		scanf("%s%*c",d.typeLogD);		// on lit la saisit de l'utilisateur
	}
	printf("Voullez-vous sauvegarder la demande ? (1 : oui / 0 : non)\t");		//on propose à l'utilisateur de rajouter la demande au fichier
	scanf("%d", &s);		// on lit la réponse de l'utilisateur 
	if (s==1){
		LieuSauv(LDem, d, &sauv);		// on demande à une fonction de nous renvoyer l'enplacement où il faut ajouter la demande
		SauvElement(d, &sauv, fichier);	// on sauvegarde la demande 
	}
	printf("\nLa demande à bien été enregistrée\n");		// on informe l'utilisateur 
	LDem=insererDem(LDem, d); 	// on ajoute la demande à la liste 
}

/*
programme : projet.c
auteur : Max Manin 
finalite : retrouve l'id d'un logement et la compare
*/ 

Booleen trouveID(Liste LDem, int d){
	while (LDem!=NULL){		// tant que LDem n'est pas vide
		if (LDem->l.idDemande==d)	// on regarde si l'id de la demande est égale à l'id rechercher
			return oui;		// on retourne 1 
		LDem=LDem->next; 	// on dit que LDem est égale à elle même mais sans la première demande
	}
	return non;	// si l'on ne trouve pas l'id chercher ou retourne 0
}

/*
programme : projet.c
auteur : Max Manin 
finalite : on regarde quel est la position de la demande à rajouté
*/

void LieuSauv(Liste LDem, Demandes d, int *sauv){
	*sauv=*sauv+1;		// on incrémente sauv de 1
	if (listevide(LDem))	// on recevera 1 ou 0 / si on recoit 1 la fonction :
		return; 	// on retourne à la fonction précédente
	if (LDem->l.echellonBourseD < d.echellonBourseD) // si l'echellon de bourse a ajouter est plus grand ou égal à la première demande de la liste :
		return;			// on retourne à la fonction précédente
	LieuSauv(LDem->next, d, sauv);	 // si les deux boucles précédentes ne ce sont pas lancer on relance la fonction en enlevant la première demande
	return; 	// on retourne à la fonction précédente
}

/*
programme : projet.c
auteur : Max Manin 
finalite :	on sauvegarde une demande dans le fichier
*/ 

void SauvElement(Demandes d, int *sauv, char *fichier){
	FILE *flot; 	// on crée un lien 
	flot=fopen(fichier, "ab");	 // on relit le lien au fichier de base ou choisit par l'utilisateur de façon à pouvoir écrire dedans  
	if (flot==NULL){ 	// on vérifie que l'ouverture a fonctionné
		printf("Problème d'ouverture du fichier\n");	// on informe l'utilisateur
		return;
	}
	sauvegardeElement(d, sauv, fichier, flot); 	// on sauvegarde la liste dans le fichier 
	fclose(flot);	// on ferme le fichier 
}

/*
programme : projet.c
auteur : Max Manin 
finalite :	on sauvegarde une demande dans le fichier
*/ 

void sauvegardeElement(Demandes d, int *sauv, char * fichier, FILE *flot){
	fseek(flot, *sauv*sizeof(Demandes), SEEK_SET);		// on se place au début du fichier puis l'on se décale de sauv fois 
	fwrite(&d, sizeof(Demandes), 1, flot);	 // on écrit dans le fichier 1 fois la demande "d"
}

/*
programme : projet.c
auteur : Max Manin 
finalite : ouvre le fichier en binaire et vérifie si le fichier est vide
*/ 

void sauvegarde(Liste LDem, char *fichier){
	int j;
	FILE *flot; 	// on crée un lien 
	flot=fopen(fichier, "wb");	 // on relit le lien au fichier de base ou choisit par l'utilisateur de façon à pouvoir écrire dedans  
	if (flot==NULL){ 	// on vérifie que l'ouverture a fonctionné
		printf("Problème d'ouverture du fichier\n");	// on informe l'utilisateur
		return;
	}
	if (listevide(LDem)){ 		// on vérifie si la liste est vide 
		printf("\nla liste est vide voullez-vous vraiment effacer le contenu du fichier ? (1 : oui / 0 : non) \t"); 	// on informe l'utiisateur
		scanf("%d", &j);	// on saisit sa réponse 
		if (j==0)	 // si il ne veut pas effacer le fichier 
			return;	 // on sort de la boucle 
	}
	sauvegardeFich(LDem, flot); 	// on sauvegarde la liste dans le fichier 
	fclose(flot);	// on ferme le fichier 
}

/*
programme : projet.c
auteur : Max Manin 
finalite : permet de saisir les informations de la demande à rajouter en vérifiant si il n'y a pas d'erreurs
*/ 

void sauvegardeFich(Liste LDem, FILE *flot){
	Demandes d;
	while (LDem!=NULL){		// la liste n'est pas vide  
		d=LDem->l;		// on dit que la demande d est la même que la première demande du fichier 
		fwrite(&d, sizeof(Demandes), 1, flot);	 // on écrit dans le fichier 1 fois la demande "d"
		LDem=LDem->next;	// on dit que LDem est égale à elle même mais sans la première demande
	}
	printf("\n Sauvegarde effectuée\n"); 	// on informe l'utilisateur
}	

/*
programme : projet.c
auteur : Max Manin 
finalite : ouvre le fichier en binaire et vérifie si le fichier est vide
*/ 

void sauvFichTxt(Liste LDem, char *fichier){
	int j;
	FILE *flot; 	// on crée un lien 
	flot=fopen(fichier, "w");	 // on relit le lien au fichier de base ou choisit par l'utilisateur de façon à pouvoir écrire dedans  
	if (flot==NULL){ 	// on vérifie que l'ouverture a fonctionné
		printf("Problème d'ouverture du fichier\n");	// on informe l'utilisateur
		return;
	}
	if (listevide(LDem)){ 		// on vérifie si la liste est vide 
		printf("\nla liste est vide voullez-vous vraiment effacer le contenu du fichier ? (1 : oui / 0 : non) \t"); 	// on informe l'utiisateur
		scanf("%d", &j);	// on saisit sa réponse 
		if (j==0)	 // si il ne veut pas effacer le fichier 
			return;	 // on sort de la boucle 
	}
	sauvegardeFichTxt(LDem, flot); 	// on sauvegarde la liste dans le fichier 
	fclose(flot);	// on ferme le fichier 
}

/*
programme : projet.c
auteur : Max Manin 
finalite : permet de saisir les informations de la demande à rajouter en vérifiant si il n'y a pas d'erreurs
*/ 

void sauvegardeFichTxt(Liste LDem, FILE *flot){
	while (LDem!=NULL){		// la liste n'est pas vide  
		fprintf(flot, "%d\t%d\t%d\t%s\t%s\t\n",LDem->l.idDemande, LDem->l.idEtudD, LDem->l.echellonBourseD, LDem->l.nomCiteD, LDem->l.typeLogD);
		if (LDem->next==NULL || LDem->l.echellonBourseD!=LDem->next->l.echellonBourseD);
		LDem=LDem->next;	// on dit que LDem est égale à elle même mais sans la première demande
	}
	printf("\n Sauvegarde effectuée\n"); 	// on informe l'utilisateur
}	



/***************************************************************************************************************************************************************************

***************************************************************************************************************************************************************************/



/*
Fonction : Chargement des Etudiants.
Auteur : Loup RUSAK 
Finalité : chargement des étudiants dans un tableau de pointeurs dynamique sur des articles.*/
Etudiant **chargeEtudiants(FILE *flot, int *nb, int *max)
{
	Etudiant **tab, **aux, e;
	*nb=0; // taille logique du tableau au début et compteur de boucle pour insertion
	*max=100; // taille logique du tableau après les allocation et pour les réallocations.
	tab=(Etudiant**)malloc(*max*sizeof(Etudiant*)); // allocation de l'espace mémoire pour stocker un étudiant
	if(tab==NULL) // si erreur d'allocation
	{
		printf("Erreur d'allocation pour le tableau de pointeurs des Etudiants\n");
		exit(1);
	}
	e=lireEtudiant(flot); //lecture de l'étudiant à partir du fichier
	while(!feof(flot))
	{
		if(*nb==*max)// si tableau déjà plein
		{
			aux=(Etudiant**)realloc(tab,(*max+5)*sizeof(Etudiant*));// réallocation du tableau pour rajouter de nouvelles places pour des étudiants.
			if(aux==NULL)
			{
				printf("Erreur de réallocation pour le tableau de pointeurs des Etudiants\n");
				exit(1);
			}
			tab=aux;
			*max=*max+5;
		}
		tab[*nb]=(Etudiant*)malloc(sizeof(Etudiant));
		if(tab[*nb]==NULL)
		{
			printf("Erreur d'allocation pour le tableau de pointeurs des Etudiants\n");
			exit(1);
		}
		*tab[*nb]=e; //affectation de l'étudiant au pointeur
		*nb=*nb+1;
		e=lireEtudiant(flot);
	}
	return tab; //on retourne le tableau dynamique de pointeurs.
}


/*
Fonction : Lecture des Etudiants.
Auteur : Loup RUSAK
Finalité : Lit un Etudiant depuis le fichier et le retourne*/
Etudiant lireEtudiant(FILE *flot)
{
	Etudiant e;
	fscanf(flot,"%d%s%s%s%s%s",&e.idEtud,e.civilite,e.nom,e.prenom,e.bourse,e.handicap);
	if(strcmp(e.bourse,"oui")==0) //Si l'étudiant est boursier on lit alors l'échellon de la bourse sinon on passe à l'étudiant suivant
	{
		fscanf(flot,"%d",&e.echellonBourse);
	}
	return e;
}


/*
Fonction : Affichage des Etudiants.
Auteur : Loup RUSAK
Finalité : Affichage à l'écran de l'Etudiant.*/
void afficherEtudiant(Etudiant e)
{
	printf("%d\t\t%s\t%15s\t\t%10s\t\t%s\t\t%s",e.idEtud,e.civilite,e.nom,e.prenom,e.bourse,e.handicap);
	if(strcmp(e.bourse,"oui")==0) // si l'étudiant est boursier alors on affiche l'échellon de la bourse sinon non
		printf("\t\t%d", e.echellonBourse);
	printf("\n");
}


/*
Fonction : Affichage du tableau des Etudiants.
Auteur : Loup RUSAK
Finalité : Affiche le tableau de pointeurs vers des Etudiants.*/
void afficherTabEtud(Etudiant **tab, int nb)
{
	int i=0;
	Etudiant e;
	printf("IDETUDIANT\tCIVILITE\t    NOM\t\t    PRENOM\t\tBOURSIER\tHANDICAP\tECHELLONBOURSE\n\n");
	while(i!=nb)
	{
		e=*tab[i];
		afficherEtudiant(e);
		i=i+1;
	}
}


/*
Fonction : Recherche des Etudiants.
Auteur : Loup RUSAK
Finalité : Recherche un Etudiant donné dans le tableau des Etudiants.*/
int rechercherEtudiant(Etudiant **tab, int nb, Etudiant e)
{
	int i;
	for(i=0 ; i<nb ; i++) // boucle de parcours du tableau
	{
		if(tab[i]->idEtud == e.idEtud) // teste d'égalité : si l'identifiant est déjà présent
		{
			return -1;
		}
		if(tab[i]->idEtud > e.idEtud) // test de supériorité : si identifiant non présent et autre identifiant plus grand trouvé
		{
			return i; // retourne la valeur d'insertion
		}
	}
	return -2; // aucun des deux cas précédents
}

/*
Fonction : Recherche des Etudiants.
Auteur : Vincent Vialette 
Finalité : Recherche un Etudiant donné dans le tableau des Etudiants.
*/
int rechercherEtudiantDem(Etudiant **tab, int nb, int e)
{
	int i;
	for(i=0 ; i<nb ; i++) // boucle de parcours du tableau
	{
		if(tab[i]->idEtud == e) // teste d'égalité : si l'identifiant est déjà présent
		{
			return -1;
		}
		if(tab[i]->idEtud > e) // test de supériorité : si identifiant non présent et autre identifiant plus grand trouvé
		{
			return i; // retourne la valeur d'insertion
		}
	}
	return -2; // aucun des deux cas précédents
}

/*
Fonction : Insertion d'un Etudiant.
Auteur : Loup RUSAK
Finalité : Insert un Etudiant donné dans le tableau des Etudiants en fonction du résultat de la recherche. */
Etudiant **insertionEtudiant(Etudiant **tab, int *nb, int *max, Etudiant e)
{
	Etudiant **aux;
	int i,res;

	res=rechercherEtudiant(tab, *nb, e); // on recherche l'idEtud de l'Etudiant dans le tableau

	if(res == -1) // si la recherche indique que l'idEtud est déjà présent
	{
		printf("\n\nidEtudiant déjà éxistant dans la structure ! Vous pouvez tenter d'insérer avec le numéro : %d\n\n", *nb+1);
		return tab; // on retourne le tableau sans aucune modifications
	}

	if(*nb == *max) // si le tableau est plein on augmente sa taille via un réallocation
	{
		aux=(Etudiant**)realloc(tab,(*nb+5)*sizeof(Etudiant*)); // on augmente de 5 la taille du tableau de pointeurs via un tableau auxiliaire
		if(aux == NULL)
		{
			printf("Erreur de réallocation pour l'insertion !\n");
			exit(1);
		}
		tab=aux; // aucun problème donc échange d'adresse
		*max=*max+5;
	}

	if(res == -2) // si la recherche indique que l'idEtud n'est pas présent et qu'il n'en existe pas de supérieurs
	{
		printf("\n\nidEtudiant non existant dans la structure; insertion ...\n\n");

		tab[*nb]=(Etudiant*)malloc(sizeof(Etudiant)); // on aloue un espace de type pointeur sur des étudiants pour poursuivre l'insertion
		if (tab[*nb]==NULL)
		{
			printf("Problème de malloc pour l'espace de l'étudiant\n");
			exit(1);
		}

		*tab[*nb]=e; // affectation de l'étudiant à l'espace créé
		*nb=*nb+1;
	}
	else // si la recherche indique que l'idEtud n'est pas présent mais qu'il en existe un supérieur
	{
		printf("\n\nidEtudiant manquant dans la structure; insertion ...\n\n");
		for(i=*nb ; i>=res ; i--)
			tab[i+1]=tab[i];

		tab[res]=(Etudiant*)malloc(sizeof(Etudiant));  // on aloue un espace de type pointeur sur des étudiants pour poursuivre l'insertion
		if (tab[res]==NULL)
		{
			printf("Problème de malloc pour l'espace de l'étudiant\n");
			exit(1);
		}

		*tab[res]=e;  // affectation de l'étudiant à l'espace créé
		*nb=*nb+1;
	}
	return tab; // on retourne le tableau modifié
}


/*
Fonction : Affichage du menu.
Auteur : Loup RUSAK
Finalité : Affiche les options disponibles pour le menu des Etudiants. */
void afficherMenuEtud(void)
{
	printf("\n\nVous êtes dans le menu de traitement des Etudiants, que souhaitez vous faire ?\n\n");
	printf("\t1) Afficher le tableau des Etudiants.\n\t2) Rechercher un Etudiant.\n\t3) Insérer un nouvel Etudiant.\n\n\t4) Sauvegarder les modifications dans le fichier.\n\t5) QUITTER\n\n");
	printf("Entrez votre réponse svp : ");
}


/*
Fonction : Saisie d'un Etudiant.
Auteur : Loup RUSAK
Finalité : Demande à l'utilisateur de saisir un étudiant. */
Etudiant saisieEtudiant(void)
{
	Etudiant nouv;
	printf("\nEntrez un nouvel étudiant (id civilite nom prenom boursier handicap): ");
	scanf("%d %s %s %s %s %s",&nouv.idEtud, nouv.civilite, nouv.nom, nouv.prenom, nouv.bourse, nouv.handicap);
	if(strcmp(nouv.bourse,"oui")==0)
	{
		printf("L'étudiant est boursier veuillez entrer l'échellon de sa bourse: ");
		scanf("%d",&nouv.echellonBourse);
	}
	return nouv;
}


/*
Fonction : Menu Etudiant.
Auteur : Loup RUSAK 
Finalité : Menu général pour les Etudiants. */
Etudiant** menuEtudiant(Etudiant **tab, int *nb, int *max)
{
	int reponse;

	afficherMenuEtud();
	scanf("%d",&reponse);

	while(reponse!=5)
	{
		if(reponse == 1)
		{
			printf("\n\nAffichage du tableau des Etudiants ...\n\n");
			afficherTabEtud(tab,*nb);
		}
		if(reponse == 2)
		{
			Etudiant e;
			int recherche;
			printf("\n\nRecherche d'un Etudiant ...\n\n");
			e=saisieEtudiant();
			recherche=rechercherEtudiant(tab, *nb, e);
			if (recherche == -1)
				printf("\n\nidEtudiant présent dans le tableau !\n\n");
			else printf("\n\nidEtudiant introuvable !\n\n");
		}
		if(reponse == 3)
		{
			Etudiant e;
			int a;
			printf("\n\nInsertion d'un Etudiant ...\n\n");
			e=saisieEtudiant();
			tab=insertionEtudiant(tab, nb, max, e);
			printf("Souhaitez vous réafficher le tableau ? (1/0): ");
			scanf("%d", &a);
			if(a==1)
				afficherTabEtud(tab,*nb);
		}
		if(reponse == 4)// si il veut sauvegarder les modifications sur le fichier
		{
			printf("\n\nSauvegarde ...\n\n");
			FILE *flot; // ouverture du fichier d'origine en mode écriture
			flot=fopen("etudiants.txt","w");
			if(flot==NULL)
			{
				printf("Erreur d'ouverture du fichier en mode écriture pour sauvegarde !\n");
				exit(1);
			}
			sauvegardeEtudiant(flot, tab, *nb);
			printf("Sauvegarde réussie !\n");
			fclose(flot);
		}
		afficherMenuEtud();
		scanf("%d",&reponse);
	}
	return tab;
}


/*
Fonction : Sauvegarde des Etudiants.
Auteur : Loup RUSAK & Max MANIN & Manoah LEVY-VALENSI & Vincent VIALETTE.
Finalité : Sauvegarde des étudiants dans le fichier d'origine après insertion */
void sauvegardeEtudiant(FILE *flot, Etudiant **tab, int nb)
{
	int i;
	for(i=0 ; i<nb ; i++)
	{
		fprintf(flot,"%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s",tab[i]->idEtud, tab[i]->civilite, tab[i]->nom, tab[i]->prenom, tab[i]->bourse, tab[i]->handicap);// écriture de l'étudiant dans le fichier
		if(strcmp(tab[i]->bourse,"oui")==0) // si l'étudiant est boursier on rajoute au fichier l'échellon de sa bourse
			fprintf(flot,"\t\t%d",tab[i]->echellonBourse);
		fprintf(flot,"\n");
	}
}




/***************************************************************************************************************************************************************************

***************************************************************************************************************************************************************************/



/*
programme : chargeLog
auteur : Manoah Levy-Valensi 
finalite : Fonction de chargement des logements dans un tableau de pointeurs.
*/

Logement** chargeLog(FILE *fic,int *nb, int *max)
{
	Logement **tab,**aux,a;												//On déclare nos deux tableaux de pointeurs sur des structure de type "Logement" et un type "Logement"
	*nb=0;
	*max=5;
	tab=(Logement**)malloc(*max *sizeof(Logement*));					//On alloue un espace en mémoire au premier tableau
	if(tab==NULL)															//Message d'erreur si l'allocation de la mémoire a échouée
	{
		printf("Problème de malloc.\n");
		exit (1);
	}
	a=lireLog(fic);														//On lit un premier type "Logement"
	while(!feof(fic))														//Début de la boucle "while" qui va répeter son contenu jusqu'à la fin du fichier
	{
		if(*nb==*max)															//Si le nombre de pointeurs présents dans le tableau est égale à la taille maximale du tableau
		{
			aux=(Logement**)realloc(tab,(*max+5)*sizeof(Logement*));			//On ré alloue un espace en mémoire de "max+5" à notre deuxième tableau
			if(aux==NULL)															//Message d'erreur si l'allocation de la mémoire a échouée
			{
				printf("Problème de realloc.\n");
				exit (1);
			}
			tab=aux;																//Le premier tableau devient le deuxième
			*max=*max+5;															//On signifie que notre taille maximale a augmentée de "5"
		}
		tab[*nb]=(Logement*)malloc(sizeof(Logement));						//On alloue un espace en mémoire au deuxième tableau
		if(tab[*nb]==NULL)														//Message d'erreur si l'allocation de la mémoire a échouée
		{
			printf("Problème de malloc.\n");
			exit (1);
		}
		*tab[*nb]=a;														//On place le type "Logement" lu précédemment à la dernière position du tableau
		*nb=*nb+1;															//On signifie que la taille logique de notre tableau a augmentée de "1"
		a=lireLog(fic);														//On lit un nouveau type "Logement"
	}
	return tab;															//On retourne le tableau qui a été remplit
}

/*
programme : lireLog
auteur : Manoah Levy-Valensi 
finalite : Retourne un Logement à partir d'un fichier.
*/

Logement lireLog(FILE *fic)
{
	Logement l;																			//On crée un type "Logement"
	fscanf(fic,"%d%s%s%s%s",&l.idLogement,l.nomCite,l.typeLog,l.dispo,l.handicap);		//On lui donne les 5 premiers composants du type "logement"
	if (strcmp(l.dispo,"non")==0)															//Si le logement est disponible
		fscanf(fic,"%d",&l.idEtud);																//On lui donne le 6ème composant
	return l;																			//on retourne donc le type "Logement" lu
}

/*
programme : afficheLog
auteur : Manoah Levy-Valensi 
finalite : Affiche le logement qu'on lui a apporté.
*/

void afficheLog(Logement l)
{
    int i=0;												//On déclare un type "entier" "i"
    printf("%d\t%s", l.idLogement,l.nomCite);				//On affiche les deux premiers composants du type "Logement" passé par la fonction appelante
    i=strlen(l.nomCite);									//On affecte à "i" la taille du 3ème composant du type "Logement"
    i=i/4;													//On le divise par 4 (taille d'une tabulation)
    if(i==0)													//Si le nom de la cité fait entre 12 et 16 caractères minimum
        i=i+1;														//On met "i" à 1
    while(i<4)													//Tant que "i" est inférieur à 4 (le maximum de tabulations prit en compte par le programme)
    {
        printf("\t");												//On écrit une tabulation
        i=i+1;														//On incrémente "i"
    }
    printf("%s\t\t%s\t%s",l.typeLog,l.dispo,l.handicap);	//On affiche les 3 composants suivants du type "Logement" de la fonction appelante
    if(strcmp(l.dispo,"non")==0)								//Si le logement est disponible
        printf("\t%d",l.idEtud);									//On affiche le dernier composant du type "Logement"
    printf("\n");											//On revient à la ligne
}

/*
programme : afficheTabLog
auteur : Manoah Levy-Valensi 
finalite : Affiche un tableau de Logements dans l'ordre.
*/

void afficheTabLog(Logement **tab, int nb)
{
    int i=0;				//On déclare un type "entier" "i" égale à "0"
    Logement l;				//On déclare un type "Logement" "l"
    while(i!=nb)				//Tant que "i" est différent de "nb" 'entier passé par la fonction appelante'
    {
        l=*tab[i];					//"l" prends les valeur du "i"ème type "Logement" du tableau passé par la fonction appelante
        afficheLog(l);				//On appelle la fonction "afficheLog" pour afficher le "i"ème type "Logement"
        i=i+1;						//On incrément "i"
    }
}

/*
programme : afficheTabLogOccupe
auteur : Manoah Levy-Valensi 
finalite : Afficher les logements déjà occupés par un étudiant en le mentionnant.
*/

void afficheTabLogOccupe(Logement **tab,int nb)
{
	int i=0,j=0;																						//On déclare deux type "entier" "i" et "j" égale à "0"
	Logement l;																							//On déclare un type "Logement" "l"
	printf("ID Logement - Nom Cité\t-\tType - Disponibilité - Accès Handicapés - ID Etudiant\n\n");
	while(i!=nb)																							//Tant que "i" est différent de "nb" 'entier passé par la fonction appelante
	{
		l=*tab[i];																								//"l" prends les valeur du "i"ème type "Logement" du tableau passé par la fonction appelante
		if(strcmp(l.dispo,"non")==0)																				//Si le logement n'est pas disponible
		{
			afficheLog(l);																								//On appelle la fonction "afficheLog" pour afficher le "i"ème type "Logement"
			j=j+1;																										//On incrément "j"
		}
		i=i+1;																										//On incrément "i"
	}
	printf("\nIl y a donc %d logements occupés sur %d.\n\n",j,nb);										//Petit message qui conclut sur le nombre de logements occupés
}

/*
programme : afficheTabLogOccupe
auteur : Manoah Levy-Valensi 
finalite : Afficher les logements déjà occupés par un étudiant en le mentionnant.
*/

void afficheTabLogLibre(Logement **tab,int nb)
{
	int i=0,j=0;																						//On déclare deux type "entier" "i" et "j" égale à "0"
	Logement l;																							//On déclare un type "Logement" "l"
	printf("ID Logement - Nom Cité\t-\tType - Disponibilité - Accès Handicapés - ID Etudiant\n\n");
	while(i!=nb)																							//Tant que "i" est différent de "nb" 'entier passé par la fonction appelante
	{
		l=*tab[i];																								//"l" prends les valeur du "i"ème type "Logement" du tableau passé par la fonction appelante
		if(strcmp(l.dispo,"oui")==0)																				//Si le logement est disponible
		{
			afficheLog(l);																								//On appelle la fonction "afficheLog" pour afficher le "i"ème type "Logement"
			j=j+1;																										//On incrément "j"
		}
		i=i+1;																										//On incrément "i"
	}
	printf("\nIl y a donc %d logements libres sur %d.\n\n",j,nb);										//Petit message qui conclut sur le nombre de logements libres
}

/*
programme : triFusionCiteTabLog
auteur : Manoah Levy-Valensi 
finalite : Trie un tableau de pointeurs sur des Logements dans l'ordre des nom de Cités.
*/

void triFusionCiteTabLog(Logement *tab[],int nb)
{
	Logement **r,**s;									//On déclare nos deux tableaux de pointeurs sur des structure de type "Logement" et un type "Logement"
	if(nb==1)												//Si le tableau est de taille logique 1 on renvoie le tableau ainsi
		return;
	r=(Logement**)malloc((nb/2)*sizeof(Logement*));		//On alloue un espace (la moitié du tableau passé par la fonction appelante) en mémoire au premier tableau
	s=(Logement**)malloc((nb/2)*sizeof(Logement*));		//On alloue un espace (la moitié du tableau passé par la fonction appelante) en mémoire au deuxième tableau
	if(r==NULL || s==NULL)									//Message d'erreur si l'une des deux allocation de mémoire n'a pas fonctionnée ou les deux
	{
		printf("Problème de malloc.\n");
		return;
	}
	copie(tab,0,nb/2,r);								//On appelle la fonction "copie" pour copier la première moitié de tableau "tab" dans le tableau "r"
	copie(tab,nb/2,nb,s);								//On appelle la fonction "copie" pour copier la deuxième moitié de tableau "tab" dans le tableau "s"
	triFusionCiteTabLog(r,nb/2);						//On appelle la fonction "triFusionCiteTabLog" pour recommencer cette fonction jusqu'à avoir un tableau "r" d'un pointeur
	triFusionCiteTabLog(s,nb-nb/2);						//On appelle la fonction "triFusionCiteTabLog" pour recommencer cette fonction jusqu'à avoir un tableau "s" d'un pointeur
	fusion(r,nb/2,s,nb-(nb/2),tab);						//On appelle la fonction "fusion" pour envoie nos tableaux d'un pointeurs pour les ramener dans l'ordre alphabétique du nom de la Cité
	free(r);											//On libère l'espace allouer pour le tableau "r"
	free(s);											//On libère l'espace allouer pour le tableau "s"
}

/*
programme : copie
auteur : Manoah Levy-Valensi 
finalite : Copie le premier tableau dans le deuxième.
*/

void copie(Logement *tab[],int i,int j, Logement *r[])
{
	int k=0;				//On déclare un type "entier" "k" égale à "0"
	while(i<j)					//Tant que "i" (au départ : début du demi-tableau) est différetn de "j" (fin du demi-tableau)
	{
		r[k]=tab[i];				//On copie le "i"ème élément du tableau complet dans le "k"ème élement du demi-tableau
		i=i+1;						//On incrément "i" (on parcour le demi-tableau)
		k=k+1;						//On incrément "k" (on parcour le demi-tableau)
	}
}

/*
programme : fusion
auteur : Manoah Levy-Valensi 
finalite : Assemble deux tableaux de taille logique "1" dans l'ordre alphabetique du nom de la Cité.
*/

void fusion(Logement *r[],int n,Logement *s[],int m,Logement *tab[])
{
	int i=0,j=0,k=0;									//On déclare un type "entier" "i","j" et "k" égale à "0"
	while(i<n && j<m)										//Tant que "i"<"n" (taille logique du premier tableau passé par la fonction appelante) et "j"<"m" (taille logique du deuxième tableau passé par la fonction appelante)
	{
		if(strcmp(r[i]->nomCite,s[j]->nomCite)<0)				//Si le premier nom de cité du premier tableau est (alphabetiquement) inférieur au premier nom de cité du deuxième tableau
		{
			tab[k]=r[i];											//C'est le premier qu'on place en "i"ème place du tableau complet
			i=i+1;													//On incrémente "i"
			k=k+1;													//On incrémente "k"
		}
		else													//Sinon
		{
			tab[k]=s[j];											//C'est le second qu'on place en "i"ème place du tableau complet
			k=k+1;													//On incrémente "i"
			j=j+1;													//On incrémente "k"
		}
	}
	while(i<n)												//Tant qu'il reste des cases non utilisées dans le premier tableau
	{
		tab[k]=r[i];											//On le place en "i"ème place du tableau complet
		i=i+1;													//On incrémente "i"
		k=k+1;													//On incrémente "k"
	}
	while(j<n)												//Tant qu'il reste des cases non utilisées dans le deuxième tableau
	{
		tab[k]=s[j];											//On le place en "i"ème place du tableau complet
		j=j+1;													//On incrémente "i"
		k=k+1;													//On incrémente "k"
	}
}

/*
Fonction : Sauvegarde des Logements.
Auteur : Manoah LEVY-VALENSI
Finalité : Sauvegarde des logements dans le fichier d'origine.
*/

void sauvegardeLog(FILE *fic, Logement **tab, int nb)
{
	int i=0;																																//On déclare un type "entier" "i" égale à "0"
	while(i<nb)																																	//Pour chaque Logement du tableau
	{
		fprintf(fic,"%d\t\t%s\t\t%s\t\t%s\t\t%s",tab[i]->idLogement, tab[i]->nomCite, tab[i]->typeLog, tab[i]->dispo, tab[i]->handicap);			//On écrit les 5 premiers composants d'un type "Logement" dans le fichier
		if(strcmp(tab[i]->dispo,"non")==0) 																												//Si le logement n'est pas disponible on rajoute au fichier le dernier composant du type "Logement"
			fprintf(fic,"\t\t%d",tab[i]->idEtud);																											//On l'écrit dans le fichier
		fprintf(fic,"\n");																															//On revient à la ligne dans le fichier (fin de l'écriture d'un logement)
		i=i+1;																																		//On incrémente "i"
	}
}

/*
programme : rechercheIdLog
auteur : Manoah Levy-Valensi 
finalite : Demande à lutilisateur le logement qu'il souhaite libérer, vérifie son existence et retourne sa position dans le tableau.
*/

int rechercheIdLog(int *idtemp,Logement **tab,int *nb)
{
	int j=0;																										//On déclare un type "entier" j" égale à "0"
	printf("\nSaisissez l'identifiant du logement que vous souhaitez libérer : ");									//Message à detination de l'utilisateur
	scanf("%d",idtemp);																								//On saisit le logement à libérer choisit par l'utilisateur
	while(j==0)																											//Tant que "j"=0 (boucle infinie)
	{
		while(j!=*nb)																										//On parcours tout le tableau pour chercher le rang du logement sélectionner par l'utilisateur
		{
			if(tab[j]->idLogement==*idtemp)																							//On teste chaque rang pour savoir si c'est celui que nous a désigné l'utilisateur
				return j;																												//Si oui on retourne le rang trouvé
			j=j+1;																													//Sinon on incrémente "J"
		}
		printf("\nL'identifiant saisit n'éxiste pas, re tapez (0 si vous sohaitez annuler) le nouvel identifiant : ");			//Message à destnation de l'utilisateur
		scanf("%d",idtemp);																										//On saisit le nouvel identifiant à rechercher
		if (*idtemp==0)																												//Si l'utilisateur veut effectuer un retour en arrière
			return -1;																													//On retourne la valeur "-1"
		j=0;																													//On réinitialise "j" (ce qui rend la boucle infinie)
	}
}

/*
programme : libererLog
auteur : Manoah Levy-Valensi 
finalite : Récupère le logement à libérer et le libère si nécessaire.
*/

void libererLog(int *idtemp,Logement **tab,int u)
{
	if(strcmp(tab[u]->dispo,"oui")==0)						//On vérifie si le logement indiqué par l'utilisateur est déjà libre
	{
		printf("\nCe logement est déjà libre.\n");				//Si c'est le cas on le lui indique
		return;													//Et on termine la fonction
	}
	if(strcmp(tab[u]->dispo,"non")==0)						//Si le logement indiqué par l'utilisateur n'est pas libre
	{
		strcpy(tab[u]->dispo,"oui");							//On met à jour le tableau pour indique que le logement est libre
		tab[u]->idEtud=0;										//On réinitialise l'identifiant de l'étudiant qui occupait le logement
		printf("\nLe logement a bien été libéré.\n");			//Message à destination de l'utilisateur
	}
}

/*
programme : menuLog
auteur : Manoah Levy-Valensi 
finalite : Affiche un menu textuel et retourne le choix de l'utilisateur.
*/

int menuLog(int *test)
{
	int menu;																		//On déclare un type "entier" "menu"
	printf("\nMenu des logements :\n");												//Début du menu textuel-->
	if(*test==0)																			//Si on a jamais charger un fichier, alors on affiche le petit menu
	{
		printf("\n\t1. Utiliser les données du fichier de base : 'logement.don'."); 
		printf("\n\t2. Utiliser les données du fichier de votre choix.");
	}
	if(*test==1)																			//Si on a déjà charger un fichier alors on peut avoir accès au choix de la sauvegarde
	{
		printf("\n\t1. Charger un nouveau fichier et abandonner les modifications en cours.");
		printf("\n\t2. Trier les logements selon le nom de la cité.");
		printf("\n\t3. Afficher les logements.");
		printf("\n\t4. Afficher les logements occupés.");
		printf("\n\t5. Afficher les logements libres.");
		printf("\n\t6. Libérer un logement.");
		printf("\n\t7. Sauvegarder les valeurs dans le fichier");
	}
	printf("\n\t0. Quitter\n");
	printf("\nSelectionnez une option :  ");										//-->Fin du menu textuel
	scanf("%d", &menu);																//On récupère le choix de l'utilisateur
	if(*test==0)																		//Si on a jamais charger un fichier, alors on a que 3 option (de 0 à 2)
	{
		while (menu>2 || menu<0)																//Tant que le choix n'est pas pris en compte par la suite du programme (option non existante)
		{
			printf("\nErreur : Reselectionnez une option :  ");										//Message qui demande à l'utilisateur de re saisir une option
			scanf("%d", &menu);																		//On scan le choix de l'utilisateur
		}
		printf("\n**\n\n");																	//On affiche une séparation avec des "*" et des retours à la ligne
	}
	if(*test==1)																		//Si on a déjà charger un fichier, alors on a 8 options (de 0 à 7)
	{
		while (menu>7 || menu<0)																//Tant que le choix n'est pas pris en compte par la suite du programme (option non existante)
		{
			printf("\nErreur : Reselectionnez une option :  ");										//Message qui demande à l'utilisateur de re saisir une option
			scanf("%d", &menu);																		//On scan le choix de l'utilisateur
		}
		printf("\n**\n\n");																	//On affiche une séparation avec des "*" et des retours à la ligne
	}
	return menu;																	//On retourne la valeur de "menu"
}




/***************************************************************************************************************************************************************************

***************************************************************************************************************************************************************************/

/*
Fonction : Recherche des Etudiants.
Auteur : Vincent Vialette 
Finalité : Afficher le menu des gestions.
*/
int menuGestion (){
	int menu=0;	
	printf("\nMenu :\n");												// affiche les posibilitées du menu principale
	printf("\t 1. Attribution des logements grâce à l'identifiant d'une demande \n");																
	printf("\t 2. Attribution des logements grâce à l'identifiant d'un étudiant \n");															
	printf("\t 0. Quitter\n");													
	printf("\nSelectionnez une option :  ");	
	scanf("%d",&menu);		// lecture du choix de l'utilisateur
	while (menu>4 || menu<0){		// on verifie que le choix existe 
		printf("\nErreur lors du choix veuillez resaissir une option :\t");		// si le choix n'existe pas on redemande à l'utilisateur de faire son choix
		scanf("%d",&menu);		
	}
	printf("\n************************************************************************\n"); 	// affiche un ligne pour simplifier la lecture
	return menu;	// on retourn le choix pour permettre à la fonction : menu d'executer le choix de l'utilisateur 
}

/*
Fonction : Recherche des Etudiants.
Auteur : Vincent Vialette 
Finalité : Attribution d'un logement à un étudiant qui en avait fait la demande grâce à l'identitée de la demande.
*/
void gestionViaDem(Liste LDem, Etudiant **tabe, Logement **tabl ,int  nbe, int nbl){
	int a, i=0, j=0, affect, eff=0;
	Demandes d;
	printf("Saisir l'identifiant d'une demande :\t");	// on demande à l'utilisateur l'id de la demande à traité
	scanf("%d", &a);	// on récupère la réponse
	while (trouveID(LDem, a)==0){	// on regarde si le demande existe 
		printf("L'identifiant n'existe pas. Veuillez resaissir :\t");	// si elle n'existe pas on la redemande 
		scanf("%d", &a);	// on la resaisie
	}
	d=initialiseDem(LDem, a);	// on enregiste la demande dans d correspondant à l'id donné
	while (i!=nbl){		// on partours le tableau des logements 
		if (strcmp(tabl[i]->nomCite,d.nomCiteD)==0 && strcmp(tabl[i]->typeLog,d.typeLogD)==0 && strcmp(tabl[i]->dispo,"oui")==0){	// on regarde si le logement correspond à la demande 
			while (j!=nbe){		// si c'est le cas  on parcours le tableau des etudiants 
				if(strcmp(tabl[i]->handicap,tabe[j]->handicap)==0){		// on regarde si il est utilisable par des personnes handicapées 
					eff=1;	// on dit qu'un logement à été trouvé
					printf("l'etudiant %d ayant fait la demande %d peut être attribué au logement %d\n", d.idEtudD, d.idDemande, tabl[i]->idLogement); 	// on informe l'utilisateur 
					printf("Voullez vous que le logement soit attribué à l'étudiant ? ( 1:oui / 0:non)\t");		// on lui demande si il veut affecter le logement à l'etudiant 
					scanf("%d", &affect);	// on lit sa réponse
					if (affect==1){	  // si il accepte on : 
						strcpy(tabl[i]->dispo,"non");	// met la dispo à non 
						tabl[i]->idEtud=d.idEtudD;	// on met l'idEtud = à l'idEtudD
						LDem=supprimerDansListe(LDem,a);
						printf("le logement à été attribué");
					}
					return; // on quitte la fonction 
				}
				j++;	// on passe à la prochaine case du tableau
			}
		}
		i++;	// on passe à la prochaine case du tableau
	}
	if (eff==0){
		printf("\nIl n'y a pas de logements à affecter à cette demande.\n");	//	on informe l'utilisateur
	}
}

/*
Fonction : Recherche des Etudiants.
Auteur : Vincent Vialette 
Finalité : Initialiser une demande en fonction de l'idDemande
*/
Demandes initialiseDem(Liste LDem, int s){
	Demandes a;
	while (LDem != NULL){	// on regarde si la liste est vide 
		if (LDem->l.idDemande == s){ 		// si notre id demande est la meme que sur la liste on :
			a=LDem->l;	// met notre demande égale à la demande de la liste 
		}
		LDem=LDem->next;		// on passe à la demande suivante
	}
	return a;	// on retourne notre demande 
}

/*
Fonction : Recherche des Etudiants.
Auteur : Vincent Vialette 
Finalité : Attribution d'un logement à un étudiant grâce à son identifiant.
*/
void gestionViaEtu(Liste LDem, Etudiant **tabe, Logement **tabl ,int  nbe, int nbl){
	int a, i=0, j=0, affect, eff=0;
	Demandes d;
	printf("Saisir l'identifiant d'un étudiant :\t");	// on demande à l'utilisateur l'id de la demande à traité
	scanf("%d", &a);		// on récupère la réponse
	d=initialiseDem2(LDem, a);	// on enregiste la demande dans d correspondant à l'id donné
	while (i!=nbl){		// on partours le tableau des logements 
		if (strcmp(tabl[i]->nomCite,d.nomCiteD)==0 && strcmp(tabl[i]->typeLog,d.typeLogD)==0 && strcmp(tabl[i]->dispo,"oui")==0){	// on regarde si le logement correspond à la demande 
			while (j!=nbe){		// si c'est le cas  on parcours le tableau des etudiants 
				if(strcmp(tabl[i]->handicap,tabe[j]->handicap)==0){		// on regarde si il est utilisable par des personnes handicapées 
					eff=1;	// on dit qu'un logement à été trouvé
					printf("l'etudiant %d ayant fait la demande %d peut être attribué au logement %d\n", d.idEtudD, d.idDemande, tabl[i]->idLogement); 	// on informe l'utilisateur 
					printf("\nVoullez vous que le logement soit attribué à l'étudiant ? ( 1:oui / 0:non)\t");		// on lui demande si il veut affecter le logement à l'etudiant 
					scanf("%d", &affect);	// on lit sa réponse
					if (affect==1){	  // si il accepte on : 
						strcpy(tabl[i]->dispo,"non");	// met la dispo à non 
						tabl[i]->idEtud=d.idEtudD;	// on met l'idEtud = à l'idEtudD
						LDem=supprimerDansListe(LDem,a);
						printf("le logement à été attribué");
					}
					return; // on quitte la fonction 
				}
				j++;	// on passe à la prochaine case du tableau
			}
		}
		i++;	// on passe à la prochaine case du tableau
	}
	if (eff==0){
		printf("\nIl n'y a pas de logements à affecter à cette demande.\n");	//	on informe l'utilisateur
	}
}

/*
Fonction : Recherche des Etudiants.
Auteur : Vincent Vialette 
Finalité : Initialiser une demande en fonction de l'idEtudD
*/
Demandes initialiseDem2(Liste LDem, int s){
	Demandes a;
	while (LDem != NULL){	// on regarde si la liste est vide 
		if (LDem->l.idEtudD == s){ 		// on regarde si notre id etudiant est le meme quand dans la liste 
			a=LDem->l;	// met notre demande égale à la demande de la liste 
		}
		LDem=LDem->next;		// on passe à la demande suivante
	}
	return a;	// on retourne notre demande 
}