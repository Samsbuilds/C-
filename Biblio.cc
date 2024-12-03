#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

// Classe Auteur
class Auteur {
public:
    Auteur(string name) : nom(name) {}
    string getNom() const { return nom; }
private:
    string nom;
};

// Classe Oeuvre
class Oeuvre {
public:
    Oeuvre(string title, Auteur author, string language) 
        : titre(title), auteur(author), langue(language) {}
    string getTitre() const { return titre; }
    string getLangue() const { return langue; }
    Auteur getAuteur() const { return auteur; }
private:
    string titre;
    Auteur auteur;
    string langue;
};

// Classe Exemplaire
class Exemplaire {
public:
    Exemplaire(Oeuvre o, int n = 1) : oeuvre(o), nombre(n) {}
    Oeuvre getOeuvre() const { return oeuvre; }
    int getNombre() const { return nombre; }
private:
    Oeuvre oeuvre;
    int nombre;
};

// Classe Bibliotheque
class Bibliotheque {
public:
    Bibliotheque(string name) : nom(name) {}
    void stocker(const Oeuvre& o, int n = 1) {
        exemplaires.push_back(Exemplaire(o, n));
    }
    void lister_exemplaires() const {
        for (const auto& e : exemplaires) {
            cout << e.getOeuvre().getTitre() << " - " << e.getNombre() << " exemplaires" << endl;
        }
    }
    void lister_exemplaires(const string& langue) const {
        for (const auto& e : exemplaires) {
            if (e.getOeuvre().getLangue() == langue) {
                cout << e.getOeuvre().getTitre() << endl;
            }
        }
    }
    void afficher_auteurs(bool succes = false) const {
        for (const auto& e : exemplaires) {
            if (succes) {
                cout << e.getOeuvre().getAuteur().getNom() << endl;
            }
        }
    }
    string getNom() const { return nom; }
    int compter_exemplaires(const Oeuvre& o) const {
        int count = 0;
        for (const auto& e : exemplaires) {
            if (e.getOeuvre().getTitre() == o.getTitre()) {
                count += e.getNombre();
            }
        }
        return count;
    }
private:
    string nom;
    vector<Exemplaire> exemplaires;
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main() {
    Auteur a1("Victor Hugo"),
           a2("Alexandre Dumas"),
           a3("Raymond Queneau", true);

    Oeuvre o1("Les Misérables", a1, "français"),
           o2("L'Homme qui rit", a1, "français"),
           o3("Le Comte de Monte-Cristo", a2, "français"),
           o4("Zazie dans le métro", a3, "français"),
           o5("The Count of Monte-Cristo", a2, "anglais");

    Bibliotheque biblio("municipale");
    biblio.stocker(o1, 2);
    biblio.stocker(o2);
    biblio.stocker(o3, 3);
    biblio.stocker(o4);
    biblio.stocker(o5);

    cout << "La bibliothèque " << biblio.getNom() 
         << " offre les exemplaires suivants :" << endl;
    biblio.lister_exemplaires();

    const string langue("anglais");
    cout << "Les exemplaires en " << langue << " sont :" << endl;
    biblio.lister_exemplaires(langue);

    cout << "Les auteurs à succès sont :" << endl;
    biblio.afficher_auteurs(true);

    cout << "Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
         << o3.getTitre() << endl;

    return 0;
}
