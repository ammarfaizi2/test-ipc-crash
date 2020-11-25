
#include <iostream>
#include <boost/interprocess/ipc/message_queue.hpp>

using namespace boost::interprocess;

int
main()
{
  message_queue mq(open_only, "test");

  while (true) {
    char buffer[64] = "Hello World!";
    if (mq.try_send(buffer, sizeof(buffer), 0)) {
      std::cout << "Data sent!" << std::endl;
    } else {
      std::cout << "Queue is full!" << std::endl;
    }
  }
}
