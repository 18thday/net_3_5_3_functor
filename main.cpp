#include <iostream>
#include <list>
#include <vector>
#include <utility>


struct get_sum {
    template <template<typename...> typename Container, typename T>
    T operator()(const Container<T>& cont) {
        T sum = 0;
        for (T value : cont) {
            if (value % 3 == 0) {
                sum += value;
            }
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


class get_info {
public:
    template <template<typename...> typename Container, typename T>
    std::pair<T, size_t> operator()(const Container<T>& cont) {
        return {get_sum(cont),  get_count(cont)};
    }

private:
    template <template<typename...> typename Container, typename T>
    T get_sum(const Container<T>& cont) {
        T sum = 0;
        for (T value : cont) {
            if (value % 3 == 0) {
                sum += value;
            }
        }
        return sum;
    }

    template <template<typename...> typename Container, typename T>
    size_t get_count(const Container<T>& cont) {
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
    {
        std::vector<int> vector_int{4, 1, 3, 6, 25, 54};
        get_count get_count{};
        get_sum get_sum{};
        std::cout << "Vector Test" << std::endl;
        std::cout << "get_sum() = " << get_sum(vector_int) << std::endl;
        std::cout << "get_count() = " << get_count(vector_int) << std::endl;
    }
    {
        std::list<int> list_int{4, 1, 3, 6, 25, 54};
        get_count get_count{};
        get_sum get_sum{};
        std::cout << std::endl << "List Test" << std::endl;
        std::cout << "get_sum() = " << get_sum(list_int) << std::endl;
        std::cout << "get_count() = " << get_count(list_int) << std::endl;
    }
    {
        std::vector<int> vector_int{4, 1, 3, 6, 25, 54};
        get_info get_info{};
        std::cout << std::endl << "Get Info" << std::endl;
        auto [sum, count] = get_info(vector_int);
        std::cout << "get_sum() = " << sum << std::endl;
        std::cout << "get_count() = " << count << std::endl;
    }

    return 0;
}
