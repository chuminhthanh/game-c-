#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "SpriteAnimation.h"
#include "CarPlayer.h"
#include "AiCar1.h"
#include "AiCar2.h"
#include "VachKeDuong.h"



GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([this]() {
			GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TextColor::RED, 1.0);

	m_score->Set2DPosition(Vector2(5, 25));
	//car player
	std::shared_ptr<CarPlayer> Obj = std::make_shared<CarPlayer>(240, 620);
	pointerCarPlayer = Obj;
	m_listCarPlayerAnimation.push_back(Obj);
	
	m_KeyPress = 0;

	std::shared_ptr<VachKeDuong> vachKeDuong = std::make_shared<VachKeDuong>(200, 0);
	pointerVachKeDuong = vachKeDuong;
	m_listVachKeDuongAnimation.push_back(vachKeDuong);

	// AiCar1
	std::shared_ptr<AiCar1> aiCar1 = std::make_shared<AiCar1>(240, 0);
	pointerAiCar1 = aiCar1;
	m_listAiCar1Animation.push_back(aiCar1);
	// AiCar2
	std::shared_ptr<AiCar2> aiCar2 = std::make_shared<AiCar2>(400, 0);
	pointerAiCar2 = aiCar2;
	m_listAiCar2Animation.push_back(aiCar2);
}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed)
	{
		switch (key)
		{
		case KEY_MOVE_LEFT:
			m_KeyPress |= 1;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress |= 1<<1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress |= 1<<2;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress |= 1<<3;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case KEY_MOVE_LEFT:
			m_KeyPress ^= 1;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress ^= 1 << 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress ^= 1 << 2;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress ^= 1 << 3;
			break;
		default:
			break;
		}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

void GSPlay::Update(float deltaTime)
{
	switch (m_KeyPress)//Handle Key event
	{
	default:
		break;
	}

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}

	for (auto it : m_listCarPlayerAnimation)
	{
		it->UpdateCarPlayerPos(deltaTime);
	}
	for (auto it : m_listVachKeDuongAnimation)
	{
		it->UpdateVachKeDuongPos(deltaTime);
	}
	// AiCar1
	for (auto it : m_listAiCar1Animation)
	{
		it->UpdateAiCar1Pos(deltaTime);
	}
	//2
	for (auto it : m_listAiCar2Animation)
	{
		it->UpdateAiCar2Pos(deltaTime);
	}
	pointerVachKeDuong->Move(1);
	pointerAiCar1->Move(1);
	pointerAiCar2->Move(1);
	if (m_KeyPress == 0)
	{
		pointerCarPlayer->Move(0);
	}
	else if (m_KeyPress == 1)
	{
		pointerCarPlayer->Move(1);
	}
	else if (m_KeyPress == 4)
	{
		pointerCarPlayer->Move(4);
	}
	else if (m_KeyPress ^= 1)
	{
		pointerCarPlayer->Move(1);
	}
	else if (m_KeyPress ^= 1 << 2)
	{
		pointerCarPlayer->Move(4);
	}

	for (auto it : m_listCarPlayerAnimation)
	{
		it->CarPlayerUpdate(deltaTime);
	}
	for (auto it : m_listAiCar1Animation)
	{
		it->AiCar1Update(deltaTime);
	}
	for (auto it : m_listAiCar2Animation)
	{
		it->AiCar2Update(deltaTime);
	}
	for (auto it : m_listVachKeDuongAnimation)
	{
			it->VachKeDuongUpdate(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_score->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	for (auto& it : m_listVachKeDuongAnimation)
	{
		it->VachKeDuongDraw();
	}
	for (auto it : m_listAnimation)
	{
		it->Draw();
	}
	for (auto& it : m_listCarPlayerAnimation)
	{
		it->CarPlayerDraw();
	}
	for (auto& it : m_listAiCar1Animation)
	{
		it->AiCar1Draw();
	}
	for (auto& it : m_listAiCar2Animation)
	{
		it->AiCar2Draw();
	}
}
