#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class AiCar2

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
	AiCar2(float x, float y);
	~AiCar2();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateAiCar2Pos(GLfloat deltaTime);
	// sprite function
	void AiCar2Update(GLfloat deltaTime);
	void AiCar2Draw();
private:
	std::shared_ptr <SpriteAnimation> AiCar2Sprite;
};