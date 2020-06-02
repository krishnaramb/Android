#include <iostream>
using namespace std;

typedef struct{
  int score;
  int category;
}report_t;

int32_t get_report(report_t* &report, size_t &size)
{
  report_t* myreport = new report_t;
  if (!myreport) return -1;

  myreport->score = 10;
  myreport->category = 1;

  report = myreport;
  size = sizeof(report_t);
  return 0;
}



int main()
{
  report_t* report = nullptr;
  size_t size = 0;
  if (get_report(report, size) == 0)
  {
    if (report && size!=0)
      cout<<"score: "<<report->score<<" "<<"category: "<<report->category <<"size: "<<size<<endl;
    else
      cout<<"report is null "<<"sz: "<<size;
  }

  const void *ptr = new report_t;

  const report_t * ptr2 = static_cast<const report_t*>(ptr);

  return 0;

}
