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

	//	adding in the normal for quad
	//	since it is lying flat down, it's y will be only normal
	vertices[0].normal = { 0, 1, 0, 0 };
	vertices[1].normal = { 0, 1, 0, 0 };
	vertices[2].normal = { 0, 1, 0, 0 };
	vertices[3].normal = { 0, 1, 0, 0 };
	vertices[4].normal = { 0, 1, 0, 0 };
	vertices[5].normal = { 0, 1, 0, 0 };

	// Textures for each vertices
	// quad consists of two triangles, therefore it's three vertices, times 2. 
	vertices[0].texCoord = { 0, 1 }; // bottom left
	vertices[1].texCoord = { 1, 1 }; // bottom right
	vertices[2].texCoord = { 0, 0 }; // top left
	vertices[3].texCoord = { 0, 0 }; // top left
	vertices[4].texCoord = { 1, 1 }; // bottom right
	vertices[5].texCoord = { 1, 0 }; // top right



	// fill vertex buffer
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex),
		vertices, GL_STATIC_DRAW);

	// enable first element as position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), 0);

	// enable second element as normal
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE,
		sizeof(Vertex), (void*)16);

	// enable third element as texture
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), (void*)32);

	// unbind buffers
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	// quad has 2 triangles
	triCount = 2;

}

void Mesh::initialiseFullScreenQuad()
{
	assert(vao == 0);

	// generate buffers
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);

	// bind vertex array aka a mesh wrapper
	glBindVertexArray(vao);

	// bind vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// define vertices
	float vertices[] = {
	-1,1, // left top
	-1,-1, // left bottom
	1,1, // right top
	-1,-1, // left bottom
	1,-1, // right bottom
	1, 1 // right top
	};

	// fill vertex buffer
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), vertices,
		GL_STATIC_DRAW);

	// enable first element as position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 8, 0);

	// unbind buffers
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// quad has 2 triangles
	triCount = 2;
}

void Mesh::initialise(unsigned int vertexCount, const Vertex* vertices, unsigned int indexCount, unsigned int* indeces)
{
	assert(vao == 0);

	// generate buffers
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);

	// bind vertex array aka a mesh wrapper
	glBindVertexArray(vao);

	// bind vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// fill vertex buffer
	glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(Vertex),
		vertices, GL_STATIC_DRAW);

	// enable first element as position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), 0);

	// enable second element as normal
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE,
		sizeof(Vertex), (void*)16);
	// enable third element as texture
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), (void*)32);

	// bind indices if there are any
	if (indexCount != 0) {
		glGenBuffers(1, &ibo);
		// bind vertex buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		// fill vertex buffer
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			indexCount * sizeof(unsigned int), indeces, GL_STATIC_DRAW);
		triCount = indexCount / 3;
	} 
	else 
	{
		triCount = vertexCount / 3;
	}

	// unbind buffers
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


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


//Creating arbitrary meshes
//	need new initialize mehtod, that takes in array of Vertex objects,
//	integer count of how many vertices there are, an array of unsigned int indeces 
//	and a count of how many indices there are
//	since we don't need indices for a mesh we could make them optional parameters
//	Initialize method is very similary to initializeQuad(),
//	starting out by asserting that the mesh hasn't already been initialized, creating VBO, VAO.
//	Then bind the VAO, VBO and the fills in the buffer data using the array of vertices.
//	Then set the first vertex attribute, same as quad

// indices are optional therfore, we need to check if number of indices has been specified,
// default is vertexCount/3 (3 vertices per triangle)
//	1. Generate the IBO
//	2. Bind the IBO to the GL_ELEMENT_ARRAY_BUFFER property (represents index buffers)
//	3. Bind the index buffer data, but this time use GL_ELEMENT_ARRAY_BUFFER tag
//	4. Set the triCount to the indexCount/3
//	Clean up by unbinding everything

// FOR POST PROCESSING
//	We need to be able to render the scene in to a Render Target that is typically the same resolution as
//	the display. We then render a Full - screen Quad to the Back Buffer, applying the target from the
//	Render Target as a texture across the quad, and try to match the texels in the texture to pixels in the
//	screen with a matching 1:1 texel to pixel ratio


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

