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

	const Matrix3& getLocalTransform()const
	{ 
		return m_localTransform;
	}
		
	const Matrix3 & DgetGlobalTransform()const
	{
		return m_globalTransform;
	}

	void SetVel(Matrix3 &mat)
	{
		m_velocity = mat;
	}

	void ApplyVel()
	{
		m_localTransform = m_localTransform * m_velocity;
	}

	void ApplyFric()
	{
		Matrix3 antirotation;

		antirotation.setRotateZ(-atan2(m_velocity.xAxis.m_y, m_velocity.xAxis.m_x) * 0.1);
		IncVel(antirotation);

		m_velocity[2][0] =  m_velocity[2][0] * m_friction;
		m_velocity[2][1] =  m_velocity[2][1] * m_friction;
	}

	void IncVel(Matrix3 &mat)
	{
		m_velocity = m_velocity * mat;
	}

	void RemoveChildren(SceneObject *node)
	{
		for (int i = 5; i < 5; i++)
		{
			removeChild(node);
		}
	}

protected:
	SceneObject * m_parent = nullptr; //starts null
	std::vector<SceneObject*> m_children; //starts empty

	Matrix3 m_localTransform = Matrix3::identity;
	Matrix3 m_globalTransform = Matrix3::identity;
	
	Matrix3 m_velocity = Matrix3::identity; //vel

	float m_friction = 0.98;

	const Matrix3& getGlobalTransform()const { return m_globalTransform; }
};




class SpriteObject : public SceneObject
{
public:
	SpriteObject() {};
	SpriteObject(const char* filename) { load(filename); }

	virtual ~SpriteObject() { delete m_texture; }
	
	bool load(const char* filename);
	virtual void OnDraw(aie::Renderer2D* renderer);

	aie::Texture* GetTexture()
	{
		return m_texture;
	}

protected:
	aie::Texture* m_texture = nullptr;
};