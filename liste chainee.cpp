//ecrire un code qui permet d'ajouter 5 variables de type structure t dans l'espace memoire
//supprimer les éléments ayant une température de 20 de la liste chaînée. 
//libèrer la mémoire allouée dynamiquement pour chaque élément de la liste.

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
	
	// Lecture de la date et de la température pour la première structure
		printf("donner la date\n");
		gets(p->date);
		printf("donner la temperature\n");
		scanf("%f",&p->temp);
		 
		
	// Initialisation de p2 pour qu'il pointe vers la même adresse que p
    p2 = p;
    
    // Boucle pour ajouter 5 autres variables de type structure t à la liste chaînée
		for(int i=0;i<5;i++) {
			// Allocation dynamique de mémoire pour la structure suivante
			p2->next=(t*)malloc (sizeof (t));
			printf("donner la date\n");
			gets(p2->date);
			printf("donner la temperature\n");
			scanf("%f",&p2->temp);
			
			// Avancer p2 vers la structure suivante
        	p2 = p2->next;
		}
	
	
	// Supprimer les éléments ayant une température de 20 de la liste chaînée
    p2 = p; // Initialisation de p2 pour qu'il pointe vers le début de la liste
    t* p3 = NULL; // Pointeur vers le précédent élément

    while (p2 != NULL) {
        if (p2->temperature == 20) {
            if (p3 == NULL) {
                // Si p2 est le premier élément de la liste
                p = p->next;
                free(p2);
                p2 = p;
            } else {
                // Si p2 n'est pas le premier élément de la liste
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

	// Libérer la mémoire allouée pour chaque élément de la liste
    p2 = p;
    while (p2 != NULL) {
        p = p2->next; // Avancer p vers la structure suivante
        free(p2); // Libérer la mémoire allouée pour p2
        p2 = p; // Mettre à jour p2 avec la structure suivante
    }
		
		
	return 0;
}
