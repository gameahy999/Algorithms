#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>

#include "binaryTree.h"
#include "search.h"
#include "sort.h"
#include "util.h"

using namespace std;

/* Implementations for problem 500 ~ 599 */

/* 500. Keyboard Row */

/* Example 1:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

*/

vector<string>
findWords(vector<string>& words)
{
    // Row number for  A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
    int charMap[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
    std::vector<string> svec;
    for (vector<string>::iterator iter = words.begin();
         iter != words.end();
         iter++) {
        if ((*iter).length() <= 1) {
            svec.push_back(*iter);
            continue;
        }

        int line = charMap[tolower((*iter)[0]) - 'a'];
        bool canTypeInOneRow = true;
        for (int i = 1; i < (*iter).length(); i++) {
            if (line != charMap[tolower((*iter)[i]) - 'a']) {
                canTypeInOneRow = false;
                break;
            }
        }
        if (canTypeInOneRow) {
            svec.push_back(*iter);
        }
    }

    return svec;
}

void
test_findWords()
{
    std::vector<string> v;
    v.push_back("Hello");
    v.push_back("Alaska");
    v.push_back("Dad");
    v.push_back("Peace");

    std::vector<string> v_output = findWords(v);
    for (vector<string>::iterator iter = v_output.begin();
         iter != v_output.end();
         iter++) {
        cout << *iter << endl;
    }
}


/* 506. Relative Ranks */

/* Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:

Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
For the left two athletes, you just need to output their relative ranks according to their scores.

Note:

1.N is a positive integer and won't exceed 10,000.
2.All the scores of athletes are guaranteed to be unique.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **
findRelativeRanks(int *nums, int numsSize, int *returnSize)
{
    return NULL;
}

vector<string>
findRelativeRanks(vector<int>& nums)
{
    // TODO
    std::vector<string> v;
    return v;
}

void
test_findRelativeRanks()
{

}


/* 520. Detect Capital */

/* Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:
1.All letters in this word are capitals, like "USA".
2.All letters in this word are not capitals, like "leetcode".
3.Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Example 1:

Input: "USA"
Output: True

Example 2:

Input: "FlaG"
Output: False
*/

bool
detectCapitalUse(char *word)
{
    // TODO
    return false;
}

void
test_detectCapitalUse()
{

}


/* 530. Minimum Absolute Difference in BST */

/* Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:
Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

Note: There are at least two nodes in this BST.
*/

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int
getMinimumDifference(struct TreeNode *root)
{
    // TODO
    return 0;
}

void
test_getMinimumDifference()
{

}
