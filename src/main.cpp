#include <iostream>
#include <glog/logging.h>

using namespace std;

int main()
{
  google::InitGoogleLogging("log_chifoumi");
  google::SetLogDestination(google::GLOG_INFO, "log_chifoumi");
  LOG(INFO) << "Init log..";
  cout << "Hello World !" << endl;
  return 0;
}
