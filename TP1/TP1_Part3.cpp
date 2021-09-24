#include <cstdio>
#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <stdlib.h>
#define N 5
using namespace std;

/**
 * \fn void bonjour ();
 * \brief fonction demandant le nom et prénom de l'utilisateur puis le salue en réutilisant son nom prénom sous le format suivant : Ines ABBES
 */
void bonjour (){
        string prenom("");
        string nom("");
        cout << "Quel est votre prénom et votre nom de famille ?" << endl;
        cin >> prenom >> nom;

        //PARTIE PRENOM 
        if (prenom[0] > 96 && prenom[0] < 123)
                prenom[0] -= 'a' - 'A';
        for (int i = 1; prenom[i] != '\0'; i++){
                if(prenom[i] > 64 && prenom[i] < 91) //si maj alors minuscule
                        prenom[i] += 'a' - 'A';
        }
        
        //PARTIE NOM
        for (int i = 0; nom[i] != '\0'; i++){
                if(nom[i] > 96 && nom[i] < 123) //si minuscule alors majuscule 
                        nom[i] -= 'a' - 'A';
        }


        cout << "Bonjour "+ prenom + " " + nom << endl;
}

//2.1 et 2.2
/**
 * \fn void guess ();
 * \brief fonction faisant deviner à l'utilisateur un nombre aléatoire  
 */
void guess (){
        srand(time(NULL)); // pour initialiser le générateur de nombre pseudo aléatoire
        int toGuess = rand()%1001; // % Reste de la division entière
        int userGuessing = 0;
        //printf("%d\n",toGuess);
        cout << "Devinez le nombre." << endl;
        cin >> userGuessing;
        int compteur = 1;
        while(userGuessing != toGuess){
                if(userGuessing > toGuess) 
                        cout << "Le nombre à deviner est plus petit. Réessayez." << endl;

                if(userGuessing < toGuess) 
                        cout << "Le nombre à deviner est plus grand. Réessayez." << endl;

                compteur++;
                cin >> userGuessing;

        }

        cout << "Bravo, vous avez deviné en " << compteur << " tentatives" << endl;
        
}

//2.3 BONUS
/**
 * \fn void ordiDevineNombre ();
 * \brief fonction permettant à l'utilisateur de faire deviner un nombre à l'ordinateur  
 */

void ordiDevineNombre(){
        int indication;
        int inf  = 0;
        int sup = 1000;
        int recherche;
        bool gagne = false;

        cout << "Choisissez un nombre entre 0 et 1000, je vais essayer de le deviner. Tapez entrée quand vous serez prêt." << endl;
        getchar();

        while (!gagne){
                recherche = (inf+sup)/2;
                cout << "Laissez moi réfléchir... " << recherche << endl; 
                cout << "Choisissez une option : \nTapez 1 si j'ai trouvé le nombre à deviner \nTapez 2 si le nombre à deviner est plus petit \nTapez 3 si le nombre à deviner est plus grand" << endl;  
                cin >> indication; 

                switch (indication){
                case 1:
                        gagne = true;
                        break;
                case 2:
                        sup = recherche;
                        break;
                case 3:
                        inf = recherche++;
                        break;
                default:
                        cout << "Erreur" << endl;
                        exit(EXIT_FAILURE);
                }
  
        }

        cout << "J'ai trouvé ! Vous aviez choisi le nombre " << recherche << endl;

}

int main(int argc, char const *argv[]){

        ordiDevineNombre();
        printf("\n\n");
        bonjour();
        printf("\n\n");
        guess();
        
        
}
