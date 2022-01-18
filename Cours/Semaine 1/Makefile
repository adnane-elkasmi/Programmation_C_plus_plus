PROGS = hello var fonctions exos

all: $(PROGS)

hello: hello.o
	g++ -o $@ $^

var: var.o
	g++ -o $@ $^

fonctions: fonctions.o
	g++ -o $@ $^

exos: exos.o
	g++ -o $@ $^

hello.o: hello.cpp

var.o: var.cpp

fonctions.o: fonctions.cpp

exos.o: exos.cpp

clean:
	rm -f *~ *.o $(PROGS)

# les commandes hello permettent de compiler le code
# la commande clean permet de supprimer l'executable
# et les fichiers de compilation intermediaire
