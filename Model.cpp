//Model.cpp
#include "Model.hpp"

#include"Button.hpp"
color_in_shape::color_in_shape(float tone, float hsv_V, float hsv_S, sf::Color rgb):
tone(tone) , hsv_VS(hsv_V , hsv_S) , rgb(rgb){}

color_in_shape::color_in_shape(float tone, sf::Vector2f hsv_VS, sf::Color rgb):
tone(tone), hsv_VS(hsv_VS), rgb(rgb){}

color_in_shape::color_in_shape():
tone(0.f), hsv_VS({0.f,0.f}), rgb(sf::Color::White) {}

Model::Model() noexcept
{
Vertarr.setPrimitiveType(sf::Triangles); count_vertex = 0;
mouse_delta_pos = { 0.f,0.f }; selecter_shape = false;
}

void Model::draw(sf::RenderWindow & window) {
	window.draw(Vertarr);
}

void Model::AddShape(sf::Vector2f point, float size_shape, size_t facets, float angle) {
	//if (size_shape == 0.f) { model.append(sf::Vertex{ point }); return; }
	angle *= to_radian;
	for (int i = 0; i < facets; i++) {
		float angle_1 = angle + (p_2 * i / facets);
		float angle_2 = angle + (p_2 * (i + 1) / facets); 

		sf::Vector2f pos_1 = point + sf::Vector2f{ sinf(angle_1) , cosf(angle_1) } *size_shape;
		sf::Vector2f pos_2 = point + sf::Vector2f{ sinf(angle_2) , cosf(angle_2) } *size_shape;

		Vertarr.append(sf::Vertex{ point });
		Vertarr.append(sf::Vertex{ pos_1 });
		Vertarr.append(sf::Vertex{ pos_2 });

	}
	facets *= 3;
	shapes.push_back({ count_vertex , count_vertex + facets ,size_shape,  point , angle });

	count_vertex += facets;
}

void Model::DeleteShape(size_t index){
	if (count_vertex == 0) { return; }

	size_t begin = shapes[index].begin;
	size_t end = shapes[index].end;
	int delta = int(end - begin);

	if (end == count_vertex) { // этот случай выполняется ТОЛЬКО если элемет послeдний
		Vertarr.resize(count_vertex - delta);
		shapes.pop_back();
		count_vertex -= delta;
		return;
	}

	for (int i = int(end) , it = int(begin); i < count_vertex; i++ , it ++) {
		Vertarr[it] = Vertarr[i];
	}
	Vertarr.resize(count_vertex - delta);
	count_vertex -= delta;
	
	shapes.erase(shapes.begin() + index);

	for (size_t i = index; i < shapes.size(); i++) {
		shapes[i].begin -= delta;
		shapes[i].end -= delta;
	}

	return;
}
void Model::Delete_shape() {
	if (count_vertex == 0) { return; }

	size_t begin = shapes.back().begin;
	size_t end = shapes.back().end;
	int delta = int(end - begin);


	Vertarr.resize(count_vertex - delta);
	shapes.pop_back();
	count_vertex -= delta;
	return;
	}


void Model::move_1_shape(Shape_in_VertexArray& zahvat_shape, sf::Vector2f vec) {
	for (size_t i = zahvat_shape.begin; i < zahvat_shape.end; i++) {
		Vertarr[i].position += vec;
	}
	zahvat_shape.pos += vec;
}

void Model::setSelectedAngle(size_t index, float angle){
	if (index >= shapes.size()) return;

		auto& shape = shapes[index];
		sf::Vector2f center = shape.pos;

		sf::Transform transform;
		transform.translate(center);
		transform.rotate(angle - shape.angle);
		transform.translate(-center);

		shape.angle = angle;

		for (size_t i = shape.begin; i < shape.end; i++) {
			Vertarr[i].position = transform.transformPoint(Vertarr[i].position);
		}
}

void Model::set_shape_color(size_t index, color_in_shape color,
	bool color_1, bool color_2, bool color_3){


	if (index >= shapes.size()) { return; }
	size_t start = shapes[index].begin;
	size_t end = shapes[index].end;

	sf::Color color_rgb = color.rgb;
	for (rsize_t it = start; it < end; it+=3) {
		if (color_1)Vertarr[it].color = color_rgb;
		if(color_2)Vertarr[it+1].color = color_rgb;
		if(color_3)Vertarr[it+2].color = color_rgb;
	}
	
	shapes[index].color_1 = color;
}

void Model::size_shape_multipler(size_t index, float factor) {
	if (index >= shapes.size()) { return; }

	auto& shape = shapes[index];
	sf::Vector2f center = shape.pos;

	for (size_t i = shape.begin; i < shape.end; i++) {
		sf::Vector2f& vertex_pos = Vertarr[i].position;

		vertex_pos = center + ((vertex_pos - center) * factor);
	}

	shape.radius *= factor;
}

bool Model::CursorToShape(sf::Vector2f point, size_t index) {

	sf::Vector2f center = Vertarr[shapes[index].begin].position;
	float radius = shapes[index].radius;

	sf::Vector2f dlt_vec = point - center;
	float delta = (dlt_vec.x * dlt_vec.x) + (dlt_vec.y * dlt_vec.y);
	if (delta < radius * radius) { return true; }
	return false;
}

void Model::update(sf::Vector2f mouse_pos, bool lkm, size_t indexSelectShape)
{
	if (indexSelectShape >= shapes.size()) { return; }

	Shape_in_VertexArray& shape = shapes[indexSelectShape];
	
	if (!selecter_shape) { mouse_delta_pos = mouse_pos - (Vertarr[shape.begin].position); }

	if (CursorToShape(mouse_pos , indexSelectShape) && lkm || selecter_shape) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
			mouse_pos = sf::Vector2f{
				float(int(mouse_pos.x) - int(mouse_pos.x)%10)
				, 
				float(int(mouse_pos.y) - int(mouse_pos.y) % 10) };
			mouse_delta_pos = {0.f,0.f};
		}

		move_1_shape(shape, mouse_pos - (Vertarr[shape.begin].position + mouse_delta_pos));
		selecter_shape = true;}

	if (!lkm) { selecter_shape = false; }
}

float Model::get_shape_angle(size_t index){
	return shapes[index].angle;
}

const color_in_shape& Model::get_shape_color(size_t index)
{
	return shapes[index].color_1;
}


void Model::set_point_color(size_t index_point, sf::Color color){
	Vertarr[index_point].color = color;
}


