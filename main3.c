#include <stdio.h>
#include <stdlib.h>

float calculmens( float principal, float tauxInteret, int duree){
    float tauxMensuel = tauxInteret / 12 /100;
    int nombrePaiment = duree *12;
    float mensualite = (principal * tauxMensuel) / (1 -pow(1+ tauxMensuel, nombrePaiment));
    return mensualite;
}

int main()
{
    const int tentativesMax = 10;
    int tentatives = 0;

  while(tentatives < tentativesMax){
      float montantPret, tauxInteret;
      int dureeRemboursement;

      printf("Enter le montant du pret : ");
      scanf("%f", &montantPret);

      printf("Enter le taux dinteret annuel (entre 3 et 7) : ");
      scanf("%f", &tauxInteret);

     if(tauxInteret < 3 || tauxInteret > 7) {
          printf("le taux dinteret entre 3 et 7 please \n");
          continue;
       }

      printf("Enter la duree de remboursement en annees (plus de 5) : ");
      scanf("%d", &dureeRemboursement);

      if (dureeRemboursement < 5) {
          printf("la duree de remboursemment doit etre de 5 ans ou plus\n");
          continue;
      }
     float mensualiteEstimee = calculmens(montantPret, tauxInteret, dureeRemboursement);
     printf("le montant estime de la mensualite est : %2.f\n", mensualiteEstimee);

     char reponse[3];
     printf("Voulez- vous effuctuer une nouvelle simulaion ? (Oui/ Non): ");
     scanf("%s", reponse);

     if (strcmp(reponse, "Non") == 0 || strcmp(reponse, "non") == 0){
        break;
     }

     tentatives++;

    }
    return 0;
}
