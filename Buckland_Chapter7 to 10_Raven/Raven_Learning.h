#pragma once
#include "Raven_Bot.h"
#include "..\Buckland_Chapter7 to 10_Raven\MLP\CNeuralNet.h"

class Raven_Learning : public Raven_Bot
{
public:
	Raven_Learning(Raven_Game* world, Vector2D pos, int equipe, string neurNetSaveFile);
	bool doesShoot();
private:
	CNeuralNet* m_neuralNetwork;

};

