#include "CarPlayer.h"
#include "SpriteAnimation.h"

CarPlayer::CarPlayer(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("CarPlayer.tga");
	CarPlayerSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 2, 0, 0.1f);
	CarPlayerSprite->SetSize(200, 300);
	CarPlayerSprite->Set2DPosition(posX, posY);
	isPlayable = true;

	isFaceRight = true;
}

CarPlayer::~CarPlayer()
{
}

void CarPlayer::Dead(int die)
{

	if (die == 1)
	{
		isDie = true;
		std::printf("Die");
	}
}

void CarPlayer::Move(int dir) {

	switch (dir)
	{
	case 0:
		if (isDie == false)
		{
			CarPlayerSprite->SetCurrentAction(0);
			CarPlayerSprite->Set2DPosition(posX, 820);
		}
		else if (isDie == true)
		{
			CarPlayerSprite->SetCurrentAction(2);
			CarPlayerSprite->Set2DPosition(posX, 280);
		}
		break;
	case 1:
		//move left
		CarPlayerSprite->Set2DPosition(posX, 750);
		CarPlayerSprite->SetCurrentAction(1);
		XX_Val = -5.0f;
		posX += XX_Val;
		if (posX < 100 || posX + 70 > 600)
		{
			posX -= XX_Val;
		}
		if (isFaceRight) {
			isFaceRight = false;
			CarPlayerSprite->SetRotation(Vector3(0, 0, 0));
		}
		break;
	case 4:
		//move right
		CarPlayerSprite->Set2DPosition(posX, 750);
		CarPlayerSprite->SetCurrentAction(1);
		XX_Val = 5.0f;
		posX += XX_Val;
		if (posX < 100 || posX + 70 > 600)
		{
			posX -= XX_Val;
		}
		if (!isFaceRight) {
			isFaceRight = true;
			CarPlayerSprite->SetRotation(Vector3(0, PI, 0));
		}
		break;
	default:
		break;
	}
}


void CarPlayer::UpdateCarPlayerPos(GLfloat deltaTime)
{
	CarPlayerSprite->Set2DPosition(posX, posY);

}

void CarPlayer::CarPlayerUpdate(GLfloat deltaTime)
{

	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	CarPlayerSprite->Update(deltaTime);
}
void CarPlayer::CarPlayerDraw()
{
	if (m_DisapearTime >= 0.0f)
	{
		CarPlayerSprite->Draw();
	}
}