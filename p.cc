#include <iostream>
#include <queue>
using namespace std; 


int main() {
	cout.setf(ios::fixed);
    cout.precision(4);
    
    int total = 0; 
	priority_queue<int> q1; 
	priority_queue<int> q2;  
	string s; 
	while(cin >> s) {
		if(s == "number") {
			int x; 
			cin >> x;
			total += x;  
			q1.push(x);
			q2.push(-x);  
			double av = double(total)/double(q2.size());  
			cout << "minimum: " << -q2.top() << ", maximum: " << q1.top()
			     << ", average: " << av << endl; 			
		}
		else if(q2.size() == 0) {
			cout << "no elements" << endl;
			while(not q1.empty()) {
				q1.pop(); 
			}
		}
	
		else {
			int x = -q2.top(); q2.pop(); 
			total -= x; 
			if(q2.size() == 0) {
				cout << "no elements" << endl;
				while(not q1.empty()) {
					q1.pop();
				}
			}
			else {
				double av = double(total)/double(q2.size());
				cout << "minimum: " << -q2.top() << ", maximum: " << q1.top()
					 << ", average: " << av << endl;	
			 }
		}
			
	}
}
