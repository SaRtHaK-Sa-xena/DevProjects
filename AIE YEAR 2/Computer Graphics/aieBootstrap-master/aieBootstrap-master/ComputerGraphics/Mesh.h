#pragma once
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <gl_core_4_4.h> 

class Mesh
{
public:
	Mesh() : triCount(0), vao(0), vbo(0), ibo(0) {}
	virtual ~Mesh();

	//	struct to populate with vertex information
	struct Vertex {
		glm::vec4 position;
		glm::vec4 normal;
		glm::vec2 texCoord;
	};
	
	//	to initialize a quad 
	void initialiseQuad();
	
	//	to draw 
	virtual void draw();


protected:
	unsigned int triCount;
	unsigned int vao, vbo, ibo;
};

