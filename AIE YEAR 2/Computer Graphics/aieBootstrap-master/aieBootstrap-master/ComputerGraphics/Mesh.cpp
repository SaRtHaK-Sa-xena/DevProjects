#include "Mesh.h"

Mesh::~Mesh()
{
	// if vertex 0, ignore otherwise delete
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
}

void Mesh::initialiseQuad()
{
	// check that the mesh is not initialized already
	assert(vao == 0);

	// generate buffers
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);

	// bind vertex array aka a mesh wrapper
	glBindVertexArray(vao);

	// bind vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// define 6 vertices for 2 triangles
	Vertex vertices[6];
	vertices[0].position = { -0.5f, 0, 0.5f, 1 };
	vertices[1].position = { 0.5f, 0, 0.5f, 1 };
	vertices[2].position = { -0.5f, 0, -0.5f, 1 };
	vertices[3].position = { -0.5f, 0, -0.5f, 1 };
	vertices[4].position = { 0.5f, 0, 0.5f, 1 };
	vertices[5].position = { 0.5f, 0, -0.5f, 1 };

	// fill vertex buffer
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex),
		vertices, GL_STATIC_DRAW);

	// enable first element as position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), 0);

	// unbind buffers
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	// quad has 2 triangles
	triCount = 2;

}

void Mesh::draw()
{
	glBindVertexArray(vao);
	// using indices or just vertices?
	if (ibo != 0)
		glDrawElements(GL_TRIANGLES, 3 * triCount,
			GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, 3 * triCount);
}

//---Notes
//	VAO = Vertex Array Object
//	VBO = Vertex Buffer Object
//	IBO = Index Buffer Object
// To create the vao and vbo we call glGen###() methods
// which follow the same naming convention as glDelete###(),
// glGenBuffers() for generating VBO and IBOs and 
// glGenVertexArrays() for generation VAOs like in line 14-18

// Once generated objects need to binded, 'Binding' makes them 'active'
// for editing or drawing by sending it to the GPU
// to bind we use glBind###()

// to assign current data to currently bound buffer, call
// glBufferData() -> takes 4 parameters
// 1. specify what type of buffer (GL_ARRAY_BUFFER for vertex data)
// 2. size of the data in bytes	
// 3. pointer to the data 
// 4. an OpenGL constant to define if the data will update after it is defined

// Since quad data is not changing we use static-> GL_STATIC_DRAW

// After the buffer data is bounded, need to inform VAO how it should order the 
// vertex data for a shader to use.
// To do this we need to 
// 1. Enable vertex attributes -> glEnableVertexAttribArray() -> passing in zero to specify which attribute
// 2. Define how big the attribute is -> glvertexAttribPointer() #REF 1
// 3. What it is made of
// 4. Where to find it in the vertex data 
// 5. And how many bytes separate each attribute in the vertex data

// Since we are only defining positions we just need to enable a single attribute
// it has four GL_FLOAT elements (since it is a vec4 position (float x, float y, etc.)), 
// doesn't need to be normalized, each position is separated by sizeof(vertex) number of bytes
// position is the first variable in the Vertex struct, so the offset is zero

// After buffer data is defined, unbind our buffers and store howmany triangles our mesh has (2)
// OpenGL works on the currently bound information, so to not accidently modify data we unbind
// To draw we need to rebind our VAO, don't need to bind anything else as it was all bound to VAO 
// when we initialized our data
// Once bound call either of the below
//							glDrawArrays()	  | glDrawElements().
// Refer to drawing a mesh using just vertices|Elements refers to using an index buffer
// Future proof if Index buffer object is valid then call correct method
// First use a constant ot define the type of primitive we'll be drawing -> GL_TRIANGLES
// GL_TRIANGLES(ofsetting into the buffers to skip the vertices)
// GL_TRIANGLES(specifying how many indices or vertices we're drawing)
// We'll draw 3 x triCount worth of indices or vertices.

//Drawing a MESH___
// to draw, we need projection, view transform to represent a camera, 
// and transform to represent where the mesh is that we're drawing
// we need to bind our shader, once bound we need to bind the uniform for 
// the projectionViewModel transform -> combination of projection, view 
// and model transform
// model transform is the quad's transform we defined to be a scale transform
//_________________



//#REF 1
// It Takes in 6 parameters
// 1. The attribute we are definining 
// 2. The elements the attributes has
// 3. What type of data is each attribute
// 4. Do we normalize the attribute (in case of vectors)
// 5. The bytes that sperate each attribute (for example, how many bytes separate
// the _position data from the next _position data in our array of Vertex objects)
// 6. How many bytes from the start of the vertex data to the first of that 
// attribute type that we are definining

