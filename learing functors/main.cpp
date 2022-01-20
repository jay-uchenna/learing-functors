//
//  main.cpp
//  learing functors
//
//  Created by Jedidiah Uchenna on 20.01.2022.
//

#include <iostream>
#include <vector>
#include <list>
class odd_or_even_test{
private:
    int start_range, end_range;
    bool is_range;
public:
    odd_or_even_test();
    odd_or_even_test(int,int);
    bool operator()(int,std::string);
};
odd_or_even_test::odd_or_even_test(){
    is_range = false;
}
odd_or_even_test::odd_or_even_test(int start_range, int end_range):start_range(start_range),end_range(end_range){
    is_range = true;
}
bool odd_or_even_test::operator()(int val, std::string odd_or_even){
    if(odd_or_even == "even"){
        if (!this->is_range)
            {
                return (val % 2) == 0;
            }
        else{
            if(val >= start_range && val <= end_range && (val % 2) == 0){
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if(odd_or_even == "odd")
    {
        if (!this->is_range)
        {
            return (val % 2) != 0;
        }
        else{
            if(val >= start_range && val <= end_range && (val % 2) != 0){
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else{
        exit(1);
    }
}
void print(int val){
    std::cout << val << " ";
}
/*
bool is_even(int num){
    return (num % 2) == 0;
}
bool is_odd(int num){
    return (num % 2) != 0;
}
 */

template <class Iterator>
int get_count(Iterator start, Iterator end, odd_or_even_test criteria)
    {
        int count = 0;
        for(; start != end; start++){
            if (criteria (*start, "even"))
            {
                print(*start);
                count++;
            }
        }
        return count;
    }

int main(int argc, const char * argv[]) {
    std::list <int> test1 {1,2,3,4,5,6,7,9,10};
    int num_of_odds = get_count(test1.begin(), test1.end(), odd_or_even_test(3,5));
    std::cout << "\n" << num_of_odds << "\n";
    return 0;
}
