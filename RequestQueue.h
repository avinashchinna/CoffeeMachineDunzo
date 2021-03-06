#ifndef REQUESTQUEUE_H_INCLUDED
#define REQUESTQUEUE_H_INCLUDED

#include<queue>
#include<mutex>
#include<string>
using namespace std;

// Thread safe queue data structure to store the serve beverages requests from the machine
class RequestQueue{
	queue<string> worker_queue;
	mutex mu; // mutex to permit access to critical section of code
public:
	RequestQueue(){}

	void push(string beverage){
		unique_lock<mutex> lock(mu);
		worker_queue.push(beverage);
	}

	bool pop(string& beverage){
		unique_lock<mutex> lock(mu);
		if(worker_queue.empty()){
			return false;
		}
		beverage = worker_queue.front();
		worker_queue.pop();
		return true;
	}

	bool isEmpty(){
		unique_lock<mutex> lock(mu);
		return worker_queue.empty();
	}
};

#endif // REQUESTQUEUE_H_INCLUDED
