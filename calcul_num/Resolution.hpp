#include "Fonction.hpp"

class Resolution
{
	private:
		Fonction f ;
		double extremite_1 , extremite_2 ;
	public:
		Resolution(Fonction fonction) ;
		void setExtremite_1(double a);
		void setExtremite_2(double a);
		double methode_newton() ;
		double methode_dichotomie() ;
		int est_possible() ;
};
