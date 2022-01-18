#include <iostream>
#include <cstring> // utilise pour strlen
using namespace std;

void tableaux();
void pointeurs();
void tableaux_dyn();
void references();
void fonctions();

int main()
{

    tableaux();

    pointeurs();

    tableaux_dyn();

    references();

    fonctions();

    return 0;
}

//////////////////////////////
// creation de tableaux statiques
void tableaux() {

    cout << "********************" << endl;
    cout << "****  TABLEAUX  ****" << endl;
    cout << "********************" << endl;

    // tableau de 3 entiers
    // notons qu'il faut specifier la taille du tableau
    int A[3]; // c'est un type double [3] : tableau de 3 double

    // on peut ensuite initialiser les valeurs
    // (noter que les indices commencent a 0)
    A[0] = 1;
    A[1] = 5;
    A[2] = -6;

    // on peut acceder aux valeurs de facon similaire
    cout << "Lecture du tableau 1 :";
    for(int i=0; i<3; i++)
        cout << " " << A[i];
    cout << endl;

    // on peut aussi initialiser un tableau des sa declaration
    // notons que dans ce cas, il n'est pas necessaire de specifier sa taille
    // (on peut mais ce n'est pas necessaire)
    double B[] = {5., -4.5, -8.2, 4.1}; // c'est un type double [] : tableau de double

    cout << "Lecture du tableau 2 :";
    for(int i=0; i<4; i++)
        cout << " " << B[i];
    cout << endl;

    // On peut recuperer la taille d'un tableau de la facon suivante
    cout << "taille du tableau 1 : "
         << sizeof(A) / sizeof(int) << endl;
    cout << "taille du tableau 2 : "
         << sizeof(B) / sizeof(double) << endl;


    // tableaux a double entree (matrices)
    // notons qu'ici il faut specifier la taille dans chaque direction
    int M[3][3] = {{1,0,0},
                   {0,1,0},
                   {0,0,1}};

    // On peut modifier les valeurs comme ceci :
    M[1][1] = 2;
    // notons que, comme partout en c++, les indices commencent a 0

    cout << "Lecture de la matrice : " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << " " << M[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // notons qu'on peut utiliser des tableaux d'autres types
    // par exemple, on peut utiliser un tableau de char pour stocker un mot (ou plusieurs)
    char mot[20]; // tableau de 20 char (caracteres)
    cout << "Entrer un mot :" << endl;
    cin >> mot;
    cout << "taille maximale du mot : " << sizeof(mot)/sizeof(char) << endl;
    cout << "taille effective du mot : " << strlen(mot) << endl;
    cout << "le mot est :" << endl;
    for(int i=0; i<strlen(mot); i++)
        cout << mot[i];
    cout << endl;
    
    cout << endl;
}

/////////////////////////////////
// introduction aux pointeurs
// definition et operations de base
void pointeurs() {

    cout << "********************" << endl;
    cout << "****  POINTEURS  ***" << endl;
    cout << "********************" << endl;

    // un pointeur correspond a l'adresse memoire d'une variable
    int a = 1;
    int *pa; // ici "int *" est le type "pointeur vers une variable entiere"
    // on peut aussi utiliser l'ecriture suivante
    // int* pa;
    pa = &a; // ici "&a" renvoie l'adresse memoire de la variable a
             // notons que pour s'y retrouver, on note "pa" un pointeur vers "a"

    cout << "pa = " << pa << endl;
    cout << "Avant modif : *pa = " << *pa << endl; // renvoie la valeur stockee a l'adresse pa
    // pa correspond a une adresse memoire (le debut "0x" signifie que l'adresse est donnee en hexadecimal)

    // On peut modifier la valeur stockee en pa comme ceci
    *pa = 6;
    cout << "Apres modif : *pa = " << *pa << endl;
    // en fait *pa correspond a lire/ecrire sur la valeur contenue dans pa



    // deux pointeurs sur la meme adresse
    int *p = &a;
    cout << "avant modif : *p = " << *p << "  *pa = " << *pa << endl;
    *p = -4;
    cout << "apres modif : *p = " << *p << "  *pa = " << *pa << endl;
    // si on modifie la valeur a travers un pointeur, cela modifie aussi la valeur de l'autre
    // (normal vu que l'info est stockee a la meme adresse)

    // lorsqu'un pointeur n'est pas initialise (lorsqu'on ne lui a pas encore attribue d'adresse memoire)
    // en general on lui donne la valeur NULL pour mettre en evidence le fait qu'il n'est pas initialise
    // c'est une adresse memoire arbitraire qui signifie que le pointeur n'est pas initialise
    double *ptest = NULL;
    if(ptest == NULL)
        cout << "ptest n'est pas initialise" << endl;

    cout << endl;
}


/////////////////////////////////
// tableaux dynamiques
// allocation dynamique de memoire
void tableaux_dyn() {
    cout << "********************" << endl;
    cout << "*** TABLEAUX DYN ***" << endl;
    cout << "********************" << endl;

    // un tableau statique connait sa taille a la compilation
    // un tableau dynamique connait sa taille a l'execution

    int n;
    cout << "Quelle taille de tableau voulez-vous ? : ";
    cin >> n;

    // si n n'est pas strictement pos, alors on met fin a la fonction
    if( !(n > 0) )
    {
        cout << "Erreur : n doit etre strictement positif !!" << endl;
        return; // cette instruction met fin a une fonction qui renvoie void
    }
    cout << "creation du tableau ..." << endl;

    // une premiere possibilite est d'utiliser les tableaux comme vus precedemment
    int A[n];
    for(int i=0; i<n; i++)
        A[i] = i;

    cout << "A = [ ";
    for(int i=0; i<n; i++)
        cout << A[i] << " ";
    cout << "]" << endl;

    // la memoire allouee sera liberee des qu'on quittera la portee de la variable
    // notons tout de meme que ce n'est pas la facon classique de faire en c++

    // une autre facon de faire est de controler soi-meme l'allocation et la liberation memoire
    int *B; // on definit un pointeur (donc une adresse memoire)
    B = new int[n]; // new int[n] alloue de la memoire pour n entiers, l'adresse associee est stockee dans B

    for(int i=0; i<n; i++)
        B[i] = i;

    cout << "B = [ ";
    for(int i=0; i<n; i++)
        cout << B[i] << " ";
    cout << "]" << endl;

    // attention : rien n'empeche de faire
    cout << B[n] << endl;
    // ce qu'il faut eviter car lit/ecrit dans une case de memoire non attribuee

    // notons que l'adresse memoire du premier element d'un tableau correspond a l'adresse du tableau
    // l'adresse memoire du nieme element d'un tableau correspond a l'adresse memoire du tableau + n
    cout << "B = " << B << endl;
    for(int i=0; i<n; i++)
    {
        cout << "&B[" << i << "] = " << &B[i]
             << "   B+" << i << " = " << B+i
             << endl;
    }

    // Au passage, noter la valeur de *B
    cout << "*B = " << *B << endl << endl;

    delete [] B; // libere la memoire allouee a l'adresse B
                 // attention : ne pas oublier cette etape, sinon la memoire reste allouee (fuite memoire)
                 // un reflexe : a chaque "new" correspond un "delete"


    // on peut aussi utiliser new pour allouer de la memoire pour un seul element
    // cette utilisation est rare mais tres utile dans certains cas
    // l'idee est que la memoire va rester allouee tant qu'on n'aura pas utilise un delete sur cette adresse
    // permet soit de la liberer plus tot, soit plus tard
    int *C = new int; // comme on alloue une seule valeur, il n'y a pas de crochets
    *C = 10;
    cout << "*C = " << *C << endl;

    delete C; // ne pas oublier de liberer la memoire allouee
              // a noter que comme on libere une seule valeur, il n'y a pas de crochets

    cout << endl;
}


/////////////////////////////////
// references
void references() {
    cout << "********************" << endl;
    cout << "**** REFERENCES ****" << endl;
    cout << "********************" << endl;

    // les references sont des alias :
    // comme pour deux pointeurs sur la meme variable, si on modifie un alias, ca les modifie tous
    // la grosse diff avec les pointeurs : on manipule des variables et pas des adresses

    // b init par copie
    {
        int a = 1;
        int b = a; // ici on cree une variable b independante de a et on init b avec la valeur de a
        b = 2;     // si on change b, ca ne changera pas a
        cout << "init b par copie : a = " << a << " b = " << b << endl;

        cout << "adresse memoire de a : " << &a << endl;
        cout << "adresse memoire de b : " << &b << endl;
        cout << endl;
    }

    // b init par reference
    {
        int a = 1;
        int &b = a; // ici on cree une variable b qui partage la meme adresse memoire que a
                    // attention : ne pas confondre le "&" des references (qui fait partie du type)
                    //             avec le "&" correspondant aux adresses memoire (qui est un operateur)
        // on peut aussi utiliser l'ecriture suivante
        // int& b = a;
        b = 2;      // si on change b, ca change aussi a
        cout << "init b par reference : a = " << a << " b = " << b << endl;

        cout << "adresse memoire de a : " << &a << endl;
        cout << "adresse memoire de b : " << &b << endl;
    }

    cout << endl;
}


/////////////////////////////////
// fonctions
void modif(int a) { a = 10; cout << "dans f : a = " << a << endl; }
void modif(int *pa) { *pa = 10; cout << "dans f : *pa = " << *pa << endl; }
void modif_ref(int &a) { a = 10; cout << "dans f : a = " << a << endl; }
// possibilite du passage par reference constante si on ne veut pas modifier la valeur
void ref_const(const int &a) { cout << "dans f : a = " << a << endl; }

void ecrire_tab(int tab[]) { cout << "taille du tableau : " << sizeof(tab) / sizeof(int) << endl;}
void ecrire_tab(int tab[], int n) {
    cout << "taille du tableau : " << n << endl;
    for(int i=0; i<n; i++)
        cout << "tab[" << i << "] = " << tab[i] << endl;
}
void modif_tab(int tab[], int n) {
    for(int i=0; i<n; i++)
        tab[i]++;
    cout << "tableau modifie" << endl;
}

void fonctions() {
    cout << "********************" << endl;
    cout << "**** FONCTIONS *****" << endl;
    cout << "********************" << endl;

    /*
     * Passage des arguments par copie/pointeur/reference/reference constante
     */

    // passage des arguments par copie
    // ici la valeur de a est copiee a l'entree de la fonction
    // la fonction n'a aucun moyen de modifier a
    {
        int a = 1;
        modif(a);
        cout << "passage par copie : a = " << a << endl;
    }

    // passage d'un pointeur (par copie)
    // ici le pointeur (donc l'adresse de a) est copie a l'entree de la fonction
    // la fonction n'a aucun moyen de modifier cette adresse
    // par contre, elle peut utiliser l'adresse pour modifier la valeur de a
    {
        int a = 1;
        modif(&a);
        cout << "passage d'un pointeur : a = " << a << endl;
    }

    // passage des arguments par reference
    // revient au meme que le passage du pointeur mais beaucoup plus commode a utiliser
    // on passe a la fonction un alias vers a : elle peut modifier la valeur de a
    {
        int a = 1;
        modif_ref(a);
        cout << "passage par reference : a = " << a << endl;
    }

    // un premier interet du passage des arguments par reference
    // est de pouvoir modifier leur valeur dans la fonction

    // un deuxieme interet est qu'il n'y a pas besoin de copier l'argument
    // -> s'il s'agit d'un argument tres tres gros en terme de memoire,
    // alors on gagne du temps en le passant par reference car on economise l'operation de copie
    // ceci apparait quand on utilise des types beaucoup plus complexes que les types de base (voir les classes)

    // dans le deuxieme cas, on peut vouloir passer un argument par reference constante :
    // dans ce cas, on passe un alias vers la fonction (donc pas de surcout lie a la copie)
    // par contre le programme s'assure que l'on n'apporte aucune modification a cet argument
    // c'est tres utile quand on ne compte pas modifier la valeur de cet argument
    cout << "utilisation du passage par reference constante :" << endl;
    ref_const(1);



    /*
     * Passage d'un tableau en argument
     */
    cout << endl;

    // on s'interesse a un tableau de 4 entiers
    int tab[] = {1,5,6,9};

    // on veut une fonction qui ecrive ces entiers dans le terminal
    // la difficulte est que lorsque ce tableau est donne en argument a une fonction
    // la fonction le considere comme un pointeur et l'on perd l'information
    // de la taille de ce tableau
    cout << "taille du tableau : " << sizeof(tab) / sizeof(int) << endl;
    ecrire_tab(tab);

    // la methode classique pour garder l'information de la taille du tableau
    // est d'ajouter un argument entier
    ecrire_tab(tab, sizeof(tab) / sizeof(int));

    // notons egalement que comme un tableau en argument est gere comme un pointeur,
    // on peut modifier ses valeurs
    modif_tab(tab, sizeof(tab) / sizeof(int));
    ecrire_tab(tab, sizeof(tab) / sizeof(int));

    cout << endl;
}
