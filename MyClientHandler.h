#ifndef FLIGHTSIMULATORPART2__MYCLIENTHANDLER_H_
#define FLIGHTSIMULATORPART2__MYCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "State.h"
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <sys/socket.h>
#include <vector>

/**
 * The Client Handler class handles receiving problems and passing them on to a solver, and then sending the solution
 * back.
 */
class MyClientHandler : public ClientHandler{
 public:
  explicit MyClientHandler(CacheManager *file_cache_manager) {
    this->cacheManager = file_cache_manager;
  }
  void handleClient(int input_stream, int output_stream) override;

 private:
  static void rmLinebreak(std::string& str);
  CacheManager* cacheManager;
};

#endif //FLIGHTSIMULATORPART2__MYCLIENTHANDLER_H_
