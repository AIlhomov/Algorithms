#include "MyInt.hpp"
#include "ExaminationA.hpp"
#include "Testing.hpp"

std::pair<int,int> MergesortTests()
{
	const int numTests = 9;
	const int numElements = 10;
	const std::string algorithmName = "Mergesort";
	std::cout << "-------" << std::endl;
	std::cout << "Starting " << algorithmName << " tests." << std::endl;
	int numFailedTests = numTests;
	int oldFailedTests = numFailedTests;

	// Do all element remain?
	std::cout << std::endl << "Checking if all elements are the original elements...";
	oldFailedTests = numFailedTests;
	numFailedTests += ContentsCheck(&mergeSort, algorithmName);
	if(numFailedTests == oldFailedTests)
		std::cout << " OK!" << std::endl;

	// Stable
	std::cout << std::endl << "Checking if the relative order of elements are preserved...";
	oldFailedTests = numFailedTests;
	numFailedTests += StabilityChecks(&mergeSort, algorithmName);
	if(numFailedTests == oldFailedTests)
		std::cout << " OK!" << std::endl;

	// Assignments
	std::cout << std::endl << "Performing sortorder and number of assignment tests... ";
	oldFailedTests = numFailedTests;
	int data[numElements] = {9,7,5,3,1,8,6,4,2,0};
	MyInt myData[numElements];
	for(int i = 0; i < numElements; ++i)
		myData[i] = MyInt(data[i]);
	numFailedTests += AssignmentTests(&mergeSort, algorithmName, myData, numElements, 68, 80);	// Could be 18 or 32, if they implement a tmp value to store the value to be swapped or not.
	std::sort(myData, myData+numElements);
	numFailedTests += AssignmentTests(&mergeSort, algorithmName, myData, numElements, 68, 80);
	if(numFailedTests == oldFailedTests)
		std::cout << "OK!" << std::endl;

	// Comparisons
	std::cout << std::endl << "Performing number of comparisons tests... ";
	oldFailedTests = numFailedTests;
	for(int i = 0; i < numElements; ++i)
		myData[i] = MyInt(i);
	numFailedTests += ComparisonTests(&mergeSort, algorithmName, myData, numElements, 19, 25);
	for(int i = 0; i < numElements; ++i)
		myData[i] = MyInt(10 - i);
	numFailedTests += ComparisonTests(&mergeSort, algorithmName, myData, numElements, 15, 25);
	if(numFailedTests == oldFailedTests)
		std::cout << "OK!" << std::endl;

	// Scaling
	oldFailedTests = numFailedTests;
	std::map<std::string, std::string> scaling{{"random", "linearithmic"},{"sorted", "linearithmic"},{"sorted reverse", "linearithmic"}};
	std::cout << std::endl << "Performing time complexity tests..." ;
	numFailedTests += ScalingTests(&mergeSort, algorithmName, scaling, 1000, 100);
	if(numFailedTests == oldFailedTests)
		std::cout << "OK!" << std::endl;

	if(numFailedTests == numTests)
		std::cout << "All tests passed!" << std::endl << "-------" << std::endl;
	else
	{
		std::cout << "Passed " << numFailedTests << " out of " << numTests << std::endl;
	}

	return std::pair<int,int>(numFailedTests, numTests);
}

std::pair<int,int> SelectionsortTests()
{
	const int numTests = 8;
	const int numElements = 10;
	const std::string algorithmName = "Selectionsort";
	std::cout << "-------" << std::endl;
	std::cout << "Starting " << algorithmName << " tests." << std::endl;
	int numFailedTests = numTests;
	int oldFailedTests = numFailedTests;

	// Do all element remain?
	std::cout << std::endl << "Checking if all elements are the original elements...";
	oldFailedTests = numFailedTests;
	numFailedTests += ContentsCheck(&selectionSort, algorithmName);
	if(numFailedTests == oldFailedTests)
		std::cout << " OK!" << std::endl;

	// Assignments
	std::cout << std::endl << "Performing sortorder and number of assignment tests... ";
	oldFailedTests = numFailedTests;
	int data[numElements] = {9,7,5,3,1,8,6,4,2,0};
	MyInt myData[numElements];
	for(int i = 0; i < numElements; ++i)
		myData[i] = MyInt(data[i]);
	numFailedTests += AssignmentTests(&selectionSort, algorithmName, myData, numElements, 18, 20);	// Could be 18 or 32, if they implement a tmp value to store the value to be swapped or not.
	std::sort(myData, myData+numElements);
	numFailedTests += AssignmentTests(&selectionSort, algorithmName, myData, numElements, 18, 20);
	if(numFailedTests == oldFailedTests)
		std::cout << "OK!" << std::endl;

	// Comparisons
	std::cout << std::endl << "Performing number of comparisons tests... ";
	oldFailedTests = numFailedTests;
	for(int i = 0; i < numElements; ++i)
		myData[i] = MyInt(i);
	numFailedTests += ComparisonTests(&selectionSort, algorithmName, myData, numElements, 45, 55);
	for(int i = 0; i < numElements; ++i)
		myData[i] = MyInt(10 - i);
	numFailedTests += ComparisonTests(&selectionSort, algorithmName, myData, numElements, 45, 55);
	if(numFailedTests == oldFailedTests)
		std::cout << "OK!" << std::endl;

	// Scaling
	oldFailedTests = numFailedTests;
	std::map<std::string, std::string> scaling{{"random", "quadratic"},{"sorted", "quadratic"},{"sorted reverse", "quadratic"}};
	std::cout << std::endl << "Performing time complexity tests..." ;
	numFailedTests += ScalingTests(&selectionSort, algorithmName, scaling,  1000, 100);
	if(numFailedTests == oldFailedTests)
		std::cout << "OK!" << std::endl;

	if(numFailedTests == numTests)
		std::cout << "All tests passed!" << std::endl << "-------" << std::endl;
	else
	{
		std::cout << "Passed " << numFailedTests << " out of " << numTests << std::endl;
	}

	return std::pair<int,int>(numFailedTests, numTests);
}

std::pair<int,int> InsertionsortTests()
{
	const int numTests = 9;
	const int numElements = 10;
	const std::string algorithmName = "Insertionsort";
	std::cout << "-------" << std::endl;
	std::cout << "Starting " << algorithmName << " tests." << std::endl;
	int numFailedTests = numTests;
	int oldFailedTests = numFailedTests;

	// Do all element remain?
	std::cout << std::endl << "Checking if all elements are the original elements...";
	oldFailedTests = numFailedTests;
	numFailedTests += ContentsCheck(&insertionSort, algorithmName);
	if(numFailedTests == oldFailedTests)
		std::cout << " OK!" << std::endl;

	// Stable
	std::cout << std::endl << "Checking if the relative order of elements are preserved...";
	oldFailedTests = numFailedTests;
	numFailedTests += StabilityChecks(&insertionSort, algorithmName);
	if(numFailedTests == oldFailedTests)
		std::cout << " OK!" << std::endl;

	// Assignments
	std::cout << std::endl << "Performing sortorder and number of assignment tests... ";
	oldFailedTests = numFailedTests;
	int data[numElements] = {9,7,5,3,1,8,6,4,2,0};
	MyInt myData[numElements];
	for(int i = 0; i < numElements; ++i)
		myData[i] = MyInt(data[i]);
	numFailedTests += AssignmentTests(&insertionSort, algorithmName, myData, numElements, 44, 55);
	std::sort(myData, myData+numElements);
	numFailedTests += AssignmentTests(&insertionSort, algorithmName, myData, numElements, 9, 20);
	if(numFailedTests == oldFailedTests)
		std::cout << "OK!" << std::endl;

	// Comparisons
	std::cout << std::endl << "Performing number of comparisons tests... ";
	oldFailedTests = numFailedTests;
	for(int i = 0; i < numElements; ++i)
		myData[i] = MyInt(i);
	numFailedTests += ComparisonTests(&insertionSort, algorithmName, myData, numElements, 9, 20);
	for(int i = 0; i < numElements; ++i)
		myData[i] = MyInt(10 - i);
	numFailedTests += ComparisonTests(&insertionSort, algorithmName, myData, numElements, 45, 55);
	if(numFailedTests == oldFailedTests)
		std::cout << "OK!" << std::endl;

	// Scaling
	oldFailedTests = numFailedTests;
	std::map<std::string, std::string> scaling{{"random", "quadratic"},{"sorted", "linear"},{"sorted reverse", "quadratic"}};
	std::cout << std::endl << "Performing time complexity tests..." ;
	numFailedTests += ScalingTests(&insertionSort, algorithmName, scaling, 1000, 100);
	if(numFailedTests == oldFailedTests)
		std::cout << "OK!" << std::endl;

	if(numFailedTests == numTests)
		std::cout << "All tests passed!" << std::endl << "-------" << std::endl;
	else
	{
		std::cout << "Passed " << numFailedTests << " out of " << numTests << std::endl;
	}

	return std::pair<int,int>(numFailedTests, numTests);
}

std::pair<int,int> IterativeBinarySearchTests()
{
	const int numTests = 6;
	const int numElements = 100;
	const std::string algorithmName = "iterative Binary Search";
	std::cout << "-------" << std::endl;
	std::cout << "Starting " << algorithmName << " tests." << std::endl;
	int numFailedTests = numTests;
	MyInt data[numElements];
	for(int i = 0; i < numElements; ++i)
		data[i] = MyInt(i);
	
	MyInt::numComparisons = 0;
	int toSearch = -1;
	int index = binarySearch(data, numElements, MyInt(toSearch));
	int correctIndex = toSearch;
	if(index != correctIndex)
	{
		std::cout << "Your " << algorithmName << " does not return the correct index." << std::endl;
		std::cout << "Should return " << correctIndex <<  " but did return " << index << "." << std::endl;
		std::cout << "The list of elements searched was [0, 1, 2, ..., 97, 98, 99]." << std::endl;
		numFailedTests -= 1;
	}
	if(!(MyInt::numComparisons ==  6|| MyInt::numComparisons ==  12|| MyInt::numComparisons == 18))
	{
		std::cout << "Your " << algorithmName << " does the wrong amount of comparisons searching for " << toSearch << " in [0, 1, 2, ..., 97, 98, 99]." << std::endl;
		std::cout << "Should be 16/12/18" << " comparisons, but performed " << MyInt::numComparisons << " comparisons." << std::endl;
		numFailedTests -= 1;
	}

	toSearch = 49;
	MyInt::numComparisons = 0;
	index = binarySearch(data, numElements, MyInt(toSearch));
	correctIndex = toSearch;
	if(index != correctIndex)
	{
		std::cout << "Your " << algorithmName << " does not return the correct index." << std::endl;
		std::cout << "Should return " << correctIndex <<  " but did return " << index << "." << std::endl;
		std::cout << "The list of elements searched was [0, 1, 2, ..., 97, 98, 99]." << std::endl;
		numFailedTests -= 1;
	}
	if(MyInt::numComparisons != 1)
	{
		std::cout << "Your " << algorithmName << " does the wrong amount of comparisons searching for " << toSearch << " in [0, 1, 2, ..., 97, 98, 99]." << std::endl;
		std::cout << "Should be 1 comparison, but performed " << MyInt::numComparisons << " comparisons." << std::endl;
		numFailedTests -= 1;
	}

	toSearch = 100;
	MyInt::numComparisons = 0;
	index = binarySearch(data, numElements, MyInt(toSearch));
	correctIndex = -1;
	if(index != correctIndex)
	{
		std::cout << "Your " << algorithmName << " does not return the correct index." << std::endl;
		std::cout << "Should return " << correctIndex <<  " but did return " << index << "." << std::endl;
		std::cout << "The list of elements searched was [0, 1, 2, ..., 97, 98, 99]." << std::endl;
		numFailedTests -= 1;
	}
	if(!(MyInt::numComparisons ==  7|| MyInt::numComparisons ==  14|| MyInt::numComparisons == 21))
	{
		std::cout << "Your " << algorithmName << " does the wrong amount of comparisons searching for " << toSearch << " in [0, 1, 2, ..., 97, 98, 99]." << std::endl;
		std::cout << "Should be 7/14/21 comparisons, but performed " << MyInt::numComparisons << " comparisons." << std::endl;
		numFailedTests -= 1;
	}

	if(numFailedTests == numTests)
		std::cout << "All tests passed!" << std::endl << "-------" << std::endl;
	else
	{
		std::cout << "Passed " << numFailedTests << " out of " << numTests << std::endl;
	}

	return std::pair<int,int>(numFailedTests, numTests);
}

int main(int argc, char const *argv[])
{
	int totalTests = 0;
	int totalFailedTests = 0;
	if(SELECTION_IMPLEMENTED == true)
	{
		auto xs = SelectionsortTests();
		totalFailedTests += xs.first;
		totalTests += xs.second;
	}
	else if(INSERTION_IMPLEMENTED == true)
	{
		auto xi = InsertionsortTests();
		totalFailedTests += xi.first;
		totalTests += xi.second;
	}
	else
	{
		std::cout << "-------" << std::endl;
		std::cout << "-------" << std::endl;
		std::cout << "You have to implement either Insertionsort or Selectionsort, you cannot skip both." << std::endl;
		std::cout << "Remember to remove the return at the bottom of the function of Selectionsort/Insertionsort." << std::endl;
		std::cout << "-------" << std::endl;
		std::cout << "-------" << std::endl;
		totalTests += 10;
	}
	
	auto x = MergesortTests();
	totalFailedTests += x.first;
	totalTests += x.second;
	
	x = IterativeBinarySearchTests();
	totalFailedTests += x.first;
	totalTests += x.second;

	if(totalFailedTests == totalTests)
		std::cout << std::endl << "-------" << std::endl << "All tests passed! Well done!" << std::endl;
	else
	{
		std::cout <<std::endl << "-------" << std::endl;
		std::cout << "Passed " << totalFailedTests << "/" << totalTests << "tests." << std::endl;
	}
	return 0;
}
