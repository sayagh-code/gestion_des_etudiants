#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include"bibliotheque.h"

void  main()
{
    FILE *etude;
    Etudiant  T[1000];
    int l,N,f,j,i,a,matricule,x,b;
    char ch,nom,prenom, z[4][15]={"l'informatique" , "mathematique" , "physique" , "langues"};
    f=0;j=0;a=0;b=0;

    etude=fopen("fichier_projet","a");
do{
    //----menu----
    schema1();
    l=18;
    gotoxy(22,5);textcolor(3);cprintf(" gestion des etudiants");
    gotoxy(4,7);textcolor(2);cprintf("total des eleves:%d",f);
    do{
    gotoxy(7,9);
    textcolor(3);cprintf("Saisie");
    gotoxy(7,10);
    cprintf("Recherche d'un etudiant");
    gotoxy(7,11);
    cprintf("Affichage des etudiants");
    gotoxy(7,12);
    cprintf("La moyenne generale");
    gotoxy(7,13);
    cprintf("Majors de promotion");
    gotoxy(7,14);
    cprintf("Supprimer un etudiant");
    gotoxy(7,15);
    cprintf("Trier les etudiants");
    gotoxy(7,16);
    cprintf("Quitter");
    switch(ch)
    {
      case 72:l=l-1;break;
      case 80:l=l+1;break;
    }
    if(l>=17)l=9;
    if(l<=8)l=16;
     gotoxy(7,l);ch=getch();
    }while(ch!=13);
   clrscr();
  gotoxy(2,2);
  //-----saisie d'un etudiant----
  if(l==9)
  {
  printf("Donner le Nombre des Etudiants a Saisir : ");scanf("%d",&N);
  clrscr();
  f=f+N;
  Lecture(T,f,a);
  a=f;
  }
  //----recherche d'un etudiant----
  if(l==10)
  {
  do{
    l=7;
    printf("chercher l'etudiant par:");
    do{
    gotoxy(2,4);printf("1-nom");
    gotoxy(2,5); printf("2-matricule");
    gotoxy(2,6); printf("retour");
    switch(ch)
    {
      case 72:l=l-1;break;
      case 80:l=l+1;break;
    }
    if(l>6)l=4;
    if(l<4)l=6;
    gotoxy(2,l);ch=getch();
    }while(ch!=13);
    clrscr();
    if(l==4)
    {
    printf("\nentrer le nom de l'eleve : ");
    scanf("%s",&nom);
    clrscr();
    x=0;
     for(i=0; i<f; i++)
     {
        if(nom==*T[i].Nom)
        {
        textcolor(3);cprintf("...AFFICHAGE DE L'ETUDIANT...");
        printf("\n\nNom     :%s",T[i].Nom);
        printf("\nPrenom    :%s",T[i].Prenom);
        printf("\nMatricule :%d",T[i].Matricule);
        printf("\ndate de naissance:");
        printf("\njour :%d",T[i].jour);
        printf("\nmois :%d",T[i].mois);
        printf("\nannee:%d",T[i].annee);
        for(x=0;x<4;x++){printf("\nNote de %s:%.2f",z[x],T[i].Note[x]);}
        printf("\nAbsence :%d",T[i].Abs);
        }
     }
     if(x==0)
     printf("\nle nom que vous avez saisie est inexistant");
     printf("\n\n\tcliquer entrer pour retourner");
     getch();
     clrscr();
    }
    if(l==5)
    {
    printf("enter le maricule de l'eleve :");
    scanf("%d",&matricule);
    clrscr();
    x=0;
     for(i=0; i<f; i++)
     {
        if(matricule==T[i].Matricule)
        {
        textcolor(3);cprintf("...AFFICHAGE DE L'ETUDIANT...");
        printf("\n\nNom     :%s",T[i].Nom);
        printf("\nPrenom    :%s",T[i].Prenom);
        printf("\nMatricule :%d",T[i].Matricule);
        printf("\ndate de naissance:");
        printf("\njour :%d",T[i].jour);
        printf("\nmois :%d",T[i].mois);
        printf("\nannee :%d",T[i].annee);
        for(x=0;x<4;x++){printf("\nNote de %s:%.2f",z[x],T[i].Note[x]);}
        printf("\nAbsence :%d",T[i].Abs);
        }
     }
      if(x==0)
      printf("le matricule que vous avez saisie est inexistant");
      printf("\n\n\tcliquer entrer pour retourner");
      getch();
      clrscr();
    }
  }while(l!=6);
  }
  //------affichage des etudiant-------
  if(l==11)
  {
 do{
  l=7;
    printf("voulez vous afficher:");
    do{
    gotoxy(2,4);printf("1-tous les etudiant");
    gotoxy(2,5); printf("2-les etudiant admis");
    gotoxy(2,6); printf("retour");
    switch(ch)
    {
      case 72:l=l-1;break;
      case 80:l=l+1;break;
    }
    if(l>6)l=4;
    if(l<4)l=6;
    gotoxy(2,l);ch=getch();
    }while(ch!=13);
    clrscr();
  if(l==4)
  {
  textcolor(3);cprintf(" ...Affichage...\n");
  Affichage(T,f);
  printf("\n\ncliquer entrer pour retourner");
  getch();
  clrscr();
  }
  if(l==5)
  {
   textcolor(3);cprintf("...les etudiants admis sont...\n");
   admis(T,f);
   printf("\n\ncliquer entrer pour retourner");
   getch();
   clrscr();
  }
  }while(l!=6);
  }
  //------la moyenne general--------
  if(l==12)
  {
   do{
    l=7;
    printf("chercher l'etudiant par:");
    do{
    gotoxy(2,4);printf("1-nom");
    gotoxy(2,5); printf("2-matricule");
    gotoxy(2,6); printf("retour");
    switch(ch)
    {
      case 72:l=l-1;break;
      case 80:l=l+1;break;
    }
    if(l>6)l=4;
    if(l<4)l=6;
    gotoxy(2,l);ch=getch();
    }while(ch!=13);
    clrscr();
    if(l==4)
    {
    printf("\nentrer le nom de l'eleve :");
    scanf("%s",&nom);
    clrscr();
    x=0;
     for(i=0; i<f; i++)
     {
        if(nom==*T[i].Nom)
        {
          textcolor(3);cprintf("...LA MOYENNE GENERAL...");
          x=1;
          schema2();
          gotoxy(11,11);printf("%s",T[i].Nom);
          gotoxy(31,11);printf("%s",T[i].Prenom);
          gotoxy(51,11);printf("%.2f",T[i].Moyenne);
        }
     }
     if(x==0)
     printf("\nle nom que vous avez saisie est inexistant");
     gotoxy(20,15);printf("cliquer entrer pour retourner");
     getch();
     clrscr();
    }
    if(l==5)
    {
    printf("enter le maricule de l'eleve :");
    scanf("%d",&matricule);
    clrscr();
    x=0;
     for(i=0; i<f; i++)
     {
        if(matricule==T[i].Matricule)
        {
          textcolor(3);cprintf("...LA MOYENNE GENERAL...");
          x=1;
          schema2();
          gotoxy(11,11);printf("%s",T[i].Nom);
          gotoxy(31,11);printf("%s",T[i].Prenom);
          gotoxy(51,11);printf("%.2f",T[i].Moyenne);
        }
     }
     if(x==0)
     printf("\nle nom que vous avez saisie est inexistant");
     gotoxy(20,15);printf("cliquer entrer pour retourner");
     getch();
     clrscr();
    }
   }while(l!=6);
  }
  //------majorant-------
  if(l==13)
  {
     schema(T,f,majorant(T,f));
     getch();
     clrscr();
  }
  //------supprimer un etudiant------
  if(l==14)
  {
   do{
    l=7;
    printf("supprimer un etudiant par:");
    do{
    gotoxy(2,4);printf("1-nom");
    gotoxy(2,5); printf("2-matricule");
    gotoxy(2,6); printf("retour");
    switch(ch)
    {
      case 72:l=l-1;break;
      case 80:l=l+1;break;
    }
    if(l>6)l=4;
    if(l<4)l=6;
    gotoxy(2,l);ch=getch();
    }while(ch!=13);
    clrscr();
    if(l==4)
    {
    printf("\nentrer le nom de l'eleve :");
    scanf("%s",&nom);
    clrscr();
    x=0;
     for(i=0; i<f; i++)
     {
        if(nom==*T[i].Nom)
        {
          x=1;
          textcolor(3);cprintf("...SUPPRESSION...");
          printf("\n\nvous avez supprimer %s %s",T[i].Nom,T[i].Prenom);
          for(b=i;b<f-1;b++)
          T[i]=T[i+1];
          f=f-1;
          a=a-1;
        }
     }
     if(x==0)
     printf("\nle nom que vous avez saisie est inexistant");
     printf("\n\n\tcliquer entrer pour retourner");
     getch();
     clrscr();
    }
    if(l==5)
    {
    printf("enter le maricule de l'eleve :");
    scanf("%d",&matricule);
    clrscr();
    x=0;
     for(i=0; i<f; i++)
     {
        if(matricule==T[i].Matricule)
        {
          x=1;
          textcolor(3);cprintf("...SUPPRESSION...");
          printf("\n\nvous avez supprimer %s %s",T[i].Nom,T[i].Prenom);
          for(b=i;b<f-1;b++)
          T[i]=T[i+1];
          f=f-1;
          a=a-1;
        }
     }
     if(x==0)
     printf("\nle nom que vous avez saisie est inexistant");
     printf("\n\n\tcliquer entrer pour retourner");
     getch();
     clrscr();
    }
   }while(l!=6);
  }
  //------trier les etudiant------
  if(l==15)
  {
   do{
    l=7;
    printf("trier par:");
    do{
    gotoxy(2,4); printf("1-matricule");
    gotoxy(2,5); printf("2-note");
    gotoxy(2,6); printf("retour");
    switch(ch)
    {
      case 72:l=l-1;break;
      case 80:l=l+1;break;
    }
    if(l>6)l=4;
    if(l<4)l=6;
    gotoxy(2,l);ch=getch();
    }while(ch!=13);
    clrscr();
    if(l==4)
    {
      textcolor(3);cprintf("...TRIE...\n\n");
      triematricule(T,f);
    }
    if(l==5)
    {
      textcolor(3);cprintf("...TRIE...\n\n");
      trienote(T,f);
    }
   }while(l!=6);
  }
}while(l!=16);

fprintf(etude,"affichage des etudiant\n");
    for(i=0; i<f; i++)
     {
        fprintf(etude,"\nNom     :%s",T[i].Nom);
        fprintf(etude,"\nPrenom    :%s",T[i].Prenom);
        fprintf(etude,"\nMatricule :%d",T[i].Matricule);
        fprintf(etude,"\nvotre date de naissance:");
        fprintf(etude,"\njour :%d",T[i].jour);
        fprintf(etude,"\nmois :%d",T[i].mois);
        fprintf(etude,"\nannee:%d",T[i].annee);
        for(j=0;j<4;j++){fprintf(etude,"\nNote de %s :%.2f",z[j],T[i].Note[j]);}
        fprintf(etude,"\nAbsence :%d",T[i].Abs);
        fprintf(etude,"\n\n");
     }
     fclose(etude);
}
