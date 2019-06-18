#include "SceneObjectClass.h"

SceneObject::~SceneObject()
{
	//detach from parent
	if (m_parent != nullptr) //if the parent exists
	{
		m_parent->removeChild(this); //removes the child nodes
	}

	//remove all children
	for (auto child : m_children)
	{
		child->m_parent = nullptr; //making parent of each child equal to nullptr
	}
}

void SceneObject::onUpdate(float deltaTime)
{
}

void SceneObject::OnDraw(aie::Renderer2D * renderer)
{
}

SceneObject * SceneObject::getParent() const
{
	return m_parent;
}

size_t SceneObject::childCount() const
{
	return m_children.size();
}

SceneObject * SceneObject::getChild(unsigned int index) const
{
	return m_children[index];
}

void SceneObject::addChild(SceneObject * child)
{
	//first to make sure it doesn't have a parent already --> since each node holds only ONE parent
	assert(child->m_parent == nullptr);

	//assign this as parent
	child->m_parent = this;

	//add new child to collection
	m_children.push_back(child);
}

void SceneObject::removeChild(SceneObject * child)
{
	//make sure that it exists in m_children
	//so find the child in the collection
	auto iter = std::find(m_children.begin(), m_children.end(), child); //from begenning to end, look for child

	//if found, remove it
	if (iter != m_children.end()) //not at end
	{
		m_children.erase(iter);
		//also unassign parent
		child->m_parent = nullptr;
	}
}
