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
		glm::vec4 position; //NOTE: each float is 4 bytes
		glm::vec4 normal;
		glm::vec2 texCoord; //NOTE: 32 bytes in from the start 
	};
	
	//	to initialize a quad 
	void initialiseQuad();
	
	//	to create arbitrary meshes
	void initialise(unsigned int vertexCount,
		const Vertex* vertices,
		unsigned int indexCount = 0,
		unsigned int* indeces = nullptr);;

	//	to draw 
	virtual void draw();


protected:
	unsigned int triCount;
	unsigned int vao, vbo, ibo;
};

