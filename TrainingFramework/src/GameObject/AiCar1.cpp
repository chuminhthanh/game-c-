#include "AiCar1.h"
#include "SpriteAnimation.h"

AiCar1::AiCar1(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiCar1.tga");
	AiCar1Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 1, 0, 0.1f);
	AiCar1Sprite->SetSize(200, 500);
	AiCar1Sprite->Set2DPosition(posX, posY);
	isPlayable = true;

	isFaceRight = true;
}

AiCar1::~AiCar1()
{
}

void AiCar1::Dead(int die)
{

	if (die == 1)
	{
		isDie = true;
		std::printf("Die");
	}
}

void AiCar1::Move(int dir) {

	switch (dir)
	{
	case 1:
		//move tren xuong

		XX_Val = 1.5f;
		posY += XX_Val;
		if (posY > 900 )
		{
			posY = 0;
		}
		break;
	default:
		break;
	}
}


void AiCar1::UpdateAiCar1Pos(GLfloat deltaTime)
{
	AiCar1Sprite->Set2DPosition(posX, posY);

}

void AiCar1::AiCar1Update(GLfloat deltaTime)
{

	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiCar1Sprite->Update(deltaTime);
}
void AiCar1::AiCar1Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiCar1Sprite->Draw();
	}
}