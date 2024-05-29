#include "Testing.hpp"

const int static INCREASE_OF_NUMBERS = 10;
const int static LINEAR_LOWER = 3;
const int static LINEAR_UPPER = 10;
const int static LINEARITHMIC_LOWER = 8;
const int static LINEARITHMIC_UPPER = 40;
const int static QUADRATIC_LOWER = 40;
const int static QUADRATIC_UPPER = 200;

std::string PrettyArray(MyInt* elements, int numElements)
{
	std::string toReturn = "[";
	for (int i = 0; i < numElements - 1; ++i)
		toReturn += std::to_string(elements[i].getValue()) + ", ";
	toReturn += std::to_string(elements[numElements - 1].getValue()) + "]";
	return toReturn;
}

void GenerateData(MyInt* elements, int numElements, int numRange)
{
	for (int i = 0; i < numElements; ++i)
		elements[i] = MyInt(rand() % numRange);
}

int ContentsCheck(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName)
{
	int numElements = 10;
	MyInt* elementsA = new MyInt[numElements];
	MyInt* elementsB = new MyInt[numElements];
	for (int i = 0; i < numElements; ++i)
	{
		elementsA[i] = MyInt(i % 5, i / 5);
		elementsB[i] = elementsA[i];
	}

	AlgorithmFunction(elementsA, numElements);
	int count = 0;
	for (int i = 0; i < numElements; ++i)
		for (int j = 0; j < numElements; ++j)
			if (elementsA[i] == elementsB[j] && elementsA[i].getControl() == elementsB[j].getControl())
				++count;
	if (count != numElements)
	{
		std::cout << "Your sorted array does not contain the same elements as before. Do not remove or alter elements in your " << algorithmName << "." << std::endl;
		return -1;
	}
	return 0;
}

int StabilityChecks(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName)
{
	const int numElements = 11;
	MyInt elements[numElements] = { MyInt(1,1),
									MyInt(9,1),
									MyInt(7,1),
									MyInt(5,1),
									MyInt(1,2),
									MyInt(7,2),
									MyInt(9,2),
									MyInt(7,3),
									MyInt(5,2),
									MyInt(5,3) };
	MyInt elementsCopy[numElements] = { MyInt(1,1),
									MyInt(9,1),
									MyInt(7,1),
									MyInt(5,1),
									MyInt(1,2),
									MyInt(7,2),
									MyInt(9,2),
									MyInt(7,3),
									MyInt(5,2),
									MyInt(5,3) };
	AlgorithmFunction(elements, numElements);
	bool checkStable = true;
	for (int i = 0; i < numElements - 1; ++i)
		if (!(elements[i] < elements[i + 1] || (elements[i] == elements[i + 1] && elements[i].getControl() < elements[i + 1].getControl())))
			checkStable = false;

	if (!checkStable)
	{
		std::cout << "Your " << algorithmName << " does not preserve the relative order of elements -> It is not a stable sorting implementation." << std::endl;
		return -1;
	}
	for (int i = 0; i < numElements - 1; i++)
		elements[i] = elementsCopy[i];

	AlgorithmFunction(elements, numElements - 1);	// Testing on 10 elements also.
	checkStable = true;
	for (int i = 0; i < numElements - 2; ++i)
		if (!(elements[i] < elements[i + 1] || (elements[i] == elements[i + 1] && elements[i].getControl() < elements[i + 1].getControl())))
			checkStable = false;

	if (!checkStable)
	{
		std::cout << "Your " << algorithmName << " does not preserve the relative order of elements -> It is not a stable sorting implementation." << std::endl;
		return -1;
	}
	return 0;
}

int ScalingTest(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName, MyInt* elementsA, int numElementsA, MyInt* elementsB, int numElementsB, std::string scaling, std::string dataType)
{
	using std::chrono::high_resolution_clock;
	using std::chrono::duration_cast;
	using std::chrono::duration;
	using std::chrono::microseconds;

	int lower = LINEAR_LOWER;
	int upper = LINEAR_UPPER;
	if (scaling == "linearithmic")
	{
		lower = LINEARITHMIC_LOWER;
		upper = LINEARITHMIC_UPPER;
	}
	else if (scaling == "quadratic")
	{
		lower = QUADRATIC_LOWER;
		upper = QUADRATIC_UPPER;
	}

	auto start_1 = high_resolution_clock::now();
	AlgorithmFunction(elementsA, numElementsA);
	auto stop_1 = high_resolution_clock::now();

	auto start_2 = high_resolution_clock::now();
	AlgorithmFunction(elementsB, numElementsB);
	auto stop_2 = high_resolution_clock::now();

	auto duration1 = duration_cast<microseconds>(stop_1 - start_1);
	auto duration2 = duration_cast<microseconds>(stop_2 - start_2);
	auto algorithmScaling = duration2.count() / duration1.count();

	if (!(algorithmScaling >= lower and algorithmScaling <= upper))
	{
		std::cout << std::endl << algorithmName << " does not sort according to its " << scaling << " time complexity on data " << dataType << "." << std::endl;
		if (algorithmScaling >= LINEAR_LOWER && algorithmScaling <= LINEAR_UPPER)
			std::cout << "It follows a linear time complexity O(n)." << std::endl;
		else if (algorithmScaling >= LINEARITHMIC_LOWER && algorithmScaling <= LINEARITHMIC_UPPER)
			std::cout << "It follows a linearithmic time complexity O(n log(n))." << std::endl;
		else if (algorithmScaling >= QUADRATIC_LOWER && algorithmScaling <= QUADRATIC_UPPER)
			std::cout << "It follows a quadratic time complexity O(n^2)." << std::endl;
		else
			std::cout << "It scales higher than O(n^2)." << std::endl;
		return -1;
	}
	return 0;
}

//template <class T>
int ScalingTests(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName, std::map<std::string, std::string> scaling, int numElements, int numRange)
{
	int numFailedTests = 0;
	srand((unsigned)1);
	MyInt* elementsA = new MyInt[numElements];
	MyInt* elementsB = new MyInt[numElements * INCREASE_OF_NUMBERS];
	GenerateData(elementsA, numElements, numRange);
	GenerateData(elementsB, numElements * INCREASE_OF_NUMBERS, numRange);
	std::string dataType = "random";
	numFailedTests += ScalingTest(AlgorithmFunction, algorithmName, elementsA, numElements, elementsB, numElements * INCREASE_OF_NUMBERS, scaling[dataType], dataType);

	std::sort(elementsA, elementsA + numElements);
	std::sort(elementsB, elementsB + (numElements * INCREASE_OF_NUMBERS));
	dataType = "sorted";
	numFailedTests += ScalingTest(AlgorithmFunction, algorithmName, elementsA, numElements, elementsB, numElements * INCREASE_OF_NUMBERS, scaling[dataType], dataType);

	std::sort(elementsA, elementsA + numElements);
	std::sort(elementsB, elementsB + (numElements * INCREASE_OF_NUMBERS));
	std::reverse(elementsA, elementsA + numElements);
	std::reverse(elementsB, elementsB + (numElements * INCREASE_OF_NUMBERS));
	dataType = "sorted reverse";
	numFailedTests += ScalingTest(AlgorithmFunction, algorithmName, elementsA, numElements, elementsB, numElements * INCREASE_OF_NUMBERS, scaling[dataType], dataType);

	delete[] elementsA;
	delete[] elementsB;
	return numFailedTests;
}

int AssignmentTests(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName, MyInt* data, int numElements, int optimalNumAssignments, int maxNumAssignments)
{
	MyInt* toSort = new MyInt[numElements];
	MyInt* sortedData = new MyInt[numElements];
	for (int i = 0; i < numElements; ++i)
		toSort[i] = sortedData[i] = data[i];
	std::sort(sortedData, sortedData + numElements);

	MyInt::numAssignments = 0;
	AlgorithmFunction(toSort, numElements);
	if (!(std::equal(toSort, toSort + numElements, sortedData)))
	{
		std::cout << std::endl << algorithmName << " does not sort " << PrettyArray(data, numElements) << " correctly." << std::endl;
		std::cout << "Your list looks like: " << PrettyArray(toSort, numElements) << std::endl;
		delete[] toSort;
		delete[] sortedData;
		return -1;
	}

	if (MyInt::numAssignments != optimalNumAssignments)
	{
		if(maxNumAssignments != -1 and MyInt::numAssignments <= maxNumAssignments)
		{
			std::cout << std::endl << algorithmName << " does not assign the optimal amount of elements, but is OK." << std::endl;
		}
		else
		{
			std::cout << std::endl << algorithmName << " does not assign elements as defined in the algorithm description." << std::endl;
			std::cout << "Your algorithm did " << MyInt::numAssignments << ". It should do " << optimalNumAssignments;
			if(maxNumAssignments != -1)
				std::cout <<  ", but at most " << maxNumAssignments << "." << std::endl;
			else
				std::cout << "." << std::endl;
			std::cout << "This was the unsorted list " << PrettyArray(data, numElements) << "." << std::endl;
			delete[] toSort;
			delete[] sortedData;
			return -1;
		}
	}
	delete[] toSort;
	delete[] sortedData;
	return 0;
}

int ComparisonTests(void (*AlgorithmFunction)(MyInt*, int), std::string algorithmName, MyInt* data, int numElements, int optimalNumComparisons, int maxNumComparisons)
{
	MyInt* toSort = new MyInt[numElements];
	for (int i = 0; i < numElements; ++i)
		toSort[i] = data[i];

	MyInt::numComparisons = 0;
	AlgorithmFunction(toSort, numElements);
	if (MyInt::numComparisons != optimalNumComparisons && MyInt::numComparisons <= maxNumComparisons)
	{
		std::cout << std::endl << algorithmName << " does not compare the optimal amount of elements, but is OK." << std::endl;
	}
	else if (MyInt::numComparisons > optimalNumComparisons)
	{
		std::cout << std::endl << algorithmName << " performs too many comparisons on the data " << PrettyArray(data, numElements) << ". Follow the algorithm definition." << std::endl;
		std::cout << "Your algorithm did " << MyInt::numComparisons << ". It should do " << optimalNumComparisons;
		if(maxNumComparisons != -1)
			std::cout << ", but at most " << maxNumComparisons << "."  << std::endl;
		else
			std::cout << "." << std::endl;
		delete[] toSort;
		return -1;
	}
	else if (MyInt::numComparisons < optimalNumComparisons)
	{
		std::cout << std::endl << algorithmName << " performs too few comparisons on the data " << PrettyArray(data, numElements) << ". Follow the algorithm definition." << std::endl;
		std::cout << "Your algorithm did " << MyInt::numComparisons << ". It should do " << optimalNumComparisons;
		if (maxNumComparisons != -1)
			std::cout << ", but at most " << maxNumComparisons << "." << std::endl;
		else
			std::cout << "." << std::endl;
		delete[] toSort;
		return -1;
	}
	delete[] toSort;
	return 0;
}