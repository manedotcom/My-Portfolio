  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  #include <stdio.h>
  #include <stdlib.h>
  #include <Time.h>

  typedef int bool ;

  #define True 1
  #define False 0

  /** Arbres de recherche binaire **/
typedef int Typeelem_Ai ;
typedef struct Noeud_Ai * Pointeur_Ai ;
struct Noeud_Ai
{
    Typeelem_Ai Val ;
    Pointeur_Ai Fg ;
    Pointeur_Ai Fd ;
    int length ;
};



  /** Implementation **\: QUEUE OF INTEGERS **/
typedef Pointeur_Ai Typeelem_Q ;

typedef struct Queue * Pointer_Q ; // this type will be used to define the head and the tail of the queue
typedef struct Node_Q * PList_Q ; // this type will be used to define the node of the queue


struct Node_Q // We define the node
{
Typeelem_Q Val ;
PList_Q Next ;
//int priorite;
};

struct Queue// We define the structure of the head and tail
{
PList_Q Head, Tail ;
};

void Create_Queue ( Pointer_Q *Fil )
{
*Fil = (struct Queue *) malloc( sizeof( struct Queue)) ;
(*Fil)->Head = NULL ;
(*Fil)->Tail = NULL ;
}

bool Empty_Queue (Pointer_Q Fil )
{ return Fil->Head == NULL ;}

//void Enqueue ( Pointer_Q Fil , Typeelem_Q Val , int pri)
void Enqueue ( Pointer_Q Fil , Typeelem_Q Val ) // Insert a node at the tail of the queue
{
PList_Q Q; // A pointer to a node of queue
Q = (struct Node_Q *) malloc( sizeof( struct Node_Q)) ; // Allocate a space for a node
Q->Val = Val ;
//Q->priorite=pri;
Q->Next = NULL;
if ( ! Empty_Queue(Fil) )
Fil->Tail->Next = Q ; // Insert on the tail
else Fil->Head = Q; // else (first time enqueue ) attach Q to the head as well
Fil->Tail = Q; // designate Q as the new tail
}

void Dequeue (Pointer_Q Fil, Typeelem_Q *Val )
{
if (! Empty_Queue(Fil) ) // the queue must be non-empty
{
*Val = Fil->Head->Val ;
Fil->Head = Fil->Head->Next;
}
else printf ( "EMPTY QUEUE \n");
}






  /** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tii Type_Tii  ;
  typedef Type_Tii * Typestr_Tii ;
  typedef int Type1_Tii  ;
  typedef int Type2_Tii  ;
  struct Tii
    {
      Type1_Tii Champ1 ;
      Type2_Tii Champ2 ;
    };

  Type1_Tii Struct1_Tii ( Typestr_Tii S)
    {
      return  S->Champ1 ;
    }

  Type2_Tii Struct2_Tii ( Typestr_Tii S)
    {
      return  S->Champ2 ;
    }

  void Aff_struct1_Tii ( Typestr_Tii S, Type1_Tii Val )
    {
       S->Champ1 = Val ;
    }

  void Aff_struct2_Tii ( Typestr_Tii S, Type2_Tii Val )
    {
       S->Champ2 = Val ;
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tii Typeelem_ATii   ;
  typedef struct Noeud_ATii * Pointeur_ATii ;

  struct Noeud_ATii
    {
      Typeelem_ATii  Val ;
      Pointeur_ATii Fg ;
      Pointeur_ATii Fd ;
      Pointeur_ATii Pere ;
     } ;

  Typeelem_ATii Info_ATii( Pointeur_ATii P )
    { return P->Val;   }

  Pointeur_ATii Fg_ATii( Pointeur_ATii P)
    { return P->Fg ; }

  Pointeur_ATii Fd_ATii( Pointeur_ATii P)
    { return P->Fd ; }

  Pointeur_ATii Pere_ATii( Pointeur_ATii P)
    { return P->Pere ; }

  void Aff_info_ATii ( Pointeur_ATii P, Typeelem_ATii Val)
    {
      Typeelem_ATii _Temp ;
      _Temp = malloc(sizeof(Type_Tii));
      /* Affectation globale de structure */
      _Temp->Champ1 = Val->Champ1;
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATii( Pointeur_ATii P, Pointeur_ATii Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATii( Pointeur_ATii P, Pointeur_ATii Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATii( Pointeur_ATii P, Pointeur_ATii Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATii( Pointeur_ATii *P)
    {
      *P = (struct Noeud_ATii *) malloc( sizeof( struct Noeud_ATii))   ;
      (*P)->Val = malloc(sizeof(Type_Tii));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATii( Pointeur_ATii P)
    { free( P ) ; }


  /** Implémentation **\: PILE DE STRUCTURES**/
  /** Piles **/

  typedef Typestr_Tii Typeelem_PTii ;
  typedef struct Maillon_PTii * Pointeur_PTii ;
  typedef   Pointeur_PTii  Typepile_PTii  ;

  struct Maillon_PTii
    {
      Typeelem_PTii  Val ;
      Pointeur_PTii Suiv ;
    } ;

  void Creerpile_PTii( Pointeur_PTii *P )
    { *P = NULL ; }

  bool Pilevide_PTii ( Pointeur_PTii P )
    { return  (P == NULL ); }

  void Empiler_PTii ( Pointeur_PTii *P,  Typeelem_PTii Val )
    {
      Pointeur_PTii Q;

      Q = (struct Maillon_PTii *) malloc( sizeof( struct Maillon_PTii))   ;
      Q->Val = malloc(sizeof(Type_Tii));
      Typeelem_PTii _Temp ;
      _Temp = malloc(sizeof(Type_Tii));
      /* Affectation globale de structure */
      _Temp->Champ1 = Val->Champ1;
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_PTii ( Pointeur_PTii *P,  Typeelem_PTii *Val )
    {
      Pointeur_PTii Sauv;

      if (! Pilevide_PTii (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }


  /** Implémentation **\: LISTE DE ENTIERS**/

  /** Listes lin?aires cha?n?es **/

  typedef int Typeelem_Li   ;
  typedef struct Maillon_Li * Pointeur_Li ;

  struct Maillon_Li
    {
      Typeelem_Li  Val ;
      Pointeur_Li Suiv ;
    } ;

  Pointeur_Li Allouer_Li (Pointeur_Li *P)
    {
      *P = (struct Maillon_Li *) malloc( sizeof( struct Maillon_Li)) ;
      (*P)->Suiv = NULL;
    }

  void Aff_val_Li(Pointeur_Li P, Typeelem_Li Val)
    {
      P->Val = Val ;
    }

  void Aff_adr_Li( Pointeur_Li P,  Pointeur_Li Q)
    {
      P->Suiv = Q ;
    }

  Pointeur_Li Suivant_Li(  Pointeur_Li P)
    { return( P->Suiv ) ;  }

  Typeelem_Li Valeur_Li( Pointeur_Li P)
    { return( P->Val) ; }

  void Liberer_Li ( Pointeur_Li P)
    { free (P);}


  /** Implémentation **\: PILE DE ENTIERS**/
  /** Piles **/

  typedef int Typeelem_Pi ;
  typedef struct Maillon_Pi * Pointeur_Pi ;
  typedef   Pointeur_Pi  Typepile_Pi  ;

  struct Maillon_Pi
    {
      Typeelem_Pi  Val ;
      Pointeur_Pi Suiv ;
    } ;

  void Creerpile_Pi( Pointeur_Pi *P )
    { *P = NULL ; }

  bool Pilevide_Pi ( Pointeur_Pi P )
    { return  (P == NULL ); }

  void Empiler_Pi ( Pointeur_Pi *P,  Typeelem_Pi Val )
    {
      Pointeur_Pi Q;

      Q = (struct Maillon_Pi *) malloc( sizeof( struct Maillon_Pi))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_Pi ( Pointeur_Pi *P,  Typeelem_Pi *Val )
    {
      Pointeur_Pi Sauv;

      if (! Pilevide_Pi (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }


  /** Implémentation **\: PILE DE ARBRES BINAIRES DE STRUCTURES**/
  /** Piles **/

  typedef Pointeur_ATii Typeelem_PATii ;
  typedef struct Maillon_PATii * Pointeur_PATii ;
  typedef   Pointeur_PATii  Typepile_PATii  ;

  struct Maillon_PATii
    {
      Typeelem_PATii  Val ;
      Pointeur_PATii Suiv ;
    } ;

  void Creerpile_PATii( Pointeur_PATii *P )
    { *P = NULL ; }

  bool Pilevide_PATii ( Pointeur_PATii P )
    { return  (P == NULL ); }

  void Empiler_PATii ( Pointeur_PATii *P,  Typeelem_PATii Val )
    {
      Pointeur_PATii Q;

      Q = (struct Maillon_PATii *) malloc( sizeof( struct Maillon_PATii))   ;
      Q->Val = Val ;
      Q->Suiv = *P;
      *P = Q;
    }

  void Depiler_PATii ( Pointeur_PATii *P,  Typeelem_PATii *Val )
    {
      Pointeur_PATii Sauv;

      if (! Pilevide_PATii (*P) )
        {
          *Val = (*P)->Val ;
          Sauv = *P;
          *P = (*P)->Suiv;
          free(Sauv);
        }
      else printf ("%s \n", "Pile vide");
    }


  /** Variables du programme principal **/
  Pointeur_ATii R=NULL;
  Pointeur_ATii R2=NULL;
  Pointeur_PTii S1=NULL;
  Pointeur_PTii S3=NULL;
  int I;
  Pointeur_Li T=NULL;
  Pointeur_Li Q=NULL;
  Pointeur_Pi S1p=NULL;
  Pointeur_Li L1=NULL;
  Pointeur_Li L1p=NULL;
  Pointeur_Li L2=NULL;
  Pointeur_Li L2p=NULL;
  Pointeur_ATii Rp=NULL;
  Pointeur_Pi S3p=NULL;
  Pointeur_Li L3=NULL;
  Pointeur_Li L3p=NULL;
  Pointeur_Li L4=NULL;
  Pointeur_Li L4p=NULL;
  int M;
  int _Px1;
  int _Px2;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** Prototypes des fonctions **/

  void Insert_list (Pointeur_Li *W , int *V);
  void Traversal_one (Pointeur_ATii *R , Pointeur_PTii *S);
  void Traversal_three (Pointeur_ATii *R , Pointeur_PTii *S);
  void Creer_arbre (Pointeur_ATii *A , Pointeur_ATii *B);
  bool  Bst (Pointeur_ATii *R) ;
  bool  Sub_l (Pointeur_ATii *R , Typestr_Tii *X) ;
  bool  Sub_r (Pointeur_ATii *R , Typestr_Tii *X) ;
  int  Subbranch_length (Pointeur_ATii *R) ;
  void Traversal_two (Pointeur_ATii *R , int *L);
  void Traversal_four (Pointeur_ATii *R , int *L);
  void Insert_branch (Pointeur_ATii *R , Pointeur_Li *L);
  void Verify_one (Pointeur_ATii *R , Pointeur_Li *L);
  void Ver_t_one (Pointeur_ATii *R , Pointeur_Pi *S , Pointeur_Li *U);
  void Rm_dup (Pointeur_Li *Lst);
  void Affich_list (Pointeur_Li *Lst);
  bool  Comp_list (Pointeur_Li *L , Pointeur_Li *U) ;
  void Verify_two (Pointeur_ATii *R , Pointeur_Li *F);
  void Ver_t_two (Pointeur_ATii *R , int *L , Pointeur_Li *W);
  void Verify_three (Pointeur_ATii *R2 , Pointeur_Li *L3);
  void Ver_t_three (Pointeur_ATii *R2 , Pointeur_Pi *S3 , Pointeur_Li *L3p);
  void Verify_four (Pointeur_ATii *R , Pointeur_Li *F);
  void Ver_t_four (Pointeur_ATii *R , int *L , Pointeur_Li *W);

  void Insert_list (Pointeur_Li *W , int *V)
    {
      /** Variables locales **/
      Pointeur_Li P=NULL;
      Pointeur_Li Q=NULL;

      /** Corps du module **/
     P  =  *W ;
     if( P == NULL) {
       Allouer_Li (& P ) ;
       Aff_val_Li ( P , *V ) ;
       }
     else
       {
       while( Suivant_Li ( P ) != NULL) {
         P  =  Suivant_Li ( P ) ;

       } ;
       Allouer_Li (& Q ) ;
       Aff_val_Li ( Q , *V ) ;
       Aff_adr_Li ( P , Q ) ;

     } ;

    }
  void Traversal_one (Pointeur_ATii *R , Pointeur_PTii *S)
    {
      /** Variables locales **/
      Typestr_Tii P;
      Pointeur_ATii _Px1=NULL;
      Pointeur_ATii _Px2=NULL;

      /** Corps du module **/
     P = malloc(sizeof(Type_Tii));
     if( *R != NULL) {
       Empiler_PTii (& *S , Info_ATii ( *R ) ) ;
       if( ( Fg_ATii ( *R ) == NULL )) {
         if( Fd_ATii ( *R ) == NULL) {
           while( ! Pilevide_PTii ( *S )) {
             Depiler_PTii (& *S , &P ) ;
             printf ( " %d", Struct1_Tii(P) ) ;

           } ;

         } ;

       } ;
       _Px1 =  Fg_ATii ( *R ) ;
       Traversal_one ( &_Px1, & *S ) ;
       _Px2 =  Fd_ATii ( *R ) ;
       Traversal_one ( &_Px2, & *S ) ;

     }
    }
  void Traversal_three (Pointeur_ATii *R , Pointeur_PTii *S)
    {
      /** Variables locales **/
      Typestr_Tii P;
      Pointeur_ATii _Px1=NULL;
      Pointeur_ATii _Px2=NULL;

      /** Corps du module **/
     P = malloc(sizeof(Type_Tii));
     if( *R != NULL) {
       Empiler_PTii (& *S , Info_ATii ( *R ) ) ;
       if( ( Fg_ATii ( *R ) == NULL )) {
         if( Fd_ATii ( *R ) == NULL) {
           while( ! Pilevide_PTii ( *S )) {
             Depiler_PTii (& *S , &P ) ;
             printf ( " %d", Struct1_Tii(P) ) ;

           } ;

         } ;

       } ;
       _Px1 =  Fd_ATii ( *R ) ;
       Traversal_three ( &_Px1, & *S ) ;
       _Px2 =  Fg_ATii ( *R ) ;
       Traversal_three ( &_Px2, & *S ) ;

     }
    }
  void Creer_arbre (Pointeur_ATii *A , Pointeur_ATii *B)
    {
      /** Variables locales **/
      Pointeur_PATii Pil=NULL;
      Pointeur_ATii P=NULL;
      Pointeur_ATii Q=NULL;
      Pointeur_ATii Pp=NULL;
      Pointeur_ATii Qq=NULL;
      int N;
      Typestr_Tii Ch;
      bool Possible;
      int Cmp;
      Type_Tii _Struct_Temp1;

      /** Corps du module **/
     Ch = malloc(sizeof(Type_Tii));
     N  =  100 ;
     Cmp  =  1 ;
     Aff_struct1_Tii ( Ch  , Aleanombre(1000 ) + 1 ) ;
     Aff_struct2_Tii ( Ch  , 0 ) ;
     Creernoeud_ATii (& P ) ;
     Creernoeud_ATii (& Pp ) ;
     *A  =  P ;
     *B  =  Pp ;
     Aff_info_ATii ( P , Ch ) ;
     Aff_info_ATii ( Pp , Ch ) ;
     while( Cmp < N) {
       Aff_struct1_Tii ( Ch  , Aleanombre(1000 ) + 1 ) ;
       Aff_struct2_Tii ( Ch  , 0 ) ;
       P  =  *A ;
       Q  =  *A ;
       Pp  =  *B ;
       Qq  =  *B ;
       while( ( Struct1_Tii ( Ch  ) != Struct1_Tii ( Info_ATii ( P )  ) ) && ( Q != NULL ) && ( Qq != NULL ))  {
         P  =  Q ;
         Pp  =  Qq ;
         if( Struct1_Tii ( Ch  ) < Struct1_Tii ( Info_ATii ( P )  )) {
           Q  =  Fg_ATii ( P ) ;
           Qq  =  Fg_ATii ( Pp ) ;
           }
         else
           {
           Q  =  Fd_ATii ( P ) ;
           Qq  =  Fd_ATii ( Pp ) ;

         }
       } ;
       if( Struct1_Tii ( Ch  ) != Struct1_Tii ( Info_ATii ( P )  )) {
         Creernoeud_ATii (& Q ) ;
         Creernoeud_ATii (& Qq ) ;
         Aff_info_ATii ( Q , Ch ) ;
         Aff_info_ATii ( Qq , Ch ) ;
         if( Struct1_Tii ( Ch  ) < Struct1_Tii ( Info_ATii ( P )  )) {
           Aff_fg_ATii ( P , Q ) ;
           Aff_pere_ATii ( Q , P ) ;
           Aff_fg_ATii ( Pp , Qq ) ;
           Aff_pere_ATii ( Qq , Pp ) ;
           }
         else
           {
           Aff_fd_ATii ( P , Q ) ;
           Aff_pere_ATii ( Q , P ) ;
           Aff_fd_ATii ( Pp , Qq ) ;
           Aff_pere_ATii ( Qq , Pp ) ;

         } ;
         Cmp  =  Cmp + 1 ;

       }
     } ;
     printf ( " %s", "\n\nParcours inorder de l\'arbre : " ) ;
     Creerpile_PATii (& Pil ) ;
     P  =  *A ;
     Possible  =  True ;
     while( Possible)  {
       while( P != NULL)  {
         Empiler_PATii (& Pil , P ) ;
         P  =  Fg_ATii ( P ) ;

       } ;
       if( ! Pilevide_PATii ( Pil ))   {
         Depiler_PATii (& Pil , &P ) ;
         /** Ecriture d'une structure */
         _Struct_Temp1 = *Info_ATii(P);
         printf ( " %d", _Struct_Temp1.Champ1 );
         printf ( " %d\t", _Struct_Temp1.Champ2 ) ;
         P  =  Fd_ATii ( P ) ;
         }
       else
         {
         Possible  =  False ;

       }
     }
    }
  bool  Bst (Pointeur_ATii *R)
    {
      /** Variables locales **/
      bool  Bst2 ;
      Pointeur_ATii _Px1=NULL;
      Typestr_Tii _Px2;
      Pointeur_ATii _Px3=NULL;
      Typestr_Tii _Px4;
      Pointeur_ATii _Px5=NULL;
      Pointeur_ATii _Px6=NULL;

      /** Corps du module **/
     _Px2 = malloc(sizeof(Type_Tii));
     _Px4 = malloc(sizeof(Type_Tii));
     if( *R == NULL) {
       Bst2  =  True ;
       }
     else
       {
       _Px1 =  Fd_ATii ( *R ) ;
       _Px2 =  Info_ATii ( *R ) ;
       _Px3 =  Fg_ATii ( *R ) ;
       _Px4 =  Info_ATii ( *R ) ;
       _Px5 =  Fd_ATii ( *R ) ;
       _Px6 =  Fg_ATii ( *R ) ;
       if( ( Sub_r ( &_Px1, &_Px2) && Sub_l ( &_Px3, &_Px4) && Bst ( &_Px5) && Bst ( &_Px6) )) {
         Bst2  =  True ;
         }
       else
         {
         Bst2  =  False ;

       }
     }
     return Bst2 ;
    }
  bool  Sub_l (Pointeur_ATii *R , Typestr_Tii *X)
    {
      /** Variables locales **/
      bool  Sub_l2 ;
      Pointeur_ATii _Px1=NULL;
      Pointeur_ATii _Px2=NULL;

      /** Corps du module **/
     if( ( *R == NULL )) {
       Sub_l2  =  True ;
       }
     else
       {
       if( Struct1_Tii ( Info_ATii ( *R )  ) > Struct1_Tii ( *X  )) {
         Sub_l2  =  False ;

       } ;
       _Px1 =  Fg_ATii ( *R ) ;
       _Px2 =  Fd_ATii ( *R ) ;
       Sub_l2  =  Sub_l ( &_Px1, & *X ) && Sub_l ( &_Px2, & *X ) ;

     }
     return Sub_l2 ;
    }
  bool  Sub_r (Pointeur_ATii *R , Typestr_Tii *X)
    {
      /** Variables locales **/
      bool  Sub_r2 ;
      Pointeur_ATii _Px1=NULL;
      Pointeur_ATii _Px2=NULL;

      /** Corps du module **/
     if( ( *R == NULL )) {
       Sub_r2  =  True ;
       }
     else
       {
       if( Struct1_Tii ( Info_ATii ( *R )  ) < Struct1_Tii ( *X  )) {
         Sub_r2  =  False ;

       } ;
       _Px1 =  Fg_ATii ( *R ) ;
       _Px2 =  Fd_ATii ( *R ) ;
       Sub_r2  =  Sub_r ( &_Px1, & *X ) && Sub_r ( &_Px2, & *X ) ;

     }
     return Sub_r2 ;
    }
  int  Subbranch_length (Pointeur_ATii *R)
    {
      /** Variables locales **/
      int  Subbranch_length2 ;
      Pointeur_ATii _Px1=NULL;
      Pointeur_ATii _Px2=NULL;
      Pointeur_ATii _Px3=NULL;
      Pointeur_ATii _Px4=NULL;

      /** Corps du module **/
     if( *R == NULL) {
       Subbranch_length2  =  0 ;
      /*FSI;
     SI FG(*R)=NIL
        SI FD(*R)=NIL
           subbranch_length:=0;
        FSI   */
       }
     else
       {
       _Px1 =  Fg_ATii ( *R ) ;
       _Px2 =  Fd_ATii ( *R ) ;
       if( Subbranch_length ( &_Px1) > Subbranch_length ( &_Px2)) {
         _Px3 =  Fg_ATii ( *R ) ;
         Subbranch_length2  =  Subbranch_length ( &_Px3) + 1 ;
         }
       else
         {
         _Px4 =  Fd_ATii ( *R ) ;
         Subbranch_length2  =  Subbranch_length ( &_Px4) + 1 ;

       }
     }
     return Subbranch_length2 ;
    }
  void Traversal_two (Pointeur_ATii *R , int *L)
    {
      /** Variables locales **/
      int X;
      Pointeur_ATii _Px1=NULL;
      Pointeur_ATii _Px2=NULL;

      /** Corps du module **/
     if( *R != NULL) {
       _Px1 =  Fg_ATii ( *R ) ;
       Traversal_two ( &_Px1, & *L ) ;
       if( Subbranch_length ( & *R ) == *L) {
         X  =  Struct1_Tii ( Info_ATii ( *R )  ) ;
         printf ( " %d", X ) ;

       } ;
       _Px2 =  Fd_ATii ( *R ) ;
       Traversal_two ( &_Px2, & *L ) ;

     }
    }
  void Traversal_four (Pointeur_ATii *R , int *L)
    {
      /** Variables locales **/
      int X;
      Pointeur_ATii _Px1=NULL;
      Pointeur_ATii _Px2=NULL;

      /** Corps du module **/
     if( *R != NULL) {
       _Px1 =  Fd_ATii ( *R ) ;
       Traversal_four ( &_Px1, & *L ) ;
       if( Subbranch_length ( & *R ) == *L) {
         X  =  Struct1_Tii ( Info_ATii ( *R )  ) ;
         printf ( " %d", X ) ;

       } ;
       _Px2 =  Fg_ATii ( *R ) ;
       Traversal_four ( &_Px2, & *L ) ;

     }
    }
  void Insert_branch (Pointeur_ATii *R , Pointeur_Li *L)
    {
      /** Variables locales **/
      int _Px1;
      Pointeur_ATii _Px2=NULL;

      /** Corps du module **/
     if( *R != NULL) {
       _Px1 =  Struct1_Tii ( Info_ATii ( *R )  ) ;
       Insert_list ( & *L , &_Px1) ;
       _Px2 =  Pere_ATii ( *R ) ;
       Insert_branch ( &_Px2, & *L ) ;

     }
    }
  void Verify_one (Pointeur_ATii *R , Pointeur_Li *L)
    {
      /** Variables locales **/
      Pointeur_ATii _Px1=NULL;
      Pointeur_ATii _Px2=NULL;

      /** Corps du module **/
     if( *R != NULL) {
       _Px1 =  Fg_ATii ( *R ) ;
       Verify_one ( &_Px1, & *L ) ;
       if( Fg_ATii ( *R ) == NULL) {
         if( Fd_ATii ( *R ) == NULL) {
           Insert_branch ( & *R , & *L ) ;

         } ;

       } ;
       _Px2 =  Fd_ATii ( *R ) ;
       Verify_one ( &_Px2, & *L ) ;

     }
    }
  void Ver_t_one (Pointeur_ATii *R , Pointeur_Pi *S , Pointeur_Li *U)
    {
      /** Variables locales **/
      int P;
      Pointeur_Li T=NULL;
      Pointeur_ATii _Px1=NULL;
      Pointeur_ATii _Px2=NULL;

      /** Corps du module **/
     if( *R != NULL) {
       Empiler_Pi (& *S , Struct1_Tii ( Info_ATii ( *R )  ) ) ;
       if( ( Fg_ATii ( *R ) == NULL )) {
         if( Fd_ATii ( *R ) == NULL) {
           while( ! Pilevide_Pi ( *S )) {
             Depiler_Pi (& *S , &P ) ;
             Insert_list ( & *U , & P ) ;

           } ;

         } ;

       } ;
       _Px1 =  Fg_ATii ( *R ) ;
       Ver_t_one ( &_Px1, & *S , & *U ) ;
       _Px2 =  Fd_ATii ( *R ) ;
       Ver_t_one ( &_Px2, & *S , & *U ) ;

     }
    }
  void Rm_dup (Pointeur_Li *Lst)
    {
      /** Variables locales **/
      Pointeur_Li X=NULL;
      Pointeur_Li Y=NULL;
      Pointeur_Li Z=NULL;
      int Xval;

      /** Corps du module **/
     if( *Lst == NULL) {
       printf ( " %s", "vide" ) ;
       }
     else
       {
       X  =  Suivant_Li ( *Lst ) ;
       while( Suivant_Li ( X ) != NULL) {
         Y  =  X ;
         Z  =  Suivant_Li ( X ) ;
         while( Z != NULL) {
           Xval  =  Valeur_Li ( X ) ;
           if( Valeur_Li ( Z ) == Xval) {
             Aff_adr_Li ( Y , Suivant_Li ( Z ) ) ;
             Aff_adr_Li ( Z , NULL ) ;
             Z  =  Suivant_Li ( Y ) ;
             }
           else
             {
             Y  =  Suivant_Li ( Y ) ;
             Z  =  Suivant_Li ( Z ) ;

           }
         } ;
         X  =  Suivant_Li ( X ) ;

       } ;

     }
    }
  void Affich_list (Pointeur_Li *Lst)
    {
      /** Variables locales **/
      Pointeur_Li Temp=NULL;

      /** Corps du module **/
     Temp  =  *Lst ;
     if( Temp == NULL) {
       printf ( " %s", "LISTE VIDE" ) ;
       }
     else
       {
       Temp  =  Suivant_Li ( Temp ) ;
       while( Temp != NULL) {
         printf ( " %d", Valeur_Li(Temp) ) ;
         Temp  =  Suivant_Li ( Temp ) ;

       } ;

     } ;

    }
  bool  Comp_list (Pointeur_Li *L , Pointeur_Li *U)
    {
      /** Variables locales **/
      bool  Comp_list2 ;
      Pointeur_Li Iter1=NULL;
      Pointeur_Li Iter2=NULL;
      bool Bool;

      /** Corps du module **/
     Bool  =  True ;
     Iter1  =  Suivant_Li ( *L ) ;
     Iter2  =  Suivant_Li ( *U ) ;
     while( ( Iter1 != NULL ) && ( Iter2 != NULL ) && ( Bool == True )) {
       if( Valeur_Li ( Iter1 ) != Valeur_Li ( Iter2 )) {
         Bool  =  False ;
         }
       else
         {
         Iter1  =  Suivant_Li ( Iter1 ) ;
         Iter2  =  Suivant_Li ( Iter2 ) ;

       }
     } ;
     Comp_list2  =  Bool ;

     return Comp_list2 ;
    }
  void Verify_two (Pointeur_ATii *R , Pointeur_Li *F)
    {
      /** Variables locales **/
      Pointeur_ATii T=NULL;
      int X;
      int _Px1;
      Pointeur_ATii _Px2=NULL;
      Pointeur_ATii _Px3=NULL;

      /** Corps du module **/
     if( *R != NULL) {
       if( ( Fg_ATii ( *R ) == NULL )) {
         if( Fd_ATii ( *R ) == NULL) {
           _Px1 =  Struct1_Tii ( Info_ATii ( *R )  ) ;
           Insert_list ( & *F , &_Px1) ;
           if( Pere_ATii ( *R ) != NULL) {
             T  =  Pere_ATii ( *R ) ;
             if( *R == Fg_ATii ( T )) {
               Aff_fg_ATii ( T , NULL ) ;
               }
             else
               {
               if( *R == Fd_ATii ( T )) {
                 Aff_fd_ATii ( T , NULL ) ;
                 }
               else
                 {
                 printf ( " %s", "\nErreur de liberation du noeud" ) ;

               }
             }
           }
         }
       } ;
       _Px2 =  Fg_ATii ( *R ) ;
       Verify_two ( &_Px2, & *F ) ;
       _Px3 =  Fd_ATii ( *R ) ;
       Verify_two ( &_Px3, & *F ) ;

     }
    }
  void Ver_t_two (Pointeur_ATii *R , int *L , Pointeur_Li *W)
    {
      /** Variables locales **/
      int X;
      Pointeur_ATii _Px1=NULL;
      int _Px2;
      Pointeur_ATii _Px3=NULL;

      /** Corps du module **/
     if( *R != NULL) {
       _Px1 =  Fg_ATii ( *R ) ;
       Ver_t_two ( &_Px1, & *L , & *W ) ;
       if( Subbranch_length ( & *R ) == *L) {
         _Px2 =  Struct1_Tii ( Info_ATii ( *R )  ) ;
         Insert_list ( & *W , &_Px2) ;

       } ;
       _Px3 =  Fd_ATii ( *R ) ;
       Ver_t_two ( &_Px3, & *L , & *W ) ;

     }
    }
  void Verify_three (Pointeur_ATii *R2 , Pointeur_Li *L3)
    {
      /** Variables locales **/
      Pointeur_ATii _Px1=NULL;
      Pointeur_ATii _Px2=NULL;

      /** Corps du module **/
     if( *R2 != NULL) {
       _Px1 =  Fd_ATii ( *R2 ) ;
       Verify_three ( &_Px1, & *L3 ) ;
       if( Fg_ATii ( *R2 ) == NULL) {
         if( Fd_ATii ( *R2 ) == NULL) {
           Insert_branch ( & *R2 , & *L3 ) ;

         } ;

       } ;
       _Px2 =  Fg_ATii ( *R2 ) ;
       Verify_three ( &_Px2, & *L3 ) ;

     }
    }
  void Ver_t_three (Pointeur_ATii *R2 , Pointeur_Pi *S3 , Pointeur_Li *L3p)
    {
      /** Variables locales **/
      int P;
      Pointeur_Li T=NULL;
      Pointeur_ATii _Px1=NULL;
      Pointeur_ATii _Px2=NULL;

      /** Corps du module **/
     if( *R2 != NULL) {
       Empiler_Pi (& *S3 , Struct1_Tii ( Info_ATii ( *R2 )  ) ) ;
       if( ( Fg_ATii ( *R2 ) == NULL )) {
         if( Fd_ATii ( *R2 ) == NULL) {
           while( ! Pilevide_Pi ( *S3 )) {
             Depiler_Pi (& *S3 , &P ) ;
             Insert_list ( & *L3p , & P ) ;

           } ;

         } ;

       } ;
       _Px1 =  Fd_ATii ( *R2 ) ;
       Ver_t_three ( &_Px1, & *S3 , & *L3p ) ;
       _Px2 =  Fg_ATii ( *R2 ) ;
       Ver_t_three ( &_Px2, & *S3 , & *L3p ) ;

     }
    }
  void Verify_four (Pointeur_ATii *R , Pointeur_Li *F)
    {
      /** Variables locales **/
      Pointeur_ATii T=NULL;
      int X;
      int _Px1;
      Pointeur_ATii _Px2=NULL;
      Pointeur_ATii _Px3=NULL;

      /** Corps du module **/
     if( *R != NULL) {
       if( ( Fg_ATii ( *R ) == NULL )) {
         if( Fd_ATii ( *R ) == NULL) {
           _Px1 =  Struct1_Tii ( Info_ATii ( *R )  ) ;
           Insert_list ( & *F , &_Px1) ;
           if( Pere_ATii ( *R ) != NULL) {
             T  =  Pere_ATii ( *R ) ;
             if( *R == Fg_ATii ( T )) {
               Aff_fg_ATii ( T , NULL ) ;
               }
             else
               {
               if( *R == Fd_ATii ( T )) {
                 Aff_fd_ATii ( T , NULL ) ;
                 }
               else
                 {
                 printf ( " %s", "\nErreur de liberation du noeud" ) ;

               }
             }
           }
         }
       } ;
       _Px2 =  Fd_ATii ( *R ) ;
       Verify_four ( &_Px2, & *F ) ;
       _Px3 =  Fg_ATii ( *R ) ;
       Verify_four ( &_Px3, & *F ) ;

     }
    }
  void Ver_t_four (Pointeur_ATii *R , int *L , Pointeur_Li *W)
    {
      /** Variables locales **/
      int X;
      Pointeur_ATii _Px1=NULL;
      int _Px2;
      Pointeur_ATii _Px3=NULL;

      /** Corps du module **/
     if( *R != NULL) {
       _Px1 =  Fd_ATii ( *R ) ;
       Ver_t_four ( &_Px1, & *L , & *W ) ;
       if( Subbranch_length ( & *R ) == *L) {
         _Px2 =  Struct1_Tii ( Info_ATii ( *R )  ) ;
         Insert_list ( & *W , &_Px2) ;

       } ;
       _Px3 =  Fg_ATii ( *R ) ;
       Ver_t_four ( &_Px3, & *L , & *W ) ;

     }
    }

    void print_spaces(int s)
    {
        int i;
        for (i=0;i<s;i++){
            printf("   ");
        }
    }

    void affich_tree_one(Pointeur_ATii R, int a, int b, int d)
    {
        Pointeur_ATii V=NULL;
        Creernoeud_ATii(&V);
        Aff_struct1_Tii(V, 0);
        Aff_struct2_Tii(V, 0);
        Pointer_Q F=NULL;
        Pointeur_ATii S=NULL;
        Create_Queue(&F);
        int c=0;
        int n=0;
        int p=1;
        int l=16;
        Enqueue(F, R);
        n++;
        printf("\n");
        while (!Empty_Queue(F) && n<16){
            Dequeue(F, &S);
            print_spaces(l-1);
            if (S!=V){
                    if (n==1 || n==a || n==b || n==d){
                    printf("\033[0;31m"); //Set the text to the color red
                    printf("%d", Struct1_Tii(S->Val));
                    printf("\033[0m"); //Resets the text to default color
                    } else {printf("%d", Struct1_Tii(S->Val));}
            } else {
                printf("   ");
                }
            print_spaces(l);
            c++;
            n++;
            if (c==p){
                printf("\n\n");
                l=l/2;
                c=0;
                p=p*2;
            }
            if (Fg_ATii(S)!=NULL){
                Enqueue(F, Fg_ATii(S));
            } else {Enqueue(F, V);}
            if (Fd_ATii(S)!=NULL){
                Enqueue(F, Fd_ATii(S));
            } else {Enqueue(F, V);}
        }
    }

    void affich_tree_two(Pointeur_ATii R, int a, int b)
    {
        Pointeur_ATii V=NULL;
        Creernoeud_ATii(&V);
        Aff_struct1_Tii(V, 0);
        Aff_struct2_Tii(V, 0);
        Pointer_Q F=NULL;
        Pointeur_ATii S=NULL;
        Create_Queue(&F);
        int c=0;
        int n=0;
        int p=1;
        int l=16;
        Enqueue(F, R);
        n++;
        printf("\n");
        while (!Empty_Queue(F) && n<16){
            Dequeue(F, &S);
            print_spaces(l-1);
            if (S!=V){
                    if (p==a && b==c){
                    printf("\033[0;32m"); //Set the text to the color red
                    printf("%d", Struct1_Tii(S->Val));
                    printf("\033[0m"); //Resets the text to default color
                    } else {printf("%d", Struct1_Tii(S->Val));}
            } else {
                printf("   ");
                }
            print_spaces(l);
            c++;
            n++;
            if (c==p){
                printf("\n\n");
                l=l/2;
                c=0;
                p=p*2;
            }
            if (Fg_ATii(S)!=NULL){
                Enqueue(F, Fg_ATii(S));
            } else {Enqueue(F, V);}
            if (Fd_ATii(S)!=NULL){
                Enqueue(F, Fd_ATii(S));
            } else {Enqueue(F, V);}
        }
    }



    void affich_tree_three(Pointeur_ATii R, int a, int b, int d)
    {
        Pointeur_ATii V=NULL;
        Creernoeud_ATii(&V);
        Aff_struct1_Tii(V, 0);
        Aff_struct2_Tii(V, 0);
        Pointer_Q F=NULL;
        Pointeur_ATii S=NULL;
        Create_Queue(&F);
        int c=0;
        int n=0;
        int p=1;
        int l=16;
        Enqueue(F, R);
        n++;
        printf("\n");
        while (!Empty_Queue(F) && n<16){
            Dequeue(F, &S);
            print_spaces(l-1);
            if (S!=V){
                    if (n==1 || n==a || n==b || n==d){
                    printf("\033[0;34m"); //Set the text to the color red
                    printf("%d", Struct1_Tii(S->Val));
                    printf("\033[0m"); //Resets the text to default color
                    } else {printf("%d", Struct1_Tii(S->Val));}
            } else {
                printf("   ");
                }
            print_spaces(l);
            c++;
            n++;
            if (c==p){
                printf("\n\n");
                l=l/2;
                c=0;
                p=p*2;
            }
            if (Fg_ATii(S)!=NULL){
                Enqueue(F, Fg_ATii(S));
            } else {Enqueue(F, V);}
            if (Fd_ATii(S)!=NULL){
                Enqueue(F, Fd_ATii(S));
            } else {Enqueue(F, V);}
        }
    }

    void affich_tree_four(Pointeur_ATii R, int a)
    {
        Pointeur_ATii V=NULL;
        Creernoeud_ATii(&V);
        Aff_struct1_Tii(V, 0);
        Aff_struct2_Tii(V, 0);
        Pointer_Q F=NULL;
        Pointeur_ATii S=NULL;
        Create_Queue(&F);
        int c=0;
        int n=0;
        int p=1;
        int l=16;
        Enqueue(F, R);
        n++;
        printf("\n");
        while (!Empty_Queue(F) && n<16){
            Dequeue(F, &S);
            print_spaces(l-1);
            if (S!=V){
                    if (n==a){
                    printf("\033[0;35m"); //Set the text to the color red
                    printf("%d", Struct1_Tii(S->Val));
                    printf("\033[0m"); //Resets the text to default color
                    } else {printf("%d", Struct1_Tii(S->Val));}
            } else {
                printf("   ");
                }
            print_spaces(l);
            c++;
            n++;
            if (c==p){
                printf("\n\n");
                l=l/2;
                c=0;
                p=p*2;
            }
            if (Fg_ATii(S)!=NULL){
                Enqueue(F, Fg_ATii(S));
            } else {Enqueue(F, V);}
            if (Fd_ATii(S)!=NULL){
                Enqueue(F, Fd_ATii(S));
            } else {Enqueue(F, V);}
        }
    }


  int main(int argc, char *argv[])
    {
     srand(time(NULL));
     printf ( " %s", "---------------------------------------------\n" ) ;
     printf ( " %s", "|             TP Z    2023/2024             |\n" ) ;
     printf ( " %s", "|   DJOUADJ ABDERRAHMANE & ZIAINIA YACINE   |\n" ) ;
     printf ( " %s", "|                 1CP D G15                 |\n" ) ;
     printf ( " %s", "---------------------------------------------\n" ) ;

     printf ( " %s", "\n***********BIENVENUE DANS NOTRE TP Z***********\n" ) ;
     printf("\nCliquez pour commencer...\n");
     system("pause");

     for( M  =  1 ;M <=  10 ; ++M){
        printf ( " %s", "\n\nITIRATION NUMERO " );
       printf ( " %d : ", M ) ;
       Creer_arbre ( & R , & R2 ) ;
       if( Bst ( & R )) {
         printf ( " %s", "\nL\'arbre cree est BST" ) ;
         }
       else
         {
         printf ( " %s", "\nErreur : l\'arbre n\'est pas BST" );
       } ;


       printf ( " %s", "\n\n************TRAVERSAL ONE************\n" ) ;
       Creerpile_PTii (& S1 ) ;
       Traversal_one ( & R , & S1 ) ;

       printf("\n\nAnimation Traversal one : \n\n");
        system("pause");
        system("cls");
        int a=2;
        int b=4;
        int d =8;
       while (d<=15){
            affich_tree_one(R, a,b,d);
            d++;
            if (d%2==0){b++;}
            if (b%3==0 && d%2==0){a++;}
            Sleep(1000);
            if (d<=15){system("cls");}
       }

       printf ( " %s", "\n\n************TRAVERSAL TWO************\n" ) ;
       for( I  =  1 ;I <=  Subbranch_length ( & R ) ; ++I){
         Traversal_two ( & R , & I ) ;
       } ;

       printf("\n\nAnimation Traversal two : \n\n");
        system("pause");
        system("cls");
        a=8;
       while (a>=1){
        b=0;
            while (b<a){
                affich_tree_two(R, a,b);
                b++;
                Sleep(1000);
                if (a>1){system("cls");}
            }
            a=a/2;
       }


       printf ( " %s", "\n\n************TRAVERSAL THREE************\n" ) ;
       Creerpile_PTii (& S3 ) ;
       Traversal_three ( & R , & S3 ) ;

       printf("\n\nAnimation Traversal three : \n\n");
        system("pause");
        system("cls");
        a=3;
        b=7;
        d =15;
       while (d>=8){
            affich_tree_three(R, a,b,d);
            d--;
            if (d%2==1){b--;}
            if (b%3==2 && d%2==01){a--;}
            Sleep(1000);
            if (d>=8){system("cls");}
       }

       printf ( " %s", "\n\n************TRAVERSAL FOUR************\n" ) ;
       for( I  =  1 ;I <=  Subbranch_length ( & R ) ; ++I){
         Traversal_four ( & R , & I ) ;
       } ;

       printf("\n\nAnimation Traversal four : \n\n");
        system("pause");
        system("cls");
        a=15;
       while (a>=1){
            //while (b<a){
                affich_tree_four(R, a);
                a--;
                Sleep(1000);
                if (a>0){system("cls");}
            //}
       }

       printf ( " %s", "\n\n************VERIFY ONE************" ) ;
       printf ( " %s", "\nListe traversal one : \n" ) ;
       Allouer_Li (& L1 ) ;
       Creerpile_Pi (& S1p ) ;
       Ver_t_one ( & R , & S1p , & L1 ) ;
       Affich_list ( & L1 ) ;
       printf ( " %s", "\nVerification traversal one (avec doubles) : \n" ) ;
       Allouer_Li (& L1p ) ;
       Verify_one ( & R , & L1p ) ;
       Affich_list ( & L1p ) ;
       printf ( " %s", "\nVerification traversal one sans doubles : \n" ) ;
       Rm_dup ( & L1p ) ;
       Affich_list ( & L1p ) ;
       if( Comp_list ( & L1p , & L1 ) == True) {
         printf ( " %s", "\nComparaison... Listes identiques" ) ;
         }
       else
         {
         printf ( " %s", "\nErreur : Les listes ne sont pas identiques!" ) ;

       } ;
       printf ( " %s", "\n\n************VERIFY TWO************" ) ;
       printf ( " %s", "\nListe traversal two : \n" ) ;
       Allouer_Li (& L2 ) ;
       for( I  =  1 ;I <=  Subbranch_length ( & R ) ; ++I){
         Ver_t_two ( & R , & I , & L2 ) ;

       } ;
       Affich_list ( & L2 ) ;
       printf ( " %s", "\nVerification traversal two : \n" ) ;
       Allouer_Li (& L2p ) ;
       while( ( Fg_ATii ( R ) != NULL ) || ( Fd_ATii ( R ) != NULL )) {
         Verify_two ( & R , & L2p ) ;

       } ;
       if( ( Pere_ATii ( R ) == NULL ) && ( Fg_ATii ( R ) == NULL ) && ( Fd_ATii ( R ) == NULL )) {
         _Px1 =  Struct1_Tii ( Info_ATii ( R )  ) ;
         Insert_list ( & L2p , &_Px1) ;
         Rp  =  R ;
         Liberernoeud_ATii ( Rp ) ;

       } ;
       Affich_list ( & L2p ) ;
       if( Comp_list ( & L2p , & L2 ) == True) {
         printf ( " %s", "\nComparaison... Listes identiques" ) ;
         }
       else
         {
         printf ( " %s", "\nErreur : Les listes ne sont pas identiques!" ) ;

       } ;
       printf ( " %s", "\n\n************VERIFY THREE************" ) ;
       printf ( " %s", "\nListe traversal three : \n" ) ;
       Allouer_Li (& L3 ) ;
       Creerpile_Pi (& S3p ) ;
       Ver_t_three ( & R2 , & S3p , & L3 ) ;
       Affich_list ( & L3 ) ;
       printf ( " %s", "\nVerification traversal three (avec doubles) : \n" ) ;
       Allouer_Li (& L3p ) ;
       Verify_three ( & R2 , & L3p ) ;
       Affich_list ( & L3p ) ;
       printf ( " %s", "\nListe traversal three sans doubles : \n" ) ;
       Rm_dup ( & L3p ) ;
       Affich_list ( & L3p ) ;
       if( Comp_list ( & L3p , & L3 ) == True) {
         printf ( " %s", "\nComparaison... Listes identiques" ) ;
         }
       else
         {
         printf ( " %s", "\nErreur : Les listes ne sont pas identiques!" ) ;

       } ;
       printf ( " %s", "\n\n************VERIFY FOUR************" ) ;
       printf ( " %s", "\nListe traversal four : \n" ) ;
       Allouer_Li (& L4 ) ;
       for( I  =  1 ;I <=  Subbranch_length ( & R2 ) ; ++I){
         Ver_t_four ( & R2 , & I , & L4 ) ;

       } ;
       Affich_list ( & L4 ) ;
       printf ( " %s", "\nVerification traversal four : \n" ) ;
       Allouer_Li (& L4p ) ;
       while( ( Fg_ATii ( R2 ) != NULL ) || ( Fd_ATii ( R2 ) != NULL )) {
         Verify_four ( & R2 , & L4p ) ;

       } ;
       if( ( Pere_ATii ( R2 ) == NULL ) && ( Fg_ATii ( R2 ) == NULL ) && ( Fd_ATii ( R2 ) == NULL )) {
         _Px2 =  Struct1_Tii ( Info_ATii ( R2 )  ) ;
         Insert_list ( & L4p , &_Px2) ;
         Rp  =  R2 ;
         Liberernoeud_ATii ( Rp ) ;

       } ;
       Affich_list ( & L4p ) ;
       if( Comp_list ( & L4p , & L4 ) == True) {
         printf ( " %s", "\nComparaison... Listes identiques" ) ;
         }
       else
         {
         printf ( " %s", "\nErreur : Les listes ne sont pas identiques!" ) ;

       } ;


     }

     printf ( " %s", "\n\n************FIN DU TP************" ) ;
      return 0;
     } ;


