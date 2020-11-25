
#include <iostream>
#include <boost/interprocess/ipc/message_queue.hpp>

using namespace boost::interprocess;

int
main()
{
  message_queue::remove("test");
  message_queue mq(create_only, "test", 3, 64);

  while (true) {
    char buffer[64];

    size_t       recv_siz = 0;
    unsigned int prio     = 0;

    std::cout << "Waiting for data..." << std::endl;

    mq.receive(buffer, sizeof(buffer), recv_siz, prio);

    std::cout << "Data received: " << buffer << std::endl;
  }
}
