#include <vector>
#include <iostream>

using namespace std;

void displayVector(vector<int> vec)
{
    int length = vec.size();
    for(int i = 0; i < length; i++)
    {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

vector<int> removeElement(vector<int> vec, int value)
{
    int vec_size = vec.size();
    int pos = -1;
    // Find position of value within the vector
    for(int i = 0;i < vec_size; i++)
    {
        if(vec.at(i) == value)
        {
            pos = i;
            break;
        }
    }

    if(pos == -1)
    {
        return vec;
    }

    for(int i = pos + 1; i < vec_size; i++)
    {
        vec.at(i-1) = vec.at(i);
    }
    vec.pop_back();
    return vec;
}


int main()
{
    vector<int> vec;
    cout << "Size : " << vec.size() << endl;

    vec.push_back(5);
    displayVector(vec);

    vec.push_back(9);
    displayVector(vec);

    vec.pop_back();
    displayVector(vec);    

    vec.push_back(20);
    vec.push_back(25);
    vec.push_back(33);
    vec.push_back(22);

    displayVector(vec);
    vec = removeElement(vec, 25);
    displayVector(vec);

    return 0;
}