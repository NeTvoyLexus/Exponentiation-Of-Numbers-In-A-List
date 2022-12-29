#include <iostream>
#include <ctime>
#include <vector>
#include <thread>
#include <future>

using namespace std;

const int ARRAY_SIZE = 10e8;

//Возведение числа в степень
int binpow(int a, int n)
{
  int res = 1;
  while (n)
  {
    if (n & 1)
      res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}

vector<int> createListRandomNumbersAsync(int threadNumber, int threadCount)
{
  int size = ARRAY_SIZE/threadCount;
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

vector<int> workTimeAsync(int threadNumber, int threadCount)
{
  int startTime = clock();
  vector<int> randomNumbers = createListRandomNumbersAsync(threadNumber,threadCount);
  int endTime = clock();
  cout << "T-" << threadNumber << "[CRT]: " << endTime - startTime << "ms." << endl;
  randomNumbers = exponentiation(randomNumbers);
  startTime = clock();
  randomNumbers = exponentiation(randomNumbers);
  endTime = clock();
  cout << "T-" << threadNumber << "[EXP]: " << endTime - startTime << "ms." << endl;
  return randomNumbers;
}

int main()
{
  // Иницилизация
  srand((int)time(0));
  vector<int> randomNumbers;
  int startTime = clock();

  vector<future<vector<int>>> responces;
  for(int i = 1; i <= 10; i++ )
  {
    responces.push_back(async(&workTimeAsync, i, 10));
  }
  
  for(int i = 0; i < responces.size(); i++ )
  {
    vector<int> tmp = responces[i].get();
    randomNumbers.insert(randomNumbers.end(), tmp.begin(), tmp.end());
  }

  int endTime = clock();
  cout << "Defference time(work threads): " << endTime - startTime << endl;
  return 0;
}