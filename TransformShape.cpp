//TransformShape.cpp
#include"TransformShape.hpp"

void trsh::RotationVA(sf::VertexArray& va,float angle,  sf::Vector2f center, Range range)
{
	angle *= Constants::ToRad;

	float cos = std::cosf(angle), sin = std::sinf(angle);
	for (size_t i = range.begin; i < range.end; i++) {
		auto& v = va[i].position;

		// Смещаем к центру
		float dx = v.x - center.x;
		float dy = v.y - center.y;

		// Поворачиваем
		float new_x = dx * cos - dy * sin;
		float new_y = dx * sin + dy * cos;

		// Возвращаем обратно
		v.x = center.x + new_x;
		v.y = center.y + new_y;
	}
}

void trsh::RotationVA(sf::VertexArray& va, float angle, sf::Vector2f center)
{
	Range range = { 0 , va.getVertexCount() };
	RotationVA(va , angle , center , range);
}

void trsh::SetRotationVA(sf::VertexArray& va, float currentAngle, float angle, sf::Vector2f center)
{
	float toAngle = angle - currentAngle;
	if (toAngle == 0.f) { return; }
	RotationVA(va, toAngle, center);	
}

void trsh::RotationVAInNullPos(sf::VertexArray& va , float angle) {
	angle *= Constants::ToRad;

	float cos = std::cosf(angle), sin = std::sinf(angle);
	for (size_t i = 0; i < va.getVertexCount(); i++) {
		auto& v = va[i].position;

		float new_x = v.x * cos - v.y * sin;
		float new_y = v.x * sin + v.y * cos;

		va[i].position = { new_x , new_y };
	}
}

void trsh::setScileVA(sf::Vector2f NewScale, sf::Vector2f OldScale, sf::VertexArray& va, sf::Vector2f center, float angle, Range diaposon){
	angle *= -Constants::ToRad;
	float cos = std::cosf(angle);
	float sin = std::sinf(angle);

	float relScaleX = NewScale.x / OldScale.x;
	float relScaleY = NewScale.y / OldScale.y;

	for (size_t i = diaposon.begin; i < diaposon.end; i++) {
		auto& v = va[i].position;

		// 1. Сдвиг к центру
		float dx = v.x - center.x;
		float dy = v.y - center.y;

		// 2. Поворот на -angle (выравнивание)
		float localX = dx * cos - dy * sin;
		float localY = dx * sin + dy * cos;

		// 3. Масштабирование
		localX *= relScaleX;
		localY *= relScaleY;

		// 4. Обратный поворот
		float finalX = localX * std::cosf(-angle) - localY * std::sinf(-angle);
		float finalY = localX * std::sinf(-angle) + localY * std::cosf(-angle);

		// 5. Возврат на место
		v.x = center.x + finalX;
		v.y = center.y + finalY;
	}
}

void trsh::moveVA(sf::VertexArray& va, sf::Vector2f vec){
	for (int i = 0; i < va.getVertexCount(); i++) {
		va[i].position += vec;}
}

void trsh::moveVA(sf::VertexArray& va, sf::Vector2f vec, Range range)
{
	for (int i = range.begin; i < range.end; i++) {
		va[i].position += vec;
	}
}

void trsh::Setfillcolor(sf::VertexArray& va, sf::Color color, Range range){
	for (int i = range.begin;i < range.end; i++) {
		va[i].color = color;}
}

void trsh::Setfillcolor(sf::VertexArray& va, sf::Color color){
	Range range = { 0 , va.getVertexCount() };
	Setfillcolor(va , color , range);
}

void trsh::RotationVV(float angle, std::vector<sf::Vertex>& vv, sf::Vector2f center, Range range)
{
	angle *= Constants::ToRad;

	float cos = std::cosf(angle), sin = std::sinf(angle);
	for (size_t i = range.begin; i < range.end; i++) {
		auto& v = vv[i].position;

		// Смещаем к центру
		float dx = v.x - center.x;
		float dy = v.y - center.y;

		// Поворачиваем
		float new_x = dx * cos - dy * sin;
		float new_y = dx * sin + dy * cos;

		// Возвращаем обратно
		v.x = center.x + new_x;
		v.y = center.y + new_y;
	}
}

void trsh::RotationVVInNullPos(std::vector<sf::Vertex>& vv,float angle ){
	angle *= Constants::ToRad;

	float cos = std::cosf(angle), sin = std::sinf(angle);
	for (size_t i = 0; i < vv.size(); i++) {
		auto& v = vv[i].position;

		float new_x = v.x * cos - v.y * sin;
		float new_y = v.x * sin + v.y * cos;

		vv[i].position = { new_x , new_y };
	}
}

void trsh::setScileVV(sf::Vector2f NewScale, sf::Vector2f OldScale, std::vector<sf::Vertex>& vv, sf::Vector2f center, float angle, Range diaposon){
	angle *= -Constants::ToRad;
	float cos = std::cosf(angle);
	float sin = std::sinf(angle);

	float relScaleX = NewScale.x / OldScale.x;
	float relScaleY = NewScale.y / OldScale.y;

	for (size_t i = diaposon.begin; i < diaposon.end; i++) {
		auto& v = vv[i].position;

		// 1. Сдвиг к центру
		float dx = v.x - center.x;
		float dy = v.y - center.y;

		// 2. Поворот на -angle (выравнивание)
		float localX = dx * cos - dy * sin;
		float localY = dx * sin + dy * cos;

		// 3. Масштабирование
		localX *= relScaleX;
		localY *= relScaleY;

		// 4. Обратный поворот
		float finalX = localX * std::cosf(-angle) - localY * std::sinf(-angle);
		float finalY = localX * std::sinf(-angle) + localY * std::cosf(-angle);

		// 5. Возврат на место
		v.x = center.x + finalX;
		v.y = center.y + finalY;
	}
}

void trsh::moveVV(std::vector<sf::Vertex>& vv, sf::Vector2f vec){
	for (int i = 0; i < vv.size(); i++) {
		vv[i].position += vec;
	}
}

