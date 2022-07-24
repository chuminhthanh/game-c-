#pragma once
#include "GameStateBase.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class SpriteAnimation;
class CarPlayer;
class AiCar1;
class AiCar2;
class VachKeDuong;
class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;
	int m_KeyPress;

private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Text>		m_score;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
	std::shared_ptr<CarPlayer> pointerCarPlayer;
	std::list<std::shared_ptr<CarPlayer>>	m_listCarPlayerAnimation;
	std::shared_ptr<VachKeDuong> pointerVachKeDuong;
	std::list<std::shared_ptr<VachKeDuong>>	m_listVachKeDuongAnimation;
	//AiPlay
	std::list<std::shared_ptr<AiCar1>>	m_listAiCar1Animation;
	std::shared_ptr<AiCar1> pointerAiCar1;
		//2	
		std::list<std::shared_ptr<AiCar2>>	m_listAiCar2Animation;
		std::shared_ptr<AiCar2> pointerAiCar2;

};

