#include "Calcul_surface.hpp"

Calcul_surface::Calcul_surface(){}

void Calcul_surface::setExtremite_1(double a)
{
	extremite_1 = a ;
}

void Calcul_surface::setExtremite_2(double a)
{
	extremite_2 = a ;
}

double Calcul_surface::getExtremite_1()
{
	return extremite_1 ;
}

double Calcul_surface::getExtremite_2()
{
	return extremite_2 ;
}

double Calcul_surface::methode_rectangle(Fonction f)
{
	int n = 10 , i = 1 ;
	double x1 = 0 , x2 = 0 ;
	double decalage = 0 , surface = 0 ;
	
	x1 = Calcul_surface::getExtremite_1() ;
	x2 = Calcul_surface::getExtremite_2() ;
	decalage = (x2 - x1) / n ;
	
	i = 1 ;
	while (i <= n)
	{
		surface += (decalage * f.image(x1)) ;
		x1 += decalage ;
		i++ ;
	}
	return (surface) ;
}

double Calcul_surface::methode_trapeze(Fonction f)
{
	int n = 10 , i = 1 ;
	double surface_total = 0 , surface_carre = 0 ;
	double x1 = 0 ,x2 = 0 ;
	double decalage = 0 ;
	
	x1 = Calcul_surface::getExtremite_1() ;
	x2 = Calcul_surface::getExtremite_2() ;
	decalage = (x2 - x1) / n ;

	x2 = x1 ;
	x2 += decalage ;
	while (i <= n)
	{
		surface_total += (decalage * f.image(x1)) ;
		surface_carre = decalage * (f.image(x2) - f.image(x1)) ;
		surface_total += surface_carre / 2 ;
		x2 += decalage ;
		x1 += decalage ;
		i++ ;
	}
	return (surface_total) ;
}
