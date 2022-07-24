#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class AiCar1

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
	AiCar1(float x, float y);
	~AiCar1();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateAiCar1Pos(GLfloat deltaTime);
	// sprite function
	void AiCar1Update(GLfloat deltaTime);
	void AiCar1Draw();
private:
	std::shared_ptr <SpriteAnimation> AiCar1Sprite;
};