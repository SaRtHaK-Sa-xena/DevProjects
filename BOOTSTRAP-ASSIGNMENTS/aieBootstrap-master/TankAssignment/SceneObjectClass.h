#pragma once
#include <vector>
#include <Renderer2D.h>

class SceneObject
{
public:
	SceneObject() {};
	virtual ~SceneObject();

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

	virtual void onUpdate(float deltaTime) {};
	virtual void SceneObject::OnDraw(aie::Renderer2D* renderer) {};

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
protected:
	SceneObject * m_parent = nullptr; //starts null
	std::vector<SceneObject*> m_children; //starts empty

	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globalTransform = Matrix3::identity;
};


class SpriteObject : public SceneObject
{
public:
	SpriteObject() {};
	SpriteObject(const char* filename) { load(filename); }

	virtual ~SpriteObject() { delete m_texture; }
	
	bool load(const char* filename);
	virtual void onDraw(aie::Renderer2D* renderer);

protected:
	aie::Texture* m_texture = nullptr;
};