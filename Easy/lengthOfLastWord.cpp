/*Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.


Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
*/

/*
* 1. start iterating string backwards
* 2. if we run into space, and we have begun counting word then return length
* 3. if character is not space, then increment length by 1
* 4. go to next character
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        // start at end of string
        // length of word is one
        // index is length of string - 1
        int _length = 0;
        int index = s.length() -1;

        while(index >= 0)
        {
            // we know that there will be at least one word. If this is a space, and we have at least one word
            // then break
            if((s[index] == ' ') && (_length > 0))
            {
                break;
            }
            // if it's not a space, increment size of word by one
            if(s[index] != ' ')
            {
                _length += 1;
            }
            // go to next character
            index -= 1;
        }

        return _length;
    }
};