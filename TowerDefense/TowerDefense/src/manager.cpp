#include <iostream>

#include "manager.h"

Manager::Manager()
{
	
}

Manager::~Manager()
{
	std::cout << "Manager destroyed" << std::endl;
}

Manager::Manager(const Manager &other)
{

}

Manager &Manager::operator=(const Manager &other)
{
	return *this;
}