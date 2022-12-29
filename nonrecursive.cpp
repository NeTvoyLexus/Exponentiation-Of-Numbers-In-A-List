#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

const int ARRAY_SIZE = 10e8;

//Возведение числа в степень
inline int binpow (int a, int n) {
	int res = 1;
	while (n)
		if (n & 1) {
			res *= a;
			--n;
		}
		else {
			a *= a;
			n >>= 1;
		}
	return res;
}

// Заполнение вектора случайными цифрами  размером size
vector<int> createListRandomNumbers(int size)
{
  vector<int> randomNumbers;
  for (int i = 0; i < size; i++)
  {
    int randNumbeWithoutZero = 1 + rand() % 9;
    randomNumbers.push_back(randNumbeWithoutZero);
  }
  return randomNumbers;
}

// Возведение в степень цифр в списке
vector<int> exponentiation(vector<int> randomNumbers)
{
  vector<int> randomExponentiationNumbers = randomNumbers;
  for(int i = 0; i < randomExponentiationNumbers.size();i++)
  {
    int randomNumber1to5 = 1 + rand() % 5;
    randomExponentiationNumbers[i] = binpow(randomExponentiationNumbers[i],randomNumber1to5);
  }
  return randomExponentiationNumbers;
}

// Замер времени заполнения вектора случайными цифрами
vector<int> workTimeCreateList(vector<int> randomNumbers)
{
  int startTime = clock();
  randomNumbers = createListRandomNumbers(ARRAY_SIZE);
  int endTime = clock();
  cout << "Defference time(create list): " << endTime - startTime << endl;
  return randomNumbers;
}

// Замер времени возведения цифр в степень
vector<int> workTimeExponentiation(vector<int> randomNumbers)
{
  int startTime = clock();
  randomNumbers = exponentiation(randomNumbers);
  int endTime = clock();
  cout << "Defference time(exponentiation list):  " << endTime - startTime << endl;
  return randomNumbers;
}

int main()
{
  // Иницилизация
  srand((int)time(0));
  vector<int> randomNumbers;

  // Заполнение вектора случайными цифрами с замером времени и его демонстрация
  randomNumbers = workTimeCreateList(randomNumbers);

  // Возведение вектора цифр в случайную степень от 1 до 5 с замером времени и его демонстрация
  randomNumbers = workTimeExponentiation(randomNumbers);
  return 0;
}