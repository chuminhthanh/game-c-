#include "AiCar2.h"
#include "SpriteAnimation.h"

AiCar2::AiCar2(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiCar2.tga");
	AiCar2Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 1, 0, 0.1f);
	AiCar2Sprite->SetSize(200, 500);
	AiCar2Sprite->Set2DPosition(posX, posY);
	isPlayable = true;

	isFaceRight = true;
}

AiCar2::~AiCar2()
{
}

void AiCar2::Dead(int die)
{

	if (die == 1)
	{
		isDie = true;
		std::printf("Die");
	}
}

void AiCar2::Move(int dir) {

	switch (dir)
	{
	case 1:
		//move tren xuong
		XX_Val = 0.5f;
		posY += XX_Val;
		if (posY > 900)
		{
			posY = 0;
		}
		break;
	default:
		break;
	}
}


void AiCar2::UpdateAiCar2Pos(GLfloat deltaTime)
{
	AiCar2Sprite->Set2DPosition(posX, posY);

}

void AiCar2::AiCar2Update(GLfloat deltaTime)
{

	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiCar2Sprite->Update(deltaTime);
}
void AiCar2::AiCar2Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiCar2Sprite->Draw();
	}
}