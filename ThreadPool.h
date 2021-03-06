#ifndef THREADPOOL_H_INCLUDED
#define THREADPOOL_H_INCLUDED

#include<thread>
#include<atomic>
#include<string>
using namespace std;

#include "RequestQueue.h"
#include "machine.h"
#include "Beverage.h"

// Custom implementation of ThreadPool to manage creation of threads and serve the requests from the machine
class ThreadPool{
	int numThreads; // initializes to number of outlets to allow serving N beverages in parallel
	atomic<bool> flag; //atomic flag to initiate and terminate the execution of threads
	RequestQueue worker_queue;
	vector<thread> threads;
	Machine* machine;

	// main function run by threads to serve beverages from the worker queue
	void do_work(){
		while(!flag){
			string beverage;
			if(worker_queue.pop(beverage)){
				//task();
				machine->serveBeverage(beverage);
			}else{
				this_thread::yield();
			}
		}
	}
public:
	ThreadPool(int _numThreads, Machine* _machine){
		this->numThreads = _numThreads;
		this->machine = _machine;
		flag = false;
		try{
			for(int i=0;i<_numThreads;i++){
				threads.push_back(thread(&ThreadPool::do_work, this));
			}
		}
		catch(...){
			flag = true;
			throw;
		}
	}

	void shutdown(){
	    while(!worker_queue.isEmpty()){
            this_thread::yield();
	    }
        flag = true;
		for(int i=0;i<numThreads;i++){
			if(threads[i].joinable()){
				threads[i].join();
			}
		}
	}

    ~ThreadPool(){
		flag = true;
		for(int i=0;i<numThreads;i++){
			if(threads[i].joinable()){
				threads[i].join();
			}
		}
	}

	void submit(string beverage){
		worker_queue.push(beverage);
	}
};

#endif // THREADPOOL_H_INCLUDED
