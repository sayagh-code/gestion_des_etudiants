#ifndef BIBLIOTHEQUE_H_INCLUDED
#define BIBLIOTHEQUE_H_INCLUDED


typedef struct
{
     char Nom[30],Prenom[30];
     float Note[10],Moyenne;
     int Abs,jour,mois,annee,Matricule;
}Etudiant;

void Lecture( Etudiant Tab[] , int Taille , int m )
{
    int i,j;
    char  x[4][15]={"l'informatique" , "mathematique" , "physique" , "langues"};

     for(i=m; i<Taille; i++)
    {
        Tab[i].Moyenne=0;
        gotoxy(19,1);textcolor(3);cprintf("...SAISIE...");
        gotoxy(10,3);textcolor(2);cprintf("saisir l'etudiant numero : %d",i+1);
        gotoxy(10,4);printf("\nNom      :  ");scanf("%s",Tab[i].Nom);
        printf("Prenom   :  ");scanf("%s",Tab[i].Prenom);
        printf("Matricule:  ");scanf("%d",&Tab[i].Matricule);
        printf("enter votre date de naissance:");
        printf("\n  jour : ");do{gotoxy(10,9);printf("      ");gotoxy(10,9);scanf("%d",&Tab[i].jour);}while(Tab[i].jour<1 || Tab[i].jour>31);
        printf("  mois : ");do{gotoxy(10,10);printf("      ");gotoxy(10,10);scanf("%d",&Tab[i].mois);}while(Tab[i].mois<1 || Tab[i].mois>12);
        printf("  annee: ");do{gotoxy(10,11);printf("       ");gotoxy(10,11);scanf("%d",&Tab[i].annee);}while(Tab[i].annee<1993 || Tab[i].annee>2003);
        for(j=0;j<4;j++){printf("Note de %s:",x[j]);do{gotoxy(24-2*j,12+j);printf("       ");gotoxy(24-2*j,12+j);scanf("%f",&Tab[i].Note[j]);}while(Tab[i].Note[j]<0 || Tab[i].Note[j]>20);
                         Tab[i].Moyenne+=Tab[i].Note[j];
                        }
        printf("Absence  : ");do{gotoxy(12,16);printf("       ");gotoxy(12,16);scanf("%d",&Tab[i].Abs);}while(Tab[i].Abs<0 || Tab[i].Abs>20);
        Tab[i].Moyenne=Tab[i].Moyenne/4;
        clrscr();
    }
}

void Affichage(Etudiant Tab[] , int Taille)
{
    int i,j;
    char  x[4][15]={"l'informatique" , "mathematique" , "physique" , "langues"};

     for(i=0; i<Taille; i++)
     {
        printf("\nNom     :%s",Tab[i].Nom);
        printf("\nPrenom    :%s",Tab[i].Prenom);
        printf("\nMatricule :%d",Tab[i].Matricule);
        printf("\nvotre date de naissance:");
        printf("\njour :%d",Tab[i].jour);
        printf("\nmois :%d",Tab[i].mois);
        printf("\nannee:%d",Tab[i].annee);
        for(j=0;j<4;j++){printf("\nNote de %s :%.2f",x[j],Tab[i].Note[j]);}
        printf("\nAbsence :%d",Tab[i].Abs);
        printf("\n\n");
     }
}

void admis(Etudiant Tab[] , int Taille)
{
    int i,j;
    for(i=0;i<Taille;i++)
    if(Tab[i].Moyenne>=10)
    {
     printf("\n\t%s %s : %.2f",Tab[i].Nom,Tab[i].Prenom,Tab[i].Moyenne);
    }
}

int majorant(Etudiant Tab[] , int Taille)
{
    int i,j;
    float max;
    if(Taille==0)
    return 1001;
    for(i=0;i<Taille;i++)
    {
        if(max<Tab[i].Moyenne)
        {
        max=Tab[i].Moyenne;
        j=i;
        }
    }
 return j;
}

void schema(Etudiant Tab[] , int Taille , int j)
{
    int i;
    gotoxy(3,2);printf("%c",218);
    for(i=0;i<60;i++){gotoxy(4+i,2);printf("%c",196);}
    gotoxy(3+i,2);printf("%c",191);

    gotoxy(3,3);printf("%c",179);
    gotoxy(3,4);printf("%c",179);
    gotoxy(3,5);printf("%c",179);
    gotoxy(63,3);printf("%c",179);
    gotoxy(63,4);printf("%c",179);
    gotoxy(63,5);printf("%c",179);

    gotoxy(3,6);printf("%c",195);
    for(i=0;i<60;i++){gotoxy(4+i,6);printf("%c",196);}
    gotoxy(3+i,6);printf("%c",180);

    gotoxy(3,7);printf("%c",179);
    gotoxy(3,8);printf("%c",179);
    gotoxy(63,7);printf("%c",179);
    gotoxy(63,8);printf("%c",179);
    gotoxy(3,9);printf("%c",179);
    gotoxy(63,9);printf("%c",179);

    gotoxy(3,10);printf("%c",195);
    for(i=0;i<60;i++){gotoxy(4+i,10);printf("%c",196);}
    gotoxy(3+i,10);printf("%c",180);

    gotoxy(3,11);printf("%c",179);
    gotoxy(3,12);printf("%c",179);
    gotoxy(63,11);printf("%c",179);
    gotoxy(63,12);printf("%c",179);
    gotoxy(3,13);printf("%c",179);
    gotoxy(63,13);printf("%c",179);
    gotoxy(3,14);printf("%c",179);
    gotoxy(63,14);printf("%c",179);
    gotoxy(3,15);printf("%c",179);
    gotoxy(63,15);printf("%c",179);

    gotoxy(3,16);printf("%c",192);
    for(i=0;i<60;i++){gotoxy(4+i,16);printf("%c",196);}
    gotoxy(3+i,16);printf("%c",217);

    gotoxy(23,6);printf("%c",194);
    gotoxy(23,7);printf("%c",179);
    gotoxy(23,8);printf("%c",179);
    gotoxy(23,9);printf("%c",179);
    gotoxy(23,10);printf("%c",197);
    gotoxy(23,11);printf("%c",179);
    gotoxy(23,12);printf("%c",179);
    gotoxy(23,13);printf("%c",179);
    gotoxy(23,14);printf("%c",179);
    gotoxy(23,15);printf("%c",179);
    gotoxy(23,16);printf("%c",193);

    gotoxy(43,6);printf("%c",194);
    gotoxy(43,7);printf("%c",179);
    gotoxy(43,8);printf("%c",179);
    gotoxy(43,9);printf("%c",179);
    gotoxy(43,10);printf("%c",197);
    gotoxy(43,11);printf("%c",179);
    gotoxy(43,12);printf("%c",179);
    gotoxy(43,13);printf("%c",179);
    gotoxy(43,14);printf("%c",179);
    gotoxy(43,15);printf("%c",179);
    gotoxy(43,16);printf("%c",193);

    gotoxy(23,4);printf("MAJORS DE PROMOTIONS");
    gotoxy(11,8);printf("Nom");
    gotoxy(30,8);printf("Prenom");
    gotoxy(50,7);printf("Moyenne");
    gotoxy(50,8);printf("generale");

    if(majorant(Tab,Taille)!=1001)
    {
    gotoxy(11,13);printf("%s",Tab[j].Nom);
    gotoxy(30,13);printf("%s",Tab[j].Prenom);
    gotoxy(50,13);printf("%.2f",Tab[j].Moyenne);
    }
    else
    gotoxy(50,13);printf("   ");
}

void trienote(Etudiant Tab[] , int Taille)
{
  int i,j;
  Etudiant c[1000],f;

     for(i=0;i<Taille;i++)
     c[i]=Tab[i];

      for(i=0;i<Taille;i++)
      for(j=i;j<Taille;j++)
      if(c[j].Moyenne>c[i].Moyenne)
      {
      f=c[i];
      c[i]=c[j];
      c[j]=f;
      }
      for(i=0;i<Taille;i++)
      {
      printf("\n%s %s : %.2f",c[i].Nom,c[i].Prenom,c[i].Moyenne);
      printf("\nmatricule : %d\n\n",c[i].Matricule);
      }

     getch();
     clrscr();
}

void triematricule(Etudiant Tab[] , int Taille)
{
     int i,j;
     Etudiant c[1000],m;

     for(i=0;i<Taille;i++)
     c[i]=Tab[i];

      for(i=0;i<Taille;i++)
      for(j=i;j<Taille;j++)
      if(c[i].Matricule>c[j].Matricule)
      {
      m=c[i];
      c[i]=c[j];
      c[j]=m;
      }
     for(i=0;i<Taille;i++)
      {
      printf("\n%s %s : %.2f",c[i].Nom,c[i].Prenom,c[i].Moyenne);
      printf("\nmatricule : %d\n\n",c[i].Matricule);
      }
     getch();
     clrscr();
}

void schema1(void)
{
    int i;
    gotoxy(3,4);printf("%c",218);
    for(i=0;i<60;i++){gotoxy(4+i,4);printf("%c",196);}
    gotoxy(3+i,4);printf("%c",191);

    gotoxy(3,5);printf("%c",179);
    gotoxy(63,5);printf("%c",179);

    gotoxy(3,6);printf("%c",195);
    for(i=0;i<60;i++){gotoxy(4+i,6);printf("%c",196);}
    gotoxy(3+i,6);printf("%c",180);

    gotoxy(3,7);printf("%c",179);
    gotoxy(3,8);printf("%c",179);
    gotoxy(63,7);printf("%c",179);
    gotoxy(63,8);printf("%c",179);
    gotoxy(3,9);printf("%c",179);
    gotoxy(63,9);printf("%c",179);
    gotoxy(3,10);printf("%c",179);
    gotoxy(63,10);printf("%c",179);

    gotoxy(3,11);printf("%c",179);
    gotoxy(3,12);printf("%c",179);
    gotoxy(63,11);printf("%c",179);
    gotoxy(63,12);printf("%c",179);
    gotoxy(3,13);printf("%c",179);
    gotoxy(63,13);printf("%c",179);
    gotoxy(3,14);printf("%c",179);
    gotoxy(63,14);printf("%c",179);
    gotoxy(3,15);printf("%c",179);
    gotoxy(63,15);printf("%c",179);
    gotoxy(3,16);printf("%c",179);
    gotoxy(63,16);printf("%c",179);
    gotoxy(3,17);printf("%c",179);
    gotoxy(63,17);printf("%c",179);

    gotoxy(3,18);printf("%c",192);
    for(i=0;i<60;i++){gotoxy(4+i,18);printf("%c",196);}
    gotoxy(3+i,18);printf("%c",217);
}

void schema2(void)
{
    int i;

    gotoxy(3,7);printf("%c",218);
    for(i=0;i<60;i++){gotoxy(4+i,7);printf("%c",196);}
    gotoxy(3+i,7);printf("%c",191);

    gotoxy(3,8);printf("%c",179);
    gotoxy(63,8);printf("%c",179);

    gotoxy(3,9);printf("%c",195);
    for(i=0;i<60;i++){gotoxy(4+i,9);printf("%c",196);}
    gotoxy(3+i,9);printf("%c",180);

    gotoxy(3,10);printf("%c",179);
    gotoxy(3,11);printf("%c",179);
    gotoxy(63,10);printf("%c",179);
    gotoxy(63,11);printf("%c",179);
    gotoxy(3,12);printf("%c",179);
    gotoxy(63,12);printf("%c",179);

    gotoxy(3,13);printf("%c",192);
    for(i=0;i<60;i++){gotoxy(4+i,13);printf("%c",196);}
    gotoxy(3+i,13);printf("%c",217);

    gotoxy(23,7);printf("%c",194);
    gotoxy(23,8);printf("%c",179);
    gotoxy(23,9);printf("%c",197);
    gotoxy(23,10);printf("%c",179);
    gotoxy(23,11);printf("%c",179);
    gotoxy(23,12);printf("%c",179);
    gotoxy(23,13);printf("%c",193);

    gotoxy(43,7);printf("%c",194);
    gotoxy(43,8);printf("%c",179);
    gotoxy(43,9);printf("%c",197);
    gotoxy(43,10);printf("%c",179);
    gotoxy(43,11);printf("%c",179);
    gotoxy(43,12);printf("%c",179);
    gotoxy(43,13);printf("%c",193);

    gotoxy(12,8);printf("NOM");
    gotoxy(31,8);printf("PRENOM");
    gotoxy(46,8);printf("MOYENNE GENERAL");
}


#endif // BIBLIOTHEQUE_H_INCLUDED
