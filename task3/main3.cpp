#include <iostream>
#include <thread>
#include <future>
#include <vector>

template<typename Iterator, typename T>
T parallel_for_each(Iterator first, Iterator last, T f) {

    const std::size_t length = std::distance(first, last);
    const std::size_t min = 25;

    if (length < (2 * min)) {
        std::for_each(first, last, f);
    }
    else {
        Iterator const middle = first + length / 2;

        std::future<T> first_half_result = std::async(&parallel_for_each<Iterator, T>, first, middle, f);
        parallel_for_each(middle, last, f);
        first_half_result.get();
    }
}

int main(int argc, char** argv) {

    std::vector<int> numbers{ 3, 4, 2, 8, 15, 267, 23, 42 };
    std::for_each(numbers.begin(), numbers.end(), [](const int& n) {
        std::cout << " " << n; 
        }
    );

    return EXIT_SUCCESS;
}