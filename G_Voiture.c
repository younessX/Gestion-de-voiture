#include<stdio.h>
#include<gtk/gtk.h>
#include<stdlib.h>
#include<string.h>
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

GtkWidget *E1,*E2,*E3,*E4,*E5,*E6,*oui,*non;
GtkWidget *window2,*window1,*window3;

void destroy(GtkWidget *widget,GtkWidget *window){
gtk_widget_destroy(window);
}
/**** hna ila brit n3ti des valeur*/
void set_value1(GtkWidget *widget,gpointer data){
gtk_entry_set_text (GTK_ENTRY(E2)," \0");
gtk_entry_set_text (GTK_ENTRY(E3)," \0");
gtk_entry_set_text (GTK_ENTRY(E4)," \0");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(E1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(E5),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(E6),0);
}

void new_f(GtkWidget *widget,gpointer data){
voiture v1;
v1.id=v1.nbplaces=v1.prixJour=0;
FILE *F;
strcpy(v1.marque,gtk_entry_get_text(GTK_ENTRY(E2)));
strcpy(v1.nom,gtk_entry_get_text(GTK_ENTRY(E3)));
strcpy(v1.couleur,gtk_entry_get_text(GTK_ENTRY(E4)));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(oui))){strcpy(v1.EnLocation,"oui");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(non))){strcpy(v1.EnLocation,"non");}
v1.id=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(E1));
v1.nbplaces=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(E5));
v1.prixJour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(E6));
GtkBuilder *builder;
builder = gtk_builder_new_from_file("my_gtk.glade");
if(strlen(v1.marque)==0 || strlen(v1.nom)==0 || strlen(v1.couleur)== 0 || v1.id==0 || v1.nbplaces==0 || v1.prixJour==0){
GtkWidget *erreur1,*ok;
erreur1 = GTK_WIDGET(gtk_builder_get_object(builder,"erreur1"));
ok = GTK_WIDGET(gtk_builder_get_object(builder,"ok"));
g_signal_connect(ok,"clicked",G_CALLBACK(destroy),erreur1);
gtk_widget_show_all(erreur1);
}
else{
F=fopen("Voiture.txt","a");
fprintf(F,"%d\t%s\t%s\t%s\t",v1.id,v1.marque,v1.nom,v1.couleur);
fprintf(F,"%d\t%d\t%s\n",v1.nbplaces,v1.prixJour,v1.EnLocation);
fclose(F);
GtkWidget *suc2,*scB2;
suc2 = GTK_WIDGET(gtk_builder_get_object(builder,"suc2"));
scB2 = GTK_WIDGET(gtk_builder_get_object(builder,"scB2"));
g_signal_connect(scB2,"clicked",G_CALLBACK(set_value1),NULL);
g_signal_connect(scB2,"clicked",G_CALLBACK(destroy),suc2);
gtk_widget_show_all(suc2);
}
}

void AjouterVoi(GtkWidget *widget,gpointer data){
GtkBuilder *builder;
GtkWidget *ok1,*annuler2;
builder = gtk_builder_new_from_file("my_gtk.glade");
window3 = GTK_WIDGET(gtk_builder_get_object(builder,"window3"));
E1 = GTK_WIDGET(gtk_builder_get_object(builder,"E1"));
E2 = GTK_WIDGET(gtk_builder_get_object(builder,"E2"));
E3 = GTK_WIDGET(gtk_builder_get_object(builder,"E3"));
E4 = GTK_WIDGET(gtk_builder_get_object(builder,"E4"));
E5 = GTK_WIDGET(gtk_builder_get_object(builder,"E5"));
E6 = GTK_WIDGET(gtk_builder_get_object(builder,"E6"));
non = GTK_WIDGET(gtk_builder_get_object(builder,"non"));
oui = GTK_WIDGET(gtk_builder_get_object(builder,"oui"));
ok1 = GTK_WIDGET(gtk_builder_get_object(builder,"ok1"));
g_signal_connect(ok1,"clicked",G_CALLBACK(new_f),NULL);
//g_signal_connect(ok1,"clicked",G_CALLBACK(destroy),);
gtk_widget_show_all(window3);
}
/*************************modiffier voiture********************/
GtkWidget *En1,*En2,*En3,*En4,*En5,*En6,*oui1,*non1;

int checkVoi(int b){
FILE *F=fopen("Voiture.txt","r");
voiture v1;
int i=0;
while(!feof(F)){
fscanf(F,"%d%s%s%s",&v1.id,v1.marque,v1.nom,v1.couleur);
fscanf(F,"%d%d%s\n",&v1.nbplaces,&v1.prixJour,v1.EnLocation);
if(v1.id==b){
i=1;
break;
}
}
fclose(F);
return i;}

void set_value2(GtkWidget *widget,gpointer data){
gtk_entry_set_text (GTK_ENTRY(En2)," \0");
gtk_entry_set_text (GTK_ENTRY(En3)," \0");
gtk_entry_set_text (GTK_ENTRY(En4)," \0");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(En1),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(En5),0);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(En6),0);
}

void id_voiture(GtkWidget *widget,gpointer data){
GtkWidget *erreur2,*ok2;
GtkBuilder *builder;
builder = gtk_builder_new_from_file("my_gtk.glade");
int a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(En1));
if(!checkVoi(a)){
erreur2 = GTK_WIDGET(gtk_builder_get_object(builder,"erreur2"));
ok2 = GTK_WIDGET(gtk_builder_get_object(builder,"ok2"));
gtk_widget_show_all(erreur2);
g_signal_connect (ok2, "clicked",G_CALLBACK(destroy),erreur2);
}
else{
voiture v1,v2;
FILE *F1,*F;
v1.nbplaces=v1.prixJour=0;
strcpy(v1.marque,gtk_entry_get_text(GTK_ENTRY(En2)));
strcpy(v1.nom,gtk_entry_get_text(GTK_ENTRY(En3)));
strcpy(v1.couleur,gtk_entry_get_text(GTK_ENTRY(En4)));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(oui1))){strcpy(v1.EnLocation,"oui");}
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(non1))){strcpy(v1.EnLocation,"non");}
v1.id=a;
v1.nbplaces=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(En5));
v1.prixJour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(En6));

if(strlen(v1.marque)==0 || strlen(v1.nom)==0 || strlen(v1.couleur)== 0 || v1.nbplaces==0 || v1.prixJour==0){
GtkWidget *erreur1,*ok;
erreur1 = GTK_WIDGET(gtk_builder_get_object(builder,"erreur1"));
ok = GTK_WIDGET(gtk_builder_get_object(builder,"ok"));
g_signal_connect(ok,"clicked",G_CALLBACK(destroy),erreur1);
gtk_widget_show_all(erreur1);
}

else{
F1=fopen("file.txt","w");
F=fopen("Voiture.txt","r");
while(!feof(F)){
fscanf(F,"%d%s%s%s",&v2.id,v2.marque,v2.nom,v2.couleur);
fscanf(F,"%d%d%s\n",&v2.nbplaces,&v2.prixJour,v2.EnLocation);

if(a==v2.id){
fprintf(F1,"%d\t%s\t%s\t%s\t",v1.id,v1.marque,v1.nom,v1.couleur);
fprintf(F1,"%d\t%d\t%s\n",v1.nbplaces,v1.prixJour,v1.EnLocation);
}

else{fprintf(F1,"%d\t%s\t%s\t%s\t",v2.id,v1.marque,v2.nom,v2.couleur);
     fprintf(F1,"%d\t%d\t%s\n",v2.nbplaces,v2.prixJour,v2.EnLocation);}
}
fclose(F1);
fclose(F);
remove("Voiture.txt");
rename("file.txt","Voiture.txt");
GtkWidget *suc1,*scB1;
suc1 = GTK_WIDGET(gtk_builder_get_object(builder,"suc1"));
scB1 = GTK_WIDGET(gtk_builder_get_object(builder,"scB1"));
g_signal_connect(scB1,"clicked",G_CALLBACK(set_value2),NULL);
g_signal_connect(scB1,"clicked",G_CALLBACK(destroy),suc1);
gtk_widget_show_all(suc1);}
}
}

/*void destroy(GtkWidget *widget, gpointer data) {
            gtk_main_quit ();
 }*/
void modifierVoi(GtkWidget *widget,gpointer data){
GtkBuilder *builder;
GtkWidget *window4,*md1;
builder = gtk_builder_new_from_file("my_gtk.glade");
En1 = GTK_WIDGET(gtk_builder_get_object(builder,"En1"));
En2 = GTK_WIDGET(gtk_builder_get_object(builder,"En2"));
En3 = GTK_WIDGET(gtk_builder_get_object(builder,"En3"));
En4 = GTK_WIDGET(gtk_builder_get_object(builder,"En4"));
En5 = GTK_WIDGET(gtk_builder_get_object(builder,"En5"));
En6 = GTK_WIDGET(gtk_builder_get_object(builder,"En6"));
non1= GTK_WIDGET(gtk_builder_get_object(builder,"non1"));
oui1= GTK_WIDGET(gtk_builder_get_object(builder,"oui1"));
md1 = GTK_WIDGET(gtk_builder_get_object(builder,"md1"));
window4=GTK_WIDGET(gtk_builder_get_object(builder,"window4"));
g_signal_connect(md1,"clicked",G_CALLBACK(id_voiture),NULL);
gtk_widget_show_all(window4);
}

/**void on_md1_clicked(GtkButton *button, GtkWidget *window4){
gtk_widget_destroy(window4);
}*/


/***supprimer voiture***/
GtkWidget *id1;
void supp(GtkWidget *widget,gpointer data){
GtkBuilder *builder;
GtkWidget *erreur2,*ok2;
builder = gtk_builder_new_from_file("my_gtk.glade");
int a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(id1));
if(!checkVoi(a)){
erreur2 = GTK_WIDGET(gtk_builder_get_object(builder,"erreur2"));
ok2 = GTK_WIDGET(gtk_builder_get_object(builder,"ok2"));
gtk_widget_show_all(erreur2);
g_signal_connect (ok2, "clicked",G_CALLBACK(destroy),erreur2);
}
else{
FILE *F,*F1;
voiture v1;
F=fopen("Voiture.txt","r");
F1=fopen("file.txt","w");
while(!feof(F)){
fscanf(F,"%d%s%s%s",&v1.id,v1.marque,v1.nom,v1.couleur);
fscanf(F,"%d%d%s\n",&v1.nbplaces,&v1.prixJour,v1.EnLocation);
if(a!=v1.id){
fprintf(F1,"%d\t%s\t%s\t%s\t",v1.id,v1.marque,v1.nom,v1.couleur);
fprintf(F1,"%d\t%d\t%s\n",v1.nbplaces,v1.prixJour,v1.EnLocation);
}
}
fclose(F1);
fclose(F);
remove("Voiture.txt");
rename("file.txt","Voiture.txt");
GtkWidget *suc3,*scB3;
suc3 = GTK_WIDGET(gtk_builder_get_object(builder,"suc3"));
scB3 = GTK_WIDGET(gtk_builder_get_object(builder,"scB3"));
g_signal_connect(scB3,"clicked",G_CALLBACK(destroy),suc3);
gtk_widget_show_all(suc3);
}
}

void supprimerVoi(GtkWidget *widget,gpointer data){
GtkBuilder *builder,*supprimer1,*sup1,*an1;
builder = gtk_builder_new_from_file("my_gtk.glade");
id1 = GTK_WIDGET(gtk_builder_get_object(builder,"id1"));
supprimer1=GTK_WIDGET(gtk_builder_get_object(builder,"supprimer1"));
sup1=GTK_WIDGET(gtk_builder_get_object(builder,"sup1"));
an1=GTK_WIDGET(gtk_builder_get_object(builder,"an1"));
g_signal_connect(sup1,"clicked",G_CALLBACK(supp),NULL);
g_signal_connect(an1,"clicked",G_CALLBACK(destroy),supprimer1);
gtk_widget_show_all(supprimer1);
}

/***Lister voiture**/
void affiche_V(GtkWidget *widget,gpointer data){
voiture v1;
FILE *F=fopen("Voiture.txt","r");
while(!feof(F)){
fscanf(F,"%d%s%s%s",&v1.id,v1.marque,v1.nom,v1.couleur);
fscanf(F,"%d%d%s\n",&v1.nbplaces,&v1.prixJour,v1.EnLocation);
printf("%d%s\t%s\t%s\t",v1.id,v1.marque,v1.nom,v1.couleur);
printf("\t%d\t\t%d\t%s\n",v1.nbplaces,v1.prixJour,v1.EnLocation);
}
}


void gestion_voi(GtkWidget *widget,gpointer data){
GtkBuilder *builder;
GtkWidget *butto2,*butto3,*annuler2,*butto4;
builder = gtk_builder_new_from_file("my_gtk.glade");
window2 = GTK_WIDGET(gtk_builder_get_object(builder,"window2"));
butto2 = GTK_WIDGET(gtk_builder_get_object(builder,"butto2"));
butto3 = GTK_WIDGET(gtk_builder_get_object(builder,"butto3"));
butto4 = GTK_WIDGET(gtk_builder_get_object(builder,"butto4"));
annuler2 = GTK_WIDGET(gtk_builder_get_object(builder,"annuler2"));
g_signal_connect(butto2,"clicked",G_CALLBACK(AjouterVoi),NULL);
g_signal_connect(butto3,"clicked",G_CALLBACK(modifierVoi),NULL);
g_signal_connect(butto4,"clicked",G_CALLBACK(supprimerVoi),NULL);
g_signal_connect (annuler2, "clicked",G_CALLBACK(destroy), window2);
gtk_widget_show_all(window2);
}

int main(int argc,int **argv){
gtk_init(&argc,&argv);
GtkBuilder *builder;
GtkWidget *button2,*annuler1,*button1;
builder = gtk_builder_new_from_file("my_gtk.glade");
window1 = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
button2 = GTK_WIDGET(gtk_builder_get_object(builder,"button2"));
button1 = GTK_WIDGET(gtk_builder_get_object(builder,"button1"));
annuler1 = GTK_WIDGET(gtk_builder_get_object(builder,"annuler1"));
g_signal_connect(button2,"clicked",G_CALLBACK(gestion_voi),NULL);
g_signal_connect (annuler1, "clicked",G_CALLBACK(destroy), window1);
gtk_widget_show_all(window1);
gtk_main();
return 0;}
