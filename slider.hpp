	//Color_indikator.hpp
	#pragma once
	#include<SFML/Graphics.hpp>

	inline sf::RectangleShape get_smal_rect() {
	float size = 16.f , out_size = 4.f,
	realsize = size+out_size;
	sf::RectangleShape rect;
	rect.setSize({ size ,size });
	rect.setOrigin({ realsize *0.5f,realsize *0.5f});
	rect.setOutlineThickness(out_size);
	rect.setFillColor({100,100,100});
	rect.setOutlineColor({50,50,50});
	return rect;}

	inline sf::RectangleShape get_big_rect(float size = 255.f) {
		float width = 17.f,
		out_size = 3.f;
		sf::RectangleShape rect;
		rect.setSize({ size ,width });
		rect.setOutlineThickness(out_size);
		rect.setOrigin({ 0.f ,0.f });
		rect.setFillColor({ 150,150,150 });
		rect.setOutlineColor({ 60,60,60 });
		return rect;
	}

	struct Color_Scale {
		sf::RectangleShape R,r,G,g,B,b;
		Color_Scale(sf::Vector2f vec) {
		r = get_smal_rect();
		g = get_smal_rect();
		b = get_smal_rect();
		R = get_big_rect();
		G = get_big_rect();
		B = get_big_rect();
		float distance = 35.f;
		R.setPosition(vec);
		r.setPosition(vec.x, vec.y + (r.getSize().y + r.getOutlineThickness()) * 0.5f);
		vec.y += distance;
		G.setPosition(vec);
		g.setPosition(vec.x, vec.y + (g.getSize().y + g.getOutlineThickness()) * 0.5f);
		vec.y += distance;
		B.setPosition(vec);
		b.setPosition(vec.x, vec.y + (b.getSize().y + b.getOutlineThickness()) * 0.5f);
		}

	};

	class Color_indikator{
		Color_Scale colorscale;
		sf::RectangleShape color_rect;
		sf::RectangleShape* zahvat_rect;
			float point;
			int pointer_shape;

			sf::Color color;
	public:
		Color_indikator(sf::Vector2f vec);
		
		void update(sf::Vector2f mouse_pos , bool LKM , int poiner_shape , sf::Color color_shape);

		void draw(sf::RenderWindow & window);

		bool is_zahvat() { return zahvat_rect != nullptr; }

		sf::Color getColor() { return color; }
	
	};

	class One_slider {
		sf::RectangleShape rect, RECT;
		sf::RectangleShape* zahvat_rect;
		float point_begin , point_end;
		int pointer_shape;
	public:
		One_slider(sf::Vector2f pos);

		void update(sf::Vector2f mouse_pos,  bool mouse_click , int pointer_shape , float angle_shape);

		void draw(sf::RenderWindow & window);

		bool is_zahvat() { return zahvat_rect != nullptr; }

		float getSilverLevel();
	};
