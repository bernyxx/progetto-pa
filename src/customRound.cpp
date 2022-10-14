#include <cmath>
#include "customRound.hpp"

double customRound(double value){
	// arrotonda alla seconda cifra decimale
	return (round(value * 100)) / 100;
}



