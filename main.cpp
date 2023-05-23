#include <iostream>
#include <cstdlib>
#include <vector>

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
        swap(vector[i], vector[index_of_minimum_element]);
        swap_count++;
    }
    return swap_count;
}

/// @brief Realization of shell sort algorithm
/// @param vector vector to sort
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

    if(j > low)
        return swap_count + quick_sort(vector, low, j);
    if(i < hight)
        return swap_count + quick_sort(vector, i, hight);
    return swap_count;
}


int main(){   
    srand((unsigned)time(NULL));

    // Set vector size
    const uint VECTOR_SIZE = 1000;

    // create initial vector and fill it with random numbers [-1000; 1000]
    std::vector<int> v_initial;
    v_initial.resize(VECTOR_SIZE);

    for(int i = 0; i < VECTOR_SIZE; i++){
        v_initial[i] = rand()%2001 - 1000;
    }

    // copy initial vector to vectors for sort
    std::vector<int> v_bubble = v_initial;
    std::vector<int> v_insertion = v_initial;
    std::vector<int> v_shell = v_initial;
    std::vector<int> v_quick = v_initial;

    // call functions to sort vectors and get number of swaps in each algorithm
    std::cout<<"number of swaps in bubble sort: "<<bubble_sort(v_bubble)<<std::endl;
    std::cout<<"number of swaps in insertion sort: "<<insertion_sort(v_insertion)<<std::endl;
    std::cout<<"number of swaps in shell sort: "<<shell_sort(v_shell)<<std::endl;
    std::cout<<"number of swaps in quick sort: "<<quick_sort(v_quick, 0, v_quick.size() - 1)<<std::endl;


    return 0;
}