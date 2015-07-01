#include <string>
#include "Message.h"

class BaseTransport {
public:
  // TODO: Create a constructor/destructor
  // Pure virtuals, totally dependent of transport implementation
  virtual void send(std::string protocol, std::string topic, Message payload, Message context) = 0;
  virtual void sendAll(std::string protocol, std::string topic, Message payload, Message context) = 0;
  virtual void receive(std::string protocol, std::string topic, Message payload, Message context) = 0;
};
