#include <cstdio>
#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <stdlib.h>
#define N 5
using namespace std;


/**
 * \fn int somme (int a, int b);
 * \brief fonction renvoyant la somme de deux nombres passés en paramètres
*/
int somme (int a, int b){
        return a+b;
}

/**
 * \fn void inverse (int a, int b);
 * \brief fonction inversant les valeurs des deux entiers passés en paramètres
 */
void inverse (int a, int b){
        int temp = a;
        a = b;
        b = temp;
}

/**
 * \fn void remplaceP (int *a, int *b, int *c);
 * \brief fonction remplaçant la valeur du troisième entier entré en paramètre par la somme des deux premiers entiers entrés en paramètre (version pointeur)
 */
void remplaceP (int *a, int *b, int *c){
        *c = somme(*a,*b);
}

/**
 * \fn void remplaceR (int &a, int &b, int &c);
 * \brief fonction remplaçant la valeur du troisième entier entré en paramètre par la somme des deux premiers entiers entrés en paramètre (version adresse)
 */
void remplaceR (int &a, int &b, int &c){
        c = somme (a, b);
}

/**
 * \fn int* newTab();
 * \brief fonction générant un tableau d'entiers rempli de valeurs aléatoires positives
 */
int* newTab (int taille){
        srand(time(NULL)); // pour initialiser le générateur de nombre pseudo aléatoire
        int *tab = NULL;
        tab = (int*) malloc(taille*sizeof(int));
        if (tab == NULL) 
                exit(-1);
       
        for (int i = 0; i < taille; i++){
                tab[i] = rand()%11; //valeur aléatoire entre 0 et 10
        }
        return tab;    

}

/**
 * \fn void afficheTab (int *tab);
 * \brief fonction affichant les valeurs successives du tableau passé en paramètre
 */
void afficheTab (int *tab, int taille){
        for (int i = 0; i < taille; i++){
              cout << tab[i] << '|';
        }
        printf("\n\n");
        
}

/**
 * \fn void echange (int *tab, int i, int j);
 * \brief fonction échangeant les valeurs aux positions i et j d'un tableau
 */
void echange (int *tab, int i, int j){
        int temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
}

/**
 * \fn void bubbleSort (int *tab, int taille)
 * \brief tri un tableau par ordre croissant 
 */
void bubbleSort (int *tab, int taille){
        int croissant;
        cout << "Tapez 1 si vous voulez trier votre tableau par ordre croissant, 0 si décroissant." << endl;
        cin >> croissant;

        if(croissant){
                for(int i = taille-1; i >= 0; i--){
                        for(int j = 0; j < i; j++){
                                if(tab[j] > tab[j+1])
                                        echange(tab, j, j+1);
                        }

                }
        }
        else{
                for(int i = taille-1; i >= 0; i--){
                        for(int j = 0; j < i; j++){
                                if(tab[j] < tab[j+1])
                                        echange(tab, j, j+1);
                        }

                }
        }
        afficheTab(tab, taille);
}

int main(int argc, char const *argv[]){

        int taille;
        cout << "Choisissez la taille du tableau." << endl;
        cin >> taille;
        printf("\n");
        
        int* tab = newTab(taille);
        afficheTab(tab, taille);
        bubbleSort(tab, taille);
        
        free(tab);
        return 0;
}
