#include <iostream>
using namespace std;

typedef struct
{
  uint8   percent_malicious_tower;
  uint8   percent_imsi_leak;
  uint8   percent_imprisoner;
  uint8   percent_dos;
  uint8   percent_downgrade;
  uint8   percent_location_tracker;
  uint8   percent_attractive;
  uint8   percent_threat_prevented;
}TimeAvgSummaryReport;

class TimeAvgReport
{
  TimeAvgSummaryReport report;

public:
    virtual void calTimeAvgSummaryReport() = 0;
    TimeAvgSummaryReport getTimeAvgSummaryReport()
    {
      return report;
    }
};


class MinAvgReport:public TimeAvgReport
{
  int maxNode;
public:
    void calTimeAvgSummaryReport() override;
};

class HourAvgReport:public TimeAvgReport
{
  int maxNode;
public:
    void calTimeAvgSummaryReport() override;
};

class DayAvgReport:public TimeAvgReport
{
  int maxNode;
public:
    void calTimeAvgSummaryReport() override;
};

class WeekAvgReport:public TimeAvgReport
{
  int maxNode;
public:
    void calTimeAvgSummaryReport() override;
};

class MonthAvgReport:public TimeAvgReport
{
  int maxNode;
public:
    void calTimeAvgSummaryReport() override;
};

void MinAvgReport::calTimeAvgSummaryReport()
{
  cout<<"calculating minAvgSummaryReport"<<endl;
}
