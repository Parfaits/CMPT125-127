#ifndef __FROG_H_INCLUDED__ // if Frog.h hasn't been included yet...
#define __FROG_H_INCLUDED__

class Frog
{
private:
	int age = 0;
	int length = 3;
	bool tadpole;
public:
	void eat();
	void grow();
	void report();	
	
};

#endif // __FROG_H_INCLUDED__ 