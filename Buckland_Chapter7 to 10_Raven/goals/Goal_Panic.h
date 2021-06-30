#ifndef GOAL_PANIC_H
#define GOAL_PANIC_H
#pragma warning (disable:4786)

#include "Goals/Goal_Composite.h"
#include "Raven_Goal_Types.h"


class Raven_Bot;


class Goal_Panic : public Goal_Composite<Raven_Bot>
{
private:

    Vector2D  m_CurrentDestination;

    //set to true when the destination for the exploration has been established
    bool      m_bDestinationIsSet;

    std::list<Raven_Bot*> m_SensedBots;

public:

    Goal_Panic(Raven_Bot* pOwner) :Goal_Composite<Raven_Bot>(pOwner,
        goal_panic),
        m_bDestinationIsSet(false)
    {}


    void Activate();

    int Process();

    void Terminate() {}
};





#endif
