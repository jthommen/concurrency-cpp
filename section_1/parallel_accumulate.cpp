#include<algorithm>
#include<functional>
#include<iostream>
#include<iterator>
#include<numeric>
#include<string>
#include<thread>
#include<vector>

// Single threaded, sequential implementation
void sequential_accumulate_test()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = std::accumulate(v.begin(), v.end(), 0);

    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

    auto dash_fold = [](std::string a, int b)
    {
        return std::move(a) + "-" + std::to_string(b);
    };

    std:: string s = std::accumulate(std::next(v.begin()), v.end(), std::to_string(v[0]), dash_fold);

    std::cout << "sum - " << sum << std::endl;
    std::cout << "product - " << product << std::endl;
    std::cout << "dash fold - " << s << std::endl;
}


// Parallel, multi threaded implementation
#define MIN_BLOCK_SIZE 1000;

// Used to pass data between threads
template<typename iterator, typename T>
void accumulate(iterator start, iterator end, T& ref)
{
    ref = std::accumulate(start, end, 0);
}

// Main function for the parallelism
template<typename iterator, typename T>
T parallel_accumulate(iterator start, iterator end, T& ref)
{
    // Calculating number of threads
    int input_size = std::distance(start, end);
    int allowed_threads_by_elements = (input_size) / MIN_BLOCK_SIZE;
    int allowed_thread_by_hardware = std::thread::hardware_concurrency();
    int num_threads = std::min(allowed_threads_by_elements, allowed_thread_by_hardware);

    // Calculating block size per thread
    int block_size = (input_size + 1) / num_threads;

    // Container holding threads
    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1); // main thread included

    iterator last; // holding last data block of previous thread block
    for(int i = 0; i < num_threads-1; i++)
    {
        last = start;
        std::advance(last, block_size); // calculating last block per thread
        threads[i] = std::thread(accumulate<iterator, T>, start, last, std::ref(results[i]));

        start = last;
    }

    // giving main thread something to do as well
    results[num_threads-1] = std::accumulate(start, end, 0);

    // Joining all individual threads
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

    // Unify all the results
    return std::accumulate(results.begin(), results.end(), ref);
}

int main()
{
    std::cout << "Sequential Accumulation\n";
    sequential_accumulate_test();

    std::cout << "Parallel Accumulation\n";
    const int size = 10000;
    int* my_array = new int[size];
    int ref = 0;

    srand(0); // what for?
    for(size_t i = 0; i < size; i++)
    {
        my_array[i] = rand() % 10;
    }

    int rer_val = parallel_accumulate<int*, int>(my_array, my_array + size, ref);
    std::cout << "Accumulated value: " << rer_val << std::endl;
}
