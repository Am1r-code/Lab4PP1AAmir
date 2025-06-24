#include <iostream>  // Task 1 
#include <vector>
#include <algorithm>
#include <cstdlib>   
#include <ctime>    
using namespace std;
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    vector<int> numbers;
    for (int i = 0; i < 10; ++i) {
        numbers.push_back(rand() % 100 + 1); 
    }
    cout << "Original vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    sort(numbers.begin(), numbers.end());
    cout << "Sorted vector:   ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    auto min_it = min_element(numbers.begin(), numbers.end());
    auto max_it = max_element(numbers.begin(), numbers.end());
    cout << "Minimum element: " << *min_it << endl;
    cout << "Maximum element: " << *max_it << endl;
    auto last_unique = unique(numbers.begin(), numbers.end());
    numbers.erase(last_unique, numbers.end());
    cout << "Unique vector:   ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}


#include <iostream>  // Task 2
#include <set>
using namespace std;
int main() {
    set<int> numbers;
    int input;
    cout << "Enter 10 integers (duplicates will be ignored):\n";
    for (int i = 0; i < 10; ++i) {
        cin >> input;
        numbers.insert(input);
    }
    cout << "\nEnter a number to search in the set: ";
    cin >> input;
    if (numbers.find(input) != numbers.end()) {
        cout << input << " exists in the set.\n";
    } else {
        cout << input << " does not exist in the set.\n";
    }
    cout << "\nElements in the set are:\n";
    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}


#include <iostream>  // Task 3
#include <sstream>
#include <map>
#include <string>
using namespace std;
int main() {
    string input = "green red yellow red orange purple yellow";
    map<string, int> wordCount;
    stringstream ss(input);
    string word;
    while (ss >> word) {
        wordCount[word]++;
    }
    for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }
    return 0;
}


#include <iostream>  // Task 4
#include <stack>
#include <string>
using namespace std;
bool areParenthesesBalanced(const string& expression) {
    stack<char> s;
    for (char ch : expression) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty()) {
                return false;  
            }
            s.pop();
        }
    }
    return s.empty();  
}
int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);
    if (areParenthesesBalanced(expr)) {
        cout << "Correct\n";
    } else {
        cout << "Incorrect\n";
    }
    return 0;
}


#include <iostream>  // Task 5
#include <queue>
#include <string>
using namespace std;
int main() {
    queue<string> visitors;
    string name;
    cout << "Enter 5 visitor names: \n";
    for (int i = 0; i < 5; ++i) {
        cout << "Visitor " << (i + 1) << ": ";
        getline(cin, name);
        visitors.push(name);
    }
    cout << "\nServing visitors...\n";
    while (!visitors.empty()) {
        cout << "Now serving: " << visitors.front() << endl;
        visitors.pop();
    }
    cout << "Queue is empty." << endl;
    return 0;
}


#include <iostream>  // Task 6
#include <vector>
#include <numeric> 
using namespace std;
double average(const vector<int>& v) {
    if (v.empty()) return 0.0;
    int sum = 0;
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        sum += *it;
    }
    return static_cast<double>(sum) / v.size();
}
int main() {
    vector<int> numbers;
    int input;
    cout << "Enter 5 integers:\n";
    for (int i = 0; i < 5; ++i) {
        cin >> input;
        numbers.push_back(input);
    }
    double result = average(numbers);
    cout << "Average: " << result << endl;
    return 0;
}


#include <iostream>  // Task 7
#include <vector>
#include <algorithm> 
using namespace std;
int main() {
    vector<int> numbers;
    for (int i = 1; i <= 20; ++i) {
        numbers.push_back(i);
    }
    reverse(numbers.begin(), numbers.end());
    int evenCount = count_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });
    cout << "Number of even elements: " << evenCount << endl;
    numbers.erase(remove_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 3 == 0;
    }), numbers.end());
    cout << "Vector after removing numbers divisible by 3:\n";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}