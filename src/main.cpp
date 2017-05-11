////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <iostream>
#include <glog/logging.h>
#include "Game.hpp"

using namespace std;

////////////////////////////////////////////////////////////
int main()
{
  // Logging setup
  google::InitGoogleLogging("log_chifoumi");
  google::SetLogDestination(google::GLOG_INFO, "log_chifoumi");
  LOG(INFO) << "Init log..";

  Game game;

  while (game.isRunning())
  {
    game.getPlayerInput();

    if (!game.isRunning())
      break;

    game.play(game.getPlayerChoice());

    cout << game.getLastResult() << endl;;
  }
  
  return 0;
}
