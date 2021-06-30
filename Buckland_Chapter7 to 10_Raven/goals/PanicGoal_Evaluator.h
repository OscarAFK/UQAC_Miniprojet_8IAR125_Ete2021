#ifndef RAVEN_PANIC_GOAL_EVALUATOR
#define RAVEN_PANIC_GOAL_EVALUATOR
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   PanicGoal_Evaluator.h
//
//  Author: Oscar Trosseau
//
//  Desc:  class to calculate how desirable the goal of panicking is
//-----------------------------------------------------------------------------

#include "Goal_Evaluator.h"
#include "../Raven_Bot.h"


class PanicGoal_Evaluator : public Goal_Evaluator
{ 
public:

	PanicGoal_Evaluator(double bias):Goal_Evaluator(bias){}
  
  double CalculateDesirability(Raven_Bot* pBot);

  void  SetGoal(Raven_Bot* pEnt);

  void RenderInfo(Vector2D Position, Raven_Bot* pBot);
};



#endif