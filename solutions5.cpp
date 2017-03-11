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


/* 508. Most Frequent Subtree Sum */

/*  Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3

return [2, -3, 4], since all the values happen only once, return all of them in any order.

Examples 2
Input:

  5
 /  \
2   -5

return [2], since 2 happens twice, however -5 only occur once.

Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer. */

int *
findFrequentTreeSum(struct TreeNode *root, int *returnSize)
{
    // TODO
    return NULL;
}

void
test_findFrequentTreeSum()
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

static bool
isAllLower(char *word)
{
    if (word == NULL || strlen(word) == 0) return true;

    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (isupper(word[i])) {
            return false;
        }
    }
    return true;
}

static bool
isAllUpper(char *word)
{
    if (word == NULL || strlen(word) == 0) return true;

    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        if (islower(word[i])) {
            return false;
        }
    }
    return true;
}

bool
detectCapitalUse(char *word)
{
    if (word == NULL || strlen(word) == 0) return false;

    if (isupper(word[0])) {
        return isAllUpper(word + 1) || isAllLower(word + 1);
    } else {
        return isAllLower(word + 1);
    }
}

void
test_detectCapitalUse()
{
    const char *word1 = "USA";
    util::printBool(detectCapitalUse(const_cast<char *>(word1)));
    const char *word2 = "FlaG";
    util::printBool(detectCapitalUse(const_cast<char *>(word2)));
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

int
getMinimumDifference(struct TreeNode *root)
{
    int minimum = INT_MAX;
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return minimum;

    int leftSideMin =
        util::min(getMinimumDifference(root->left),
                  util::abs_ex(root->val - getMaxElementOfBinarySearchTree(root->left)));
    int rightSideMin =
        util::min(getMinimumDifference(root->right),
                  util::abs_ex(getMinElementOfBinarySearchTree(root->right) - root->val));

    return util::min(leftSideMin, rightSideMin);
}

void
test_getMinimumDifference()
{
    printf("%d\n", getMinimumDifference(NULL));

    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = root->right = new TreeNode(3);
    TreeNode *node2 = node1->left = new TreeNode(2);
    printf("%d\n", getMinimumDifference(root));
    delete root;
    delete node1;
    delete node2;

    root = new TreeNode(0);
    node1 = new TreeNode(2236);
    node2 = new TreeNode(1277);
    TreeNode *node3 = new TreeNode(519);
    TreeNode *node4 = new TreeNode(2776);
    root->right = node1;
    node1->left = node2;
    node1->right = node4;
    node2->left = node3;
    printf("%d\n", getMinimumDifference(root));
    delete root;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
}
