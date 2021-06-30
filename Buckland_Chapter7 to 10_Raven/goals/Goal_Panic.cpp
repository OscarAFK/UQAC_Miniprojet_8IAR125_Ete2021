#include "Goal_Panic.h"
#include "../Raven_Bot.h"
#include "../Raven_SensoryMemory.h"
#include "../navigation/Raven_PathPlanner.h"
#include "../Raven_Game.h"
#include "../Raven_Map.h"
#include "Messaging/Telegram.h"
#include "..\Raven_Messages.h"

#include "Goal_MoveToPosition.h"


#include "debug/DebugConsole.h"

//------------------------------ Activate -------------------------------------
//-----------------------------------------------------------------------------
void Goal_Panic::Activate()
{
  m_iStatus = active;

  //if this goal is reactivated then there may be some existing subgoals that
  //must be removed
  RemoveAllSubgoals();

  if (!m_bDestinationIsSet)
  {
    //grab a random location
    m_CurrentDestination = m_pOwner->GetWorld()->GetMap()->GetRandomNodeLocationWhithinRange(m_pOwner->Pos(),20);

    m_bDestinationIsSet = true;
  }

    m_pOwner->GetPathPlanner()->RequestPathToPosition(m_CurrentDestination);
    AddSubgoal(new Goal_MoveToPosition(m_pOwner, m_CurrentDestination));
}

//------------------------------ Process -------------------------------------
//-----------------------------------------------------------------------------
int Goal_Panic::Process()
{
  //if status is inactive, call Activate()
  ActivateIfInactive();

  //process the subgoals
  m_iStatus = ProcessSubgoals();

  return m_iStatus;
}





