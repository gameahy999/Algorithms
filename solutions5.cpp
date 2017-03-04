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
