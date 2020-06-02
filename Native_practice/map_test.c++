#include <iostream>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

typedef struct{
  int category;
}report;

int main()
{

    vector<int> v;
    v.resize(10, 0);
    for (auto iter = v.begin(); iter != v.end();iter++ )
      cout<<*iter<<endl;


    map<int, report> mp;
    mp[1] = {0};
    mp[10] = {2};
    cout<<"size"<<mp.size()<<endl;

    for(auto iter = mp.begin(); iter != mp.end(); iter++)
      {
        cout<<iter->first<<"\t"<<(iter->second).category<<endl;
      }
  mp[1] = {100};

  for(auto iter = mp.begin(); iter != mp.end(); iter++)
    {
      cout<<iter->first<<"\t"<<(iter->second).category<<endl;
    }
    return 0;
}
