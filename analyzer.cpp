#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <chrono>
#include "StringData.cpp"

int main() {

    dataset[] = get_data();

    std::cout << linear_search(dataset, "not_here"), '\n';
    std::cout << binary_search(dataset, "not_here"), '\n';

    std::cout << linear_search(dataset, "mzzzz"), '\n';
    std::cout << binary_search(dataset, "mzzzz"), '\n';

    std::cout << linear_search(dataset, "aaaaa"), '\n';
    std::cout << binary_search(dataset, "aaaaa"), '\n';

    return 0;
}

int linear_search(container[], int element) {

    std::cout << "Linear Search for", element;

    auto start_time = std::chrono::system_clock::now();

    for(int i = 0; i < conatainer.length; i++) {
        if (container[i] == element){
                    auto end_time = std::chrono::system_clock::now();
                    std::chrono::duration<double> time_elapsed = end_time - start_time;
                    std::cout << "Time:", time_elapsed;
                    return i;
            }
    }
    auto end_time  = std::chrono::system_clock::now();
    std::chrono::duration<double> time_elapsed = end_time - start_time;
    std::cout << "Time:", time_elapsed;
    return -1;

}

int binary_search(container[], int element) {

    std::cout << "Binary Search for", element;
    auto start_time = std::chrono::system_clock::now();
    int minIndex = 0;
    int maxIndex = container.length() - 1;
    int midIndex = int((minIndex + (maxIndex - minIndex) / 2));

    while (minIndex <= maxIndex){

        if (element == dataset[midIndex]){
            auto end_time  = std::chrono::system_clock::now();
            std::chrono::duration<double> time_elapsed = end_time - start_time;
            std::cout << "Time: ", time_elapsed;
            return midIndex;
        }
        else if(element > dataset[midIndex] and element < dataset[midIndex + 1]){
            auto end_time   = std::chrono::system_clock::now();
            std::chrono::duration<double> time_elapsed = end_time - start_time;
            std::cout << "Time: ", time_elapsed;
            return -1;
        }

        else if(element < dataset[midIndex]){
            maxIndex = midIndex;
            midIndex = int((minIndex + (maxIndex - minIndex) / 2));
            continue;
        }
        else if(element > dataset[midIndex]){
            minIndex = midIndex;
            midIndex = int((minIndex + (maxIndex - minIndex) / 2));
            continue;
        }

    }

}