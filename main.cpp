#include <iostream>
#include <list>
#include <vector>


struct get_sum {
    template <template<typename...> typename Container, typename T>
    T operator()(const Container<T>& cont) {
        T sum = 0;
        for (T value : cont) {
            sum += value;
        }
        return sum;
    }
};

struct get_count {
    template <typename Container>
    size_t operator()(const Container& cont) {
        size_t count = 0;
        for (auto value : cont) {
            if (value % 3 == 0) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    std::vector<int> vector_int{4, 1, 3, 6, 25, 54};
    get_count get_count{};
    get_sum get_sum{};
    std::cout << "Vector Test" << std::endl;
    std::cout << "get_sum() = " << get_sum(vector_int) << std::endl;
    std::cout << "get_count() = " << get_count(vector_int) << std::endl;

    std::list<int> list_int{4, 1, 3, 6, 25, 54};
    std::cout << std::endl << "List Test" << std::endl;
    std::cout << "get_sum() = " << get_sum(list_int) << std::endl;
    std::cout << "get_count() = " << get_count(list_int) << std::endl;
    return 0;
}
