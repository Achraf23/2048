#include <iostream>
#include<time.h>
#define TAILLE 4

using namespace std;

struct cellule
{
    unsigned int ligne;
    unsigned int colonne;
};


void ajouter(unsigned int grille[TAILLE][TAILLE])
{

    unsigned int ligne,colonne;

    do
    {
        ligne=rand()%4;
        colonne=rand()%4;

    }while(grille[ligne][colonne]!=0);

    grille[ligne][colonne]=2;

}

void initialise(unsigned int grille[TAILLE][TAILLE])
{
    for(unsigned int i=0;i<TAILLE;i++)
    {
        for(unsigned int j=0;j<TAILLE;j++)
            grille[i][j]=0;
    }

    ajouter(grille);
    ajouter(grille);

}




void affiche_grille(unsigned int grille[TAILLE][TAILLE])
{
    for(unsigned int i=0;i<TAILLE;i++)
    {
        for(unsigned int j=0;j<TAILLE;j++)
        {
            if(grille[i][j]==0)
                cout << "_";
            else
                cout << grille[i][j];

            cout << "   ";
        }

        cout << endl << endl;
    }
}





void affiche_essai(unsigned int tab[])
{
    for(unsigned int i=0;i<TAILLE;i++)
        cout << tab[i] << " ";

}


void iteratif(unsigned int tab[])
{
    int j;

    for(int i=TAILLE-1;i>=0;i--)// parcours tableau de la droite a l gauche
    {
        if(tab[i])
        {
            j=i-1;

            while(j>=0 && tab[j]==0)// trouver le voisin(plus proche element different de 0 a gauche)
                j--;

            if(j>=0)//voisin existe sinon pas de voisin
            {
                if(tab[j]==tab[i])
                {
                    tab[i]*=2;
                    tab[j]=0;
                }


            }

            // on remonte et mon met un 0 quand on echange
            unsigned int remonte=i+1;

            while(remonte<TAILLE && tab[remonte]==0)
                remonte++;

            tab[remonte-1]=tab[i];

            if(remonte-1!=i)
            tab[i]=0;


        }

    }

}


void iteratif_inverse(unsigned int tab[])
{
    int j;

    for(int i=0;i<TAILLE;i++)// parcours tableau de la droite a l gauche
    {
        if(tab[i])
        {
            j=i+1;

            while(j<TAILLE && tab[j]==0)// trouver le voisin(plus proche element different de 0 a gauche)
                j++;

            if(j<TAILLE)//voisin existe sinon pas de voisin
            {
                if(tab[j]==tab[i])
                {
                    tab[i]*=2;
                    tab[j]=0;
                }


            }

            // on remonte et mon met un 0 quand on echange
            int remonte=i-1;

            while(remonte>=0 && tab[remonte]==0)
                remonte--;

            tab[remonte+1]=tab[i];

            if(remonte+1!=i)
            tab[i]=0;


        }

    }

}

void iteratif_gauche(unsigned int tab[TAILLE][TAILLE])
{

    int j;

    for(int k=0;k<TAILLE;k++)
    {
        for(int i=0;i<TAILLE;i++)// parcours tableau de la droite a l gauche
        {
            if(tab[k][i])
            {
                j=i+1;

                while(j<TAILLE && tab[k][j]==0)// trouver le voisin(plus proche element different de 0 a gauche)
                    j++;

                if(j<TAILLE)//voisin existe sinon pas de voisin
                {
                    if(tab[k][j]==tab[k][i])
                    {
                        tab[k][i]*=2;
                        tab[k][j]=0;
                    }


                }

                // on remonte et mon met un 0 quand on echange
                int remonte=i-1;

                while(remonte>=0 && tab[k][remonte]==0)
                    remonte--;

                tab[k][remonte+1]=tab[k][i];

                if(remonte+1!=i)
                tab[k][i]=0;


            }

        }

    }

}

void iteratif_droite(unsigned int tab[TAILLE][TAILLE])
{
    int j;

    for(int k=0;k<TAILLE;k++)
    {

        for(int i=TAILLE-1;i>=0;i--)// parcours tableau de la droite a l gauche
        {
            if(tab[k][i])
            {
                j=i-1;

                while(j>=0 && tab[k][j]==0)// trouver le voisin(plus proche element different de 0 a gauche)
                    j--;

                if(j>=0)//voisin existe sinon pas de voisin
                {
                    if(tab[k][j]==tab[k][i])
                    {
                        tab[k][i]*=2;
                        tab[k][j]=0;
                    }


                }

                // on remonte et mon met un 0 quand on echange
                unsigned int remonte=i+1;

                while(remonte<TAILLE && tab[k][remonte]==0)
                    remonte++;

                tab[k][remonte-1]=tab[k][i];

                if(remonte-1!=i)
                tab[k][i]=0;


            }

        }

    }


}


void iteratif_bas(unsigned int tab[TAILLE][TAILLE])
{
    int j;

    for(int k=0;k<TAILLE;k++)
    {

        for(int i=TAILLE-1;i>=0;i--)// parcours tableau de la droite a l gauche
        {
            if(tab[i][k])
            {
                j=i-1;

                while(j>=0 && tab[j][k]==0)// trouver le voisin(plus proche element different de 0 a gauche)
                    j--;

                if(j>=0)//voisin existe sinon pas de voisin
                {
                    if(tab[j][k]==tab[i][k])
                    {
                        tab[i][k]*=2;
                        tab[j][k]=0;
                    }


                }

                // on remonte et mon met un 0 quand on echange
                unsigned int remonte=i+1;

                while(remonte<TAILLE && tab[remonte][k]==0)
                    remonte++;

                tab[remonte-1][k]=tab[i][k];

                if(remonte-1!=i)
                tab[i][k]=0;


            }

        }

    }


}

void iteratif_haut(unsigned int tab[TAILLE][TAILLE])
{
    int j;
    for(int k=0;k<TAILLE;k++)
    {
        for(int i=0;i<TAILLE;i++)// parcours tableau de la droite a l gauche
        {
            if(tab[i][k])
            {
                j=i+1;

                while(j<TAILLE && tab[j][k]==0)// trouver le voisin(plus proche element different de 0 a gauche)
                    j++;

                if(j<TAILLE)//voisin existe sinon pas de voisin
                {
                    if(tab[j][k]==tab[i][k])
                    {
                        tab[i][k]*=2;
                        tab[j][k]=0;
                    }


                }

                // on remonte et mon met un 0 quand on echange
                int remonte=i-1;

                while(remonte>=0 && tab[remonte][k]==0)
                    remonte--;

                tab[remonte+1][k]=tab[i][k];

                if(remonte+1!=i)
                tab[i][k]=0;


            }

        }

    }
}

void jouer(unsigned int tab[TAILLE][TAILLE])
{
    unsigned int jouer=1;
    initialise(tab);

    affiche_grille(tab);

    while(jouer)
    {
        cout << "commande: ";
        cin >> jouer;

        switch(jouer)
        {
        case 1:
            iteratif_gauche(tab);
            ajouter(tab);
            affiche_grille(tab);
            break;

        case 2:
            iteratif_bas(tab);
            ajouter(tab);
            affiche_grille(tab);
            break;

        case 3:
            iteratif_droite(tab);
            ajouter(tab);
            affiche_grille(tab);
            break;

        case 5:
            iteratif_haut(tab);
            ajouter(tab);
            affiche_grille(tab);
            break;

        default:
            jouer=0;
            break;


        }
    }
}



int main()
{

    srand((unsigned int) time(NULL));

    unsigned int jeu[TAILLE][TAILLE];

    jouer(jeu);

    /*unsigned int t[TAILLE];

    t[0]=2;  t[1]=4;    t[2]=0;   t[3]=4;

    iteratif_inverse(t);

    affiche_essai(t);*/


    return 0;
}
