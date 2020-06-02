#include<iostream>
#include<deque>

using namespace std;
typedef struct{
  int id;
  int category;
}report;

const int id_to_find = 10;
const int cat_to_replace = 900;
const int MAX_D_REPORT_SZ = 5;
deque<report> d_report;

void insert_deque(report report)
{
  for(auto iter = d_report.begin(); iter != d_report.end(); iter++)
  {
    if(iter->id ==report.id)
    {
      d_report.erase(iter);
      break;
    }
  }
  d_report.push_front(report);
  if (d_report.size() > MAX_D_REPORT_SZ)
  {
    d_report.pop_back();
  }
}

int main()
{

  insert_deque({1,1});
  insert_deque({2,2});
  insert_deque({3,3});
  insert_deque({4,4});
  insert_deque({5,5});
  insert_deque({6,6});
  for(auto iter = d_report.begin(); iter != d_report.end(); iter++)
  {
    cout<<iter->category<<endl;
  }

  insert_deque({3,300});
cout <<"---------------------"<<endl;
  for(auto iter = d_report.begin(); iter != d_report.end(); iter++)
  {
    cout<<iter->category<<endl;
  }

  insert_deque({8,8});
cout <<"---------------------"<<endl;
  for(auto iter = d_report.begin(); iter != d_report.end(); iter++)
  {
    cout<<iter->category<<endl;
  }
  // d_report.push_front({1,10});
  // d_report.push_front({2,2});
  // d_report.push_front({3,5});
  // d_report.push_front({4,300});
  // cout<<"count: "<<d_report.size()<<endl;
  //
  // for(auto iter = d_report.begin(); iter != d_report.end(); iter++)
  // {
  //   cout<<iter->category<<endl;
  // }
  //
  // cout<<"back: "<<d_report.back().category<<endl;
  // cout<<"count: "<<d_report.size()<<endl;
  //
  // for(auto iter = d_report.begin(); iter != d_report.end(); iter++)
  // {
  //   cout<<iter->category<<endl;
  // }
  //
  // d_report.pop_back();
  // cout<<"count: "<<d_report.size()<<endl;
  // for(auto iter = d_report.begin(); iter != d_report.end(); iter++)
  // {
  //   cout<<iter->category<<endl;
  // }
  //


  return 0;
}

// 4 3  2 1
