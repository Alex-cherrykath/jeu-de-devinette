#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>   

#define MAX 03 // définit une taille maximale pour l'historique des essais


int main() {
    int nombre;  // le nombre que l'ordinateur va choisir
    int supposition; 
    int nbressais = 0;      
    int historique[MAX]; // tableau pour stocker l'historique des essais
    int i; 

   
    srand((unsigned int)time(NULL));

    // rand() % 100 donne un nombre entre 0 et 99. En ajoutant 1, on obtient entre 1 et 100
    nombre = (rand() % 100) + 1;

    printf("\n");
    printf("****Bienvenue au Jeu de Devinette****\n");
    printf("\n");
    printf("J'ai choisi un nombre entre 1 et 100.\n");
    printf("Essaie de le deviner !\n\n");

    do {
        printf("Quelle est ta proposition ? ");
        
        scanf("%d", &supposition);

        // stock la proposition dans l'historique
        historique[nbressais] = supposition;
        nbressais++; 
        if (supposition < nombre) {
            printf("Plus grand !\n");
        } else if (supposition > nombre) {
            printf("Plus petit !\n");
        } else {
            // si la supposition est correcte
            printf("\nFélicitations ! Tu as trouvé le nombre secret : %d\n", nombre);
            printf("Tu l'as trouvé en %d essais.\n\n", nbressais);
        }

    } while (supposition != nombre); // la boucle continue tant que le nombre n'est pas trouvé

    printf("Vos essais precedent sont: \n");
    for (i = 0; i < nbressais; i++) {
        printf("%d ", historique[i]);
    }
    printf("\n");

    return 0; 
}
