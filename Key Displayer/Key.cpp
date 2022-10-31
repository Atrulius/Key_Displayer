#include "Key.h"
#include "Rect.h"

void Key::Load(int Index, sf::RenderWindow*& window) {

	RectOutline.setSize(sf::Vector2f(iSize - 10, iSize - 10));
	RectOutline.setPosition((Index + 1) * iSize + 5, window->getSize().y - iSize + 5);
	RectOutline.setFillColor(RectOutlineColor);

	RectBase.setSize(sf::Vector2f(iSize - 20, iSize - 20));
	RectBase.setPosition((Index + 1) * iSize + 10, window->getSize().y - iSize + 10);
	RectBase.setFillColor(RectBaseColor);

	Line.setPosition((Index + 1) * iSize + 10, 0);
	Line.setSize(sf::Vector2f(iSize - 20, 0));
	Line.setFillColor(LineColor);

	Font.loadFromFile("StokkenesIT.ttf");

	Character.setString(Index == 0 ? "d" : 
						Index == 1 ? "f" :
						Index == 2 ? "j" :
									 "k");

	Character.setCharacterSize(16);
	Character.setScale(float(iSize) / 16, float(iSize) / 16);
	const_cast<sf::Texture&>(Font.getTexture(Character.getCharacterSize())).setSmooth(false);
	Character.setFont(Font);
	Character.setOrigin(1.f / 2 * float(Character.getLocalBounds().width) + 1, float(Character.getLocalBounds().height) / 2);
	Character.setFillColor(TextColor);
	Character.setPosition((Index + 1) * iSize + float(iSize) / 2, window->getSize().y - iSize);

	Particles.Initialize((Index + 1) * iSize + float(iSize) / 2, window->getSize().y - iSize, 0, -iSize * 2, 10, iSize * 2, 1, ParticleColor);

}

void Key::Update(bool Active) {

	if (Active) Particles.Add_Particles(0.5);

	Particles.Update();

	for (int i = 0; i < Total - 1; i++) bActive[Total - 1 - i] = bActive[Total - 1 - i - 1];

	bActive[0] = Active;

	RectOutline.setFillColor(Active ? RectOutlineHoldingColor : RectOutlineColor);
	RectBase.setFillColor(Active ? RectBaseHoldingColor : RectBaseColor);
	Character.setFillColor(Active ? TextHoldingColor : TextColor);

}

void Key::Draw(sf::RenderWindow*& window) {

	bool b = false;
	int Index = 0;

	for (int i = Total - 1; i >= 0; i--) {

		if (b) {

			if (!bActive[i]) {

				Line.setSize(sf::Vector2f(Line.getSize().x, float(window->getSize().y - iSize) / Total * Index + (Line.getPosition().y < 0) * float(iSize) / 2));

				sf::RectangleShape TEMP = Line;

				TEMP.setFillColor(LineOutlineColor);

				Rect::Rounded(TEMP, 15, window);
				Rect::Rounded(Rect::Get::Base_From_Outline(Line, 5), 10, window);

				b = false;

			}

		}
		else if (bActive[i]) {

			Line.setPosition(Line.getPosition().x, window->getSize().y - iSize - (i + 1) * float(window->getSize().y - iSize) / Total - float(iSize) / 2 * (i == Total - 1));

			Index = 0;

			b = true;

		}

		Index++;

	}

	if (b) {

		Line.setSize(sf::Vector2f(Line.getSize().x, float(window->getSize().y - iSize) / Total * Index + float(iSize) / 2 + (Index == Total) * float(iSize) / 2));

		sf::RectangleShape TEMP = Line;

		TEMP.setFillColor(LineOutlineColor);

		Rect::Rounded(TEMP, 15, window);
		Rect::Rounded(Rect::Get::Base_From_Outline(Line, 5), 10, window);

	}



	Particles.Draw(window);

	Rect::Rounded(RectOutline, 25, window);
	Rect::Rounded(RectBase, 20, window);

	window->draw(Character);

}