//ColorIndicator.cpp
#include "ColorIndicator.hpp"
#include<numbers>

sf::Color lerpColor(const sf::Color& a, const sf::Color& b, float t) {
	return sf::Color(
		static_cast<sf::Uint8>(a.r + (b.r - a.r) * t),
		static_cast<sf::Uint8>(a.g + (b.g - a.g) * t),
		static_cast<sf::Uint8>(a.b + (b.b - a.b) * t),
		255
	);
}

ColorIndicator::ColorIndicator(sf::Vector2f pos) : posBegin(pos), posEnd(pos) {
	select_tone = false; select_color = false;
	to_sector = 0; 

	current_color = sf::Color::Red;
	color_ton_area.setPrimitiveType(sf::Triangles);
	color_area.setPrimitiveType(sf::TriangleStrip);
	sf::Vector2f size = { segment,15.f };

	colors[0] = { 255,0,0};
	colors[1] = { 255,255,0};
	colors[2] = { 0,255,0};
	colors[3] = { 0,255,255};
	colors[4] = { 0,0,255};
	colors[5] = { 255,0,255};
	colors[6] = { 255,0,0 };

	for (int i = 0; i < 6; i++)
	{add_color_tranglines_rect(posEnd, size, colors[i], colors[i + 1] , true);}
	length = posEnd.x - posBegin.x;

	size_color_area = { 255.f,255.f };
	pos_color_aera = posBegin + sf::Vector2f{ segment * 2.f , 40 };

	add_color__rect(pos_color_aera,size_color_area , sf::Color::Red );
	
	point_tone.setPosition(posBegin + sf::Vector2f{0 , size.y * 0.5f});

	rect_ton.setPosition(posBegin);
	rect_ton.setSize({length , size.y});
	rect_ton.setFillColor({0,0,0,0});
	rect_ton.setOutlineThickness(5.f);
	rect_ton.setOutlineColor({100,100,100});

	point_radius = 5.f;
	point_tone.setRadius(point_radius);
	point_tone.setOrigin(point_radius, point_radius);
	point_tone.setFillColor({0,0,0 ,0});

	point_tone.setOutlineThickness(6.f);
	point_tone.setOutlineColor({200,200,200 });


	final_color_rect.setSize({40.f,40.f});
	final_color_rect.setPosition(posBegin + sf::Vector2f{0.f, 50.f });

	point_color_init(pos_color_aera);
}

void ColorIndicator::point_color_init(sf::Vector2f pos){
	pos_point_color = pos;

	point_color.setPrimitiveType(sf::Triangles);
	float p_2 = float(std::numbers::pi) * 2.f;
	int facets = 4;
	float size_1 = 5.f;
	
	for (int i = 0; i < facets; i++) {
		float angle_1 = (p_2 * (i - 0.3f) / facets);
		float angle_2 = (p_2 * i / facets);
		float angle_3 = (p_2 * (i + 0.3f) / facets);

		float size_2 = 15.f;
		if (i % 2 != 0) { size_2 += 2.f; }

		sf::Vector2f pos_1 = pos + sf::Vector2f{ sinf(angle_1) , cosf(angle_1) } *size_1;
		sf::Vector2f pos_2 = pos + sf::Vector2f{ sinf(angle_2) , cosf(angle_2) } *size_2;
		sf::Vector2f pos_3 = pos + sf::Vector2f{ sinf(angle_3) , cosf(angle_3) } *size_1;

		point_color.append(sf::Vertex{ pos_1 ,  sf::Color::White});
		point_color.append(sf::Vertex{ pos_2 ,  sf::Color::White });
		point_color.append(sf::Vertex{ pos_3 ,  sf::Color::White });

	}

}

void ColorIndicator::add_color_tranglines_rect(sf::Vector2f pos, sf::Vector2f size, sf::Color color_1, sf::Color color_2, bool add_size){
	sf::Vector2f pos_1 = pos + sf::Vector2f{ 0.f, size.y};
	sf::Vector2f pos_2 = pos + sf::Vector2f{size.x , 0.f };
	sf::Vector2f pos_3 = pos + size;

	color_ton_area.append({ pos , color_1});
	color_ton_area.append({ pos_1 , color_1 });
	color_ton_area.append({ pos_2 , color_2 });


	color_ton_area.append({ pos_2 , color_2 });
	color_ton_area.append({ pos_3 , color_2 });
	color_ton_area.append({ pos_1 , color_1 });

	if (add_size) { posEnd += sf::Vector2f{ size.x , 0.f }; }
}

void ColorIndicator::add_color__rect(sf::Vector2f pos, sf::Vector2f size, sf::Color color){
	sf::Vector2f pos_1 = pos + sf::Vector2f{ size.x , 0.f };
	sf::Vector2f pos_2 = pos + sf::Vector2f{ 0.f, size.y };
	sf::Vector2f pos_3 = pos + size;

	color_area.append({ pos ,  sf::Color::White });
	color_area.append({ pos_1 ,color });
	color_area.append({ pos_2 , sf::Color::Black });
	color_area.append({ pos_3 , sf::Color::Black });

	rect_color.setPosition(pos);
	rect_color.setSize({size});
	rect_color.setOutlineThickness(7.5f);
	rect_color.setOutlineColor({90,90,90});

}

void ColorIndicator::update(sf::Vector2f mousePos, bool LKM) {
	if (!LKM) { select_color = false; select_tone = false; return; }

	if (((rect_ton.getGlobalBounds().contains(mousePos) && LKM) || select_tone) && !select_color) {
		select_tone = true;
		// Ограничиваем позицию ползунка
		float clampedX = std::clamp(mousePos.x, posBegin.x, posEnd.x);
		point_tone.setPosition(clampedX, point_tone.getPosition().y);

		// 2. Расчет цвета
		float totalLength = posEnd.x - posBegin.x;
		float currentPos = clampedX - posBegin.x;

		// Процент от 0.0 до 1.0 по всей длине
		float globalT = currentPos / totalLength;

		// Переводим в номер сегмента (0..5)
		float scaled = globalT * 6.0f;
		int segmentIndex = static_cast<int>(scaled);

		// Защита от выхода за границы (если мышь точно на конце)
		if (segmentIndex >= 6) segmentIndex = 5;

		// Процент внутри текущего сегмента (0.0..1.0)
		float localT = scaled - segmentIndex;

		// Получаем два соседних цвета
		sf::Color c1 = colors[segmentIndex];
		sf::Color c2 = colors[segmentIndex + 1];

		// Смешиваем их
		current_color = lerpColor(c1, c2, localT);
	
	}

	color_area[color_area.getVertexCount() - 3].color = current_color;

	if (((point_color.getBounds().contains(mousePos) && LKM) || select_color)&& !select_tone) {
		select_color = true;
		sf::Vector2f to_mouse;

		to_mouse.x = std::clamp(mousePos.x , pos_color_aera.x , pos_color_aera.x + size_color_area.x) - pos_point_color.x;
		to_mouse.y = std::clamp(mousePos.y, pos_color_aera.y, pos_color_aera.y + size_color_area.y) - pos_point_color.y;

		pos_point_color += to_mouse;

		for (int i = 0; i < point_color.getVertexCount(); i++) {
			point_color[i].position += to_mouse;
		}
	
	}


		sf::Vector2f current_pos = pos_point_color - (pos_color_aera);

		float globalTx = 1.f - (current_pos.x / size_color_area.x);
		float globalTy = (current_pos.y / size_color_area.x);

		sf::Color intermediate;

		intermediate = lerpColor(current_color ,sf::Color::White,globalTx );
		final_color = lerpColor(intermediate, sf::Color::Black, globalTy);

		final_color_rect.setFillColor(final_color);


}

void ColorIndicator::draw(sf::RenderWindow& window) {
	window.draw(final_color_rect);

	window.draw(rect_color);

	window.draw(color_ton_area);
	window.draw(color_area);
	
	window.draw(rect_ton);
	window.draw(point_tone);
	window.draw(point_color);
}