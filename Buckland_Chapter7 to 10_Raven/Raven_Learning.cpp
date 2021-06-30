#include "Raven_Learning.h"
#include <iostream>

Raven_Learning::Raven_Learning(Raven_Game* world, Vector2D pos, int equipe, string neurNetSaveFile = "") : Raven_Bot(world, pos, equipe) {
	m_neuralNetwork = new CNeuralNet();
	if (!neurNetSaveFile.compare(""))
	{
		try
		{
			m_neuralNetwork->LoadMLPNetwork(neurNetSaveFile);
		}
		catch (const std::exception&)
		{
			std::cout << "Unable to load from file.";
		}
	}
}

bool Raven_Learning::doesShoot() {
	vector<double> inputs;
	Vector2D AimingPos = GetTargetBot()->Pos();
	if (!GetWeaponSys()->isInstantHit()) {
		AimingPos = GetWeaponSys()->PredictFuturePositionOfTarget();
	}
	inputs.push_back(RotateFacingTowardPosition(GetTargetBot()->Pos()) ? 1 : 0);
	inputs.push_back(GetTargetSys()->GetTimeTargetHasBeenVisible());
	inputs.push_back(hasLOSto(AimingPos) ? 1 : 0);
	inputs.push_back(AimingPos.x);
	inputs.push_back(AimingPos.y);
	inputs.push_back(Pos().x);
	inputs.push_back(Pos().y);
	return m_neuralNetwork->Update(inputs).at(0) > 0.5;
}