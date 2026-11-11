//ReadyShape.hpp
#include"ReadyShape.hpp"

void sh::VAaddVA(sf::VertexArray& baseVA, sf::VertexArray& addVA){
for (rsize_t i = 0;i < addVA.getVertexCount();i++) { baseVA.append(addVA[i]); }}

void sh::VAaddVA(sf::VertexArray& baseVA, sf::VertexArray addVA){
for (rsize_t i = 0;i < addVA.getVertexCount();i++) {baseVA.append(addVA[i]);}}

sf::VertexArray sh::Rect(float angle, sf::Vector2f size, sf::Color color){
		sf::VertexArray vertarr(sf::Triangles);

		sf::Vector2f pos_1 = sf::Vector2f(-size.x, -size.y);
		sf::Vector2f pos_2 = sf::Vector2f(-size.x, size.y);
		sf::Vector2f pos_3 = sf::Vector2f(size.x, -size.y);
		sf::Vector2f pos_4 = sf::Vector2f(size.x, size.y);

		vertarr.append({ pos_1 , color });vertarr.append({ pos_2, color });vertarr.append({ pos_3, color });
		vertarr.append({ pos_3, color });vertarr.append({ pos_4 , color });vertarr.append({ pos_2, color });

		trsh::RotationVAInNullPos(vertarr, angle);

		return vertarr;

}

void sh::Rect(sf::VertexArray& Va, float angle, sf::Vector2f size, sf::Color color)
{VAaddVA(Va, Rect(angle, size, color));}

sf::VertexArray sh::Cross(float angle, float radius, sf::Color color)
{	angle *= Constants::ToRad;
	sf::VertexArray vertarr(sf::Triangles);

	for (int i = 0; i < 2; i++) {
		if ((i + 1) % 2 == 0)angle += (90.f * Constants::ToRad);
		float angle_1 = angle + (Constants::P_2 / 24);
		float angle_2 = angle - (Constants::P_2 / 24);

		sf::Vector2f pos_1 = sf::Vector2f(std::cosf(angle_1), std::sinf(angle_1)) * radius;
		sf::Vector2f pos_2 = sf::Vector2f(std::cosf(angle_2), std::sinf(angle_2)) * radius;

		sf::Vector2f pos_3 = sf::Vector2f(std::cosf(angle_1), std::sinf(angle_1)) * -radius;
		sf::Vector2f pos_4 = sf::Vector2f(std::cosf(angle_2), std::sinf(angle_2)) * -radius;

		vertarr.append(sf::Vertex(pos_1, color));vertarr.append(sf::Vertex(pos_2, color));vertarr.append(sf::Vertex(pos_3, color));
		vertarr.append(sf::Vertex(pos_3, color));vertarr.append(sf::Vertex(pos_4, color));vertarr.append(sf::Vertex(pos_1, color));
	}

	return vertarr;
}

void sh::Cross(sf::VertexArray& Va, float angle, float radius, sf::Color color)
{VAaddVA(Va, Cross(angle, radius, color));}

sf::VertexArray sh::RegularPoligon(size_t facets, float radius, float angle, sf::Color color)
{	angle *= Constants::ToRad;
	sf::VertexArray vertarr(sf::Triangles);

	for (size_t i = 0; i < facets; i++) {
		float a1 = angle + (Constants::P_2 * i / facets);
		float a2 = angle + (Constants::P_2 * (i + 1) / facets);

		sf::Vector2f p1 = sf::Vector2f{ std::cosf(a1), std::sinf(a1) } * radius;
		sf::Vector2f p2 = sf::Vector2f{ std::cosf(a2), std::sinf(a2) } * radius;

		vertarr.append(sf::Vertex({ 0.f,0.f } , color));
		vertarr.append(sf::Vertex(p1, color));
		vertarr.append(sf::Vertex(p2, color));
	}

	return vertarr;
}

void sh::RegularPoligon(sf::VertexArray& Va, size_t facets, float radius, float angle, sf::Color color)
{
	VAaddVA(Va, RegularPoligon(facets, radius, angle, color));
}

sf::VertexArray sh::RegularPoligonAndBorder(size_t facets, float radius, float outRadius, float angle, sf::Color color, sf::Color color_2)
{
	sf::VertexArray V = RegularPoligon(facets , outRadius, angle, color_2);
	RegularPoligon(V, facets, radius, angle, color);
	return V;
}

void sh::RegularPoligonAndBorder(sf::VertexArray& Va, size_t facets, float radius, float outRadius, float angle, sf::Color color, sf::Color color_2)
{
	VAaddVA(Va, RegularPoligonAndBorder(facets, radius, outRadius, angle, color, color_2));
}

sf::VertexArray sh::HollovRegularPoligon(size_t facets, float radius, float outRadius, float angle, sf::Color color)
{
	angle *= Constants::ToRad;
	sf::VertexArray vertarr(sf::Triangles);

	for (size_t i = 0; i < facets; i++) {
		float a1 = angle + (Constants::P_2 * i / facets);
		float a2 = angle + (Constants::P_2 * (i + 1) / facets);

		sf::Vector2f p1 = sf::Vector2f{ std::cosf(a1), std::sinf(a1) } * radius;
		sf::Vector2f p2 = sf::Vector2f{ std::cosf(a2), std::sinf(a2) } * radius;

		sf::Vector2f p3 = sf::Vector2f{ std::cosf(a1), std::sinf(a1) } * outRadius;
		sf::Vector2f p4 = sf::Vector2f{ std::cosf(a2), std::sinf(a2) } * outRadius;

		vertarr.append(sf::Vertex(p1, color));
		vertarr.append(sf::Vertex(p2, color));
		vertarr.append(sf::Vertex(p3, color));

		vertarr.append(sf::Vertex(p3, color));
		vertarr.append(sf::Vertex(p4, color));
		vertarr.append(sf::Vertex(p2, color));
	}

	return vertarr;
}

void sh::HollovRegularPoligon(sf::VertexArray& Va, size_t facets, float radius, float outRadius, float angle, sf::Color color)
{
	VAaddVA(Va, HollovRegularPoligon(facets, radius, outRadius, angle, color));
}

sf::VertexArray sh::Trangle(float radius, float angle ,sf::Color color)
{
	angle *= Constants::ToRad;
	sf::VertexArray vertarr(sf::Triangles);

	size_t count = 3;
	vertarr.resize(count);

	for (size_t i = 0; i < count; i++) {
		float angle1 = angle + (Constants::P_2 * i / count);

		sf::Vector2f pos = sf::Vector2f{ std::sin(angle1), std::cos(angle1) } * radius;

		vertarr[i] = sf::Vertex(pos , color);
	}

	return vertarr;
}

void sh::Trangle(sf::VertexArray& Va, float radius, float angle, sf::Color color)
{
	VAaddVA(Va, Trangle(radius, angle, color));
}
