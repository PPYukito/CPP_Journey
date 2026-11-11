#pragma once

class Scene
{

protected:
    bool m_IsPlaying = false;

public:
    virtual ~Scene() = default;

    virtual void Initialize() {}
    virtual void Finalize() {}
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;

};