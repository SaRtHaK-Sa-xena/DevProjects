#pragma once
class Agent
{
public:
	Agent ();
	virtual ~Agent();

	// Update the agent and its behaviours
	virtual void Update(float deltaTime);
	// Draw the agent
	virtual void Draw(aie::Renderer2D* renderer);
	// Add a behaviour to the agent
	void AddBehaviour(Behaviour* behaviour);
	// Movement functions
	void SetPosition(Vector2 position) { m_Position = position; }
	Vector2 GetPosition() { return m_Position; }
	void SetVelocity(Vector2 velocity) { m_Velocity = velocity; }
	Vector2 GetVelocity() { return m_Velocity; }
protected:
	std::vector<Behaviour*> m_BehaviourList;
	Vector2 m_Position;
	Vector2 m_Velocity;
};