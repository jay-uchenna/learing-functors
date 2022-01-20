//
//  main.cpp
//  learing functors
//
//  Created by Jedidiah Uchenna on 20.01.2022.
//

#include <iostream>
#include <vector>
#include <list>
#include "even.hpp"
#include "odd.hpp"



void print(int val){
    std::cout << val << " ";
}

template <class Iterator,typename T>
int get_count(Iterator start, Iterator end, T criteria)
    {
        int count = 0;
        for(; start != end; start++){
            if (criteria (*start))
            {
                print(*start);
                count++;
            }
        }
        return count;
    }

int main(int argc, const char * argv[]) {
    std::list <int> test1 {1,2,3,4,5,6,7,9,10};
    int num_of_odds = get_count(test1.begin(), test1.end(), even());
    std::cout << "\n" << num_of_odds << "\n";
    return 0;
}
