#include <iostream>

int main()
{
    // typage statique des variables
    std::cout << std::endl
              << "///////////////////////" << std::endl;
    std::cout << "/ TYPAGE DES VARIABLES " << std::endl;
    std::cout << "///////////////////////" << std::endl << std::endl;
    // debut d'un bloc de code
    {
        // int est un entier
        int a = 1;
        // float est un reel
        float b = 0.5;
        // double est un reel (double precision)
        double c = 0.1;
        // char est un caractere
        char carac = 'a';
        // string est une chaine de caracteres
        std::string mot = "bonjour";
        // bool est un booleen (vrai ou faux)
        bool test = true; // bool test = false;

        // notons qu'on ne peut pas redefinir une variable deja definie
        // l'instruction suivante ne compilera pas
        // double b;

        std::cout << "a*b = " << a*b << std::endl;
        std::cout << "carac = " << carac << std::endl;
        std::cout << "mot = " << mot << std::endl;

        // on peut aussi changer la valeur d'une variable deja definie
        a = 5;
        std::cout << "nouvelle valeur de a = " << a << std::endl;

        // On peut convertir (cast) un type en un autre
        // par exemple, ici, on convertit un double en un int :
        double d = 3.7;
        std::cout << "d = " << d << std::endl;
        std::cout << "(int) d = " << (int) d << std::endl;

        // On peut demander a une variable d'etre constante
        // dans ce cas, on ne pourra pas modifier sa valeur dans la suite du programme
        const double x = 8.4; // definition d'un double constant
        const int y = 7;      // definition d'un int constant
        // l'instruction suivante ne compilera pas
        // x = 5.1;
    }
    // fin du bloc de code

    // on peut verifier que a (defini dans le bloc precedent) n'est pas defini ici
    // la portee de la variable a est limitee a son bloc de code
    // a = 6;

    // les tests logiques
    std::cout << std::endl
              << "///////////////////////" << std::endl;
    std::cout << "OPERATEURS ARITHMETIQUES" << std::endl;
    std::cout << "///////////////////////" << std::endl << std::endl;
    // debut du bloc
    {
        // on definit trois variables
        int a = 5, b = 10; // ici on a defini deux int sur la meme ligne et on les a tous les deux initialises
        double c = 0.4;

        // on peut utiliser les operateurs classiques (ces operateurs fonctionnent aussi sur les reels : essayer avec c)
        std::cout << "a+b = " << a+b << std::endl; // addition
        std::cout << "a-b = " << a-b << std::endl; // soustraction
        std::cout << "a*b = " << a*b << std::endl; // multiplication
        std::cout << "a/b = " << a/b << std::endl; // division

        // attention (tres important !!) : la division entre deux entiers est une division euclidienne
        // par exemple 5/10 = 0
        // si vous voulez obtenir une division "reelle", il faut que l'un des deux arguments soit un reel
        // on peut par exemple convertir la valeur de a en un reel avant de faire la division
        std::cout << "(double) a/b = " << (double) a/b << std::endl; // division reelle

        // l'operateur % entre deux int correspond au reste de la division euclidienne
        // de sorte que a vaut (a/b)*b + a%b (ou a/b est le quotient)
        std::cout << "a%b = " << a%b << std::endl; // reste de la division euclidienne

        // autres operateurs
        c += a; // correspond a : c = c + a
        c -= a; // correspond a : c = c - a
        c /= a; // correspond a : c = c / a
        c *= a; // correspond a : c = c * a

        // apres ces operations, la valeur de c est restee la meme :
        std::cout << "c = " << c << std::endl;

        a %= b; // correspond a : a = a % b;
        // bien entendu cette operation ne fonctionne que sur les entiers
        // c %= a;

        // operateur ++ incremente la valeur d'une variable (fonctionne aussi sur les reels)
        std::cout << std::endl;
        std::cout << "a avant : " << a << std::endl;
        std::cout << "a++ = " << a++ << std::endl;
        std::cout << "a apres : " << a << std::endl; // la nouvelle valeur de a est donnee par : a = a + 1

        // une petite subtilite entre a++ et ++a est l'ordre entre incrementation et valeur de retour de l'operateur
        std::cout << std::endl;
        std::cout << "a avant : " << a << std::endl;
        std::cout << "++a = " << ++a << std::endl;
        std::cout << "a apres : " << a << std::endl; // la nouvelle valeur de a est donnee par : a = a + 1

        // de la meme facon : --a et a-- decrementent la valeur de a
    }
    // fin du bloc

    // les tests logiques
    std::cout << std::endl
              << "///////////////////////" << std::endl;
    std::cout << "/// TESTS LOGIQUES ////" << std::endl;
    std::cout << "///////////////////////" << std::endl << std::endl;
    // debut du bloc
    {
        bool test = true;
        int a = 1;
        int b = 1;

        // un test if prend un booleen en entree
        // le bloc de code qui suit s'execute uniquement si le booleen est vrai (true)
        if( test )
        {
            std::cout << "execution du bloc if 1 " << std::endl;
        }

        // on peut aussi ajouter un else :
        // le bloc else ne s'executera que si le bloc if correspondant ne s'execute pas
        // le test a == b renvoie true si a et b ont la meme valeur et false sinon
        if( a == b ) // vrai si a egal b
        {
            std::cout << "execution du bloc if 2 (a == b)" << std::endl;
        }
        else
        {
            std::cout << "execution du bloc else 2 (a != b)" << std::endl;
        }

        // enfin, on peut ajouter des conditions intermediaires 'else if'
        // un 'else if' ne sera teste que si les conditions du 'if' et 'else if'
        // precedents ne sont pas remplies
        // son bloc de code s'executera si sa condition associee est vraie
        if( false )
        {
            std::cout << "execution du bloc if 3 " << std::endl;
        }
        else if( a < b ) // vrai si a est strictement plus petit que b
        {
            std::cout << "execution du bloc else if 1 (a < b)" << std::endl;
        }
        else if( a > b ) // vrai si a est strictement plus grand que b
        {
            std::cout << "execution du bloc else if 2 (a > b)" << std::endl;
        }
        else if( (a == b) && test ) // vrai si (a egal b) et 'test' est vrai
        {
            std::cout << "execution du bloc else if 3 ((a == b) && test)" << std::endl;
        }
        else // le bloc suivant est execute uniquement si toutes les conditions precedentes sont fausses
        {
            std::cout << "execution du bloc else 3 " << std::endl;
        }

        // on peut aussi utiliser
        // bool1 && bool2 : renvoie true si bool1 ET bool2 sont vrais, renvoie false sinon
        // bool1 || bool2 : renvoie true si bool1 OU bool2 est vrai, renvoie false sinon
        // <= : plus petit ou egal
        // >= : plus grand ou egal
        // a!=b : vrai si a et b n'ont pas la meme valeur
        // ! : prend le contraire d'un booleen
        // par exemple !(a==b) renvoie le meme booleen que a!=b
    }
    // fin du bloc
    
    // les boucles
    std::cout << std::endl
              << "///////////////////////" << std::endl;
    std::cout << "/////// BOUCLES ///////" << std::endl;
    std::cout << "///////////////////////" << std::endl << std::endl;
    // debut du bloc
    {
        // boucle for
        // trois instructions suivent le 'for'
        // la premiere (int i=0) est executee au tout debut de la boucle
        // la seconde (i<10) est la condition d'arret de la boucle :
        //                tant qu'elle est vraie, la boucle continue
        // la troisieme (i++) est executee a chaque iteration de la boucle
        for(int i=0; i<10; i++)
        {
            // notons que la variable 'i' est definie dans les parentheses juste apres 'for'
            // la portee de cette variable (locale a la boucle) s'entend jusqu'a la fin de la boucle
            std::cout << "i = " << i << std::endl;
        } // fin de la portee de 'i'

        // boucle while
        // est executee tant que la condition est vraie
        bool condition = true;
        while(condition) // on teste la condition d'arret avant chaque iteration
        {
            std::cout << "iteration de while" << std::endl;
            condition = false; // ici la condition devient fausse donc la boucle s'arrete apres une iteration
        }

        // boucle do-while
        // comme une boucle while sauf que le test est fait apres chaque iteration
        do // on execute une premiere fois
        {
            std::cout << "iteration de do-while" << std::endl;
            condition = false;
        } while(condition); // puis on commence a tester la condition d'arret
        
        // notons que les instructions a executer dans une boucle sont contenues
        // dans un bloc de code (entre { } )

        
        /*
         * les instructions "break" et "continue"
         */
        std::cout << std::endl;
        std::cout << "test pour break et continue :" << std::endl;
        for(int i=4; i<=15; i++) // ici on parcourt les entiers de 4 a 15
        {
            if( i == 10 )
                break; // la commande break arrete la boucle quand elle est executee
            // ceci signifie que quand i vaut 10, la boucle s'arrete

            if( i == 6 )
                continue;
            // la commande continue met fin a cette iteration de la boucle
            // et passe directement a l'iteration suivante
            // ceci signifie que quand i vaut 6, on arrete l'iteration en cours
            
            std::cout << "i = " << i << std::endl;
        }
        // A la fin, on devrait obtenir les entiers entre 4 et 15 sauf 6 et sauf tous ceux qui sont >= a 10
        // les instructions break et continue fonctionnent aussi sur les boucle while et do-while
        // notons que quand le code a executer dans une condition if (ou else ou else if) ne contient qu'une ligne,
        // alors on peut ne pas mettre d'accolade

    }
    // fin du bloc

    return 0;
}
