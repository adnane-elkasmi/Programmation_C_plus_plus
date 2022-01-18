#include <vector>
#include <map>
#include <cassert>
#include <algorithm>
#include <fstream>
#include <string>

#ifndef GRAPHEHEADERDEF
#define GRAPHEHEADERDEF


class Arc
{
public:
    int a, b;                               // sommets formant cet Arc
    double poids;                           // poids de l'arc
    Arc() : a(0), b(0), poids(0.) {}        // constructeur par defaut
    Arc(int a_, int b_) : a(a_), b(b_), poids(0.) {}// constructeur avec valeurs pour les sommets
    Arc(int a_, int b_, double p) : a(a_), b(b_), poids(p) {}
    // constructeur avec valeurs pour les sommets et le poids
};

inline std::ostream& operator <<(std::ostream& f, const  Arc a)
{ return  f << a.a << ' ' << a.b  << ' ' << a.poids << ' ' ;}

class Graphe
{
public:
    int N; // nb de noeuds
    std::vector<Arc> ListA; // liste des Arc
    std::map<int, std::string> noms; // noms des sommets
    std::map<std::string,int> nums;  // numeros des villes
    Graphe(const char * filename); // constructeur a partir d'un fichier
    std::vector<int> neighborsArcs(int i); // renvoie la liste des arcs attaches au noeud i
};

#endif
