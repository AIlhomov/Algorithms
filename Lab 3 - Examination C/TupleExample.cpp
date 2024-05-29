#include <string>
#include <tuple>
#include <vector>
#include <iostream>

int main()
{
	//create tuple
	std::tuple<std::string, std::string, int> tupleOne("A", "B", 99);
	std::tuple<std::string, std::string, int> tupleTwo {"A", "B", 88};
	std::tuple<std::string, std::string, int> tupleThree;
	tupleThree = std::make_tuple("A", "B", 99);

	// get part of tuple
	std::string first = std::get<0>(tupleOne); // "A"
	std::string second = std::get<1>(tupleOne); // "B"
	int third = std::get<2>(tupleOne); // 99

	std::cout << first << ", " << second << ", " << third << std::endl;
	std::cout << std::get<0>(tupleTwo) << ", " << std::get<1>(tupleTwo) << ", " << std::get<2>(tupleTwo) << std::endl;
	std::cout << std::endl;
	// comparing tuple
	if (tupleOne == tupleThree)
	{
		std::cout << "Equal" << std::endl;
	}
	if (tupleOne != tupleTwo)
	{
		std::cout << "Not equal" << std::endl;
	}
	std::cout << std::endl;

	/*
	operators <, <= , >, >= and so on compares the values in order.For example
	assume tuples

	("A", "B", 44) < ("K", "A", 55) is true because "A" < "K"
	("A", "B", 44) < ("A", "K", 55) is true because "B" < "K"
	("A", "B", 44) < ("A", "B", 55) is true because 44 < 55

	*/

	// vector containing tuples
	std::vector<std::tuple<std::string, std::string, int>> tupleVect;
	tupleVect.push_back(tupleOne);
	tupleVect.push_back(std::make_tuple("X", "Y", 55));
	tupleVect.push_back({"M", "L", 22});

	for (int i = 0; i<tupleVect.size();i++)
		std::cout<< std::get<0>(tupleVect[i]) << ", " << std::get<1>(tupleVect[i]) << ", " << std::get<2>(tupleVect[i]) << std::endl;

	std::cout<<std::endl;
	for (auto tuple: tupleVect)
		std::cout << std::get<0>(tuple) << ", " << std::get<1>(tuple) << ", " << std::get<2>(tuple) << std::endl;

	return 0;
}