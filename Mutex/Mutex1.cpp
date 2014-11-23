// Example of mutex

#include <mutex>		// mutex
#include <thread>		// thread
#include <iostream>		// cout

using namespace std;

mutex mtx;	// mutex for critical section

void print_block_wo_mtx (int n, char c) 
{
	for (int i = 0; i < n; ++i) 
		cout << c; 
	
	cout << '\n';
}

void print_block_with_mtx (int n, char c) 
{
	// Critical section (exclusive access to cout signaled by locking mtx).
	// The mutex object is modified as an atomic operation (causes no data races).
	mtx.lock();

	for (int i = 0; i < n; ++i) 
		cout << c;

	cout << '\n';
	
	mtx.unlock();
}

int main ()
{
	cout << "Printing chars without synchronized access via mutex primitive:\n\n";

	thread th1 (print_block_wo_mtx, 200, '*');
	thread th2 (print_block_wo_mtx, 200, '$');

	th1.join();
	th2.join();

	cout << endl;

	cout << "Printing chars with synchronized access via mutex primitive:\n\n";

	thread th3 (print_block_with_mtx, 200, '*');
	thread th4 (print_block_with_mtx, 200, '$');

	th3.join();
	th4.join();

	cin.get();

	return 0;
}