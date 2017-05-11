////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Game.hpp"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

////////////////////////////////////////////////////////////
Game::Game() : m_running(true)
{
}


////////////////////////////////////////////////////////////
void Game::getPlayerInput()
{
  string input;

  // While isn't correct 
  do {
    // Get input from player
    cout << "move (rock, paper, scissors, quit): ";
    cin >> input;
    
    // Convert to lower case
    transform(input.begin(), input.end(), input.begin(), ::tolower);
  } while (input != "rock" and input != "paper" and input != "scissors"
	   and input != "quit");

  // Actions
  if (input == "rock")
    m_playerChoice = ROCK;
  else if (input == "paper")
    m_playerChoice = PAPER;
  else if (input == "scissors")
    m_playerChoice = SCISSORS;
  else
    m_running = false;
}


////////////////////////////////////////////////////////////
void Game::displayResult()
{
  m_IAChoice = (Choice) m_random(3);
  int result = 0; // 0 (Draw) -1 (Loose) 1 (Won)
  
  switch(m_playerChoice)
  {
  case ROCK:
    if (m_IAChoice == ROCK) result = 0;
    if (m_IAChoice == PAPER) result = -1;
    if (m_IAChoice == SCISSORS) result = 1;
    break;
  case PAPER:
    if (m_IAChoice == ROCK) result = 1;
    if (m_IAChoice == PAPER) result = 0;
    if (m_IAChoice == SCISSORS) result = -1;
    break;
  case SCISSORS:
    if (m_IAChoice == ROCK) result = -1;
    if (m_IAChoice == PAPER) result = 1;
    if (m_IAChoice == SCISSORS) result = 0;
    break;
  }

  string playerChoice = priv_convertChoice(m_playerChoice);
  string IAChoice = priv_convertChoice(m_IAChoice);
  
  if (result == 0)
    m_lastResult = "draw (" + playerChoice + "-" + IAChoice + ")";
  else if (result == -1)
    m_lastResult = "lost (" + playerChoice + "-" + IAChoice + ")";
  else
      m_lastResult = "won (" + playerChoice + "-" + IAChoice + ")";

  cout << m_lastResult << endl;
}


////////////////////////////////////////////////////////////
const std::string Game::priv_convertChoice(Choice c) const
{
  switch(c)
  {
  case ROCK:
    return "rock";
  case PAPER:
    return "paper";
  case SCISSORS:
    return "scissors";
  }

  return "";
}


////////////////////////////////////////////////////////////
const std::string Game::getLastResult() const
{
  return m_lastResult;
}


////////////////////////////////////////////////////////////
bool Game::isRunning() const
{
  return m_running;
}
