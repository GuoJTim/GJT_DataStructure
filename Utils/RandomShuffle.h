#include <vector>
#include <random>
#include <algorithm>
#ifndef RandomShuffle_H
#define RandomShuffle_H 
class RandomShuffle{
	public:
		template<class T>
		static void arr_shuffle(std::vector<T> &arr){
			std::random_device rd;
			std::default_random_engine rng(rd());
			shuffle(arr.begin(),arr.end(),rng);
		}
		
};
#endif
