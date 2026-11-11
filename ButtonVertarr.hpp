//ButtonVertarr.hpp
#pragma once
#include<SFML/Graphics/VertexArray.hpp>
#include"VertexArray.hpp"
#include"BaseButton.hpp"
class ButtonVertarr : public BaseButton{
	VertexArray Va;
public:
	ButtonVertarr();
	ButtonVertarr(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f Origin, sf::VertexArray&& Va, sf::Color color = { 255,255,255 }, TypePressed type = TypePressed::OnOff);
	ButtonVertarr(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f Origin, sf::Color color, float OutLine, sf::Color colorOutLine, TypePressed type, sf::VertexArray&& Va);
	ButtonVertarr(sf::Vector2f pos, TypePressed type,  sf::VertexArray&& Va,sf::Vector2f size = { 40.f,40.f }, float OutLine = 5.f, sf::Color colorOutLine = { 70,70,70 });
	ButtonVertarr(sf::Vector2f pos, sf::VertexArray&& Va, sf::Vector2f size = { 40.f,40.f }, TypePressed type = TypePressed::OnOff, float OutLine = 5.f, sf::Color colorOutLine = { 70,70,70 });

	void setVisible(bool state) override;

	ButtonVertarr& operator=(ButtonVertarr& other);
	ButtonVertarr& operator=(ButtonVertarr&& other) noexcept;

	~ButtonVertarr() = default;
};


