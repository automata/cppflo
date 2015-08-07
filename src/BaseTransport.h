#include <string>
#include <json11.hpp>
#include "Message.h"

using namespace std;
using namespace json11;

class BaseTransport {
public:
  // TODO: Create a constructor/destructor
  // Pure virtuals, totally dependent of transport implementation
  virtual void send(string protocol, string topic, Message payload, Message context) = 0;
  virtual void sendAll(string protocol, string topic, Message payload, Message context) = 0;
  static void receive(string protocol, string topic, Json payload, Json context);
};
