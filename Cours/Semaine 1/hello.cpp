#include <iostream>
// cet include donne acces a des fonctions supplementaires
// ici "std::cout" et "std::endl"


/*
  Le fichier source principal d'un programme en C++ doit contenir
  une fonction "main". Le programme correspond au code dans
  cette fonction "main".
 */
int main() // un commentaire sur une ligne
{
    /*
      un commentaire sur 
      plusieurs lignes
     */


    // "std::cout" envoie du texte vers le terminal
    // "std::endl" effectue un retour a la ligne
    std::cout << "Hello !!" << std::endl;
    
    return 0;
}


/*
  Le compilateur traduit un (ou plusieurs) fichier(s) de code source 
  en un fichier executable par l'ordinateur

  Pour compiler le fichier hello.cpp, on peut utiliser la commande
  g++ hello.cpp -o hello

  Sinon utiliser le Makefile et utiliser la commande
  make hello
  ou
  make
  (s'il n'y a qu'un seul programme dans le dossier)
 */
