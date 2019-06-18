#pragma once
#include <vector>
#include <Renderer2D.h>

class SceneObject
{
public:
	SceneObject() {};
	virtual ~SceneObject();

	void update(float deltaTime)
	{
		onUpdate(deltaTime);

		//update children
		for (auto child : m_children) //iterate through child for how many children there are
		{
			child->draw(renderer);
		}
	}

	virtual void onUpdate(float deltaTime);
	virtual void SceneObject::OnDraw(aie::Renderer2D* renderer);

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
};