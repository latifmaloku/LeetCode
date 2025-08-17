/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/

class Solution {
public:
    // if we scan a string left to right then we know for every closing paren,
    // we must have a open peren that has occurred in the past.
    /*
     * 1. start scaning the string one character at a time
     * 2. if we run into an open paren, then push it into a stack (this is last in first out)
     * 3. if we run into a closed paren, pop item from stack.
     * 4. if popped item is open matching paren then continue. Else fail, and
     * return false.
     */

    // return true if passed in character is an opening paren.
    bool isOpenParen(char c) {
        if ((c == '{') || (c == '[') || (c == '(')) {
            return true;
        }
        return false;
    }

    // return matching opening paren of passed in closing paren
    char getOpeningParen(char c) {
        if(c == '}')
        {
            return '{';
        }

        if(c == ')')
        {
            return '(';
        }

        if(c == ']')
        {
            return '[';
        }

        return ' ';
    }
    bool isValid(string s) {
        // if we get a string of size 1 or less, then no way we can get a closing set
        if(s.length() <= 1)
        {
            return false;
        }

        stack<char> openParens;
        // iterate over string one char at a time
        for(int i = 0; i < s.length(); i++)
        {
            char currentChar = s[i];
            // if this is opening paren, then push it into stack
            if(isOpenParen(currentChar))
            {
                openParens.push(currentChar);
            }else{ // this must be a closing paren
                // if our stack is empty then this is an invalid set of parens
                if(openParens.size() <= 0)
                {
                    return false;
                }
                // get last char pushed into the stack
                char popedParen = openParens.top();
                // if it's not a matching set then return false
                if(popedParen != getOpeningParen(currentChar))
                {
                    return false;
                }
                // remove last item pushed into stack
                openParens.pop();
            }
        }
        // if there is still something in the stack, then there is a paren that was not closed.
        // return false in this case
        if(openParens.size())
        {
            return false;
        }

        return true;
    }

};