////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CppUTest/CommandLineTestRunner.h>
#include "Game.hpp"
#include <iostream>

TEST_GROUP(GroupGame) { };


////////////////////////////////////////////////////////////
TEST(GroupGame, Game_test1)
{
  Game game;
  CHECK_EQUAL(true, game.isRunning());
  CHECK_EQUAL("", game.getLastResult());
}


////////////////////////////////////////////////////////////
TEST(GroupGame, Game_test2)
{
  Game game;
  int rockCount{0};
  int paperCount{0};
  int scissorsCount{0};
  const int nbGames{100000};

  for (unsigned i = 0; i < nbGames; i++)
  {
    game.play(ROCK);

    switch(game.getIAChoice())
    {
    case ROCK:
      rockCount++;
      break;
    case PAPER:
      paperCount++;
      break;
    case SCISSORS:
      scissorsCount++;
      break;
    }
  }

  double rockPercent     = (double) rockCount / nbGames;
  double paperPercent    = (double) paperCount / nbGames;
  double scissorsPercent = (double) scissorsCount / nbGames;

  if (rockPercent < 0.3 or rockPercent > 0.35)
    FAIL("Rock n'est pas équiprobable");

  if (paperPercent < 0.3 or paperPercent > 0.35)
    FAIL("Rock n'est pas équiprobable: ");

  if (scissorsPercent < 0.3 or scissorsPercent > 0.35)
    FAIL("Rock n'est pas équiprobable: ");
}
