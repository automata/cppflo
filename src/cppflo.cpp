// Copyright 2015 Vilson Vieira <vilson@void.cc>

#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>
#include "WebSocketTransport.h"

int main() {
  // TODO: How to do not use pointers?
  WebSocketTransport* wst = new WebSocketTransport(9002);
  //wst->send("foo", "bar", *(new Message()), *(new Message()));
}
