#include <iostream>
#include "Resolution.hpp"

using namespace std ;

int main(int argc, char** argv)
{
	Fonction f ;
	f.setExpression_fonction(argv[1]) ;
	Resolution _1(f);
	_1.setExtremite_1(stof(argv[2]));
	_1.setExtremite_2(stof(argv[3]));
	double racine = _1.methode_newton();
	cout << "Racine: " << racine << "\n" ;
	racine = _1.methode_dichotomie() ;
	cout << "Racine: " << racine << "\n" ;
	return (0) ;
}
