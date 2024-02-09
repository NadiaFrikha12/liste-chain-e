//ecrire un code qui permet d'ajouter 5 variables de type structure t dans l'espace memoire
//supprimer les �l�ments ayant une temp�rature de 20 de la liste cha�n�e. 
//lib�rer la m�moire allou�e dynamiquement pour chaque �l�ment de la liste.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct t {
	char date [100];
	float temperature;
	struct t* next;
};
typedef struct t t;

int main(){
	t *p;
	//allocation dynamique de la memoire 
	p=(t*) malloc (sizeof (t ));
	//verifier si le pointeur est null 
	if (p==NULL){
		printf("erreur");
		return 0;
	}
	
	// Lecture de la date et de la temp�rature pour la premi�re structure
		printf("donner la date\n");
		gets(p->date);
		printf("donner la temperature\n");
		scanf("%f",&p->temp);
		 
		
	// Initialisation de p2 pour qu'il pointe vers la m�me adresse que p
    p2 = p;
    
    // Boucle pour ajouter 5 autres variables de type structure t � la liste cha�n�e
		for(int i=0;i<5;i++) {
			// Allocation dynamique de m�moire pour la structure suivante
			p2->next=(t*)malloc (sizeof (t));
			printf("donner la date\n");
			gets(p2->date);
			printf("donner la temperature\n");
			scanf("%f",&p2->temp);
			
			// Avancer p2 vers la structure suivante
        	p2 = p2->next;
		}
	
	
	// Supprimer les �l�ments ayant une temp�rature de 20 de la liste cha�n�e
    p2 = p; // Initialisation de p2 pour qu'il pointe vers le d�but de la liste
    t* p3 = NULL; // Pointeur vers le pr�c�dent �l�ment

    while (p2 != NULL) {
        if (p2->temperature == 20) {
            if (p3 == NULL) {
                // Si p2 est le premier �l�ment de la liste
                p = p->next;
                free(p2);
                p2 = p;
            } else {
                // Si p2 n'est pas le premier �l�ment de la liste
                p3->next = p2->next;
                free(p2);
                p2 = p3->next;
            }
        } else {
            // Avancer p2 et p3
            p3 = p2;
            p2 = p2->next;
        }
    }

	// Lib�rer la m�moire allou�e pour chaque �l�ment de la liste
    p2 = p;
    while (p2 != NULL) {
        p = p2->next; // Avancer p vers la structure suivante
        free(p2); // Lib�rer la m�moire allou�e pour p2
        p2 = p; // Mettre � jour p2 avec la structure suivante
    }
		
		
	return 0;
}
