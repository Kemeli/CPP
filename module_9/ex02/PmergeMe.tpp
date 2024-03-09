template <typename Container>
void PmergeMe::displayFinalTime(struct timeval &start, Container &container, std::string type)
{
	struct timeval end;
	gettimeofday(&end, NULL);
	double vec_time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	std::cout << 
		"Time to process a range of "
		<< std::fixed
		<< std::setprecision(6)
		<< container.size() <<
		" elements with " << type << " => "
		<< vec_time << " us" << std::endl;
}


template <typename Container>
void PmergeMe::fillContainer(Container& container, char* argv[], int argc)
{
	for (int i = 1; i < argc; ++i) {
		int number = atoi(argv[i]);
		container.push_back(number);
	}
}


template <typename Container>
void PmergeMe::processInputAndSort(Container& container, char* argv[], int argc, std::string type) {
	struct timeval start;
	gettimeofday(&start, NULL);
	fillContainer(container, argv, argc);
		
	std::cout << "Before: ";
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << "\n";
	
	fordJohnsonSort(container, 0, container.size() - 1);
	displayFinalTime(start, container, type);

	std::cout << "After: ";
	for (size_t i = 0; i < container.size(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << "\n";
}


template <typename Container>
void PmergeMe::fordJohnsonSort(Container& container, int left, int right) {
	if (left >= right)
		return ;

	int middle = left + (right - left) / 2;

	fordJohnsonSort(container, left, middle);
	fordJohnsonSort(container, middle + 1, right);

	merge(container, left, middle, right);
}

template <typename Container>
void PmergeMe::merge(Container& container, int left, int middle, int right) {
	int n1 = middle - left + 1;
	int n2 = right - middle;

	Container L, R;

	for (int i = 0; i < n1; i++)
		L.push_back(container[left + i]);
	for (int j = 0; j < n2; j++)
		R.push_back(container[middle + 1 + j]);

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			container[k] = L[i];
			i++;
		} else {
			container[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		container[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		container[k] = R[j];
		j++;
		k++;
	}
}
