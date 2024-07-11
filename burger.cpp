#include "burger.h"

burger::burger(int numPatties)
{
	setNumPatties(numPatties);
}

//loop through the set and get the toppings using the set iterator
std::string burger::getToppings()
{
	std::string result;
	for (auto it = toppings.begin(); it.hasNext();){
		toppingType topping = it.next();
		result += toppingStr[topping];
		if(it.hasNext())
			result += ", ";
	}
	return result;
}

void burger::addTopping(toppingType topping)
{
	toppings.insert(topping);
}

int burger::getNumPatties() const
{
	return numPatties;
}

void burger::setNumPatties(int num)
{
	if (num > 0)
		numPatties = num;
	else
		std::cout << "The number of patties should be greater than 0." << std::endl;
}

std::string burger::tostring()
{
	std::ostringstream out;
	out << std::setprecision(2) << std::fixed << std::showpoint;
	out << "Number of patties: " << numPatties << std::endl;
	out << "Toppings: " << getToppings();

	return out.str();
}
