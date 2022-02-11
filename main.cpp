#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <numeric>
#include <climits>
#include <vector>

using namespace std;

int Find_max(vector<int>& vec);
int Find_min(vector<int>& vec);
void Sum_of_all_elements(vector<int>& vec);
int Find_sum_of_max_from_part(vector<int>& vec);
int Sum_of_all_part(int num, vector<int>& vec);
void Input(vector<int>& vec);

int main(int argc, char** argv)
{
  int number;
  cin >> number;
  vector<int> vec(number);
  Input(vec);
  //Find_max(vec);
  //Sum_of_all_elements(vec);
  int sum_max = Find_sum_of_max_from_part(vec);
  cout << sum_max << endl;
  return 0;
}
int Find_max(vector<int>& vec)
{
  int tmp_sum_max = numeric_limits<int>::lowest();
  int num = vec.size();
  for (int i = 0; i < num; i++)
    if (tmp_sum_max < vec.at(i))
      tmp_sum_max = vec.at(i);
  return tmp_sum_max;
}
int Find_min(vector<int>& vec)
{
  int tmp_min = numeric_limits<int>::max();
  int num = vec.size();
  for (int i = 0; i < num; i++)
    if (tmp_min > vec.at(i))
      tmp_min = vec.at(i);
  return tmp_min;
}
int Find_sum_of_max_from_part(vector<int>& vec)
{
  int sum_max = numeric_limits<int>::lowest();
  int num = 1;
  while (num <= vec.size())
  {
    int tmp = Sum_of_all_part(num, vec);
    if (tmp > sum_max)
      sum_max = tmp;
    num++;
  }
  return sum_max;
}
int Sum_of_all_part(int num, vector<int>& vec)
{
  int sum_max = 0;
  for (int i = 0; i < vec.size(); i++)
  {
    int tmp = 0;
    for (int j = i; j < num; j++)
    {
      tmp += vec.at(j);
      if (tmp > sum_max)
        sum_max = tmp;
    }
  }
  return sum_max;
}
void Sum_of_all_elements(vector<int>& vec)
{
  int sum_tmp = 0;
  int num = vec.size();
  for (int i = 0; i < num; i++)
  {
    sum_tmp += vec.at(i);
  }
  cout << sum_tmp << endl;
}
void Input(std::vector<int>& vec)
{
  int num = vec.size();
  for (int i = 0; i < num; i++)
    cin >> vec.at(i);
}