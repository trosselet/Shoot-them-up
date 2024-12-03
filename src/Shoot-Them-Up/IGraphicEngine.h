#pragma once

class IGraphicEngine {
public:
    virtual ~IGraphicEngine() = default;

    //Window
    virtual void Initialize(unsigned int width, unsigned int height, const std::string& title) = 0;
    virtual void Run() = 0;
    virtual void Draw() = 0;
    virtual void HandleInput() = 0;

};