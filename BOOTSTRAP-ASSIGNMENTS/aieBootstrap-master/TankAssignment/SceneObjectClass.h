#pragma once
#include <vector>
#include <Renderer2D.h>
#include "MathFuncLib.h"

class SceneObject
{
public:
	SceneObject() {};
	virtual ~SceneObject();

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

	virtual void onUpdate(float deltaTime) {};
	virtual void OnDraw(aie::Renderer2D* renderer) {};

	void updateTransform();

	void setPosition(float x, float y);
	void setRotate(float radians);
	void setScale(float width, float height);
	void translate(float x, float y);
	void rotate(float radians);
	void scale(float width, float height);

	SceneObject* getParent() const;
	size_t childCount()const;
	SceneObject* getChild(unsigned int index)const;

	//add child
	void addChild(SceneObject* child);


	//remove child---> sort of like binary tree remove function
	void removeChild(SceneObject *child);

	const Matrix3& getLocalTransform()const { return m_localTransform; }

	

protected:
	SceneObject * m_parent = nullptr; //starts null
	std::vector<SceneObject*> m_children; //starts empty

	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globalTransform = Matrix3::identity;

	
	const Matrix3& getGlobalTransform()const { return m_globalTransform; }
};

//Matrix3 operator*(const Vector3 &vec, float scalar)
//{
//	return vec * scalar;
//}
class SpriteObject : public SceneObject
{
public:
	SpriteObject() {};
	SpriteObject(const char* filename) { load(filename); }

	virtual ~SpriteObject() { delete m_texture; }
	
	bool load(const char* filename);
	virtual void OnDraw(aie::Renderer2D* renderer);

protected:
	aie::Texture* m_texture = nullptr;
};