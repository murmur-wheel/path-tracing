//
// Created by murmur-wheel on 2020/10/24.
//

#include <glog/logging.h>

int main(int argc, char* argv[]) {
  ::google::InitGoogleLogging(argv[0]);
  LOG(INFO) << "hello, glog";

  ::google::ShutdownGoogleLogging();
}