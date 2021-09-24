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
 * \fn void tennis (int J1, int J2);
 * \brief fonction permettant de déterminer le score en fonction du nombre d'échanges qui ont été remportés par chaque joueur.
 */
void tennis (int J1, int J2){
        string scoreJ1 = "0";
        string scoreJ2 = "0";
        string msgGagnantJ1 = "Joueur 1 gagne le jeu !";
        string msgGagnantJ2 = "Joueur 2 gagne le jeu !";
        int echangeTotal = somme(J1,J2);

        while(echangeTotal > 0 && scoreJ1 != msgGagnantJ1 && scoreJ2 != msgGagnantJ2){
                if (J1 > 0 && scoreJ1 == "0"){
                        scoreJ1 = "15";
                        J1--;
                }
                else if (J2 > 0 && scoreJ2 == "0"){
                        scoreJ2 = "15";
                        J2--;
                }
                else if (J1 > 0 && scoreJ1 == "15"){
                        scoreJ1 = "30";
                        J1--;
                }
                else if (J2 > 0 && scoreJ2 == "15"){
                        scoreJ2 = "30";
                        J2--;
                }
                else if (J1 > 0 && scoreJ1 == "30"){
                        if (scoreJ2 == "40"){
                                scoreJ1 = "40A";
                                scoreJ2 = "40A";
                        }
                        else 
                                scoreJ1 = "40";
                        J1--;
                }
                else if (J2 > 0 && scoreJ2 == "30"){
                        if (scoreJ1 == "40"){
                                scoreJ2 = "40A";
                                scoreJ1 = "40A";
                        }
                        else    
                                scoreJ2 = "40";
                        J2--;
                }
                else if (J1 > 0 && scoreJ1 == "40A"){
                        if (scoreJ2 == "AV"){
                                scoreJ1 = "40A";
                                scoreJ2 = "40A"; //retour à égalité
                        }
                        else{      
                                scoreJ1 = "AV"; // avantage 
                        }
                        J1--;
                }                
                else if (J2 > 0 && scoreJ2 == "40A"){
                        if (scoreJ1 == "AV"){
                                scoreJ1 = "40A";
                                scoreJ2 = "40A";
                        }
                        else{     
                                scoreJ2 = "AV"; // Egalité
                        }
                        J2--;
                }
                else if (J1 > 0 && ((scoreJ1 == "40") || (scoreJ1 == "AV"))){
                        scoreJ1 = msgGagnantJ1;
                }
                else if (J2 > 0 && ((scoreJ2 == "40") || (scoreJ2 == "AV"))){
                        scoreJ2 = msgGagnantJ2;
                }

                echangeTotal--;
        }

        cout << "------ Score ------\n Joueur 1 : "<< scoreJ1 << "\n Joueur 2 : "<< scoreJ2 << endl;
}

int main(int argc, char const *argv[]){

        int J1,J2;
        cout << "Entrez le nombre d'échange gagné par le joueur 1 puis le nombre d'échange gagné par le joueur 2." << endl;
        cin >> J1 >> J2;

        tennis(J1,J2);
        
        return 0;
}
