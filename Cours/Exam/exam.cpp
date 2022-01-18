#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;
// using std::cout;
// using std::endl;



class Point {
public:
    Point(int a, int b) : x(a), y(b) {}
    Point() : x(0), y(0) {}
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    friend ostream& operator<<(ostream& os, const Point& p);
    Point operator+(const Point& p) {
        Point ret;
        ret.x = x + p.x;
        ret.y = y + p.y;

        return ret;
    }
    virtual void info() const {
        cout << "(" << x << "," << y << ")" << endl;
    }
    bool operator<(const Point& p) {
        if( x != p.x )
            return x < p.x;

        return y < p.y;
    }
    int get_x() const {return x;}
    int get_y() const {return y;}
protected:
    int x, y;
};

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}


class Polygone {
public:
    Polygone(Point *p_P, int n_) : n(n_) , p(new Point[n_]) {
        for(int i=0; i<n; i++)
        {
            p[i] = p_P[i];
        }
    }
    Polygone(Point p1, Point p2, Point p3) : n(3) , p(new Point[3]) {
        p[0] = p1;
        p[1] = p2;
        p[2] = p3;
    }
    bool coupe_abscisses() {
        bool pos = false;
        bool neg = false;

        for(int i=0; i<n; i++) {
            if(p[i].get_y() >= 0)
                pos = true;
            if(p[i].get_y() <= 0)
                neg = true;
        }
        if(pos && neg)
            return true;

        return false;
    }

    ~Polygone() {delete[] p;}
private:
    Point* p;
    int n;
};


class Pixel : public Point {
public:
    Pixel(int a, int b, int col_) : Point(a,b) , col(col_) {}
    friend ostream& operator<<(ostream& os, const Pixel& p);
    void info() const {
        cout << "(" << x << "," << y << ")-> " << col << endl;
    }
private:
    int col;
};

ostream& operator<<(ostream& os, const Pixel& p) {
    os << "(" << p.x << "," << p.y << ")-> " << p.col;
    return os;
}


int main() {


    /*
     * Instructions :
     * Vous coderez tout dans ce fichier (exam.cpp)
     * Vous avez acces a internet durant l'epreuve
     * Il vous est interdit de vous connecter a votre boite email durant l'epreuve
     * ou a Facebook ou tout autre moyen de communication avec les autres etudiants
     * Se connecter a l'un de ces sites sera considere comme une tentative de triche
     * A la fin de l'epreuve, vous deposerez votre fichier exam.cpp sur moodle
     * (section examen)
     *
     * Le surveillant ne repondra a aucune question concernant le sujet
     * Cette epreuve durera 1h30 (2h pour les etudiants disposant d'un tiers temps)
     *
     *
     * La question 1 doit etre traitee avant les autres.
     * Les questions 2, 3 et 4 sont independantes les unes des autres.
     * La question 5 necessite d'avoir traite les questions 1 et 4.
     *
     * Bareme indicatif : ~4pts par question (peut etre legerement adapte)
     */

    /*
     * Question 1 : coder une classe Point representant un point de Z^2
     *              (chaque coordonnee est un int et est un membre private)
     * vous devrez ecrire les methodes suivantes (public) :
     * - un constructeur prenant deux int a et b : cree un point (a,b)
     * - un constructeur par defaut : cree un point (0,0)
     * - une methode move(int dx, int dy) qui deplace le point de dx (direction x) et dy (direction dy)
     * - un operator<< permettant de renvoyer l'etat du Point (les coordonnees sont entre parentheses et separees par une virgule)
     * - un operateur+(const Point&) ajoutant les coordonnees de deux points
     *
     * Ci-dessous quelques tests :
     */

    {
        cout << "Question 1 :" << endl;
        Point p1;
        cout << p1 << endl; // doit ecrire (0,0)

        Point p2(1,-3);
        Point p3 = p2; // le constructeur par copie genere par le compilateur fait l'affaire
        p3.move(1,1);
        Point p4 = p3 + p2;
        cout << p4 << endl; // doit renvoyer (3,-5)
    }

    /*
     * Question 2 : on veut trier une liste d'instances de Point
     * L'ordre utilise sera le suivant :
     * (a,b) sera plus grand que (c,d) si a>c ou si (a==c et b>d)
     *
     * Utiliser un conteneur standard et lui donner les points suivants :
     * (1,0) , (2,0) , (-4,1) , (1,5) , (2,-2) , (2,0)
     * Utiliser un algorithme de la STL pour trier cette liste et renvoyer la liste triee 
     * (par ordre croissant) dans le terminal
     */

    // ne pas mettre ces tests dans le sujet ...
    {
        cout << endl;
        cout << "Question 2 :" << endl;
        vector<Point> vect;
        vect.push_back(Point(1,0));
        vect.push_back(Point(2,0));
        vect.push_back(Point(-4,1));
        vect.push_back(Point(1,5));
        vect.push_back(Point(2,-2));
        vect.push_back(Point(2,0));

        sort( vect.begin() , vect.end() );

        for(auto it = vect.begin(); it != vect.end(); it++)
            cout << *it << endl;
    }


    /*
     * Question 3 : on veut coder une classe Polygone
     * Cette classe contiendra un membre de type 'pointeur vers un Point' et un membre int (le nombre de points)
     * Coder les methodes suivantes :
     * - Polygone(Point * p_P, int n) ou p_P est un pointeur vers un tableau de Point (qu'on peut supposer deja alloue) et n le nombre de points
     *   (il faudra recopier les points dans un nouveau tableau et non pas recopier l'adresse memoire)
     * - Polygone(Point p1, Point p2, Point p3) : construit un triangle a partir de ces trois points
     * - coupe_abscisses() : renvoie un booleen indiquant si le polygone coupe l'axe des abscisses
     *   (algo : soit tous les points sont d'un cote, soit ils sont tous de l'autre, soit le polygone coupe l'axe des abscisses)
     * - un destructeur pour liberer la memoire allouee
     *
     * noter que vous devrez allouer la memoire manuellement avec "new"
     * si besoin, vous pourrez ajouter des getter dans la classe Point
     * Quelques tests :
     */

    {
        cout << endl;
        cout << "Question 3 :" << endl;
        Point p_P[] = { {1,2} , {4,-1} , {2,1} };
        Polygone pol(p_P,3);
        if( pol.coupe_abscisses() )
            cout << "pol coupe l'axe des abscisses" << endl;
        else
            cout << "pol ne coupe pas l'axe des abscisses" << endl;

        Polygone pol2(Point(-3,-4) , Point(2,-1) , Point(-1,-5) );
        if( pol2.coupe_abscisses() )
            cout << "pol2 coupe l'axe des abscisses" << endl;
        else
            cout << "pol2 ne coupe pas l'axe des abscisses" << endl;

    }

    /*
     * Question 4 : on veut coder une classe Pixel
     * Cette classe Pixel doit heriter de Point
     * On se donne un membre supplementaire : un int representant la couleur du pixel (private)
     * Coder un constructeur prenant trois entiers
     * Reecrire l'operator<< pour Pixel de maniere a avoir les coordonnees des points entre parenthese
     * suivi d'une fleche -> et de la couleur du pixel
     * vous pourrez passer les coordonnees de Point en protected (optionnel)
     *
     * Quelques tests :
     */

    {
        cout << endl;
        cout << "Question 4 :" << endl;
        Pixel p(1,1,-1);
        cout << p << endl; // doit afficher (1,1)-> -1
    }



    /*
     * Question 5 :
     * on veut stoker dans un meme conteneur de votre choix l'information concernant 
     * les Points suivants
     * (1,2) , (-1,3) , (-8,2) , (2,5)
     * et les Pixel suivants
     * (-1,1)-> 1 , (0,1)-> 2 , (1,1)-> -3
     * on veut afficher les membres de la liste et obtenir dans le terminal :
     * (1,2)
     * (-1,3)
     * (-8,2)
     * (2,5)
     * (-1,1)-> 1
     * (0,1)-> 2
     * (1,1)-> -3
     * vous n'avez droit qu'a une seule boucle sur le conteneur choisi
     * plutot que d'utiliser l'operateur <<, on pourra coder une methode info()
     */

    // ne pas mettre ces tests dans le sujet
    {
        cout << endl;
        cout << "Question 5 :" << endl;

        Point p1(1,2), p2(-1,3), p3(-8,2), p4(2,5);
        Pixel p5(-1,1,1), p6(0,1,2), p7(1,1,-3);

        vector<Point*> vect;
        vect.push_back(&p1);
        vect.push_back(&p2);
        vect.push_back(&p3);
        vect.push_back(&p4);
        vect.push_back(&p5);
        vect.push_back(&p6);
        vect.push_back(&p7);

        for(auto it = vect.begin(); it != vect.end(); it++)
        {
            (*it)->info();
        }
    }

    cout << "end prog" << endl;

    return 1;
}
