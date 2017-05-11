////////////////////////////////////////////////////////////
///
/// \brief Main entry point
/// \file main.cpp
/// \author Florian
/// \date 11 mai 2017
///
////////////////////////////////////////////////////////////


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
    // Get player input from standard input
    game.getPlayerInput();

    // Quit case
    if (!game.isRunning())
      break;

    // Compute result
    game.play(game.getPlayerChoice());

    // Display result
    cout << game.getLastResult() << endl;;
  }
  
  return 0;
}
