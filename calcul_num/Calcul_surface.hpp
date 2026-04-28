#include "Fonction.hpp"

class Calcul_surface
{
	private:
		double extremite_1 , extremite_2 ;
	public:
		Calcul_surface() ;
		void setExtremite_1(double a);
		void setExtremite_2(double a);
		double getExtremite_1();
		double getExtremite_2();
		double methode_rectangle(Fonction f) ;
		double methode_trapeze(Fonction f) ;
};
