#include "PmergeMe.hpp"
#include <vector>
#include <deque>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <list of positive integers>\n";
		return 1;
	}

	for (int i = 1; argv[i] != NULL; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++){
			if (!std::isdigit(argv[i][j]) && argv[i][j] != ' '){
				std::cerr << "Usage: " << argv[0] << " <list of positive integers>\n";
				exit(0);
			}
		}
	}

	PmergeMe sorter;
	std::vector<int> dataVector;
	std::deque<int> dataDeque;

	sorter.processInputAndSort(dataVector, argv, argc, "std::vector");
	sorter.processInputAndSort(dataDeque, argv, argc, "std::deque");

	return 0;
}
