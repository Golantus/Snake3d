#ifndef RNG
#define RNG
#include <cstdlib> // дл€ rand() и srand()
#include <ctime> // дл€ time()

// √енерируем рандомное число между min и max
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// –авномерно распредел€ем генерацию значени€ из диапазона
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
#endif