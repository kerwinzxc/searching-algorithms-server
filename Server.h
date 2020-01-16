//
// Created by haim on 14/01/2020.
//

#ifndef SERVER_H_
#define SERVER_H_
#define PORT 5600
#include "ClientHandler.h"
class Server {
 public:
  virtual int open(int port, ClientHandler client_handler) = 0;
  virtual void stop() = 0;
};

#endif //SERVER_H_
