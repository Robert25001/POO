#include "Resolution.hpp"
#include <iostream>
#include <cmath>

using namespace std ;

Resolution::Resolution(Fonction fonction)
{
	f = fonction ;
}

void Resolution::setExtremite_1(double a)
{
	extremite_1 = a ;
}

void Resolution::setExtremite_2(double a)
{
	extremite_2 = a ;
}

int Resolution::est_possible()
{
	if ((f.image(extremite_1) * f.image(extremite_2)) < 0)
	{
		return (1) ;
	}
	else
	{
		return (0) ;
	}
}

double Resolution::methode_newton()
{
	if (Resolution::est_possible() == 1)
	{
		double x = extremite_1 ;
		while (fabs(f.image(x)) > eps)
		{
			x = x - (f.image(x)  / f.derive(x)) ;
		}
		return (x) ;
	}
	else
	{
		cout << "pas de solution dans cet intervale\n" ;
		return (0) ;
	}
}

double Resolution::methode_dichotomie()
{
	double a = extremite_1 , b = extremite_2 ;
	double m = (a + b) / 2 ;
	if ((f.image(a) * f.image(b)) < 0)
	{
		while (fabs(f.image(m)) > eps)
		{
			if ((f.image(a) * f.image(m)) < 0)
			{
				b = m ;
			}
			else
			{
				a = m ;
			}
			m = (a + b) / 2 ;
		}
	}
	else
	{
		cout << "Pas de solution \n" ;
		m = 0 ;
	}
	return (m) ;
}
