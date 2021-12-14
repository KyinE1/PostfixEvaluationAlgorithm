#include <iostream>
#include <string>
#include "eval.h"
#include "inpost.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

/** Reads a series of infix strings from standard input. Each string is converted to 
 *  postfix, printed, evaluated to find the result.
 * 
 * @return: End of driver code.
 */
int main() {
    string infix;
    string postfix;

    while (getline(cin, infix)) {
        cout << "  infix: " << infix << endl;
        postfix = convert(infix);
        cout << "postfix: " << postfix << endl;
        int result = evaluate(postfix);
        cout << "  value: " << result << endl << endl;
    }

    return 0;
}
