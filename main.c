/* Oswin Freyr
PAYEBIEN P.
Jeu "Les petits Canassons */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define FacesDe 6
#define LT 3
#define CT 16
#define SV 1
#define SJ 18
int ageJ1;
int ageJ2;
int ResultatDe;
int Tabl[LT][CT] = {{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},{34,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17},{33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18}};
int PV1; int PV2; int PJ1; int PJ2; //initialise les pions des 2 joueurs
int joueur = 1; //initialisation d'un paramètre pour déterminer le joueur jouant ce tour ci
int NbpionJ = 0; //Initialisation du nombre de pions du joueur jaune
int NbpionV = 0; //Initialisation du nombre de pions du joueur jaune
int VJ = 0;//Initialisation de la victoire du joueur jaune
int VV = 0;//Initialisation de la victoire du joueur vert

//PROTOTYPES SOUS-PROGRAMMES

int AgeJ (); //Recuperation des ages de 2 joueurs
void couleur (int Ctexte, int Cfond); //Selection des couleurs voulues
void choixPremierJoueur (int ageJ1, int ageJ2); //Determine le premier joueur a commencer en fonction des ages des 2 joueurs
int LancerD (); //Permet de recuperer les resultats des lancers de dé des 2 joueurs
void Plateau(int Tabl[LT][CT]); //Affiche en tableau le plateau de jeu ainsi que les ecuries des 2 joueurs
int Deplacement(); //Permet le deplacement des pions des 2 joueurs

//PROGRAMME PRINCIPAL

int main()
{
    srand(time(NULL));
    printf("Bienvenue au jeu des Petits Canassons\n");
    Sleep(1000); //Impose un temps de pause avant l'execution
    printf("Age Joueur 1 :\n");
    scanf("%d",&ageJ1); //Recupere l age du premier joueur
    printf("Age Joueur 2 :\n");
    scanf("%d",&ageJ2); //Recupere l age du deuxieme joueur
    choixPremierJoueur(ageJ1, ageJ2);
    couleur(15,0); //Permet d inclure les couleurs necessaires dans le programme
    system("PAUSE");
    system("cls");
    Plateau(Tabl); //Affichage du plateau de jeu
    system("PAUSE");
    do //Boucle permettant de reiterer les fonctions du programme en alternant le tour des joueurs
    {
        if (joueur==1)
        {
            couleur(14,0); //Attribue la couleur jaune au joueur le plus jeune
            printf("Joueur jaune a vous de jouer\n");
        }
        else
        {
            couleur(2,0); //Attribue la couleur verte au joueur le plus vieux
            printf("Joueur vert a vous de jouer\n");
        }
        LancerD(); //Execute le lancer de de
        printf("Vous avez fait un %d\n", ResultatDe);
        int SP; //Initialise la case de sortie, depart des pions des 2 joueurs
        if (ResultatDe==6) //Possibilite de sortir un pion si le resultat du lancer de de est 6
        {
            if (joueur==1)
            {
                if (NbpionJ<2) //Condition sur le nombre de pion du joueur jaune
                {
                    printf("Sortir un pion ?\n 1-Oui\n 2-Non\n");
                    scanf("%d",&SP);
                    if (SP==1)
                    {
                        printf("Votre pion est sur la case 18\n");
                        NbpionJ++;
                        if (NbpionJ==1)
                            {
                                PJ1=SJ;
                            }
                            if (NbpionJ==2)
                            {
                                PJ2=SJ;
                            }
                    }
                }
            }
            if (joueur==0)
            {
               if (NbpionV<2) //Condition sur le nombre de pion du joueur vert
                {
                    printf("Sortir un pion ?\n 1-Oui\n 2-Non\n");
                    scanf("%d",&SP);
                    if (SP==1)
                    {
                        printf("Votre pion est sur la case 1\n");
                        NbpionV++;
                        if (NbpionV==1)
                            {
                                PV1=SV;
                            }
                            if (NbpionV==2)
                            {
                                PV2=SV;
                            }
                    }
                }
            }
        }
        if (joueur==1)
        {
            if (NbpionJ>=1)
            {
                Deplacement();
            }
        }
        if (joueur==0)
        {
            if (NbpionV>=1)
            {
                Deplacement();
            }
        }
        if (joueur==1) //Permet d intervertir les roles (tour d un joueur, puis de l autre)
        {
            joueur=0;
        }
        else
        {
            joueur=1;
        }
        if (PJ1==17)
        {
            VJ++;
            printf("Le pion 1 n'est plus en jeu");
        }
        if (PJ2==17)
        {
            VJ++;
            printf("Le pion 2 n'est plus en jeu");
        }
        if (PV1==34)
        {
            VV++;
            printf("Le pion 1 n'est plus en jeu");
        }
        if (PV2==34)
        {
            VV++;
            printf("Le pion 2 n'est plus en jeu");
        }
    }while (VJ!=2 && VV!=2); //condition de victoire pour sortir de la boucle
    return 0;
}

//DECLARATION DES SOUS-PROGRAMMES

void couleur (int Ctexte, int Cfond) //Permet d inclure au programme les couleurs souhaitees (ici noir blanc jaune vert)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, Cfond*16+Ctexte);
}

void choixPremierJoueur(int ageJ1, int ageJ2) //Attribue les couleurs en fonction de l age des 2 joueurs
{
    if (ageJ1<=ageJ2)
    {
        couleur(14,0); //Donne a J1 la couleur jaune
        printf("J1 vous commencez la partie avec les pions jaunes\n");
        couleur(2,0); //Donne a J2 la couleur verte
        printf("J2 vous avez les pions verts\n");

    }
    if (ageJ1>ageJ2)
    {
        couleur(14,0); //Donne a J2 la couleur jaune
        printf("J2 vous commencez la partie avec les pions jaunes\n");
        couleur(2,0); //Donne a J1 la couleur verte
        printf("J1 vous avez les pions verts\n");
    }
}

int LancerD() //Permet un lancer de dé avec duree du lancer et resultat aleatoires
{
    int Tmin = 1000; //Borne minimale sur l intervalle de temps du lancer
    int Tmax = 3000; //Borne maximale sur l intervalle de temps du lancer
    int attente=rand()%(Tmax-999) + Tmin;
    Sleep(attente);
    ResultatDe = rand()%FacesDe +1;
    return ResultatDe;
}

void Plateau(int Tabl[LT][CT]) //Permet d afficher le tableau de jeu ainsi que les ecuries des 2 joueurs en fonction des couleurs respectives
{
    couleur(2,0);
    printf(" -------\n|PV1 PV2|\n -------\n"); //Delimite les ecuries du joueur vert

    printf("\n");
    couleur(15,0);
    int i; int j;
    for(i=0; i<LT; i++) //Affichage du tableau
    {
        for(j=0; j<CT; j++)
        {
            if (Tabl[i][j]>9)
                printf(" %d |",Tabl[i][j]);
            if (Tabl[i][j]<10)
                printf("  %d |",Tabl[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    couleur(14,0);
    printf("\t\t\t\t\t\t\t\t\t -------\n\t\t\t\t\t\t\t\t\t|PJ1 PJ2|\n\t\t\t\t\t\t\t\t\t -------\n"); //Delimite les ecuries du joueur jaune
    printf("\n");
    couleur(15,0);
}

int Deplacement() //Permet le deplacement sur le plateau de jeu des pions de chaque joueur
{
    int reponse1;
    printf("Avez vous sorti un canasson ce tour ci?\n 1-Oui\n 2-Non\n");
    scanf("%d",&reponse1);
    if (reponse1==2)
    {
        int reponse2; int reponse3;
        if (joueur==1)
        {
            printf("Avez vous 2 pions de sortis ?\n 1-Oui\n 2-Non\n");
            scanf("%d",&reponse2);
            if (reponse2==1)
            {
                printf("Quel pion voulez vous jouer ?\n 1-Pion 1\n 2-Pion 2\n");
                scanf("%d",&reponse3);
                if (reponse3==1)
                {
                    PJ1=PJ1+LancerD();
                    printf("Votre pion 1 est en case %d\n",PJ1);
                }
                if (reponse3==2)
                {
                    PJ2=PJ2+LancerD();
                    printf("Votre pion 2 est en case %d\n",PJ2);
                }
            }
            if (reponse2==2)
            {
                PJ1=PJ1+LancerD();
                printf("Votre pion 1 est en case %d\n",PJ1);
            }
            if (PJ1>34)
            {
                PJ1=PJ1-34;
            }
            if (PJ2>34)
            {
                PJ2=PJ2-34;
            }
        }
        if (joueur==0)
        {
            printf("Avez vous 2 pions de sortis ?\n 1-Oui\n 2-Non\n");
            scanf("%d",&reponse2);
            if (reponse2==1)
            {
                printf("Quel pion voulez vous jouer ?\n 1-Pion 1\n 2-Pion 2\n");
                scanf("%d",&reponse3);
                if (reponse3==1)
                {
                    PV1=PV1+LancerD();
                    printf("Votre pion 1 est en case %d\n",PV1);
                }
                if (reponse3==2)
                {
                    PV2=PV2+LancerD();
                    printf("Votre pion 2 est en case %d\n",PV2);
                }
            }
            if (reponse2==2)
            {
                PV1=PV1+LancerD();
                printf("Votre pion 1 est en case %d\n",PV1);
            }
            if (PV1>34)
            {
                PV1=PV1-34;
            }
            if (PV2>34)
            {
                PV2=PV2-34;
            }
        }
    }
}
