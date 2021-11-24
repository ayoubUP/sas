#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* dans cette étape nous avons crée notre propre type de donne utilisant les struct
et definer ce type sous le nom de cmp utilisant typedef */
int CompteCreer = 0;
typedef struct compte
{
    char nom[20], prenom[20],cin[20];
    float montant;
} cmp;
// ici nous creons notre tableaux de struct
cmp compte_Users[50];

void menu();
void premier_compte();
void introduire_plusieurs_compte();
void Affichage();
void menu_affichage();
void tri_ascendant();
void tri_descendant();
void superieur_ascendant();
void afichage_operation();
void depot();
void retrait();
int recherch_cin();
void exite();

int main()
{
    //	ce variable
    int choix,numberOfCompte, indice;
    start:
    // nous avons fait cette boucle pour afficher le menu pendant que l'utilisateur entre un numéro en dehors de notre menu (<1 ou >5)
    printf("\n\n****** Meunu *****\n");
    menu();
    do
    {
        printf("Entree votre choix, entre 1 et 5 : ");
        scanf("%d",&choix);
    }
    while(choix<1 || choix>5);
    switch(choix)
    {
        case 1:
            printf("\n creer un compte \n");
            premier_compte();
            goto start;
        case 2:
            printf("\n creer plusieurs comptes \n");
            printf("\n taper le nombre des Comptes \n");
            scanf("%d",&numberOfCompte);
            // dans cette étape nous appelons cette fonction pour creer pusieure compte	et on envoie numberOfCompte en parametre
            introduire_plusieurs_compte(numberOfCompte);
            goto start;
        case 3:
            afichage_operation();
            do
            {
                printf("Entree votre choix, entre 1 et 2: ");
                scanf("%d",&choix);
            }
            while(choix<1 || choix>2);
            printf("%d\n", choix);
            switch (choix)
            {
                case 1:
                    depot();
                    Affichage();
                    break;
                case 2:
                    retrait();
                    Affichage();
                    break;
            }
            goto start;
        case 4:
            menu_affichage();
            do
            {
                printf("Entree votre choix, entre 1 et 4: ");
                scanf("%d",&choix);
            }
            while(choix<1 || choix>4);
            switch(choix)
            {
                case 1:
                    tri_ascendant();
                    Affichage();
                    break;
                case 2:
                    tri_descendant();
                    Affichage();
                    break;
                case 3:
                    superieur_ascendant();
                    break;
                case 4:
                    superieur_descendant();
                    break;
                case 5:
                    indice  = recherche_cin();
                    if(indice > -1)
                    {
                        printf("nom : %s\n", compte_Users[indice].nom);
                        printf("prenom: %s\n",compte_Users[indice].prenom);
                        printf("cin:%s\n",compte_Users[indice].cin);
                        printf("montant:%f\n",compte_Users[indice].montant);
                    }
                    else printf("pas trouve\n");
                    break;
            }
            goto start;
        case 5:
            exite();
            break;
    }
    return 0;
}

void menu ()
{
    printf("-1) creer un compte bancaire\n");
    printf("-2) creer plusieurs comptes bancaires \n");
    printf("-3) Operations\n");
    printf("-4) Affichage\n");
    printf("-5) Exit\n");
}

void premier_compte ()
{
    printf("entre le nom  :");
    scanf("%s",&compte_Users[CompteCreer].nom);

    printf("entre cin  :");
    scanf("%s",&compte_Users[CompteCreer].cin);

    printf("entre prenom :");
    scanf("%s",&compte_Users[CompteCreer].prenom);


    printf("entre le montant :");
    scanf("%f",&compte_Users[CompteCreer].montant);

    CompteCreer++;
}

void Affichage()
{
    for(int j = 0 ; j < CompteCreer ; j++)
    {
        printf("\n compte %d \n",j+1);
        printf("\n CIN : %s ",compte_Users[j].cin);
        printf("\n Nom : %s ",compte_Users[j].nom);
        printf("\n Prenom : %s",compte_Users[j].prenom);
        printf("\n Montant : %f",compte_Users[j].montant);
    }
}

void introduire_plusieurs_compte(int n)
{
    int i,j ;
    for(i=0; i<n ; i++)
    {
        printf("\nCompte %d \n",i+1);
        premier_compte();
    }
}

void exite()
{
    exit(0);
}

void menu_affichage()
{
    printf("1) affichage par ordre ascendant \n");
    printf("2) affichage par ordre descendant \n");
    printf("3) affichage par ordre ascendant ayant un montant superieur a un chifre introduit \n");
    printf("4) affichage par ordre descendant ayant un montant superieur a un chifre introduit \n");
    printf("5) recherche par cin \n");
}

void tri_ascendant()
{
    int i,j ;
    for(i=0; i<CompteCreer-1; i++)
    {
        for(j=i+1; j<CompteCreer; j++)
        {
            if(compte_Users[i].montant > compte_Users[j].montant)
            {
                cmp tmp = compte_Users[i];
                compte_Users[i] = compte_Users[j];
                compte_Users[j] = tmp;
            }
        }
    }
}

void tri_descendant()
{
    int i,j ;
    for(i=0; i<CompteCreer-1; i++)
    {
        for(j=i+1; j<CompteCreer; j++)
        {
            if(compte_Users[i].montant < compte_Users[j].montant)
            {
                cmp tmp = compte_Users[i];
                compte_Users[i] = compte_Users[j];
                compte_Users[j] = tmp;
            }
        }
    }
}

void superieur_ascendant()
{
    int i;
    float nombre;
    printf("entrer nombre :  ");
    scanf("%f", &nombre);
    tri_ascendant();
    for(i=0; i<CompteCreer; i++)
    {
        if(nombre <= compte_Users[i].montant)
        {
            printf("nom : %s\n",compte_Users[i].nom);
            printf("prenom : %s\n",compte_Users[i].prenom);
            printf("cin : %s\n",compte_Users[i].cin);
            printf("montant : %f\n",compte_Users[i].montant);
        }
    }
}

void superieur_descendant()
{
    int i;
    float nombre;
    printf("entrer nombre :  ");
    scanf("%f", &nombre);
    tri_descendant();
    for(i=0; i<CompteCreer; i++)
    {
        if(nombre <= compte_Users[i].montant)
        {
            printf("nom : %s\n",compte_Users[i].nom);
            printf("prenom : %s\n",compte_Users[i].prenom);
            printf("cin : %s\n",compte_Users[i].cin);
            printf("montant : %f\n",compte_Users[i].montant);
        }
    }
}

void afichage_operation()
{
    printf("1) depot \n");
    printf("2) retrait \n");
}

void depot()
{
    float montant;
    int indice = recherche_cin();
    if(indice > -1)
    {
        printf("combien vous voulez deposer :  ");
        scanf("%f", &montant);
        compte_Users[indice].montant += montant;
    }
    else printf("non trouve\n");
}

void retrait()
{
    float montant;
    int indice = recherche_cin();
    if(indice > -1)
    {
        printf("combien vous voulez retrait :  ");
        scanf("%f", &montant);
        compte_Users[indice].montant -= montant;
    }
}

int recherche_cin()
{
    char cin[20];
    int i;
    printf("entre cin : ");
    scanf("%s",cin);
    for(i=0; i<CompteCreer; i++)
    {
        if(strcmp(compte_Users[i].cin, cin) == 0)
            return i;
    }
    return -1;
}
