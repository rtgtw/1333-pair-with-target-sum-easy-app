/*
1333. Pair with target sum

Given an array of numbers sorted in ascending order and a target sum, find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target. If no such pair exists return [-1, -1].

Example 1:

Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6



Solution:

We can employ the two pointers method here where we take two pointers at the head and tail
of the array and slide the pointers

with this specific solution, the array should be sorted 

if sorted, we can take the sum of the two elements, and if the sum is greater than the target
then decrement the tail and vise versa

then return the head and tail indicies 

if no pair exist return -1,-1


*/



#include <iostream>
#include <vector> //Dynamic Array

class Solution {
public:
	static std::vector<int> search(const std::vector<int>& arr, int targetSum);
	
};


 std::vector<int> Solution::search(const std::vector<int>& arr, int targetSum) {

	//Take two pointers, head and tail
	//The head pointer should start at the beginning of the array
	int head = 0;

	//The tail pointer should start at the end of the array, which is length - 1
	int tail = arr.size() - 1;

	//Create an empty vector array to store the ordered pair upon finding the values
	//initialize the ordered pair to -1,-1 per instructions
	std::vector<int> result = { -1,-1 };


	//If head crosses tail (head > tail) that means we have looked at all possible values
	//to achieve this we do <= instead of just <
	//We can use a while loop to look for the target

	while (head < tail) {

		//With each iteration we want to add the sum of head and tail and see if it matches the target
		//If the value is larger than the target we want to decrement tail and vise versa for head
		//We want to return the index of head and tail within a vector as an ordered pair
		if ((arr[head] + arr[tail]) == targetSum) {

			result = { head,tail };
			return result;

		}//if sum is greater than the target then go down, decrement tail
		else if ((arr[head] + arr[tail]) > targetSum) {
		
			tail--;
		}
		//if sum is less than the target then go up, increment head
		else {
			head++;
		}
	}

	//if we come out of the while loop with no hit, then the ordered pair w/ the sum
	//was not found just return array
	return result;


}

 int main() {

	 Solution solution;

	 std::vector<int> array1 = { 1,2,3,4,5,6 };
	 std::vector<int> array2 = { 2,5,9,11 };

	 int target = 6;

	 std::cout << solution.search(array1, target)[0] << ' ' << solution.search(array1,target)[1];



	 /*
	 Time= O(n) we are iterating through a vector array with n elements
	 Space = O(1) we are storing the ordered pair within a vector but thats it, and a couple variables
	 //space is constant time

	 
	 :30 study time

	 */


	 return 0;
 }
