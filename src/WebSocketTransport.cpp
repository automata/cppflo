#include "WebSocketTransport.h"

WebSocketTransport::WebSocketTransport (int port) {
  server httpServer;
  httpServer.set_message_handler(this->handleMessage);
  httpServer.init_asio();
  httpServer.listen(port);
  httpServer.start_accept();
  httpServer.run();
}

void WebSocketTransport::send (std::string protocol, std::string topic, Message payload, Message context) {
  std::cout << protocol << "," << topic << std::endl;
}

void WebSocketTransport::sendAll (std::string protocol, std::string topic, Message payload, Message context) {

}

void WebSocketTransport::receive (std::string protocol, std::string topic, Message payload, Message context) {

}

void WebSocketTransport::handleMessage (websocketpp::connection_hdl hdl, server::message_ptr msg) {
  // Call receive
  std::cout << "Received:" << msg->get_payload() << std::endl;
}
