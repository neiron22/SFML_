//Model.cpp
#include "Model.hpp"

#include"TransformShape.hpp"

//#include"Button.hpp"


ShapeInfo::ShapeInfo(Range range, float radius, sf::Vector2f pos, float angle = 0)noexcept :
	range(range), radius(radius), pos(pos), angle(angle),

	color_1(0, 0, 0, sf::Color::White), color_2(0, 0, 0, sf::Color::White), color_3(0, 0, 0, sf::Color::White),

	scale({ 1.f , 1.f })

{}

ColorShape::ColorShape(float tone, float hsv_V, float hsv_S, sf::Color rgb):
tone(tone) , hsv_VS(hsv_V , hsv_S) , rgb(rgb){}

ColorShape::ColorShape(float tone, sf::Vector2f hsv_VS, sf::Color rgb):
tone(tone), hsv_VS(hsv_VS), rgb(rgb){}

ColorShape::ColorShape():
tone(0.f), hsv_VS({0.f,0.f}), rgb(sf::Color::White) {}

void ModelEditor::AddShape(sf::Vector2f pos, float radius, size_t facets, float angle) {
	angle *= to_radian;

	size_t startVertex = data.vertices.size();

	// Центральный треугольник для каждой грани
	for (size_t i = 0; i < facets; i++) {
		float a1 = angle + (std::numbers::pi * 2 * i / facets);
		float a2 = angle + (std::numbers::pi * 2 * (i + 1) / facets);

		sf::Vector2f p1 = pos + sf::Vector2f{ std::sin(a1), std::cos(a1) } * radius;
		sf::Vector2f p2 = pos + sf::Vector2f{ std::sin(a2), std::cos(a2) } * radius;

		data.vertices.push_back(pos);
		data.vertices.push_back(p1);
		data.vertices.push_back(p2);
	}

	data.shapes.emplace_back(ShapeInfo
		{
		{startVertex,startVertex + facets * 3},
		radius,pos,angle
		});

}

void ModelEditor::DeleteShape(size_t index){
	if(changed.check(index , size())) return;

	auto& ShapeToDel = data.shapes[index];

	Range range = ShapeToDel.range;
	size_t delta = range.end - range.begin;

	data.shapes.erase(data.shapes.begin() + index);

	for (size_t i = index; i < data.shapes.size(); ++i) {
		data.shapes[i].range -= delta;
	}

	data.vertices.erase(data.vertices.begin() + range.begin , data.vertices.begin() + range.end);
}

void ModelEditor::MoveShape(size_t index, sf::Vector2f delta)
{
	if (index >= size()) { return; }
	Range range = data.shapes[index].range;

	for (size_t i = range.begin; i < range.end; i++) {
		data.vertices[i].position += delta;
	}

}

void ModelEditor::RotateShape(size_t index, float angle){
	/*if (changed.check(index, size())) return;

	ShapeInfo& shape = data.shapes[index];
	Range range = shape.range;

	float rad = angle * to_radian;
	float cos_a = std::cos(rad);
	float sin_a = std::sin(rad);	
	
	sf::Vector2f center = shape.pos;

	trsh::RotationVV(angle , data.vertices , shape.pos , shape.range);

	shape.angle += angle;*/
}

void ModelEditor::SetRotationShape(size_t index, float angle)
{
	if (changed.check(index, size())) return;

	float current_angle = data.shapes[index].angle;
	
	RotateShape(index , angle - current_angle);
}

void ModelEditor::SetColorShape(size_t index, ColorShape color)
{
	if (changed.check(index, size())) return;

	data.shapes[index].color_1 = color;
	data.shapes[index].color_2 = color;
	data.shapes[index].color_3 = color;
}

void ModelEditor::ScaleShape(size_t index, sf::Vector2f NewScale){
	if (changed.check(index, size())) return;

	auto& shape = data.shapes[index];
	
	sf::Vector2f center = shape.pos;
	float rad = -shape.angle * to_radian; // Минус, чтобы выровнять фигуру
	float cos_a = std::cos(rad);
	float sin_a = std::sin(rad);

	// Относительный масштаб (насколько нужно изменить текущий)
	float relScaleX = NewScale.x / shape.scale.x;
	float relScaleY = NewScale.y / shape.scale.y;

	for (size_t i = shape.range.begin; i < shape.range.end; i++) {
		auto& v = data.vertices[i].position;

		// 1. Сдвиг к центру
		float dx = v.x - center.x;
		float dy = v.y - center.y;

		// 2. Поворот на -angle (выравнивание)
		float localX = dx * cos_a - dy * sin_a;
		float localY = dx * sin_a + dy * cos_a;

		// 3. Масштабирование
		localX *= relScaleX;
		localY *= relScaleY;

		// 4. Обратный поворот
		float finalX = localX * std::cos(-rad) - localY * std::sin(-rad);
		float finalY = localX * std::sin(-rad) + localY * std::cos(-rad);

		// 5. Возврат на место
		v.x = center.x + finalX;
		v.y = center.y + finalY;
	}

	// Обновляем сохраненные значения
	shape.scale.x = NewScale.x;
	shape.scale.y = NewScale.y;

	// Радиус тоже нужно обновить, если он используется для кликов
	shape.radius *= std::max(relScaleX, relScaleY);
}

ShapeInfo* ModelEditor::getShape(size_t index)
{
	if (index >= size()) { return nullptr; }
	return &data.shapes[index];
}

Model::Model(): editor(data){}

void Model::update(sf::Vector2f mouse_pos){
	editor.changed.reset();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) { render.buildForm(editor.getData()); }
}

void ModelRender::buildForm(const ModelData& data){
	size_t count = data.vertices.size();
	va.resize(count);
	for (size_t i = 0; i < count;i++) { va[i] = data.vertices[i]; }

}

void ModelRender::draw(sf::RenderWindow& window){window.draw(va);}
