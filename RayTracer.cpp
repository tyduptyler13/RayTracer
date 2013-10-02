
#include<thread>
#include<iostream>

class RayTracer{


public:
	const unsigned concurentThreadsSupported = std::thread::hardware_concurrency();
	RayTracer(){

	}


};

int main(int argc, char** argv){

	RayTracer* r = new RayTracer();
	std::cout << r->concurentThreadsSupported << std::endl;

}
