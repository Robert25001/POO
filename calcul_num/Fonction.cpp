#include "Fonction.hpp"
#include "mon_calcul.hpp"

Fonction::Fonction(){} ;

void Fonction::setExpression_fonction(std::string fonction)
{
	expression_fonction = fonction ;
}

std::string Fonction::getExpression_fonction()
{
	return expression_fonction ;
}

double Fonction::image(float x)
{
	return (convertir(expression_fonction, x)) ;
}

double Fonction::derive(float x)
{
	double resultat = (Fonction::image(x + eps) - Fonction::image(x)) / eps ;
	return resultat ;
}
