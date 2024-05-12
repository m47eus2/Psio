#include "CustomRectangleShape.h"

CustomRectangleShape::CustomRectangleShape(sf::Vector2f size, sf::Vector2f position) : sf::RectangleShape(size)
{
	setPosition(position);
}

void CustomRectangleShape::setSpeed(float Xspeed, float Yspeed, float Rspeed)
{
	Xspeed_ = Xspeed;
	Yspeed_ = Yspeed;
	Rspeed_ = Rspeed;
}

void CustomRectangleShape::setBounds(int x_start, int x_stop, int y_start, int y_stop)
{
	x_start_border_ = x_start;
	x_stop_border_ = x_stop;
	y_start_border_ = y_start;
	y_stop_border_ = y_stop;
}

void CustomRectangleShape::animate(bool up, bool down, bool right, bool left)
{
	sf::FloatRect bounds_rect = getGlobalBounds();
	if (is_selected == false)
	{	
		if (bounds_rect.getPosition().y <= y_start_border_) Yspeed_ = fabs(Yspeed_);
		if (bounds_rect.getPosition().y + bounds_rect.getSize().y >= y_stop_border_) Yspeed_ = fabs(Yspeed_) * -1;
		if (bounds_rect.getPosition().x <= x_start_border_) Xspeed_ = fabs(Xspeed_);
		if (bounds_rect.getPosition().x + bounds_rect.getSize().x >= x_stop_border_) Xspeed_ = fabs(Xspeed_) * -1;

		move(Xspeed_, Yspeed_);
		rotate(Rspeed_);
	}
	else
	{
		if (up && bounds_rect.getPosition().y >= y_start_border_) move(0.0, fabs(Yspeed_) * -1);
		if (down && bounds_rect.getPosition().y + bounds_rect.getSize().y <= y_stop_border_) move(0.0, fabs(Yspeed_));
		if (right && bounds_rect.getPosition().x + bounds_rect.getSize().x <= x_stop_border_) move(fabs(Xspeed_), 0.0);
		if (left && bounds_rect.getPosition().x >= x_start_border_) move(fabs(Xspeed_) * -1, 0.0);
	}
}

void CustomRectangleShape::select()
{
	is_selected = 1;
	setFillColor(sf::Color(rand() % 254, rand() % 254, rand() % 254));
}

void CustomRectangleShape::unselect()
{
	is_selected = 0;
	setFillColor(sf::Color::White);
}