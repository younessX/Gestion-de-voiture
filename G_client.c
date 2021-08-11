#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct contratLocation
{
 float numContrat;
 int idVoiture;
 int idClient;
 char debut[11];
 char fin[11];
 int cout;
}contrat;

typedef struct Client
{
 int idClient;
 char nom[20];
 char prenom[20];
 int cin;
 char adresse[15];
 int telephone;
}client;

typedef struct Voiture
{
 int id;
 char marque[15];
 char nom[15];
 char couleur[7];
 int nbplaces;
 int prixJour;
 char EnLocation[4];
}voiture;

int menu(){
char b;
printf("\nvoulez vous retourner au menu?(O/N) ");
scanf("%c",&b);
while(b!='O' && b!='N'){
printf("taper O pour oui et N pour non!: ");
scanf("%c",&b);
}
if(b=='O'){return 1;}
return 0;}

int checkCli(int a){
FILE *F;
client c;
int i=0;
F=fopen("client.txt","r");
while(!feof(F)){
fscanf(F,"%d%s%s",&c.idClient,c.nom,c.prenom);
fscanf(F,"%d%s%d\n",&c.cin,c.adresse,&c.telephone);
if(c.idClient==a){i=1;break;}
}
if(i==0){printf("\nce client n'existe pas");}
fclose(F);
return i;}

void afficheCli(){
FILE *F;
client c;
F=fopen("client.txt","r");
printf("idClient \tnom \tprenom \tcin \tadresse \ttelephone\n");
while(!feof(F)){
fscanf(F,"%d%s%s",&c.idClient,c.nom,c.prenom);
fscanf(F,"%d%s%d\n",&c.cin,c.adresse,&c.telephone);
printf("%d\t%s\t%s\t",c.idClient,c.nom,c.prenom);
printf("%d\t%s\t%d\n",c.cin,c.adresse,c.telephone);
}
fclose(F);
Gestion_Cli();}

client infoClient(){
client x;
printf("saisir idClient: ");scanf("%d",&x.idClient);
printf("saisir le nom: ");scanf("%s",x.nom);
printf("saisir le prenom: ");scanf("%s",x.prenom);
printf("saisir le cin: ");scanf("%d",&x.cin);
printf("saisir l'adresse: ");scanf("%s",x.adresse);
printf("saisir le telephone: ");scanf("%d",&x.telephone);

return x;}

void suppCl(){
int x;
printf("saisir le id du client pour le supprimer: ");
scanf("%d",&x);
if(checkCli(x)){
FILE *F,*F1;
client c;
F=fopen("client.txt","r");
F1=fopen("file.txt","w");
while(!feof(F)){
fscanf(F,"%d%s%s",&c.idClient,c.nom,c.prenom);
fscanf(F,"%d%s%d\n",&c.cin,c.adresse,&c.telephone);
if(x!=c.idClient){
fprintf(F1,"%d\t%s\t%s\t",c.idClient,c.nom,c.prenom);
fprintf(F1,"%d\t%s\t%d\n",c.cin,c.adresse,c.telephone);
}
}
fclose(F);
fclose(F1);
remove("client.txt");
rename("file.txt","client.txt");
printf("la supprition est bien fait\n");}
Gestion_Cli();
}

void modifierCli(){
FILE *F,*F1;
client c;
int x;
printf("saisir le idClient: ");
scanf("%d",&x);
if(checkCli(x)){
F=fopen("client.txt","r");
F1=fopen("file.txt","w");
while(!feof(F)){
fscanf(F,"%d%s%s",&c.idClient,c.nom,c.prenom);
fscanf(F,"%d%s%d\n",&c.cin,c.adresse,&c.telephone);
if(c.idClient==x){
printf("pour modifier ce client\n");
c=infoClient();
}
fprintf(F1,"%d\t%s\t%s\t",c.idClient,c.nom,c.prenom);
fprintf(F1,"%d\t%s\t%d\n",c.cin,c.adresse,c.telephone);
}
fclose(F);
fclose(F1);
remove("client.txt");
rename("file.txt","client.txt");
printf("la modufication est bien fait");
Gestion_Cli();
}
else{
if(menu()) Gestion_Cli();
else modifierCli();}
}

void ajouterCl(){
FILE *F;
client c;
F=fopen("client.txt","a");
c=infoClient();
fprintf(F,"%d\t%s\t%s\t",c.idClient,c.nom,c.prenom);
fprintf(F,"%d\t%s\t%d\n",c.cin,c.adresse,c.telephone);
fclose(F);
printf("le client est bien ajouter");
Gestion_Cli();}

void Gestion_Cli(){
int x,a,i=0,y;
float nb;
contrat con;
client cl,c;
voiture v;
FILE *F,*F1;
do{
printf("\n");
printf("    Gestion des clients\n\n");
printf("liste des clients..................1\n");
printf("Ajouter client.....................2\n");
printf("Modifier client....................3\n");
printf("Supprimer client...................4\n");
printf("Retour.............................5\n\n");
printf("        votre choix : ");
scanf("%d",&x);}while(x<=0||x>5);
switch(x){
case 1:
 afficheCli();
break;

case 2:
 ajouterCl();
break;

case 3:
modifierCli();
break;

case 4:
 suppCl();
break;

case 5:

break;

default:
printf("erreur!");
break;
}
}
main(){
Gestion_Cli();
}
