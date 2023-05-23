#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <thread>

/// @brief Function to swap values of two variables, two variables must be same type
/// @tparam T template for function
/// @param param1 first variable to swap
/// @param param2 second variable to swap
template<typename T>
void swap(T &param1, T &param2){
    T temporal_value = param1;
    param1 = param2;
    param2 = temporal_value;
}

/// @brief Realization of bubble sort algorithm
/// @param vector vector to sort
/// @return number of swaps
int bubble_sort(std::vector<int> &vector){
    int swap_count = 0;
    for(int i = 0; i < vector.size() - 1; i++){
        for(int j = i + 1; j < vector.size(); j++){
            if (vector[i] > vector[j]){
                swap(vector[i], vector[j]);
                swap_count++;
            }
        }
    }
    return swap_count;
}

/// @brief Realization of insertion sort algorithm
/// @param vector vector to sort
/// @return number of swaps
int insertion_sort(std::vector<int> &vector){
    int swap_count = 0;
    int index_of_minimum_element;
    for(int i = 0; i < vector.size() - 1; i++){
        index_of_minimum_element = i;
        for(int j = i + 1; j < vector.size(); j++){
            if (vector[j] < vector[index_of_minimum_element]) index_of_minimum_element = j;
        }
        if(i != index_of_minimum_element){
            swap(vector[i], vector[index_of_minimum_element]);
            swap_count++;
        }
    }
    return swap_count;
}

/// @brief Realization of shell sort algorithm
/// @param vector vector to sort
/// @return number of swaps
int shell_sort(std::vector<int> &vector){
    int swap_count = 0;
    for(int s = vector.size() / 2; s > 0; s /= 2){
        for(int i = s; i < vector.size(); i++){
            for(int j = i - s; j >= 0 && vector[j] > vector[j + s]; j -= s){
                swap(vector[j], vector[j + s]);
                swap_count++;
            }
        }
    }
    return swap_count;
}


/// @brief Realization of quick sort algorithm
/// @param vector vector to sort
/// @param low start of sorted vector
/// @param hight end of sorted vector
/// @return number of swaps
int quick_sort(std::vector<int> &vector, int low, int hight){
    int swap_count = 0;
    int i = low, j = hight;
    int pivot = vector[(i + j) / 2];

    while(i <= j){
        while(vector[i] < pivot)
            i++;
        while(vector[j] > pivot)
            j--;
        if(i <= j){
            swap(vector[i], vector[j]);
            swap_count++;
            i++;
            j--;
        }
    }

    if(j > low){
        swap_count += quick_sort(vector, low, j);
    }
    if(i < hight)
    {
        swap_count += quick_sort(vector, i, hight);
    }
    return swap_count;
}


/// @brief Function that run bubble sort for vector and measurement elapsed time
/// @param vector reference to the vector to be copied for sorting
void function_bubble_sort_in_thread(const std::vector<int>& vector){
    // create copy of vector
    std::vector<int> v_bubble = vector;

    // create variable to store elapsed seconds in each algorithm
    std::chrono::duration<double> elapsed_seconds;

    // get time before call bubble_sort function
    auto start = std::chrono::system_clock::now();

    // run bubble_sort function and store number of swaps
    int number_of_swaps = bubble_sort(v_bubble);

    // get time after call bubble_sort function
    auto end = std::chrono::system_clock::now();
    
    // count elapsed time
    elapsed_seconds = end - start;

    // print info in console
    std::cout<<"number of swaps in bubble sort: "<<number_of_swaps<<std::endl;
    std::cout<<"elapsed time in bubble sort: "<<elapsed_seconds.count()<<"s"<<std::endl;
}

/// @brief Function that run insertion sort for vector and measurement elapsed time
/// @param vector reference to the vector to be copied for sorting
void function_insertion_sort_in_thread(const std::vector<int> &vector){
    // create copy of vector
    std::vector<int> v_insertion = vector;

    // create variable to store elapsed seconds in each algorithm
    std::chrono::duration<double> elapsed_seconds;

    // Get time before call insertion_sort function
    auto start = std::chrono::system_clock::now();

    // run insertion_sort function and store number of swaps
    int number_of_swaps = insertion_sort(v_insertion);
    
    // Get time after call insertion_sort function
    auto end = std::chrono::system_clock::now();
    
    // count elapsed time
    elapsed_seconds = end - start;

    // print info in console
    std::cout<<"number of swaps in insertion sort: "<<number_of_swaps<<std::endl;
    std::cout<<"elapsed time in insertion sort: "<<elapsed_seconds.count()<<"s"<<std::endl;
}

/// @brief Function that run shell sort for vector and measurement elapsed time
/// @param vector reference to the vector to be copied for sorting
void function_shell_sort_in_thread(const std::vector<int> &vector){
    // create copy of vector
    std::vector<int> v_shell = vector;

    // create variable to store elapsed seconds in each algorithm
    std::chrono::duration<double> elapsed_seconds;

    // Get time before call shell_sort function
    auto start = std::chrono::system_clock::now();

    // run shell_sort function and store number of swaps
    int number_of_swaps = shell_sort(v_shell);
 
    // Get time after call shell_sort function
    auto end = std::chrono::system_clock::now();
    
    // count elapsed time
    elapsed_seconds = end - start;

    // print info in console
    std::cout<<"number of swaps in shell sort: "<<number_of_swaps<<std::endl;
    std::cout<<"elapsed time in shell sort: "<<elapsed_seconds.count()<<"s"<<std::endl;
}

/// @brief Function that run quick sort for vector and measurement elapsed time
/// @param vector reference to the vector to be copied for sorting
void function_quick_sort_in_thread(const std::vector<int> &vector){
    // create copy of vector
    std::vector<int> v_quick = vector;

    // create variable to store elapsed seconds in each algorithm
    std::chrono::duration<double> elapsed_seconds;

    // Get time before call quick_sort function
    auto start = std::chrono::system_clock::now();

    // run quick_sort function and store number of swaps
    int number_of_swaps = quick_sort(v_quick, 0, v_quick.size() - 1);
    
    // Get time after call quick_sort function
    auto end = std::chrono::system_clock::now();

    // count elapsed time
    elapsed_seconds = end - start;

    // print info in console
    std::cout<<"number of swaps in quick sort: "<<number_of_swaps<<std::endl;
    std::cout<<"elapsed time in quick sort: "<<elapsed_seconds.count()<<"s"<<std::endl;
}


int main(){   
    srand((unsigned)time(NULL));

    // Set vector size
    const uint VECTOR_SIZE = 100000;

    // create initial vector and fill it with random numbers [-1000; 1000]
    std::vector<int> v_initial;
    v_initial.resize(VECTOR_SIZE);

    for(int i = 0; i < VECTOR_SIZE; i++){
        v_initial[i] = rand()%2001 - 1000;
    }

    std::cout<<"Vector size = "<<VECTOR_SIZE<<std::endl<<std::endl;

    // Create thread for sort algorithms, one thread - one alghoritm
    std::thread th_bubble_sort(function_bubble_sort_in_thread, std::ref(v_initial));
    std::thread th_insertion_sort(function_insertion_sort_in_thread, std::ref(v_initial));
    std::thread th_shell_sort(function_shell_sort_in_thread, std::ref(v_initial));
    std::thread th_quick_sort(function_quick_sort_in_thread, std::ref(v_initial));


    // Wait all algorithms finished
    th_bubble_sort.join();
    th_insertion_sort.join();
    th_shell_sort.join();
    th_quick_sort.join();

    return 0;
}