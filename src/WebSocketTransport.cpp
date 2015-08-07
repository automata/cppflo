#include "WebSocketTransport.h"

WebSocketTransport::WebSocketTransport (int port) {
  server httpServer;
  httpServer.set_message_handler(this->handleMessage);
  httpServer.init_asio();
  httpServer.listen(port);
  httpServer.start_accept();
  httpServer.run();
}

void WebSocketTransport::send (string protocol, string topic, Message payload, Message context) {
  cout << protocol << "," << topic << endl;
}

void WebSocketTransport::sendAll (string protocol, string topic, Message payload, Message context) {

}

void WebSocketTransport::receive (string protocol, string topic, Json payload, Json context) {

}

void WebSocketTransport::handleMessage (websocketpp::connection_hdl hdl, server::message_ptr msg) {
  // Call receive
  cout << "Received:" << msg->get_payload() << std::endl;
  const auto msgStr = msg->get_payload();
  string err;
  Json msgJson = Json::parse(msgStr, err);
  if (!err.empty()) {
    cout << "Error:" << err.c_str() << endl;
    return;
  }
  Json context = Json::object {
    { "connection", "foo"},
  };
  WebSocketTransport::receive(msgJson["protocol"].dump(), msgJson["command"].dump(), msgJson["payload"], context);
}
