#pragma once
#include <string>
#include "mon_calcul.hpp"

#define eps 1e-6

class Fonction
{
	private:
		std::string expression_fonction ;
	public:
		Fonction() ;
		void setExpression_fonction(std::string fonction) ;
		std::string getExpression_fonction() ;
		double derive(float x) ;
		double image(float x) ;
};
