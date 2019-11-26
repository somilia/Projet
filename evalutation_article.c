#include <stdio.h>
#include <stdlib.h>
#include <math.h>








void main(void)
{
     
    char tableau[50]={0};
    FILE* fichier = NULL;
    int i =0;
    int b=0;
    char *delimiteur;
 
      
    fichier = fopen("Pate_a_tartiner.csv", "r");
 
    if (fichier != NULL)
    {
       for(i = 0; i < 3; i++)  //regler probleme de quelle ligne
       {
            fgets (tableau, 50, fichier);
            delimiteur = strtok(tableau,";");
            while (delimiteur != NULL)
            {
                if (b==0){ printf("Lecture de  %s\n", delimiteur); b=1;}
                else {printf("Lecture des valeurs:  %s\n", delimiteur);}
                delimiteur = strtok(NULL,";");
            }
        b=0;
         
        }
        fclose(fichier);
    }
 
    else
    {
        printf("Fichier CSV non trouve\n");
    }
 
    return;
 
}



/** EXEMPLE DE CODE DU PROF A SUPPRIMER
  FILE *fichier = NULL; /* fichier est le nom local du fichier */
  /* Initialisation du fichier qui représentera le fichier de données ouvert */
  fichier = fopen("../ressources/VocabAnglaisFrancais.csv" , "r");

  if ( fichier != NULL )
  {
    char MotFrancais[WORD_SIZE_MAX];
    char MotAnglais[WORD_SIZE_MAX];
    char ligne[WORD_SIZE_MAX];

    char* motTemp;
    char saisie[WORD_SIZE_MAX]; /* Déclaration d'une variable "saisie" de type chaîne de caractères pour la suite */
    int resultat = 0;

    while ( fgets( ligne, sizeof(ligne), fichier ) != NULL && !feof(fichier)) /* Lire une ligne */
    {

      motTemp=strtok(ligne, ","); /* APPEL jusqu'à la virgule => (EN GROS) LE PREMIER MOT (Francais) */
      strncpy(MotAnglais, motTemp, WORD_SIZE_MAX); /* Fonction qui copie le contenu de motTemp dans MotFrancais */
      motTemp=strtok(NULL, ""); /* APPEL après la virgule => DEUXIEME MOT (Anglais) */
      strncpy(MotFrancais, motTemp, WORD_SIZE_MAX);

      fprintf(stdout, "Traduction en français de : %s ? (Puis taper sur entrée)\n", MotAnglais);
#ifdef DEBUG
      fprintf(stdout, "%s", saisie);
#endif
      fgets(saisie, sizeof saisie, stdin); /* Saisie sécurisée : fonction équivalente à fscanf */

      /* La fonction strcmp renvoie une valeur (0 si c'est juste) que l'on affecte à une variable "resultat" */
      int size = strlen(MotFrancais);
      // Matches only if we do not consider the \r and \n in MotFrancais
      resultat = strncmp(saisie,MotFrancais, size - 2);

#ifdef DEBUG
      int size2 = strlen(saisie);
      fprintf(stdout, "longueur de saisie : %d, longueur de MotFrancais : %d \n", size2, size);
      fprintf(stdout, "resultat de la comparaison : %d \n", resultat);
#endif

      if (resultat == 0) /* Correction */
        fprintf(stdout, "Bravo. C'était la bonne réponse :-)\n\n");
      else
        fprintf(stdout, "Faux. La réponse était %s \n", MotFrancais);

      motTemp='\0';
    }

    if ( EOF != fclose(fichier) )
    {
#ifdef DEBUG
      fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
      fprintf(stdout, "Probleme de fermeture du fichier \n");
      return EXIT_FAILURE;
    }
  }
  else /*( fichier == NULL)*/
  {
#ifdef DEBUG
    fprintf(stderr, "Fonction en cours d'exécution : %s \n", __func__ );
#endif
    fprintf(stdout, "Problème d'ouverture du fichier \n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
**/
















}








