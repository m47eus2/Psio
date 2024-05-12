#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class CustomRectangleShape : public sf::RectangleShape
{
	float Xspeed_ = 3.f;
	float Yspeed_ = 3.f;
	float Rspeed_ = 0.3f;

	int x_start_border_ = 0;
	int x_stop_border_ = 800;
	int y_start_border_ = 0;
	int y_stop_border_ = 600;

	bool is_selected = false;

public:
	CustomRectangleShape(sf::Vector2f size, sf::Vector2f position);

	void setSpeed(float Xspeed, float Yspeed, float Rspeed);

	void setBounds(int x_start_border, int x_stop_border, int y_start_border, int y_stop_border);

	void animate(bool up, bool down, bool right, bool left);

	void select();
	void unselect();
};

