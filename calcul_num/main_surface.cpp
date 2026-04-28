#include <iostream>
#include "Calcul_surface.hpp"

using namespace std ;

int main()
{
	Fonction f ;
	Calcul_surface _1 ;
	_1.setExtremite_1(0);
	_1.setExtremite_2(8);
	double surface = 0 ;
	surface = _1.methode_rectangle(f);
	cout << "Surface rectangle = " << surface << endl ;
	surface = _1.methode_trapeze(f);
	cout << "Surface trapeze = " << surface << endl ;
	return (0) ;
}
