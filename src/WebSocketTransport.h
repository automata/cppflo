#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include "BaseTransport.h"

typedef websocketpp::server<websocketpp::config::asio> server;

class WebSocketTransport : public BaseTransport {
public:
  WebSocketTransport(int port);
  void send(std::string protocol, std::string topic, Message payload, Message context);
  void sendAll(std::string protocol, std::string topic, Message payload, Message context);
  void receive(std::string protocol, std::string topic, Message payload, Message context);
private:
  static void handleMessage(websocketpp::connection_hdl hdl, server::message_ptr msg);
};
