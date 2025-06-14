#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // For getch()
#include <time.h>
#include <windows.h>




#define MAX_RECORDS 1024
#define MAXINDEX 100000 // Number of cases in the index
#define MAX_BLOC_INDEX 1024 // Number of records per block in the index file


/* Types for LnOF file */

/* Header */
typedef struct Tentete {
    int tete;
    int queue;
} Tentete;

/* Record in the block */
typedef struct Tenreg {
    int id;
    char title[71]; // Max 70 characters + null terminator
    char author[31]; // Max 30 characters + null terminator
    int type;
    int domain;
    int pub_year;
    int qty;
} Tenreg;

/* Block */
typedef struct Tbloc {
    Tenreg tab[MAX_RECORDS];
    int suivant;
    int NB;
} Tbloc;

/* Index */
typedef struct caseindex {
    int id;
    int bloc;
    int dep;
} caseindex;

/* Index Table */
typedef struct index {
    caseindex tab[MAXINDEX];
    int taille;
} index;

/* Index File Header */
typedef struct iEntete {
    int nbBloc;
} iEntete;

/* Index File */
typedef struct fIndex {
    FILE *f;
    iEntete entete;
} fIndex;
typedef struct tBlocIndex
{
    caseindex tab[MAX_BLOC_INDEX];
    int NB;

} tBlocIndex;

/* Logical File */
typedef struct LnOF {
    FILE *f;
    Tentete entete;
    index *indexp;
} LnOF;
/* TOF Entete */
typedef struct tofentete {
    int nbBloc; /* Number of blocs */
} tofentete;
/* TOF Block */
typedef struct TblocTOF {
    Tenreg tab[MAX_RECORDS];
    int NB;
} TblocTOF;

/* Global Variables */
index indextab;
LnOF library;
int nombreEcrireDir = 0;
int nombreLireDir = 0;
typedef struct SearchResult {
    int dep;        // The dep value of the found record
    int bloc;     // The number of blocks in the index
} SearchResult;

index indextab_TOF;
int TOF_created=0;
int indextabtof_created =0;

/* Prototypes of the abstract machine */
int getheader(LnOF *fichier, int i);
void setheader(LnOF *fichier, int i, int val);
void open(LnOF *fichier, char *nomF, char mode);
void close(LnOF *fichier);
void readbloc(LnOF *fichier, int i, Tbloc *buf);
void writebloc(LnOF *fichier, int i, Tbloc *buf);
int allocbloc(LnOF *fichier);
void generateRandomRecord(Tenreg *record);
void initializeLibrary(char *filename, int N);
int compareCaseIndex(const void *a, const void *b);
void sauvIndexPr(char nomIndex[], index *indexp);
void printIndexFile(const char *filename);
SearchResult binarysearch(int searchId);
void loadIndexFromBinaryFile(const char *filename, index *indextab);
void removeRecordsByType(int typeToRemove);
void displaydomain(int domainn) ;
int getyear() ;
void displaytypeyear(int type, int currentYear) ;
void Textecolor(int ForgC);
void createTOF(const char *inputFile, const char *outputFile);
int compareByID(const void *a, const void *b);
void searchByIdInTOF(const char *filename, int searchId) ;
void displayTOF(const char *filename) ;
void displayBlock(const char *filename, int blockNumber) ;
void displayTentete(const char *filename);
void displaytofentete(const char *filename);



/* Constants */
const char *types[] = {"Ouvrages et manuels", "Revues et periodiques", "Actes de conferences",
                       "Rapports de recherche", "Memoires et theses", "Polycopies et support de cours"};

const char *domains[] = {"Algorithmes et structures de donnees", "Intelligence artificielle et apprentissage automatique",
                         "Systemes d'exploitation", "Cybersecurite", "Bases de données et gestion des donnees",
                         "Reseaux et telecommunications", "Genie logiciel, programmation et developpement logiciel",
                         "Informatique graphique, multimedia, vision par ordinateur et traitement d’images",
                         "Science des donnees et statistiques", "Robotique et systèmes embarques",
                         "Blockchain et technologies distribuees", "Calcul haute performance et informatique quantique"};
int idToSearch;
