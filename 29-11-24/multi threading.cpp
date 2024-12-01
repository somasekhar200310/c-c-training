
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx;

void threadfun()
{
	cout << "this is thread fun\n";
	for (int i = 1; i <= 10000; i++)
	{
	    mtx.lock();
		cout << "thread " << i << endl;
	    mtx.unlock();
	}
}
 
int main()
{
    thread thrd1(threadfun);
    thread thrd2(threadfun);

    thrd1.join();
    thrd2.join();

	return 0;
}
