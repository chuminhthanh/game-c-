#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class CarPlayer

{
public:
	bool isDie;
	bool stable = true;
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat XX_Val = 0.0f;
	GLfloat m_DisapearTime;
	int state;
	float timer;
	//stat
	bool isPlayable;
	bool isFaceRight;
	//decletion
	CarPlayer(float x, float y);
	~CarPlayer();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateCarPlayerPos(GLfloat deltaTime);
	// sprite function
	void CarPlayerUpdate(GLfloat deltaTime);
	void CarPlayerDraw();
private:
	std::shared_ptr <SpriteAnimation> CarPlayerSprite;
};