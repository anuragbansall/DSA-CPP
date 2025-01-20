#include <iostream>
using namespace std;

void clearRangeOfBits(int num, int i, int j);
void singleNumber(int nums[], int n);
void xorBeauty(int nums[], int n);
void divideTwoIntegers(int dividend, int divisor);

int main()
{
    /*
    Question 1:
        Write a function to clear the range of bits from i to j in a given number.
        (i & j are counted backwards from the right end of the number)
        Examples:
        Input: num = 15, i = 1, j = 3
        Output: 1
        Explanation: 15 in binary form is => 00001111 [i = 1st & j = 3rd bit underlined]
        After bits are cleared, number will become 00000001
        Input: num = 31, i = 1, j = 3
        Output: 17
        Note - Think about what type of bitmask is needed. It can also be a combination of 2 numbers.
    */
    int num, i, j;
    cout << "Enter the number, i and j: ";
    cin >> num >> i >> j;

    clearRangeOfBits(num, i, j);

    /*
    Question 2:
        Given a non-empty array of integers nums, every element appears twice except for one.
        Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.
        Hint - Think XOR.
    */
    int arr[] = {4, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    singleNumber(arr, n);

    /*
    Question 3:
        You are given a 0-indexed integer array nums. The effective value of three indices i, j, and k is defined as ((nums[i] | nums[j]) & nums[k]).
        The xor-beauty of the array is the XORing of the effective values of all the possible triplets of indices (i, j, k) where 0 <= i, j, k < n.
        Return the xor-beauty of nums.
    */
    int arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    xorBeauty(arr2, n2);

    return 0;
}

void clearRangeOfBits(int num, int i, int j)
{
    int a = ~0 << (j + 1);
    int b = (1 << i) - 1;

    int mask = a | b;
    int ans = num & mask;

    cout << "Number after clearing bits: " << ans << endl;
}

void singleNumber(int nums[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= nums[i];
    }
    cout << "Single number: " << ans << endl;
}

void xorBeauty(int nums[], int n)
{
    int beauty = 0;
    for (int i = 0; i < n; i++)
    {
        beauty ^= nums[i];
    }

    cout << "XOR Beauty: " << beauty << endl;
}