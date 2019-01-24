#include "Functions.h"

void readList(std::vector<int> &list, std::string fileName) { //this will clear the list before it reads
	list.clear();
	std::ifstream infile(fileName);
	std::string line;
	getline(infile, line);
	getline(infile, line);
	//Skips the first two lines in the file

	int tempInt;
	//Reads in integers to the list until it reaches nothing
	while (infile >> tempInt) {
		list.push_back(tempInt);
	}

}

void bubbleSort(std::vector<int> &list) {
	int comparisons = 0;
	int assignments = 0;
	int listSize = list.size();
	float sortedCount = 0;
	int backOfList = 1;
	bool notSorted = true;
	while (notSorted) { //This will repeat until all it doesn't have to make any swaps
		notSorted = false;
		for (int i = 0; i < listSize-backOfList; i++) {
			if (list[i] > list[i + 1]) {
				//swap the two variables
				int temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				notSorted = true; //Since it made a swap, the list wasn't sorted
				assignments += 2;
			}
			comparisons++;
		}
		sortedCount++;
		backOfList++;
	}
	std::cout << "Bubble Sort required " << assignments << " assignments and " << comparisons << " comparisons." << std::endl;
}


void merge(std::vector<int> &list, int upperBound, int middleBound, int lowerBound, int &comparisons, int &assignments) {
	std::vector<int> tempLeft; //Create two temporary vectors for the left and right side that we will merge
	std::vector<int> tempRight;
	std::vector<int> mergedVec;


	//Split the list into two smaller ones
	for (int i = upperBound; i <= middleBound; i++) {
		tempLeft.push_back(list[i]);
	}

	for (int i = middleBound + 1; i <= lowerBound; i++) {
		tempRight.push_back(list[i]);
	}

	//Compare the values in each of the two smaller vectors, starting at zero in each of them. 
	//When we figure out which value is the smallest in each vector, we place it in our merge vector.
	//We then increment of the index of the vector we just pulled the value from.
	//This will run until there are no more values in one vector
	int leftIndex = 0;
	int rightIndex = 0;
	for (int i = 0; i < tempLeft.size() + tempRight.size(); i++) {
		if (leftIndex < tempLeft.size() && rightIndex < tempRight.size()) {
			if (tempLeft[leftIndex] <= tempRight[rightIndex]) {
				mergedVec.push_back(tempLeft[leftIndex]);
				leftIndex++;
			}
			else {
				mergedVec.push_back(tempRight[rightIndex]);
				rightIndex++;
			}
		}
		comparisons++;
	}

	//Empty out anything left behind in either vector
	if (leftIndex < tempLeft.size()) {
		for (int i = leftIndex; i < tempLeft.size(); i++) {
			mergedVec.push_back(tempLeft[i]);
		}
		comparisons++;
	}

	if (rightIndex < tempRight.size()) {
		for (int i = rightIndex; i < tempRight.size(); i++) {
			mergedVec.push_back(tempRight[i]);
		}
		comparisons++;
	}

	//Copy everything in our temporary vector to the actual list
	int mPos = 0;
	for (int i = upperBound; i <= lowerBound; i++) {
		list[i] = mergedVec[mPos];
		mPos++;
		assignments++;
	}
}

void mergeSort(std::vector<int> &list, int upperBound, int lowerBound, int &comparisons, int &assignments) {
	if (upperBound < lowerBound) { // will keep recursively running until they are both equal at 1
		int middleBound = upperBound + (lowerBound - upperBound) / 2;
		//This splits the current list into two halves and merge sorts both of them
		mergeSort(list, upperBound, middleBound, comparisons, assignments);
		mergeSort(list, middleBound+1, lowerBound, comparisons, assignments);
		// Once the lists are all split, they will be merged
		merge(list, upperBound, middleBound, lowerBound, comparisons, assignments);
	}
}

void indexSort(std::vector<int> &list) {
	int assignments = 0;
	//we cheat by using the size of the array as our sorting tool
	std::vector<int> indexList(list.size());
	std::vector<int> tempList;
	//everytime we spot a number in the array we fill index of that number of our new vector with a 1 to mark how many of that number there is
	for (int i = 0; i < list.size(); i++) {
		indexList[list[i]] += 1;
	}
	//this always runs n times

	
	//this will run n times
	for (int listPlace = 0; listPlace < indexList.size(); listPlace++) {
		//This will search for 1s in the index vector and place the corresponding index into our sorted array
		while (indexList[listPlace] > 0) {
			tempList.push_back(listPlace);
			indexList[listPlace]--;
		}
	}

	for (int i = 0; i < indexList.size(); i++) {
		list[i] = tempList[i];
		assignments++;
	}
	std::cout << "Index sort required " << assignments << " assignments." << std::endl;

}