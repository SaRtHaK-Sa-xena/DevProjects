#include "SceneObjectClass.h"
#include <assert.h>
#include <Texture.h>

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

void SceneObject::update(float deltaTime)
{
	onUpdate(deltaTime);

	//update children
	for (auto child : m_children) //iterate through child for how many children there are
	{
		child->update(deltaTime);
	}
}

void SpriteObject::OnDraw(aie::Renderer2D * renderer)
{
	renderer->drawSpriteTransformed3x3(m_texture, (float*)&m_globalTransform);
}

void SceneObject::draw(aie::Renderer2D * renderer)
{
	//run onDraw behaviour
	OnDraw(renderer);

	//draw children
	for (auto child : m_children)
	{
		child->draw(renderer);
	}

}


void SceneObject::updateTransform()
{
	ApplyVel(); //def
	if (m_parent != nullptr)
	{
		m_globalTransform = m_parent->m_globalTransform * m_localTransform;
	}
	else
	{
		m_globalTransform = m_localTransform;
	}

	//have all child objects global transform updated
	//so loop through all children
	for (auto child : m_children)
	{
		child->updateTransform();
		child->ApplyVel(); //set accordingly
	}
}

void SceneObject::setPosition(float x, float y)
{
	m_localTransform[2] = { x,y,1 };
	updateTransform();
}

//void SceneObject::getPosition(SpriteObject variable_tank)
//{
//
//}

void SceneObject::setRotate(float radians)
{
	m_localTransform.setRotateZ(radians);
	updateTransform();
}

void SceneObject::setScale(float width, float height)
{
	m_localTransform.setScaled(width, height, 1);
	updateTransform();
}

void SceneObject::translate(float x, float y)
{
	m_localTransform.translate(x, y);
	updateTransform();
}

void SceneObject::rotate(float radians)
{
	m_localTransform.rotateZ(radians);
	updateTransform();
}

void SceneObject::scale(float width, float height)
{
	m_localTransform.scale(width, height, 1);
	updateTransform();
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

bool SpriteObject::load(const char * filename)
{
	delete m_texture;
	m_texture = nullptr;
	m_texture = new aie::Texture(filename);
	return m_texture != nullptr;
}


