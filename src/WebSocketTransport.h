#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include "BaseTransport.h"

typedef websocketpp::server<websocketpp::config::asio> server;

class WebSocketTransport : public BaseTransport {
public:
  WebSocketTransport(int port);
  void send(string protocol, string topic, Message payload, Message context);
  void sendAll(string protocol, string topic, Message payload, Message context);
  static void receive(string protocol, string topic, Json payload, Json context);
private:
  static void handleMessage(websocketpp::connection_hdl hdl, server::message_ptr msg);
};
