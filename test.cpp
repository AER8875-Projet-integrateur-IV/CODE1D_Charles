// tests
#include <iostream>
using namespace std;

int main(){

  int i = 1;
  int n, subscript;
  float t;
  int c = 300;
  int domaine = 100;
  int cellules;
  float delta_x;
  float delta_t;
  float cfl;

  cellules = 50;
  cfl = 1;
  delta_x = domaine/cellules; // taille divisee par le nb de cellules
  delta_t = cfl*delta_x/c; // calcul de delta_t
  int u [cellules+2] = {}; // init cellules
  int u_new [cellules+2] = {}; // init cellules a updater

  cout << delta_t << '\n' << delta_x << '\n' << c*delta_t/delta_x << '\n';

  for ( n=0 ; n<cellules/5 ; ++n ) //conditions initiales
  {
    subscript = 0.4*domaine/delta_x + n +1;
    static_cast<int>(subscript);
    u [subscript] = 100;
  }



  // calcul de chaque cellule en avancant le temps
  while (i < 50)
  {

    for (n = 1; n < cellules+1; ++n)
    {
      printf("%d ", u [n]);
      u_new [n] = u [n] - c*delta_t/delta_x*(u [n] - u [n-1]); //equation de l'onde avec differences finies
    }

    u_new [0] = u_new [cellules];//conditon de periodicite
    u_new[cellules+1] = u_new [1];

    for (n = 0; n < cellules+2; ++n)
    {
      u [n] = u_new [n]; //copie du nouvel etat

    }
    printf("\n%s\n","-----");
    i++;
  }

  t = i*delta_t;
  cout << '\n' << t << '\n';


  return 0;
}
