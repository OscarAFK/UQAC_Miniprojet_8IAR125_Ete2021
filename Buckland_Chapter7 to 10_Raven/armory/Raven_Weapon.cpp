#include "Raven_Weapon.h"

///////////////////////////////////////////////////////////////////////////////
//------------------------ ReadyForNextShot -----------------------------------
//
//  returns true if the weapon is ready to be discharged
//-----------------------------------------------------------------------------
bool Raven_Weapon::isReadyForNextShot()
{
	if (Clock->GetCurrentTime() > m_dTimeNextAvailable)
	{
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------
void Raven_Weapon::UpdateTimeWeaponIsNextAvailable()
{
	m_dTimeNextAvailable = Clock->GetCurrentTime() + 1.0 / m_dRateOfFire;
}


//-----------------------------------------------------------------------------
bool Raven_Weapon::AimAt(Vector2D target)const
{
	return m_pOwner->RotateFacingTowardPosition(target);
}

//-----------------------------------------------------------------------------
void Raven_Weapon::IncrementRounds(int num)
{
	m_iNumRoundsLeft += num;
	Clamp(m_iNumRoundsLeft, 0, m_iMaxRoundsCarried);
}


